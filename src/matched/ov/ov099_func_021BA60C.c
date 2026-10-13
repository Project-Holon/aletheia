/*
 * function: func_021BA60C
 * address: 0x021BA60C
 * packet: pkt_ov099_021BA60C
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   func_02049F34 0x02049F34 arm
 *   d_021C2878 0x021C2878 data ov099 a2
 */
#include "../include/Obj06351.h"
#include "../include/Obj22018.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MI_CpuFill8(void *, u32, u32);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern const u16 d_021C2878[];
void func_021BA60C(char *a, char *p, u32 unused, u32 arc)
{
    MI_CpuFill8(p, 0, 20);
    ((struct Obj06351 *)p)->f0 = func_02049F34(arc, 9, (u32)(p + 4), (u16)(((struct Obj22018 *)a)->f4));
    p[9] = 0;
    p[8] = 15;
    ((struct Obj06351 *)p)->fA = d_021C2878[(u8)p[9]];
}
