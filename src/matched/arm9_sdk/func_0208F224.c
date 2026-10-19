/*
 * function: WM_Enable
 * address:  0x0208F224
 * packet:   pkt_0208F224
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_Enable (libwm.TWL.HYB.a(wm_standard.o))
 *
 * symbols:
 *   WMi_EnableEx  0x0208F234  arm
 */

extern int WMi_EnableEx(void *callback, unsigned long miscFlags);

int WM_Enable(void *callback)
{
    return WMi_EnableEx(callback, 0);
}
