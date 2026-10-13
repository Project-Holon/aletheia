/*
 * function: HAND_ITEM_RecoverHpOnCheck
 * address: 0x021DD4B0
 * packet: pkt_ov093_021DD4B0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   HAND_ITEM_HpBerryCheckAndUse 0x021DDE30 thumb ov093
 */
struct Unk021D62A8;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void HAND_ITEM_HpBerryCheckAndUse(int a, int b, int c, int d, int e);
void HAND_ITEM_RecoverHpOnCheck(int a, void *b, int c)
{
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam(b, c), 15) == 0)
        HAND_ITEM_HpBerryCheckAndUse(a, (int)b, c, 2, 0);
}
