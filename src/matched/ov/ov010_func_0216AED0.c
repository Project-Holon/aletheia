/*
 * function: SCRCMD_SYMBOL_GetMmdl
 * address: 0x0216AED0
 * packet: pkt_ov010_0216AED0
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetMmdlSys 0x02188C7C thumb ov021
 *   FLDMMDL_SysSearchObjId 0x0216DE94 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
extern void *FLDMMDL_SysSearchObjId(void *, u32);
void *SCRCMD_SYMBOL_GetMmdl(void *p, u32 id) { return FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(p))), id); }
