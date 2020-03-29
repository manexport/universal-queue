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
#ifndef __UQPUB_H__
#define __UQPUB_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "config.h"

	typedef llong_t(*interface_queue_create)(ssize_t num);
	typedef ssize_t(*interface_queue_insert)(llong_t ins, llong_t it);
	typedef ssize_t(*interface_queue_remove)(llong_t ins, llong_t it);
	typedef llong_t(*interface_queue_destory)(llong_t ins);
	typedef ssize_t(*interface_queue_reset)(llong_t ins);
	typedef llong_t(*interface_queue_front)(llong_t ins);
	typedef llong_t(*interface_queue_tail)(llong_t ins);

	typedef struct
	{
		llong_t  any_queue;
		interface_queue_create  create;
		interface_queue_insert  insert;
		interface_queue_remove  remove;
		interface_queue_destory destory;
		interface_queue_reset   reset;
		interface_queue_front   front;
		interface_queue_tail    tail;
	}universal_queue_interface;

#ifdef __cplusplus
}
#endif
#endif // __UNIVERSAL_QUEUE_H__