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
#include "pthread.h"
#include "uqpub.h"
#include "list_queue.h"

typedef struct
{
	struct _list_node* next;
	struct _list_node* prev;
	pthread_mutex_t list_mutex;
	llong_t node_num;
}list_head;
typedef struct _list_node
{ 
	struct _list_node* next;
	struct _list_node* prev;
	llong_t data;
}list_node;
static llong_t self_register(llong_t ins)
{
	universal_queue_interface* hd = (universal_queue_interface*)ins;
	hd->create = list_queue_create;
	hd->insert = list_queue_insert;
	hd->destory = list_queue_destory;
	hd->front = list_queue_front;
	hd->tail = list_queue_tail;
	hd->reset = list_queue_reset;
	return 0;
}

static llong_t self_unregister(llong_t ins)
{
	universal_queue_interface* hd = (universal_queue_interface*)ins;
	hd->create = hd->insert= hd->destory= hd->front= hd->tail= hd->reset=NULL;
	return 0;
}

llong_t list_queue_create(llong_t ins, ssize_t num)
{
	list_head* llq = (list_head*)malloc(sizeof(list_head));
	llq->next = llq->prev = NULL;
	llq->node_num = 0;
	pthread_mutex_init(&llq->list_mutex, NULL);
	return llq;
}

ssize_t list_queue_insert(llong_t ins, llong_t it)
{

}

ssize_t list_queue_remove(llong_t ins, llong_t it)
{

}

llong_t list_queue_destory(llong_t ins)
{
	list_head* llq = (list_head*)malloc(sizeof(list_head));
	llq->next = llq->prev = NULL;
	llq->node_num = 0;
}

ssize_t list_queue_reset(llong_t ins)
{
	list_head* llq = (list_head*)malloc(sizeof(list_head));
	llq->next = llq->prev = NULL;
	llq->node_num = 0;
	pthread_mutex_init(&llq->list_mutex, NULL);
}

llong_t list_queue_front(llong_t ins)
{

}

llong_t list_queue_tail(llong_t ins)
{

}

