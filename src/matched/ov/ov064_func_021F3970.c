/*
 * function: GIMMICK64_StartArcEffect
 * address:  0x021F3970
 * packet:   pkt_ov064_021F3970
 * region:   ov064
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   GIMMICK64_ArcEffectEvent  0x021F3AF8  thumb  ov064
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    int a;
    int b;
    int c;
} V3;

typedef struct {
    u8 pad[0x18];
    V3 v18;
    V3 v24;
    int f30;
    u16 h34;
    u16 h36;
} W;

typedef unsigned int   u32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FIELDMAP_GetExpObj(int *p);
extern void func_020061E4(u32 a);
struct Desc;
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(int a, int b, int c, u16 d, int e);
extern void FLD_EXP_OBJ_SetAnimeFrame(int a, int b, int c, u16 d, int e);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern int GIMMICK64_ArcEffectEvent(void *task);

void GIMMICK64_StartArcEffect(int a, const V3 *p0, const V3 *p1, int f30, int n)
{
    int i;
    void *sys;
    int s;
    W *w;

    sys = GAMESYSTEM_GetFieldMap((void *)a);
    w = (W *)FIELDMAP_GetCommonWork((char *)sys, 1);
    s = FIELDMAP_GetExpObj(sys);
    func_020061E4(0x566);
    *(V3 *)FLD_EXP_OBJ_GetModelStatus((char *)s, 0, 1) = *p0;
    FLD_EXP_OBJ_SetModelHidden((char *)s, 0, 1, 0);
    for (i = 0; i < 3; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime((char *)s, 0, (int)1, (u16)i), 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 1, i, 0);
        FLD_EXP_OBJ_SetAnimeFrame(s, 0, 1, i, 0);
    }
    w->v18 = *p0;
    w->v24 = *p1;
    w->h34 = n;
    w->h36 = 0;
    w->f30 = f30;
    func_020122C0((void *)a, 0, (void *)GIMMICK64_ArcEffectEvent, 0);
}
