/*
 * function: BTL_HANDLER_ITEM_RecoverHpOnTrigger
 * address: 0x021DD480
 * packet: pkt_ov093_021DD480
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_HANDLER_ITEM_HpBerryCheckAndUse 0x021DDE30 thumb ov093
 */
struct Unk021D62A8;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_HANDLER_ITEM_HpBerryCheckAndUse(int a, int b, int c, int d, int e);
void BTL_HANDLER_ITEM_RecoverHpOnTrigger(int a, void *b, int c)
{
    if (BTL_POKEPARAM_HasSick(func_021C7CF4(b, c), 15) == 0)
        BTL_HANDLER_ITEM_HpBerryCheckAndUse(a, (int)b, c, 2, 1);
}
