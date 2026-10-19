/*
 * function: HAND_WAZA_LeechSeedSetSickCont
 * address:  0x021E2004
 * packet:   pkt_ov093_021E2004
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetFrontPosOfPoke  0x021C7D00  thumb  ov093
 *   BTL_SICKCONT_MakeKind1Value  0x021E89D4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

typedef struct Word { unsigned int v; } Word;
extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_GetFrontPosOfPoke(u8 *p, int b);
extern Word BTL_SICKCONT_MakeKind1Value(int a);
extern int BTL_EVENT_OverwriteVar(int a, Word b);

void HAND_WAZA_LeechSeedSetSickCont(int u, int a, int b)
{
    if (b == BTL_EVENT_GetVar(3)) {
        Word t = BTL_SICKCONT_MakeKind1Value(BTL_SERVER_FLOW_GetFrontPosOfPoke((u8 *)a, b));
        BTL_EVENT_OverwriteVar(0x1e, t);
    }
}
