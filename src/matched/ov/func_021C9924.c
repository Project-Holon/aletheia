/*
 * function: BSUBWAY_SCR_ClearWorkPtr
 * address:  0x021C9924
 * packet:   pkt_021C9924
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * 
 * Blocking site: the bl to GAME_DATA_SetCurrentEvent at +0008 of this function.
 * 
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_SetCurrentEvent  0x02012EE4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern char *GAME_DATA_SetCurrentEvent(char *base, int v);

int BSUBWAY_SCR_ClearWorkPtr(u32 a)
{
return (int)GAME_DATA_SetCurrentEvent((char *)GAMESYSTEM_GetGameData((const struct Ctx *)a), 0);
}

