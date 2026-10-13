/*
 * function: func_021B9C58
 * address: 0x021B9C58
 * packet: pkt_ov223_021B9C58
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: a raw 10-byte row stride preserves muls instead of strength-reduced halfword indexing.
 * symbols:
 *   d_021BC792 0x021BC792 data a2
 *   ICA_ANIME_IncFrameLoop 0x02011590 thumb
 *   func_021BC52C 0x021BC52C thumb ov223
 *   ICA_ANIME_SetCameraStatus 0x02011B8C thumb
 */
#include "../include/Obj00738.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct IcaAnime;extern const u16 d_021BC792[];extern u32 ICA_ANIME_IncFrameLoop(struct IcaAnime *,int);extern void *func_021BC52C(void *);extern void ICA_ANIME_SetCameraStatus(void *,void *);
void func_021B9C58(char *p) {if(((struct Obj00738 *)p)->f4C!=*(const u16 *)((const u8 *)d_021BC792+((struct Obj00738 *)p)->f44*10)) {ICA_ANIME_IncFrameLoop(*(struct IcaAnime * *)&((struct Obj00738 *)p)->f40,2048);ICA_ANIME_SetCameraStatus(func_021BC52C(((struct Obj00738 *)p)->f14),((struct Obj00738 *)p)->f40);(((struct Obj00738 *)p)->f4C)++;}}
