/*
 * function: BTL_SERVER_FLOW_RollMoveAccuracy
 * address: 0x021BFA60
 * packet: pkt_ov093_021BFA60
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Declare flag before base to place their spills at the original stack offsets.
 * symbols:
 *   func_021BF324 0x021BF324 thumb ov093
 *   func_021C69B8 0x021C69B8 thumb ov093
 *   BTL_POKEPARAM_HasSick 0x021D62C4 thumb ov093
 *   BTL_SERVER_FLOW_CalcAccuracyRatio 0x021C6A04 thumb ov093
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SetVarReadOnly 0x021D75EC thumb ov093
 *   BTL_EVENT_SetVarOnce 0x021D7630 thumb ov093
 *   func_021D59B4 0x021D59B4 thumb ov093
 *   BTL_EVENT_SetVar 0x021D75A8 thumb ov093
 *   BTL_EVENT_SetVarRanged 0x021D7674 thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_MultiplyVar 0x021D7704 thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 *   BTL_POKEPARAM_TestTurnFlag 0x021D5BB0 thumb ov093
 *   BTL_CALC_ApplyAccuracyStage 0x021D7908 thumb ov093
 *   BTL_CALC_MulRatio 0x021D7B10 thumb ov093
 *   func_021B911C 0x021B911C thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 */
#include "../include/Obj07752.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Q { u16 h0; u8 pad[6]; u32 w8; };
extern int func_021BF324(u8 *, u8 *, u8 *);
extern int func_021C69B8(u8 *, u8 *, u32, u16);
struct Unk021D62A8;
struct UtilWork;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_SERVER_FLOW_CalcAccuracyRatio(u8 *, u8 *, u8 *, struct Q *);
extern void BTL_EVENT_PushVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int, u32);
extern void BTL_EVENT_SetVarOnce(int, u32);
extern int func_021D59B4(u8 *p, int k);
extern void BTL_EVENT_SetVar(int, u32);
extern void BTL_EVENT_SetVarRanged(int, u32, u32, u32);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int);
extern void BTL_EVENT_MultiplyVar(int, int);
extern void BTL_EVENT_PopVarFrame(int);
extern int BTL_POKEPARAM_TestTurnFlag(struct UtilWork *p, u32 n);
extern unsigned char BTL_CALC_ApplyAccuracyStage(int a, int i);
extern u32 BTL_CALC_MulRatio(u32, u32);
extern int func_021B911C(void *, int);
extern u32 BTL_CALC_Random(u32);
int BTL_SERVER_FLOW_RollMoveAccuracy(u8 *p, u8 *a, u8 *b, struct Q *q)
{
    u8 flag;
    s8 x, y;
    int base;
    u32 scale;
    int v;
    u32 chance;
    if (func_021BF324(p, a, b)) return 1;
    if (func_021C69B8(p, a, (u32)b, q->h0)) return 1;
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)b, 32)) return 1;
    base = BTL_SERVER_FLOW_CalcAccuracyRatio(p, a, b, q);
    BTL_EVENT_PushVarFrame(5014);
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarOnce(75, 0);
    BTL_EVENT_SetVar(39, func_021D59B4(a, 6));
    BTL_EVENT_SetVar(40, func_021D59B4(b, 7));
    BTL_EVENT_SetVarRanged(53, 4 << 10, 41, 4 << 15);
    BTL_EVENT_DispatchEventChecked(p, 51);
    x = BTL_EVENT_GetVar(39);
    y = BTL_EVENT_GetVar(40);
    flag = BTL_EVENT_GetVar(75);
    if ((BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)b, 17) && y > 6) || flag) y = 6;
    if (BTL_POKEPARAM_TestTurnFlag((struct UtilWork *)a, 14)) BTL_EVENT_MultiplyVar(53, 4915);
    scale = BTL_EVENT_GetVar(53);
    BTL_EVENT_PopVarFrame(5039);
    v = x + 6 - y;
    if (v < 0) v = 0;
    if (v > 12) v = 12;
    chance = BTL_CALC_MulRatio(BTL_CALC_ApplyAccuracyStage((u8)base, (u8)(s8)v), scale);
    if (chance > 100) chance = 100;
    if (func_021B911C(((struct Obj07752 *)p)->f4, 6)) chance = 100;
    if (BTL_CALC_Random(100) < (u8)chance) return 1;
    return 0;
}
