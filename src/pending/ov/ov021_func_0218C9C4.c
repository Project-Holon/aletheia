/*
 * function: func_0218C9C4
 * address:  0x0218C9C4
 * packet:   pkt_ov021_0218C9C4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * 2026-10-01: same ops and size; the original loads pos[2] once, computes
 * both bounds, stores out->b before loading pos[0], and stores out->a after
 * it. Local/ordering variants tried keep a reload or a different colour.
 * 2026-10-02: also inert: struct-copy *out = r (initialiser or fields),
 * long/V3-struct pos, z/x locals at top (scheduler then hoists both loads),
 * lo kept in a local stored after the x load (CW sinks the subs to its
 * store). Storing a after the pos[0] load needs a source order the
 * scheduler cannot produce from any of these.
 */

typedef struct {
    int a;
    int b;
    int c;
    int d;
} Rect;

void func_0218C9C4(Rect *out, int *pos)
{
    out->a = pos[2] - 0x30000;
    out->b = pos[2] + 0x30000;
    out->c = pos[0] - 0x20000;
    out->d = pos[0] + 0x20000;
}
