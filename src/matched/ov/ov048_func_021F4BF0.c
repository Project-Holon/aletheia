/*
 * function: GIMMICK_OBJ_ELBOARD_StopLine
 * address: 0x021F4BF0
 * packet: pkt_ov048_021F4BF0
 * region: ov048
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_DisableObjectAnime 0x020477D4 arm
 *   G3D_SYSTEM_ResetObjectAnimeFrame 0x02047804 arm
 */
#include "../include/Obj05134.h"
typedef unsigned int   u32;
struct AnmCtl;
struct Owner;
extern int G3D_SYSTEM_DisableObjectAnime(struct Owner *owner, u32 index);
typedef unsigned short u16;
extern u32 G3D_SYSTEM_ResetObjectAnimeFrame(struct AnmCtl *c, u16 idx);
void GIMMICK_OBJ_ELBOARD_StopLine(int *p) { if(p[1]==1) { p[1]=0; G3D_SYSTEM_DisableObjectAnime((struct Owner *)p[4],((struct Obj05134 *)p)->f14); G3D_SYSTEM_ResetObjectAnimeFrame((struct AnmCtl *)p[4],((struct Obj05134 *)p)->f14); } }
