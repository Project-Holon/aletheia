/*
 * function: POKELIST_DeleteFonts
 * address: 0x021B7268
 * packet: pkt_ov091_021B7268
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 */
#include "../include/Obj06209.h"
struct PrintSys;
struct Rec;
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
void POKELIST_DeleteFonts(unsigned p) { PRINTSYS_QUE_Clear((struct PrintSys *)(((struct Obj06209 *)p)->f140)); PRINTSYS_QUE_Delete((struct PrintSys *)(((struct Obj06209 *)p)->f140)); MSGDATA_Delete((struct Rec *)(((struct Obj06209 *)p)->f134)); GF_FONT_Delete(((struct Obj06209 *)p)->f13C); GF_FONT_Delete(((struct Obj06209 *)p)->f138); }
