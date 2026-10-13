/*
 * function: WIH_StateOutSetParentParam
 * address: 0x02178198
 * packet: pkt_ov014_02178198
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   WIH_SetError 0x0217814C thumb ov014
 *   WIH_StateInStartParent 0x021781BC thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void WIH_ChangeSysState(int);
extern void WIH_SetError(int);
extern int WIH_StateInStartParent(void);
void WIH_StateOutSetParentParam(void *arg)
{
    int result = ((u16 *)arg)[1];
    if (result != 0) {
        WIH_SetError(result);
        WIH_ChangeSysState(9);
        return;
    }
    if (WIH_StateInStartParent() == 0)
        WIH_ChangeSysState(9);
}
