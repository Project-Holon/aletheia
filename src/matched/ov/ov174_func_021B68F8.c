/*
 * function: LOCAL_TVT_SYS_CreateTextWindow
 * address: 0x021B68F8
 * packet: pkt_ov174_021B68F8
 * region: ov174
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 0x021B6992..0x021B6994 is two zero alignment bytes.
 * symbols:
 *   BMP_MENUWORK_DrawWindowBorder 0x0201F7A8 thumb
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 *   func_02041B6C 0x02041B6C arm
 *   BMP_WIN_Delete 0x020452E8 arm
 *   BMP_MENUWORK_DrawWindow 0x0201F73C thumb
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_02028470 0x02028470 thumb
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_GetBmp 0x02045770 arm
 */
#include "../include/Obj02507.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct CharBuf;
struct Cfg;
struct Descriptor;
extern void BMP_MENUWORK_DrawWindowBorder(void *desc, u32 kind);
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern void func_02041B6C(unsigned);
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern void BMP_MENUWORK_DrawWindow(void *,int,int,int);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_02028470(u8 *p, u32 v);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *BMP_WIN_GetBmp(struct Descriptor *);
void LOCAL_TVT_SYS_CreateTextWindow(u8 *p,int mode)
{
 void *tmp;
 if(((struct Obj02507 *)p)->f5C){
 BMP_MENUWORK_DrawWindowBorder(((struct Obj02507 *)p)->f5C,1);
 tmp=((struct Obj02507 *)p)->f5C;BMP_WIN_ClearScreen(tmp);func_02041B6C(BMP_WIN_GetBgLayer(tmp));
 BMP_WIN_Delete(((struct Obj02507 *)p)->f5C);((struct Obj02507 *)p)->f5C=0;
 }
 if(mode==0) ((struct Obj02507 *)p)->f5C=(void *)BMP_WIN_Create(0,1,1,30,4,12,1);
 else if(mode==1) ((struct Obj02507 *)p)->f5C=(void *)BMP_WIN_Create(0,1,19,30,4,12,1);
 BMP_MENUWORK_DrawWindow(((struct Obj02507 *)p)->f5C,1,1,13);
 BMP_Clear(BMP_WIN_GetBmp(((struct Obj02507 *)p)->f5C),15);
 BMP_WIN_TransferChars(((struct Obj02507 *)p)->f5C);BMP_WIN_MakeScreen(((struct Obj02507 *)p)->f5C);
 func_02041B6C(0);func_02028470(p+128,6);
}
