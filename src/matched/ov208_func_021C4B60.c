/*
 * function: ov208_func_021C4B60
 * address:  0x021C4B60
 * packet:   pkt_ov208_021C4B60
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   func_0201C6C4  0x0201C6C4  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ov208Menu {
    u8  pad0[0x554];
    u32 win[5];
    u32 active[5];
    u32 print[5];
};

extern u32  func_02045770(u32 win);
extern int  func_0201C6C4(u32 print, u32 bmp);
extern void func_02045334(u32 win);
extern void func_02045374(u32 win);
extern u32  func_02045730(u32 win);
extern void func_02041B6C(u32 layer);

void ov208_func_021C4B60(void *a0, struct Ov208Menu *p, int a2, int i)
{
    u32 w;

    if (p->active[i] != 0 && func_0201C6C4(p->print[i], func_02045770(p->win[i])) == 0) {
        w = p->win[i];
        func_02045334(w);
        func_02045374(w);
        func_02041B6C(func_02045730(w));
        p->active[i] = 0;
    }
}
