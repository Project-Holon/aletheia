/*
 * function: func_021F3CD0
 * address: 0x021F3CD0
 * packet: pkt_ov194_021F3CD0
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MI_CpuFill8 0x02082BCC arm
 *   STRBUF_Create 0x020457B0 arm
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_0201F73C 0x0201F73C thumb
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BMP_WIN_GetBgLayer 0x02045730 arm
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj01774.h"
extern void MI_CpuFill8(unsigned char *,unsigned,unsigned);
struct U16Vec;
extern struct U16Vec *STRBUF_Create(unsigned int capacity, unsigned int heapId);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Cfg;
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *d);
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_020409B4(unsigned);
void func_021F3CD0(unsigned char *p,int a,int b,int c,int d,unsigned short e) {
    int window;
    MI_CpuFill8(p,0,0x24);
    ((struct Obj01774 *)p)->f20=15;
    ((struct Obj01774 *)p)->f4=a; ((struct Obj01774 *)p)->f18=d; ((struct Obj01774 *)p)->f0=b; ((struct Obj01774 *)p)->f10=c;
    ((struct Obj01774 *)p)->f1C=(int)STRBUF_Create(255,e);
    ((struct Obj01774 *)p)->f14=BMP_WIN_Create(4,1,19,30,4,15,1);
    func_0201F73C((void *)(((struct Obj01774 *)p)->f14),2,1,14);
    ((struct Obj01774 *)p)->f8=((struct Obj01774 *)p)->f14;
    ((struct Obj01774 *)p)->fC=0;
    BMP_Clear((struct CharBuf *)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj01774 *)p)->f14),((struct Obj01774 *)p)->f20);
    window=((struct Obj01774 *)p)->f14;
    BMP_WIN_TransferChars((struct Descriptor *)window); BMP_WIN_MakeScreen((struct Cfg *)window);
    func_020409B4(BMP_WIN_GetBgLayer((struct Descriptor *)window));
}
