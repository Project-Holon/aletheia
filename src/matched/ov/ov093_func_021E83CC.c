/*
 * function: HAND_WAZA_PledgeCheckCombo
 * address:  0x021E83CC
 * packet:   pkt_ov093_021E83CC
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
 *   BTL_EVENT_GetClientReservedChoice  0x021D6E50  thumb  ov093
 *   BTL_EVENT_GetFactorKey  0x021D70A8  thumb  ov093
 *   HAND_WAZA_FindPledgeCombo  0x021E8384  thumb  ov093
 *   BTL_EVENT_OverwriteVar  0x021D76BC  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern int BTL_EVENT_GetVar(int key);
struct QQ;
extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
extern int BTL_EVENT_GetClientReservedChoice(u8 *p, u8 *id, u16 *value);
extern u16 BTL_EVENT_GetFactorKey(struct QQ *p);
extern int HAND_WAZA_FindPledgeCombo(u32 x, u32 y);
extern int BTL_EVENT_OverwriteVar(int key, u32 val);

void HAND_WAZA_PledgeCheckCombo(void *a, void *b, int c, int *d)
{
    u16 y;
    u8 x;
    int r;
    u8 k;

    if (c == BTL_EVENT_GetVar(3)) {
        if (BTL_EVENT_GetClientReservedChoice(BTL_SERVER_FLOW_GetPokeParam(b, c), &x, &y) != 0) {
            r = HAND_WAZA_FindPledgeCombo(BTL_EVENT_GetFactorKey(a), y);
            k = BTL_EVENT_GetVar(0x16);
            if (r != 0) {
                d[1] = r;
                d[0] = 1;
                d[2] = x;
                switch (r) {
                case 1:
                    k = 10;
                    break;
                case 2:
                    k = 9;
                    break;
                case 3:
                    k = 11;
                    break;
                }
                BTL_EVENT_OverwriteVar(0x16, k);
            }
        }
    }
}
