/*
 * function: ov021_func_021A4B98
 * address:  0x021A4B98
 * packet:   pkt_ov021_021A4B98
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_021A4B54  0x021A4B54  thumb  ov021
 *   func_021A5264  0x021A5264  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07498.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern int func_0216D3CC(int a0);
extern int func_021A4B54(u8 *, void *, u8 *);
extern int func_021A5264(u8 *a, void *b, u32 c, int *d);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);

int ov021_func_021A4B98(u8 *a, void *b, u8 *c)
{
    int sp;
    u32 r;
    if (func_0216D3CC((int)b) == 0) {
        return 0;
    }
    if (((struct Obj07498 *)c)->f8 == 9) {
        return func_021A4B54(a, b, c);
    }
    r = func_021A5264(a, b, ((struct Obj07498 *)c)->f8, &sp);
    if (((struct Obj07498 *)c)->f10 == 1 && r != 0 && !(r & 0x10)) {
        r = 0;
    }
    if (sp != -1) {
        u32 t;
        func_021AB0F0(sp);
        t = func_021AB0F8(sp);
        if (r == 0) {
            if (t & 2) {
                return 2;
            }
            if (((struct Obj07498 *)c)->f10 == 1) {
                return 2;
            }
        }
    }
    return 4;
}
