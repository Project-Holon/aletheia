/*
 * function: SCRCMD_SCREENEFFECTS_CheckScriptEffectDone
 * address:  0x021B2874
 * packet:   pkt_021B2874
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Emitted from the ov021 instruction shape.
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetScriptEffectBusy  0x02189A24  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u32 FIELDMAP_GetScriptEffectBusy(u8 *p);

int SCRCMD_SCREENEFFECTS_CheckScriptEffectDone(u32 a, u32 b, u32 c, u32 d)
{
if (FIELDMAP_GetScriptEffectBusy(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b))) != 1) {
    return 1;
}
return 0;
}

