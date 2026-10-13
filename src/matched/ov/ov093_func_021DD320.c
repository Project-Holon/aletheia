/*
 * function: BTL_HANDLER_ITEM_LeppaBerryOnForcedUse
 * address: 0x021DD320
 * packet: pkt_ov093_021DD320
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two-byte alignment padding.
 * symbols:
 *   BTL_HANDLER_ITEM_PushRecoverPp 0x021DD39C thumb ov093
 */
typedef unsigned char u8;
extern int BTL_HANDLER_ITEM_PushRecoverPp(int, void *, u8, int, int);
void BTL_HANDLER_ITEM_LeppaBerryOnForcedUse(int a, void *b, u8 c, int *d)
{
    if (d[6] != 0) BTL_HANDLER_ITEM_PushRecoverPp(a, b, c, (int)d, 1);
}
