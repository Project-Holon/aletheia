/*
 * function: FIELD_MSGBG_LoadWindowGraphicsStep
 * address:  0x021902AC
 * packet:   pkt_ov021_021902AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_MSGBG_LoadWindowGraphicsStepFn  0x02192FEC  thumb  ov021
 *
 * Unlabelled tail-call forwarder, called from EVENT_FIELDMAP_CONTROL_RunDefaultFadeIn.
 */

typedef unsigned short u16;

extern void FIELD_MSGBG_LoadWindowGraphicsStepFn(int a, int b, int c);

void FIELD_MSGBG_LoadWindowGraphicsStep(u16 *p, int v)
{
    FIELD_MSGBG_LoadWindowGraphicsStepFn(p[1], p[0], v);
}
