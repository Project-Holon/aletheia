/*
 * function: func_021C77B0
 * address:  0x021C77B0
 * packet:   pkt_ov093_021C77B0
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern void BTL_EVENT_PushVarFrame(int line);
extern u8 BTL_POKEPARAM_GetPokeId(u8 *p);
extern void BTL_EVENT_SetVarReadOnly(int key, u32 val);
extern void BTL_EVENT_SetVarOnce(int key, u32 val);
extern void BTL_EVENT_DispatchEventChecked(void *a, int id);
extern int BTL_EVENT_GetVar(int key);
extern void BTL_EVENT_PopVarFrame(int line);

int func_021C77B0(u8 *p, u8 *a, u32 b, u32 c, u32 d, u32 e)
{
    int r;
    int res;

    BTL_EVENT_PushVarFrame(12801);
    BTL_EVENT_SetVarReadOnly(2, BTL_POKEPARAM_GetPokeId(a));
    BTL_EVENT_SetVarReadOnly(3, c);
    BTL_EVENT_SetVarReadOnly(0x1f, b);
    BTL_EVENT_SetVarReadOnly(0x20, d);
    BTL_EVENT_SetVarReadOnly(0x19, e);
    res = 0;
    BTL_EVENT_SetVarOnce(0x41, 0);
    BTL_EVENT_DispatchEventChecked(p, 0x5b);
    r = BTL_EVENT_GetVar(0x41);
    BTL_EVENT_PopVarFrame(12810);
    if (r == 0)
        res = 1;
    return res;
}
