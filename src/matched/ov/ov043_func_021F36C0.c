/*
 * function: FIELD_GIMMICK_LIFT_ELEVATOR_Init
 * address:  0x021F36C0
 * packet:   pkt_ov043_021F36C0
 * region:   ov043
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The two 0x021C0628 argument tables must be const: non-const, every
 * stack-argument store lands ahead of the register loads.  The second
 * loop's flag is an if/else (beq; movs #1; b; movs #0), the third loop's a
 * ternary (movs #1; bne; movs #0).  0x0218CEE0 and 0x021C0628 are
 * unlabelled ov021 leaves filed alongside.
 *
 * symbols:
 *   sGimmick43FixedHeightAreas     0x021F4510  data  a4
 *   sGimmick43LiftZones     0x021F4480  data  a4
 *   sGimmick43ExpObjUnitDesc     0x021F4318  data  a4
 *   sGimmick43LiftStartPos     0x021F4358  data  a4
 *   sGimmick43ElevatorStartPos     0x021F434C  data  a4
 *   sGimmick43ObstacleStartPos     0x021F4340  data  a4
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetFog  0x02188C64  thumb  ov021
 *   FIELDMAP_GetGameSystem  0x02188C80  thumb  ov021
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   FIELDMAP_GetG3dMapper  0x02188C98  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_G3D_MAPPER_GetHeightEx  0x0218CEE0  thumb  ov021
 *   FIELDMAP_AllocCommonWork  0x02189764  thumb  ov021
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetFieldSave  0x02012EC4  thumb
 *   GIMMICK_WORK_GetSaveArea  0x0200B3A4  thumb
 *   HEIGHT_EX_SetArea  0x021C0628  thumb  ov021
 *   FLD_EXP_OBJ_AddUnitFromArchive  0x021BE760  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelCullDraw  0x021BE4A4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeLoop  0x021BE6B8  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_GetAnimeLastFrame  0x021BE748  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   FIELD_GIMMICK_LIFT_ELEVATOR_ShowLiftAnime  0x021F3F38  thumb  ov043
 *   FIELD_GIMMICK_LIFT_ELEVATOR_ShowElevatorIdleAnime  0x021F4174  thumb  ov043
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FIELD_FOG_SetOffset  0x021A01BC  thumb  ov021
 *   FIELD_FOG_SetSlope  0x021A01B4  thumb  ov021
 *   sub_02030344   0x02030344  arm
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
} EA;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10[2];
} EB;

extern const EA sGimmick43FixedHeightAreas[];
extern const EB sGimmick43LiftZones[];
extern int sGimmick43ExpObjUnitDesc;
extern const V sGimmick43LiftStartPos[];
extern const V sGimmick43ElevatorStartPos;
extern const V sGimmick43ObstacleStartPos;

struct Big;
struct Ctx;
extern int FIELDMAP_GetExpObj(int *p);
extern u32 FIELDMAP_GetFog(u8 *p);
extern void *FIELDMAP_GetGameSystem(void *p);
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern u32 FIELDMAP_GetG3dMapper(u8 *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
extern void *FIELD_G3D_MAPPER_GetHeightEx(void *p);
extern void *FIELDMAP_AllocCommonWork(unsigned char *p, int id, int a, int b);
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern u8 *GAME_DATA_GetFieldSave(struct Big *p);
typedef signed int     s32;
struct Rec94;
extern s32 *GIMMICK_WORK_GetSaveArea(struct Rec94 *p, u32 b);
extern void  HEIGHT_EX_SetArea(u8 i, int a, int b, int c, int d, int e, int f, void *t);
extern void  FLD_EXP_OBJ_AddUnitFromArchive(void *p, void *a, int b);
extern V    *FLD_EXP_OBJ_GetModelStatus(void *p, int i, u16 j);
extern void FLD_EXP_OBJ_SetModelCullDraw(char *p, int i, int j, int v);
extern void *FLD_EXP_OBJ_GetAnime(void *p, int i, u16 j, u16 k);
extern void FLD_EXP_OBJ_SetAnimeLoop(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimePaused(unsigned char *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, int j, int k, int flag);
extern int FLD_EXP_OBJ_GetAnimeLastFrame(u32 a);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, int d, int e);
extern void  FIELD_GIMMICK_LIFT_ELEVATOR_ShowLiftAnime(int *a, void *b, int c);
extern void  FIELD_GIMMICK_LIFT_ELEVATOR_ShowElevatorIdleAnime(void *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *p, struct VecFx32 *out);
extern int   FIELD_FOG_SetOffset(u32 a, u32 b);
extern int   FIELD_FOG_SetSlope(u32 a, u32 b);
extern void *sub_02030344(u32 heapId);

void FIELD_GIMMICK_LIFT_ELEVATOR_Init(void *a0)
{
    void *s;
    int *q;
    u32 g;
    void *w;
    V *e;
    void *b;
    int i;
    int k;
    u8 flag;
    u8 x;
    int pos[3];

    s = (void *)FIELDMAP_GetExpObj(a0);
    g = FIELDMAP_GetFog(a0);
    q = GIMMICK_WORK_GetSaveArea((struct Rec94 *)GAME_DATA_GetFieldSave(GAMESYSTEM_GetGameData(FIELDMAP_GetGameSystem(a0))), 7);
    FIELDMAP_AllocCommonWork(a0, 1, FIELDMAP_GetHeapId(a0), 0x58);
    w = FIELD_G3D_MAPPER_GetHeightEx((void *)FIELDMAP_GetG3dMapper(a0));
    for (i = 0; i < 8; i++) {
        HEIGHT_EX_SetArea(i, sGimmick43FixedHeightAreas[i].f0, sGimmick43FixedHeightAreas[i].f4, sGimmick43FixedHeightAreas[i].f8,
                      sGimmick43FixedHeightAreas[i].fc, sGimmick43FixedHeightAreas[i].f10, 0x800000, w);
    }
    for (i = 0; i < 6; i++) {
        x = i + 8;
        if (q[i] != 0) {
            flag = 1;
        } else {
            flag = 0;
        }
        HEIGHT_EX_SetArea(x, sGimmick43LiftZones[i].f0, sGimmick43LiftZones[i].f4, sGimmick43LiftZones[i].f8,
                      sGimmick43LiftZones[i].fc, sGimmick43LiftZones[i].f10[flag], 0x800000, w);
    }
    FLD_EXP_OBJ_AddUnitFromArchive(s, &sGimmick43ExpObjUnitDesc, 0);
    for (i = 0; i < 6; i++) {
        e = FLD_EXP_OBJ_GetModelStatus(s, 0, i);
        *e = sGimmick43LiftStartPos[i];
        flag = q[i] ? 1 : 0;
        e->b = sGimmick43LiftZones[i].f10[flag];
        FLD_EXP_OBJ_SetModelCullDraw(s, 0, (u16)i, 1);
        for (k = 0; k < 2; k++) {
            b = FLD_EXP_OBJ_GetAnime(s, 0, i, k);
            FLD_EXP_OBJ_SetAnimeLoop(b, 0);
            FLD_EXP_OBJ_SetAnimePaused(b, 1);
        }
        FIELD_GIMMICK_LIFT_ELEVATOR_ShowLiftAnime(q, s, i);
    }
    e = FLD_EXP_OBJ_GetModelStatus(s, 0, 7);
    *e = sGimmick43ElevatorStartPos;
    FLD_EXP_OBJ_SetModelCullDraw(s, 0, (u16)7, 1);
    for (k = 0; k < 2; k++) {
        b = FLD_EXP_OBJ_GetAnime(s, 0, 7, k);
        FLD_EXP_OBJ_SetAnimeLoop(b, 0);
        FLD_EXP_OBJ_SetAnimePaused(b, 1);
    }
    FIELD_GIMMICK_LIFT_ELEVATOR_ShowElevatorIdleAnime(s);
    e = FLD_EXP_OBJ_GetModelStatus(s, 0, 6);
    *e = sGimmick43ObstacleStartPos;
    FLD_EXP_OBJ_SetModelCullDraw(s, 0, (u16)6, 1);
    FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 6, 0, 1);
    b = FLD_EXP_OBJ_GetAnime(s, 0, 6, 0);
    FLD_EXP_OBJ_SetAnimeLoop(b, 0);
    FLD_EXP_OBJ_SetAnimePaused(b, 1);
    if (q[6]) {
        FLD_EXP_OBJ_SetAnimeFrame((int)s, 0, 6, 0, FLD_EXP_OBJ_GetAnimeLastFrame((u32)b));
    }
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(a0), (struct VecFx32 *)pos);
    if (pos[1] <= -0x280000) {
        FIELD_FOG_SetOffset(g, 0x7FDF);
        FIELD_FOG_SetSlope(g, 9);
    }
    sub_02030344(0x15);
}
