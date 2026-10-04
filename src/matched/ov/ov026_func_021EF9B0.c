/*
 * function: func_021EF9B0
 * address: 0x021EF9B0
 * packet: pkt_ov026_021EF9B0
 * region: ov026
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_020056EC 0x020056EC thumb
 */
#include "../include/Obj13039.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_02082BCC(void *, int, u32);
extern u32 func_020056EC(u32);
void func_021EF9B0(u8 *p, int b)
{
    func_02082BCC(p, 0, 64);
    ((struct Obj13039 *)p)->f38 = func_020056EC(3);
    p[1] = b;
}
