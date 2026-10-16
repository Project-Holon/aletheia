/*
 * function: BTLV_CORE_PlayEffectivenessSe
 * address:  0x021EA32C
 * packet:   pkt_ov093_021EA32C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTLV_SCU_PlaySeUnlessMainStep  0x021EAF00  thumb  ov093
 */
typedef unsigned char u8;

extern void BTLV_SCU_PlaySeUnlessMainStep(u8 *p, int a);

void BTLV_CORE_PlayEffectivenessSe(u8 *p, int k)
{
    int v;

    switch (k) {
    case 2:
        v = 0x563;
        break;
    case 3:
        v = 0x565;
        break;
    default:
        v = 0x564;
        break;
    }
    BTLV_SCU_PlaySeUnlessMainStep(p, v);
}
