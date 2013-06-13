#ifndef DIFF_DEFINE
/******************************************************************************
 *  File: macros.h
 *
 *  This file is part of isostuffer
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/
#endif /* ! DIFF_DEFINE */
/******************************************************************************
 *  The definitions of some utility macros
 *
 *  Changxi Zheng (cxzheng@cs.cornell.edu)
 *
 ******************************************************************************/

/*
 * The returned value should be zero, if an operation is succeed.
 * otherwise, non-zero is returned.
 */
#ifndef MACRO_DEF_H
#   define MACRO_DEF_H

#ifndef ERROR_RETURN
#   define ERROR_RETURN        -1
#endif

#ifndef SUCC_RETURN
#   define SUCC_RETURN          0
#endif

#ifndef _FAILED
#   define _FAILED(p)      ((p) < 0)
#endif

#ifndef _SUCCEEDED
#ifndef DIFF_DEFINE
#   define _SUCCEEDED(p)  ((p) == 0)
#else /* DIFF_DEFINE */
#   define _SUCCEEDED(p)  ((p) >= 0)
#endif /* DIFF_DEFINE */
#endif

#include <stdio.h>
#include <assert.h>

/*
#ifdef HAVE_CONFIG_H
#   include "conts-config.h"
#endif
*/
#ifdef DIFF_DEFINE
#ifndef __ASSERT_VOID_CAST
#   define __ASSERT_VOID_CAST   (void)
#endif
#endif /* DIFF_DEFINE */

#define SHOULD_NEVER_HAPPEN(x)                                              \
        {                                                                   \
            fprintf(stderr, "ERROR: SHOULD NEVER ARRIVE HERE at %s:L.%d\n", \
                    __FILE__, __LINE__);                                    \
            fflush(stderr);                                                 \
            exit(x);                                                        \
        }

#ifdef DIFF_DEFINE
#define ABORT_HERE(x)                                                       \
        {                                                                   \
            fprintf(stdout, "Abort execution at %s:L.%d\n",                 \
                    __FILE__, __LINE__);                                    \
            fflush(stdout);                                                 \
            exit(x);                                                        \
        }

#endif /* DIFF_DEFINE */
#if defined(DEBUG) | defined(_DEBUG)
#   ifndef V
#       define V(x)                                                     \
        {                                                               \
            int hr = x;                                                 \
            if( _FAILED(hr) ) {                                         \
                fprintf(stderr, "DEBUG Failed: line %d, file \"%s\"\n", \
                        __LINE__, __FILE__);                            \
                fflush(stderr);                                         \
            }                                                           \
        }
#   endif
#   ifndef V_RETURN
#       define V_RETURN(x)                                              \
        {                                                               \
            int hr = x;                                                 \
            if( _FAILED(hr) ) {                                         \
                fprintf(stderr, "DEBUG Failed: line %d, file \"%s\"\n", \
                        __LINE__, __FILE__);                            \
                fflush(stderr);                                         \
                return hr;                                              \
            }                                                           \
        }
#   endif
#   ifndef MSG_ASSERT
#ifdef DIFF_DEFINE
#     if defined(__APPLE__) || defined(MACOSX)
#       define MSG_ASSERT(x, ...)                                       \
        {                                                               \
            if ( !(x) ) {                                               \
                fprintf(stderr, __VA_ARGS__);                           \
                fprintf(stderr, "Assertion Failed: %s at line %d, file \"%s\"\n", \
                        __STRING(x), __LINE__, __FILE__);               \
                abort();                                                \
            }                                                           \
        }
#     else      // define for mac
#endif /* DIFF_DEFINE */
#       define MSG_ASSERT(x, ...)                                       \
        {                                                               \
            if ( !(x) ) {                                               \
                fprintf(stderr, __VA_ARGS__);                           \
                __assert_fail(__STRING(x), __FILE__, __LINE__, __ASSERT_FUNCTION); \
            }                                                           \
        }
#ifdef DIFF_DEFINE
#     endif
#endif /* DIFF_DEFINE */
#   endif
#else
#   ifndef V
#       define V(x)         { x; }
#   endif
#   ifndef V_RETURN
#       define V_RETURN(x)  { int hr = x; if( _FAILED(hr) ) { return hr; } }
#   endif
#   ifndef MSG_ASSERT
#       define MSG_ASSERT(x, ...)   (__ASSERT_VOID_CAST (0))
#   endif
#endif

/*
 * Safely delete/release a reference
 */
#ifdef __cplusplus

#ifndef SAFE_DELETE
#   define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#   define SAFE_DELETE_ARRAY(p) { if(p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#   define SAFE_RELEASE(p)      { if(p) { (p)->Release(); (p)=NULL; } }
#endif

#ifdef DIFF_DEFINE
#endif

// Using similar macro from Linux kernel code
#if defined(likely) | defined(unlikely)
#   error likely or unlikely is already defined
#else
#   define likely(x)    __builtin_expect(!!(x), 1)
#   define unlikely(x)  __builtin_expect(!!(x), 0)
#endif /* DIFF_DEFINE */
#endif

#endif

