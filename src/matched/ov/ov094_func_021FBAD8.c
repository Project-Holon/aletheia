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
 * Script command: mode 5 calls GFL_USE_StopAllSe, any other mode is passed to
 * func_020061F8.
 *
 * symbols:
 *   VM_GetU32 0x0201134C thumb
 *   GFL_USE_StopAllSe 0x02006210 thumb
 *   func_020061F8 0x020061F8 thumb
 */
#include "../include/Obj21673.h"
typedef unsigned int   u32;
struct Cursor;
extern u32 VM_GetU32(struct Cursor *p);
extern void GFL_USE_StopAllSe(void);
extern void func_020061F8(int i);

int func_021FBAD8(void *a, char *s)
{
    int r = VM_GetU32(a);

    if (r == 5)
        GFL_USE_StopAllSe();
    else
        func_020061F8(r);
    return ((struct Obj21673 *)s)->f23C;
}
