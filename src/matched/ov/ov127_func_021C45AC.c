/*
 * function: func_021C45AC
 * address: 0x021C45AC
 * packet: pkt_ov127_021C45AC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: 2-byte zero alignment padding.
 * symbols:
 *   CLACT_RegisterCellAnim 0x0204AF28 arm
 */
#include "../include/Obj10466.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int     s32;
extern s32 CLACT_RegisterCellAnim(void *owner, u32 first, u32 second, u32 mode);
void func_021C45AC(u8 *p,u32 heap) { int i; for(i=0;i<16;i++) *(u32 *)(p+i*20+392)=CLACT_RegisterCellAnim(((struct Obj10466 *)p)->f2FC,i*2+17,i*2+18,(u16)heap); }
