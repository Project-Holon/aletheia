/*
 * function: MYSTERY_UTIL_DeleteDetailWindow
 * address: 0x021DA698
 * packet: pkt_ov121_021DA698
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CLACT_SetActorDrawEnable 0x0204B3DC arm
 *   MYSTERY_UTIL_ClearWindowList 0x021DA2A8 thumb ov121
 *   MYSTERY_UTIL_DeleteWindowList 0x021DA280 thumb ov121
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_020307B0 0x020307B0 arm
 */
#include "../include/Obj03786.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);
extern void MYSTERY_UTIL_ClearWindowList(u8 *);
extern void MYSTERY_UTIL_DeleteWindowList(u8 *);
extern void BG_SYS_PushTile(u32 index);
extern u32 func_020307B0(void *p);
void MYSTERY_UTIL_DeleteDetailWindow(u8 *p) { if(*(u32 * *)&((struct Obj03786 *)p)->f60 && ((struct Obj03786 *)p)->f8!=3) **(u32 * *)&((struct Obj03786 *)p)->f60=((struct Obj03786 *)p)->f8; CLACT_SetActorDrawEnable(((struct Obj03786 *)p)->f4,0); MYSTERY_UTIL_ClearWindowList(*(u8 * *)&((struct Obj03786 *)p)->f0); MYSTERY_UTIL_DeleteWindowList(*(u8 * *)&((struct Obj03786 *)p)->f0); BG_SYS_PushTile((u8)(((struct Obj03786 *)p)->f28)); func_020307B0(p); }
