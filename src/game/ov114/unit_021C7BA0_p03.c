/*
 * file:     unit_021C7BA0_p03.c
 * unit:     yes
 * function: func_021C8D14, func_021C8DA0
 * address:  0x021C8D14
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021D3D38 0x021D3D38 data a4
 *   d_021D3D28 0x021D3D28 data a4
 *   d_021D3D40 0x021D3D40 data a4
 *   d_021CF538 0x021CF538 data a4
 *   d_021D3D2C 0x021D3D2C data a4
 *   d_021CF674 0x021CF674 data a4
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 *   d_021CF69C 0x021CF69C data a4
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "../../matched/include/G_Six.h"

extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
void func_021C8D14(void);
void func_021C8DA0(void);
extern const unsigned d_021D3D38[];
extern void *d_021D3D28;
extern unsigned d_021D3D2C[], d_021CF538[], d_021CF674[], d_021D3D40[];
extern unsigned d_021D3D2C[], d_021CF538[], d_021CF69C[];

void func_021C8D14(void)
{
    memcpy(d_021D3D40, d_021D3D38, 8);
    func_021C9EE4((int)d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF674, d_021D3D2C[2], d_021D3D40, 8, 0) == 0) {
        d_021D3D2C[0] = 18;
        return;
    }
    d_021D3D2C[0] = 24;
    d_021D3D2C[1] = -13;
    func_021CA1B4();
}

void func_021C8DA0(void)
{
    func_021C9EE4((int)d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF69C, d_021D3D2C[2], ((unsigned *)&d_021D3D40), 0, 0) == 0) {
        d_021D3D2C[0] = 20;
        return;
    }
    d_021D3D2C[0] = 24;
    d_021D3D2C[1] = -13;
    func_021CA1B4();
}
