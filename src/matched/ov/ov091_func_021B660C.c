/*
 * function: func_021B660C
 * address:  0x021B660C
 * packet:   pkt_ov091_021B660C
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The 0x160 table is indexed as `p + i * 4 + 0x160` (base plus scaled
 * index, then the field offset) and the list lookup goes through a temp:
 * that is what puts the row address after func_0201AB28 and keeps the
 * three 0x160 offsets as spilled loop invariants.
 *
 * symbols:
 *   func_0201AA18  0x0201AA18  thumb
 *   func_020355C4  0x020355C4  arm
 *   func_020212B0  0x020212B0  thumb
 *   func_021B6D90  0x021B6D90  thumb  ov091
 *   func_021B7298  0x021B7298  thumb  ov091
 *   func_021B71E4  0x021B71E4  thumb  ov091
 *   func_0201AB28  0x0201AB28  thumb
 *   func_021BA6A0  0x021BA6A0  thumb  ov091
 *   func_021BA81C  0x021BA81C  thumb  ov091
 *   func_021BB43C  0x021BB43C  thumb  ov091
 *   func_02027F60  0x02027F60  thumb
 *   func_021B709C  0x021B709C  thumb  ov091
 *   func_021B9A84  0x021B9A84  thumb  ov091
 *   func_021BCCCC  0x021BCCCC  thumb  ov091
 *   func_020056A0  0x020056A0  thumb
 *   func_021B6D64  0x021B6D64  thumb  ov091
 *   func_021BB594  0x021BB594  thumb  ov091
 *   func_021BBA8C  0x021BBA8C  thumb  ov091
 *   func_021B7698  0x021B7698  thumb  ov091
 *   func_02041B6C  0x02041B6C  arm
 *   func_0203D34C  0x0203D34C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_0201AA18(void *);
extern u8 func_020355C4(void);
extern u16 func_020212B0(u16 id);
extern void func_021B6D90(u8 *p);
extern void func_021B7298(u8 *p);
extern void func_021B71E4(u8 *p);
extern void *func_0201AB28(void *p, u32 idx);
extern int func_021BA6A0(u8 *p, int k, int e);
extern int func_021BA81C(u8 *p, int k);
extern int func_021BB43C(int p);
extern u32 func_02027F60(u32 a, u32 b, u32 c, u32 d, u32 heap);
extern void func_021B709C(u8 *p);
extern int func_021B9A84(u8 *p);
extern void func_021BCCCC(u8 *p);
extern int func_020056A0(void (*cb)(void *, u8 *), u8 *p, int pri);
extern void func_021B6D64(void *tcb, u8 *p);
extern int func_021BB594(u8 *p);
extern int func_021BBA8C(u8 *p);
extern void func_021B7698(u8 *p);
extern void func_02041B6C(u32 id);
extern void func_0203D34C(u32 a, u32 b);

#define W(o) (*(int *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

int func_021B660C(u8 *p)
{
    u8 n;
    u8 i;
    u8 *q;
    int e;

    n = func_0201AA18((void *)*(int *)W(0x280));
    W(8) = func_020355C4();
    W(0x3c) = 0x17;
    p[0xc] = 0;
    p[0xe] = 0;
    W(0x2c) = 0;
    W(0x38) = 0;
    W(0x30) = 9;
    W(0x34) = 9;
    W(0x14) = 0;
    W(0x10) = 0;
    p[0x105] = 0;
    p[0x100] = 0;
    H(0x102) = 0;
    H(0x110) = 0;
    p[0x114] = 0;
    W(0x120) = 0;
    W(0x130) = 0;
    W(0x1e8) = 0;
    W(0x108) = 0;
    W(0x10c) = 0;
    W(0x118) = 0;
    W(0x264) = 0;
    W(0x250) = 0;
    W(0x278) = 0;
    *(u8 *)(W(0x280) + 0x63) = 0;
    W(0x28) = 1;
    W(0x24) = 0;
    for (i = 0; i < 0x17; i++)
        ((int *)(p + 0x178))[i] = -1;
    W(0x1c) = *(int *)(W(0x280) + 0x34) == 0x19 ? 1 : 0;
    q = (u8 *)W(0x280);
    if (*(int *)(q + 0x34) == 0x18) {
        *(int *)(q + 0x34) = 3;
        W(0x18) = 1;
    } else {
        W(0x18) = 0;
    }
    q = (u8 *)W(0x280);
    if (*(int *)(q + 0x34) == 0x1a) {
        *(int *)(q + 0x34) = 1;
        W(0x20) = 1;
    } else {
        W(0x20) = 0;
    }
    q = (u8 *)W(0x280);
    if (*(int *)(q + 0x34) == 6 && *(u16 *)(q + 0x46) == 0)
        *(u16 *)(W(0x280) + 0x46) = func_020212B0(*(u16 *)(q + 0x44));
    func_021B6D90(p);
    func_021B7298(p);
    func_021B71E4(p);
    for (i = 0; i < 6; i++) {
        if (i < n) {
            e = (int)func_0201AB28(*(void **)W(0x280), i);
            *(int *)(p + i * 4 + 0x160) = func_021BA6A0(p, i, e);
        } else
            *(int *)(p + i * 4 + 0x160) = func_021BA81C(p, i);
        if (func_021BB43C(*(int *)(p + i * 4 + 0x160)) <= 5)
            p[0x105]++;
    }
    W(0x254) = func_02027F60(0, 1, W(0x138), W(0x140), H(0));
    func_021B709C(p);
    if (func_021B9A84(p) == 1)
        func_021BCCCC(p);
    W(4) = func_020056A0(func_021B6D64, p, 8);
    W(0x150) = func_021BB594(p);
    W(0x154) = func_021BBA8C(p);
    func_021B7698(p);
    func_02041B6C(3);
    func_02041B6C(2);
    func_02041B6C(7);
    func_0203D34C(1, H(0));
    return 1;
}
