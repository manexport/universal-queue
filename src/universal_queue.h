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

	typedef enum universal_queue_error_e
	{
		universal_queue_error_none=0x00,
		universal_queue_invalid_arg,
		universal_queue_err_unknown=-1,
	}universal_queue_error;
	typedef enum universal_queue_type_e
	{
		UNIVERSAL_QUEUE_LIST = 0x00,
		UNIVERSAL_QUEUE_HEAP,
		UNIVERSAL_QUEUE_ARRAY,
		UNIVERSAL_QUEUE_UNKNOW = -1
	}universal_queue_type;

	//struct universal_queue_interfaces;
	typedef universal_queue_type  uqtype;
	//typedef universal_queue_error uqerror;
	//typedef universal_queue_interfaces universal_queue_interfaces;

	typedef struct {
		ullong (*universal_queue_create)(ssize_t num, uqtype type);
		ssize_t(*universal_queue_insert)(ullong ins, ullong it);
		ssize_t(*universal_queue_remove)(ullong ins, ullong it);
		ullong (*universal_queue_destory)(ullong ins);
		ssize_t(*universal_queue_reset)(ullong ins);
		ullong (*universal_queue_front)(ullong ins);
		ullong (*universal_queue_tail)(ullong ins);
	}universal_queue_api;


universal_queue_api*  _universal_queue_api;

#define universal_queue_create      _universal_queue_api->universal_queue_create
#define universal_queue_insert      _universal_queue_api->universal_queue_insert
#define universal_queue_remove      _universal_queue_api->universal_queue_remove
#define universal_queue_destory     _universal_queue_api->universal_queue_destory
#define universal_queue_reset       _universal_queue_api->universal_queue_reset
#define universal_queue_front       _universal_queue_api->universal_queue_front
#define universal_queue_tail        _universal_queue_api->universal_queue_tail
#ifdef __cplusplus
}
#endif
#endif // __UNIVERSAL_QUEUE_H__