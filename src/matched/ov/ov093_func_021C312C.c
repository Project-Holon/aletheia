/*
 * function: BTL_SERVER_FLOW_QueryStatStageChangeEvent
 * address:  0x021C312C
 * packet:   pkt_ov093_021C312C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Note (final push 2026-10-05 G4L8): the script result is written back into the
 * stack parameter d (the caller BTL_SERVER_FLOW_TryChangeStatStage does value = BTL_SERVER_FLOW_QueryStatStageChangeEvent(..., value)).
 * Assigning to a stack-passed parameter, instead of a fresh local r, keeps the end
 * line as its own pool word (no ldr + adds #7 fold). Both --lang c99 and c EXACT.
 *
 * symbols:
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_POKEPARAM_GetPokeId  0x021D5440  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef enum { K0, K1, K10 = 10 } Kind;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int BTL_SERVER_FLOW_QueryStatStageChangeEvent(u8 *p, u8 *a, Kind b, u8 c, u16 e, int d)
{
    BTL_EVENT_PushVarFrame(8385);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(3, c);
    BTL_EVENT_SetVarReadOnly(0x1F, b);
    BTL_EVENT_SetVarOnce(0x20, d);
    BTL_EVENT_DispatchEventChecked(p, 0x5A);
    d = BTL_EVENT_GetVar(0x20);
    BTL_EVENT_PopVarFrame(8392);
    return d;
}
