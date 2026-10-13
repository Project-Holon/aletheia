/*
 * function: GIMMICK_OBJ_ELBOARD_StartLine
 * address: 0x021F4B54
 * packet: pkt_ov048_021F4B54
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   G3D_SYSTEM_EnableObjectAnime 0x020477A4 arm
 *   G3D_SYSTEM_ResetObjectAnimeFrame 0x02047804 arm
 */
#include "../include/Obj03648.h"
typedef unsigned int   u32;
struct G3dSys;
extern u32 G3D_SYSTEM_EnableObjectAnime(struct G3dSys *sys, u32 idx);
struct AnmCtl;
typedef unsigned short u16;
extern u32 G3D_SYSTEM_ResetObjectAnimeFrame(struct AnmCtl *c, u16 idx);
void GIMMICK_OBJ_ELBOARD_StartLine(int *p) { if(p[1]!=1) { p[1]=1; p[2]=0; p[6]=0; G3D_SYSTEM_EnableObjectAnime((void *)p[4],((struct Obj03648 *)p)->f14); G3D_SYSTEM_ResetObjectAnimeFrame((struct AnmCtl *)p[4],((struct Obj03648 *)p)->f14); } }
