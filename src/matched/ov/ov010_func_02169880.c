/*
 * function: func_02169880
 * address:  0x02169880
 * packet:   pkt_ov010_02169880
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * The second loop's final store goes through the +0x9C array, as the bytes show.
 *
 * symbols:
 */
#include "../include/Obj12387.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct E {
    int a;
    int b;
    int c;
    int d;
    u16 e;
} E;

void func_02169880(u8 *p)
{
    int i;
    E *e;

    for (i = 0; i < ((struct Obj12387 *)p)->fA4; i++) {
        (*(E **)(p + 0x9c))[i].a = -1;
        e = &(*(E **)(p + 0x9c))[i];
        e->b = 0;
        e->c = 0;
        e->d = 0;
        (*(E **)(p + 0x9c))[i].e = 0;
    }
    for (i = 0; i < ((struct Obj12387 *)p)->fA6; i++) {
        (*(E **)(p + 0xa0))[i].a = -1;
        e = &(*(E **)(p + 0xa0))[i];
        e->b = 0;
        e->c = 0;
        e->d = 0;
        (*(E **)(p + 0x9c))[i].e = 0;
    }
}
