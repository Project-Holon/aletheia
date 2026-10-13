/*
 * function: func_021E026C
 * address: 0x021E026C
 * packet: pkt_ov137_021E026C
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two zero alignment bytes at 021E0302.
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
 *   func_0201EF40 0x0201EF40 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   func_0201F250 0x0201F250 thumb
 *   STRBUF_Delete 0x02045808 arm
 */
#include "../include/Obj02871.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct U16Vec;
struct WordSet;
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
extern void func_0201EF40(struct WordSet *p, u32 i, u32 v);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void STRBUF_Delete(struct U16Vec *vec);
void func_021E026C(u8 *p,int message,unsigned value)
{
    u8 *s;
    void *window,*text,*owner,*data;
    s=p+3296;
    window=((struct Obj02871 *)s)->f10;
    func_0201EF40(((struct Obj02871 *)s)->fC,0,value);
    text=STRBUF_Create(256,114);
    MSGDATA_ReadString(((struct Obj02871 *)s)->f8,message,text);
    func_0201F250(((struct Obj02871 *)s)->fC,((struct Obj02871 *)s)->f5C,text);
    STRBUF_Delete(text);
    func_0201F73C(window,2,1,14);
    BMP_Clear(BMP_WIN_GetBmp(window),15);
    owner=((struct Obj02871 *)s)->f58;
    data=BMP_WIN_GetBmp(((struct Obj02871 *)s)->f28);
    PRINTSYS_PrintQueColor(owner,(u32)data,0,0,(u32)(((struct Obj02871 *)s)->f5C),(u32)(((struct Obj02871 *)s)->f4),1088);
    ((struct Obj02871 *)s)->f2C=1;
    BMP_WIN_TransferChars(window);
    BMP_WIN_MakeScreen(window);
    func_02041B6C(BMP_WIN_GetBgLayer(window));
}
