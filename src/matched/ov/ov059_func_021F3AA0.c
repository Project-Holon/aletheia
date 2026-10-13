/*
 * function: SP_POKE_GIMMICK_ShowAndPlay
 * address:  0x021F3AA0
 * packet:   pkt_ov059_021F3AA0
 * region:   ov059
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
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef unsigned int   u32;
struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FIELDMAP_GetExpObj(int *p);
extern void func_020061E4(u32 a);
extern V *FLD_EXP_OBJ_GetModelStatus(void *p, int i, u16 j);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern u8 *FLD_EXP_OBJ_GetAnime(void *p, int i, u16 j, u16 k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, u16 j, u16 k, int flag);
extern void FLD_EXP_OBJ_SetAnimeFrame(void *p, int i, u16 j, u16 k, int flag);

void SP_POKE_GIMMICK_ShowAndPlay(void *a, int b, V *c)
{
    int i;
    void *t;
    void *s;
    int flag;

    t = GAMESYSTEM_GetFieldMap(a);
    FIELDMAP_GetCommonWork(t, 1);
    flag = 1;
    s = (void *)FIELDMAP_GetExpObj(t);
    if (b == 0) {
        flag = 0;
        func_020061E4(0x567);
    } else {
        func_020061E4(0x793);
    }
    *FLD_EXP_OBJ_GetModelStatus(s, 0, flag) = *c;
    FLD_EXP_OBJ_SetModelHidden(s, 0, (u16)flag, 0);
    for (i = 0; i < 3; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(s, 0, flag, i), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, flag, i, 1);
        FLD_EXP_OBJ_SetAnimeFrame(s, 0, flag, i, 0);
    }
}
