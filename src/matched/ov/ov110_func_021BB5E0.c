/*
 * function: func_021BB5E0
 * address: 0x021BB5E0
 * packet: pkt_ov110_021BB5E0
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   BMP_WIN_MakeScreen 0x02045374 arm
 *   func_020409B4 0x020409B4 arm
 *   func_02040618 0x02040618 arm
 */
#include "../include/Obj22360.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 BMP_WIN_Create(u32,u32,u32,u32,u8,u8,u8); extern void BMP_WIN_MakeScreen(u32); extern void func_020409B4(u32); extern void func_02040618(u32,u32,u32);
void func_021BB5E0(u8 *p) { u32 win; win=BMP_WIN_Create(6,1,1,30,22,0,1); BMP_WIN_MakeScreen(win); func_020409B4(6); func_02040618(6,3,-192); ((struct Obj22360 *)p)->f98=win; }
