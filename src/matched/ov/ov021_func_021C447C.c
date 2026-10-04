/*
 * function: func_021C447C
 * address:  0x021C447C
 * packet:   pkt_ov021_021C447C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_02021288  0x02021288  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0202130C  0x0202130C  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 */

typedef unsigned int u32;

extern u32 func_02021288(u32 a);
extern void *func_0201ADE4(u32 species, int form, u32 heap);
extern u32 func_0202130C(u32 a);
struct Personal;
extern u32 func_0201AE1C(const struct Personal *p, u32 field);
extern void func_0201AE14(void *p);

u32 func_021C447C(u32 a, u32 b, u32 c, u32 d)
{
    u32 y, x, v;

    if (b >= 0x289)
        return 0;
    if (func_02021288(d) == 0)
        return 0;
    x = (u32)func_0201ADE4(b, c, a);
    y = func_0202130C(d);
    if (y < 0x20) {
        v = func_0201AE1C((const struct Personal *)x, 0x27);
    } else if (y < 0x40) {
        v = func_0201AE1C((const struct Personal *)x, 0x28);
        y -= 0x20;
    } else if (y < 0x60) {
        v = func_0201AE1C((const struct Personal *)x, 0x29);
        y -= 0x40;
    } else {
        v = func_0201AE1C((const struct Personal *)x, 0x2a);
        y -= 0x60;
    }
    func_0201AE14((void *)x);
    return v & (1 << y);
}
