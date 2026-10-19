/*
 * function: PDWACC_MESSAGE_ExitSystem
 * address: 0x021D941C
 * packet: pkt_ov123_021D941C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: inline the first high-half argument; a separate first assignment colours the word r1.
 * symbols:
 *   PDWACC_MESSAGE_DeleteButtonManager 0x021D92B8 thumb ov123
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BG_SYS_FreeTileRun 0x0203FB44 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   TIME_ICON_Delete  0x0202F038  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   WORDSET_Delete  0x0201ED04  thumb  arm9
 *   GF_FONT_SetDefaultTextColor  0x0201DD68  thumb  arm9
 */
#include "../include/Obj00534.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void PDWACC_MESSAGE_DeleteButtonManager(u8 *);
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BG_SYS_FreeTileRun(u32 layer, u32 offset, u32 size);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 WORDSET_Delete(struct WordSet *p);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void TIME_ICON_Delete(u8 *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void BMP_WIN_Exit(void);
extern u32 func_020307B0(void *p);
void PDWACC_MESSAGE_ExitSystem(u8 *p)
{
    u32 a;
    int i;
    BG_SYS_FreeTileRun(1,(u16)(((struct Obj00534 *)p)->f0),(u16)(((struct Obj00534 *)p)->f0>>16));
    a=((struct Obj00534 *)p)->f8>>16;
    BG_SYS_FreeTileRun(5,(u16)(((struct Obj00534 *)p)->f8),(u16)a);
    a=((struct Obj00534 *)p)->f4>>16;
    BG_SYS_FreeTileRun(6,(u16)(((struct Obj00534 *)p)->f4),(u16)a);
    PDWACC_MESSAGE_DeleteButtonManager(p);
    GF_FONT_SetDefaultTextColor();
    MSGDATA_Delete(((struct Obj00534 *)p)->f20);
    GF_FONT_Delete(((struct Obj00534 *)p)->f28);
    STRBUF_Delete(((struct Obj00534 *)p)->f2C);
    STRBUF_Delete(((struct Obj00534 *)p)->f30);
    WORDSET_Delete(((struct Obj00534 *)p)->f24);
    APP_TASKMENU_RES_Delete(((struct Obj00534 *)p)->fAC);
    PRINTSYS_QUE_Clear(((struct Obj00534 *)p)->f8C);
    PRINTSYS_QUE_Delete(((struct Obj00534 *)p)->f8C);
    if (((struct Obj00534 *)p)->f80) PRINTSYS_PrintStreamDelete(((struct Obj00534 *)p)->f80);
    if (((struct Obj00534 *)p)->f90) {
        TIME_ICON_Delete(((struct Obj00534 *)p)->f90);
        ((struct Obj00534 *)p)->f90=0;
    }
    if (((struct Obj00534 *)p)->f40) BMP_WIN_Delete(((struct Obj00534 *)p)->f40);
    if (((struct Obj00534 *)p)->f44) BMP_WIN_Delete(((struct Obj00534 *)p)->f44);
    if (((struct Obj00534 *)p)->f48) BMP_WIN_Delete(((struct Obj00534 *)p)->f48);
    if (((struct Obj00534 *)p)->f4C) BMP_WIN_Delete(((struct Obj00534 *)p)->f4C);
    for(i=0;i<12;i++) if (*(void **)(p+i*4+0x50)) BMP_WIN_Delete(*(void **)(p+i*4+0x50));
    TCBL_Destroy(((struct Obj00534 *)p)->f88);
    BMP_WIN_Exit();
    func_020307B0(p);
}
