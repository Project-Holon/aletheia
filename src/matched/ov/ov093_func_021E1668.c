/*
 * unit: yes
 * function: func_021E1668, func_021E1778
 * address: 0x021E1668
 * packet: pkt_ov093_021E1668
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * follower: 021E1778 store-return stub included; zero local reused for n+1.
 * symbols:
 *   data_021F2BD0 0x021F2BD0 data a4
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D69AC 0x021D69AC thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void *func_021C7CF4(void *, int);
extern u8 func_021D69AC(void *, int);
extern u8 *func_021C88A4(void *, int, int);
extern void func_021C88C8(void *, void *);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
void func_021E1668(int unused, void *q, int id)
{
    void *m;
    u8 *r;
    u32 n;
    int zero;
    if (id == func_021D775C(3)) {
        m = func_021C7CF4(q, id);
        zero = 0;
        n = func_021D69AC(m, 0);
        if (n >= 3) return;
        r = func_021C88A4(q, 38, id);
        r[4] = id;
        r[5] = zero;
        zero = n + 1;
        r[6] = zero;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 4, id);
        func_021C8838(r + 4, 2, 0x2d1);
        func_021C8860(r + 4, id);
        func_021C8860(r + 4, zero);
        func_021C88C8(q, r);
        r = func_021C88A4(q, 14, id);
        r[15] = 1;
        r[16] = id;
        *(int *)(r + 4) = 2;
        r[12] = 1;
        r[14] = 1;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 38, id);
        *(u32 *)r |= 0x1000000;
        r[4] = id;
        r[5] = 1;
        r[6] = func_021D69AC(m, 1) + 1;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 14, id);
        r[15] = 1;
        r[16] = id;
        *(int *)(r + 4) = 4;
        r[12] = 1;
        r[14] = 1;
        func_021C88C8(q, r);
        r = func_021C88A4(q, 38, id);
        *(u32 *)r |= 0x1000000;
        r[4] = id;
        r[5] = 2;
        r[6] = func_021D69AC(m, 2) + 1;
        func_021C88C8(q, r);
    }
}
extern u32 data_021F2BD0[];
u32 *func_021E1778(u32 *p)
{
    *p = 3;
    return data_021F2BD0;
}
