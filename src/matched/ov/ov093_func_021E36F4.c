/*
 * unit: yes
 * function: func_021E36F4, func_021E37B4
 * address: 0x021E36F4
 * packet: pkt_ov093_021E36F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E37B4 store-and-return stub included.
 * symbols:
 *   data_021F2824 0x021F2824 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021E86E8 0x021E86E8 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../include/Obj10083.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
typedef unsigned short u16;
struct QI;
extern void *func_021C7CF4(int *p, int i);
extern u16 func_021D5B40(struct QI *p);
extern int func_021E86E8(void *, int, int);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *p, u32 val);
extern void func_021C88C8(void *, void *);
void func_021E36F4(void *a, void *b, int c, int *d)
{
    u8 k;
    void *m;
    u8 *p;
    if (c != func_021D775C(3)) return;
    if (func_021D5B40(func_021C7CF4(b, c)) != 0) return;
    if (*d != 0) return;
    k = func_021D775C(6);
    if (k == 31) return;
    m = func_021C7CF4(b, k);
    if (func_021D5B40(m) == 0) return;
    if (func_021E86E8(b, c, k) != 0) return;
    p = func_021C88A4(b, 36, c);
    p[4] = k;
    func_021C8838(p + 8, 2, 1057);
    func_021C8860((struct S *)(p + 8), c);
    func_021C8860((struct S *)(p + 8), k);
    func_021C8860((struct S *)(p + 8), func_021D5B40(m));
    func_021C88C8(b, p);
    p = func_021C88A4(b, 58, c);
    ((struct Obj10083 *)p)->f0 |= 0x1000000;
    p[4] = 1;
    func_021C88C8(b, p);
}
extern u32 data_021F2824[];
u32 *func_021E37B4(u32 *p)
{
    *p = 1;
    return data_021F2824;
}
