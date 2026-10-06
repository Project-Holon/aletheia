/*
 * function: func_021F6D90
 * address: 0x021F6D90
 * packet: pkt_ov215_021F6D90
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02015EB0 0x02015EB0 thumb
 *   func_02015F50 0x02015F50 thumb
 */
#include "../include/Obj14713.h"
typedef unsigned char u8;
struct McssFade;
extern void func_02015EB0(void *);
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_02015F50(struct McssFade *w, u32 cur, u32 target, s32 step, u32 e);
void func_021F6D90(char *p){func_02015EB0(((struct Obj14713 *)p)->f34);func_02015F50(*(struct McssFade * *)&((struct Obj14713 *)p)->f34,16,0,2,32767);}
