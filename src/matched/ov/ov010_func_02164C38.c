/*
 * function: func_02164C38, func_02164C5C
 * address: 0x02164C38
 * packet: pkt_ov010_02164C38
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * unit: yes
 * symbols:
 *   func_020307B0 0x020307B0 arm
 *   func_0200FB24 0x0200FB24 thumb
 *   func_0200FBA0 0x0200FBA0 thumb
 */
#include "../include/Obj18983.h"
#include "../include/Obj18984.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_020307B0(void *p);
extern u32 func_0200FB24(void);
extern void func_0200FBA0(void);
int func_02164C38(int a,int b,u8 *p) { if(((struct Obj18983 *)p)->f4==0) { func_020307B0(p); if(func_0200FB24()) func_0200FBA0(); return 1; } return 0; }
void func_02164C5C(u8 *p) { ((struct Obj18984 *)p)->f4=0; }
