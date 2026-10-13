/*
 * function: HAND_TOKUSEI_CheckRedirectMoveType
 * address:  0x021DB4E8
 * packet:   pkt_ov093_021DB4E8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_SERVER_FLOW_CheckAllyMoveAutoHitById  0x021C8290  thumb  ov093
 *   func_021DB550  0x021DB550  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_SERVER_FLOW_CheckAllyMoveAutoHitById(u8 *p, int a, int b, void *item);
extern int func_021DB550(int t);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

int HAND_TOKUSEI_CheckRedirectMoveType(int a, int b, int c, int d)
{
    u8 k;
    u16 t;
    u8 n;

    k = BTL_EVENT_GetVar(3);
    if (k != b && d == BTL_EVENT_GetVar(0x16)) {
        t = BTL_EVENT_GetVar(0x12);
        if (BTL_SERVER_FLOW_CheckAllyMoveAutoHitById((u8 *)a, k, b, (void *)t) == 0 && func_021DB550(t) == 0) {
            n = BTL_EVENT_GetVar(4);
            if (BTL_EVENT_OverwriteVar(4, b) != 0 && n != b)
                return 1;
        }
    }
    return 0;
}
