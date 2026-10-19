/*
 * function: SODATEYA_SyncPartyAfterDeposit
 * address:  0x021C38DC
 * packet:   pkt_021C38DC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * 
 * Blocking site: the bl to GAME_DATA_GetPerapVoiceSave at +000C of this function.
 * 
 * no listing carries a func_ label at this address -- disasm.py classified the bytes as data in every overlay whose window holds it -- and the only branches to it are these ov021 call sites, so the `label` class has no traced entry point to read and a region hint cannot invent one.  Filing a source for the TARGET (rule 10) would attest every caller that needs it, with no change here.
 * 
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetPerapVoiceSave  0x02012F98  thumb
 *   func_02007C34  0x02007C34  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 func_02007C34(u32, u32);
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Sub02007AC8Entry;
extern struct Sub02007AC8Entry *GAME_DATA_GetPerapVoiceSave(void *p);
extern void *FIELDMAP_GetGameSystem(void *p);

int SODATEYA_SyncPartyAfterDeposit(u32 a, u32 b)
{
return func_02007C34((u32)GAME_DATA_GetPerapVoiceSave((void *)GAMESYSTEM_GetGameData((const struct Ctx *)FIELDMAP_GetGameSystem((void *)a))), b);
}

