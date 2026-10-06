/*
 * function: func_021FBAD8
 * address:  0x021FBAD8
 * packet:   pkt_ov094_021FBAD8
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * EXACT*: the listing extent includes two bytes of trailing alignment padding.
 *
 * Script command: mode 5 calls func_02006210, any other mode is passed to
 * func_020061F8.
 *
 * symbols:
 *   func_0201134C 0x0201134C thumb
 *   func_02006210 0x02006210 thumb
 *   func_020061F8 0x020061F8 thumb
 */
#include "../include/Obj21673.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 func_0201134C(struct Cursor *p);
extern void func_02006210(void);
extern void func_020061F8(int i);

int func_021FBAD8(void *a, char *s)
{
    int r = func_0201134C(a);

    if (r == 5)
        func_02006210();
    else
        func_020061F8(r);
    return ((struct Obj21673 *)s)->f23C;
}
