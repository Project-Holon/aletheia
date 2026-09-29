/*
 * unit:     yes
 * function: func_021E6278, func_021E62E8
 * address:  0x021E6278
 * packet:   pkt_ov093_021E6278
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D775C  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   func_021D5BB0  0x021D5BB0  thumb  ov093
 *   func_021C88A4  0x021C88A4  thumb  ov093
 *   func_021C88C8  0x021C88C8  thumb  ov093
 *   func_021C8838  0x021C8838  thumb  ov093
 *   func_021C8860  0x021C8860  thumb  ov093
 *   d_021F2AA8     0x021F2AA8  data   ov093  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_021D775C(int key);
extern void *func_021C7CF4(void *a, int b);
extern int func_021D5BB0(void *q, u32 n);
extern void *func_021C88A4(void *a, int k, int b);
extern void func_021C88C8(void *a, void *b);
extern void func_021C8838(void *p, int a, int b);
extern void func_021C8860(void *p, u32 v);
extern int d_021F2AA8[];

void func_021E6278(int u, void *a, u32 b)
{
    u8 *e;
    u8 k;

    if (b == func_021D775C(3)) {
        k = func_021D775C(6);
        if (func_021D5BB0(func_021C7CF4(a, k), 7) != 0) {
            e = func_021C88A4(a, 0x16, b);
            e[8] = k;
            *(u32 *)(e + 4) = 7;
            func_021C88C8(a, e);
            e = func_021C88A4(a, 4, b);
            func_021C8838(e + 4, 2, 0x208);
            func_021C8860(e + 4, k);
            func_021C88C8(a, e);
        }
    }
}

int *func_021E62E8(int *p)
{
    *p = 2;
    return d_021F2AA8;
}
