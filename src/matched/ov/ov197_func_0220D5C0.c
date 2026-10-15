/*
 * function: B_BAG_MAIN_InitBg
 * address: 0x0220D5C0
 * packet: pkt_ov197_0220D5C0
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_ApplyGraphicsMode 0x0203FC6C arm
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   func_02041B6C 0x02041B6C arm
 *   BG_SYS_SetSubPlaneVisible 0x02043598 arm
 *   d_0220DEB0 0x0220DEB0 data a4
 *   d_0220DEE0 0x0220DEE0 data a4
 *   d_0220DF20 0x0220DF20 data a4
 *   d_0220DF00 0x0220DF00 data a4
 *   d_0220DEC0 0x0220DEC0 data a4
 */
#include "../include/Obj14552.h"
#include "../include/Obj25101.h"
#include "../include/Obj25102.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct BgVramReq {u32 a,b,c,d;};
struct BgTemplate {u32 a,b,size,c;u8 d,e,f,g;u32 h;u8 i,j,k,l;u32 m;};
extern const struct BgVramReq d_0220DEB0;
extern const struct BgTemplate d_0220DEE0,d_0220DF20,d_0220DF00,d_0220DEC0;
extern void BG_SYS_ApplyGraphicsMode(const struct BgVramReq *,u32);
extern void BG_SYS_InitBgLayer(u32,const struct BgTemplate *,u32);
extern void BG_SYS_ClearSlot(u32);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02041B6C(u32);
extern void BG_SYS_SetSubPlaneVisible(u32,u32);
void B_BAG_MAIN_InitBg(char *p)
{
 struct BgVramReq req=d_0220DEB0;
 struct BgTemplate b7,b6,b5,b4;
 BG_SYS_ApplyGraphicsMode(&req,1);
 b7=d_0220DEE0;BG_SYS_InitBgLayer(7,&b7,0);
 b6=d_0220DF20;BG_SYS_InitBgLayer(6,&b6,0);
 b5=d_0220DF00;BG_SYS_InitBgLayer(5,&b5,0);BG_SYS_ClearSlot(5);
 b4=d_0220DEC0;BG_SYS_InitBgLayer(4,&b4,0);BG_SYS_ClearSlot(4);
 BG_SYS_InitRun(5,32,0,((struct Obj25101 *)(*(char * *)&((struct Obj14552 *)p)->f0))->fC);
 BG_SYS_InitRun(4,32,0,((struct Obj25102 *)(*(char * *)&((struct Obj14552 *)p)->f0))->fC);
 func_02041B6C(5);func_02041B6C(4);BG_SYS_SetSubPlaneVisible(15,1);
}
