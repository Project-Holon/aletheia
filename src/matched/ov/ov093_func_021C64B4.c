/*
 * function: BTL_SERVER_FLOW_GetMoveParam
 * address:  0x021C64B4
 * packet:   pkt_ov093_021C64B4
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct except the call to the unlabelled arm9 leaf 0x0201C1E8,
 * which has no witness outside this function (evidence class: none until the
 * leaf is filed; it is the integrator's, inside a labelled arm9 region). Verified C for
 * that leaf (`one` --thumb, no --region, EXACT, 12 bytes):
 *
 *   extern u32 WAZA_TOOL_GetParam(void *p, u32 id);   // symbols: WAZA_TOOL_GetParam 0x0201BD28 thumb
 *   u32 WAZA_TOOL_GetDamageType(void *p) { return WAZA_TOOL_GetParam(p, 2); }
 *
 * Once the leaf's shard exists re-run this file; it should go EXACT.
 *
 * symbols:
 *   WAZA_TOOL_GetType   0x0201C1C8  thumb
 *   WAZA_TOOL_GetDamageType   0x0201C1E8  thumb
 *   WAZA_TOOL_GetParam   0x0201BD28  thumb
 *   BTL_POKEPARAM_GetTypePair  0x021D57FC  thumb  ov093
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern u8 WAZA_TOOL_GetType(void *p);
extern int WAZA_TOOL_GetDamageType(int a);
extern u32 WAZA_TOOL_GetParam(u16 id, u32 field);
extern u16 BTL_POKEPARAM_GetTypePair(void *p);
extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

struct Out64B4 {
    u16 h0;
    u16 h2;
    u16 h4;
    u8 b6;
    u8 pad7;
    u32 w8;
    u32 wC;
    u32 w10;
};

void BTL_SERVER_FLOW_GetMoveParam(u8 *p, u16 q, u8 *a, struct Out64B4 *out)
{
    int line = 11464;
    BTL_EVENT_PushVarFrame(line);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarOnce(0x16, WAZA_TOOL_GetType((void *)q));
    BTL_EVENT_SetVar(0x1C, BTL_POKEPARAM_GetTypePair(a));
    BTL_EVENT_SetVar(0x1A, WAZA_TOOL_GetDamageType(q));
    BTL_EVENT_SetVar(0x1B, WAZA_TOOL_GetParam(q, 0x1B));
    BTL_EVENT_SetVarOnce(0x4B, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x28);
    out->h0 = q;
    out->h2 = q;
    out->b6 = BTL_EVENT_GetVar(0x16);
    out->h4 = BTL_EVENT_GetVar(0x1C);
    out->w8 = BTL_EVENT_GetVar(0x1A);
    out->wC = BTL_EVENT_GetVar(0x1B);
    out->w10 = 0;
    if (BTL_EVENT_GetVar(0x4B) != 0) {
        out->b6 = 0x11;
    }
    BTL_EVENT_PopVarFrame(11493);
}
