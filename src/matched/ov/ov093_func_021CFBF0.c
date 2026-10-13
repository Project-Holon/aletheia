/*
 * function: BTL_CLIENT_ChooseAiSwitchTarget
 * address: 0x021CFBF0
 * packet: pkt_ov093_021CFBF0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_CLIENT_GetEscapeBlocker 0x021CF8D4 thumb ov093
 *   BTL_SLOT_CountLiving 0x021B9B98 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_GetTrainerSlotOfPoke 0x021B8D8C thumb ov093
 *   BTL_CLIENT_PickRandomFoe 0x021CFD50 thumb ov093
 *   BTL_POKEPARAM_IsIllusionActive 0x021D6C24 thumb ov093
 *   BTL_MAIN_ResolveIllusionPoke 0x021B937C thumb ov093
 *   BTL_CLIENT_IsCountdownEndingNext 0x021CFDCC thumb ov093
 *   BTL_CLIENT_ShouldSwitchVsWonderGuard 0x021CFE08 thumb ov093
 *   BTL_CLIENT_ShouldSwitchNoEffectiveMove 0x021CFE98 thumb ov093
 *   BTL_CLIENT_ShouldSwitchWhileLocked 0x021CFFAC thumb ov093
 *   BTL_CLIENT_FindSwitchFromHitHistory 0x021D0100 thumb ov093
 *   BTL_CLIENT_FindNaturalCureSwitch 0x021D0248 thumb ov093
 *   BTL_CLIENT_FindSwitchByTypeMatchup 0x021D0304 thumb ov093
 *   BTL_CLIENT_ListAbleMons 0x021D0980 thumb ov093
 *   BTL_CLIENT_SortMonsByMovePower 0x021D09E0 thumb ov093
 *   BTL_CLIENT_HasSlotInOrder 0x021CFBBC thumb ov093
 *   BTL_CLIENT_SetSlotOrder 0x021CFBE0 thumb ov093
 */
#include "../include/Obj00489.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BTL_CLIENT_GetEscapeBlocker(u8 *, void *, u8 *, u16 *);
typedef signed char    s8;
struct G;
struct R4;
extern u8 BTL_SLOT_CountLiving(u8 *p);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern int BTL_MAIN_GetTrainerSlotOfPoke(void *, void *, u32);
extern u8 *BTL_CLIENT_PickRandomFoe(struct G *g, int k);
extern int BTL_POKEPARAM_IsIllusionActive(struct R4 *p);
extern u8 *BTL_MAIN_ResolveIllusionPoke(int, char *, u8 *);
extern int BTL_CLIENT_IsCountdownEndingNext(void *, void *);
extern int BTL_CLIENT_ShouldSwitchVsWonderGuard(struct G *g, void *a, void *b);
extern int BTL_CLIENT_ShouldSwitchNoEffectiveMove(struct G *g, void *a, void *b);
extern int BTL_CLIENT_ShouldSwitchWhileLocked(struct G *g, void *mon, void *target);
extern int BTL_CLIENT_FindSwitchFromHitHistory(struct G *g, void *mon, void *target, u8 *out);
extern int BTL_CLIENT_FindNaturalCureSwitch(struct G *g, void *m, u8 *out);
extern int BTL_CLIENT_FindSwitchByTypeMatchup(struct G *g, void *mon, void *target, u8 *out);
extern u8 BTL_CLIENT_ListAbleMons(u8 *, u8 *);
extern void BTL_CLIENT_SortMonsByMovePower(u8 *p, u8 *order, u8 count, void *target);
extern int BTL_CLIENT_HasSlotInOrder(s8 *p, int v);
extern void BTL_CLIENT_SetSlotOrder(u8 *p, u32 i, u32 v);
int BTL_CLIENT_ChooseAiSwitchTarget(u8 *g, void *m, u32 slot, u8 *out)
{
    u8 choice;
    u8 id;
    u16 k;
    u8 buf[6];
    u8 *q;
    u32 n;
    u32 i;
    u8 ok;
    choice = 6;
    if (BTL_CLIENT_GetEscapeBlocker(g, m, &id, &k) != 4) return 0;
    if (BTL_SLOT_CountLiving(((struct Obj00489 *)g)->f118) <= g[0x11c]) return 0;
    q = BTL_CLIENT_PickRandomFoe((struct G *)g, BTL_MAIN_GetTrainerSlotOfPoke(((struct Obj00489 *)g)->f0, ((struct Obj00489 *)g)->f4, BTL_POKEPARAM_GetPokeId(m)));
    if (!q) return 0;
    if (BTL_POKEPARAM_IsIllusionActive((struct R4 *)q))
        q = BTL_MAIN_ResolveIllusionPoke(*(int *)&((struct Obj00489 *)g)->f0, *(char * *)&((struct Obj00489 *)g)->f4, q);
    if (BTL_CLIENT_IsCountdownEndingNext(g, m)) ok = 1;
    else if (BTL_CLIENT_ShouldSwitchVsWonderGuard((struct G *)g, m, q)) ok = 1;
    else if (BTL_CLIENT_ShouldSwitchNoEffectiveMove((struct G *)g, m, q)) ok = 1;
    else if (BTL_CLIENT_ShouldSwitchWhileLocked((struct G *)g, m, q)) ok = 1;
    else if (BTL_CLIENT_FindSwitchFromHitHistory((struct G *)g, m, q, &choice)) ok = 1;
    else if (BTL_CLIENT_FindNaturalCureSwitch((struct G *)g, m, &choice)) ok = 1;
    else if (BTL_CLIENT_FindSwitchByTypeMatchup((struct G *)g, m, q, &choice)) ok = 1;
    else return 0;
    if (!ok) return 0;
    if (choice == 6) {
        n = BTL_CLIENT_ListAbleMons(g, buf);
        BTL_CLIENT_SortMonsByMovePower(g, buf, n, q);
        for (i = 0; i < n; i++) {
            if (!BTL_CLIENT_HasSlotInOrder((s8 *)g, buf[i])) {
                choice = buf[i];
                break;
            }
        }
    }
    if (choice == 6) return 0;
    BTL_CLIENT_SetSlotOrder(g, slot, choice);
    *out = choice;
    return 1;
}
