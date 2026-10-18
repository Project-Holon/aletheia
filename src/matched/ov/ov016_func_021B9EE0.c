/*
 * function: SendFrame
 * address:  0x021B9EE0
 * packet:   pkt_ov016_021BA804
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SendBroadcast  0x021B9EA4  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol SendFrame (name from the vendor
 * object; a 12-byte local with no label in function_starts.txt, witnessed by three calls
 * from AutoConfigThreadEx). atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126
 * (its .comment), which is the 2.0/sp1p2 front end; see aoss_release (aoss_release.c).
 * DWARF lists (sock, lpb, size) and drops one unused parameter; the body moves r2/r3 into
 * r1/r2, so the dropped parameter is the second one.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B9EE0.c \
 *       --func SendFrame --addr 0x021B9EE0 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
extern int SendBroadcast(int sock, unsigned char *lpb, int size);

static int SendFrame(int sock, void *target, unsigned char *lpb, int size)
{
    return SendBroadcast(sock, lpb, size);
}
