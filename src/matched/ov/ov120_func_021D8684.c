/*
 * function: func_021D8684
 * address: 0x021D8684
 * packet: pkt_ov120_021D8684
 * region: ov120
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * follower: two zero padding bytes at 021D8782.
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 */
#include "../include/Obj00131.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct WordSet;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void GF_FONT_SetTextColor(u32 r, u32 g, u32 b);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
void func_021D8684(char *p,int unused,u32 n)
{
    void *q;
    MSGDATA_ReadString(((struct Obj00131 *)p)->fC,40,((struct Obj00131 *)p)->f18);
    if(!((struct Obj00131 *)p)->f8C) ((struct Obj00131 *)p)->f8C=(void *)BMP_WIN_Create(1,21,4,10,2,4,1);
    q=((struct Obj00131 *)p)->f8C;
    BMP_Clear(func_02045770(q),0);
    GF_FONT_SetTextColor(15,14,0);
    PRINTSYS_Print(func_02045770(q),0,3,((struct Obj00131 *)p)->f18,((struct Obj00131 *)p)->f14);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_0201EFA4(((struct Obj00131 *)p)->f10,0,n,5,1,1);
    MSGDATA_ReadString(((struct Obj00131 *)p)->fC,36,((struct Obj00131 *)p)->f20);
    func_0201F250(((struct Obj00131 *)p)->f10,((struct Obj00131 *)p)->f18,((struct Obj00131 *)p)->f20);
    if(!((struct Obj00131 *)p)->f90) ((struct Obj00131 *)p)->f90=(void *)BMP_WIN_Create(1,21,6,10,3,11,1);
    q=((struct Obj00131 *)p)->f90;
    BMP_Clear(func_02045770(q),0);
    GF_FONT_SetTextColor(15,2,0);
    PRINTSYS_Print(func_02045770(q),0,5,((struct Obj00131 *)p)->f18,((struct Obj00131 *)p)->f14);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
}
