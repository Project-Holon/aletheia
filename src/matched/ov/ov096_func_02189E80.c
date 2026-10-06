/*
 * function: func_02189E80
 * address: 0x02189E80
 * packet: pkt_ov096_02189E80
 * region: ov096
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02189E90 0x02189E90 thumb ov096
 */
#include "../include/Obj21977.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Cursor;
extern int func_02189E90(struct Cursor *a, u8 *b, int c);
int func_02189E80(struct Cursor *a, u8 *b)
{
    func_02189E90(a,b,3); return ((struct Obj21977 *)b)->fC4;
}
