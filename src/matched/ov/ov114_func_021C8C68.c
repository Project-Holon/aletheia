/*
 * function: func_021C8C68
 * address: 0x021C8C68
 * packet: pkt_ov114_021C8C68
 * region: ov114
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: arm
 * status: EXACT
 * symbols:
 *   d_021D3D2C 0x021D3D2C data a4
 *   d_021D3D40 0x021D3D40 data a4
 *   d_021D3E6C 0x021D3E6C data a4
 *   d_021D3D28 0x021D3D28 data a4
 *   d_021CF538 0x021CF538 data a4
 *   d_021CF654 0x021CF654 data a4
 *   func_02092344 0x02092344 arm
 *   func_021C9EE4 0x021C9EE4 arm ov114
 *   func_021CA470 0x021CA470 arm ov114
 *   func_021CA1B4 0x021CA1B4 arm ov114
 */

#include "../include/G_Six.h"

typedef struct {
    unsigned words[0x4f];
    unsigned a;
    unsigned gap[0x20];
    unsigned count, b, c;
} State;
extern State d_021D3D2C;
extern void *d_021D3D28;
extern struct Six d_021D3D40;
extern unsigned d_021D3E6C[], d_021CF538[], d_021CF654[];
extern void *func_02092344(void *, const void *, unsigned);
extern void func_021C9EE4(int server, char *initdata);
extern int func_021CA470(void *, unsigned, void *, unsigned, unsigned);
extern void func_021CA1B4(void);
void func_021C8C68(unsigned a, const void *p, unsigned c, const void *q, unsigned n)
{
    d_021D3D2C.c = c;
    func_02092344(((unsigned *)&d_021D3D40), p, 0x128);
    d_021D3D2C.a = a;
    func_02092344(d_021D3E6C, q, n);
    d_021D3D2C.count = n;
    func_021C9EE4((int)d_021D3D28, (char *)d_021CF538);
    if (func_021CA470(d_021CF654, d_021D3D2C.words[2], ((unsigned *)&d_021D3D40), 0x1b0, 0) == 0) {
        d_021D3D2C.words[0] = 16;
        return;
    }
    d_021D3D2C.words[0] = 24;
    d_021D3D2C.words[1] = -13;
    func_021CA1B4();
}
