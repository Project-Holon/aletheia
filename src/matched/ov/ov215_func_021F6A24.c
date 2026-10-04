/*
 * function: func_021F6A24
 * address: 0x021F6A24
 * packet: pkt_ov215_021F6A24
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * trailing: existing follower unit 021F6A3C/6A44.
 * symbols:
 *   func_02014D2C 0x02014D2C thumb
 *   func_021F6F24 0x021F6F24 thumb ov215
 *   func_021F6EE4 0x021F6EE4 thumb ov215
 */
#include "../include/Obj06708.h"
struct McssSys;
extern void func_02014D2C(struct McssSys *);
extern void func_021F6F24(char *);
extern void func_021F6EE4(char *);
void func_021F6A24(char *p){func_02014D2C(*(struct McssSys * *)&((struct Obj06708 *)p)->f30);func_021F6F24(p);func_021F6EE4(*(char * *)&((struct Obj06708 *)p)->f44);}
