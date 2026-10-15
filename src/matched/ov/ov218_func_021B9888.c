/*
 * function: UN_SELECT_Delete
 * address: 0x021B9888
 * packet: pkt_ov218_021B9888
 * region: ov218
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHBAR_Delete 0x021B639C thumb ov067
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void TOUCHBAR_Delete(u8 *);
void UN_SELECT_Delete(u8 *p)
{
    TOUCHBAR_Delete(p);
}
