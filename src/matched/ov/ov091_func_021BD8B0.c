/*
 * function: PLIST_BATTLE_StartEffect
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
 *   POKELIST_ShutdownBgPlane0 0x021B7034 thumb ov091
 *   POKELIST_SetupLight 0x021B6F28 thumb ov091
 *   PLIST_DEMO_CreateParticles 0x021BDABC thumb ov091
 */
#include "../include/Obj00009.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void func_02040588(unsigned char which, unsigned char enable);
extern void POKELIST_ShutdownBgPlane0(char *);
extern void POKELIST_SetupLight(char *);
extern void PLIST_DEMO_CreateParticles(u8 *);
void PLIST_BATTLE_StartEffect(char *p) { ((struct Obj00009 *)p)->f268=0; ((struct Obj00009 *)p)->f26C=0; ((struct Obj00009 *)p)->f270=0; func_02040588(0,0); POKELIST_ShutdownBgPlane0(p); POKELIST_SetupLight(p); PLIST_DEMO_CreateParticles((u8 *)p); p[12]=15; }
