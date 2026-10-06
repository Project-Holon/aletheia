/*
 * function: func_021F6D58
 * address: 0x021F6D58
 * packet: pkt_ov215_021F6D58
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02015E04 0x02015E04 thumb
 *   func_02015F50 0x02015F50 thumb
 */
#include "../include/Obj14712.h"
typedef unsigned char u8;
struct McssFade;
extern void func_02015E04(void *);
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
void func_021F6D58(char *p){func_02015E04(((struct Obj14712 *)p)->f34);func_02015F50(*(struct McssFade * *)&((struct Obj14712 *)p)->f34,0,16,0,32767);}
