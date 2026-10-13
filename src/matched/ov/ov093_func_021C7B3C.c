/*
 * function: func_021C7B3C
 * address:  0x021C7B3C
 * packet:   pkt_ov093_021C7B3C
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
 *   BTL_EVENT_DispatchEventChecked  0x021D70F0  thumb  ov093
 *   BTL_EVENT_PopVarFrame  0x021D7540  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern void BTL_EVENT_PopVarFrame(int line);

void func_021C7B3C(u8 *p, u32 a, u16 b, u16 c)
{
    BTL_EVENT_PushVarFrame(13068);
    BTL_EVENT_SetVarReadOnly(2, a);
    BTL_EVENT_SetVarReadOnly(0xf, b);
    BTL_EVENT_SetVarReadOnly(0x10, c);
    BTL_EVENT_DispatchEventChecked(p, 0x89);
    BTL_EVENT_PopVarFrame(13073);
}
