/*
 * function: HAND_WAZA_VenoshockDoublePowerOnPoison
 * address:  0x021E6FC8
 * packet:   pkt_ov093_021E6FC8
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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void HAND_WAZA_VenoshockDoublePowerOnPoison(int x, int a, int c)
{
    int t = 4;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam((int *)a, (u8)BTL_EVENT_GetVar(4)), 5) != 0) {
            BTL_EVENT_MultiplyVar(0x31, t << 11);
        }
    }
}
