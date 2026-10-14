/*
 * function: MB_COMM_SYS_Init
 * address: 0x021EE740
 * packet: pkt_ov107_021EE740
 * region: ov107
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MB_COMM_SYS_InitDisplay 0x021EEF28 thumb ov107
 *   MB_COMM_SYS_LoadGraphics 0x021EF0F4 thumb ov107
 *   MB_UTIL_MSG_Create 0x021F1404 thumb ov107
 *   MB_COMM_SYS_CreateNetState 0x021F0DE8 thumb ov107
 *   MB_COMM_SYS_DrawTitle 0x021EF444 thumb ov107
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C1B0 0x0200C1B0 thumb
 *   func_020056A0 0x020056A0 thumb
 *   func_02005654 0x02005654 thumb
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 *   func_02034F84 0x02034F84 arm
 *   MB_COMM_SYS_VBlank 0x021EEEAC thumb ov107
 *   MB_COMM_SYS_VBlankRefreshBg 0x021EEEB4 thumb ov107
 *   MB_COMM_SYS_VBlankRefreshBgStandalone 0x021EEEF8 thumb ov107
 *   gMbParentUi 0x021F6EA0 data a4
 */
#include "../include/Obj00057.h"
#include "../include/Obj22273.h"
#include "../include/G_Counter.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Big;
struct Blk34;
struct Object;
extern void MB_COMM_SYS_InitDisplay(u8 *);
extern void MB_COMM_SYS_LoadGraphics(u8 *);
struct Work;
extern struct Work *MB_UTIL_MSG_Create(u16 heap, u32 a, u32 b, u32 c, u32 d, u32 e);
extern struct Object *MB_COMM_SYS_CreateNetState(u16);
extern void MB_COMM_SYS_DrawTitle(u8 *);
extern void *GAME_DATA_GetSaveControl(struct Big *);
extern void *func_0200C0F0(void *);
extern void func_0200C1B0(struct Blk34 *,u32);
extern void *func_020056A0(u32,u32,u32);
extern int func_02005654(int,int);
extern void GFL_USE_CancelChangeAndPlayBgm(u32,u16);
extern void func_02034F84(u32);
extern void MB_COMM_SYS_VBlank(void);
extern void MB_COMM_SYS_VBlankRefreshBg(void);
extern void MB_COMM_SYS_VBlankRefreshBgStandalone(void);
extern struct Counter gMbParentUi;
void MB_COMM_SYS_Init(u8 *p) {
 p[0x25]=0;
 ((struct Obj00057 *)p)->f20=0;
 p[0x28]=**(u8 * *)&((struct Obj00057 *)p)->f8;
 MB_COMM_SYS_InitDisplay(p);
 MB_COMM_SYS_LoadGraphics(p);
 if(!p[0x28]) ((struct Obj00057 *)p)->f68=MB_UTIL_MSG_Create(((struct Obj00057 *)p)->f0,5,5,72,0,0);
 else ((struct Obj00057 *)p)->f68=MB_UTIL_MSG_Create(((struct Obj00057 *)p)->f0,1,1,72,0,1);
 ((struct Obj00057 *)p)->fC=MB_COMM_SYS_CreateNetState(((struct Obj00057 *)p)->f0);
 ((struct Obj00057 *)p)->f2C=0;
 ((struct Obj00057 *)p)->f60=0;
 MB_COMM_SYS_DrawTitle(p);
 if(!p[0x28]) {
  ((struct Obj00057 *)p)->f4C=func_0200C0F0(GAME_DATA_GetSaveControl(*(struct Big * *)&((struct Obj22273 *)(*(u8 * *)&((struct Obj00057 *)p)->f8))->f4));
  func_0200C1B0(*(struct Blk34 * *)&((struct Obj00057 *)p)->f4C,4);
 } else {
  *(u32 *)&((struct Obj00057 *)p)->f4C=0;
  *(u16 *)(((u8 *)&gMbParentUi)+2)=0;
 }
 ((struct Obj00057 *)p)->f4=func_020056A0((u32)MB_COMM_SYS_VBlank,(u32)p,8);
 if(!p[0x28]) func_02005654((int)MB_COMM_SYS_VBlankRefreshBg,0);
 else { func_02005654((int)MB_COMM_SYS_VBlankRefreshBgStandalone,0); GFL_USE_CancelChangeAndPlayBgm(1154,0xffff); }
 ((struct Obj00057 *)p)->f1C=0;
 ((struct Obj00057 *)p)->f44=0;
 ((struct Obj00057 *)p)->f48=0;
 ((struct Obj00057 *)p)->f38=0;
 ((struct Obj00057 *)p)->f3A=0;
 ((struct Obj00057 *)p)->f3C=0;
 func_02034F84(16);
}
