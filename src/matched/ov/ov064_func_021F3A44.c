/*
 * function: FIELD_GIMMICK_ARC_EFFECT_ShowArcModelAt
 * address:  0x021F3A44
 * packet:   pkt_ov064_021F3A44
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
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef unsigned int   u32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(int a, int b, int c, u16 d, int e);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, u16 d, int e);

void FIELD_GIMMICK_ARC_EFFECT_ShowArcModelAt(int a, V3 *v)
{
    int i;
    int s;

    s = FIELDMAP_GetExpObj(GAMESYSTEM_GetFieldMap((void *)a));
    GFL_USE_PlaySeDefaultVolume(0x567);
    *(V3 *)FLD_EXP_OBJ_GetModelStatus((char *)s, 0, 1) = *v;
    FLD_EXP_OBJ_SetModelHidden((char *)s, 0, 1, 0);
    for (i = 0; i < 3; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)s, 0, (int)1, (u16)i), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 1, i, 1);
        FLD_EXP_OBJ_SetAnimeFrame(s, 0, 1, i, 0);
    }
}
