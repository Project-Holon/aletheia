/*
 * function: INTRO_MSG_Delete
 * address: 0x021BF1A4
 * packet: pkt_ov204_021BF1A4
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   INTRO_MSG_DeleteTimeIcon 0x021BF580 thumb ov204
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   TCBL_Destroy 0x02031140 arm
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   WORDSET_Delete 0x0201ED04 thumb
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj01292.h"
struct U16Vec; struct Descriptor; struct S02031140;
typedef unsigned char  u8;
extern void INTRO_MSG_DeleteTimeIcon(u8 *p);
extern int APP_KEYCURSOR_Delete(int);
extern void STRBUF_Delete(struct U16Vec *);
extern unsigned int GF_FONT_Delete(void *ptr);
struct Rec3;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void TCBL_Destroy(struct S02031140 *);
struct PrintSys;
struct Rec;
struct WordSet;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int WORDSET_Delete(struct WordSet *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);
void INTRO_MSG_Delete(char *p)
{
    INTRO_MSG_DeleteTimeIcon((u8 *)p);
    APP_KEYCURSOR_Delete(((struct Obj01292 *)p)->f20);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01292 *)p)->f3C);
    STRBUF_Delete(*(struct U16Vec * *)&((struct Obj01292 *)p)->f40);
    GF_FONT_Delete(((struct Obj01292 *)p)->f10);
    if (((struct Obj01292 *)p)->f14 != 0)
        PRINTSYS_PrintStreamDelete((struct Rec3 *)(((struct Obj01292 *)p)->f14));
    BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj01292 *)p)->f1C);
    if (((struct Obj01292 *)p)->f38)
        BMP_WIN_Delete(*(struct Descriptor * *)&((struct Obj01292 *)p)->f38);
    TCBL_Destroy(*(struct S02031140 * *)&((struct Obj01292 *)p)->f18);
    PRINTSYS_QUE_Delete(((struct Obj01292 *)p)->f4);
    if (((struct Obj01292 *)p)->fC)
        MSGDATA_Delete(((struct Obj01292 *)p)->fC);
    WORDSET_Delete(((struct Obj01292 *)p)->f8);
    func_020307B0(p);
}
