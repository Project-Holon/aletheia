/*
 * function: BMP_OAM_SetObjMode
 * address:  0x0202597C
 * packet:   pkt_0202590C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0204B688  0x0204B688  arm
 */
#include "../include/Obj08787.h"

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Actor;
extern void func_0204B688(struct Actor *actor, u32 value);

void BMP_OAM_SetObjMode(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08787 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08787 *)g)->fCA; j++) {
            func_0204B688(*(void **)(g + 4 + (i * ((struct Obj08787 *)g)->fCA + j) * 4), a);
        }
    }
}
