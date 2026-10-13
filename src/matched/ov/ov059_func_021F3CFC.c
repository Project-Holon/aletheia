/*
 * function: SP_POKE_GIMMICK_StartSwapNpc
 * address:  0x021F3CFC
 * packet:   pkt_ov059_021F3CFC
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
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
 *   FLD_EXP_OBJ_GetAnime  0x021BE674  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimePaused  0x021BE6B0  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeEnabled  0x021BE700  thumb  ov021
 *   FLD_EXP_OBJ_SetAnimeFrame  0x021BE6CC  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   SP_POKE_GIMMICK_SwapNpcEventMain  0x021F3D9C  thumb  ov059
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    u8 pad[0x24];
    u16 *p24;
} W;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FIELDMAP_GetExpObj(int *p);
extern V *FLD_EXP_OBJ_GetModelStatus(void *p, int i, u16 j);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);
extern void *FLD_EXP_OBJ_GetAnime(char *base, int i, unsigned int j, int k);
extern void FLD_EXP_OBJ_SetAnimePaused(u8 *p, int v);
extern void FLD_EXP_OBJ_SetAnimeEnabled(void *p, int i, u16 j, u16 k, int flag);
extern void FLD_EXP_OBJ_SetAnimeFrame(void *p, int i, u16 j, u16 k, int flag);
extern int SP_POKE_GIMMICK_SwapNpcEventMain(void *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);

void SP_POKE_GIMMICK_StartSwapNpc(void *a, V *b, u16 c, u16 d)
{
    int i;
    void *t;
    void *s;
    W *w;
    u16 *q;

    t = GAMESYSTEM_GetFieldMap(a);
    w = (W *)FIELDMAP_GetCommonWork(t, 1);
    s = (void *)FIELDMAP_GetExpObj(t);
    q = w->p24;
    q[0] = c;
    q[1] = d;
    *FLD_EXP_OBJ_GetModelStatus(s, 0, 2) = *b;
    FLD_EXP_OBJ_SetModelHidden(s, 0, 2, 0);
    for (i = 0; i < 3; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(s, 0, (u16)2, (u16)i), 0);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, 2, i, 1);
        FLD_EXP_OBJ_SetAnimeFrame(s, 0, 2, i, 0);
    }
    func_020122C0(a, 0, SP_POKE_GIMMICK_SwapNpcEventMain, 0);
}
