/*
 * function: UNION_EFF_ExitAnimGroup
 * address: 0x0217F9BC
 * packet: pkt_ov019_0217F9BC
 * region: ov019
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   G3D_SYSTEM_FreeVramTexture 0x020470D0 arm
 *   G3D_SYSTEM_DeleteResource 0x02046EFC arm
 */
#include "../include/Obj05958.h"
typedef unsigned char u8;
typedef unsigned int u32;
struct Tagged;
extern int G3D_SYSTEM_FreeVramTexture(u32 *p);
extern void G3D_SYSTEM_DeleteResource(struct Tagged *p);
void UNION_EFF_ExitAnimGroup(char *p) { G3D_SYSTEM_FreeVramTexture(((struct Obj05958 *)p)->f14); G3D_SYSTEM_DeleteResource(((struct Obj05958 *)p)->f18); ((struct Obj05958 *)p)->f18=0; G3D_SYSTEM_DeleteResource(((struct Obj05958 *)p)->f14); ((struct Obj05958 *)p)->f14=0; }
