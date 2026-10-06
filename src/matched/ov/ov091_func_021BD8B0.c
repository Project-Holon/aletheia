/*
 * function: func_021BD8B0
 * address: 0x021BD8B0
 * packet: pkt_ov091_021BD8B0
 * region: ov091
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02040588 0x02040588 arm
 *   func_021B7034 0x021B7034 thumb ov091
 *   func_021B6F28 0x021B6F28 thumb ov091
 *   func_021BDABC 0x021BDABC thumb ov091
 */
#include "../include/Obj00009.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_021B7034(char *);
extern void func_021B6F28(char *);
extern void func_021BDABC(u8 *);
void func_021BD8B0(char *p) { ((struct Obj00009 *)p)->f268=0; ((struct Obj00009 *)p)->f26C=0; ((struct Obj00009 *)p)->f270=0; func_02040588(0,0); func_021B7034(p); func_021B6F28(p); func_021BDABC((u8 *)p); p[12]=15; }
