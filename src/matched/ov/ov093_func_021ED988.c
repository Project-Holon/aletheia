/*
 * function: BTLV_SCU_ResetMonSlots
 * address:  0x021ED988
 * packet:   pkt_ov093_021ED988
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_ResetMonSlot  0x021ED9C8  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct E;
extern void BTLV_SCU_ResetMonSlot(struct E *e);
void BTLV_SCU_ResetMonSlots(u8 *p)
{
    u32 i;
    for (i = 0; i < 6; i++)
        BTLV_SCU_ResetMonSlot((struct E *)(p + 0x48 + i * 12));
}
