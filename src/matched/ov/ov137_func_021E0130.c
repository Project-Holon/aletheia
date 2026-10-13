/*
 * function: func_021E0130
 * address: 0x021E0130
 * packet: pkt_ov137_021E0130
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 021E01AE.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_0201F73C 0x0201F73C thumb
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_PrintQueColor 0x0201C724 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj03843.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_0201F73C(void *,int,int,int);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_PrintQueColor(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
struct Cfg;
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
void func_021E0130(u8 *p,int message)
{
    u8 *s;
    void *window,*owner,*data;
    s=p+3296;
    window=((struct Obj03843 *)s)->f10;
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    func_0201F73C(window,2,1,14);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    MSGDATA_ReadString(((struct Obj03843 *)s)->f8,message,((struct Obj03843 *)s)->f5C);
    owner=((struct Obj03843 *)s)->f58;
    data=BMP_WIN_GetBmp(((struct Obj03843 *)s)->f28);
    PRINTSYS_PrintQueColor(owner,(u32)data,0,0,(u32)(((struct Obj03843 *)s)->f5C),(u32)(((struct Obj03843 *)s)->f4),1088);
    ((struct Obj03843 *)s)->f2C=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
}
