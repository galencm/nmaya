/*  =========================================================================
    nmaya - A library for arranging stuff

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of zbroker, the ZeroMQ broker project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

/*
@header
    nmaya - A library for arranging stuff
@discuss
@end
*/

#include "nmaya_classes.h"

//  Structure of our class

struct _nmaya_t {
    //int filler;     //  Declare class properties here
    char *directory;
};


//  --------------------------------------------------------------------------
//  Create a new nmaya

nmaya_t *
nmaya_new (const char *directory)
{
    if (directory == NULL)
        directory = ".hydra/posts";

    nmaya_t *self = (nmaya_t *) zmalloc (sizeof (nmaya_t));
    assert (self);
    self->directory = strdup (directory);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the nmaya

void
nmaya_destroy (nmaya_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        nmaya_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

//  --------------------------------------------------------------------------
//  Pluck an item from an arrangment

nmaya_arrangement_t *
    nmaya_pluck (nmaya_t *self, const char *arrangement_key, int position)
{
    nmaya_arrangement_t *plucked = NULL;
    zconfig_t *post = NULL;
    //zconfig_t *post = zconfig_new ("root", NULL);
    zdir_t *directory = zdir_new (self->directory, "-");
    zlist_t *files = zdir_list (directory);
    zhashx_t *arrangement_index = zhashx_new();
    zfile_t *file = (zfile_t *) zlist_first (files);

    zdir_print (directory,4);

    while (file) {
        printf("loading: %s\n", zfile_filename (file, NULL));
        post = zconfig_load ( zfile_filename (file, NULL));
        // zconfig_print (post);
        printf("key:     %s\n", zconfig_get (post, arrangement_key, NULL));
        printf("value:   %s\n", zfile_filename (file, NULL));
        printf("\n");
        zhashx_insert (arrangement_index, zconfig_get (post, arrangement_key, NULL), zfile_filename (file, NULL));
        file = (zfile_t *) zlist_next (files);
    }

    zlistx_t *keys = zhashx_keys (arrangement_index);
    zlistx_sort (keys);

    const char *search_key = (const char*) zlistx_first (keys);
    int count = 0;
    printf("%d %s\n", count, search_key);

    while (count < position && search_key) {
        search_key = (const char*) zlistx_next (keys);
        count++;
        printf("%d %s\n", count, search_key);
    }

    if (search_key){

        post = zconfig_load ( zhashx_lookup(arrangement_index, search_key));
        zconfig_print (post);

        char *blob_path = zconfig_get (post, "/post/location", NULL);
        //chop off 'posts/' +5
        char* blob_fullpath = zsys_sprintf ("%s%s", self->directory, blob_path+5);
        printf("blob fullpath:   %s\n", blob_fullpath);

        plucked = nmaya_arrangement_new(zconfig_get (post, "/post/mime-type", NULL), zchunk_slurp(blob_fullpath,0));
        zstr_free (&blob_path);
        zstr_free (&blob_fullpath);
    }
    else
        plucked = nmaya_arrangement_new("*/*", zchunk_new(NULL,0));
    
    // TOFIX free string
    //zstr_free(search_key);
    zlistx_destroy (&keys);
    zlist_destroy(&files);
    zdir_destroy(&directory);
    zfile_destroy(&file);
    // zconfig_destroy segfaults
    // zconfig_destroy(&post);
    zhashx_destroy(&arrangement_index);
    return plucked;

}

//  --------------------------------------------------------------------------
//  Return the nmaya version for run-time API detection

void
nmaya_version (int *major, int *minor, int *patch)
{
    *major = NMAYA_VERSION_MAJOR;
    *minor = NMAYA_VERSION_MINOR;
    *patch = NMAYA_VERSION_PATCH;
}

//  --------------------------------------------------------------------------
//  Self test of this class

// If your selftest reads SCMed fixture data, please keep it in
// src/selftest-ro; if your test creates filesystem objects, please
// do so under src/selftest-rw.
// The following pattern is suggested for C selftest code:
//    char *filename = NULL;
//    filename = zsys_sprintf ("%s/%s", SELFTEST_DIR_RO, "mytemplate.file");
//    assert (filename);
//    ... use the "filename" for I/O ...
//    zstr_free (&filename);
// This way the same "filename" variable can be reused for many subtests.
#define SELFTEST_DIR_RO "src/selftest-ro"
#define SELFTEST_DIR_RW "src/selftest-rw"

void
nmaya_test (bool verbose)
{
    printf (" * nmaya: ");

    //  @selftest
    //  Simple create/destroy test
    // cp -r ../hii/.hyda .
    nmaya_t *self = nmaya_new (".hydra/posts");
    assert (self);
    nmaya_arrangement_t *thing = nmaya_pluck (self,"/post/subject",0);
    assert (streq (nmaya_arrangement_mime_type (thing), "image/jpeg"));
    // zchunk_t *content = nmaya_arrangement_content (thing);
    // printf ("%s", zchunk_strhex (content));
    nmaya_arrangement_t *another_thing = nmaya_pluck (self,"/post/subject",1001);
    assert (streq (nmaya_arrangement_mime_type (another_thing), "*/*"));

    // zchunk_destroy (&content);
    nmaya_arrangement_destroy(&thing);
    nmaya_arrangement_destroy(&another_thing);
    nmaya_destroy (&self);
    //  @end
    printf ("OK\n");
}
