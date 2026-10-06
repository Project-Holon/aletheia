/*
 * function: func_021F2674
 * address:  0x021F2674
 * packet:   pkt_ov032_021F2674
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021F2674 0x021F2674 thumb
 *   func_021F00C8 0x021F00C8 thumb ov032
 *   func_021F0078 0x021F0078 thumb ov032
 *   func_021EFF7C 0x021EFF7C thumb ov032
 *   func_021F0114 0x021F0114 thumb ov032
 *   func_021F0140 0x021F0140 thumb ov032
 */
#include "../include/Obj00188.h"

extern int func_021F00C8(char *);
extern int func_021F0078(char *);
typedef unsigned char  u8;
extern int func_021EFF7C(u8 *p);
extern int func_021F0114(u8 *p);
extern int func_021F0140(u8 *p);

int func_021F2674(char *p)
{
    int r;

    if (func_021F00C8(p)) {
        ((struct Obj00188 *)p)->f74 = 90;
        return 2;
    }
    if (func_021F0078(p)) {
        return 0;
    }
    r = func_021EFF7C((u8 *)p);
    if (r == 0) {
        if (((struct Obj00188 *)p)->f74 != 0) {
            ((struct Obj00188 *)p)->f74 = ((struct Obj00188 *)p)->f74 - 1;
            return 0;
        }
        if (func_021F0114((u8 *)p) == 1) {
            ((struct Obj00188 *)p)->f74 = 90;
            return 2;
        }
        if (func_021F0140((u8 *)p) == 0) {
            return 0;
        }
        ((struct Obj00188 *)p)->f74 = 90;
        return 1;
    }
    return r;
}
