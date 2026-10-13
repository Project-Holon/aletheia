/*
 * function: SCRCMD_MMDL_StartRise
 * address:  0x0216A7A0
 * packet:   pkt_ov010_0216A7A0
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
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 *   SCRCMD_MMDL_RiseEventMain  0x0216A838  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int a;
    int b;
    int c;
} Vec3;

typedef struct {
    int f0;
    u16 f4;
    u16 f6;
    void *f8;
    Vec3 v;
} S;

extern void *SCRCMD_WORK_GetGameData(void *a0);
extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a0, void *a1);
struct Desc;

extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetMmdlSys(unsigned char *p);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *a, struct VecFx32 *out);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);
extern int SCRCMD_MMDL_RiseEventMain();

int SCRCMD_MMDL_StartRise(int a0, int a1)
{
    void *l0;
    void *r6;
    int l4;
    int r7;
    int r5;
    struct Desc *l8;
    void *obj;
    S *r4;

    SCRCMD_WORK_GetGameData((void *)a1);
    l0 = SCRCMD_WORK_GetScriptWork((void *)a1);
    r6 = SCRCMD_WORK_GetGameSystem((void *)a1);
    l4 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    r7 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    r5 = SCRIPT_WORK_ReadWorkValue((void *)a0, (void *)a1);
    l8 = func_020122C0((void *)r6, 0, (void *)SCRCMD_MMDL_RiseEventMain, 0x18);
    r4 = func_020124E8((struct Obj *)l8);
    r4->f4 = r5;
    r4->f6 = 0;
    obj = FLDMMDL_SysSearchObjId((void *)FIELDMAP_GetMmdlSys(GAMESYSTEM_GetFieldMap((void *)r6)), l4);
    FLDMMDL_GetPos(obj, (struct VecFx32 *)&r4->v);
    r4->f8 = obj;
    FLDMMDL_SetMoveBit(obj, 0x8000);
    r4->f0 = (r7 << 15) - r4->v.b;
    SCRIPT_SYS_CallEvent(l0, l8);
    return 1;
}
