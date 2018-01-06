/*  =========================================================================
    nmaya - class description

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of zbroker, the ZeroMQ broker project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.
    =========================================================================
*/

#ifndef NMAYA_H_INCLUDED
#define NMAYA_H_INCLUDED

#ifdef __cplusplus
extern "C" {
#endif

//  Include the library file with typdefs, public includes and public constants
#include "nmaya_library.h"

//  @interface
//  Create a new nmaya
NMAYA_EXPORT nmaya_t *
    nmaya_new (void);

//  Destroy the nmaya
NMAYA_EXPORT void
    nmaya_destroy (nmaya_t **self_p);

//  Self test of this class
NMAYA_EXPORT void
    nmaya_test (bool verbose);

//  @end

#ifdef __cplusplus
}
#endif

#endif
