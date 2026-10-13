/*
 * function: func_021E0EF4
 * address: 0x021E0EF4
 * packet: pkt_ov119_021E0EF4
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * prototype: 0201F73C arg2 is u16 because 021E0FC4..021E0FC6 truncates the loaded full word before the call.
 * prototype: 0201CCE4 forwarding wrapper leaves r0 live; caller stores it at 021E0F94 despite legacy void declaration.
 * symbols:
 *   func_021E106C 0x021E106C thumb ov119
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   GF_FONT_SetTextColor 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   PRINTSYS_PrintStream 0x0201CCE4 thumb
 *   func_02028470 0x02028470 thumb
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02041B6C 0x02041B6C arm
 */
#include "../include/Obj01055.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
struct Cfg;
struct CharBuf;
extern void func_021E106C(char *p);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void GF_FONT_SetTextColor(u32,u32,u32);
extern signed char func_02012FFC(void);
extern u32 PRINTSYS_PrintStream(u32,u32,u32,u32,u32,u32,u32,u32,u16,u16);
extern void func_02028470(u8 *,u32);
extern void PRINTSYS_Print(void *,s16,s16,void *,void *);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void BMP_WIN_TransferChars(struct Descriptor *);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02041B6C(u32 bit);
void func_021E0EF4(char *p,int flag,int x,int y,int w,int h)
{
    void *v;
    func_021E106C(p);
    func_02049B40(23,5,4,448,32,((struct Obj01055 *)p)->f5F4);
    v=(void *)BMP_WIN_Create(6,(u8)x,(u8)y,(u8)w,h,(u32)14,(u32)0);
    ((struct Obj01055 *)p)->f71C=v;
    BMP_Clear(func_02045770(v),15);
    GF_FONT_SetTextColor(1,2,15);
    if(flag==0) {
        ((struct Obj01055 *)p)->f72C=PRINTSYS_PrintStream((u32)v,0,0,*(u32 *)&((struct Obj01055 *)p)->f738,*(u32 *)&((struct Obj01055 *)p)->f728,func_02012FFC(),((struct Obj01055 *)p)->f744,2,((struct Obj01055 *)p)->f5F4,15);
        func_02028470((u8 *)p+0x11d4,2);
    } else {
        PRINTSYS_Print(func_02045770(v),0,0,((struct Obj01055 *)p)->f738,((struct Obj01055 *)p)->f728);
    }
    func_0201F73C(v,1,(u16)(((struct Obj01055 *)p)->f644),15);
    BMP_WIN_TransferChars(v);BMP_WIN_MakeScreen(v);func_02041B6C(6);
}
