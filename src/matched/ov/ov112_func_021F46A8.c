/*
 * function: MUSICAL_SHOT_INFO_InitWindows
 * address: 0x021F46A8
 * packet: pkt_ov112_021F46A8
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two-byte padding at 0x021F4746.
 * symbols:
 *   GF_FONT_SetDefaultTextColor 0x0201DD68 thumb
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02045B38 0x02045B38 arm
 *   func_02049B40 0x02049B40 arm
 *   TCBL_Create 0x0203101C arm
 *   GF_FONT_Create  0x0201D7EC  thumb  arm9
 *   PRINTSYS_QUE_Create  0x0201C440  thumb  arm9
 *   BMP_MENUWORK_LoadCharAndPltt  0x0201F5BC  thumb  arm9
 */
#include "../include/Obj01147.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void BMP_WIN_TransferChars(struct Descriptor *d);
struct Cfg;
struct GfFont;
struct MsgBank;
struct Tcbl;
extern void BMP_WIN_MakeScreen(struct Cfg *cfg);
extern void BG_SYS_PushTile(u32 index);
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void BMP_MENUWORK_LoadCharAndPltt(u32 a, u32 b, u32 c, u32 d, u16 e);
extern u32 func_02049B40(int,int,int,int,int,u16);
extern void GF_FONT_SetDefaultTextColor(u32);
extern struct Tcbl *TCBL_Create(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 PRINTSYS_QUE_Create(void *p);
void MUSICAL_SHOT_INFO_InitWindows(u8 *p)
{
    int zero;
    ((struct Obj01147 *)p)->f1C=BMP_WIN_Create(4,1,1,30,4,10,1);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj01147 *)p)->f1C);
    BMP_WIN_MakeScreen((struct Cfg *)(((struct Obj01147 *)p)->f1C));
    BG_SYS_PushTile(4);
    zero=0;
    ((struct Obj01147 *)p)->f20=(u32)GF_FONT_Create(23,0,0,0,((struct Obj01147 *)p)->f0);
    ((struct Obj01147 *)p)->f28=(u32)func_02045B38(0,2,78,((struct Obj01147 *)p)->f0);
    BMP_MENUWORK_LoadCharAndPltt(4,1,11,0,((struct Obj01147 *)p)->f0);
    GF_FONT_SetDefaultTextColor(func_02049B40(23,5,4,320,32,((struct Obj01147 *)p)->f0));
    ((struct Obj01147 *)p)->f18=(u32)TCBL_Create(((struct Obj01147 *)p)->f0,((struct Obj01147 *)p)->f0,3,256);
    ((struct Obj01147 *)p)->f24=zero;
    ((struct Obj01147 *)p)->f2C=zero;
    ((struct Obj01147 *)p)->f30=zero;
    ((struct Obj01147 *)p)->f34=zero;
    ((struct Obj01147 *)p)->f38=PRINTSYS_QUE_Create((void *)(((struct Obj01147 *)p)->f0));
}
