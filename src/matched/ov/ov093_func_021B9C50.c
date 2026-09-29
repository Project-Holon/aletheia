/*
 * function: func_021B9C50
 * address:  0x021B9C50
 * packet:   pkt_ov093_021B9C50
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9AB0  0x021B9AB0  thumb  ov093
 *   func_021B9AC8  0x021B9AC8  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int func_021B9AB0(int k);
extern int func_021B9AC8(int k);

void func_021B9C50(u32 *p, int k, u32 *o1, u32 *o2)
{
    u32 t;
    int a;
    int b;

    if (k != 0) {
        if (k != 1) {
            t = p[0];
            a = func_021B9AB0(k);
            b = func_021B9AC8(k);
            p[0] = p[a];
            p[a] = p[b];
            p[b] = t;
            if (o1)
                *o1 = t;
            if (o2)
                *o2 = p[0];
        }
    }
}
