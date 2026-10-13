/*
 * function: func_021D9A58
 * address: 0x021D9A58
 * packet: pkt_ov121_021D9A58
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BMP_WIN_ClearScreen 0x020456F8 arm
 */
#include "../include/Obj22875.h"
typedef unsigned char u8;
struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
void func_021D9A58(u8 *p) { BMP_WIN_ClearScreen(((struct Obj22875 *)p)->fC); }
