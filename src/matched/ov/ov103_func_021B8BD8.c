/*
 * function: func_021B8BD8
 * address: 0x021B8BD8
 * packet: pkt_ov103_021B8BD8
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes follow compiled code.
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039338 0x02039338 arm
 */
#include "../include/Obj22211.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *func_020399A8(void);
extern u16 func_02039338(void);
void func_021B8BD8(u32 a, u32 b, u32 c, u8 *p, struct Entry *e) { if(e == func_020399A8()) { if(a != func_02039338()) ((struct Obj22211 *)p)->f290=1; } }
