/*
 * function: WIH_StateInSetParentParam
 * address: 0x02178168
 * packet: pkt_ov014_02178168
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 *   WIH_StateOutSetParentParam 0x02178198 thumb ov014
 *   WM_SetParentParameter 0x0208F480 arm
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   WIH_SetError 0x0217814C thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *gWihWork;
extern void WIH_StateOutSetParentParam(void *);
extern int WM_SetParentParameter(void (*)(void *), void *);
extern void WIH_ChangeSysState(int);
extern void WIH_SetError(int);
int WIH_StateInSetParentParam(void)
{
    int result;
    WIH_ChangeSysState(3);
    result = WM_SetParentParameter(WIH_StateOutSetParentParam, gWihWork);
    if (result != 2) {
        WIH_SetError(result);
        WIH_ChangeSysState(9);
        return 0;
    }
    return 1;
}
