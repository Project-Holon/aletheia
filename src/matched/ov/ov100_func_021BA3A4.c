/*
 * function: func_021BA3A4
 * address: 0x021BA3A4
 * packet: pkt_ov100_021BA3A4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two trailing zero padding bytes at 0x021BA452.
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   MSGDATA_ReadString 0x02045CAC arm
 *   PRINTSYS_Print 0x0201C7A4 thumb
 *   BMP_WIN_TransferChars 0x02045334 arm
 */
#include "../include/Obj00060.h"
struct Word { int x; };
typedef unsigned short u16;
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
typedef signed short   s16;
struct Cfg;
struct CharBuf;
struct MsgBank;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void MSGDATA_ReadString(struct MsgBank *bank, u32 index, void *dest);
extern void PRINTSYS_Print(void *x, s16 y, s16 z, void *s, void *w);
extern void BMP_WIN_TransferChars(struct Descriptor *);
void func_021BA3A4(struct Word *p,int a) {
 func_02049B40(23,5,4,0x1a0,32,((struct Obj00060 *)a)->f278);
 if(*(int *)&((struct Obj00060 *)a)->f27C==0) {
  int v=BMP_WIN_Create(5,1,1,30,5,13,0);
  *(int *)&((struct Obj00060 *)a)->f27C=v;
  BMP_WIN_MakeScreen((struct Cfg *)v);
  func_0201F73C((void *)(*(int *)&((struct Obj00060 *)a)->f27C),0,(unsigned short)(((struct Obj00060 *)a)->f304),14);
 }
 BMP_Clear((struct CharBuf *)((int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((struct Obj00060 *)a)->f27C)),255);
 ((struct Obj00060 *)a)->fCB0=p->x;
 MSGDATA_ReadString((struct MsgBank *)(((struct Obj00060 *)a)->f288),p->x,(void *)(((struct Obj00060 *)a)->f298));
 PRINTSYS_Print((void *)((int)BMP_WIN_GetBmp((struct Descriptor *)*(int *)&((struct Obj00060 *)a)->f27C)),4,4,(void *)(((struct Obj00060 *)a)->f298),(void *)(((struct Obj00060 *)a)->f290));
 BMP_WIN_TransferChars((struct Descriptor *)*(int *)&((struct Obj00060 *)a)->f27C);
}
