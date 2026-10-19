#ifndef EVENT_COMM_ERROR_SHARED_TYPES_H
#define EVENT_COMM_ERROR_SHARED_TYPES_H

#include "../types.h"

typedef struct GameSystem GameSystem;

typedef struct GameEvent GameEvent;

/* Values an event function returns to the event runner. */
enum {
    EVENT_CONTINUE,
    EVENT_FINISHED
};

typedef int (*GameEventFunc)(GameEvent *event, int *seq, void *work);

#endif
