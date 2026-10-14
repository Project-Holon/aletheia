/*
 * function: MAILVIEW_DeletePmsDraw
 * address:  0x021C4DA8
 * packet:   pkt_ov136_021C4DA8
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MAILVIEW_DeletePmsDraw 0x021C4DA8 thumb
 *   PMS_DRAW_Delete 0x0202DC08 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj01751.h"
typedef unsigned char u8;
struct Bank;
struct Obj;
struct PrintSys;
extern void PMS_DRAW_Delete(struct Obj *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
typedef unsigned int   u32;
extern u32 CLACT_DeleteUnit(struct Bank *bank);
void MAILVIEW_DeletePmsDraw(u8 *p)
{
    PMS_DRAW_Delete(((struct Obj01751 *)p)->f148);
    PRINTSYS_QUE_Delete(((struct Obj01751 *)p)->f158);
    ((struct Obj01751 *)p)->f158 = 0;
    CLACT_DeleteUnit(((struct Obj01751 *)p)->f154);
}
