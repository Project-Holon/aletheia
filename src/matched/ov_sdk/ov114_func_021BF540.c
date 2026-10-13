/*
 * function: DWC_GHTTPCleanupRootCAList
 * address:  0x021BF540
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ghttpCleanupRootCAList  0x021C2350  arm  ov114
 *
 *
 * Predicate: true when the census reports exactly one entry.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern int ghttpCleanupRootCAList(void);

int DWC_GHTTPCleanupRootCAList(void)
{
    return ghttpCleanupRootCAList() == 1;
}
