/*
 * function: BR_POKESEARCH_ShowBg
 * address: 0x021F8D5C
 * packet: pkt_ov185_021F8D5C
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_SHOT_SYS_DeleteScene 0x021F3BF0 thumb ov112
 *   BR_GRAPHIC_End3d 0x021FC640 thumb ov186
 *   BR_RES_LoadUiPalette 0x021FC148 thumb ov186
 *   BR_RES_LoadBgGraphics 0x021FB964 thumb ov186
 *   BR_SIDEBAR_SetVisibleBySpace 0x021FEEC0 thumb ov186
 */
#include "../include/Obj03337.h"
#include "../include/Obj04583.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Pair;struct PrintSys;
extern void MUSICAL_SHOT_SYS_DeleteScene(u8 *);
extern void BR_GRAPHIC_End3d(void *,unsigned);
extern void BR_RES_LoadUiPalette(char *,unsigned,unsigned);
extern void BR_RES_LoadBgGraphics(void *,unsigned,u16);
extern void BR_SIDEBAR_SetVisibleBySpace(char *p, int mode, u32 value);
void BR_POKESEARCH_ShowBg(char *p,char *q) { if(((struct Obj03337 *)p)->f14){MUSICAL_SHOT_SYS_DeleteScene(((struct Obj03337 *)p)->f14);((struct Obj03337 *)p)->f14=0;BR_GRAPHIC_End3d(((struct Obj04583 *)q)->f8,((struct Obj03337 *)p)->f30);BR_RES_LoadUiPalette(*(char * *)&((struct Obj04583 *)q)->fC,0,((struct Obj03337 *)p)->f30);BR_RES_LoadBgGraphics(((struct Obj04583 *)q)->fC,0,((struct Obj03337 *)p)->f30);BR_SIDEBAR_SetVisibleBySpace((char *)(((struct Obj04583 *)q)->f4),0,1);} }
