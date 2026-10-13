/*
 * function: func_021DF1C8
 * address: 0x021DF1C8
 * packet: pkt_ov119_021DF1C8
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202208C 0x0202208C thumb
 *   DWC_RAP_SetVchatTalkLock 0x0215642C thumb ov009
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF168 0x021DF168 thumb ov119
 */
#include "../include/Obj13902.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);
extern void DWC_RAP_SetVchatTalkLock(int);
extern void func_021D8E84(void *,int);
extern void func_021DF168(void *);
void func_021DF1C8(void *p) {
 func_0202208C((void *)4,0,0,0,6,1,((struct Obj13902 *)p)->f5F4);
 if(((struct Obj13902 *)p)->f118C==2) DWC_RAP_SetVchatTalkLock(1);
 func_021D8E84(p,(int)func_021DF168);
}
