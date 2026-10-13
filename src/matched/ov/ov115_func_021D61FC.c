/*
 * function: func_021D61FC
 * address: 0x021D61FC
 * packet: pkt_ov115_021D61FC
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_ClearExitFlag 0x0203CF04 arm
 *   GFL_NET_IRC_WIRELESS_Exit 0x0203D0D0 arm
 *   GFL_NET_STATE_ClearErrorMode 0x0203C968 arm
 *   GFL_NET_STATE_SetWifiError 0x0203CA04 arm
 *   GFL_NET_IsSessionNull 0x0203CDBC arm
 *   GFL_NET_Exit 0x0203CEAC arm
 *   func_021D6134 0x021D6134 thumb ov115
 *   func_021D6274 0x021D6274 thumb ov115
 *   func_021D625C 0x021D625C thumb ov115
 *   func_021D6328 0x021D6328 thumb ov115
 */
typedef unsigned int u32;
extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
extern void GFL_NET_ClearExitFlag(void);
extern void GFL_NET_IRC_WIRELESS_Exit(void);
extern void GFL_NET_STATE_ClearErrorMode(void);
extern void GFL_NET_STATE_SetWifiError(void);
extern int GFL_NET_IsSessionNull(void);
extern int GFL_NET_Exit(int a0);
extern void func_021D6134(void *a0, int a1, int a2);
extern void func_021D6274(unsigned char *p);
extern void func_021D625C(unsigned char *p);
typedef unsigned char  u8;
extern void func_021D6328(u8 *p);
void func_021D61FC(void *p) {
    if (func_0200FB24()) {
        GFL_NET_ClearExitFlag(); GFL_NET_IRC_WIRELESS_Exit(); GFL_NET_STATE_ClearErrorMode(); GFL_NET_STATE_SetWifiError(); func_0200FBA0();
    }
    if (GFL_NET_IsSessionNull()) {
        func_021D6134(p,(int)((void (*)(void))func_021D6274),0x1bf);
        return;
    }
    if (GFL_NET_Exit((int)func_021D6328)) func_021D6134(p,(int)((void (*)(void))func_021D625C),0x1c7);
}
