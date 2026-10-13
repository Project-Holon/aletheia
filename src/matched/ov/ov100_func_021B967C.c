/*
 * function: IRCBATTLEMATCH_SetPaletteFade
 * address: 0x021B967C
 * packet: pkt_ov100_021B967C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MI_CpuCopy8 0x02082D44 arm
 *   IRCBATTLEMATCH_BlendBgPalette 0x021B95F0 thumb ov100
 *   func_0207E468 0x0207E468 arm
 */
#include "../include/Obj13705.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern void MI_CpuCopy8(const void *,void *,u32);
extern int IRCBATTLEMATCH_BlendBgPalette(int,int,int);
extern void func_0207E468(int,int,int);
void IRCBATTLEMATCH_SetPaletteFade(int a,int b){if(b){MI_CpuCopy8((void *)0x05000400,((struct Obj13705 *)a)->fCB4,0x200);IRCBATTLEMATCH_BlendBgPalette(a,1,9);}else{func_0207E468(*(int *)&((struct Obj13705 *)a)->fCB4,0,0x120);}}
