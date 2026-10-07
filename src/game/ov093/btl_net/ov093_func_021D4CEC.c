/*
 * function: func_021D4CEC
 * address: 0x021D4CEC
 * packet: pkt_ov093_021D4CEC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * Lever: shared entry pointer, based at +0xbf4, preserves the single
 * global read and the +0xbb8/+0xbba field offsets within each iteration.
 * symbols:
 *   d_021F3B88 0x021F3B88 data ov093 a4
 */
#include "../../../matched/include/Obj13433.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *d_021F3B88;
void func_021D4CEC(void)
{
    int i;
    u8 *p;
    for (i = 0; i < 4; i++) {
        p = d_021F3B88 + 0xbf4 + i * 0xbbc;
        ((struct Obj13433 *)p)->fBB8 = 0;
        ((struct Obj13433 *)p)->fBBA = 1;
    }
}
