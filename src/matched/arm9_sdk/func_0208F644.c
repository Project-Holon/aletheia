/*
 * function: WM_StartParent
 * address:  0x0208F644
 * packet:   pkt_0208F644
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WM_StartParent (libwm.TWL.HYB.a(wm_standard.o))
 *
 * symbols:
 *   WMi_StartParentEx 0x0208F5C8 arm
 */

extern int WMi_StartParentEx(void *callback, int powerSave);

int WM_StartParent(void *callback)
{
    return WMi_StartParentEx(callback, 1);
}
