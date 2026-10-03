/*
 * function: func_0215FD0C
 * address:  0x0215FD0C
 * packet:   pkt_ov010_0215FD0C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Nine-state link setup task of the ov010 field (the extent ends at
 * 0x0215FEC6; 0x0215FEC8 is its unlabelled table-lookup leaf). State 3
 * keeps the call arm inside the negated test so the `return 1` block
 * follows it.
 *
 * symbols:
 *   func_02188CCC  0x02188CCC  thumb  ov021
 *   func_02188C7C  0x02188C7C  thumb  ov021
 *   func_021A0ED4  0x021A0ED4  thumb  ov021
 *   func_021A0F30  0x021A0F30  thumb  ov021
 *   func_021A0F94  0x021A0F94  thumb  ov021
 *   func_021A0FA8  0x021A0FA8  thumb  ov021
 *   func_021A12A4  0x021A12A4  thumb  ov021
 *   func_021945A4  0x021945A4  thumb  ov021
 *   func_0216D9A0  0x0216D9A0  thumb  ov010
 *   func_0216D9E4  0x0216D9E4  thumb  ov010
 *   func_0215FEC8  0x0215FEC8  thumb  ov010
 *   func_0215E840  0x0215E840  thumb  ov010
 *   func_0215EA30  0x0215EA30  thumb  ov010
 *   func_0215EA38  0x0215EA38  thumb  ov010
 *   func_0216075C  0x0216075C  thumb  ov010
 *   func_021644F4  0x021644F4  thumb  ov010
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_020129D0  0x020129D0  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_0201235C  0x0201235C  thumb
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Info {
    u16 id;
    u16 flags;
    u32 f04;
    u32 f08;
    void *obj;
    void *field;
} Info;

typedef struct Query {
    u16 a;
    u16 b;
    u32 c;
} Query;

typedef struct Ctx {
    u16 f00;            /* 0x00 */
    void *f04;          /* 0x04 */
    void *f08;          /* 0x08 */
    void *field;        /* 0x0C */
    u32 f10;            /* 0x10 */
    u32 state;          /* 0x14 */
    u32 f18;            /* 0x18 */
    u8 req[0x28 - 0x1C];/* 0x1C */
    u32 f28;            /* 0x28 */
    u8 pad2C[0x40 - 0x2C];
    u32 f40;            /* 0x40 */
    u32 f44;            /* 0x44 */
    u32 f48;            /* 0x48 */
    u32 f4c;            /* 0x4C */
} Ctx;

extern void *func_02188CCC(void *field);
struct BigObj;
struct Evt;
struct Obj;
struct S0201235C;
extern void *func_02188C7C(u8 *p);
extern int func_021A0ED4(void *link);
extern void func_021A0F30(void *link, int on);
extern int func_021A0F94(void *link);
extern void func_021A0FA8(int *p);
extern u32 func_021A12A4(void *link);
extern void *func_021945A4(void *sys, void *field, u32 arg);
extern void func_0216D9A0(void *map);
extern void func_0216D9E4(void *map);
extern u32 func_0215FEC8(u32 n);
extern void func_0215E840(void *field, Info *out);
extern void func_0215EA30(Query *q, u16 a, u16 b, u32 c);
extern void *func_0215EA38(u32 kind, Query *q, Info *info);
extern void *func_0216075C(void *req, u16 id);
extern void *func_021644F4(u32 i, void *a, void *b);
extern void *func_020124E4(struct Obj *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_020129D0(struct BigObj *p, u8 v);
extern void *func_0201210C(const struct Ctx *p);
extern void func_0201235C(struct S0201235C *o, u32 *out);
extern void func_02012374(struct Evt *evt, struct Evt **out);

int func_0215FD0C(void *task, void *unused, Ctx *c)
{
    Query q;
    Info info;
    void *map;
    void *sys;
    void *next;
    u32 n;
    int r;

    switch (c->state) {
    case 0:
        if (func_021A0ED4(func_02188CCC(c->field)) == 1) {
            map = func_02188C7C(c->field);
            sys = func_020120F4(func_020124E4(task));
            func_0216D9A0(map);
            func_020129D0(sys, 1);
            func_021A0F30(func_02188CCC(c->field), 1);
            c->state = 1;
        }
        break;
    case 1:
        r = func_021A0F94(func_02188CCC(c->field));
        if (r == 3) {
            c->state = 2;
            func_021A0FA8(func_02188CCC(c->field));
        } else if (r == 4) {
            c->state = 3;
            func_021A0FA8(func_02188CCC(c->field));
        }
        break;
    case 2:
        sys = func_020120F4(func_020124E4(task));
        n = func_021A12A4(func_02188CCC(c->field));
        func_020129D0(sys, n);
        c->f10 = func_021A12A4(func_02188CCC(c->field));
        c->f28 = func_0215FEC8(n);
        c->state = 5;
        break;
    case 3:
        func_0216D9E4(func_02188C7C(c->field));
        if (c->f40 != 1 && c->f40 != 4) {
            func_0201235C(task, func_021945A4(func_020124E4(task), c->field, c->f18));
            return 0;
        }
        return 1;
    case 4:
        func_0216D9E4(func_02188C7C(c->field));
        func_0215E840(func_0201210C(c->f08), &info);
        func_0215EA30(&q, c->f48, c->f44, c->f4c);
        next = func_0215EA38(c->f44, &q, &info);
        if (next == 0)
            return 1;
        func_0201235C(c->f04, next);
        break;
    case 5:
        func_02012374(task, func_0216075C(c->req, c->f00));
        c->state = 6;
        break;
    case 6:
        if (c->f40 == 0)
            c->state = 1;
        else if (c->f40 == 1)
            c->state = 3;
        else if (c->f40 == 3)
            c->state = 7;
        else if (c->f40 == 2)
            c->state = 4;
        else if (c->f40 == 4)
            c->state = 3;
        break;
    case 7:
        func_0216D9E4(func_02188C7C(c->field));
        func_02012374(task, func_021644F4(c->f44, c->f08, c->field));
        c->state = 8;
        break;
    case 8:
        return 1;
    }
    return 0;
}
