/*  =========================================================================
    nmaya_arrangement - class description

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of zbroker, the ZeroMQ broker project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

/*
@header
    nmaya_arrangement -
@discuss
@end
*/

#include "nmaya_classes.h"

//  Structure of our class

struct _nmaya_arrangement_t {
    int filler;     //  Declare class properties here
};


//  --------------------------------------------------------------------------
//  Create a new nmaya_arrangement

nmaya_arrangement_t *
nmaya_arrangement_new (void)
{
    nmaya_arrangement_t *self = (nmaya_arrangement_t *) zmalloc (sizeof (nmaya_arrangement_t));
    assert (self);
    //  Initialize class properties here
    return self;
}


//  --------------------------------------------------------------------------
//  Destroy the nmaya_arrangement

void
nmaya_arrangement_destroy (nmaya_arrangement_t **self_p)
{
    assert (self_p);
    if (*self_p) {
        nmaya_arrangement_t *self = *self_p;
        //  Free class properties here
        //  Free object itself
        free (self);
        *self_p = NULL;
    }
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
nmaya_arrangement_test (bool verbose)
{
    printf (" * nmaya_arrangement: ");

    //  @selftest
    //  Simple create/destroy test
    nmaya_arrangement_t *self = nmaya_arrangement_new ();
    assert (self);
    nmaya_arrangement_destroy (&self);
    //  @end
    printf ("OK\n");
}
