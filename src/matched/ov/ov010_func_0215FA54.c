/*
 * function: func_0215FA54
 * address:  0x0215FA54
 * packet:   pkt_ov010_0215FA54
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Proc main of an ov010 sub-sequence: 11 states that push the child
 * tasks, load ov122 and ov172, and pick the closing screen from w->f28.
 * Byte-correct (first draft plus one lever: in state 9 the `f28 == 2`
 * test and the call share an else block ending in the one `*state = 10`
 * store, so that store is the copy the other arms cross-jump to).
 * Former blocker (MATCH): the pooled 0xAC is ov172_id passed in r1 to
 * func_02012444, which is not in match.py's OVERLAY_ID_CONSUMERS
 * (func_02012444 stores r1 in a task descriptor, src/matched/func_02012444.c),
 * so the ABS32 at +0x190 has no witness.
 *
 * symbols:
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012374  0x02012374  thumb
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   func_02012444  0x02012444  thumb
 *   func_020129B8  0x020129B8  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   GFL_USE_GetBgmNo  0x02005C44  thumb
 *   GFL_USE_CancelChangeAndPlayBgm  0x02005D90  thumb
 *   GFL_USE_FadeInBgmFull  0x02005DF8  thumb
 *   func_02026400  0x02026400  thumb
 *   func_02026454  0x02026454  thumb
 *   func_02026460  0x02026460  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_0217CE08  0x0217CE08  thumb
 *   func_0217CDBC  0x0217CDBC  thumb
 *   func_0217FA24  0x0217FA24  thumb
 *   ov122_id       0x0000007A  data
 *   ov172_id       0x000000AC  data
 *   d_021D5764     0x021D5764  data  ov122
 *   d_021C7240     0x021C7240  data
 
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    void *sys;          /* 0x00 */
    u8 pad04[0x0C - 0x04];
    u8 f0c[0x1C - 0x0C];/* 0x0C */
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
} Work;

struct Comm;
struct Ctx;
struct Evt;
struct IcaAnime;
struct Obj;
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
struct BigObj;
extern void func_020129B8(struct BigObj *p, u32 v);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *sys);
extern u16 GFL_USE_GetBgmNo(void);
extern void GFL_USE_CancelChangeAndPlayBgm(u32 h, u32 v);
extern void GFL_USE_FadeInBgmFull(u32 v);
extern void func_02026400(struct Comm *p);
extern u32 func_02026454(void *obj);
extern u32 func_02026460(void *obj);
extern int func_02158344(int a0);
extern void *func_021BE8D4(void *sys, void *proc, u32 a, u32 b);
extern void *func_021BE92C(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern void *func_0217CE08(void *sys, void *proc, u32 a, u32 b);
extern void *func_0217CDBC(void *sys);
extern void *func_0217FA24(void *sys);
extern u8 ov122_id[];
extern u8 ov172_id[];
extern u8 d_021D5764[];
extern u8 d_021C7240[];

int func_0215FA54(void *evt, u32 *state, Work *w)
{
    void *sys = w->sys;
    void *save = (void *)func_02012138(sys);
    void *ctx = func_020120F4(sys);
    void *proc = func_0201210C(sys);

    switch (*state) {
    case 0:
        func_02012374(evt, func_021BE8D4(sys, proc, 0, 0));
        (*state)++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)sys, (int)proc));
        *state = 2;
        break;
    case 2:
        (*state)++;
    case 3:
        GAMESYSTEM_CallProc(sys, (u32)ov122_id, d_021D5764, w);
        (*state)++;
        break;
    case 4:
        if (GAMESYSTEM_GetProcStatus(sys) != 0)
            break;
        switch (w->f20) {
        case 0:
            if (func_02158344((int)save) && w->f28 == 2)
                func_020129B8(ctx, 3);
            *state = 6;
            break;
        case 1:
            w->f24 = GFL_USE_GetBgmNo();
            func_02012444(evt, (u32)ov172_id, (u32)d_021C7240, (u32)w->f0c);
            *state = 5;
            break;
        default:
            *state = 6;
            break;
        }
        break;
    case 5:
        if (GAMESYSTEM_GetProcStatus(sys) != 0)
            break;
        GFL_USE_CancelChangeAndPlayBgm(w->f24, 0xFFFF);
        GFL_USE_FadeInBgmFull(60);
        *state = 6;
        break;
    case 6:
        w->f1c = 0;
        (*state)++;
        break;
    case 7:
        func_02012374(evt, FIELD_STATUS_CreateFieldOpenEvent(sys));
        (*state)++;
        break;
    case 8:
        func_02012374(evt, func_021BE92C(sys, proc, 0, 0, 1, 0, 0));
        (*state)++;
        break;
    case 9:
        if (w->f20 == 0) {
            if (w->f28 == 0) {
                if (func_02026460(save))
                    break;
                if (func_02026454(save)) {
                    func_02026400(save);
                    break;
                }
                func_02012374(evt, func_0217CE08(sys, proc, 0x117, 0));
                *state = 10;
            } else if (w->f28 == 3) {
                func_02012374(evt, func_0217FA24(sys));
                *state = 10;
            } else {
                if (w->f28 != 2)
                    func_02012374(evt, func_0217CDBC(sys));
                *state = 10;
            }
        } else {
            *state = 10;
        }
        break;
    case 10:
        return 1;
    }
    return 0;
}
