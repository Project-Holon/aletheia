/*
 * function: func_021F54A0
 * address: 0x021F54A0
 * packet: pkt_ov075_021F54A0
 * region: ov075
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0208068C 0x0208068C arm
 *   func_020056A0 0x020056A0 thumb
 *   func_021F54C0 0x021F54C0 thumb ov075
 */
#include "../include/Obj20793.h"
typedef unsigned int u32;
extern void func_0208068C(int);
extern void *func_020056A0(u32,u32,u32);
extern void func_021F54C0(void *,int *);
void func_021F54A0(char *p) { ((struct Obj20793 *)p)->f10=0; func_0208068C(8); func_020056A0((u32)func_021F54C0,(u32)(p+16),0); }
