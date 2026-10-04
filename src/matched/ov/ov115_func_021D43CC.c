/*
 * function: func_021D43CC
 * address: 0x021D43CC
 * packet: pkt_ov115_021D43CC
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_020221A4 0x020221A4 thumb
 *   func_021D5C70 0x021D5C70 thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D5D5C 0x021D5D5C thumb ov115
 *   func_02156C84 0x02156C84 thumb ov009
 *   func_02012DD0 0x02012DD0 thumb
 *   func_02156C98 0x02156C98 thumb ov009
 *   func_021D4360 0x021D4360 thumb ov115
 */
#include "../include/Obj22588.h"
typedef unsigned char u8; typedef unsigned int u32;
extern u32 func_020221A4(void); extern int func_021D5C70(int); extern void func_021D426C(u8 *,u32); extern void *func_021D5D5C(u8 *,int,int,int);
extern unsigned char func_02156C84(void); extern int func_02012DD0(u8 *); extern void func_02156C98(int); extern void func_021D4360(u8 *);
void func_021D43CC(u8 *p) { int r; if(func_02156C84()) { r=func_02012DD0(*(u8 * *)&((struct Obj22588 *)p)->f44); switch(r) { case 0: case 1: return; default: func_02156C98(r); break; } } func_021D4360(p); }
