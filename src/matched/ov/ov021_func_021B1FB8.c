/*
 * function: SCRCMD_FLDMMDL_StartMmdlMoveToGrid
 * address:  0x021B1FB8
 * packet:   pkt_ov021_021B1FB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRCMD_WORK_GetOccupyInfo  0x0215A5EC  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_CreateHopEvent  0x02161AC0  thumb  ov010
 *   SCRIPT_SYS_CallEvent  0x0215897C  thumb  ov010
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
struct Tri;
extern void *SCRCMD_WORK_GetOccupyInfo(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void *EVENT_FIELD_PROCLINK_CreateHopEvent(void *p, void *a1, struct Tri *t, void *a3);
extern void SCRIPT_SYS_CallEvent(void *vm, void *task);

int SCRCMD_FLDMMDL_StartMmdlMoveToGrid(u32 a, u32 b)
{
    int buf[3];
    int vec[3];
    void *t;
    int i;
    int x;
    int y;
    int z;
    u32 m;
    void *w;
    u32 o;

    t = SCRCMD_WORK_GetScriptWork((void *)b);
    i = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    x = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    y = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    z = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    m = (u32)SCRCMD_WORK_GetOccupyInfo((void *)b);
    w = SCRCMD_WORK_GetGameSystem((void *)b);
    o = (u32)FLDMMDL_SysSearchObjId((void *)m, i);
    FLDMMDL_GetPos((const struct Actor *)o, (struct VecFx32 *)buf);
    vec[0] = (x << 16) + 0x8000;
    vec[1] = y << 16;
    vec[2] = (z << 16) + 0x8000;
    SCRIPT_SYS_CallEvent(t, EVENT_FIELD_PROCLINK_CreateHopEvent(w, (void *)o, (struct Tri *)buf, vec));
    return 1;
}
