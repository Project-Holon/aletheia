/*
 * function: func_021C7BA8
 * address:  0x021C7BA8
 * packet:   pkt_ov093_021C7BA8
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
 *   BTL_EVENT_SetVar  0x021D75A8  thumb  ov093
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVar(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

void func_021C7BA8(u8 *p, u8 a, u32 b, u32 c, u32 *out)
{
    BTL_EVENT_PushVarFrame(13102);
    BTL_EVENT_SetVarReadOnly(2, a);
    BTL_EVENT_SetVarReadOnly(0x52, c);
    BTL_EVENT_SetVarReadOnly(0x53, b);
    BTL_EVENT_SetVar(0x1e, *out);
    BTL_EVENT_DispatchEventChecked(p, 0x9f);
    *out = BTL_EVENT_GetVar(0x1e);
    BTL_EVENT_PopVarFrame(13109);
}
