/*
 * function: SCRCMD_MMDL_StartOrbit
 * address:  0x0216A884
 * packet:   pkt_ov010_0216A884
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb  ov021
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_MMDL_OrbitEventMain  0x0216A8F0  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Desc;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
struct Ctx;
struct Orbit;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern int SCRCMD_MMDL_OrbitEventMain(void *unused, u32 *mode, struct Orbit *o);

int SCRCMD_MMDL_StartOrbit(int a0, int a1)
{
    void *l0;
    void *r4;
    int r6;
    struct Desc *r7;
    void *m;
    int *r5;

    SCRCMD_WORK_GetGameData((void *)a1);
    l0 = SCRCMD_WORK_GetScriptWork((void *)a1);
    r4 = SCRCMD_WORK_GetGameSystem((void *)a1);
    r6 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    r7 = func_020122C0((void *)r4, 0, (void *)SCRCMD_MMDL_OrbitEventMain, 0x14);
    r5 = func_020124E8((struct Obj *)r7);
    r5[0] = 0;
    m = FLDMMDL_SysSearchObjId((void *)FIELDMAP_GetMmdlSys(GAMESYSTEM_GetFieldMap((void *)r4)), r6);
    FLDMMDL_GetPos((const struct Actor *)m, (struct VecFx32 *)(r5 + 2));
    ((void **)r5)[1] = m;
    SCRIPT_SYS_CallEvent(l0, r7);
    return 1;
}
