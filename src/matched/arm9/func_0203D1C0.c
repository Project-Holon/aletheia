/*
 * unit:     no
 * function: GFL_NET_IsConnectMember
 * address:  0x0203D1C0
 * packet:   pkt_0203D1B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetSession  0x0203D788  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_HANDLE_IsNegotiationDone  0x020399B8  arm
 *
 * TU: net.c (named by the assert site at 0x0203D2EC, which passes the
 * string at 0x020A7CA0, "net.c").
 *
 * Guard on the network singleton, then a two-step query: look the entry
 * `index` up with GFL_NET_HANDLE_GetNetHandle and ask GFL_NET_HANDLE_IsNegotiationDone about the result.
 * The `moveq r0, #0` is a no-op on the value it guards; it only exists
 * because the source spells the null return out.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GFL_NET_IsConnectMember.c \
 *       --func GFL_NET_IsConnectMember --addr 0x0203D1C0 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

struct NetEntry;

extern void       *GFL_NET_GetSession(void);
typedef signed int     s32;
typedef unsigned char  u8;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetNetHandle(s32 idx);
extern u32 GFL_NET_HANDLE_IsNegotiationDone(u8 *p);

u32 GFL_NET_IsConnectMember(u32 index)
{
    if (GFL_NET_GetSession() == 0) {
        return 0;
    }
    return GFL_NET_HANDLE_IsNegotiationDone((u8 *)GFL_NET_HANDLE_GetNetHandle(index));
}
