/*
 * function: func_021EF1D4
 * address:  0x021EF1D4
 * packet:   pkt_ov170_021EF1D4
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_HitCont 0x02035BA4 arm
 *   TOUCHPANEL_GetPointCont 0x02035CB8 arm
 *   d_021F0034 0x021F0034 data a1
 */

extern int TOUCHPANEL_HitCont(const void *p);
extern unsigned TOUCHPANEL_GetPointCont(unsigned *outA, unsigned *outB);
extern const unsigned char d_021F0034[];

int func_021EF1D4(unsigned *a, unsigned *b)
{
    if (TOUCHPANEL_HitCont(d_021F0034) != -1) {
        TOUCHPANEL_GetPointCont(a, b);
        return 1;
    }
    return 0;
}
