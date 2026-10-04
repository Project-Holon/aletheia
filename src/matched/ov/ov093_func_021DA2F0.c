/*
 * unit: yes
 * function: func_021DA2F0, func_021DA320
 * address: 0x021DA2F0
 * packet: pkt_ov093_021DA2F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021F07F0 0x021F07F0 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 * extent: includes store-and-return followers 021DA320.
 */
#include "../include/Obj07811.h"
extern unsigned char d_021F07F0[];
extern int func_021D775C(int);
extern void *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, void *);

void func_021DA2F0(int a, void *b, int c)
{
    unsigned char *p;
    if (c == func_021D775C(2)) {
        p = func_021C88A4(b, 11, c);
        ((struct Obj07811 *)p)->f4 = 0x24;
        p[0x14] = 1;
        p[8] = c;
        p[0x15] = 1;
        func_021C88C8(b, p);
    }
}

void *func_021DA320(int *p)
{
    *p = 1;
    return d_021F07F0;
}
