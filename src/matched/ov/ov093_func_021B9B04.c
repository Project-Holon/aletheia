/*
 * function: BTL_SIDE_CountLivingOfClient
 * address:  0x021B9B04
 * packet:   pkt_021B9B04
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SIDE_GetSlotOfClientThunk  0x021B9AF8  thumb  ov093
 *   BTL_SLOT_CountLiving  0x021B9B98  thumb  ov093
 */

char *BTL_SIDE_GetSlotOfClientThunk(char *, int);
typedef unsigned char  u8;
u8 BTL_SLOT_CountLiving(u8 *p);

unsigned char BTL_SIDE_CountLivingOfClient(int a, int b)
{
    return BTL_SLOT_CountLiving((u8 *)BTL_SIDE_GetSlotOfClientThunk((char *)a, b));
}
