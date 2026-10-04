/*
 * function: func_021C9DCC
 * address: 0x021C9DCC
 * packet: pkt_ov093_021C9DCC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021C195C 0x021C195C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021B9934(char *p, int i);
extern void func_021C195C(u8 *, u8 *, u32);
int func_021C9DCC(u8 *p, u8 *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, q[4]);
    func_021C195C(p, a, *(u32 *)(q + 8));
    return 1;
}
