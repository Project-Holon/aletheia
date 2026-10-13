/*
 * function: SP_POKE_GIMMICK_StartMove
 * address:  0x021F39B8
 * packet:   pkt_ov059_021F39B8
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     twin of ov059 SP_POKE_GIMMICK_ShowAndPlay. Returns func_020122C0's result (a
 *           void return moves the final store to r0/r1); d is const V *
 *           (without it the second struct copy loads w before d), and the
 *           sixth parameter is read with ldr, so it is int.
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
 *   SP_POKE_GIMMICK_MoveEventMain  0x021F3B90  thumb  ov059
 */

typedef unsigned short u16;
typedef unsigned char u8;

typedef struct {
    int a;
    int b;
    int c;
} V;

typedef struct {
    int b;
    V c;
    V d;
    int e;
    u16 f;
    u16 g;
} W;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
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
extern int SP_POKE_GIMMICK_MoveEventMain(void *a);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);

void *SP_POKE_GIMMICK_StartMove(void *a, int b, V *c, const V *d, int e, int f)
{
    int i;
    void *t;
    void *s;
    void *r;
    W *w;
    int flag;

    t = GAMESYSTEM_GetFieldMap(a);
    flag = 1;
    w = (W *)FIELDMAP_GetCommonWork(t, 1);
    s = (void *)FIELDMAP_GetExpObj(t);
    if (b == 0) {
        flag = 0;
        func_020061E4(0x566);
    }
    *FLD_EXP_OBJ_GetModelStatus(s, 0, flag) = *c;
    FLD_EXP_OBJ_SetModelHidden(s, 0, (u16)flag, 0);
    for (i = 0; i < 3; i++) {
        FLD_EXP_OBJ_SetAnimePaused(FLD_EXP_OBJ_GetAnime(s, 0, flag, i), 1);
        FLD_EXP_OBJ_SetAnimeEnabled(s, 0, flag, i, 0);
        FLD_EXP_OBJ_SetAnimeFrame(s, 0, flag, i, 0);
    }
    w->c = *c;
    w->d = *d;
    w->f = f;
    w->g = 0;
    w->e = e;
    r = func_020122C0(a, 0, SP_POKE_GIMMICK_MoveEventMain, 0);
    w->b = b;
    return r;
}
