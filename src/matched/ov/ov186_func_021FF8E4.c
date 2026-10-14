/*
 * function: BR_NET_StepWaitRequest
 * address:  0x021FF8E4
 * packet:   pkt_021FF8E4
 * region:   ov186
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 0x021FF8E0 is an unlabelled two-byte `bx lr` leaf reached through the pool
 * word 0x021FF8E1 (thumb bit set); now matched as src/matched/BR_NET_StepIdle.c.
 *
 * symbols:
 *   GDS_RAP_IsIdle  0x021D730C  thumb  ov125
 *   BR_NET_SetStep  0x021FFB68  thumb  ov186
 *   BR_NET_StepIdle  0x021FF8E0  thumb  ov186
 */

extern int GDS_RAP_IsIdle(char *p);
extern void BR_NET_SetStep(char *p, int v);
extern void BR_NET_StepIdle(void);

void BR_NET_StepWaitRequest(void *p, int a1, int a2)
{
    if (GDS_RAP_IsIdle((char *)a2) != 0)
        BR_NET_SetStep(p, (int)((void *)BR_NET_StepIdle));
}
