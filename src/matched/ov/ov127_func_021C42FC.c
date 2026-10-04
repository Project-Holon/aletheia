/*
 * function: func_021C42FC
 * address: 0x021C42FC
 * packet: pkt_ov127_021C42FC
 * region: ov127
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing 2-byte alignment padding only.
 * symbols:
 *   func_0204AF28 0x0204AF28 arm
 */
#include "../include/Obj23022.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int     s32;
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
void func_021C42FC(char *p,u32 unused,u32 heap) { int i; for(i=16;i<18;i++) { *(u32 *)((u32)p+(u32)i*20+0x188)=func_0204AF28(((struct Obj23022 *)p)->f2F8,(i-16)*2,(i-16)*2+1,(u16)heap); } }
