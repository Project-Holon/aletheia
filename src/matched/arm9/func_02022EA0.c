/*
 * function: func_02022EA0
 * address:  0x02022EA0
 * packet:   pkt_02022EA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MI_CpuFill8   0x02082BCC  arm
 *
 * Clear 0x30c bytes of an OBJ record, stamp the two attribute words a3/a4
 * and the mode bytes a1/a2.  a2 == 1 is the "no second slot" spelling: the
 * word at +0x304 is left alone and the two bytes sit at +0x308/+0x309.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02022EA0.c \
 *       --func func_02022EA0 --addr 0x02022EA0 --cc 1.1p1 --thumb
 */
#include "../include/Obj04050.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void MI_CpuFill8(void *dst, u32 value, u32 size);

void func_02022EA0(u8 *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    MI_CpuFill8(a0, 0, 0x30c);
    if (a2 == 1) {
        ((struct Obj04050 *)a0)->f180 = a3;
        ((struct Obj04050 *)a0)->f308 = a2;
        ((struct Obj04050 *)a0)->f309 = a1;
        return;
    }
    ((struct Obj04050 *)a0)->f180 = a3;
    ((struct Obj04050 *)a0)->f304 = a4;
    ((struct Obj04050 *)a0)->f308 = a2;
    ((struct Obj04050 *)a0)->f309 = a1;
}
