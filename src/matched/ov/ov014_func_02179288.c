/*
 * function: WIH_ParentConnect
 * address:  0x02179288
 * packet:   pkt_ov014_02179288
 * region:   ov014
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   gWihWork     0x021797A8  data   ov014  a4
 *   WIH_ChangeSysState  0x02178138  thumb  ov014
 *   WIH_StateInSetParentParam  0x02178168  thumb  ov014
 *   WM_GetDispersionBeaconPeriod  0x0208EF30  arm
 *   GFL_NET_GetParentSendSize  0x0203D6CC  arm
 *   GFL_NET_GetChildSendSize  0x0203D6BC  arm
 *   GFL_NET_GetMaxConnectNum  0x0203D680  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int BOOL;

extern u8 *gWihWork;

extern void WIH_ChangeSysState(int state);
extern BOOL WIH_StateInSetParentParam(void);
extern u16 WM_GetDispersionBeaconPeriod(void);
typedef unsigned int   u32;
extern u32 GFL_NET_GetParentSendSize(void);
extern u32 GFL_NET_GetChildSendSize(void);
extern u32 GFL_NET_GetMaxConnectNum(void);

BOOL WIH_ParentConnect(int mode, u16 a, int b, u16 c)
{
    *(u16 *)(gWihWork + 0x1EBA) = 0;
    *(int *)(gWihWork + 0x1E74) = mode;
    WIH_ChangeSysState(3);
    *(u16 *)(gWihWork + 0xC) = a;
    *(u16 *)(gWihWork + 0x32) = b;
    *(u16 *)(gWihWork + 0x18) = WM_GetDispersionBeaconPeriod();
    if (GFL_NET_GetParentSendSize() != 0) {
        *(u16 *)(gWihWork + 0x34) = GFL_NET_GetParentSendSize();
    } else {
        *(u16 *)(gWihWork + 0x34) = GFL_NET_GetChildSendSize() * GFL_NET_GetMaxConnectNum() + 4;
    }
    *(u16 *)(gWihWork + 0x36) = GFL_NET_GetChildSendSize();
    *(u16 *)(gWihWork + 0x10) = c;
    *(u16 *)(gWihWork + 0x16) = 0;
    *(u16 *)(gWihWork + 0x12) = 0;
    *(u16 *)(gWihWork + 0xE) = 1;
    *(u16 *)(gWihWork + 0x14) = (mode == 2);
    if (mode == 0 || mode == 2 || mode == 4)
        return WIH_StateInSetParentParam();
    return 0;
}
