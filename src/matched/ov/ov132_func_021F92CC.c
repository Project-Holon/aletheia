/*
 * function: func_021F92CC
 * address: 0x021F92CC
 * packet: pkt_ov132_021F92CC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   MSGDATA_CreateFromMemory 0x02045C44 arm
 *   func_02049B40 0x02049B40 arm
 *   TCBL_Create 0x0203101C arm
 *   PRINTSYS_QUE_Create 0x0201C440 thumb
 */
#include "../include/Obj01257.h"
#include "../include/Obj23182.h"
#include "../include/Obj23183.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
struct Cfg;
struct GfFont;
struct MsgBank;
struct Tcbl;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void func_020409B4(u32);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *MSGDATA_CreateFromMemory(const void *file, u32 heapId);
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *);
void func_021F92CC(u8 *p)
{
    int zero;
    ((struct Obj01257 *)p)->fD0=BMP_WIN_Create(1,4,20,24,4,15,1);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01257 *)p)->fD0);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj01257 *)p)->fD0));
    func_020409B4(1);
    zero=0;
    ((struct Obj01257 *)p)->fD4=(u32)GF_FONT_Create(23,0,0,0,((struct Obj01257 *)p)->f0);
    ((struct Obj01257 *)p)->fDC=(u32)MSGDATA_CreateFromMemory(((struct Obj23183 *)(*(u8 * *)&((struct Obj23182 *)(*(u8 * *)&((struct Obj01257 *)p)->f30))->f18))->f8,((struct Obj01257 *)p)->f0);
    func_02049B40(23,5,0,480,32,((struct Obj01257 *)p)->f0);
    ((struct Obj01257 *)p)->fCC=(u32)TCBL_Create(((struct Obj01257 *)p)->f0,((struct Obj01257 *)p)->f0,3,256);
    ((struct Obj01257 *)p)->fD8=zero;
    ((struct Obj01257 *)p)->fE0=zero;
    ((struct Obj01257 *)p)->fE4=zero;
    ((struct Obj01257 *)p)->fE8=PRINTSYS_QUE_Create((void *)(u32)((struct Obj01257 *)p)->f0);
}
