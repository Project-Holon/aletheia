/*
 * function: POKETRADE_PROC_RecvPeerWordB
 * address: 0x021D935C
 * packet: pkt_ov119_021D935C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   POKETRADE_PROC_ClearSideMon 0x021D94A0 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern void POKETRADE_PROC_ClearSideMon(void *, int);
void POKETRADE_PROC_RecvPeerWordB(u32 a, u32 b, u32 c, void *base, void *e)
{
    if (e == GFL_NET_HANDLE_GetCurrentHandle()) {
        if (a != GFL_NET_GetHandleNetID((struct Link *)GFL_NET_HANDLE_GetCurrentHandle()))
            POKETRADE_PROC_ClearSideMon(base, 1);
    }
}
