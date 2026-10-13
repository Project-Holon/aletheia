/*
 * function: func_021DBEE4
 * address: 0x021DBEE4
 * packet: pkt_ov121_021DBEE4
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_Delete 0x020437AC arm
 *   MI_CpuFill8 0x02082BCC arm
 */
#include "../include/Obj13958.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Obj020437AC; extern void BMP_Delete(struct Obj020437AC *);
extern void MI_CpuFill8(void *,int,int);
void func_021DBEE4(u32 p) { if (((struct Obj13958 *)p)->f0) { BMP_Delete(*(struct Obj020437AC * *)&((struct Obj13958 *)p)->fD0); MI_CpuFill8((void *)p,0,220); } }
