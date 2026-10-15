/*
 * function: LOCAL_TVT_SYS_DeleteTextResources
 * address: 0x021B6824
 * packet: pkt_ov174_021B6824
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes 021B687A..021B687C.
 * symbols:
 *   APP_KEYCURSOR_Delete 0x02028604 thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Delete 0x02045808 arm
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   TCBL_Destroy 0x02031140 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 */
#include "../include/Obj00681.h"
typedef unsigned char u8;
extern int APP_KEYCURSOR_Delete(int a0);
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct U16Vec;
struct WordSet;
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void STRBUF_Delete(struct U16Vec *vec);
extern unsigned int WORDSET_DeleteStrbufED04(struct WordSet *p);
extern unsigned int MSGDATA_Delete(struct Rec *rec);
extern unsigned int BMP_WIN_Delete(struct Descriptor *d);
typedef unsigned int   u32;
extern u32 GF_FONT_Delete(void *ptr);
extern void TCBL_Destroy(struct S02031140 *p);
extern void GF_FONT_SetDefaultTextColor(void);
void LOCAL_TVT_SYS_DeleteTextResources(u8 *p)
{
    APP_KEYCURSOR_Delete((int)(((struct Obj00681 *)p)->f7C));
    PRINTSYS_QUE_Delete(((struct Obj00681 *)p)->f78);
    if(((struct Obj00681 *)p)->f64) PRINTSYS_PrintStreamDelete(((struct Obj00681 *)p)->f64);
    if(((struct Obj00681 *)p)->f70) STRBUF_Delete(((struct Obj00681 *)p)->f70);
    if(((struct Obj00681 *)p)->f74) WORDSET_DeleteStrbufED04(((struct Obj00681 *)p)->f74);
    MSGDATA_Delete(((struct Obj00681 *)p)->f6C);
    MSGDATA_Delete(((struct Obj00681 *)p)->f68);
    if(((struct Obj00681 *)p)->f5C) BMP_WIN_Delete(((struct Obj00681 *)p)->f5C);
    GF_FONT_Delete(((struct Obj00681 *)p)->f60);
    TCBL_Destroy(((struct Obj00681 *)p)->f58);
    GF_FONT_SetDefaultTextColor();
}
