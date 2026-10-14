/*
 * function: GURU2_RECEIPT_UpdateQueues
 * address:  0x021DD1B4
 * packet:   pkt_021DD1B4
 * region:   ov137
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
#include "../include/Obj10615.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct PrintSys;
struct Tcbl;
extern u32 PRINTSYS_QUE_Main(struct PrintSys *ps);
extern void TCBL_Main(struct Tcbl *p);

void GURU2_RECEIPT_UpdateQueues(u8 *p)
{
    if (((struct Obj10615 *)p)->fEC)
        PRINTSYS_QUE_Main(((struct Obj10615 *)p)->fEC);
    TCBL_Main(((struct Obj10615 *)p)->fF4);
}
