/*
 * function: func_021EC338
 * address:  0x021EC338
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *
 * Forward with a resolved handle and the object table entry.
 */
#include "../include/Obj18519.h"

typedef unsigned int   u32;
extern u32 func_0201BA68(void *mon);
typedef unsigned short u16;
extern void *func_02049E74(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);

void func_021EC338(char *p, void *b, void *c)
{
    func_02049E74((void *)(((struct Obj18519 *)p)->f1B0), func_0201BA68(b), 0, (u32)c, 0x4c);
}

