/*
 * function: func_021E32F8
 * address:  0x021E32F8
 * packet:   pkt_ov093_021E32F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C7CF4  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetHiddenPowerPower  0x02018820  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *func_021C7CF4(int *p, int i);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern u32 POKE_TOOL_GetHiddenPowerPower(void *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void func_021E32F8(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x30, POKE_TOOL_GetHiddenPowerPower(BTL_POKEPARAM_GetMon(func_021C7CF4(a, b))));
}
