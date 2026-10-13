/*
 * function: func_021C7998
 * address:  0x021C7998
 * packet:   pkt_ov093_021C7998
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_PushVarFrame  0x021D74F8  thumb  ov093
 *   BTL_EVENT_SetVarReadOnly  0x021D75EC  thumb  ov093
 *   BTL_EVENT_SetVarOnce  0x021D7630  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

void func_021C7998(u8 *p, u32 x)
{
    BTL_EVENT_PushVarFrame(12930);
    BTL_EVENT_SetVarReadOnly(0x39, x);
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x7d);
    if (BTL_EVENT_GetVar(0x41) == 0)
        BTL_EVENT_DispatchEventChecked(p, 0x7e);
    BTL_EVENT_PopVarFrame(12938);
}
