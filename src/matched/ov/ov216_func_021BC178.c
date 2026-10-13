/*
 * function: func_021BC178
 * address: 0x021BC178
 * packet: pkt_ov216_021BC178
 * region: ov216
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   STRBUF_Delete 0x02045808 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   func_0201ED04 0x0201ED04 thumb
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
#include "../include/Obj01437.h"
struct U16Vec; struct Rec; struct WordSet; struct PrintSys; struct S02031140;
extern void STRBUF_Delete(struct U16Vec *);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int func_0201ED04(struct WordSet *p);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void PRINTSYS_QUE_Clear(struct PrintSys *);
extern void PRINTSYS_QUE_Delete(struct PrintSys *);
extern void GF_FONT_SetDefaultTextColor(void);
extern void TCBL_Destroy(struct S02031140 *);
extern void ARC_TOOL_DeleteHandle(void *);
void func_021BC178(char *p)
{
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01437 *)p)->f144);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01437 *)p)->f140);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01437 *)p)->f13C);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj01437 *)p)->f134);
    MSGDATA_Delete(*(struct Rec * *)&((struct Obj01437 *)p)->f130);
    func_0201ED04(*(struct WordSet * *)&((struct Obj01437 *)p)->f138);
    GF_FONT_Delete(((struct Obj01437 *)p)->f128);
    PRINTSYS_QUE_Clear(*(struct PrintSys * *)&((struct Obj01437 *)p)->f12C);
    PRINTSYS_QUE_Delete(*(struct PrintSys * *)&((struct Obj01437 *)p)->f12C);
    GF_FONT_SetDefaultTextColor();
    TCBL_Destroy(*(struct S02031140 * *)&((struct Obj01437 *)p)->f18);
    ARC_TOOL_DeleteHandle(((struct Obj01437 *)p)->f54);
}
