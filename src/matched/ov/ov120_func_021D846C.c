/*
 * function: func_021D846C
 * address:  0x021D846C
 * packet:   pkt_021D846C
 * region:   ov120
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202DC08  0x0202DC08  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00286.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Obj;
extern void func_0202DC08(struct Obj *p);

void func_021D846C(u8 *p)
{
    if (((struct Obj00286 *)p)->fCC) {
        func_0202DC08(((struct Obj00286 *)p)->fCC);
        *(u32 *)&((struct Obj00286 *)p)->fCC = 0;
    }
}
