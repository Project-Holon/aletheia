/*
 * function: func_021D9404
 * address:  0x021D9404
 * packet:   pkt_021D9404
 * region:   ov123
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   TCBL_Main  0x020310C4  arm
 *   PRINTSYS_QUE_Main  0x0201C4E4  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj13998.h"

typedef unsigned int u32;

struct PrintSys;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

void func_021D9404(char *p)
{
    TCBL_Main(((struct Obj13998 *)p)->f88);
    PRINTSYS_QUE_Main(((struct Obj13998 *)p)->f8C);
}
