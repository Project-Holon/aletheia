/*
 * function: func_0220B120
 * address: 0x0220B120
 * packet: pkt_ov197_0220B120
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_0220B150 0x0220B150 thumb ov197
 */
#include "../include/Obj14542.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void func_0220B150(char *,u8);
void func_0220B120(char *p) { ((struct Obj14542 *)p)->f24=BMP_WIN_Create(4,1,19,30,4,12,1); func_0220B150(p,((struct Obj14542 *)p)->f532); }
