/*
 * function: HAND_ITEM_RequestUseAtHalfHpDirect
 * address: 0x021DD77C
 * packet: pkt_ov093_021DD77C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   HAND_ITEM_IsHpAtOrBelowFraction 0x021DDEA4 thumb ov093
 *   HAND_ITEM_PushUseItem 0x021DD044 thumb ov093
 * Interface: C7CF4 returns the live r0 payload and receives observed r1.
 */
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *, int);
extern int HAND_ITEM_IsHpAtOrBelowFraction(void *, int, unsigned int);
extern void HAND_ITEM_PushUseItem(void *, void *, int);

void HAND_ITEM_RequestUseAtHalfHpDirect(int a, void *b, int c, int *d)
{
    if (*d == 0 && BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(b, c), 15) == 0 && HAND_ITEM_IsHpAtOrBelowFraction(b, c, 2) != 0) HAND_ITEM_PushUseItem((void *)a, b, c);
}
