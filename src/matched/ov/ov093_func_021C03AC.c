/*
 * function: BTL_SERVER_FLOW_CheckConfusionSelfHit
 * address:  0x021C03AC
 * packet:   pkt_ov093_021C03AC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_POKEPARAM_HasSick  0x021D62C4  thumb  ov093
 *   BTL_SERVER_FLOW_PushInfatuationMessage  0x021C54FC  thumb  ov093
 *   BTL_CALC_RollPercent  0x021D7AF0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
extern int BTL_POKEPARAM_HasSick(struct Unk021D62A8 *p, int i);
extern void BTL_SERVER_FLOW_PushInfatuationMessage(u8 *p, u8 *a);
extern int BTL_CALC_RollPercent(u32 pct);

int BTL_SERVER_FLOW_CheckConfusionSelfHit(u8 *p, u8 *a)
{
    if (BTL_POKEPARAM_HasSick((struct Unk021D62A8 *)a, 7) != 0) {
        BTL_SERVER_FLOW_PushInfatuationMessage(p, a);
        if (BTL_CALC_RollPercent(50) != 0) return 1;
    }
    return 0;
}
