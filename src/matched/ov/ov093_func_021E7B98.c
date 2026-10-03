/*
 * unit: yes
 * function: func_021E7B98, func_021E7C6C
 * address: 0x021E7B98
 * packet: pkt_ov093_021E7B98
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D775C 0x021D775C thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   func_021D5B40 0x021D5B40 thumb ov093
 *   func_0202136C 0x0202136C thumb
 *   func_021E869C 0x021E869C thumb ov093
 *   func_021D5444 0x021D5444 thumb ov093
 *   func_021E8638 0x021E8638 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   d_021F2AE8 0x021F2AE8 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021D775C(int);
extern void *func_021C7CF4(int, int);
extern int func_021D5B40(void *);
extern u32 func_0202136C(u16);
extern int func_021E869C(int, int);
struct QF;
extern u16 func_021D5444(struct QF *p);
extern int func_021E8638(int, int);
extern u8 *func_021C88A4(int, int, int);
extern void func_021C8838(void *, int, int);
extern void func_021C8860(void *, u32);
extern void func_021C88C8(int, u8 *);
extern int d_021F2AE8[];

void func_021E7B98(int a, int b, int c)
{
    u8 k;
    void *x;
    u16 h;
    u8 *p;
    if (c == func_021D775C(3)) {
        k = func_021D775C(6);
        x = func_021C7CF4(b, k);
        h = func_021D5B40(func_021C7CF4(b, c));
        if (h != 0 && func_0202136C(h) == 0 && func_021D5B40(x) == 0
            && func_021E869C(b, c) == 0 && func_021E869C(b, k) == 0
            && func_021E8638(func_021D5444(x), h) == 0) {
            p = func_021C88A4(b, 0x20, c);
            p[6] = c;
            *(u16 *)(p + 4) = 0;
            func_021C88C8(b, p);
            p = func_021C88A4(b, 0x20, c);
            p[6] = k;
            *(u16 *)(p + 4) = h;
            func_021C8838(p + 12, 2, 0x457);
            func_021C8860(p + 12, k);
            func_021C8860(p + 12, c);
            func_021C8860(p + 12, h);
            func_021C88C8(b, p);
        }
    }
}

int *func_021E7C6C(int *p)
{
    *p = 2;
    return d_021F2AE8;
}
