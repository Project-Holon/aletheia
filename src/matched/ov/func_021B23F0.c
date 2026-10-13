/*
 * function: SCRCMD_GIMMICK40_SetFlag
 * address:  0x021B23F0
 * packet:   pkt_021B23F0
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
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GIMMICK40_SetFlag  0x021F37A4  thumb  ov040
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
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void GIMMICK40_SetFlag(u8 *p);

int SCRCMD_GIMMICK40_SetFlag(u32 a, u32 b, u32 c, u32 d)
{
SCRCMD_WORK_GetScriptWork((void *)b);
GIMMICK40_SetFlag(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem((void *)b)));
return 0;
}

