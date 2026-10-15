/*
 * function: BTL_SERVER_FLOW_RemoveSubstituteTargets
 * address:  0x021BF1B4
 * packet:   pkt_ov093_021BF1B4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   INTRO_MSG_SetMsgBank  0x021BF204  thumb  ov093
 *   func_021BF214  0x021BF214  thumb  ov093
 *   func_021BF224  0x021BF224  thumb  ov093
 *   func_021BF234  0x021BF234  thumb  ov093
 *   BTL_POKEPARAM_HasSubstitute  0x021D6D7C  thumb  ov093
 *   WAZA_TOOL_GetFlag  0x0201BEB8  thumb
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void INTRO_MSG_SetMsgBank(int c);
extern int func_021BF214(int c);
extern void func_021BF224(int c, int x);
extern int func_021BF234(int c);
extern u32 BTL_POKEPARAM_HasSubstitute(u8 *p);
extern u32 WAZA_TOOL_GetFlag(u16 id, u32 bit);

void BTL_SERVER_FLOW_RemoveSubstituteTargets(int u, u16 *b, int s, int c, int e)
{
    int x;
    INTRO_MSG_SetMsgBank(c);
    x = func_021BF214(c);
    while (x != 0) {
        if (s != x && BTL_POKEPARAM_HasSubstitute((u8 *)x) != 0 && e == 0 && WAZA_TOOL_GetFlag((u16)((void *)*b), 0xd) == 0)
            func_021BF224(c, x);
        x = func_021BF234(c);
    }
}
