/*
BSD 3-Clause License

Copyright (c) 2020, manexport<manexport@yeah.net>
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#ifndef __UNIVERSAL_QUEUE_H__
#define __UNIVERSAL_QUEUE_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifdef UNIVERSAL_QUEUE_STATICLIB
#  define UNIVERSAL_QUEUE_EXTERN
#elif defined(_WIN32)					 
#  ifdef UNIVERSAL_QUEUE_EXPORTS
#    define UNIVERSAL_QUEUE_EXTERN __declspec(dllexport)
#  else /* !UNIVERSAL_QUEUE_EXPORTS */
#    define UNIVERSAL_QUEUE_EXTERN __declspec(dllimport)
#  endif /* !UNIVERSAL_QUEUE_EXPORTS */
#else    /* !defined(_WIN32) */
#  ifdef UNIVERSAL_QUEUE_EXPORTS
#    define UNIVERSAL_QUEUE_EXTERN __attribute__((visibility("default")))
#  else /* !UNIVERSAL_QUEUE_EXPORTS */
#    define UNIVERSAL_QUEUE_EXTERN
#  endif /* !UNIVERSAL_QUEUE_EXPORTS */
#endif   /* !defined(_WIN32) */

#include "config.h"

	typedef enum
	{
		UNIVERSAL_QUEUE_ERROR_NONE = 0x00,
		UNIVERSAL_QUEUE_INVALID_ARG,
		UNIVERSAL_QUEUE_BUFFER_ERROR,
		UNIVERSAL_QUEUE_ERR_FATAL,
		UNIVERSAL_QUEUE_ERR_NOMEM,
		UNIVERSAL_QUEUE_ERR_UNKNOWN = -1,
	}UNIVERSAL_QUEUE_ERR;
	typedef enum 
	{
		UNIVERSAL_QUEUE_LIST = 0x00,
		UNIVERSAL_QUEUE_HEAP,
		UNIVERSAL_QUEUE_ARRAY,
		UNIVERSAL_QUEUE_UNKNOW = -1
	}universal_queue_type;
	typedef struct universal_queue_interface;
	typedef universal_queue_type  ttype_t;
	UNIVERSAL_QUEUE_EXTERN llong_t universal_queue_create(ssize_t num, ttype_t type);
	UNIVERSAL_QUEUE_EXTERN ssize_t universal_queue_insert(llong_t ins, llong_t it);
	UNIVERSAL_QUEUE_EXTERN ssize_t universal_queue_remove(llong_t ins, llong_t it);
	UNIVERSAL_QUEUE_EXTERN llong_t universal_queue_destory(llong_t ins);
	UNIVERSAL_QUEUE_EXTERN ssize_t universal_queue_reset(llong_t ins);
	UNIVERSAL_QUEUE_EXTERN llong_t universal_queue_front(llong_t ins);
	UNIVERSAL_QUEUE_EXTERN llong_t universal_queue_tail(llong_t ins);

#ifdef __cplusplus
}
#endif
#endif // __UNIVERSAL_QUEUE_H__