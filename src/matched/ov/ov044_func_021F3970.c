/*
 * function: GIMMICK44_SnapLiftToBottom
 * address:  0x021F3970
 * packet:   pkt_ov044_021F3970
 * region:   ov044
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetCamera  0x02188C58  thumb  ov021
 *   FIELD_CAMERA_GetTraceTarget  0x0218EC5C  thumb  ov021
 *   FIELD_CAMERA_StopTargetTrace  0x0218EC54  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_PLAYER_SetPos  0x021A3044  thumb  ov021
 */

typedef unsigned int u32;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
typedef unsigned char  u8;
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern void *FIELDMAP_GetCamera(void *p);
extern u32 FIELD_CAMERA_GetTraceTarget(u8 *p);
extern void FIELD_CAMERA_StopTargetTrace(u8 *p);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern void FIELD_PLAYER_SetPos(u8 *p, void *v);

void GIMMICK44_SnapLiftToBottom(void *a)
{
    void *s;
    void *r;
    int *p;
    u32 h;
    void *c;
    int v[3];

    s = GAMESYSTEM_GetFieldMap((void *)a);
    r = (void *)FIELDMAP_GetExpObj(s);
    p = FIELDMAP_GetCommonWork(s, 1);
    h = (u32)FIELDMAP_GetCamera(s);
    p[3] = FIELD_CAMERA_GetTraceTarget((u8 *)h);
    FIELD_CAMERA_StopTargetTrace((u8 *)h);
    ((int *)FLD_EXP_OBJ_GetModelStatus(r, 0, 0))[1] = -0x50000;
    c = FIELDMAP_GetFieldPlayer((void *)s);
    FIELD_PLAYER_GetPos(c, (struct VecFx32 *)v);
    v[1] = -0x50000;
    FIELD_PLAYER_SetPos(c, v);
}
