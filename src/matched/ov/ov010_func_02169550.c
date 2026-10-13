/*
 * function: FIELD_G3D_MAP_ClearModelRes
 * address: 0x02169550
 * packet: pkt_ov010_02169550
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02046C9C 0x02046C9C arm
 */
#include "../include/Obj00306.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Rec;
extern void func_02046C9C(struct Rec *rec, u32 mode, u32 value);
void FIELD_G3D_MAP_ClearModelRes(char *p) { func_02046C9C(((struct Obj00306 *)p)->f84, 1, 0); }
