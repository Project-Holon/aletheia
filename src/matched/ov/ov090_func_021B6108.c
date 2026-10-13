/*
 * function: PLIST_COMM_End
 * address: 0x021B6108
 * packet: pkt_ov090_021B6108
 * region: ov090
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_COMMAND_DeleteCommandTable 0x0203A5E4 arm
 * Leaf of ov178 021E54CC; caller unloads overlay 90 immediately after call.
 */
extern void GFL_NET_COMMAND_DeleteCommandTable(unsigned);
void PLIST_COMM_End(void *unused)
{
 GFL_NET_COMMAND_DeleteCommandTable(0x2D00);
}
