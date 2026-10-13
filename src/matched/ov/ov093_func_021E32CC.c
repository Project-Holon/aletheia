/*
 * function: HAND_WAZA_HiddenPowerOnWazaTypeCheck
 * address:  0x021E32CC
 * packet:   pkt_ov093_021E32CC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetMon  0x021D5844  thumb  ov093
 *   POKE_TOOL_GetHiddenPowerType  0x02018790  thumb
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern void *BTL_POKEPARAM_GetMon(void *m);
extern u32 POKE_TOOL_GetHiddenPowerType(void *p);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_HiddenPowerOnWazaTypeCheck(int u, void *a, int b)
{
    if (b == BTL_EVENT_GetVar(2))
        BTL_EVENT_OverwriteVar(0x16, POKE_TOOL_GetHiddenPowerType(BTL_POKEPARAM_GetMon(BTL_SERVER_FLOW_GetPokeParam(a, b))));
}
