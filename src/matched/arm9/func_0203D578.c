/*
 * function: GFL_NET_IsSendQueueEntryOfHandle
 * address:  0x0203D578
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Forwards the first argument through GFL_NET_HANDLE_GetNetHandleID and passes the result
 * with the second argument to GFL_NET_SYSTEM_IsSendQueueEntry.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_IsSendQueueEntryOfHandle.c \
 *       --func GFL_NET_IsSendQueueEntryOfHandle --addr 0x0203D578 --arm --cc 1.1p1
 *
 * symbols:
 *   GFL_NET_SYSTEM_IsSendQueueEntry  0x02039468  arm
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 */

typedef unsigned int u32;

struct Entry;
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);
extern void GFL_NET_SYSTEM_IsSendQueueEntry(u32 b, u32 r);

void GFL_NET_IsSendQueueEntryOfHandle(int a, u32 b)
{
    u32 r = GFL_NET_HANDLE_GetNetHandleID((void *)a);

    GFL_NET_SYSTEM_IsSendQueueEntry(b, r);
}
