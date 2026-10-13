/*
 * function: HAND_TOKUSEI_Klutz_SkipCheck
 * address:  0x021DB650
 * packet:   pkt_ov093_021DB650
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_SERVER_FLOW_GetPokeParam  0x021C7CF4  thumb  ov093
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_EVENT_GetFactorPokeId  0x021D70AC  thumb  ov093
 *   gKlutzExemptItemIds     0x021F0B78  data   a2
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern void *BTL_SERVER_FLOW_GetPokeParam(int *p, int i);
struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern unsigned char BTL_EVENT_GetFactorPokeId(unsigned char *p);
extern const u16 gKlutzExemptItemIds[];

int HAND_TOKUSEI_Klutz_SkipCheck(int a, int b, int c, int d, int e, u8 g)
{
    u32 i;

    if (BTL_POKEPARAM_HasSick(BTL_SERVER_FLOW_GetPokeParam((int *)b, g), 0x10) != 0)
        return 0;
    if (c == 5 && g == BTL_EVENT_GetFactorPokeId((unsigned char *)a)) {
        for (i = 0; i < 13; i++) {
            if (e == gKlutzExemptItemIds[i])
                return 0;
        }
        return 1;
    }
    return 0;
}
