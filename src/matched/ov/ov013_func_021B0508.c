/*
 * function: func_021B0508
 * address: 0x021B0508
 * packet: pkt_ov013_021B0508
 * region: ov013
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 * Initialize TCV session state, six counters and three request slots.
 * final push 2026-10-05 G7L7: closed. Two changes from the old draft. The f1C store is written in
 * each arm of the mode if/else (the join no longer splits the 3C84 pointer, f1C goes through the
 * first load). The pair table read takes a = d[k].a first and then p = &d[k] for p->b, which
 * gives the later-born address temp the lower register (r1) and the table base r2, so the table
 * load stays below the f1C store.
 * symbols:
 *   d_021B3C84     0x021B3C84  data  ov013  a4
 *   d_021B3C24     0x021B3C24  data  ov013  a4
 *   d_021B60D8     0x021B60D8  data  ov013  a4
 *   d_021B3AD0     0x021B3AD0  data  ov013  a1
 *   d_021B42C0     0x021B42C0  data  ov013  a4
 *   d_021B3CB0     0x021B3CB0  data  ov013  a4
 *   d_021B3CBC     0x021B3CBC  data  ov013  a4
 *   func_02087170  0x02087170  arm
 *   func_021B3250  0x021B3250  arm  ov013
 *   func_021B16E4  0x021B16E4  arm  ov013
 *   func_021B19BC  0x021B19BC  arm  ov013
 *   func_021B12FC  0x021B12FC  arm  ov013
 *   func_021B3364  0x021B3364  arm  ov013
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 f0;
    u8 pad2[2];
    u32 f4;
    u8 pad8[4];
    u32 fC;
    u8 pad10[0xC];
    u32 f1C;
    int f20;
    u32 f24;
} Ctx3C84;

typedef struct {
    u8 pad0[0x8c0];
    int f8C0;
    u32 f8C4;
    u32 f8C8;
    u32 f8CC;
    int f8D0;
    int f8D4;
} Ctx42C0;

typedef struct {
    u8 pad0[0x10];
    int f10;
} Ctx60D8;

typedef struct {
    u8 raw[0x94];
} Slot;

extern Ctx3C84 d_021B3C84;
extern int d_021B3C24;
extern Ctx60D8 d_021B60D8;
typedef struct {
    u8 a;
    u8 b;
} Pair;

extern const Pair d_021B3AD0[];
extern Ctx42C0 d_021B42C0;
extern void *d_021B3CB0[3];
extern Slot d_021B3CBC[3];

extern u16 func_02087170(void);
extern void func_021B3250(void);
extern void func_021B16E4(u32 i);
extern void func_021B19BC(char *p, int i, int a2);
extern void func_021B12FC(void);
extern void func_021B3364(void);

static inline u32 pairValue(u32 k)
{
    const Pair *p;
    u32 a;
    a = d_021B3AD0[k].a;
    p = &d_021B3AD0[k];
    return a * 0x44 + p->b + 0xC;
}
int func_021B0508(void)
{
    u32 i;
    u32 k;

    d_021B3C84.f0 = func_02087170();
    d_021B3C24 = 1;
    d_021B3C84.f20 = 0;
    d_021B3C84.f4 = 0;
    k = 0;
    if (d_021B60D8.f10 != 1) {
        k = 4;
        d_021B3C84.f1C = k;
    } else {
        d_021B3C84.f1C = k;
    }
    d_021B3C84.f24 = 0x440;
    d_021B3C84.fC = pairValue(k);
    d_021B42C0.f8C0 = 0;
    d_021B42C0.f8C4 = 0;
    d_021B42C0.f8CC = 0;
    d_021B42C0.f8C8 = 0;
    d_021B42C0.f8D0 = 0;
    d_021B42C0.f8D4 = 0;
    func_021B3250();
    for (i = 0; (i < 3) ? 1 : 0; i++) {
        d_021B3CB0[i] = 0;
        func_021B16E4(i);
        func_021B19BC((char *)&d_021B3CBC[i], i, -1);
    }
    func_021B12FC();
    func_021B3364();
    return 1;
}
