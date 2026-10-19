#ifndef EVENT_COMM_ERROR_SHARED_TYPES_H
#define EVENT_COMM_ERROR_SHARED_TYPES_H

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef struct GameSystem GameSystem;

typedef struct GameEvent GameEvent;

/* Values an event function returns to the event runner. */
enum {
    EVENT_CONTINUE,
    EVENT_FINISHED
};

typedef int (*GameEventFunc)(GameEvent *event, int *seq, void *work);

#endif
