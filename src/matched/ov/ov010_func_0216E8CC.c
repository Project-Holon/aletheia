/*
 * function: EVENT_BATTLE_CreateResultOnlyTask
 * address:  0x0216E8CC
 * packet:   pkt_ov010_0216E8CC
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
 *   EVENT_BATTLE_InitTaskWork  0x0216F02C  thumb  ov010
 *   FIELDMAP_GetEncount  0x02188CE8  thumb  ov021
 *   EFFECT_ENCOUNT_ConsumeSpot  0x021AAABC  thumb  ov021
 *   EVENT_BATTLE_ProcBattleTask  0x0216EB98  thumb  ov010
 */

typedef unsigned short u16;

struct Work;
extern int EVENT_BATTLE_ProcBattleTask(void *evt, unsigned int *state, struct Work *w);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Desc;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void EVENT_BATTLE_InitTaskWork(void **p, void *a, void *b);
extern u32 FIELDMAP_GetEncount(u8 *p);
extern void EFFECT_ENCOUNT_ConsumeSpot(int s);

int EVENT_BATTLE_CreateResultOnlyTask(int a0, int a1, int a2)
{
    int h;
    int *t;

    h = (int)func_020122C0((void *)a0, 0, EVENT_BATTLE_ProcBattleTask, 0x28);
    t = func_020124E8((struct Obj *)h);
    EVENT_BATTLE_InitTaskWork((void **)t, (void *)a0, (void *)a2);
    t[5] = 0;
    t[6] = 1;
    t[8] = 1;
    t[9] = 9;
    EFFECT_ENCOUNT_ConsumeSpot(FIELDMAP_GetEncount((u8 *)a1));
    return h;
}
