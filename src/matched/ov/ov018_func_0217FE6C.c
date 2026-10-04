/*
 * function: func_0217FE6C
 * address:  0x0217FE6C
 * packet:   pkt_ov018_0217FE6C
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Task callback in the shape of func_02182AA4: a 10-state sequence; state 0
 * copies the 0x98-byte work block into a temporary allocation (lines 493
 * and 517 of the file string at 0x02183B30) and hands it to one of the
 * follow-up task starters.
 *
 * symbols:
 *   func_020124E4  0x020124E4  thumb
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_0217F40C  0x0217F40C  thumb
 *   func_0217F3C4  0x0217F3C4  thumb
 *   func_02175DCC  0x02175DCC  thumb  ov011
 *   func_02030734  0x02030734  arm
 *   func_02082D44  0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02175BCC  0x02175BCC  thumb  ov011
 *   func_02175B14  0x02175B14  thumb  ov011
 *   func_02175B8C  0x02175B8C  thumb  ov011
 *   func_0217620C  0x0217620C  thumb  ov011
 *   func_02182A08  0x02182A08  thumb  ov018
 *   func_02182998  0x02182998  thumb  ov018
 *   func_02181BE8  0x02181BE8  thumb  ov018
 *   func_02182988  0x02182988  thumb  ov018
 *   func_02174258  0x02174258  thumb  ov011
 *   func_02175C40  0x02175C40  thumb  ov011
 *   func_0217C914  0x0217C914  thumb  ov018
 *   func_0217553C  0x0217553C  thumb  ov011
 *   func_02173C04  0x02173C04  thumb  ov011
 *   func_0217537C  0x0217537C  thumb  ov011
 *   func_021802A8  0x021802A8  thumb  ov018
 *   func_0217F420  0x0217F420  thumb
 *   func_0217FE38  0x0217FE38  thumb
 *   str_02183B30   0x02183B30  data   a1
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    void *f00;
    void *f04;
    void *f08;
    void *f0C;
    void *f10;
    void *f14;
    void *f18;
    void *f1C;
    void *f20;
    void *f24;
    unsigned char f28;
    unsigned char pad29[3];
    void *f2C;
} Ov018Obj;

typedef struct {
    u16 f00;            /* 0x00 */
    u8 pad02[0x10 - 2];
    Ov018Obj obj;       /* 0x10 */
    u8 f40;             /* 0x40 */
    u8 f41;             /* 0x41 */
    u8 pad42[0x98 - 0x42];
    u8 f98;             /* 0x98 */
    u8 f99;             /* 0x99 */
} Outer;

typedef struct {
    u16 lo : 9;
    u16 f9 : 6;
    u16 f15 : 1;
} Bits;

extern char str_02183B30[];

struct Obj;
void *func_020124E4(struct Obj *p);
struct Ctx;
u32 func_02012138(const struct Ctx *p);
u8 *func_02158344(void *);
int func_0217F40C(Ov018Obj *p);
void func_0217F3C4(Ov018Obj *p, int a);
int func_02175DCC(void *p);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
void func_02082D44(void *, void *, int);
void func_020307B0(void *);
u8 *func_02175BCC(u8 *p);
int func_02175B14(u8 *);
int func_02175B8C(u8 *);
int func_0217620C(u8 *, int);
void func_02182A08(void *, void *);
void func_02182998(void *, void *);
void func_02181BE8(void *, void *);
void func_02182988(void *, void *);
int func_02174258(u8 *);
int func_02175C40(void *p);
int func_0217C914(u8 *, Outer *, u8 *);
void func_0217553C(u8 *);
int func_02173C04(int, int);
u8 *func_0217537C(u8 *);
void func_021802A8(void *, Outer *, u8 *);
int func_0217F420(void);
void func_0217FE38(u8 *v, Outer *c);

int func_0217FE6C(void *a, int *state, Outer *c)
{
    u8 *v;
    u8 *p;
    void *t;
    int kind;
    Bits *b;

    v = func_02158344((void *)func_02012138(func_020124E4(a)));
    if (v == 0) {
        if (func_0217F40C(&c->obj) == 0) {
            return 0;
        }
        if (*state <= 6) {
            func_0217F3C4(&c->obj, 4);
            *state = 8;
            return 0;
        }
    }
    switch (*state) {
    case 0:
        kind = func_02175DCC(v + 0x1AC);
        b = (Bits *)(v + 0xA2 + c->f40 * 0x1C);
        if (b->f15 == 1) {
            t = func_02030734((u16)((c->f00 & 0x7FFF) | 0x8000), 0x98, 1, str_02183B30, 493);
            func_02082D44(c, t, 0x98);
            if (func_02175BCC(v + 0x1AC) == 0 && func_02175B14(v + 0x1AC) == 1
                && func_02175B8C(v + 0x1AC) == 1 && func_0217620C(v + 0x1AC, c->f40) == 1) {
                func_02182A08(a, t);
            } else {
                func_02182998(a, t);
            }
            func_020307B0(t);
        } else if (b->f9 != 0) {
            t = func_02030734((u16)((c->f00 & 0x7FFF) | 0x8000), 0x98, 1, str_02183B30, 517);
            func_02082D44(c, t, 0x98);
            if (((Bits *)(v + c->f40 * 0x1C + 0xA2))->f9 == 2) {
                if (kind == 5) {
                    func_02181BE8(a, t);
                } else {
                    func_02182988(a, t);
                }
            } else {
                func_02182998(a, t);
            }
            func_020307B0(t);
        } else {
            (*state)++;
        }
        break;
    case 1:
        if (func_02174258(v) == 1) {
            (*state)++;
        }
        break;
    case 2:
        switch (func_02175C40(v + 0x1AC)) {
        case 1:
            c->f99 = 1;
            (*state)++;
            break;
        case 2:
            (*state)++;
            break;
        }
        break;
    case 3:
        switch (func_0217C914(v, c, &c->f98)) {
        case 1:
            func_0217553C(v);
            *state = 4;
            break;
        case 2:
            *state = 9;
            break;
        case 3:
            *state = 7;
            break;
        }
        break;
    case 4:
        if (func_02173C04(c->f40, c->f99) == 1) {
            (*state)++;
        }
        break;
    case 5:
        p = func_0217537C(v);
        if (p != 0) {
            if (p[1] != c->f99 || c->f99 == 1) {
                c->f41 = 0;
            }
            (*state)++;
        }
        break;
    case 6:
        func_021802A8(a, c, v);
        return 0;
    case 7:
        *state = 9;
        break;
    case 8:
        if (func_0217F420() == 1) {
            *state = 9;
        }
        break;
    case 9:
        func_0217FE38(v, c);
        return 1;
    }
    return 0;
}
