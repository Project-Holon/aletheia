/*
 * function: func_021B6E88
 * address:  0x021B6E88
 * packet:   pkt_021B6868
 * region:   ov172
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Copies one 8-byte entry in and steps the +4 cursor.
 *
 * symbols:
 *   func_021B6EC4  0x021B6EC4  thumb  ov172
 *   func_021B6ECC  0x021B6ECC  thumb  ov172
 *   MI_CpuCopy8  0x02082D44  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj04549.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u8 *func_021B6EC4(void *p, int i);
extern void func_021B6ECC(void *o, u16 *c);
extern void  MI_CpuCopy8(void *a, void *b, int c);

void func_021B6E88(char *p, void *q)
{
    MI_CpuCopy8(q, func_021B6EC4(p, ((struct Obj04549 *)p)->f4), 8);
    func_021B6ECC(p, (u16 *)(p + 4));
}
