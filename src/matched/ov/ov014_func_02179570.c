/*
 * function: WIH_End
 * address: 0x02179570
 * packet: pkt_ov014_02179570
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   gWihWork 0x021797A8 data ov014 a4
 *   WIH_ChangeSysState 0x02178138 thumb ov014
 *   WM_End 0x0208F43C arm
 *   WIH_StateOutEnd 0x02178DE0 thumb ov014
 */
typedef unsigned char u8;
extern u8 *gWihWork;
extern void WIH_ChangeSysState(int);
extern int WM_End(void (*)(u8 *));
extern void WIH_StateOutEnd(u8 *);
int WIH_End(void (*cb)(int))
{
    *(void (**)(int))(gWihWork + 0x1E64) = cb;
    WIH_ChangeSysState(3);
    if (WM_End(WIH_StateOutEnd) != 2) {
        WIH_ChangeSysState(9);
        return 0;
    }
    return 1;
}
