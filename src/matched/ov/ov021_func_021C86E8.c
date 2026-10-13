/*
 * function: PLEASURE_BOAT_AdvanceTime
 * address:  0x021C86E8
 * packet:   pkt_ov021_021C86E8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * The sum is built in two statements (`r = f4 % 1350; r += b * 30;`) so
 * the multiply lands after the _s32_div_f call; one expression, or a
 * separate `t = b * 30` local, hoists it above the call into r4.
 * Addresses are Black-image addresses.
 */

typedef struct {
    int f0;
    short f4;
    short f6;
    int f8;
} S;

void PLEASURE_BOAT_AdvanceTime(S *p, int b, int c)
{
    int r;

    r = p->f4 % 1350;
    r += b * 30;
    if (r >= 1350) {
        if (c) {
            p->f4 = (p->f8 + 1) * 1350 - 1;
        } else {
            p->f4 = (p->f8 + 1) * 1350;
            p->f8++;
        }
    } else {
        p->f4 += b * 30;
    }
}
