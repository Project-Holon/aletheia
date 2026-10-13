/*
 * function: SCRIPT_SYS_ForceExitNet
 * address:  0x02158DBC
 * packet:   pkt_02158DBC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_NET_GetRunState  0x0203CD98  arm
 *   GFL_NET_ClearExitFlag  0x0203CF04  arm
 *   GFL_NET_Exit  0x0203CEAC  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   GFL_NET_Main  0x0203CF5C  arm
 *   GFL_NET_IsSessionNull  0x0203CDBC  arm
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int GFL_NET_GetRunState();
extern int GFL_NET_ClearExitFlag();
extern int GFL_NET_Exit(int a0);
extern int GFL_NET_IRC_WIRELESS_Exit();
extern u32 GFL_NET_Main(void);
extern int GFL_NET_IsSessionNull();
extern int GFL_USE_PollPowerExit();

int SCRIPT_SYS_ForceExitNet(void)
{
    int a0;

    a0 = GFL_NET_GetRunState();
loc_02158DC2:
    if (a0 == 0) goto loc_02158DE0;
loc_02158DC6:
    a0 = GFL_NET_ClearExitFlag();
loc_02158DCA:
a0 = 0;
    a0 = GFL_NET_Exit(a0);
loc_02158DD0:
    a0 = GFL_NET_IRC_WIRELESS_Exit();
loc_02158DD4:
    a0 = GFL_NET_Main();
loc_02158DD8:
    a0 = GFL_NET_IsSessionNull(a0);
loc_02158DDC:
    if (a0 == 0) goto loc_02158DD4;
loc_02158DE0:
    a0 = GFL_USE_PollPowerExit();
loc_02158DE4:
    goto loc_02158DE0;}
