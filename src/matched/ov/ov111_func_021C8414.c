/*
 * function: VIEWER_ACTOR_StepScrollCount
 * address:  0x021C8414
 * packet:   pkt_ov111_021C8414
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:

 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef int s32;

void VIEWER_ACTOR_StepScrollCount(u8 *p, int idx)
{
    s32 *count = (s32 *)(p + 0x188);

    if (count[idx] < 0x23F) {
        count[idx]++;
    }
}
