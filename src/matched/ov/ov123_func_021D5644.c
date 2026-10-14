/*
 * function: GSYNC_MESSAGE_ExitSystem
 * address: 0x021D5644
 * packet: pkt_ov123_021D5644
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: low and high halves of packed words pass to u16 callee parameters; no explicit high-half cast.
 * symbols:
 *   func_0201DD68 0x0201DD68 thumb
 *   GSYNC_MESSAGE_ClearStream 0x021D584C thumb ov123
 *   GSYNC_MESSAGE_DeleteButtonManager 0x021D54E0 thumb ov123
 *   BMP_WIN_Delete 0x020452E8 arm
 *   func_0203FB44 0x0203FB44 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   STRBUF_Delete 0x02045808 arm
 *   TCBL_Destroy 0x02031140 arm
 *   BMP_WIN_Exit 0x020450C8 arm
 *   func_020307B0 0x020307B0 arm
 *   GF_FONT_Delete  0x0201D83C  thumb  arm9
 *   APP_TASKMENU_RES_Delete  0x02027FD8  thumb  arm9
 *   APP_KEYCURSOR_Delete  0x02028604  thumb  arm9
 *   PRINTSYS_QUE_Delete  0x0201C4C0  thumb  arm9
 *   PRINTSYS_QUE_Clear  0x0201C6EC  thumb  arm9
 */
#include "../include/Obj01154.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void GSYNC_MESSAGE_ClearStream(char *);
typedef unsigned char  u8;
extern void GSYNC_MESSAGE_DeleteButtonManager(u8 *p);
struct Descriptor;
struct PrintSys;
struct Rec;
struct S02031140;
struct TaskMenuState;
struct U16Vec;
struct WordSet;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern int APP_KEYCURSOR_Delete(int a0);
extern u32 func_0201ED04(struct WordSet *p);
extern void func_0201DD68(void);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern u32 GF_FONT_Delete(void *ptr);
extern void STRBUF_Delete(struct U16Vec *vec);
extern u32 APP_TASKMENU_RES_Delete(struct TaskMenuState *s);
extern void PRINTSYS_QUE_Clear(struct PrintSys *p);
extern void PRINTSYS_QUE_Delete(struct PrintSys *p);
extern void TCBL_Destroy(struct S02031140 *p);
extern void BMP_WIN_Exit(void);
extern u32 func_020307B0(void *p);
void GSYNC_MESSAGE_ExitSystem(char *p)
{
    int i;
    u32 a;
    GSYNC_MESSAGE_ClearStream(p);
    if (((struct Obj01154 *)p)->f44) BMP_WIN_Delete(((struct Obj01154 *)p)->f44);
    if (((struct Obj01154 *)p)->f48) BMP_WIN_Delete(((struct Obj01154 *)p)->f48);
    for(i=0;i<12;i++) {
        if (*(void **)(p+0x4c+i*4)) BMP_WIN_Delete(*(void **)(p+0x4c+i*4));
    }
    a=((struct Obj01154 *)p)->f8>>16;
    func_0203FB44((int)5,(u16)(((struct Obj01154 *)p)->f8),(u16)a);
    a=((struct Obj01154 *)p)->f4>>16;
    func_0203FB44((int)6,(u16)(((struct Obj01154 *)p)->f4),(u16)a);
    GSYNC_MESSAGE_DeleteButtonManager((u8 *)p);
    APP_KEYCURSOR_Delete((int)(((struct Obj01154 *)p)->f40));
    func_0201ED04(((struct Obj01154 *)p)->f24);
    func_0201DD68();
    MSGDATA_Delete(((struct Obj01154 *)p)->f20);
    GF_FONT_Delete(((struct Obj01154 *)p)->f28);
    STRBUF_Delete(((struct Obj01154 *)p)->f2C);
    STRBUF_Delete(((struct Obj01154 *)p)->f30);
    APP_TASKMENU_RES_Delete(((struct Obj01154 *)p)->fA4);
    PRINTSYS_QUE_Clear(((struct Obj01154 *)p)->f88);
    PRINTSYS_QUE_Delete(((struct Obj01154 *)p)->f88);
    TCBL_Destroy(((struct Obj01154 *)p)->f84);
    BMP_WIN_Exit();
    func_020307B0(p);
}
