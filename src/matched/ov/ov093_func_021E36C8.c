/*
 * function: HAND_WAZA_ThiefOnWazaPrepare
 * address:  0x021E36C8
 * packet:   pkt_ov093_021E36C8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_GetItem  0x021D5B40  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_EVENT_GetVar(int key);
struct QI;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern u16 BTL_POKEPARAM_GetItem(struct QI *p);

void HAND_WAZA_ThiefOnWazaPrepare(int u, void *a, int b, int *p)
{
    if (b == BTL_EVENT_GetVar(3))
        *p = (BTL_POKEPARAM_GetItem(BTL_SERVER_FLOW_GetPokeParam(a, b)) != 0) ? 1 : 0;
}
