/*
 * function: PMSIV_EDIT_BoxOriginToSlotPos
 * address: 0x021BC578
 * packet: pkt_ov110_021BC578
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:

 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;

void PMSIV_EDIT_BoxOriginToSlotPos(const s16 *a, s16 *b)
{
    b[0] = a[0] + 24;
    b[1] = a[1] + 8;
}
