/*
 * file:     btl_net_p14.c
 * unit:     yes
 * function: func_021D4EFC, func_021D4F84
 * address:  0x021D4EFC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02017E1C  0x02017E1C  thumb
 *   func_021D52B4  0x021D52B4  thumb ov093
 *   func_02019C90  0x02019C90  thumb
 *   func_02017D30 0x02017D30 thumb
 *   func_02017D70 0x02017D70 thumb
 *   func_021D5244 0x021D5244 thumb ov093
 */
struct Sav;
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

struct Ent {u16 h[6]; u8 fC,fD;};

struct Bits {u8 lo:4,hi:4;};

extern u32 func_02017E1C(void *p, u32 id, u32 buf);
extern void func_021D52B4(u8 *p, void *h, u32 flag);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern u32 func_02017D30(struct Sav *p);
extern u32 func_02017D70(struct Sav *p, u32 f);
extern int func_021D5244(struct Ent *,void *,u8);
void func_021D4EFC(struct S *a, void *mon, u32 c, u32 d);
int func_021D4F84(u8 *p, void *h, int reset);


void func_021D4EFC(struct S *a, void *mon, u32 c, u32 d)
{
    if (c != 0) {
        a->f10 = func_02017E1C(mon, 0xa0, 0);
        a->f0e = func_02017E1C(mon, 0xa1, 0);
    }
    a->f08 = func_02017E1C(mon, 8, 0);
    func_021D52B4((u8 *)a, mon, d);
    if (d != 0) {
        a->f13c = func_02017E1C(mon, 0xa, 0);
    }
    a->f141 = func_02017E1C(mon, 0x6f, 0);
    a->f13e = func_02019C90(a->f0c, a->f141, 0x26);
    if (a->f13e < 1) {
        a->f13e = 1;
    }
}

int func_021D4F84(u8 *p, void *h, int reset)
{
    u8 t = func_02017D30(h);
    u32 count = 0;
    u32 i;
    if (reset) {
        for (i = 0; i < 4; i++) {
            ((struct Bits *)(p + 0x109 + i * 14))->lo = 0;
            ((struct Bits *)(p + 0x109 + i * 14))->hi = 0;
        }
    }
    for (i = 0; i < 4; i++) {
        if (func_021D5244(&((struct Ent *)(p + 0x104))[i],h,i)) count++;
    }
    if (reset) {
        for (i = 0; i < 4; i++) {
            *(u16 *)(p + i * 14 + 0x10a) = *(u16 *)(p + i * 14 + 0x104);
            *(u16 *)(p + i * 14 + 0x10c) = *(u16 *)(p + i * 14 + 0x106);
            *(u16 *)(p + i * 14 + 0x10e) = *(u16 *)(p + i * 14 + 0x108);
            (p + i * 14)[0x110] = 1;
        }
    }
    func_02017D70(h,t);
    return count;
}
