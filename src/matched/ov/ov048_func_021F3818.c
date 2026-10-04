/*
 * function: func_021F3818
 * address: 0x021F3818
 * packet: pkt_ov048_021F3818
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200C0F0 0x0200C0F0 thumb
 *   func_0200C3B8 0x0200C3B8 thumb
 */
#include "../include/Obj00377.h"
typedef unsigned short u16;
struct Big;
struct Blk34;
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C0F0(void *p);
extern void func_0200C3B8(struct Blk34 *p, u16 v);
void func_021F3818(char *p) { func_0200C3B8(func_0200C0F0(func_02012EBC(((struct Obj00377 *)p)->f8)), ((struct Obj00377 *)p)->f64); }
