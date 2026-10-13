/*
 * function: INTRUDE_SUBDISP_UpdateBgPalette
 * address: 0x0217EF44
 * packet: pkt_ov018_0217EF44
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   INTRUDE_SUBDISP_SetBgPalette 0x0217EF70 thumb ov018
 * interface: r1 holds p[0xd8] at 0x0217EF64 and EF70 reads it.
 */
#include "../include/Obj03092.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void INTRUDE_SUBDISP_SetBgPalette(int *p, int x);
void INTRUDE_SUBDISP_UpdateBgPalette(u8 *p)
{
    GAMESYSTEM_GetGameData(((struct Obj03092 *)p)->f0);
    GAMESYSTEM_GetGameComm(((struct Obj03092 *)p)->f0);
    if (p[0xd8] != p[0x105]) INTRUDE_SUBDISP_SetBgPalette((int *)p, p[0xd8]);
}
