/*
 * function: WIFICLUB_ChangeNetMode
 * address: 0x021BDE30
 * packet: pkt_ov099_021BDE30
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 98 bytes code followed by two zero alignment bytes.
 * symbols:
 *   GFL_NET_SetWaitMode 0x0203D644 arm
 *   WIFICLUB_StartNetSession 0x021BDD0C thumb ov099
 *   WIFICLUB_ShouldEnterWaitMode 0x021BDDB4 thumb ov099
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SetAcceptConnection 0x0203D1E8 arm
 */
extern void GFL_NET_SetWaitMode(int);
extern void WIFICLUB_StartNetSession(void *, int);
typedef unsigned int   u32;
extern int WIFICLUB_ShouldEnterWaitMode(int a, void *b);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void GFL_NET_SetAcceptConnection(u32 unused, void *arg);
void WIFICLUB_ChangeNetMode(void *p, int kind, int value)
{
    if (kind == 1) {
        GFL_NET_SetWaitMode(0);
        WIFICLUB_StartNetSession(p, 0);
    } else {
        if (WIFICLUB_ShouldEnterWaitMode(kind, (void *)value)) GFL_NET_SetWaitMode(1);
    }
    switch (kind) {
    case 2:
    case 5:
        GFL_NET_SetAcceptConnection((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
        return;
    case 0:
    case 1:
    case 3:
    case 4:
    case 6:
    default:
        GFL_NET_SetAcceptConnection((int)GFL_NET_HANDLE_GetCurrentHandle(), (void *)1);
        break;
    }
}
