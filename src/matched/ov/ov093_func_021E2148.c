/*
 * function: HAND_WAZA_RageEndOnActionStart
 * address:  0x021E2148
 * packet:   pkt_ov093_021E2148
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
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   HAND_WAZA_RemoveMoveHandlerOfPoke  0x021E03D8  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct QQ;
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern void HAND_WAZA_RemoveMoveHandlerOfPoke(u8 *a, int b);

void HAND_WAZA_RageEndOnActionStart(void *u, int a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(2) && p[6] != 0)
        HAND_WAZA_RemoveMoveHandlerOfPoke(BTL_SERVER_FLOW_GetPokeParam((int *)a, b), BTL_EVENT_GetFactorKey(u));
}
