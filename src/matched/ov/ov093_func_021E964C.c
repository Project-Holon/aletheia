/*
 * function: BTLV_CORE_StepActionMenu
 * address:  0x021E964C
 * packet:   pkt_ov093_021E964C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021D3D90  0x021D3D90  thumb  ov093
 *   func_021E96A4  0x021E96A4  thumb  ov093
 *   func_021E96B4  0x021E96B4  thumb  ov093
 */
#include "../include/Obj03707.h"
typedef unsigned char u8;
extern u8 func_021D3D90(u8 *p);
extern void func_021E96A4(void *a, int b, int c, int d, int e);
extern int func_021E96B4(void *a);

int BTLV_CORE_StepActionMenu(char *p, int *st)
{
    switch (*st) {
    case 0:
        func_021E96A4(((struct Obj03707 *)p)->f180, ((struct Obj03707 *)p)->fBC, ((struct Obj03707 *)p)->f175,
                      func_021D3D90(((struct Obj03707 *)p)->f4), ((struct Obj03707 *)p)->fB8);
        (*st)++;
    case 1:
        ((struct Obj03707 *)p)->fC4 = func_021E96B4(((struct Obj03707 *)p)->f180);
        if (((struct Obj03707 *)p)->fC4)
            return 1;
    }
    return 0;
}
