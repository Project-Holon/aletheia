/*
 * function: UNION_APP_OpenLimited
 * address: 0x02184148
 * packet: pkt_ov022_02184148
 * region: ov022
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_GetRunState 0x0203CD98 arm
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SetAcceptConnection 0x0203D1E8 arm
 */
extern int GFL_NET_GetRunState(void);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern void GFL_NET_SetAcceptConnection(u32 unused, void *arg);
void UNION_APP_OpenLimited(unsigned char *p, int a)
{
    if (GFL_NET_GetRunState()) {
        GFL_NET_SetAcceptConnection((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
        p[9] = 2;
        p[11] = a;
        p[10] = 0;
    }
}
