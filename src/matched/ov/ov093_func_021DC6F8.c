/*
 * function: BTL_ABILITY_SandForceBoostPower
 * address:  0x021DC6F8
 * packet:   pkt_ov093_021DC6F8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   func_021C8288  0x021C8288  thumb  ov093
 *   BTL_EVENT_MultiplyVar  0x021D7704  thumb  ov093
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int func_021C8288(u8 *p);
extern void BTL_EVENT_MultiplyVar(int a, int b);

void BTL_ABILITY_SandForceBoostPower(int a, void *p, int v)
{
    u8 k;

    if (v == BTL_EVENT_GetVar(3) && func_021C8288(p) == 4) {
        k = BTL_EVENT_GetVar(0x16);
        if (k == 4 || k == 5 || k == 8)
            BTL_EVENT_MultiplyVar(0x31, 0x14cd);
    }
}
