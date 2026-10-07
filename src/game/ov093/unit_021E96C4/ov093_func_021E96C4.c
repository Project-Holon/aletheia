/*
 * function: func_021E96C4
 * address:  0x021E96C4
 * packet:   pkt_ov093_021E96C4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021E9708  0x021E9708  thumb  ov093
 *   func_021E9718  0x021E9718  thumb  ov093
 */
#include "../../../matched/include/Obj07839.h"
extern void func_021E9708(void *a, int b, int c);
extern int func_021E9718(void *a);

int func_021E96C4(char *p, int *st)
{
    switch (*st) {
    case 0:
        func_021E9708(((struct Obj07839 *)p)->f180, ((struct Obj07839 *)p)->fBC, ((struct Obj07839 *)p)->fB8);
        (*st)++;
        break;
    case 1:
        if (func_021E9718(((struct Obj07839 *)p)->f180))
            return 1;
        break;
    }
    return 0;
}
