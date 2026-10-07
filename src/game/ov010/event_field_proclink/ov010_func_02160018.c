/*
 * function: func_02160018
 * address:  0x02160018
 * packet:   pkt_ov010_02160018
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Proc main of the ov010 link exchange: a 16-state machine that drives
 * the ov021 connection object at +0xC, classifies the received result
 * code, and hands off to the result screens before tearing down.
 *
 * The ov021 calls to 0x021C536C, 0x021C5380 and 0x021C5394 (once folded
 * into func_021C5348) resolve since seeds_2 labelled them. Levers: in state 4 `retry` declared first and `bad`
 * last (retry spills to sp+4, ok to sp+0, next stays in r7), the result
 * code dispatched as a switch and the case-10 value as an if chain with
 * the f18 != 0 arm first; in state 12 the tail call in a local written
 * as a nested if (i == 0, then the save test) with the call in all
 * three arms, which is what makes both w->f04 loads hoist above their
 * branches and lets state 11 cross-jump into the shared tail.
 *
 * symbols:
 *   func_021605C0  0x021605C0  thumb  ov010
 *   func_0216060C  0x0216060C  thumb  ov010
 *   func_02160564  0x02160564  thumb  ov010
 *   func_0216040C  0x0216040C  thumb  ov010
 *   func_02164480  0x02164480  thumb  ov010
 *   func_0216070C  0x0216070C  thumb  ov010
 *   func_0216075C  0x0216075C  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_021644F4  0x021644F4  thumb  ov010
 *   func_021606DC  0x021606DC  thumb  ov010
 *   func_021C5224  0x021C5224  thumb  ov021
 *   func_021C5348  0x021C5348  thumb  ov021
 *   func_021C536C  0x021C536C  thumb  ov021
 *   func_021C5380  0x021C5380  thumb  ov021
 *   func_021C5394  0x021C5394  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_020120F4  0x020120F4  thumb
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_02012B70  0x02012B70  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02028754  0x02028754  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Flags {
    u32 f00;
    u32 f04;
    u8 pad[0x10];
} Flags;

typedef struct Req {
    u8 pad00[0x24];
    u32 f24;            /* 0x24 */
    u32 f28;            /* 0x28 */
} Req;

typedef struct Work {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *f0c;          /* 0x0C */
    Req *f10;           /* 0x10 */
    u16 f14;            /* 0x14 */
    u8 pad16[2];
    u32 f18;            /* 0x18 */
} Work;

extern void func_021605C0(int a0, int a1);
struct Obj;
struct Owner;
extern int func_0216060C(int a0, int a1);
extern int func_02160564(u32 state, u32 *out, u32 *err);
extern int func_0216040C(Req *r, u32 code);
extern void func_02164480(Flags *f, void *a, void *b);
extern int func_0216070C(Work *w);
extern void *func_0216075C(struct Owner *o, u16 id);
extern u32 *func_0216D9E4(void *c);
extern int func_021644F4(int i, void *a, void *p);
extern void *func_021606DC(void *p, u32 a);
struct BigObj;
struct Ctx;
struct Evt;
struct Rec44;
struct SaveBlock;
extern void func_021C5224(char *p);
extern void func_021C5348(u8 *p);
extern void func_021C536C(u8 *p);
extern int func_021C5380(u8 *p);
extern u32 func_021C5394(u8 *p, u32 *out);
extern void *func_02188C7C(u8 *p);
extern void *func_020120F4(const struct Ctx *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern int func_02012B70(const struct BigObj *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern u32 func_02028754(struct Obj *obj, u32 n);
extern u32 func_020307B0(void *p);

int func_02160018(void *evt, u32 *state, Work *w)
{
    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        func_021605C0(0, (int)w);
        *state = 2;
        break;
    case 2:
        func_021C5348(w->f0c);
        *state = 3;
        break;
    case 3:
        func_021C5224(w->f0c);
        if (func_021C5380(w->f0c) == 0)
            *state = 4;
        break;
    case 4: {
        u32 code;
        int r;

        func_021C5224(w->f0c);
        r = func_021C5394(w->f0c, &code);
        if (r == 1) {
            Flags fl;
            u32 n;
            u32 err;
            int retry = 0;
            int ok;
            int next;
            int bad = 0;

            ok = func_02160564(code, &n, &err);
            next = func_0216040C(w->f10, code);
            if (err == 0 && func_02012B70(func_020120F4(w->f04)) == 1) {
                bad = 1;
            } else if (ok == 1) {
                func_02164480(&fl, w->f04, w->f08);
                if (func_02028754((struct Obj *)(&fl), n) == 0)
                    bad = 1;
            }
            if (code == 9 && func_0216070C(w) == 0)
                retry = 1;
            if (bad == 1) {
                *state = 12;
            } else if (retry == 1) {
                *state = 14;
            } else {
                switch (next) {
                case 0:
                    *state = 9;
                    break;
                case 1:
                    *state = 11;
                    break;
                }
            }
        } else if (r == 2) {
            *state = 5;
        }
        break;
    }
    case 5:
        func_021C536C(w->f0c);
        *state = 6;
        break;
    case 6:
        func_021C5224(w->f0c);
        if (func_021C5380(w->f0c) == 0)
            *state = 7;
        break;
    case 7:
        if (func_0216060C((int)w, (int)state) != 0) {
            func_020307B0(w->f10);
            func_0216D9E4(func_02188C7C(w->f08));
            return 1;
        }
        break;
    case 8:
        func_021605C0(1, (int)w);
        *state = 4;
        break;
    case 9:
        func_02012374(evt, func_0216075C((struct Owner *)w->f10, w->f14));
        *state = 10;
        break;
    case 10:
    {
        u32 v = w->f10->f24;

        if (v == 0) {
            if (w->f18 != 0)
                *state = 7;
            else
                *state = 8;
        } else if (v == 1) {
            *state = 7;
        } else if (v == 3) {
            *state = 11;
        }
        break;
    }
    case 11:
        if (func_0216060C((int)w, (int)state) != 0) {
            u32 i = w->f10->f28;

            func_020307B0(w->f10);
            w->f10 = 0;
            func_02012374(evt, (struct Evt **)func_021644F4(i, w->f04, w->f08));
            *state = 13;
        }
        break;
    case 12:
        if (func_0216060C((int)w, (int)state) != 0) {
            u32 i = w->f10->f28;

            func_020307B0(w->f10);
            w->f10 = 0;
            {
                void *t;

                if (i == 0) {
                    if (func_02012B28(func_020127A4(func_020120F4(w->f04))) == 1)
                        t = func_021606DC(w->f04, 1);
                    else
                        t = func_021606DC(w->f04, 0);
                } else {
                    t = func_021606DC(w->f04, 0);
                }
                func_02012374(evt, t);
            }
            *state = 13;
        }
        break;
    case 13:
        func_0216D9E4(func_02188C7C(w->f08));
        return 1;
    case 14:
        if (func_0216060C((int)w, (int)state) != 0) {
            func_020307B0(w->f10);
            w->f10 = 0;
            func_02012374(evt, func_021606DC(w->f04, 2));
            *state = 15;
        }
        break;
    case 15:
        func_0216D9E4(func_02188C7C(w->f08));
        return 1;
    }
    return 0;
}
