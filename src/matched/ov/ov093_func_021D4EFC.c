/*
 * function: func_021D4EFC
 * address:  0x021D4EFC
 * packet:   pkt_ov093_021D4EFC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021D52B4  0x021D52B4  thumb ov093
 *   func_02019C90  0x02019C90  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct S {
    u8 pad00[8];
    u32 f08;
    u16 f0c;
    u16 f0e;
    u16 f10;
    u8 pad12[0x13c - 0x12];
    u16 f13c;
    u16 f13e;
    u8 pad140;
    u8 f141;
};

extern u32 func_02017E1C(void *p, u32 id, u32 buf);
extern void func_021D52B4(struct S *a, void *mon, u32 c);
extern u32 func_02019C90(u16 a, u16 b, u32 k);

void func_021D4EFC(struct S *a, void *mon, u32 c, u32 d)
{
    if (c != 0) {
        a->f10 = func_02017E1C(mon, 0xa0, 0);
        a->f0e = func_02017E1C(mon, 0xa1, 0);
    }
    a->f08 = func_02017E1C(mon, 8, 0);
    func_021D52B4(a, mon, d);
    if (d != 0) {
        a->f13c = func_02017E1C(mon, 0xa, 0);
    }
    a->f141 = func_02017E1C(mon, 0x6f, 0);
    a->f13e = func_02019C90(a->f0c, a->f141, 0x26);
    if (a->f13e < 1) {
        a->f13e = 1;
    }
}
