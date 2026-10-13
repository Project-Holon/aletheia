/*
 * function: BTL_ID_IsBagItemUseBlocked
 * address: 0x0689C90C
 * packet: pkt_ov095_0689C90C
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov095/unit_0689C888.c and filed here.
 *
 * symbols:
 *   gBagItemUseBlockedItems 0x0689E2AA data a2
 *   BTL_ID_IsInList 0x0689C888 thumb
 */

int BTL_ID_IsInList(unsigned a, unsigned short *b, unsigned n);
int BTL_ID_IsBagItemUseBlocked(unsigned a);
extern unsigned short gBagItemUseBlockedItems[];

int BTL_ID_IsBagItemUseBlocked(unsigned a)
{
    return BTL_ID_IsInList(a, gBagItemUseBlockedItems, 3);
}
