/*
 * function: ghttpCleanupRootCAList
 * address:  0x021C2350
 * packet:   pkt_021B9500
 * region:   ov114
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   ghiEncryptorCleanupRootCAList  0x021C1210  arm  ov114
 *
 *
 * Tail-call thunk to ghiEncryptorCleanupRootCAList via `ldr ip,pool; bx ip`.
 */

typedef unsigned char u8;
typedef unsigned int u32;
extern void ghiEncryptorCleanupRootCAList(void);

void ghttpCleanupRootCAList(void)
{
    ghiEncryptorCleanupRootCAList();
}
