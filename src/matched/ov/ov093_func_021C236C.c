/*
 * function: BTL_SERVER_FLOW_RollMoveAddedSick
 * address: 0x021C236C
 * packet: pkt_ov093_021C236C
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   WAZA_TOOL_GetSickCont 0x0201BF58 thumb
 *   BTL_CALC_MakeSickContFromSpec 0x021D7C70 thumb ov093
 *   BTL_EVENT_PushVarFrame 0x021D74F8 thumb ov093
 *   BTL_POKEPARAM_GetPokeId 0x021D5440 thumb ov093
 *   BTL_EVENT_SetVarReadOnly 0x021D75EC thumb ov093
 *   BTL_EVENT_SetVar 0x021D75A8 thumb ov093
 *   BTL_EVENT_SetVarOnce 0x021D7630 thumb ov093
 *   BTL_EVENT_DispatchEventChecked 0x021D70F0 thumb ov093
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   BTL_EVENT_PopVarFrame 0x021D7540 thumb ov093
 *   BTL_CALC_Random 0x021D78AC thumb ov093
 *   BTL_MAIN_ReturnZero 0x021B911C thumb ov093
 */
#include "../include/Obj21082.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u16 v; } W;
typedef struct { u32 v; } Word;
extern u32 WAZA_TOOL_GetParam(u16, u32);
extern W WAZA_TOOL_GetSickCont(u16);
extern void BTL_CALC_MakeSickContFromSpec(W, u32, Word *);
extern void BTL_EVENT_PushVarFrame(int);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int, u32);
extern void BTL_EVENT_SetVar(int, u32);
extern void BTL_EVENT_SetVarOnce(int, u32);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern u32 BTL_EVENT_GetVar(int);
extern void BTL_EVENT_PopVarFrame(int);
extern u32 BTL_CALC_Random(u32);
extern int BTL_MAIN_ReturnZero(void *, int);
static inline int chance(u32 n)
{
    return BTL_CALC_Random(100) < n;
}
u32 BTL_SERVER_FLOW_RollMoveAddedSick(u8 *p, u16 id, u8 *a, u8 *b, Word *dest)
{
    u32 s;
    W w;
    Word out;
    u8 rate;
    u32 result;
    u8 changedRate;
    u8 veto;
    s = WAZA_TOOL_GetParam(id, 11);
    w = WAZA_TOOL_GetSickCont(id);
    rate = WAZA_TOOL_GetParam(id, 12);
    BTL_CALC_MakeSickContFromSpec(w, (u32)a, &out);
    BTL_EVENT_PushVarFrame(0x1d7c);
    BTL_EVENT_SetVarReadOnly(4, BTL_POKEPARAM_GetPokeId(b));
    BTL_EVENT_SetVarReadOnly(3, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(0x12, id);
    BTL_EVENT_SetVar(0x1d, s);
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_SetVarOnce(0x1e, out.v);
    BTL_EVENT_SetVar(0x26, rate);
    BTL_EVENT_DispatchEventChecked(p, 0x64);
    result = BTL_EVENT_GetVar(0x1d);
    rate = BTL_EVENT_GetVar(0x26);
    veto = BTL_EVENT_GetVar(0x41);
    if (result == 0xffff) result = 0;
    out.v = BTL_EVENT_GetVar(0x1e);
    BTL_EVENT_PopVarFrame(0x1d8f);
    if (!veto && result) {
        if (chance(rate)) {
            *dest = out;
            return result;
        }
        if (BTL_MAIN_ReturnZero(((struct Obj21082 *)p)->f4, 0)) {
            *dest = out;
            return result;
        }
    }
    return 0;
}
