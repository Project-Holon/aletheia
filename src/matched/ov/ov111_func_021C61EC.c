/*
 * function: func_021C61EC
 * address:  0x021C61EC
 * packet:   pkt_ov111_021C61EC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_0201D304  0x0201D304  thumb
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045808  0x02045808  arm
 *   func_02045374  0x02045374  arm
 *   func_02045334  0x02045334  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045C04  0x02045C04  arm
 *   func_02012F5C  0x02012F5C  thumb
 *   func_020089F4  0x020089F4  thumb
 *   func_02025C9C  0x02025C9C  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;

typedef struct {
    u8 pad0[4];
    void *f4;
} Sub24;

typedef struct {
    u16 heap;
    u8 pad2[2];
    void *bg[7];
    u8 pad20[4];
    Sub24 *f24;
    u8 pad28[0x31FC - 0x28];
    void *f31FC;
    void *f3200;
    u8 pad3204[0x3234 - 0x3204];
    void *f3234;
} Work;

extern void *func_02045770(void *p);
extern void func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern u32 func_0201D304(void *a, void *b, u32 c);
extern void func_02043B5C(void *a, int b);
extern void *func_02045EC0(void *a, u32 b);
extern void func_02045808(void *p);
extern void func_02045374(void *p);
extern void func_02045334(void *p);
extern void func_02041B6C(u8 bg);
extern void *func_02045B38(u32 a, u32 b, u32 c, u32 d);
extern void func_02045C04(void *p);
extern void *func_02012F5C(void *p);
extern int func_020089F4(void *p);
extern u32 func_02025C9C(int k);

void func_021C61EC(Work *p, int k, int flush)
{
    void *bank;
    void *str;
    u32 w;

    bank = func_02045B38(0, 2, 0xBF, p->heap);
    if (func_020089F4(func_02012F5C(p->f24->f4))) {
        str = func_02045EC0(bank, func_02025C9C(k));
    } else {
        str = func_02045EC0(bank, 0);
    }
    w = func_0201D304(str, p->f31FC, 0);
    func_02043B5C(func_02045770(p->bg[1]), 0);
    func_0201C7A4(func_02045770(p->bg[1]), 0x80 - w, 0, str, p->f31FC);
    func_02045808(str);
    func_02045C04(bank);
    if (flush) {
        func_02045374(p->bg[1]);
        func_02045334(p->bg[1]);
        func_02041B6C(7);
    }
}
