/*
 * function: UNION_SUBDISP_GetScrollRange
 * address:  0x021F0D40
 * packet:   pkt_ov031_021F0D40
 * region:   ov031
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (no lr push) sitting in a word run; filed as a blocker of
 * UNION_SUBDISP_SetScrollFromKnob and UNION_SUBDISP_SetKnobFromScroll.
 *
 * symbols:
 *   UNION_SUBDISP_GetScrollRange  0x021F0D40  thumb
 */

typedef struct {
    char pad[0x43C];
    int a;
} B;

int UNION_SUBDISP_GetScrollRange(B *p)
{
    int v = p->a;

    if (v >= 0x1E)
        v = 0x1D;
    v -= 2;
    if (v < 0)
        v = 0;
    return v;
}
