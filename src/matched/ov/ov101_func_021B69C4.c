/*
 * function: IRC_COMPATIBLE_ProcExit
 * address: 0x021B69C4
 * packet: pkt_ov101_021B69C4
 * region: ov101
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_USE_PopBgm 0x02005E9C thumb
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   func_021B6148 0x021B6148 thumb ov101
 *   IRC_COMPATIBLE_StepRunnerExit 0x021B6C08 thumb ov101
 *   func_020307B0 0x020307B0 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj13717.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int GFL_USE_PopBgm(void);
extern void GFL_USE_SetBgmPlayerParam(void *);
extern void func_021B6148(void *);
extern void IRC_COMPATIBLE_StepRunnerExit(u8 *);
extern u32 func_020307B0(void *p);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(u32 heap);
int IRC_COMPATIBLE_ProcExit(int a,int b,int c,u8 *d) {
 GFL_USE_PopBgm(); GFL_USE_SetBgmPlayerParam(0); func_021B6148(((struct Obj13717 *)d)->f0); IRC_COMPATIBLE_StepRunnerExit(d+4); func_020307B0(((struct Obj13717 *)d)->f3C); func_020315D4((void *)a); func_020306F0(58); return 1;
}
