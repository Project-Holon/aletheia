/*
 * function: C_GEAR_IsIdleForInput
 * address: 0x021F0D48
 * packet: pkt_ov029_021F0D48
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * 2026-10-04 (wD2 lane 09): bytes are identical; only the relocation at +0024 is open.
 * Filed the callee as matched ov021_func_02189A48.c (EXACT, returns *(u32 *)(p+0x144)).
 * The tool still reports no independent witness for 02189A48 (3 overlays overlap).
 * Needs the integrator to regenerate the witness index, nothing left in the source.
 * blocker: FIELDMAP_GetSubscreenBusy, ov021 owner leaf, lacks an outside code witness.
 * interface: 0201210C returns the full word at +0x20; it is passed directly
 * to 02189A48, whose ov021 body reads the full word at +0x144. No value lost.
 * symbols:
 *   WIPE_SYS_EndCheck 0x020221A4 thumb
 *   GXx_GetMasterBrightness_ 0x0207D55C arm
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   FIELDMAP_GetSubscreenBusy 0x02189A48 thumb ov021
 */
extern unsigned int WIPE_SYS_EndCheck(void);
typedef unsigned short u16;
struct Ctx;
extern int GXx_GetMasterBrightness_(volatile u16 *reg);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetSubscreenBusy(char *p);
int C_GEAR_IsIdleForInput(char *p)
{
    if (!WIPE_SYS_EndCheck()) return 0;
    if (GXx_GetMasterBrightness_((unsigned short *)0x0400106c)) return 0;
    if (!FIELDMAP_GetSubscreenBusy((char *)GAMESYSTEM_GetFieldMap(*(void **)(p + 0x1c)))) return 1;
    return 0;
}
