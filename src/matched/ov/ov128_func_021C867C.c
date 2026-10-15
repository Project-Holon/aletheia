/*
 * function: func_021C867C
 * address: 0x021C867C
 * packet: pkt_ov128_021C867C
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   STRBUF_Create 0x020457B0 arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_02041B6C 0x02041B6C arm
 *   STRBUF_Delete 0x02045808 arm
 *   func_021CA3E8 0x021CA3E8 thumb ov128
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   PRINTSYS_PrintStreamDelete  0x0201CE48  thumb  arm9
 *   MSG_SPEED_GetWait  0x02012FFC  thumb  arm9
 */
#include "../include/Obj00329.h"
#include "../include/Obj03811.h"
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
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern struct U16Vec *STRBUF_Create(u32 capacity, u32 heapId);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern signed char MSG_SPEED_GetWait(void);
extern void *PRINTSYS_PrintStream(void *,int,int,void *,void *,void *,void *,int,u16,int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
extern void STRBUF_Delete(struct U16Vec *vec);
extern void func_021CA3E8(int);
void func_021C867C(u8 *p, u8 *a, int n, int heap)
{
    void *text;
    void *q;
    if (((struct Obj00329 *)a)->f2C) {
        PRINTSYS_PrintStreamDelete(((struct Obj00329 *)a)->f2C);
        ((struct Obj00329 *)a)->f2C = 0;
    }
    BMP_Clear(BMP_WIN_GetBmp(((struct Obj03811 *)p)->f108),15);
    text=STRBUF_Create(128,heap);
    MSGDATA_ReadString(((struct Obj00329 *)a)->f4,n,text);
    func_0201F250(((struct Obj00329 *)a)->f0,((struct Obj03811 *)p)->f110,text);
    ((struct Obj00329 *)a)->f2C=PRINTSYS_PrintStream(((struct Obj03811 *)p)->f108,0,0,((struct Obj03811 *)p)->f110,((struct Obj00329 *)a)->f17C,(void *)MSG_SPEED_GetWait(),((struct Obj00329 *)a)->f28,10,((struct Obj00329 *)a)->f180,0);
    func_0201F73C(((struct Obj03811 *)p)->f108,2,70,11);
    q=((struct Obj03811 *)p)->f108;
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(BMP_WIN_GetBgLayer(q));
    STRBUF_Delete(text);
    func_021CA3E8(0);
}
