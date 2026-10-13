/*
 * function: BTL_SERVER_FLOW_ProcMemberInCore
 * address: 0x021BD8F0
 * packet: pkt_ov093_021BD8F0
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BTL_SIDE_GetSlotOfClient 0x021B9AEC thumb ov093
 *   BTL_SERVER_CMD_Push 0x021CD4B0 thumb ov093
 *   BTL_SLOT_UpdateIllusion 0x021B9D10 thumb ov093
 *   BTL_SLOT_Swap 0x021B9C10 thumb ov093
 *   BTL_SLOT_GetPoke 0x021B9BF0 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_MAIN_RegisterZukanSeen 0x021B8750 thumb ov093
 *   HAND_TOKUSEI_AddAbilityHandlers 0x021D8484 thumb ov093
 *   HAND_ITEM_AddHeldItemFactor 0x021DCF5C thumb ov093
 *   BTL_POKEPARAM_StartTurnThreshold 0x021D63EC thumb ov093
 *   BTL_POKEPARAM_ReloadAndResetEffects 0x021D6580 thumb ov093
 *   BTL_MAIN_GetRule 0x021B8588 thumb ov093
 *   BTL_MAIN_GetPositionsPerClientThunk 0x021B99B8 thumb ov093
 *   BTL_MAIN_GetClientTrainerIndex 0x021B8BEC thumb ov093
 *   func_021BD9C4 0x021BD9C4 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern char *BTL_SIDE_GetSlotOfClient(char *, int);
extern void BTL_SERVER_CMD_Push(void *w, volatile u32 id, ...);
struct Arr;
extern void BTL_SLOT_UpdateIllusion(char *a, struct Arr *arr, int k);
struct S2;
extern void BTL_SLOT_Swap(u32 *p, int a, int b);
extern u32 BTL_SLOT_GetPoke(struct S2 *p, u32 i);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_MAIN_RegisterZukanSeen(char *p, unsigned char k, void *m);
extern void *HAND_TOKUSEI_AddAbilityHandlers(void *a);
extern void *HAND_ITEM_AddHeldItemFactor(void *p);
extern void BTL_POKEPARAM_StartTurnThreshold(u8 *p, u16 n);
extern void BTL_POKEPARAM_ReloadAndResetEffects(void *);
extern u32 BTL_MAIN_GetRule(void **p);
extern int BTL_MAIN_GetPositionsPerClientThunk(void *pp, unsigned int b);
extern u8 BTL_MAIN_GetClientTrainerIndex(u8 *, u32, u8);
extern void func_021BD9C4(void *, int, u8, void *);
void BTL_SERVER_FLOW_ProcMemberInCore(u8 *p, u8 i, u8 a, u8 b)
{
    char *arr;
    u8 *m;
    u8 id;
    u8 *flags;
    arr = BTL_SIDE_GetSlotOfClient(*(char * *)&((struct Obj00003 *)p)->f8, i);
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 42, i);
    BTL_SLOT_UpdateIllusion(*(char * *)&((struct Obj00003 *)p)->f4, (struct Arr *)arr, i);
    if (a != b) BTL_SLOT_Swap((u32 *)arr, a, b);
    m = (u8 *)BTL_SLOT_GetPoke((struct S2 *)arr, a);
    id = BTL_POKEPARAM_GetPokeId(m);
    BTL_MAIN_RegisterZukanSeen(((struct Obj00003 *)p)->f4, i, m);
    HAND_TOKUSEI_AddAbilityHandlers(m);
    HAND_ITEM_AddHeldItemFactor(m);
    BTL_POKEPARAM_StartTurnThreshold(m, ((struct Obj00003 *)p)->f10);
    BTL_POKEPARAM_ReloadAndResetEffects(m);
    flags = p + 0x7c1;
    flags[id] = 1;
    if (BTL_MAIN_GetRule(((struct Obj00003 *)p)->f4) == 3) {
        if ((u32)BTL_MAIN_GetPositionsPerClientThunk(((struct Obj00003 *)p)->f4, (int)i) <= a) flags[id] = 0;
    }
    BTL_SERVER_CMD_Push(((struct Obj00003 *)p)->fC, 18, i, a, b, (u16)((struct Obj00003 *)p)->f10);
    func_021BD9C4(p + 0x1ab8, BTL_MAIN_GetClientTrainerIndex(*(u8 * *)&((struct Obj00003 *)p)->f4, i, a), id, ((struct Obj00003 *)p)->f8);
}
