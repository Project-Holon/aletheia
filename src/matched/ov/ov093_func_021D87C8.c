/*
 * function: HAND_TOKUSEI_QuickFeetBoostSpeed
 * address:  0x021D87C8
 * packet:   pkt_ov093_021D87C8
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
 *   BTL_POKEPARAM_GetMajorStatusIndex  0x021D62A8  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;

int BTL_EVENT_GetVar(int a);
void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct Unk021D62A8;
int BTL_POKEPARAM_GetMajorStatusIndex(struct Unk021D62A8 *p);
void BTL_EVENT_MultiplyVar(int a, int b);
int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_TOKUSEI_QuickFeetBoostSpeed(void *a, int b, int c)
{
    void *r;
    if (c == BTL_EVENT_GetVar(2)) {
        r = BTL_SERVER_FLOW_GetPokeParam((int *)b, c);
        if (BTL_POKEPARAM_GetMajorStatusIndex(r) != 0) {
            BTL_EVENT_MultiplyVar(0x35, 6 << 10);
            BTL_EVENT_OverwriteVar(0x51, 0);
        }
    }
}
