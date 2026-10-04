/*
 * function: func_021CA128
 * address: 0x021CA128
 * packet: pkt_ov093_021CA128
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9934 0x021B9934 thumb ov093
 *   func_021BD60C 0x021BD60C thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Bits { u32 low : 8; u32 index : 5; u32 high : 19; };
extern u8 *func_021B9934(char *p, int i);
extern int func_021BD60C(u8 *, u8 *, u8);
int func_021CA128(u8 *p, struct Bits *q)
{
    u8 *a = func_021B9934(*(char * *)&((struct Obj00003 *)p)->f8, (u8)q->index);
    if (func_021BD60C(p, a, 1)) {
        ((struct Obj00003 *)p)->f14 = 5;
        return 1;
    }
    return 0;
}
