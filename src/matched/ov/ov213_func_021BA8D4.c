/*
 * function: func_021BA8D4
 * address: 0x021BA8D4
 * packet: pkt_ov213_021BA8D4
 * region: ov213
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * EXACT* tail: two zero alignment bytes after the function.
 * symbols:
 *   PARTICLE_DeleteSystem 0x02050DB8 arm
 *   PARTICLE_ExitManager 0x02050ED4 arm
 */
#include "../include/Obj10931.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern void PARTICLE_DeleteSystem(u8 *);
extern void PARTICLE_ExitManager(void);
void func_021BA8D4(char *p) { if(*(u8 * *)&((struct Obj10931 *)p)->f10) PARTICLE_DeleteSystem(*(u8 * *)&((struct Obj10931 *)p)->f10); PARTICLE_ExitManager(); }
