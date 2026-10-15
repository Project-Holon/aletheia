/*
 * function: PSEL_DeleteSelectAnime
 * address: 0x021B9A6C
 * packet: pkt_ov223_021B9A6C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   G3D_UTIL_RemoveUnit 0x020480E4 arm
 *   PSEL_DeleteRecords 0x021B9600 thumb ov223
 *   ICA_ANIME_Delete 0x02011558 thumb
 */
#include "../include/Obj05571.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;struct IcaAnime;extern void G3D_UTIL_RemoveUnit(struct Ctx *,u32);extern void PSEL_DeleteRecords(void *);extern void ICA_ANIME_Delete(struct IcaAnime *);
void PSEL_DeleteSelectAnime(char *p) {G3D_UTIL_RemoveUnit(*(struct Ctx * *)&((struct Obj05571 *)p)->f28,((struct Obj05571 *)p)->f2E);PSEL_DeleteRecords(((struct Obj05571 *)p)->f3C);((struct Obj05571 *)p)->f3A=0;ICA_ANIME_Delete(*(struct IcaAnime * *)&((struct Obj05571 *)p)->f40);}
