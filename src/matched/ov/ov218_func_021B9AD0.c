/*
 * function: func_021B9AD0
 * address:  0x021B9AD0
 * packet:   pkt_021B9AD0
 * region:   ov218
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *   TCBL_Main  0x020310C4  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14771.h"

typedef unsigned int   u32;
struct PrintSys;
struct Tcbl;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Main(struct Tcbl *p);

void func_021B9AD0(char *p)
{
    PRINTSYS_QUE_Main((struct PrintSys *)(((struct Obj14771 *)p)->f10));
    TCBL_Main((struct Tcbl *)(((struct Obj14771 *)p)->f4));
}
