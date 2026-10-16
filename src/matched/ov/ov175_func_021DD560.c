/*
 * function: sakeCancelRequest
 * address:  0x021DD560
 * packet:   pkt_ov175_021DD560
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * ARM tail call: ldr ip, =target; bx ip.  The listing labels the
 * two-instruction body func_021DD560 between sakeGetFileUploadURL and
 * sakeiInitRequest; the C is the public SAKE cancel wrapper of
 * src/game/ov175/sakemain.c, which forwards to the internal
 * sakeiCancelRequest.
 *
 * symbols:
 *   sakeiCancelRequest  0x021DD328  arm  ov175
 */

struct SAKEInternal;
struct SAKERequestInternal;
extern int sakeiCancelRequest(struct SAKEInternal *sake, struct SAKERequestInternal *request);

int sakeCancelRequest(struct SAKEInternal *sake, struct SAKERequestInternal *request)
{
    return sakeiCancelRequest(sake, request);
}
