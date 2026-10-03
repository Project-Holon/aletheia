/*
 * unit: yes
 * function: func_021E37C0, func_021E38F8
 * address: 0x021E37C0
 * packet: pkt_ov093_021E37C0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E38F8 store-and-return stub included.
 * symbols:
 *   data_021F2E58 0x021F2E58 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_021E86C8 0x021E86C8 thumb ov093
 *   func_021E8638 0x021E8638 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
struct QF;
extern void *func_021C7CF4(int *p, int i);
extern int func_021D5B40(void *);
extern u16 func_021D5444(struct QF *p);
extern int func_021E86C8(void *, int);
extern int func_021E8638(int, int);
extern u32 func_0202136C(u16 v);
extern u8 *func_021C88A4(void *, int, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern void func_021C88C8(void *, void *);
void func_021E37C0(void *a, void *b, int c)
{
    u8 k;
    void *m;
    void *n;
    u16 x;
    u16 y;
    int t;
    int u;
    u8 *p;
    if (c != func_021D775C(3)) return;
    k = func_021D775C(6);
    if (func_021E86C8(b, c) != 0) return;
    m = func_021C7CF4(b, c);
    n = func_021C7CF4(b, k);
    x = func_021D5B40(m);
    y = func_021D5B40(n);
    if (x == 0 && y == 0) return;
    t = func_021D5444(m);
    u = func_021D5444(n);
    if (func_0202136C(x) != 0) return;
    if (func_0202136C(y) != 0) return;
    if (func_021E8638(t, y) != 0) return;
    if (func_021E8638(u, x) != 0) return;
    if (func_021E8638(t, x) != 0) return;
    if (func_021E8638(u, y) != 0) return;
    p = func_021C88A4(b, 36, c);
    p[4] = k;
    func_021C8838(p + 8, 2, 682);
    func_021C8860(p + 8, c);
    if (y != 0) {
        func_021C8838(p + 80, 2, 685);
        func_021C8860(p + 80, c);
        func_021C8860(p + 80, y);
    }
    if (x != 0) {
        func_021C8838(p + 44, 2, 685);
        func_021C8860(p + 44, k);
        func_021C8860(p + 44, x);
    }
    func_021C88C8(b, p);
}
extern u32 data_021F2E58[];
u32 *func_021E38F8(u32 *p)
{
    *p = 4;
    return data_021F2E58;
}
