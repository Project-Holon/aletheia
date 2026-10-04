/*
 * function: func_021E95CC
 * address:  0x021E95CC
 * packet:   pkt_ov170_021E95CC
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020260F0 0x020260F0 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_021E8F90 0x021E8F90 thumb
 *
 * Enters state 9 with reason v.
 */
#include "../include/Obj00000.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
struct Sound;
extern u32 func_020260F0(struct Sound *obj);
extern void func_020355D8(u8 v);
extern int func_021E8F90(void *p, int a);

#define WORK(p) (*(char **)((p) + 0x2C))

int func_021E95CC(unsigned char *p, unsigned char v)
{
    if (func_020260F0(*(void **)(WORK(p) + 0x70)) == 1)
        func_020355D8(0);
    else
        func_020355D8(1);
    ((struct Obj00000 *)p)->f28 = 9;
    p[0x12] = v;
    return func_021E8F90(p, 1);
}
