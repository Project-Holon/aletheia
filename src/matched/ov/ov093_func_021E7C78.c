/*
 * function: HAND_WAZA_FinalGambitSetFixedDamage
 * address:  0x021E7C78
 * packet:   pkt_ov093_021E7C78
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
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_FinalGambitSetFixedDamage(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(3))
        BTL_EVENT_OverwriteVar(0x37, func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(b, c), 0xd));
}
