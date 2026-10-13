/*
 * function: INTRUDE_COMM_SendShutdownRequest
 * address: 0x021736EC
 * packet: pkt_ov011_021736EC
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   INTRUDE_COMM_IsLinked 0x021736D8 thumb ov011
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   INTRUDE_COMM_RecvShutdownRequest 0x021736E0 thumb ov011
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 * The fifth argument to 021736E0 is visibly written to the outgoing stack slot.
 */
extern int INTRUDE_COMM_IsLinked(void);
typedef unsigned short u16;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void INTRUDE_COMM_RecvShutdownRequest(int, int, int, char *, unsigned int);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
int INTRUDE_COMM_SendShutdownRequest(char *p)
{
    unsigned int n;
    if (INTRUDE_COMM_IsLinked() == 0) {
        n = GFL_NET_SYSTEM_GetCurrentAid();
        INTRUDE_COMM_RecvShutdownRequest(n, 0, 0, p, (unsigned int)GFL_NET_HANDLE_GetCurrentHandle());
        return 1;
    }
    return GFL_NET_SendToHandle((struct Entry *)((unsigned int)GFL_NET_HANDLE_GetCurrentHandle()), 0x200, 0, 0);
}
