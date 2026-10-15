/*
 * function: NAMEIN_GRAPHIC_RevertChar
 * address: 0x021F22AC
 * packet: pkt_ov194_021F22AC
 * region: ov194
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   NAMEIN_GRAPHIC_NextPairChar 0x021F4F7C thumb ov194
 *   NAMEIN_GRAPHIC_Backspace 0x021F2150 thumb ov194
 *   NAMEIN_GRAPHIC_AppendChar 0x021F2190 thumb ov194
 */
#include "../include/Obj10807.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int NAMEIN_GRAPHIC_NextPairChar(char *,const u16 *,u16 *),NAMEIN_GRAPHIC_Backspace(u8 *),NAMEIN_GRAPHIC_AppendChar(char *,u16);
int NAMEIN_GRAPHIC_RevertChar(char *p) { u16 v;if(((struct Obj10807 *)p)->f1E!=0 && NAMEIN_GRAPHIC_NextPairChar(*(char * *)&((struct Obj10807 *)p)->f90,(u16 *)((u32)p+(((struct Obj10807 *)p)->f1E-1)*2),&v)) { NAMEIN_GRAPHIC_Backspace((u8 *)p);NAMEIN_GRAPHIC_AppendChar(p,v);return 1; }return 0; }
