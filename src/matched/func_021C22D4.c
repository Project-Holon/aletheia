/*
 * function: func_021C22D4
 * address:  0x021C22D4
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C0DA4  0x021C0DA4  arm  ov114
 *
 *
 * Current object's +0x10 word, or 0 when nothing is selected.
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern u8 *func_021C0DA4(void);

u32 func_021C22D4(void)
{
    u8 *p = func_021C0DA4();
    if (p != 0)
        return *(u32 *)(p + 0x10);
    return 0;
}
