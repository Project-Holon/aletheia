/*
 * function: WIH_StateInReset
 * address: 0x02178CDC
 * packet: pkt_ov014_02178CDC
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   WIH_SetError 0x0217814C thumb ov014
 *   WM_Reset 0x0208F400 arm
 *   WIH_StateOutReset 0x02178D00 thumb ov014
 */
typedef unsigned char u8;
extern void WIH_ChangeSysState(int);
extern void WIH_SetError(int);
extern void WIH_StateOutReset(u8 *);
extern int WM_Reset(void (*)(u8 *));
int WIH_StateInReset(void) {
 int r;
 WIH_ChangeSysState(3);
 r = WM_Reset(WIH_StateOutReset);
 if (r != 2) { WIH_SetError(r); return 0; }
 return 1;
}
