/*
 * function: func_021BF47C
 * address:  0x021BF47C
 * packet:   pkt_ov217_021BF47C
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BF810 0x021BF810 thumb ov217
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00021.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern u32 func_021BF810(void *p);
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *a, unsigned int b);
void func_021BF47C(char *p)
{
    if (((struct Obj00021 *)p)->f3C8 == 0 || func_021BF810(p) == 0) {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00021 *)p)->f39C, 0);
    } else {
        CLACT_SetActorDrawEnable((struct Obj *)((struct Obj00021 *)p)->f39C, 1);
    }
}
