/*
 * unit:     no
 * function: GFL_NET_HANDLE_RecvNegotiationReturn
 * address:  0x0203A150
 * packet:   pkt_0203A150
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   GFL_NET_GetInitParam  0x0203D798  arm
 *   GFL_NET_HANDLE_GetNetHandleID  0x020395EC  arm
 *   GFL_NET_HANDLE_SetNegotiationEnd  0x0203A118  arm
 *   GF_STANDARD_CompareBytes  0x0203EFC8  arm
 *   GFL_NET_HANDLE_GetNetHandle  0x0203996C  arm
 *   GFL_NET_IRC_WIRELESS_AddMacAddress  0x0203DAC4  arm
 *   OS_GetMacAddress  0x02087C6C  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Msg
{
    u8 pad_00[6];
    u8 mac[6];
    u8 f0c;
    u8 f0d;
    u8 f0e;
    u8 f0f;
};

struct Peer
{
    u8 pad_00[0x4a];
    u8 f4a;
};

struct Glob
{
    u8 pad_00[0xc];
    void (*f0c)(int, u32);
    u8 pad_10[0x57];
    u8 f67;
    u8 pad_68[6];
    u16 f6e;
};

typedef signed int     s32;
extern void *GFL_NET_GetInitParam(void);
struct Entry;
extern int GFL_NET_HANDLE_GetNetHandleID(struct Entry *a);
extern void GFL_NET_HANDLE_SetNegotiationEnd(u8 *p);
extern s32 GF_STANDARD_CompareBytes(const u8 *a, const u8 *b, u32 n);
extern struct Peer *GFL_NET_HANDLE_GetNetHandle(u32);
extern void GFL_NET_IRC_WIRELESS_AddMacAddress(const u8 *mac);
extern void OS_GetMacAddress(u8 *);

void GFL_NET_HANDLE_RecvNegotiationReturn(int a0, int a1, struct Msg *msg, int a3, struct Peer *peer)
{
    struct Glob *g;
    u8 mac[8];
    u32 id;

    g = GFL_NET_GetInitParam();
    id = GFL_NET_HANDLE_GetNetHandleID((struct Entry *)peer);
    if (id == 0xff)
    {
        peer->f4a = 5;
        return;
    }

    if (g->f6e != 0)
    {
        if (g->f6e != msg->f0f)
            GFL_NET_HANDLE_SetNegotiationEnd((u8 *)peer);
        if (g->f6e != msg->f0e)
            GFL_NET_HANDLE_SetNegotiationEnd((u8 *)peer);
    }
    else
    {
        if (g->f67 != msg->f0f)
            GFL_NET_HANDLE_SetNegotiationEnd((u8 *)peer);
        if (g->f67 != msg->f0e)
            GFL_NET_HANDLE_SetNegotiationEnd((u8 *)peer);
    }

    OS_GetMacAddress(mac);
    if (GF_STANDARD_CompareBytes(msg->mac, mac, 6) == 0)
    {
        if (msg->f0c != GFL_NET_HANDLE_GetNetHandleID((struct Entry *)peer))
            GFL_NET_HANDLE_SetNegotiationEnd((u8 *)peer);
    }

    if (peer->f4a == 7)
        return;

    GFL_NET_HANDLE_GetNetHandle(msg->f0c)->f4a = 5;

    if (g->f0c != 0)
        g->f0c(a3, msg->f0c);

    GFL_NET_IRC_WIRELESS_AddMacAddress(msg->mac);
    GFL_NET_IRC_WIRELESS_AddMacAddress((const u8 *)msg);
}
