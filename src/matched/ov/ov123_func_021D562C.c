/*
 * function: GSYNC_MESSAGE_UpdateSystem
 * address:  0x021D562C
 * packet:   pkt_021D562C
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
#include "../include/Obj13971.h"

typedef unsigned int u32;

struct PrintSys;
struct Tcbl;
extern void TCBL_Main(struct Tcbl *p);
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);

void GSYNC_MESSAGE_UpdateSystem(char *p)
{
    TCBL_Main(((struct Obj13971 *)p)->f84);
    PRINTSYS_QUE_Main(((struct Obj13971 *)p)->f88);
}
