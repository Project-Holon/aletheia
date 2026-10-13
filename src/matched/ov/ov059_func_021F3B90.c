/*
 * function: SP_POKE_GIMMICK_MoveEventMain
 * address:  0x021F3B90
 * packet:   pkt_ov059_021F3B90
 * region:   ov059
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     the task callback SP_POKE_GIMMICK_StartMove installs: steps w->g towards
 *           w->f and interpolates a position between w->c and w->d with a
 *           bump of w->e on the middle axis. Each difference goes through
 *           the named temporary k (the original computes it into r1 and
 *           copies it to r0 for muls; inline, it lands in r0 and the
 *           function is 6 bytes short). The tail is one if with the
 *           return 1 inside it (the inverse early return flips the blo).
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
 *   FLD_EXP_OBJ_SetModelHidden  0x021BE4B4  thumb  ov021
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

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern V *FLD_EXP_OBJ_GetModelStatus(void *p, int i, u16 j);
extern void FLD_EXP_OBJ_SetModelHidden(char *p, int i, int j, int v);

int SP_POKE_GIMMICK_MoveEventMain(void *a)
{
    void *t;
    void *s;
    W *w;
    int flag;
    int n;
    int d;
    int k;
    V pos;

    t = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(a));
    s = (void *)FIELDMAP_GetExpObj(t);
    flag = 1;
    w = (W *)FIELDMAP_GetCommonWork(t, 1);
    if (w->b == 0)
        flag = 0;
    w->g++;
    n = w->g;
    d = w->f;
    k = w->d.a - w->c.a;
    pos.a = w->c.a + k * n / d;
    k = w->d.b - w->c.b;
    pos.b = w->c.b + k * n / d;
    k = w->d.c - w->c.c;
    pos.c = w->c.c + k * n / d;
    if (n >= (d + 1) / 2)
        n = d - n;
    pos.b += w->e * n / d;
    *FLD_EXP_OBJ_GetModelStatus(s, 0, flag) = pos;
    if (w->g >= w->f) {
        if (w->b == 1)
            FLD_EXP_OBJ_SetModelHidden(s, 0, (u16)flag, 1);
        return 1;
    }
    return 0;
}
