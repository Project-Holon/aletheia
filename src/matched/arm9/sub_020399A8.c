/*
 * function: GFL_NET_HANDLE_GetCurrentHandle
 * address:  0x020399A8
 * packet:   pkt_020398B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid  0x02039338  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *
 * A two-call forwarder: the index GFL_NET_SYSTEM_GetCurrentAid returns goes straight to
 * GFL_NET_HANDLE_GetNetHandle through r0, and that entry is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_HANDLE_GetCurrentHandle.c  *       --func GFL_NET_HANDLE_GetCurrentHandle --addr 0x020399A8 --cc 1.1p1 --arm
 */

struct Entry;

typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(int idx);

struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void)
{
    return GFL_NET_HANDLE_GetNetHandle(GFL_NET_SYSTEM_GetCurrentAid());
}
