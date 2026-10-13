/*
 * function: func_021D9514
 * address: 0x021D9514
 * packet: pkt_ov123_021D9514
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow the return.
 * symbols:
 *   MSGDATA_ReadString 0x02045CAC arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_PrintStream  0x0201CCE4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 */
#include "../include/Obj02477.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
struct MsgBank;
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(unsigned int,unsigned int,unsigned int);
extern void *PRINTSYS_PrintStream(void *,int,int,void *,void *,int,void *,int,u16,u16);
extern signed char func_02012FFC(void);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D9514(char *p, int n)
{
    void *q;
    MSGDATA_ReadString(((struct Obj02477 *)p)->f20,n,((struct Obj02477 *)p)->f2C);
    if (!((struct Obj02477 *)p)->f48) ((struct Obj02477 *)p)->f48=(void *)BMP_WIN_Create(5,1,3,30,4,11,1);
    q=((struct Obj02477 *)p)->f48;
    BMP_Clear(func_02045770(q),15);
    GF_FONT_SetTextColor(1,2,15);
    ((struct Obj02477 *)p)->f80=PRINTSYS_PrintStream(q,0,0,((struct Obj02477 *)p)->f2C,((struct Obj02477 *)p)->f28,func_02012FFC(),((struct Obj02477 *)p)->f88,2,((struct Obj02477 *)p)->fB0,15);
    func_0201F73C(q,1,(u16)(((struct Obj02477 *)p)->f8),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(5);
}
