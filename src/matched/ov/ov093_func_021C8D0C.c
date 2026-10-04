/*
 * function: func_021C8D0C
 * address: 0x021C8D0C
 * packet: pkt_ov093_021C8D0C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: caller narrows index to u8 before func_021B9934.
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C5A34 0x021C5A34 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef struct { u32 pad : 8; u32 idx : 5; u32 rest : 19; } Ent;
extern u8 *func_021B9934(char *p, int i);
extern void func_021C5A34(u8 *p, u8 *a);
int func_021C8D0C(u8 *p, Ent *e)
{
    func_021C5A34(p, func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)e->idx));
    return 1;
}
