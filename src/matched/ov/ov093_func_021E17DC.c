/*
 * unit: yes
 * function: func_021E17DC, func_021E18E0
 * address: 0x021E17DC
 * packet: pkt_ov093_021E17DC
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E18E0 store-and-return stub included.
 * symbols:
 *   data_021F2BE8 0x021F2BE8 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void *func_021C7CF4(void *, int);
extern u8 func_021D69AC(void *, int);
extern u8 *func_021C88A4(void *, int, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern void func_021C88C8(void *, void *);
void func_021E17DC(void *a, void *b, int c)
{
    void *m;
    int x;
    int y;
    int z;
    u8 *p;
    if (c != func_021D775C(2)) return;
    m = func_021C7CF4(b, c);
    x = func_021D69AC(m, 1);
    y = func_021D69AC(m, 2);
    z = func_021D69AC(m, 0);
    if (x != 0) {
        p = func_021C88A4(b, 14, c);
        p[15] = 1;
        p[16] = c;
        *(u32 *)(p + 4) = 2;
        p[12] = -x;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 38, c);
        p[4] = c;
        p[5] = 1;
        p[6] = 0;
        func_021C88C8(b, p);
    }
    if (y != 0) {
        p = func_021C88A4(b, 14, c);
        p[15] = 1;
        p[16] = c;
        *(u32 *)(p + 4) = 4;
        p[12] = -y;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 38, c);
        p[4] = c;
        p[5] = 2;
        p[6] = 0;
        func_021C88C8(b, p);
    }
    if (z != 0) {
        p = func_021C88A4(b, 38, c);
        p[4] = c;
        p[5] = 0;
        p[6] = 0;
        func_021C88C8(b, p);
        p = func_021C88A4(b, 4, c);
        func_021C8838(p + 4, 2, 724);
        func_021C8860(p + 4, c);
        func_021C88C8(b, p);
    }
}
extern u32 data_021F2BE8[];
u32 *func_021E18E0(u32 *p)
{
    *p = 3;
    return data_021F2BE8;
}
