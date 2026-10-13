/*
 * function: EVENT_FIELD_PROCLINK_CreateCommExitEvent
 * address:  0x02161B90
 * packet:   pkt_ov010_02161B90
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   func_02012138  0x02012138  thumb
 *   EVENT_FIELD_PROCLINK_StartCommProc  0x02161CDC  thumb  ov010
 *   EVENT_FIELD_PROCLINK_StartSeasonCommProc  0x02161D18  thumb  ov010
 *   GAME_BEACON_SEARCH_SetSimpleEventB  0x0216570C  thumb  ov010
 *   EVENT_FIELD_PROCLINK_CommExitEventMain  0x02161BF8  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Node {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 f08[0x1C];       /* 0x08 */
} Node;

struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void MI_CpuFill8(void *p, int v, int n);
struct Ctx;
extern unsigned int func_02012138(const struct Ctx *p);
extern void EVENT_FIELD_PROCLINK_StartCommProc(void *a, void *b, u8 c, u8 d);
extern void EVENT_FIELD_PROCLINK_StartSeasonCommProc(int a, int b, u8 c, u8 d);
extern void GAME_BEACON_SEARCH_SetSimpleEventB(void);
extern int EVENT_FIELD_PROCLINK_CommExitEventMain(void *a0, int *state, struct Obj *o);

void *EVENT_FIELD_PROCLINK_CreateCommExitEvent(void *p, void *a1, int kind, int sub, int flag)
{
    void *h;
    Node *n;

    h = func_020122C0(p, a1, EVENT_FIELD_PROCLINK_CommExitEventMain, 0x24);
    n = func_020124E8(h);
    MI_CpuFill8(n, 0, 0x24);
    n->f00 = p;
    n->f04 = (void *)func_02012138(p);
    if (flag != 0)
        EVENT_FIELD_PROCLINK_StartCommProc(n->f08, p, kind, sub);
    else
        EVENT_FIELD_PROCLINK_StartSeasonCommProc((int)n->f08, (int)p, kind, sub);
    if (kind == 3)
        GAME_BEACON_SEARCH_SetSimpleEventB();
    return h;
}
