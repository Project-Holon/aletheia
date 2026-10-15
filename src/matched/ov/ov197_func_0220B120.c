/*
 * function: B_BAG_MAIN_InitWindows
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
 *   B_BAG_MAIN_CreateWindows 0x0220B150 thumb ov197
 */
#include "../include/Obj14542.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8);
extern void B_BAG_MAIN_CreateWindows(char *,u8);
void B_BAG_MAIN_InitWindows(char *p) { ((struct Obj14542 *)p)->f24=BMP_WIN_Create(4,1,19,30,4,12,1); B_BAG_MAIN_CreateWindows(p,((struct Obj14542 *)p)->f532); }
