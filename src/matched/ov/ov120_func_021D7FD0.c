/*
 * function: GTSNEGO_MSG_PrintEntry
 * address: 0x021D7FD0
 * packet: pkt_ov120_021D7FD0
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D80D2.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 *   WORDSET_SetSlotFromKeyedMessage  0x0201F094  thumb  arm9
 *   WORDSET_SetSlotFromMsgE7  0x0201F048  thumb  arm9
 *   WORDSET_CopyTaggedText  0x0201F250  thumb  arm9
 */
#include "../include/Obj00131.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Sub0200852CObj;
struct WordSet;
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 func_02025C1C(u32,u32,u32);
extern u32 func_02025C30(u32,u32,u32);
extern void WORDSET_SetSlotFromMsgE7(struct WordSet *p, u32 i, u32 n);
extern void WORDSET_SetSlotFromKeyedMessage(struct WordSet *p, u32 i, u32 a, u32 n);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void WORDSET_CopyTaggedText(struct WordSet *ws, void *dst, void *src);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void GTSNEGO_MSG_PrintEntry(char *p,void *r)
{
    u32 a,b,c,d;
    void *q;
    a=func_0200856C(r);
    b=func_02008570(r);
    c=func_02025C1C(a,b,func_02008564(r));
    d=func_02025C30(a,b,func_02008564(r));
    if(a==c && b==d) {
        WORDSET_SetSlotFromMsgE7(((struct Obj00131 *)p)->f10,0,func_0200856C(r));
        a=func_0200856C(r);
        WORDSET_SetSlotFromKeyedMessage(((struct Obj00131 *)p)->f10,1,a,func_02008570(r));
    } else {
        WORDSET_SetSlotFromMsgE7(((struct Obj00131 *)p)->f10,0,0);
        WORDSET_SetSlotFromKeyedMessage(((struct Obj00131 *)p)->f10,1,0,0);
    }
    MSGDATA_ReadString(((struct Obj00131 *)p)->fC,34,((struct Obj00131 *)p)->f20);
    WORDSET_CopyTaggedText(((struct Obj00131 *)p)->f10,((struct Obj00131 *)p)->f18,((struct Obj00131 *)p)->f20);
    if(!((struct Obj00131 *)p)->f84) ((struct Obj00131 *)p)->f84=(void *)BMP_WIN_Create(1,1,15,30,5,11,1);
    q=((struct Obj00131 *)p)->f84;
    BMP_Clear(BMP_WIN_GetBmp(q),0);
    GF_FONT_SetTextColor(15,2,0);
    PRINTSYS_Print(BMP_WIN_GetBmp(q),5,5,((struct Obj00131 *)p)->f18,((struct Obj00131 *)p)->f14);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(1);
}
