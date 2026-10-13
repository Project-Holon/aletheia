/*
 * function: GIMMICK64_ArcEffectEvent
 * address:  0x021F3AF8
 * packet:   pkt_ov064_021F3AF8
 * region:   ov064
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GAME_EVENT_GetGameSystem  0x020124E4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetExpObj  0x02188D2C  thumb  ov021
 *   FIELDMAP_GetCommonWork  0x021897BC  thumb  ov021
 *   FLD_EXP_OBJ_GetModelStatus  0x021BE480  thumb  ov021
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
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;
    int f30;
    u16 h34;
    u16 h36;
} W;

struct Ctx;
struct Obj;
extern void *GAME_EVENT_GetGameSystem(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int FIELDMAP_GetExpObj(int *p);
extern int *FIELDMAP_GetCommonWork(char *p, int idx);
extern int FLD_EXP_OBJ_GetModelStatus(char *p, unsigned i, int j);

int GIMMICK64_ArcEffectEvent(void *task)
{
    V3 v;
    W *w;
    void *sys;
    int s;
    int n;
    int m;
    int a;
    int d;

    sys = GAMESYSTEM_GetFieldMap(GAME_EVENT_GetGameSystem(task));
    s = FIELDMAP_GetExpObj(sys);
    w = (W *)FIELDMAP_GetCommonWork((char *)sys, 1);
    w->h36++;
    a = w->f18;
    n = w->h36;
    d = w->f24 - a;
    m = w->h34;
    v.a = a + d * n / m;
    a = w->f1c;
    d = w->f28 - a;
    v.b = a + d * n / m;
    a = w->f20;
    d = w->f2c - a;
    v.c = a + d * n / m;
    if (n >= (m + 1) / 2)
        n = m - n;
    v.b += w->f30 * n / m;
    *(V3 *)FLD_EXP_OBJ_GetModelStatus((char *)s, 0, 1) = v;
    if (w->h36 >= w->h34)
        return 1;
    return 0;
}
