/*
 * function: INTRUDE_SUBDISP_ScriptApplyCommState
 * address:  0x0217CF88
 * packet:   pkt_ov018_0217CF88
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   INTRUDE_FIELD_ResetExtraAreaCount  0x0217BBCC  thumb  ov018
 *   INTRUDE_FIELD_AddAreaMaps  0x0217BBD8  thumb  ov018
 *   INTRUDE_FIELD_AddAreaMapCount  0x0217BC94  thumb  ov018
 *   INTRUDE_FIELD_AddMarkerMmdls  0x0217C194  thumb  ov018
 */

struct Ctx;

extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
typedef unsigned int   u32;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
typedef unsigned char  u8;
extern u32 func_02026454(void *obj);
extern u32 func_02026474(void *obj);
extern void INTRUDE_FIELD_ResetExtraAreaCount(int a, int b, char *p);
extern void INTRUDE_FIELD_AddAreaMaps(u8 *a, int b, u8 *c);
extern void INTRUDE_FIELD_AddAreaMapCount(int a, int n);
extern void INTRUDE_FIELD_AddMarkerMmdls();

int INTRUDE_SUBDISP_ScriptApplyCommState(int a0, int a1)
{
    void *w;
    void *c;
    int h;
    int v;

    w = SCRCMD_WORK_GetGameSystem((void *)a1);
    GAMESYSTEM_GetGameData((const struct Ctx *)w);
    c = GAMESYSTEM_GetFieldMap((void *)w);
    h = GAMESYSTEM_GetGameComm(w);
    v = 0;
    if (func_02026454((void *)h) == 2)
        v = func_02026474((void *)h);
    if (v != 0) {
        INTRUDE_FIELD_ResetExtraAreaCount((int)c, (int)w, (char *)v);
        INTRUDE_FIELD_AddAreaMaps((u8 *)c, (int)w, (u8 *)v);
    } else {
        INTRUDE_FIELD_AddAreaMapCount((int)c, 1);
    }
    INTRUDE_FIELD_AddMarkerMmdls(c);
    return 0;
}
