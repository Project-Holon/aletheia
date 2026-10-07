/*
 * function: func_021C8978
 * address: 0x021C8978
 * packet: pkt_ov114_021C8978
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 * d_021D3D28 0x021D3D28 data a4
 * d_021D3D2C 0x021D3D2C data a4
 * d_021CF538 0x021CF538 data a4
 * d_021CF614 0x021CF614 data a4
 * d_021D3D40 0x021D3D40 data a4
 * func_021C9EE4 0x021C9EE4 arm ov114
 * func_021CA470 0x021CA470 arm ov114
 * func_021CA1B4 0x021CA1B4 arm ov114
 */

#include "../include/G_Six.h"

extern unsigned int *d_021D3D28;
extern struct Six d_021D3D40;
extern unsigned int d_021D3D2C[], d_021CF538[], d_021CF614[];
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned int, void *, unsigned int, unsigned int);
extern void func_021CA1B4(void);
void func_021C8978(void)
{
    func_021C9EE4((int)d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF614, d_021D3D2C[2], ((unsigned int *)&d_021D3D40), 0, 0) == 0) {
        d_021D3D2C[0] = 12;
        return;
    }
    d_021D3D2C[0] = 0x18;
    d_021D3D2C[1] = -13;
    func_021CA1B4();
}
