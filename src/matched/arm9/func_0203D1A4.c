/*
 * function: func_0203D1A4
 * address:  0x0203D1A4
 * packet:   pkt_0203CDD4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *
 * Forward to GFL_NET_HANDLE_GetNetHandleID and mask the result to a byte.  GFL_NET_HANDLE_GetNetHandleID is
 * called from GFL_NET_IsSendQueueEntryOfHandle (outside this range), which is what attests the
 * `bl` here as a real function rather than a wildcarded relocation.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D1A4.c \
 *       --func func_0203D1A4 --addr 0x0203D1A4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct Link;

struct Entry;
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);

u32 func_0203D1A4(struct Link *p)
{
    return GFL_NET_HANDLE_GetNetHandleID((struct Entry *)p) & 0xff;
}
