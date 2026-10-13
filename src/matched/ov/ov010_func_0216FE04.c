/*
 * function: WAZA_OSHIE_UploadPalette
 * address: 0x0216FE04
 * packet: pkt_ov010_0216FE04
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0207FA0C 0x0207FA0C arm
 *   DWCi_ScreenDC_FlushRange 0x020862F0 arm
 *   func_0207FA40 0x0207FA40 arm
 *   func_0207FADC 0x0207FADC arm
 */
#include "../include/Obj12410.h"
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_0207FA0C(void);
extern void DWCi_ScreenDC_FlushRange(void *,u32);
extern void func_0207FA40(void *,u32,u32);
extern void func_0207FADC(void);
void WAZA_OSHIE_UploadPalette(char *p,void *q) { u32 b,a; a=((struct Obj12410 *)p)->f10; b=(u16)((struct Obj12410 *)p)->f8*8; func_0207FA0C(); DWCi_ScreenDC_FlushRange(q,32); func_0207FA40(q,a+b,32); func_0207FADC(); }
