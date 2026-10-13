/*
 * function: func_02166E50
 * address:  0x02166E50
 * packet:   pkt_ov010_02166E50
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Two-stage task: stage 0 starts an ov110 sub-task (pooled 0x6E is the
 * overlay id, 0x021C39B8 a table in its window) on the work at +0x10;
 * stage 1 reads back its result by the kind at +0x00 into the u16 outputs
 * at +0x04/+0x08 and flags +0x0C, then frees the work.
 *
 * Byte-correct (lane B5, run 1).  7 of 14 sites unresolved, no C change helps:
 *   - ov110_id 0x6E: overlay_id refuses, func_02012444 is not in
 *     OVERLAY_ID_CONSUMERS (it stores a1 in a descriptor for the state
 *     machine GAME_EVENT_CallProcSeq rather than passing it straight to a loader).
 *   - d_021C39B8: with the ov110 token the hint is "contested" and no
 *     overlay_id site loads ov110; without it, "no witness".  Resolves once
 *     ov110_id does.
 *   - arm9 unlabelled leaves 0x0202411C, 0x02024124, 0x02024128,
 *     0x02024134 (a .word run in asm/arm9/main.s after PMSI_PARAM_Delete) and
 *     0x0200E714: no witness outside this range; each needs its own EXACT
 *     arm9 entry (matched class).
 * Same blocker family as ov010_func_02166908 / ov010_func_0216B004.
 *
 * symbols:
 *   func_020124E8  0x020124E8  thumb
 *   func_02012444  0x02012444  thumb
 *   PMSI_PARAM_CheckCanceled  0x0202411C  thumb
 *   PMSI_PARAM_GetWords  0x02024128  thumb
 *   PMSI_PARAM_GetWord  0x02024124  thumb
 *   PMSI_PARAM_GetSentence  0x02024134  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200E6F0  0x0200E6F0  thumb
 *   func_0200E714  0x0200E714  thumb
 *   PMSI_PARAM_Delete  0x020240FC  thumb
 *   ov110_id       0x0000006E  data   a1
 *   d_021C39B8     0x021C39B8  data   ov110  a4
 
 * 2026-10-05 (D8 lane 15): overlay id sites now resolve; all relocations resolved, EXACT.
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Res4 {
    u16 a;
    u16 b;
} Res4;

typedef struct Res8 {
    u16 pad[2];
    u16 a;
    u16 b;
} Res8;

typedef struct Work {
    u32 kind;       /* 0x00 */
    u16 *out0;      /* 0x04 */
    u16 *out1;      /* 0x08 */
    u16 *done;      /* 0x0C */
    void *task;     /* 0x10 */
    u32 f14;        /* 0x14 */
    u32 f18;        /* 0x18 */
} Work;

struct Big;
struct Ctx;
struct Obj;
struct Rec0200E714;
extern void *func_020124E8(struct Obj *p);
extern void func_02012444(struct Obj *obj, u32 a1, u32 a2, u32 a3);
extern int PMSI_PARAM_CheckCanceled(unsigned char *p);
extern void  PMSI_PARAM_GetWords(void *t, Res4 *out);
extern unsigned int PMSI_PARAM_GetWord(unsigned short *p);
extern void PMSI_PARAM_GetSentence(char *a, void *b);
extern void *func_020124E4(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200E6F0(u32 a);
extern void func_0200E714(struct Rec0200E714 *dst, int idx, struct Rec0200E714 *src);
extern void  PMSI_PARAM_Delete(void *t);

extern char ov110_id[];
extern char d_021C39B8[];

u32 func_02166E50(void *obj, u32 *mode)
{
    Work *w = func_020124E8(obj);
    void *t = w->task;
    Res4 r4;
    Res8 r8;
    u16 v;
    u16 done;

    switch (*mode) {
    case 0:
        if (t == 0) {
            return 1;
        }
        func_02012444(obj, (u32)ov110_id, (u32)d_021C39B8, (u32)t);
        (*mode)++;
        break;
    case 1:
        if (PMSI_PARAM_CheckCanceled(t) != 0) {
            done = 0;
        } else {
            if (w->kind == 5) {
                PMSI_PARAM_GetWords(t, &r4);
                *w->out0 = r4.a;
                v = r4.b;
            } else if (w->kind == 4) {
                *w->out0 = PMSI_PARAM_GetWord(t);
                v = 0;
            } else {
                PMSI_PARAM_GetSentence(t, &r8);
                if (w->f18 != 0) {
                    func_0200E714(func_0200E6F0((u32)func_02012EBC(func_020120F4(func_020124E4(obj)))), w->f14, (struct Rec0200E714 *)(&r8));
                }
                *w->out0 = r8.a;
                v = r8.b;
            }
            *w->out1 = v;
            done = 1;
        }
        *w->done = done;
        PMSI_PARAM_Delete(w->task);
        return 1;
    }
    return 0;
}
