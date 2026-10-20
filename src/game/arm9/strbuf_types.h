#ifndef GAME_ARM9_STRBUF_TYPES_H
#define GAME_ARM9_STRBUF_TYPES_H

#include "../types.h"

#define STRBUF_MAGIC 0xB6F8D2ECu

/* A bounded string of u16 characters; chars[] holds capacity entries plus the end code. */
typedef struct Strbuf {
    u16 capacity;    /* +0x00 */
    u16 length;      /* +0x02 */
    u32 magic;       /* +0x04, STRBUF_MAGIC while live */
    u16 chars[1];    /* +0x08 */
} Strbuf;

#endif
