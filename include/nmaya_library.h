/*  =========================================================================
    nmaya - generated layer of public API

    Copyright (c) the Contributors as noted in the AUTHORS file.
    This file is part of zbroker, the ZeroMQ broker project.

    This Source Code Form is subject to the terms of the Mozilla Public
    License, v. 2.0. If a copy of the MPL was not distributed with this
    file, You can obtain one at http://mozilla.org/MPL/2.0/.

################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
    =========================================================================
*/

#ifndef NMAYA_LIBRARY_H_INCLUDED
#define NMAYA_LIBRARY_H_INCLUDED

//  Set up environment for the application

//  External dependencies
#include <czmq.h>

//  NMAYA version macros for compile-time API detection
#define NMAYA_VERSION_MAJOR 0
#define NMAYA_VERSION_MINOR 1
#define NMAYA_VERSION_PATCH 0

#define NMAYA_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define NMAYA_VERSION \
    NMAYA_MAKE_VERSION(NMAYA_VERSION_MAJOR, NMAYA_VERSION_MINOR, NMAYA_VERSION_PATCH)

#if defined (__WINDOWS__)
#   if defined NMAYA_STATIC
#       define NMAYA_EXPORT
#   elif defined NMAYA_INTERNAL_BUILD
#       if defined DLL_EXPORT
#           define NMAYA_EXPORT __declspec(dllexport)
#       else
#           define NMAYA_EXPORT
#       endif
#   elif defined NMAYA_EXPORTS
#       define NMAYA_EXPORT __declspec(dllexport)
#   else
#       define NMAYA_EXPORT __declspec(dllimport)
#   endif
#   define NMAYA_PRIVATE
#elif defined (__CYGWIN__)
#   define NMAYA_EXPORT
#   define NMAYA_PRIVATE
#else
#   define NMAYA_EXPORT
#   if (defined __GNUC__ && __GNUC__ >= 4) || defined __INTEL_COMPILER
#       define NMAYA_PRIVATE __attribute__ ((visibility ("hidden")))
#   else
#       define NMAYA_PRIVATE
#   endif
#endif

//  Project has no stable classes, so we build the draft API
#undef  NMAYA_BUILD_DRAFT_API
#define NMAYA_BUILD_DRAFT_API

//  Opaque class structures to allow forward references
//  These classes are stable or legacy and built in all releases
//  Draft classes are by default not built in stable releases
#ifdef NMAYA_BUILD_DRAFT_API
typedef struct _nmaya_t nmaya_t;
#define NMAYA_T_DEFINED
typedef struct _nmaya_arrangement_t nmaya_arrangement_t;
#define NMAYA_ARRANGEMENT_T_DEFINED
#endif // NMAYA_BUILD_DRAFT_API


//  Public classes, each with its own header file
#ifdef NMAYA_BUILD_DRAFT_API
#include "nmaya_arrangement.h"
#endif // NMAYA_BUILD_DRAFT_API

#ifdef NMAYA_BUILD_DRAFT_API
//  Self test for private classes
NMAYA_EXPORT void
    nmaya_private_selftest (bool verbose);
#endif // NMAYA_BUILD_DRAFT_API

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/