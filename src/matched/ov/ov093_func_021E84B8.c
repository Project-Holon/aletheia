/*
 * function: HAND_WAZA_PledgeSetCombinedMoveId
 * address:  0x021E84B8
 * packet:   pkt_ov093_021E84B8
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_EVENT_GetVar  0x021D775C  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_PledgeSetCombinedMoveId(int a, int b, int c, int *d)
{
    int k;

    if (c == BTL_EVENT_GetVar(2)) {
        if (d[0] != 0) {
            k = 0;
            switch (d[1]) {
            case 1:
                k = 0x206;
                break;
            case 2:
                k = 0x207;
                break;
            case 3:
                k = 0x208;
                break;
            }
            BTL_EVENT_OverwriteVar(0x13, k);
        }
    }
}
