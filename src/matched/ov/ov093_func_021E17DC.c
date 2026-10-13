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
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_GetCounter 0x021D69AC thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern void *func_021C7CF4(int *p, int i);
extern unsigned char BTL_POKEPARAM_GetCounter(unsigned char *base, int idx);
extern void *func_021C88A4(char *p, int a, int b);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *, u32);
extern void func_021C88C8(void *, void *);
void func_021E17DC(void *a, void *b, int c)
{
    void *m;
    int x;
    int y;
    int z;
    u8 *p;
    if (c != BTL_EVENT_GetVar(2)) return;
    m = func_021C7CF4(b, c);
    x = BTL_POKEPARAM_GetCounter(m, 1);
    y = BTL_POKEPARAM_GetCounter(m, 2);
    z = BTL_POKEPARAM_GetCounter(m, 0);
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
        func_021C8860((struct S *)(p + 4), c);
        func_021C88C8(b, p);
    }
}
extern u32 data_021F2BE8[];
u32 *func_021E18E0(u32 *p)
{
    *p = 3;
    return data_021F2BE8;
}
