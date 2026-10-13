/*
 * function: BTL_DEADREC_Init
 * address: 0x0689D118
 * packet: pkt_ov095_0689D118
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_DEADREC_ClearTurn 0x0689D0FC thumb ov095
 */
typedef unsigned char u8;
typedef unsigned int u32;
extern void BTL_DEADREC_ClearTurn(u8 *p);
void BTL_DEADREC_Init(u8 *p)
{
    u32 i;
    for (i = 0; i < 4; i++) {
        BTL_DEADREC_ClearTurn(p + i * 49);
    }
}
