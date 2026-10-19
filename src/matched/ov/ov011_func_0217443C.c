/*
 * function: INTRUDE_COMM_RecvBusyEnd
 * address: 0x0217443C
 * packet: pkt_ov011_0217443C
 * region: ov011
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SetAcceptConnection 0x0203D1E8 arm
 *   NET_WHPIPE_SetBeaconStatus 0x021780FC thumb ov014
 */
typedef unsigned int u32;
struct Entry;
struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
void GFL_NET_SetAcceptConnection(u32 unused, void *arg);
typedef unsigned char  u8;
void NET_WHPIPE_SetBeaconStatus(u8 value);
void INTRUDE_COMM_RecvBusyEnd(int a, int b, void *c, signed char *p)
{
    p[0x93d]--;
    if (p[0x93d] == 0 && p[0x93c] == 0) {
        GFL_NET_SetAcceptConnection((u32)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
        NET_WHPIPE_SetBeaconStatus(0);
    }
}
