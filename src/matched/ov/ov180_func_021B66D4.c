/*
 * function: func_021B66D4
 * address:  0x021B66D4
 * packet:   pkt_021B66D4
 * region:   ov180
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   G3D_UTIL_Delete  0x02047E54  arm
 *   G3D_SYSTEM_Exit  0x02046788  arm
 */
#include "../include/Obj24484.h"

struct Rec;
extern void G3D_UTIL_Delete(struct Rec *p);
extern void G3D_SYSTEM_Exit(void);

void func_021B66D4(int *p)
{
    G3D_UTIL_Delete((struct Rec *)(((struct Obj24484 *)p)->f10));
    G3D_SYSTEM_Exit();
}
