/*
 * function: BMP_OAM_SetPalette
 * address:  0x02025A54
 * packet:   pkt_0202590C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0204B6F4  0x0204B6F4  arm
 */
#include "../include/Obj08790.h"

typedef signed char    s8;
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Obj;
extern void func_0204B6F4(struct Obj *o, u32 v, u32 flag);

void BMP_OAM_SetPalette(u8 *g, u32 a)
{
    int i;
    int j;

    for (i = 0; i < ((struct Obj08790 *)g)->fCB; i++) {
        for (j = 0; j < ((struct Obj08790 *)g)->fCA; j++) {
            func_0204B6F4(*(void **)(g + 4 + (i * ((struct Obj08790 *)g)->fCA + j) * 4), a, 0);
        }
    }
}
