/*
 * function: EVENT_FIELD_PROCLINK_CreateHopEvent
 * address:  0x02161AC0
 * packet:   pkt_ov010_02161AC0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetEffect  0x02188CD0  thumb  ov021
 *   func_0207CA00  0x0207CA00  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   EVENT_FIELD_PROCLINK_HopEventMain  0x021619B8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Tri {
    u32 w[3];
} Tri;

typedef struct Node {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 pad08[4];
    Tri f0c;            /* 0x0C */
    u8 f18[12];         /* 0x18 */
} Node;

struct Ctx;
struct Desc;
struct HopWork;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern u32 FIELDMAP_GetEffect(u8 *p);
extern void func_0207CA00(void *a, void *b, void *c);
extern void GFL_USE_PlaySeDefaultVolume(u32 v);
extern int EVENT_FIELD_PROCLINK_HopEventMain(void *task, u32 *seq, struct HopWork *w);

void *EVENT_FIELD_PROCLINK_CreateHopEvent(void *p, void *a1, Tri *t, void *a3)
{
    void *h;
    Node *n;

    h = func_020122C0(p, 0, EVENT_FIELD_PROCLINK_HopEventMain, 0x24);
    n = func_020124E8(h);
    n->f04 = a1;
    n->f00 = (void *)FIELDMAP_GetEffect(GAMESYSTEM_GetFieldMap(p));
    n->f0c = *t;
    func_0207CA00(a3, t, n->f18);
    GFL_USE_PlaySeDefaultVolume(0x55E);
    return h;
}
