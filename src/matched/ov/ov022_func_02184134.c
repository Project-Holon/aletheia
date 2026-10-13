/*
 * function: UNION_APP_Open
 * address: 0x02184134
 * packet: pkt_ov022_02184134
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Original r0 return from 020399A8 flows into unused parameter 0 of
 * 0203D1E8; its r1 argument is literal payload 1. No implicit arguments.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_NotifyUserEvent 0x0203D1E8 arm
 */
typedef unsigned char u8;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_NotifyUserEvent(u32, void *);
void UNION_APP_Open(u8 *p)
{
    GFL_NET_NotifyUserEvent((u32)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
    p[9] = 0;
}
