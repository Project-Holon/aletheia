/*
 * function: func_021D5960
 * address: 0x021D5960
 * packet: pkt_ov123_021D5960
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes zero alignment padding follow the return.
 * symbols:
 *   func_020452E8 0x020452E8 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 *   PRINTSYS_Print  0x0201C7A4  thumb  arm9
 *   GF_FONT_SetTextColor  0x0201DD78  thumb  arm9
 */
#include "../include/Obj05361.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Cfg;
struct CharBuf;
struct Descriptor;
extern u32 func_020452E8(struct Descriptor *d);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(unsigned int,unsigned int,unsigned int);
extern void PRINTSYS_Print(void *,short,short,void *,void *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021D5960(char *p,int a,int b)
{
    void *q;
    if (((struct Obj05361 *)p)->f48) func_020452E8(((struct Obj05361 *)p)->f48);
    q=(void *)BMP_WIN_Create((int)6,(int)1,(u8)a,(int)30,b,11,1);
    ((struct Obj05361 *)p)->f48=q;
    BMP_Clear(func_02045770(q),15);
    GF_FONT_SetTextColor(1,2,15);
    PRINTSYS_Print(func_02045770(q),0,0,((struct Obj05361 *)p)->f2C,((struct Obj05361 *)p)->f28);
    func_0201F73C(q,1,(u16)(((struct Obj05361 *)p)->f4),12);
    BMP_WIN_TransferChars(q);
    BMP_WIN_MakeScreen(q);
    func_02041B6C(6);
}
