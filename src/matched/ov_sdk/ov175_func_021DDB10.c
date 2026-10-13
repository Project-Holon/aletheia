/*
 * function: sakeiStartRequest
 * address:  0x021DDB10
 * packet:   pkt_021DDB10
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sakeiSetupRequest  0x021DD98C  arm
 *   sakeiExecuteRequest  0x021DDA98  arm
 *
 * Store the +0x20 flag, run the +0x08 side of the pair and, when it comes
 * back empty, tear the object down and report 0.
 */

struct SAKERequestInternal;
extern int sakeiSetupRequest(struct SAKERequestInternal *request);
struct SAKERequestInternal;
extern void sakeiExecuteRequest(struct SAKERequestInternal *request);

int sakeiStartRequest(void *p, int v)
{
    int r;

    *(int *)((char *)p + 0x20) = v;
    r = sakeiSetupRequest(p);
    if (r)
        return r;
    sakeiExecuteRequest(p);
    return 0;
}

