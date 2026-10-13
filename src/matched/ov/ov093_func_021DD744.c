/*
 * function: HAND_ITEM_RequestUseAtHalfHp
 * address: 0x021DD744
 * packet: pkt_ov093_021DD744
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   HAND_ITEM_HpBerryCheckAndUse 0x021DDE30 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *, int);
extern void HAND_ITEM_HpBerryCheckAndUse(int, int, int, int, int);

void HAND_ITEM_RequestUseAtHalfHp(int a, void *b, int c, int *d)
{
    if (*d == 0 && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(b, c), 15) == 0) HAND_ITEM_HpBerryCheckAndUse(a, (int)b, c, 2, 0);
}
