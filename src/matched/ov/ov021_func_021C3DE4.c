/*
 * function: func_021C3DE4
 * address:  0x021C3DE4
 * packet:   pkt_ov021_021C3DE4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 */

typedef unsigned int u32;
typedef unsigned short u16;

extern void *func_0201ADE4(u32 a, int b, u32 heap);
struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);

void func_021C3DE4(u32 *a, u32 *p, u32 heap)
{
    u32 s[3];
    u32 x = (u32)func_0201ADE4((u16)p[0], (u16)p[1], heap);

    s[0] = func_0201AE1C((const struct Personal *)x, 0x1a);
    s[1] = func_0201AE1C((const struct Personal *)x, 0x1b);
    s[2] = func_0201AE1C((const struct Personal *)x, 0x1c);
    func_0201AE14((void *)x);
    if (p[0x13] < 2) {
        p[4] = s[p[0x13]];
        if (p[4] == 0)
            p[4] = s[0];
    }
}
