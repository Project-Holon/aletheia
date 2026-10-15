/*
 * function: ServerBrowserClear
 * address:  0x0219F00C
 * packet:   pkt_02155168
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Calls the two block helpers sixty bytes apart.
 *
 * symbols:
 *   ServerBrowserHalt  0x0219EFF0  arm  ov009
 *   SBServerListClear  0x0219F830  arm  ov009
 */

extern void ServerBrowserHalt(char *p);
struct SBL;
extern void SBServerListClear(struct SBL *slist);

void ServerBrowserClear(char *p)
{
    ServerBrowserHalt(p);
    SBServerListClear((struct SBL *)(p + 0x60));
}

