/*
 * function: SAVE_SCREEN_Delete
 * address: 0x021B9928
 * packet: pkt_ov205_021B9928
 * region: ov205
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   TCBL_DeleteAllTasks 0x0203115C arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BG_SYS_FreeLayerBuf 0x020403F4 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   SAVE_SCREEN_DeleteBackground 0x021B99D8 thumb ov205
 */
#include "../include/Obj03359.h"
struct Descriptor;
struct Rec;
struct S02031140;
struct Tcbl;
struct U16Vec;
struct WordSet;
extern void TCBL_DeleteAllTasks(struct Tcbl *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void BMP_MENUWORK_DrawWindowBorder(void *,unsigned);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern void BG_SYS_FreeLayerBuf(unsigned);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void SAVE_SCREEN_DeleteBackground(void);
void SAVE_SCREEN_Delete(char *p)
{
    TCBL_DeleteAllTasks(((struct Obj03359 *)p)->f24);
    TCBL_Destroy(((struct Obj03359 *)p)->f24);
    ((struct Obj03359 *)p)->f24=0;
    BMP_MENUWORK_DrawWindowBorder(((struct Obj03359 *)p)->f1C,0);
    BMP_WIN_Delete(((struct Obj03359 *)p)->f1C);
    STRBUF_Delete(((struct Obj03359 *)p)->fC);
    WORDSET_DeleteStrbufED04(((struct Obj03359 *)p)->f18);
    MSGDATA_Delete(((struct Obj03359 *)p)->f14);
    BG_SYS_FreeLayerBuf(0);
    GF_FONT_Delete(((struct Obj03359 *)p)->f10);
    SAVE_SCREEN_DeleteBackground();
}
