/*
 * function: func_021CD440
 * address:  0x021CD440
 * packet:   pkt_ov021_021CD440
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D83C  0x0216D83C  thumb  ov010
 *   func_0216D86C  0x0216D86C  thumb  ov010
 *   func_021CD400  0x021CD400  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned int u32;

extern u16 func_02188C9C(void *p);
extern void *func_02188CB4(void *p);
extern void *func_021A3074(void *p);
extern int func_0216D83C(void *p);
extern int func_0216D86C(void *p);
extern u32 func_021CD400(u32 a, int b, int c);

int func_021CD440(void *a, u16 *out)
{
    u16 x;
    void *o;
    u16 h;
    u16 w;

    x = func_02188C9C(a);
    o = func_021A3074(func_02188CB4(a));
    h = func_0216D83C(o);
    w = func_0216D86C(o);
    *out = func_021CD400(x, h, w);
    if (*out != 0x1ab)
        return 1;
    *out = x;
    return 0;
}
