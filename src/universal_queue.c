/*BSD 3-Clause License

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
#include <stdlib.h>
#include <stdio.h>
#include "uqpub.h"
#include "list_queue.h"
#include "universal_queue.h"

llong_t universal_queue_create(ssize_t num, ttype_t type)
{
	if (num <= 0 || type == UNIVERSAL_QUEUE_UNKNOW)
		return 0;
	universal_queue_interface* ins = (universal_queue_interface*)malloc(sizeof(universal_queue_interface));
	if (!ins)
		return ins;
	if (type == UNIVERSAL_QUEUE_LIST)
	{
		ins->any_queue = list_queue_create(ins, num);
		self_register(ins);
	}
}
ssize_t universal_queue_insert(llong_t ins, llong_t it)
{
	universal_queue_interface* hd = (universal_queue_interface*)ins;
	return hd->insert(ins, it);
}

ssize_t universal_queue_remove(llong_t ins, llong_t it)
{

}

llong_t universal_queue_destory(llong_t ins)
{

}

ssize_t universal_queue_reset(llong_t ins)
{

}

llong_t universal_queue_front(llong_t ins)
{

}

llong_t universal_queue_tail(llong_t ins)
{

}


