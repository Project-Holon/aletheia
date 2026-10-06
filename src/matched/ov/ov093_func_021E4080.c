/*
 * unit: yes
 * function: func_021E4080, func_021E4148
 * address: 0x021E4080
 * packet: pkt_ov093_021E4080
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E4148 store-and-return stub included after two padding bytes.
 * symbols:
 *   data_021F27B4 0x021F27B4 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
#include "../include/Obj02790.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void *func_021C7CF4(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
extern void func_021C88C8(void *, void *);
void func_021E4080(void *a, void *b, int c)
{
    u8 k;
    void *m;
    void *n;
    u32 x;
    u32 y;
    u32 avg;
    u8 *p;
    if (c != func_021D775C(3)) return;
    k = func_021D775C(6);
    m = func_021C7CF4(b, c);
    n = func_021C7CF4(b, k);
    x = func_021D59B4(m, 13);
    y = func_021D59B4(n, 13);
    avg = (x + y) / 2;
    p = func_021C88A4(b, 8, c);
    p[4] = 2;
    p[7] = c;
    ((struct Obj02790 *)p)->f10 = avg - x;
    p[8] = k;
    ((struct Obj02790 *)p)->f14 = avg - y;
    p[6] = 1;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 4, c);
    func_021C8838(p + 4, 1, 113);
    func_021C88C8(b, p);
    p = func_021C88A4(b, 33, c);
    p[4] = c;
    ((struct Obj02790 *)p)->f8 = 1;
    func_021C88C8(b, p);
    p = func_021C88A4(b, 33, c);
    p[4] = k;
    ((struct Obj02790 *)p)->f8 = 1;
    func_021C88C8(b, p);
}
extern u32 data_021F27B4[];
u32 *func_021E4148(u32 *p)
{
    *p = 1;
    return data_021F27B4;
}
