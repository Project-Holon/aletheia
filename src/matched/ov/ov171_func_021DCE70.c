/*
 * function: DENDOU_VIEW_RunState
 * address: 0x021DCE70
 * packet: pkt_ov171_021DCE70
 * region: ov171
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   sStateHandlers 0x021DEB5C data a4
 *   DENDOU_VIEW_UpdateActors 0x021DE030 thumb ov171
 *   DENDOU_VIEW_FlushWindows 0x021DD8DC thumb ov171
 */
#include "../include/Obj14286.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u8 sStateHandlers[];
extern void DENDOU_VIEW_UpdateActors(u8*);
extern void DENDOU_VIEW_FlushWindows(char*);
int DENDOU_VIEW_RunState(u8*p){typedef int(*Fn)(u8*);((struct Obj14286 *)p)->fC6C=(*(Fn*)((u32)sStateHandlers+*(u32*)(p+0xc6c)*4))(p);if(((struct Obj14286 *)p)->fC6C==11)return 0;DENDOU_VIEW_UpdateActors(p);DENDOU_VIEW_FlushWindows((char*)p);return 1;}
