/*
 * function: DWC_GHTTPSetRootCAList
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
 *   ghttpSetRootCAList  0x021C2344  arm  ov114
 *
 *
 * Predicate: true when `a` is the sole entry of the 0x021CE544 table.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int ghttpSetRootCAList(int, void *);

int DWC_GHTTPSetRootCAList(int a)
{
    return ghttpSetRootCAList(a, (void *)0x021CE544) == 1;
}
