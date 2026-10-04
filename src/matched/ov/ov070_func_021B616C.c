/*
 * function: func_021B616C
 * address: 0x021B616C
 * packet: pkt_ov070_021B616C
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020081DC 0x020081DC thumb
 */
#include "../include/Obj00002.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void *func_020081DC(void *, u16, u16, unsigned int);
void *func_021B616C(u8 *p, int i)
{
    if (*(int *)&((struct Obj00002 *)p)->f81C) return (void *)((unsigned int)p + 0x20U + (unsigned int)i * 4U);
    return func_020081DC(((struct Obj00002 *)p)->f18, ((struct Obj00002 *)p)->f80C, i, (unsigned int)p);
}
