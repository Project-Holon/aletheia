/*
 * function: PMSIV_CATEGORY_Create
 * address: 0x021BB290
 * packet: pkt_ov110_021BB290
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   PMS_INPUT_GetUiInputModePtr 0x021BF6D4 thumb ov110
 *   sPmsivCategoryAllocSite 0x021C3C44 data a1
 */
#include "../include/Obj03751.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32,u32,int,const char *,u16); extern u8 *PMS_INPUT_GetUiInputModePtr(u8 *); extern const char sPmsivCategoryAllocSite[];
u8 *PMSIV_CATEGORY_Create(u32 a,u8 *b,u32 c) { u8 *p; p=func_02030734(42,164,0,sPmsivCategoryAllocSite,220); ((struct Obj03751 *)p)->f0=a; *(u8 * *)&((struct Obj03751 *)p)->f4=b; ((struct Obj03751 *)p)->f8=c; ((struct Obj03751 *)p)->fC=0; ((struct Obj03751 *)p)->f14=0; ((struct Obj03751 *)p)->f54=0; ((struct Obj03751 *)p)->f58=0; *(u8 * *)&((struct Obj03751 *)p)->f5C=PMS_INPUT_GetUiInputModePtr(b); return p; }
