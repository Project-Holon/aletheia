/*
 * function: func_021C941C
 * address: 0x021C941C
 * packet: pkt_ov114_021C941C
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D3EFC 0x021D3EFC data a4
 *   d_021D4084 0x021D4084 data a4
 *   d_021CF6D4 0x021CF6D4 data a4
 *   d_021CF714 0x021CF714 data a4
 *   d_021D4098 0x021D4098 data a4
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 */

#include "../../../matched/include/G_Block.h"

extern void *d_021D3EFC;
extern struct Block d_021D4098;
extern unsigned d_021D4084[], d_021CF6D4[], d_021CF714[];
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
void func_021C941C(unsigned x)
{
    ((unsigned char *)d_021D4084)[0x14] = x - 1;
    func_021C9EE4((int)d_021D3EFC, (char *)d_021CF6D4);
    if (func_021CA470(d_021CF714, d_021D4084[2], ((unsigned *)&d_021D4098), 1, 0) == 0) {
        d_021D4084[0] = 2;
        return;
    }
    d_021D4084[0] = 12;
    d_021D4084[1] = -5;
    func_021CA1B4();
}
