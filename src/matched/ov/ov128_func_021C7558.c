/*
 * function: func_021C7558
 * address: 0x021C7558
 * packet: pkt_ov128_021C7558
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   PRINTSYS_PrintStreamDelete 0x0201CE48 thumb
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 */
#include "../include/Obj03280.h"
#include "../include/Obj05379.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct WordSet;
extern void PRINTSYS_PrintStreamDelete(struct Rec3 *p);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char func_02012FFC(void);
extern void *PRINTSYS_PrintStream(void *,int,int,void *,void *,int,void *,int,u16,u16);
extern void func_0201F73C(void *,int,int,int);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(unsigned);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021CA3E8(int);
void func_021C7558(u8 *p,u8 *ctx,unsigned v,unsigned heap)
{
    void *buf;
    void *obj;
    int font;
    if(((struct Obj03280 *)ctx)->f2C) {
        PRINTSYS_PrintStreamDelete(((struct Obj03280 *)ctx)->f2C);
        ((struct Obj03280 *)ctx)->f2C=0;
    }
    buf=STRBUF_Create(128,heap);
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj05379 *)p)->f1C),15);
    MSGDATA_ReadString(((struct Obj03280 *)ctx)->f4,v,buf);
    func_0201F250(((struct Obj03280 *)ctx)->f0,((struct Obj05379 *)p)->f2C,buf);
    font=func_02012FFC();
    ((struct Obj03280 *)ctx)->f2C=PRINTSYS_PrintStream(((struct Obj05379 *)p)->f1C,0,0,((struct Obj05379 *)p)->f2C,((struct Obj03280 *)ctx)->f17C,font,((struct Obj03280 *)ctx)->f28,10,((struct Obj03280 *)ctx)->f180,0);
    func_0201F73C(((struct Obj05379 *)p)->f1C,2,70,11);
    obj=((struct Obj05379 *)p)->f1C;
    BMP_WIN_TransferChars(obj);
    BMP_WIN_MakeScreen(obj);
    func_02041B6C(BMP_WIN_GetBgLayer(obj));
    STRBUF_Delete(buf);
    func_021CA3E8(0);
}
