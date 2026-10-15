/*
 * function: VIEWER_ACTOR_SetSelection
 * address:  0x021C81A4
 * packet:   pkt_ov111_021C81A4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   VIEWER_ACTOR_UpdateRowVisibility  0x021C810C  thumb
 *   VIEWER_ACTOR_RefreshRows  0x021C8364  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;

typedef struct {
    unsigned char pad0[0x114];
    u16 f114;
    u16 f116;
} Work;

extern void VIEWER_ACTOR_UpdateRowVisibility(Work *p, int a, int b);
extern void VIEWER_ACTOR_RefreshRows(Work *p);

void VIEWER_ACTOR_SetSelection(Work *p, u16 v)
{
    p->f114 = v;
    VIEWER_ACTOR_UpdateRowVisibility(p, v, p->f116);
    VIEWER_ACTOR_RefreshRows(p);
}
