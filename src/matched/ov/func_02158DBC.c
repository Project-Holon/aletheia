/*
 * function: func_02158DBC
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
 *   func_0203CD98  0x0203CD98  arm
 *   GFL_NET_ClearExitFlag  0x0203CF04  arm
 *   func_0203CEAC  0x0203CEAC  arm
 *   GFL_NET_IRC_WIRELESS_Exit  0x0203D0D0  arm
 *   GFL_NET_Main  0x0203CF5C  arm
 *   func_0203CDBC  0x0203CDBC  arm
 *   GFL_USE_PollPowerExit  0x020053EC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0203CD98();
extern int GFL_NET_ClearExitFlag();
extern int func_0203CEAC(int a0);
extern int GFL_NET_IRC_WIRELESS_Exit();
extern u32 GFL_NET_Main(void);
extern int func_0203CDBC();
extern int GFL_USE_PollPowerExit();

int func_02158DBC(void)
{
    int a0;

    a0 = func_0203CD98();
loc_02158DC2:
    if (a0 == 0) goto loc_02158DE0;
loc_02158DC6:
    a0 = GFL_NET_ClearExitFlag();
loc_02158DCA:
a0 = 0;
    a0 = func_0203CEAC(a0);
loc_02158DD0:
    a0 = GFL_NET_IRC_WIRELESS_Exit();
loc_02158DD4:
    a0 = GFL_NET_Main();
loc_02158DD8:
    a0 = func_0203CDBC(a0);
loc_02158DDC:
    if (a0 == 0) goto loc_02158DD4;
loc_02158DE0:
    a0 = GFL_USE_PollPowerExit();
loc_02158DE4:
    goto loc_02158DE0;}
