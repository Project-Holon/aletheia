/*
 * function: func_021607E0
 * address:  0x021607E0
 * packet:   pkt_ov010_021607E0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The fourteen-state task func_0216075C creates. The procedure table at
 * 0x021712CC has 24-byte records; each pool word is the table plus the
 * field offset.
 *
 * symbols:
 *   d_021712CC     0x021712CC  data
 *   func_02160A64  0x02160A64  thumb  ov010
 *   func_02160A4C  0x02160A4C  thumb  ov010
 *   func_02160A7C  0x02160A7C  thumb  ov010
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   FIELD_STATUS_CreateFieldOpenEvent  0x020145CC  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188DA0  0x02188DA0  thumb  ov021
 *   func_02188DB0  0x02188DB0  thumb  ov021
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Owner {
    void *f00;          /* 0x00 */
    void *f04;          /* 0x04 */
    u8 pad08[8];
    void *f10;          /* 0x10 */
    u8 pad14[0x10];
    u32 result;         /* 0x24 */
} Owner;

typedef struct Callbacks {
    void *fn[3];
    u32 arg;
    void *ctx;
} Callbacks;

typedef struct Task {
    u16 id;             /* 0x00 */
    u8 pad02[2];
    u32 proc;           /* 0x04 */
    u32 prev;           /* 0x08 */
    u32 next;           /* 0x0C */
    u32 state;          /* 0x10 */
    void *handle;       /* 0x14 */
    Owner *owner;       /* 0x18 */
    void *work;         /* 0x1C */
    Callbacks cb;       /* 0x20 */
} Task;

typedef struct Proc {
    void *f00;                                      /* 0x00 */
    void *f04;                                      /* 0x04 */
    void *(*init)(Task *t, void *arg, u32 prev, void *work); /* 0x08 */
    u32 (*finish)(Task *t, void *work);             /* 0x0C */
    void (*start)(Task *t, void *arg);              /* 0x10 */
    void (*exit)(void *work);                       /* 0x14 */
} Proc;

extern Proc d_021712CC[];

extern int func_02160A64(Callbacks *c);
extern int func_02160A4C(Callbacks *c);
extern int func_02160A7C(Callbacks *c);
struct IcaAnime;
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
struct Ctx;
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int FIELD_STATUS_CreateFieldCloseEvent(int a0, int a1);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *a);
extern void *func_0201210C(const struct Ctx *p);
extern void func_02188DA0(void);
extern void func_02188DB0(u8 *a);
extern void GAMESYSTEM_CallProc(struct IcaAnime *p, u32 id, void *a, void *b);
extern u32 GAMESYSTEM_GetProcStatus(const struct Ctx *p);
extern u32 func_020307B0(void *p);

int func_021607E0(void *evt, u32 *state, Task *t)
{
    u32 v;
    void *work;

    switch (*state) {
    case 0:
        *state = 1;
        break;
    case 1:
        v = t->state;
        if (v <= 1) {
            *state = 2;
        } else if (v == 4) {
            if (d_021712CC[t->proc].start == 0)
                *state = 6;
            else
                *state = 3;
        } else if (v == 3) {
            t->owner->result = 3;
            *state = 2;
        } else if (v == 2) {
            t->owner->result = 2;
            *state = 2;
        }
        break;
    case 2:
        v = t->state;
        if (v == 0)
            t->owner->result = 0;
        else if (v == 1)
            t->owner->result = 1;
        return 1;
    case 3:
        if (func_02160A64(&t->cb) == 0)
            break;
        d_021712CC[t->proc].start(t, t->owner->f10);
        *state = 4;
        break;
    case 4:
        *state = 5;
        break;
    case 5:
        if (t->state == 0) {
            if (func_02160A4C(&t->cb) == 0)
                break;
            *state = 1;
        } else {
            *state = 1;
        }
        break;
    case 6:
        func_02012374(evt, (struct Evt **)func_021BE8D4(t->owner->f00, (int)t->owner->f04, 0, 0));
        *state = 7;
        break;
    case 7:
        if (func_02160A64(&t->cb) == 0)
            break;
        func_02012374(evt, (struct Evt **)FIELD_STATUS_CreateFieldCloseEvent((int)t->owner->f00, (int)t->owner->f04));
        *state = 11;
        break;
    case 8:
        func_02160A7C(&t->cb);
        func_02012374(evt, FIELD_STATUS_CreateFieldOpenEvent(t->owner->f00));
        *state = 9;
        break;
    case 9:
        work = func_0201210C(t->owner->f00);
        t->owner->f04 = work;
        func_02188DA0();
        func_02188DB0(t->owner->f04);
        *state = 10;
        break;
    case 10:
        if (func_02160A4C(&t->cb) == 0)
            break;
        func_02012374(evt, (struct Evt **)func_021BE92C(t->owner->f00, (int)t->owner->f04, 0, 0, 0, 0, 0));
        *state = 1;
        break;
    case 11:
        work = d_021712CC[t->proc].init(t, t->owner->f10, t->prev, t->work);
        if (t->work != 0) {
            d_021712CC[t->prev].exit(t->work);
            t->work = 0;
        }
        t->work = work;
        if (d_021712CC[t->proc].f04 == 0)
            break;
        GAMESYSTEM_CallProc(t->owner->f00, (u32)d_021712CC[t->proc].f00, d_021712CC[t->proc].f04, work);
        *state = 12;
        break;
    case 12:
        if (GAMESYSTEM_GetProcStatus(t->owner->f00) != 0)
            break;
        *state = 13;
        break;
    case 13:
        t->state = d_021712CC[t->proc].finish(t, t->work);
        v = t->state;
        if (v == 0)
            t->owner->result = 0;
        else if (v == 1)
            t->owner->result = 1;
        else if (v == 3)
            t->owner->result = 3;
        else if (v == 2)
            t->owner->result = 2;
        if (t->state == 4) {
            t->prev = t->proc;
            t->proc = t->next;
            *state = 11;
        } else {
            if (t->work != 0) {
                func_020307B0(t->work);
                t->work = 0;
            }
            *state = 8;
        }
        break;
    }
    return 0;
}
