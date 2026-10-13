/*
 * function: func_021D8168
 * address: 0x021D8168
 * packet: pkt_ov116_021D8168
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_MENU_ProcessYesNo 0x0201FEBC thumb
 */
#include "../include/Obj10343.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BMP_MENU_ProcessYesNo(u8 *);
u32 func_021D8168(u8 *p) { u32 result=-2; if(*(u8 * *)&((struct Obj10343 *)p)->f980!=0) { result=BMP_MENU_ProcessYesNo(*(u8 * *)&((struct Obj10343 *)p)->f980); if(result!=-1) *(u32 *)&((struct Obj10343 *)p)->f980=0; } return result; }
