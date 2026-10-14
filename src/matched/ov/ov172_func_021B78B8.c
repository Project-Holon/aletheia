/*
 * function: CTVT_CAMVIEW_StepWindow
 * address: 0x021B78B8
 * packet: pkt_ov172_021B78B8
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CTVT_CAMVIEW_StepValue 0x021B792C thumb ov172
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 */
#include "../include/Obj06556.h"
typedef unsigned short u16;
extern int CTVT_CAMVIEW_StepValue(void *, u16 *, u16 *);
extern void GFL_USE_PlaySeDefaultVolume(unsigned int);
int CTVT_CAMVIEW_StepWindow(void *p, char *q)
{
    int result, zero;
    if (((struct Obj06556 *)q)->f0 == 1) {
        zero = 0;
        result = 0;
        result |= CTVT_CAMVIEW_StepValue(p, (u16 *)(q + 12), (u16 *)(q + 20));
        result |= CTVT_CAMVIEW_StepValue(p, (u16 *)(q + 14), (u16 *)(q + 22));
        result |= CTVT_CAMVIEW_StepValue(p, (u16 *)(q + 16), (u16 *)(q + 24));
        result |= CTVT_CAMVIEW_StepValue(p, (u16 *)(q + 18), (u16 *)(q + 26));
        if (result == 0) ((struct Obj06556 *)q)->f0 = zero;
        if (((struct Obj06556 *)q)->f8 == 1) {
            ((struct Obj06556 *)q)->f8 = 0;
            GFL_USE_PlaySeDefaultVolume(0x66e);
        }
        ((struct Obj06556 *)q)->f4 = 0;
        return 1;
    }
    return 0;
}
