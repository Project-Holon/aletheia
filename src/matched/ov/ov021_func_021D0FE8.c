/*
 * function: TRIAL_HOUSE_CreateSaveTask
 * address:  0x021D0FE8
 * packet:   pkt_ov021_021D0FE8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   TRIAL_HOUSE_SaveTaskMain  0x021D10A8  thumb  ov021
 *   FIELD_SAVEANIME_Create  0x021D1164  thumb  ov021
 *   FIELD_SAVEANIME_Start  0x021D11B0  thumb  ov021
 */

typedef struct Work {
    void *f00;
    int f04;
    int f08;
    int f0C;
} Work;

typedef unsigned int   u32;
struct Ctx;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
extern int TRIAL_HOUSE_SaveTaskMain(u32 a, u32 *b, u32 *c);
extern void *FIELD_SAVEANIME_Create(u32 heap, u32 v);
extern void FIELD_SAVEANIME_Start(u32 *p);

void *TRIAL_HOUSE_CreateSaveTask(void *a, int unused, int c)
{
    void *task;
    Work *w;
    int v;

    task = func_020122C0(a, 0, TRIAL_HOUSE_SaveTaskMain, 0x10);
    w = func_020124E8(task);
    w->f00 = a;
    w->f04 = 0;
    w->f08 = c;
    v = (int)FIELD_SAVEANIME_Create(0x8015, (u32)GAMESYSTEM_GetFieldMap(a));
    w->f0C = v;
    FIELD_SAVEANIME_Start((u32 *)v);
    return task;
}
