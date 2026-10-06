/*
 * function: func_0216025C
 * address:  0x0216025C
 * packet:   pkt_ov010_0216025C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Nine-state connection sequence; returns 1 when the sequence has ended.
 * EXACT* because the listing extent runs over the unlabelled followers
 * 0x0216040C, 0x02160564 and 0x021605C0. Levers: the case-3 test is an
 * else-if chain with the `*state = 1` arm written twice (the first copy is
 * cross-jumped into `b`), and cases 4 and 5 hand one local `h` to
 * func_02012374, which is what lets case 4 cross-jump into case 5's call.
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200C404  0x0200C404  thumb
 *   func_0200C464  0x0200C464  thumb
 *   func_0216040C  0x0216040C  thumb  ov010
 *   func_02160564  0x02160564  thumb  ov010
 *   func_02012B70  0x02012B70  thumb
 *   func_02164480  0x02164480  thumb  ov010
 *   func_02028754  0x02028754  thumb
 *   func_0216070C  0x0216070C  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0216060C  0x0216060C  thumb  ov010
 *   func_0216075C  0x0216075C  thumb  ov010
 *   func_02012374  0x02012374  thumb
 *   func_021644F4  0x021644F4  thumb  ov010
 *   func_020127A4  0x020127A4  thumb
 *   func_02012B28  0x02012B28  thumb
 *   func_021606DC  0x021606DC  thumb  ov010
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
    u8 pad[0x24];
    u32 result;         /* 0x24 */
    u32 next;           /* 0x28 */
} Req;

typedef struct Ctx {
    u32 f00;
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    u32 f0c;
    Req *req;           /* 0x10 */
    u16 id;             /* 0x14 */
} Ctx;

struct Big;
struct BigObj;
struct Evt;
struct Rec44;
struct SaveBlock;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200C404(void *p);
extern u8 func_0200C464(const u8 *a, u32 i);
extern int func_0216040C(Req *r, u32 code);
extern int func_02160564(u32 state, u32 *out, u32 *err);
extern int func_02012B70(const struct BigObj *p);
extern void func_02164480(Flags *f, void *a, void *b);
struct Obj;
struct Owner;
struct Work;
extern u32 func_02028754(struct Obj *obj, u32 n);
extern int func_0216070C(struct Work *w);
extern u32 func_020307B0(void *p);
extern void *func_02188C7C(u8 *p);
extern void func_0216D9E4(void *p);
extern int func_0216060C(int a0, int a1);
extern void *func_0216075C(struct Owner *o, u16 id);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_021644F4(int i, void *a, void *p);
extern void *func_020127A4(struct SaveBlock *p);
extern u32 func_02012B28(const struct Rec44 *p);
extern void *func_021606DC(void *p, u32 a);

int func_0216025C(void *evt, u32 *state, Ctx *c)
{
    Flags flags;
    u32 idx;
    u32 err;
    u32 code;
    int r;
    int ok;
    int failed;
    int busy;
    u32 next;
    void *h;

    switch (*state) {
    case 0:
        code = func_0200C464(func_0200C404(func_02012EBC(func_020120F4(c->f04))), 0);
        failed = 0;
        r = func_0216040C(c->req, code);
        busy = 0;
        ok = func_02160564(code, &idx, &err);
        if (err == 0 && func_02012B70(func_020120F4(c->f04)) == 1) {
            failed = 1;
        } else if (ok == 1) {
            func_02164480(&flags, c->f04, c->f08);
            if (func_02028754((struct Obj *)(&flags), idx) == 0)
                failed = 1;
        }
        if (code == 9 && func_0216070C((struct Work *)c) == 0)
            busy = 1;
        if (failed == 1) {
            *state = 5;
        } else if (busy == 1) {
            *state = 7;
        } else {
            switch (r) {
            case 0:
                *state = 2;
                break;
            case 1:
                *state = 4;
                break;
            }
        }
        break;
    case 1:
        func_020307B0(c->req);
        func_0216D9E4(func_02188C7C(c->f08));
        return 1;
    case 2:
        if (func_0216060C((int)c, (int)state) != 0) {
            func_02012374(evt, func_0216075C((struct Owner *)c->req, c->id));
            *state = 3;
        }
        break;
    case 3:
        r = c->req->result;
        if (r == 0) {
            *state = 1;
        } else if (r == 1) {
            *state = 1;
        } else if (r == 3) {
            *state = 4;
        }
        break;
    case 4:
        next = c->req->next;
        func_020307B0(c->req);
        c->req = 0;
        h = (void *)func_021644F4(next, c->f04, c->f08);
        func_02012374(evt, h);
        *state = 6;
        break;
    case 5:
        next = c->req->next;
        func_020307B0(c->req);
        c->req = 0;
        if (next == 0) {
            if (func_02012B28(func_020127A4(func_020120F4(c->f04))) == 1)
                h = func_021606DC(c->f04, 1);
            else
                h = func_021606DC(c->f04, 0);
        } else {
            h = func_021606DC(c->f04, 0);
        }
        func_02012374(evt, h);
        *state = 6;
        break;
    case 6:
        func_0216D9E4(func_02188C7C(c->f08));
        return 1;
    case 7:
        func_020307B0(c->req);
        c->req = 0;
        func_02012374(evt, func_021606DC(c->f04, 2));
        *state = 8;
        break;
    case 8:
        func_0216D9E4(func_02188C7C(c->f08));
        return 1;
    }
    return 0;
}
