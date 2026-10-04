/*
 * function: func_02025774
 * address:  0x02025774
 * packet:   pkt_02025774
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B3DC  0x0204B3DC  arm
 */
#include "../include/Obj08786.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Obj;
extern void func_0204B3DC(struct Obj *p, unsigned int v);

void func_02025774(u8 *g, u32 a)
{
    u8 i;
    u8 j;

    for (i = 0; i < ((struct Obj08786 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08786 *)g)->fCA; j++) {
            func_0204B3DC(*(void **)(g + 4 + (i * ((struct Obj08786 *)g)->fCA + j) * 4), a);
        }
    }
}
