/*
 * function: BTL_SERVER_FLOW_ProcPokeLeaveField
 * address: 0x021C5108
 * packet: pkt_ov093_021C5108
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 198 compiled bytes followed by two zero padding bytes at 021C51CE.
 * symbols:
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_SERVER_FLOW_DispatchPokeLeaveEvent 0x021C51D0 thumb ov093
 *   BTL_SERVER_FLOW_ReleaseBindingTarget 0x021BFF60 thumb ov093
 *   BTL_CALC_RemoveAbilityHandlers 0x021D8510 thumb ov093
 *   BTL_HANDLER_ITEM_RemoveUnforcedFactors 0x021DCF24 thumb ov093
 *   BTL_CALC_DisableAbilityHandlers 0x021D8538 thumb ov093
 *   BTL_HANDLER_ITEM_DisablePokeFactors 0x021DCFA4 thumb ov093
 *   func_021E0434 0x021E0434 thumb ov093
 *   BTL_SERVER_FLOW_InitFieldPokeIter 0x021BD2B4 thumb ov093
 *   BTL_SERVER_FLOW_SetFieldPokeIterRule 0x021BD338 thumb ov093
 *   BTL_SERVER_FLOW_NextFieldPokeIter 0x021BD34C thumb ov093
 *   BTL_POKEPARAM_CureSickBySource 0x021D6264 thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_FIELD_QueryStaticSlotB 0x021EF90C thumb ov093
 *   BTL_SERVER_FLOW_CheckShowdown 0x021BC2B0 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_SERVER_FLOW_RecheckOpponentAbilityEffects 0x021C3FDC thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_SERVER_FLOW_DispatchPokeLeaveEvent(u8 *, u8 *);
extern void BTL_SERVER_FLOW_ReleaseBindingTarget(u8 *, u8 *, int);
extern void BTL_CALC_RemoveAbilityHandlers(void *p);
extern void BTL_HANDLER_ITEM_RemoveUnforcedFactors(u8 *);
extern void BTL_CALC_DisableAbilityHandlers(void *p);
extern void BTL_HANDLER_ITEM_DisablePokeFactors(void *p);
extern void func_021E0434(u8 *);
extern void BTL_SERVER_FLOW_InitFieldPokeIter(u8 *, u8 **);
extern void BTL_SERVER_FLOW_SetFieldPokeIterRule(u8 *, u8 *);
extern int BTL_SERVER_FLOW_NextFieldPokeIter(u8 *, u8 **, u8 **);
struct UtilSlots;
extern void BTL_POKEPARAM_CureSickBySource(struct UtilSlots *p, int v);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
extern int BTL_FIELD_QueryStaticSlotB(int a);
extern int BTL_SERVER_FLOW_CheckShowdown(u8 *);
extern int func_021D59B4(u8 *p, int k);
extern void BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(u8 *, u8 *);
void BTL_SERVER_FLOW_ProcPokeLeaveField(u8 *p, u8 *a, int b)
{
    u32 it;
    u8 *cur;
    int k = BTL_POKEPARAM_GetPokeId(a);
    BTL_SERVER_FLOW_DispatchPokeLeaveEvent(p, a);
    BTL_SERVER_FLOW_ReleaseBindingTarget(p, a, 0);
    if (b == 0) {
        BTL_CALC_RemoveAbilityHandlers(a);
        BTL_HANDLER_ITEM_RemoveUnforcedFactors(a);
    } else {
        BTL_CALC_DisableAbilityHandlers(a);
        BTL_HANDLER_ITEM_DisablePokeFactors(a);
    }
    func_021E0434(a);
    BTL_SERVER_FLOW_InitFieldPokeIter((u8 *)&it, (u8 **)p);
    BTL_SERVER_FLOW_SetFieldPokeIterRule((u8 *)&it, p);
    while (BTL_SERVER_FLOW_NextFieldPokeIter((u8 *)&it, (u8 **)p, &cur)) {
        BTL_POKEPARAM_CureSickBySource((struct UtilSlots *)cur, k);
        BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x2c, BTL_POKEPARAM_GetPokeId(cur), k);
    }
    BTL_FIELD_QueryStaticSlotB(k);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 0x23, k);
    if (!BTL_SERVER_FLOW_CheckShowdown(p) && (u16)func_021D59B4(a, 0x11) == 0x7f)
        BTL_SERVER_FLOW_RecheckOpponentAbilityEffects(p, a);
}
