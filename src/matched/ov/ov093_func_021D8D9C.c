/*
 * function: HAND_TOKUSEI_CheckAllyHasAbility
 * address:  0x021D8D9C
 * packet:   pkt_ov093_021D8D9C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * lever: BTL_SERVER_FLOW_CollectAlivePokeIds returns a u8 count, so n is a u8 and the count is spilled and reloaded.
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeViewPos  0x021C8010  thumb  ov093
 *   BTL_SERVER_FLOW_CollectAlivePokeIds  0x021C7F68  thumb  ov093
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

extern int BTL_SERVER_FLOW_GetPokeViewPos(u8 *p, unsigned int v);
extern u8 BTL_SERVER_FLOW_CollectAlivePokeIds(int *p, int b, u8 *out);
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int func_021D59B4(u8 *p, int k);

int HAND_TOKUSEI_CheckAllyHasAbility(void *a, int k, u8 *buf, int v)
{
    int t;
    u8 n;
    u8 i;

    t = BTL_SERVER_FLOW_GetPokeViewPos(a, k);
    if (t != 6) {
        n = BTL_SERVER_FLOW_CollectAlivePokeIds(a, (u16)((7 << 8) | t), buf);
        for (i = 0; i < n; i++) {
            if (k != buf[i]) {
                if (v == func_021D59B4(BTL_SERVER_FLOW_GetPokeParam(a, buf[i]), 0x11))
                    return 1;
            }
        }
    }
    return 0;
}
