/*
 * function: func_021F37B8
 * address:  0x021F37B8
 * packet:   pkt_ov064_021F37B8
 * region:   ov064
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   GIMMICK64_PlayerEffectEvent  0x021F384C  thumb  ov064
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
struct Obj00020;
extern void *FIELDMAP_GetFieldPlayer(struct Obj00020 *p);
struct VecFx32;
extern void FIELD_PLAYER_GetPos(unsigned char *a, struct VecFx32 *v);
typedef unsigned int   u32;
struct Desc;
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(int a, int b, int c, u16 d, int e);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, u16 d, int e);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int GIMMICK64_PlayerEffectEvent(void *task, int *st);

void *func_021F37B8(int a)
{
    int i;
    void *sys;
    int s;
    V3 v;

    sys = GAMESYSTEM_GetFieldMap((void *)a);
    s = FIELDMAP_GetExpObj(sys);
    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer((void *)sys), (struct VecFx32 *)&v);
    *(V3 *)FLD_EXP_OBJ_GetModelStatus((char *)s, 0, 0) = v;
    FLD_EXP_OBJ_SetModelHidden((char *)s, 0, 0, 0);
    for (i = 0; i < 4; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)s, 0, (int)0, (u16)i), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 0, i, 1);
        FLD_EXP_OBJ_SetAnimeFrame(s, 0, 0, i, 0);
    }
    return func_020122C0((void *)a, 0, (void *)GIMMICK64_PlayerEffectEvent, 0);
}
