/*
 * function: HAND_WAZA_DreamEaterFailIfAwake
 * address:  0x021E101C
 * packet:   pkt_ov093_021E101C
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
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

extern int BTL_EVENT_GetVar(int key);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
typedef unsigned int   u32;
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_DreamEaterFailIfAwake(int a, int b, int c)
{
    int n;

    if (c != BTL_EVENT_GetVar(3))
        return;
    n = (unsigned char)BTL_EVENT_GetVar(4);
    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam((int *)b, n), 2) == 0)
        BTL_EVENT_OverwriteVar(64, 1);
}
