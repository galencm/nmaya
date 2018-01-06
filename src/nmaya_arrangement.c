/*  =========================================================================
    maya_arrangement - arrangement of stuff

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of zbroker, the ZeroMQ broker project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

/*
@header
    maya_arrangement - arrangement of stuff
@discuss
@end
*/

#include "maya_classes.h"

#define ID_SIZE     40          //  Size of SHA1 digest as text string

//  Structure of our class

struct _maya_arrangement_t {
    //int filler;     //  Declare class properties here
    char *mime_type;            //  MIME type
    zchunk_t *content;          //  Content chunk
    char digest [ID_SIZE + 1];  //  Content SHA1 digest
    size_t content_size;        //  Content size
};


//  --------------------------------------------------------------------------
//  Create a new maya_arrangement

maya_arrangement_t *
maya_arrangement_new (const char *mime_type, zchunk_t *content)
{

    maya_arrangement_t *self = (maya_arrangement_t *) zmalloc (sizeof (maya_arrangement_t));
    assert (self);
    //  Initialize class properties here
    self->mime_type = strdup (mime_type);
    self->content = zchunk_dup (content);
    strcpy (self->digest, zchunk_digest (self->content));
    self->content_size = zchunk_size (self->content);

    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the maya_arrangement

void
maya_arrangement_destroy (maya_arrangement_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        maya_arrangement_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
}

//  --------------------------------------------------------------------------
//  Return the arrangement mime_type

const char *
maya_arrangement_mime_type (maya_arrangement_t *self)
{
    assert (self);
    return self->mime_type;
}

//  --------------------------------------------------------------------------
//  Return the arrangement content

zchunk_t *
maya_arrangement_content (maya_arrangement_t *self)
{
    assert (self);
    if (self->content)
        return zchunk_dup (self->content);

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
maya_arrangement_test (bool verbose)
{
    printf (" * maya_arrangement: ");

    //  @selftest
    //  Simple create/destroy test
    maya_arrangement_t *self = maya_arrangement_new ("*/*", zchunk_new (NULL,0));
    assert (self);
    maya_arrangement_destroy (&self);
    //  @end
    printf ("OK\n");
}
