/*
 * function: func_021F36C0
 * address:  0x021F36C0
 * packet:   pkt_ov037_021F36C0
 * region:   ov037
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Cross-overlay collision: the same address is also resident in ov039.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EC4  0x02012EC4  thumb
 *   func_0200B3A4  0x0200B3A4  thumb
 */
#include "../include/Obj13080.h"

typedef unsigned char  u8;
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 *func_02012EC4(struct Big *p);
extern void *func_0200B3A4(unsigned int, unsigned int);

void func_021F36C0(unsigned int a0, int a1, int a2)
{
    char *p = func_0200B3A4((unsigned int)func_02012EC4(func_020120F4((const struct Ctx *)a0)), 2);

    if (a1)
        ((struct Obj13080 *)p)->f14 = 1;
    if (a2)
        ((struct Obj13080 *)p)->f16 = 1;
}
