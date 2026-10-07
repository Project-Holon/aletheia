/*
 * function: func_021C87FC
 * address:  0x021C87FC
 * packet:   pkt_ov114_021C87FC
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbol overlay hints are deliberately omitted: `d_021D3D40` lives in
 * overlapping bss, and naming ov114 explicitly makes the hint contested,
 * while leaving it off lets the function's own region disambiguate.
 *
 * symbols:
 *   d_021D3D28   0x021D3D28  data  a4
 *   d_021D3D2C   0x021D3D2C  data  a4
 *   d_021CF538   0x021CF538  data  a4
 *   d_021CF5B8   0x021CF5B8  data  a4
 *   d_021D3D40   0x021D3D40  data  a4
 *   func_021C9EE4 0x021C9EE4  arm
 *   func_021CA470 0x021CA470  arm
 *   func_021CA1B4 0x021CA1B4  arm
 */

#include "../include/G_Six.h"

extern unsigned int *d_021D3D28;
extern unsigned int d_021D3D2C[];
extern unsigned int d_021CF538[];
extern unsigned int d_021CF5B8[];
extern struct Six d_021D3D40;

extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned int, void *, unsigned int, unsigned int);
extern void func_021CA1B4(void);

void func_021C87FC(unsigned int x)
{
    d_021D3D2C[0x72] = x;
    func_021C9EE4((int)((void *)d_021D3D28), (char *)d_021CF538);
    if (func_021CA470(d_021CF5B8, d_021D3D2C[2], ((unsigned int *)&d_021D3D40), 0x1b0, 0) == 0) {
        d_021D3D2C[0] = 6;
        return;
    }
    d_021D3D2C[0] = 0x18;
    d_021D3D2C[1] = -0x0d;
    func_021CA1B4();
}
