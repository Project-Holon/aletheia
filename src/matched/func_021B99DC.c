/*
 * function: func_021B99DC
 * address:  0x021B99DC
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BE880  0x021BE880  arm  ov114
 *
 *
 * Forwards the record's +0x0c key to the module query.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021BE880(int);

int func_021B99DC(u8 *p)
{
    if (p != 0)
        return func_021BE880(*(u32 *)(p + 0xc));
    return 0;
}
