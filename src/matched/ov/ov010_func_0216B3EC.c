/*
 * function: func_0216B3EC
 * address:  0x0216B3EC
 * packet:   pkt_ov010_0216B3EC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Seven-state proc of an ov010 field menu: run the list task, then the
 * chosen entry's screen, writing 0 or 1 to the caller's result word.
 * Byte-correct first draft.
 * Blocker (MATCH): the arm9 Thumb callee 0x02012FA4 has no func_ label
 * and no matched file (seed).
 *
 * 2026-10-05: byte-identical; the wildcard is arm9 func_02012FA4 (new matched/arm9 file, EXACT, this lane); needs its shard.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216B24C  0x0216B24C  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_020061E4  0x020061E4  thumb
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021665D0  0x021665D0  thumb  ov010
 *   func_02012FA4  0x02012FA4  thumb
 *   func_021854B0  0x021854B0  thumb
 *   func_0219C630  0x0219C630  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Work {
    u16 *result;        /* 0x00 */
    u16 f04;            /* 0x04 */
    u8 pad06[2];
    u8 f08[0x14 - 0x08];/* 0x08 */
    u16 f14;            /* 0x14 */
    u8 f16;             /* 0x16 */
    u8 pad17;
    u16 f18;            /* 0x18 */
    u8 pad1A[2];
    u32 f1c;            /* 0x1C */
    u32 f20;            /* 0x20 */
} Work;

struct Ctx;
struct Evt;
struct Obj;
extern void *func_020124E4(struct Obj *p);
extern u32 func_02012138(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_0201210C(const struct Ctx *p);
extern void *func_02188C7C(u8 *p);
extern void func_0216D9A0(void *map);
extern int func_0216B24C(void *vm, int value, int flag);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_020061E4(u32 se);
extern void *func_021BE8D4(void *sys, void *proc, u32 a, u32 b);
extern int func_021665D0(int a0, int a1);
extern void func_02012FA4(void *ctx, u8 i);
extern void *func_021854B0(void *sys, void *proc, u32 id, void *pos, u32 flag);
extern int func_0219C630(void *map);
extern void *func_021BE92C(void *sys, void *proc, u32 a, u32 b, u32 c, u32 d, u32 e);
extern u32 *func_0216D9E4(void *c);

int func_0216B3EC(void *evt, u32 *state, Work *w)
{
    void *sys = func_020124E4(evt);
    void *ctx;
    void *proc;

    func_02012138(sys);
    ctx = func_020120F4(sys);
    proc = func_0201210C(sys);
    switch (*state) {
    case 0:
        func_0216D9A0(func_02188C7C(proc));
        if (w->f20 == 1) {
            *state = 2;
        } else {
            func_02012374(evt, (void *)func_0216B24C(sys, (int)(&w->f18), w->f16));
            (*state)++;
        }
        break;
    case 1:
        if (w->f18 == 0) {
            if (w->result != 0)
                *w->result = 0;
            *state = 6;
        } else {
            (*state)++;
        }
        break;
    case 2:
        if (w->f1c != 0)
            func_020061E4(1369);
        func_02012374(evt, func_021BE8D4(sys, proc, 9, 0));
        (*state)++;
        break;
    case 3:
        w->f04 = func_021665D0((int)sys, w->f16);
        func_02012FA4(ctx, w->f16);
        func_02012374(evt, func_021854B0(sys, proc, w->f04, w->f08, w->f14));
        (*state)++;
        break;
    case 4:
        if (func_0219C630(func_02188C7C(func_0201210C(sys))) == 1)
            break;
        func_02012374(evt, func_021BE92C(sys, proc, 9, 0, 0, 0, 0));
        (*state)++;
        break;
    case 5:
        if (w->result != 0)
            *w->result = 1;
        *state = 6;
        break;
    case 6:
        func_0216D9E4(func_02188C7C(proc));
        return 1;
    }
    return 0;
}
