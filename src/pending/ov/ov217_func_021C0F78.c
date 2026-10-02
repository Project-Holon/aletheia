/*
 * function: func_021C0F78
 * address:  0x021C0F78
 * packet:   pkt_ov217_021C0F78
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * Note 2026-10-02: DIFF, only the load slot of p[6] (ldrb r2) differs: original loads it before
 * the font ldr; compiler sinks it after the stack stores. Tried int/s16/u8 locals, nested args.
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_021C1090  0x021C1090  thumb  ov217
 *   func_0201C7D0  0x0201C7D0  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

extern void *func_02045770(void *a);
extern void func_02043B5C(void *a, int b);
extern int func_021C1090(u8 *p, void *text);
extern void func_0201C7D0(void *w, s16 x, s16 y, void *text, void *font, u16 color);
extern void func_02045334(void *a);
extern void func_02045374(void *a);
extern void func_02045730(void *a);
extern void func_02041B6C(void);

void func_021C0F78(u8 *p, void *text)
{
    u16 color;
    void *w;
    int x;
    int y;
    void *font;
    void *obj;
    color = ((p[8] & 31) << 10) | ((p[9] & 31) << 5) | (p[10] & 31);
    w = func_02045770(*(void **)(p + 0x18));
    func_02043B5C(w, p[10]);
    if (*(int *)(p + 0xC) != 0) {
        x = p[5] + func_021C1090(p, text);
    } else {
        x = p[5];
    }
    y = p[6];
    font = *(void **)(p + 0x10);
    func_0201C7D0(w, x, y, text, font, color);
    if (*(int *)(p + 0x1C) != 0) {
        obj = *(void **)(p + 0x18);
        func_02045334(obj);
        func_02045374(obj);
        func_02045730(obj);
        func_02041B6C();
    }
}
