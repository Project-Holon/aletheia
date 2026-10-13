/*
 * function: func_021BA8BC
 * address: 0x021BA8BC
 * packet: pkt_ov213_021BA8BC
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   PARTICLE_KillAllEffects 0x02051620 arm
 *   func_02050DB8 0x02050DB8 arm
 */
#include "../include/Obj10930.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void PARTICLE_KillAllEffects(u8 *);
extern void func_02050DB8(u8 *);
void func_021BA8BC(char *p, int object) { PARTICLE_KillAllEffects(*(u8 * *)&((struct Obj10930 *)p)->f10); func_02050DB8(*(u8 * *)&((struct Obj10930 *)p)->f10); *(u32 *)&((struct Obj10930 *)p)->f10=0; }
