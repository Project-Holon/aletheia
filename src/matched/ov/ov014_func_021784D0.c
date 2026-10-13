/*
 * function: WIH_StateOutEndParentMP
 * address: 0x021784D0
 * packet: pkt_ov014_021784D0
 * region: ov014
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_SetError 0x0217814C thumb ov014
 *   DWCi_MOV_WH_StateInEndKeyShare 0x0217945C thumb ov014
 *   func_021784F0 0x021784F0 thumb ov014
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern void WIH_SetError(int);
extern void DWCi_MOV_WH_StateInEndKeyShare(void);
extern int func_021784F0(void);
void WIH_StateOutEndParentMP(void *arg)
{
    int result = ((u16 *)arg)[1];
    if (result != 0) {
        WIH_SetError(result);
        DWCi_MOV_WH_StateInEndKeyShare();
        return;
    }
    if (func_021784F0() == 0)
        DWCi_MOV_WH_StateInEndKeyShare();
}
