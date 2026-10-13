/*
 * function: func_021B66A0
 * address: 0x021B66A0
 * packet: pkt_ov180_021B66A0
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_UTIL_Create 0x02047CFC arm
 *   func_021B65FC 0x021B65FC thumb ov180
 */
#include "../include/Obj00547.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef short s16;
struct Util;
extern void G3D_SYSTEM_Init(u32 texMode, u32 texSize, u32 plttMode, u32 plttSize, u16 fifoSize, s16 heap, void (*setup)(void));
extern struct Util *G3D_UTIL_Create(u16,u16,u16);
extern void func_021B65FC(void);
void func_021B66A0(char *p) {G3D_SYSTEM_Init(0,1,0,1,4096,141,func_021B65FC);*(struct Util * *)&((struct Obj00547 *)p)->f10=G3D_UTIL_Create(32,32,141);}
