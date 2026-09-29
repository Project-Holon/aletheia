/*
 * function: func_021BB050
 * address:  0x021BB050
 * packet:   pkt_ov099_021BB050
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_020450F0  0x020450F0  arm
 *   func_02045374  0x02045374  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C7A4  0x0201C7A4  thumb
 *   func_02045334  0x02045334  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed short   s16;

typedef struct {
    char pad00[0xe0];
    u32 fe0;
    char pade4[4];
    u32 fe8;
    char padec[0xc];
    u32 ff8;
    char padfc[0x9c];
    void *f198;
} W;

extern void *func_021BA8BC(void *p);
extern void *func_020450F0(u32 frame, u32 x, u32 y, u32 w, u32 h, u32 pal, u32 chr);
extern void  func_02045374(void *win);
extern void  func_02045CAC(u32 a0, u32 a1, u32 a2);
extern void *func_02045770(void *win);
extern void  func_0201C7A4(void *x, s16 y, s16 z, void *s, void *w);
extern void  func_02045334(void *win);

void func_021BB050(W *w)
{
    func_021BA8BC(w->f198);
    w->f198 = func_020450F0(3, 5, 1, 0x16, 2, 0xf, 1);
    func_02045374(w->f198);
    func_02045CAC(w->fe0, 0x12, w->ff8);
    func_0201C7A4(func_02045770(w->f198), 0, 0, (void *)w->ff8, (void *)w->fe8);
    func_02045334(w->f198);
}
