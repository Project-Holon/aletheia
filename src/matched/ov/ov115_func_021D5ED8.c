/*
 * function: WIFILOGIN_MSG_PrintMessage
 * address: 0x021D5ED8
 * packet: pkt_ov115_021D5ED8
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   STRBUF_Clone 0x02045874 arm
 *   WORDSET_CopyTaggedText 0x0201F250 thumb
 *   WIFILOGIN_MSG_GetFrameIdB 0x021D5FC4 thumb ov115
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj01720.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern struct U16Vec *STRBUF_Clone(struct U16Vec *src, u32 heapId);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 WIFILOGIN_MSG_GetFrameIdB(u32);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32);
extern void STRBUF_Delete(struct U16Vec *vec);
void WIFILOGIN_MSG_PrintMessage(u8 *p,u32 n) {
    void *w;
    void *s;
    MSGDATA_ReadString(((struct Obj01720 *)p)->f1C,n,((struct Obj01720 *)p)->f28);
    s=STRBUF_Clone(((struct Obj01720 *)p)->f28,((struct Obj01720 *)p)->f4C);
    WORDSET_CopyTaggedText(((struct Obj01720 *)p)->f20,((struct Obj01720 *)p)->f28,s);
    if (((struct Obj01720 *)p)->f30==0) ((struct Obj01720 *)p)->f30=(void *)BMP_WIN_Create(WIFILOGIN_MSG_GetFrameIdB(((struct Obj01720 *)p)->f50),1,1,30,16,11,1);
    w=((struct Obj01720 *)p)->f30;
    BMP_Clear(BMP_WIN_GetBmp(w),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(BMP_WIN_GetBmp(w),0,0,((struct Obj01720 *)p)->f28,((struct Obj01720 *)p)->f24);
    BMP_MENUWORK_DrawWindow(w,(u32)1,(u16)(((struct Obj01720 *)p)->f4),(u32)12);
    BMP_WIN_TransferChars(w);
    BMP_WIN_MakeScreen(w);
    func_02041B6C(WIFILOGIN_MSG_GetFrameIdB(((struct Obj01720 *)p)->f50));
    STRBUF_Delete(s);
}
