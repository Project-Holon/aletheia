/*
 * function: HAND_ITEM_FlavorHealSpDefenseIfForcedUse
 * address: 0x021DD6F4
 * packet: pkt_ov093_021DD6F4
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   HAND_ITEM_FlavorHeal 0x021DD7B8 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
typedef unsigned char  u8;
extern void HAND_ITEM_FlavorHeal(int a, u8 *b, int c, int *d, int e);

void HAND_ITEM_FlavorHealSpDefenseIfForcedUse(int a, void *b, int c, int *d)
{
    if (d[6] != 0) HAND_ITEM_FlavorHeal(a, b, c, d, 4);
}
