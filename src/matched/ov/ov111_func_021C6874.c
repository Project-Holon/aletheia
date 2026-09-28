/*
 * function: func_021C6874
 * address:  0x021C6874
 * packet:   pkt_ov111_021C6874
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_021C63B8  0x021C63B8  thumb  ov111
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;

typedef struct {
    u8 pad0[0x1C];
    void *bg;
    u8 pad20[0x32FA - 0x20];
    u8 list[0x13];
} Work;

extern void *func_02045770(void *p);
extern void func_02043B5C(void *a, int b);
extern void func_02045334(void *p);
extern void func_02045374(void *p);
extern void func_02045730(void *p);
extern void func_02041B6C(void);
extern void func_021C63B8(Work *p, void *a, int sel, int y, int idx);

void func_021C6874(Work *p, int scroll, int flush, int idx)
{
    void *bg = p->bg;
    int i;
    int top = -(scroll / 16);

    func_02043B5C(func_02045770(bg), 0);
    for (i = 0; i < 5; i++) {
        func_021C63B8(p, bg, p->list[i + top], scroll % 16 + i * 16, idx);
    }
    if (flush) {
        func_02045334(bg);
        func_02045374(bg);
        func_02045730(bg);
        func_02041B6C();
    }
}
