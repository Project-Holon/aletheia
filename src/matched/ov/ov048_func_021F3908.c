/*
 * function: func_021F3908
 * address: 0x021F3908
 * packet: pkt_ov048_021F3908
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAME_DATA_GetSaveControlWork 0x02012EC0 thumb
 *   func_0200C0E8 0x0200C0E8 thumb
 *   func_0200C3B0 0x0200C3B0 thumb
 */
#include "../include/Obj00377.h"
typedef unsigned short u16;
struct Big;
struct Blk34;
extern void *GAME_DATA_GetSaveControlWork(struct Big *p);
extern void *func_0200C0E8(void *p);
extern u16 func_0200C3B0(struct Blk34 *p);
void func_021F3908(int *p) { if(p[4]==0) { ((struct Obj00377 *)p)->f64=func_0200C3B0(func_0200C0E8(GAME_DATA_GetSaveControlWork((void *)p[2]))); p[4]=1; } }
