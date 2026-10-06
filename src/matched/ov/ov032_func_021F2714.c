/*
 * function: func_021F2714
 * address:  0x021F2714
 * packet:   pkt_ov032_021F2714
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     func_021F05E8 takes three arguments (its own matched file); the
 *           cleared zero is shared with its third argument, which is what
 *           puts the zero in r2 for the three stores.
 *
 * symbols:
 *   func_021F2714 0x021F2714 thumb
 *   func_021F0050 0x021F0050 thumb ov032
 *   func_021F05E8 0x021F05E8 thumb ov032
 *   func_021F067C 0x021F067C thumb ov032
 *   func_021F029C 0x021F029C thumb ov032
 *   func_021F028C 0x021F028C thumb ov032
 */
#include "../include/Obj00007.h"

typedef unsigned int   u32;
typedef unsigned char  u8;
extern int func_021F0050(unsigned char *p);
extern void func_021F05E8(u8 *p, int a, u32 b);
extern void func_021F067C(char *);
extern void func_021F029C(char *, int);
extern void func_021F028C(unsigned char *p);

int func_021F2714(char *p)
{
    int r;

    if (((struct Obj00007 *)p)->f82 == 0) {
        r = func_021F0050((unsigned char *)p);
        if (r != ((struct Obj00007 *)p)->f84 || r == -1) {
            ((struct Obj00007 *)p)->f82 = 1;
        }
        ((struct Obj00007 *)p)->f88 = ((struct Obj00007 *)p)->f88 + 1;
    }
    if (((struct Obj00007 *)p)->f82 != 0) {
        if (((struct Obj00007 *)p)->fA8 > 0) {
            return 3;
        }
        ((struct Obj00007 *)p)->f82 = 0;
        ((struct Obj00007 *)p)->f88 = 0;
        ((struct Obj00007 *)p)->f81 = 0;
        if (((struct Obj00007 *)p)->f83 == 0) {
            func_021F05E8((u8 *)p, 4, 0);
        }
        func_021F067C(p);
        func_021F029C(p, 0);
        return ((struct Obj00007 *)p)->f83;
    }
    if (((struct Obj00007 *)p)->fA8 == 0) {
        func_021F028C((unsigned char *)p);
    }
    return 3;
}
