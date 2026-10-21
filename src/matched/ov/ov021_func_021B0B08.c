/*
 * function: SCRCMD_MSGWIN_UpdateBalloonPos
 * address:  0x021B0B08
 * packet:   pkt_ov021_021B0B08
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SCRCMD_MSGWIN_UpdateBalloonPos  0x021B0B08  thumb
 *   SCRCMD_WORK_GetMmdlSys  0x0215A5EC  thumb  ov010
 *   SCRCMD_WORK_GetWordSetWork  0x0215A63C  thumb  ov010
 *   FLDMMDL_SysSearchObjId  0x0216DE94  thumb  ov010
 *   FLDMMDL_GetDirDisp  0x0216D5F8  thumb  ov010
 *   FLDMMDL_GetPos  0x0216D88C  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetG3dCamera  0x0218EC2C  thumb  ov021
 *   SCRCMD_WORK_GetWindowKind  0x0215A66C  thumb  ov010
 *   SCRCMD_MSGWIN_SelectBalloonOffset  0x021B0960  thumb
 */

typedef unsigned short u16;

typedef struct V3 {
    int x, y, z;
} V3;

typedef struct S {
    u16 id;
    u16 pad;
    V3 sum;
    V3 a;
    V3 b;
} S;

extern void *SCRCMD_WORK_GetMmdlSys(void *);
extern unsigned char *SCRCMD_WORK_GetWordSetWork(unsigned char *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Ctx;
extern void *FLDMMDL_SysSearchObjId(void *map, u32 id);
extern u16 FLDMMDL_GetDirDisp(void *p);
struct Actor;
struct VecFx32;
extern void FLDMMDL_GetPos(const struct Actor *, struct VecFx32 *);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELD_CAMERA_GetG3dCamera(u8 *p);
extern u8 SCRCMD_WORK_GetWindowKind(u8 *p);
extern void SCRCMD_MSGWIN_SelectBalloonOffset(V3 *, V3 *, int, int, int);

void SCRCMD_MSGWIN_UpdateBalloonPos(void *a, int b)
{
    void *t = SCRCMD_WORK_GetMmdlSys(a);
    S *s = (S *)SCRCMD_WORK_GetWordSetWork(a);
    void *o = FLDMMDL_SysSearchObjId(t, s->id);
    V3 v;
    if (o != 0) {
        FLDMMDL_GetDirDisp(o);
        FLDMMDL_GetPos(o, (struct VecFx32 *)&v);
        if (b == 1 || v.x != s->a.x || v.y != s->a.y || v.z != s->a.z) {
            int p, q;
            s->a = v;
            p = (int)FIELDMAP_GetCamera(GAMESYSTEM_GetFieldMap(SCRCMD_WORK_GetGameSystem(a)));
            q = FIELD_CAMERA_GetG3dCamera((void *)p);
            SCRCMD_MSGWIN_SelectBalloonOffset(&s->a, &s->b, q, p, SCRCMD_WORK_GetWindowKind(a));
        }
        s->sum.x = s->a.x + s->b.x;
        s->sum.y = s->a.y + s->b.y;
        s->sum.z = s->a.z + s->b.z;
    }
}
