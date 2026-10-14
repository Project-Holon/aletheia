/*
 * function: GDS_SOCKET_Unlock
 * address:  0x021D7CC0
 * packet:   pkt_021D7CC0
 * region:   ov125
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Resolved: the ov121 region hint on the data symbol was contested by the
 * other overlays in the window; un-hinted, sole-ref/data picks the unique
 * overlay start, so the ABS32 pool relocation resolves (the PC24 to
 * func_02086078 was already `label`).
 *
 * symbols:
 *   func_02086078  0x02086078  arm
 *   gGdsSocketMutex     0x021DA174  data  a4
 *
 * Addresses are Black-image addresses.
 */

extern void func_02086078(void *);
extern char gGdsSocketMutex[];

void GDS_SOCKET_Unlock(void)
{
    func_02086078(gGdsSocketMutex);
}
