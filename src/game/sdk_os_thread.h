#ifndef GAME_SDK_OS_THREAD_H
#define GAME_SDK_OS_THREAD_H

#include "types.h"

/*
 * Thread queue of the SDK operating system layer (OS thread module).  A queue
 * holds the first and last thread of a list; the thread object itself is
 * defined by the files that use its fields.
 */

typedef struct _OSThread OSThread;

typedef struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
} OSThreadQueue;

#endif
