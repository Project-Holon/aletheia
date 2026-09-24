/*
 * function: func_021BF520
 * address:  0x021BF520
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021C2344  0x021C2344  arm  ov114
 *
 *
 * Predicate: true when `a` is the sole entry of the 0x021CE544 table.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021C2344(int, void *);

int func_021BF520(int a)
{
    return func_021C2344(a, (void *)0x021CE544) == 1;
}
