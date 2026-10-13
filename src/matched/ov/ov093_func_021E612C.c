/*
 * function: HAND_WAZA_FakeOutCheckFail
 * address:  0x021E612C
 * packet:   pkt_ov093_021E612C
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
 *   BTL_POKEPARAM_TestContFlag  0x021D5BDC  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct UtilWork;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_POKEPARAM_TestContFlag(struct UtilWork *p, u32 n);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_FakeOutCheckFail(int a, void *b, int c)
{
    if (c == BTL_EVENT_GetVar(2)) {
        if (BTL_POKEPARAM_TestContFlag(BTL_SERVER_FLOW_GetPokeParam(b, c), 0) != 0)
            BTL_EVENT_OverwriteVar(0x22, 0x1a);
    }
}
