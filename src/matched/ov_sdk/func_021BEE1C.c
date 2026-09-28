/*
 * function: func_021BEE1C
 * address:  0x021BEE1C
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021BEC00  0x021BEC00  arm  ov114
 *
 *
 * Fires the record's +0x1c callback with code 4 once the node exists.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 *func_021BEC00(int, int);

void func_021BEE1C(int a, u8 *b)
{
    void (*g)(u8 *, int, int);
    if (func_021BEC00(a, (int)b) == 0)
        return;
    g = *(void (**)(u8 *, int, int))(b + 0x1c);
    if (g == 0)
        return;
    g(b, 4, 0);
}
