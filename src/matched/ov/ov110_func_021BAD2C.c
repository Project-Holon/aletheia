/*
 * function: PMS_INPUT_VIEW_LoadBgPalette
 * address: 0x021BAD2C
 * packet: pkt_ov110_021BAD2C
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ARC_UTIL_UploadBgPaletteAddFromHandleExt 0x020499D4 arm
 */
#include "../include/Obj10273.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 ARC_UTIL_UploadBgPaletteAddFromHandleExt(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
void PMS_INPUT_VIEW_LoadBgPalette(u8 *p,int v) { int id,x; if(v) { id=29; x=96; } else { id=28; x=0; } ARC_UTIL_UploadBgPaletteAddFromHandleExt(((struct Obj10273 *)p)->f8C,id,3,0,x,0,0,42); ((struct Obj10273 *)p)->f84=1; ((struct Obj10273 *)p)->f88=v; }
