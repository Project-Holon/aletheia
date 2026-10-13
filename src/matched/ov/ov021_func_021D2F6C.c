/*
 * function: SCRCMD_StartEffectAtPosition
 * address:  0x021D2F6C
 * packet:   pkt_ov021_021D2F6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   FIELD_GIMMICK_ARC_EFFECT_StartArcEffect  0x021F3970  thumb  ov064
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void *FIELD_GIMMICK_ARC_EFFECT_StartArcEffect(void *a, int *v, int *w, int c, int d);
extern void SCRIPT_SYS_CallEvent(void *a, void *b);

u32 SCRCMD_StartEffectAtPosition(u32 a, u32 b)
{
    int v[3];
    int w[3];
    void *s10;
    void *sc;
    void *s14;
    int s18;
    int s8;
    int s4;
    int r7;
    int r6;
    int r4;
    void *r;

    s10 = SCRCMD_WORK_GetScriptWork((void *)b);
    sc = SCRCMD_WORK_GetGameSystem((void *)b);
    s14 = GAMESYSTEM_GetFieldMap(sc);
    s18 = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    s8 = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    s4 = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r7 = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r6 = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r4 = (int)SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    r = FLDMMDL_SysSearchObjId(FIELDMAP_GetMmdlSys((void *)s14), s18);
    if (r != 0) {
        FLDMMDL_GetPos(r, (struct VecFx32 *)v);
    }
    w[0] = (s8 << 16) + 0x8000;
    w[1] = s4 << 15;
    w[2] = (r7 << 16) + 0x8000;
    r = FIELD_GIMMICK_ARC_EFFECT_StartArcEffect(sc, v, w, r6 << 15, r4);
    if (r == 0) {
        return 1;
    }
    SCRIPT_SYS_CallEvent(s10, r);
    return 1;
}
