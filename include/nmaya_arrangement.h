/*  =========================================================================
    nmaya_arrangement - class description

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of zbroker, the ZeroMQ broker project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef NMAYA_ARRANGEMENT_H_INCLUDED
#define NMAYA_ARRANGEMENT_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  @interface
//  Create a new nmaya_arrangement
NMAYA_EXPORT nmaya_arrangement_t *
    nmaya_arrangement_new (void);

//  Destroy the nmaya_arrangement
NMAYA_EXPORT void
    nmaya_arrangement_destroy (nmaya_arrangement_t **self_p);

//  Self test of this class
NMAYA_EXPORT void
    nmaya_arrangement_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
