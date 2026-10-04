/*
 * function: func_021B9BA0
 * address: 0x021B9BA0
 * packet: pkt_ov070_021B9BA0
 * region: ov070
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02045CAC 0x02045CAC arm
 *   func_021BB6E0 0x021BB6E0 thumb ov070
 */
#include "../include/Obj01516.h"
typedef unsigned int   u32;
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_021BB6E0(int, unsigned *, unsigned, unsigned short, short, unsigned short);
void func_021B9BA0(char *p) { func_02045CAC((struct MsgBank *)(((struct Obj01516 *)p)->f51C), 0x87, (void *)(((struct Obj01516 *)p)->f524)); func_021BB6E0((int)p, (unsigned *)(p + 0x774), *(unsigned *)&((struct Obj01516 *)p)->f524, 0, 4, 0x3DC0); }
