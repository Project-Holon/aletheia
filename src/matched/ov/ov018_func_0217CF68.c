/*
 * function: INTRUDE_SUBDISP_ScriptResetFieldState
 * address: 0x0217CF68
 * packet: pkt_ov018_0217CF68
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   SCRCMD_WORK_GetGameSystem 0x0215A5DC thumb ov010
 *   GAMESYSTEM_GetFieldMap 0x0201210C thumb
 *   GAMESYSTEM_GetGameComm 0x02012138 thumb
 *   INTRUDE_FIELD_AddAreaMmdls 0x0217BF84 thumb ov018
 */
extern void *SCRCMD_WORK_GetGameSystem(void *);
typedef unsigned int   u32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
extern void INTRUDE_FIELD_AddAreaMmdls(int a);
int INTRUDE_SUBDISP_ScriptResetFieldState(void *unused, void *p)
{
    void *sys;
    void *obj;
    sys = SCRCMD_WORK_GetGameSystem(p);
    obj = GAMESYSTEM_GetFieldMap(sys);
    GAMESYSTEM_GetGameComm(sys);
    INTRUDE_FIELD_AddAreaMmdls((int)obj);
    return 0;
}
