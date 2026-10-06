/*
 * unit: yes
 * function: func_021B65A8, func_021B65B4
 * address: 0x021B65A8
 * packet: pkt_ov067_021B65A8
 * region: ov067
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Extent includes the unlabelled tail-call follower at 0x021B65B4.
 * symbols:
 *   func_021B6600 0x021B6600 thumb ov067
 *   func_021B69F8 0x021B69F8 thumb ov067
 *   func_021B6548 0x021B6548 thumb ov067
 */
#include "../include/Obj07675.h"
extern void *func_021B6600(unsigned char *p, unsigned int id);
typedef unsigned int   u32;
extern u32 func_021B69F8(u32 p);
extern int func_021B6548(unsigned char *p, unsigned int id, int v);

int func_021B65A8(unsigned char *p, int id)
{
    return func_021B69F8((u32)func_021B6600(p, id));
}

int func_021B65B4(unsigned char *p, unsigned int id)
{
    *(int *)&((struct Obj07675 *)p)->f8 = 0;
    *(int *)&((struct Obj07675 *)p)->f0 = -1;
    return func_021B6548(p, id, 1);
}
