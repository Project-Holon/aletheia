/*
 * function: UNION_SUBDISP_DeleteSystems
 * address: 0x021F022C
 * packet: pkt_ov031_021F022C
 * region: ov031
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   CLACT_DeleteUnit 0x0204B1CC arm
 */
#include "../include/Obj06132.h"
struct Bank;
struct PrintSys;
struct Rec;
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 CLACT_DeleteUnit(struct Bank *bank);
void UNION_SUBDISP_DeleteSystems(char *p)
{
    MSGDATA_Delete(((struct Obj06132 *)p)->f48);
    GF_FONT_Delete(((struct Obj06132 *)p)->f44);
    PRINTSYS_QUE_Clear(((struct Obj06132 *)p)->f40);
    PRINTSYS_QUE_Delete(((struct Obj06132 *)p)->f40);
    CLACT_DeleteUnit(((struct Obj06132 *)p)->f14);
}
