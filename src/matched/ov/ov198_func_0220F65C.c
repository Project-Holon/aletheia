/*
 * function: func_0220F65C
 * address: 0x0220F65C
 * packet: pkt_ov198_0220F65C
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6B4 0x0201C6B4 thumb
 *   WIPE_SYS_Start 0x0202208C thumb
 */
#include "../include/Obj14564.h"
#include "../include/Obj25232.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys;
extern u32 func_0201C6B4(const struct PrintSys *);
extern void WIPE_SYS_Start(void *,u32,u32,u32,u32,u32,u32);
int func_0220F65C(u8 *p) { if(func_0201C6B4(*(const struct PrintSys * *)&((struct Obj14564 *)p)->f1EAC)==1){WIPE_SYS_Start((void *)4,1,1,0,6,1,((struct Obj25232 *)(*(u8 * *)&((struct Obj14564 *)p)->f0))->f10);return 2;}return 1; }
