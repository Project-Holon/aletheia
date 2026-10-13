/*
 * function: WIH_StateInEndChildMP
 * address: 0x02178C50
 * packet: pkt_ov014_02178C50
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_StateOutEndChildMP 0x02178C74 thumb ov014
 *   WM_EndMP 0x0208FDEC arm
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   WIH_SetError 0x0217814C thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void WIH_StateOutEndChildMP(void *);
extern int WM_EndMP(void (*)(void *));
extern void WIH_ChangeSysState(int);
extern void WIH_SetError(int);
int WIH_StateInEndChildMP(void)
{
    int result;
    WIH_ChangeSysState(3);
    result = WM_EndMP(WIH_StateOutEndChildMP);
    if (result != 2) {
        WIH_SetError(result);
        return 0;
    }
    return 1;
}
