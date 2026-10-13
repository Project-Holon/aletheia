/*
 * function: func_02164C20
 * address: 0x02164C20
 * packet: pkt_ov010_02164C20
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   WIH_DWC_Delete 0x020103E4 thumb
 *   func_0203CEAC 0x0203CEAC arm
 *   func_02164C5C 0x02164C5C thumb ov010
 */
#include "../include/Obj18982.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void WIH_DWC_Delete(u8 *);
extern int func_0203CEAC(int a0);
extern void func_02164C5C(u8 *p);
int func_02164C20(int a,int b,u8 *p) { WIH_DWC_Delete(*(u8 * *)&((struct Obj18982 *)p)->f80); func_0203CEAC((int)func_02164C5C); return 1; }
