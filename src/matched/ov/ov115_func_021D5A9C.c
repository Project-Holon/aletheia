/*
 * function: WIFILOGIN_MSG_Delete
 * address: 0x021D5A9C
 * packet: pkt_ov115_021D5A9C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TIME_ICON_Delete 0x0202F038 thumb
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   WIFILOGIN_MSG_CloseMessage 0x021D5D3C thumb ov115
 *   WIFILOGIN_MSG_GetFrameIdA 0x021D5FA0 thumb ov115
 *   WIFILOGIN_MSG_GetFrameIdB 0x021D5FC4 thumb ov115
 *   BG_SYS_DeleteHalf 0x0203FB44 arm
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   WORDSET_DeleteStrbufED04 0x0201ED04 thumb
 *   MSGDATA_Delete 0x02045C04 arm
 *   GF_FONT_Delete 0x0201D83C thumb
 *   STRBUF_Delete 0x02045808 arm
 *   APP_TASKMENU_RES_Delete 0x02027FD8 thumb
 *   TCBL_Destroy 0x02031140 arm
 *   PRINTSYS_QUE_Clear 0x0201C6EC thumb
 *   PRINTSYS_QUE_Delete 0x0201C4C0 thumb
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj00724.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Descriptor;
struct PrintSys;
struct Rec;
struct Rec3;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern void TIME_ICON_Delete(u8 *p);
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern void WIFILOGIN_MSG_CloseMessage(u8 *p);
extern u32 WIFILOGIN_MSG_GetFrameIdA(u32);
extern u32 WIFILOGIN_MSG_GetFrameIdB(u32);
extern void BG_SYS_DeleteHalf(u32 layer, u32 offset, u32 size);
extern void GF_FONT_SetDefaultTextColor(void);
extern u32 WORDSET_DeleteStrbufED04(struct WordSet *p);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void TCBL_Destroy(struct S02031140 *p);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_WIN_Exit(void);
extern u32 func_020307B0(void *p);
void WIFILOGIN_MSG_Delete(u8 *p) {
    u32 n;
    if (((struct Obj00724 *)p)->f80) { TIME_ICON_Delete(((struct Obj00724 *)p)->f80); ((struct Obj00724 *)p)->f80=0; }
    if (((struct Obj00724 *)p)->f38) { PRINTSYS_PrintStreamDelete(((struct Obj00724 *)p)->f38); ((struct Obj00724 *)p)->f38=0; }
    WIFILOGIN_MSG_CloseMessage(p);
    n=((struct Obj00724 *)p)->f0;
    BG_SYS_DeleteHalf(WIFILOGIN_MSG_GetFrameIdA(((struct Obj00724 *)p)->f50),(u16)n,(u16)(n>>16));
    n=((struct Obj00724 *)p)->f4;
    BG_SYS_DeleteHalf(WIFILOGIN_MSG_GetFrameIdB(((struct Obj00724 *)p)->f50),(u16)n,(u16)(n>>16));
    GF_FONT_SetDefaultTextColor();
    WORDSET_DeleteStrbufED04(((struct Obj00724 *)p)->f20);
    MSGDATA_Delete(((struct Obj00724 *)p)->f1C);
    GF_FONT_Delete(((struct Obj00724 *)p)->f24);
    STRBUF_Delete(((struct Obj00724 *)p)->f28);
    APP_TASKMENU_RES_Delete(((struct Obj00724 *)p)->f70);
    TCBL_Destroy(((struct Obj00724 *)p)->f44);
    PRINTSYS_QUE_Clear(((struct Obj00724 *)p)->f48);
    PRINTSYS_QUE_Delete(((struct Obj00724 *)p)->f48);
    if (((struct Obj00724 *)p)->f2C) { BMP_WIN_Delete(((struct Obj00724 *)p)->f2C); ((struct Obj00724 *)p)->f2C=0; }
    if (((struct Obj00724 *)p)->f30) { BMP_WIN_Delete(((struct Obj00724 *)p)->f30); ((struct Obj00724 *)p)->f30=0; }
    BMP_WIN_Exit();
    func_020307B0(p);
}
