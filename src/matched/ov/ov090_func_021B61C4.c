/*
 * function: PLIST_COMM_OnStatusReceived
 * address: 0x021B61C4
 * packet: pkt_ov090_021B61C4
 * region: ov090
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 */
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
void PLIST_COMM_OnStatusReceived(int a, int b, unsigned char *c, unsigned char *d) {
    GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()));
    if(c[2]==0) d[148]++;
}
