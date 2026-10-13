/*
 * function: WIH_StateInEndChild
 * address: 0x02178C98
 * packet: pkt_ov014_02178C98
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   WIH_SetError 0x0217814C thumb ov014
 *   WM_Disconnect 0x0208F938 arm
 *   func_02178CC4 0x02178CC4 thumb ov014
 *   DWCi_MOV_WH_StateInEndKeyShare 0x0217945C thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void WIH_ChangeSysState(int);
extern void WIH_SetError(int);
extern void func_02178CC4(u8 *);
extern void DWCi_MOV_WH_StateInEndKeyShare(void);
extern int WM_Disconnect(void (*)(u8 *), u16);
int WIH_StateInEndChild(void) {
 int r;
 int result = 0;
 WIH_ChangeSysState(3);
 r = WM_Disconnect(func_02178CC4, 0);
 if (r != 2) { WIH_SetError(r); DWCi_MOV_WH_StateInEndKeyShare(); return result; }
 return 1;
}
