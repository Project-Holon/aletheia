/*
 * file:     unit_021B23E0.c
 * unit:     yes
 * function: func_021B23E0, func_021B2488, func_021B24FC, func_021B2564, func_021B25B0, func_021B25FC, func_021B2620, func_021B26DC, func_021B2724, func_021B275C, func_021B279C, func_021B2848, func_021B2894, func_021B2958, func_021B29A4, func_021B2A20, func_021B2AA0, func_021B2BE0, func_021B2D54, func_021B2DD0, func_021B2ED8
 * address:  0x021B23E0
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B4BD0  0x021B4BD0  data  ov013  a4
 *   d_021B3C48  0x021B3C48  data  ov013  a4
 *   d_021B4BE0  0x021B4BE0  data  a4
 *   func_020870D0  0x020870D0  arm
 *   func_021B2010  0x021B2010  arm  ov013
 *   func_021B20D4  0x021B20D4  arm  ov013
 *   func_02176E90  0x02176E90  arm  ov009
 *   func_020923B0 0x020923B0 arm
 *   d_021B3AF0  0x021B3AF0  data  ov013  a1
 *   d_021B3AF5  0x021B3AF5  data  ov013  a1
 *   d_021B3BC8  0x021B3BC8  data  ov013  a1
 *   d_021B3AFC  0x021B3AFC  data  ov013  a1
 *   d_021B3B40 0x021B3B40 data ov013 a1
 *   d_021B3B84 0x021B3B84 data ov013 a1
 *   func_021B1F54  0x021B1F54  arm  ov013
 *   d_021B4C24 0x021B4C24 data a4
 *   func_02082AC0 0x02082AC0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed char s8;

typedef struct Node {
    u32 state;
    u8 f4;
    u8 f5;
    u16 f6;
    u32 f8;
    int fC;
    u32 f10;
    struct Node *next;
} Node;

typedef struct Pool {
    Node *nodes;
    Node *head;
    void *tick;
    u32 mul;
    u32 add;
    Node freeList;
    Node active;
} Pool;

typedef struct Sess {
    u8 id;
    u8 f1;
    u8 pad2[2];
    void (*cb)(int, int, void *, unsigned int);
    u32 arg;
    int fC;
    int state;
    u32 f14;
} Sess;

typedef struct Stat {
    int f0;
    int mask;
    u64 t;
} Stat;

typedef struct Pkt {
    u32 magic;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u8 f8;
    u8 f9;
    u8 fa;
    u8 fb;
    u32 fc;
} Pkt;

typedef struct Event {
    int type;
    Node *node;
} Event;

typedef struct E {
    struct E *next;
    u8 pad[0x474];
} E;

typedef struct {
    E *cur;
    E *buf;
} G;

extern u64 func_020870D0(void);
extern int func_02176E90(int i, Pkt *p, int n);
extern void *func_020923B0(void *, int, unsigned int);
extern void func_02082AC0(int, void *, u32);
extern int func_021B1F54(Node *p);
extern int func_021B2010(void *a, unsigned int b, unsigned char *buf, unsigned int c);
extern int func_021B20D4(Node *a, unsigned int b, unsigned char *buf, unsigned int c);
void func_021B23E0(void);
int func_021B2488(int a, Pkt *p, int len, Event *x);
Node *func_021B24FC(unsigned int idx);
int func_021B2564(int a, int b);
int func_021B25B0(int a, int b);
void func_021B25FC(Node *a, Pkt *b);
int func_021B2620(Node *o, Pkt *p);
void func_021B26DC(int x);
void func_021B2724(Node *p, unsigned int v);
int func_021B275C(Node *o, Pkt *p);
int func_021B279C(Pkt *o, Node *q);
int func_021B2848(Node *o, Pkt *p, int n);
int func_021B2894(Node *c, Pkt *m);
int func_021B2958(Node *p);
int func_021B29A4(Node *obj, const Pkt *q);
Node *func_021B2A20(int id);
int func_021B2AA0(Pkt *pkt, Event *ev);
int func_021B2BE0(Pkt *pkt, Event *ev);
int func_021B2D54(Pkt *p, Event *out);
int func_021B2DD0(Pkt *pkt, Event *ev);
int func_021B2ED8(E *a, u32 b);
extern Sess d_021B60D8;
extern Stat d_021B4BD0;
extern u64 d_021B3C48;
extern Pool d_021B4BE0;
extern u8 d_021B3AF0[];
extern u8 d_021B3AF5[];
extern s8 d_021B3BC8[][11];
extern s8 d_021B3AFC[][11];
extern s8 d_021B3B40[], d_021B3B84[];
extern G d_021B4C24;


void func_021B23E0(void)
{
    u64 now;

    now = func_020870D0();
    if (d_021B60D8.state != 2)
        return;
    if (d_021B60D8.fC == 0)
        return;
    if (d_021B4BD0.t == 0)
        return;
    if (now - d_021B4BD0.t <= d_021B3C48)
        return;
    d_021B4BD0.t = 0;
    d_021B4BE0.active.state = 0;
    d_021B4BE0.active.fC = 0;
    func_021B26DC(0);
    d_021B60D8.cb(d_021B4BE0.active.f4, 9, &d_021B4BE0.active, d_021B60D8.arg);
}

int func_021B2488(int a, Pkt *p, int len, Event *x)
{
    if (len != 0x10)
        return 0;
    if (p->f8 != a || p->f9 != d_021B60D8.id)
        return 0;
    if (p->f5 != 0x10)
        return func_021B2D54(p, x);
    if (d_021B60D8.fC == 0)
        return func_021B2AA0(p, x);
    return func_021B2BE0(p, x);
}

Node *func_021B24FC(unsigned int idx)
{
    Node *n;

    if (idx >= 0x20)
        return 0;
    if (idx == d_021B60D8.id)
        return 0;
    n = d_021B4BE0.nodes;
    if (n == 0)
        return 0;
    d_021B4BE0.nodes = n->next;
    func_021B2724(n, idx);
    n->next = d_021B4BE0.head;
    d_021B4BE0.head = n;
    return n;
}

int func_021B2564(int a, int b)
{
    u8 buf[16];
    int r;

    r = func_021B2010((void *)a, b, buf, 16);
    if (r != 0)
        return r;
    if (func_021B275C((Node *)a, (Pkt *)buf) != 0)
        return 0;
    return -4;
}

int func_021B25B0(int a, int b)
{
    u8 buf[16];
    int r;

    r = func_021B20D4((Node *)a, b, buf, 16);
    if (r != 0)
        return r;
    if (func_021B275C((Node *)a, (Pkt *)buf) != 0)
        return 0;
    return -4;
}

void func_021B25FC(Node *a, Pkt *b)
{
    if (b->fa == 1) {
        b->fb = a->f4;
        b->fc = d_021B4BD0.mask;
    }
}

int func_021B2620(Node *o, Pkt *p)
{
    int cnt;
    u8 i;

    cnt = 0;
    func_021B25FC(o, p);
    for (i = 0; i < 0x20; i++) {
        unsigned int m = (i != 0) ? (1 << i) : 1;
        if ((d_021B4BD0.mask & m) != 0 && i != d_021B60D8.id) {
            p->f9 = i;
            if (func_02176E90(i, p, 0x10) != 0)
                cnt++;
        }
    }
    if (p->fa == 1)
        o->f8 = d_021B4BD0.mask;
    else if (p->fa == 0)
        o->f8 = 0;
    return cnt == 0 ? -4 : 0;
}

void func_021B26DC(int x)
{
    u8 buf[16];

    ((Pkt *)buf)->f4 = 0xff;
    func_021B2848(&d_021B4BE0.active, (Pkt *)buf, 4);
    ((Pkt *)buf)->fa = x;
    func_021B2620(&d_021B4BE0.active, (Pkt *)buf);
}

void func_021B2724(Node *p, unsigned int v)
{
    func_020923B0(p, 0, 24);
    p->state = d_021B60D8.state;
    p->fC = 0;
    p->f4 = v;
}

int func_021B275C(Node *o, Pkt *p)
{
    if (p->f4 == 0xff && p->f6 == 4) {
        func_021B2620(o, p);
    } else if (func_02176E90(o->f4, p, 0x10) == 0) {
        return 0;
    }
    return 1;
}

int func_021B279C(Pkt *o, Node *q)
{
    q->f5 = o->fb;
    if (o->f4 == 0xff) {
        if (o->f6 == 0) {
            q->f8 = (q->f4 != 0) ? (1 << q->f4) : 1;
        }
        return d_021B3AF0[o->f6];
    }
    if (o->f4 == 0) {
        if (o->f6 == 0) {
            if (q->fC == 1) {
                q->f8 = (q->f4 != 0) ? (1 << q->f4) : 1;
                return 7;
            }
            if (q->fC == 5)
                return 9;
            return 12;
        }
        return d_021B3AF5[o->f6];
    }
    return 12;
}

/*
 * lever: Returning zero keeps the clearing value in r0 and frees r2 for byte loads.
 */
int func_021B2848(Node *o, Pkt *p, int n)
{
    p->magic = 0x5f564354;
    p->f5 = 0x10;
    p->f6 = n;
    p->f8 = d_021B60D8.id;
    p->f9 = o->f4;
    p->fa = 0;
    p->fb = d_021B60D8.id;
    p->fc = 0;
    return 0;
}

int func_021B2894(Node *c, Pkt *m)
{
    int i;
    int r;

    i = m->f6;
    if (m->f4 == 0)
        i += 5;
    if ((unsigned int)i >= 0xb)
        i = -1;
    if (i < 0)
        return -1;
    if (d_021B60D8.state == 1)
        r = d_021B3BC8[c->fC][i];
    else
        r = d_021B3AFC[c->fC][i];
    switch (r) {
    case -1:
        return r;
    case -2:
        func_021B25B0((int)c, 1);
        c->fC = 0;
        c->state = 0;
        return r;
    case -3:
        func_021B25B0((int)c, 3);
        c->fC = 0;
        c->state = 0;
        return r;
    default:
        return r;
    }
}

int func_021B2958(Node *p)
{
    Node *n;

    n = d_021B4BE0.head;
    while (n) {
        if (n->state != 0 && n->fC == 2) {
            if (p != n)
                return 0;
        }
        n = n->next;
    }
    return 1;
}

static inline s8 lookup(u32 t, int row, u32 col) { return *(s8 *)(row * 11 + t + col); }

/*
 * lever: Calling the indexed inline in each table-selection arm restores the MLA register and independent -1/-2 constants.
 * checks: Per-arm inline lookup is EXACT; one data table in each arm preserves the original dispatch.
 */
int func_021B29A4(Node *obj, const Pkt *q)
{
    u32 i;
    int v;
    i = q->f6;
    if (q->f4 == 0)
        i += 5;
    if (i >= 11)
        i = -1;
    if ((int)i < 0)
        return -1;
    if (d_021B60D8.state == 1)
        v = lookup((u32)d_021B3B40, obj->fC, i);
    else
        v = lookup((u32)d_021B3B84, obj->fC, i);
    if (v == -1)
        return 1;
    if (v == -2)
        return 0;
    obj->fC = v;
    return 1;
}

Node *func_021B2A20(int id)
{
    Node *n;

    n = d_021B4BE0.head;
    if (d_021B60D8.state == 2) {
        if (d_021B4BE0.active.state != 0 && d_021B4BE0.active.f4 == id)
            return &d_021B4BE0.active;
        return 0;
    }
    while (n) {
        if (n->state != 0 && n->f4 == id)
            return n;
        n = n->next;
    }
    return 0;
}

int func_021B2AA0(Pkt *pkt, Event *ev)
{
    Node *node;
    int r;

    if (pkt->f4 == 0xFF) {
        if (pkt->f6 == 4)
            return func_021B2DD0(pkt, ev);
        if (pkt->f6 == 3)
            return 0;
    }
    node = func_021B2A20(pkt->f8);
    if (node) {
        r = func_021B2894(node, pkt);
        switch (r) {
        case -1:
            return 0;
        case -2:
            ev->type = 0xC;
            node->state = 0;
            ev->node = node;
            return 1;
        }
        ev->type = func_021B279C(pkt, node);
        ev->node = node;
        node->fC = r;
        return ev->type != 0;
    }
    node = func_021B24FC(pkt->f8);
    if (node == 0) {
        func_021B2724(&d_021B4BE0.freeList, pkt->f8);
        func_021B25B0((int)&d_021B4BE0.freeList, 3);
        return 0;
    }
    r = func_021B2894(node, pkt);
    if (r == -2 || r == -1) {
        func_021B1F54(node);
        return 0;
    }
    ev->type = func_021B279C(pkt, node);
    ev->node = node;
    node->fC = r;
    return ev->type != 0;
}

/*
 * note: Audio session start/continue gate.
 *
 * note pass 2 2026-10-06 P2L53: EXACT (c99 and c). The event fill
 * (ev->type, ev->node, n->fC) is written out in each arm and only the tick
 * stamp is shared. The two fill copies are cross-jumped after jump threading,
 * which leaves the lone `b` hop at +0x88 (idiom
 * a-conditional-branch-onto-an-unconditional-b-is-a-cross-jumped-tail-copy).
 * The ev->type compare then sits after a join with two stored values, so it
 * is reloaded (`ldr r0,[r7]`), and the zero/result colours (r6/r4) follow.
 */
int func_021B2BE0(Pkt *pkt, Event *ev)
{
    Node *n;
    int r;

    if (d_021B4BE0.active.state == 2) {
        if (d_021B4BE0.active.f4 == pkt->f8) {
            n = &d_021B4BE0.active;
            r = func_021B2894(n, pkt);
            switch (r) {
            case -2:
                ev->type = 0xC;
                ev->node = 0;
                return 1;
            case -3:
            case -1:
                return 0;
            default:
                break;
            }
            ev->type = func_021B279C(pkt, n);
            ev->node = n;
            n->fC = r;
        } else {
            func_021B26DC(1);
            return 0;
        }
    } else {
        if (!(d_021B4BD0.mask & ((pkt->f8 != 0) ? (1 << pkt->f8) : 1)))
            return 0;
        d_021B4BE0.active.f4 = pkt->f8;
        d_021B4BE0.active.state = 2;
        d_021B4BE0.active.fC = 0;
        n = &d_021B4BE0.active;
        r = func_021B2894(n, pkt);
        switch (r) {
        case -3:
        case -2:
        case -1:
            d_021B4BE0.active.state = 0;
            return 0;
        }
        ev->type = func_021B279C(pkt, n);
        ev->node = n;
        n->fC = r;
    }
    if (ev->type == 10) {
        func_021B26DC(1);
        d_021B4BD0.t = func_020870D0();
    } else {
        func_021B26DC(0);
        d_021B4BD0.t = 0;
    }
    return 1;
}

int func_021B2D54(Pkt *p, Event *out)
{
    Node *n;

    if (p->f4 == 0xff && p->f6 == 4)
        return 0;
    n = func_021B2A20(p->f8);
    if (n) {
        out->type = 2;
        out->node = n;
        n->state = 0;
        func_021B25B0((int)n, 2);
        return 1;
    }
    func_021B2724(&d_021B4BE0.freeList, p->f8);
    func_021B25B0((int)&d_021B4BE0.freeList, 2);
    return 0;
}

int func_021B2DD0(Pkt *pkt, Event *ev)
{
    if (d_021B60D8.state != 2)
        return 0;
    if (d_021B60D8.f1 != pkt->f8)
        return 0;
    switch (pkt->fa) {
    case 0:
        if (d_021B4BE0.active.state == 0)
            return 0;
        if (d_021B4BE0.active.fC == 5 || d_021B4BE0.active.fC == 2)
            ev->type = 9;
        else
            ev->type = 5;
        d_021B4BE0.active.state = 0;
        d_021B4BE0.active.fC = 0;
        ev->node = &d_021B4BE0.active;
        break;
    case 1:
        d_021B4BE0.active.state = 2;
        if (pkt->fb == d_021B60D8.id) {
            d_021B4BE0.active.fC = 2;
            ev->type = 7;
            d_021B4BE0.active.f8 = pkt->fc;
        } else {
            d_021B4BE0.active.fC = 3;
            ev->type = 6;
            d_021B4BE0.active.f8 = pkt->fb == 0 ? 1 : 1 << pkt->fb;
        }
        d_021B4BE0.active.f5 = pkt->fb;
        ev->node = &d_021B4BE0.active;
        break;
    default:
        return 0;
    }
    return 1;
}

/*
 * lever: fill call takes data, p and b; r1/r2 stay live across the guards.
 */
int func_021B2ED8(E *a, u32 b)
{
    u32 i;
    u32 n;
    E *p;
    n = b / 0x478;
    p = a;
    d_021B4C24.buf = p;
    if (n < 4 || n > 0x48) return 0;
    if (p == 0) return 0;
    if ((u32)p & 0x1f) {
        d_021B4C24.buf = 0;
        return 0;
    }
    i = 0;
    func_02082AC0(i, p, b);
    for (i = 0; i < n - 1; i++)
        d_021B4C24.buf[i].next = &d_021B4C24.buf[i + 1];
    (d_021B4C24.buf + n)[-1].next = 0;
    d_021B4C24.cur = d_021B4C24.buf;
    return 1;
}
