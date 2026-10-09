/*
 * file:     unit_021B1498.c
 * unit:     yes
 * function: func_021B1498, func_021B14A8, func_021B14F8, func_021B1588, func_021B1634, func_021B1688, func_021B16B4, func_021B16E4, func_021B1720, func_021B1790, func_021B1810, func_021B190C, func_021B1944, func_021B19AC, func_021B19BC, func_021B1A48, func_021B1A74, func_021B1AA0, func_021B1AC0, func_021B1B94, func_021B1F2C, func_021B1F54, func_021B2010, func_021B20B0, func_021B20D4, func_021B2180, func_021B21A4, func_021B2254, func_021B22B4
 * address:  0x021B1498
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
 *   d_021B4BA0 0x021B4BA0 data a4
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   d_021B4B98  0x021B4B98  data  a4
 *   d_021B3C28 0x021B3C28 data a4
 *   d_021B4BC4 0x021B4BC4 data a4
 *   d_021B4BAC 0x021B4BAC data a4
 *   d_021B4BB8 0x021B4BB8 data a4
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   func_02082BCC  0x02082BCC  arm
 *   func_020870D0  0x020870D0  arm
 *   d_021B60D8 0x021B60D8 data a4
 *   func_021B24FC 0x021B24FC arm ov013
 *   d_021B4BE0  0x021B4BE0  data  a4
 *   func_021B2848  0x021B2848  arm  ov013
 *   func_021B29A4  0x021B29A4  arm  ov013
 *   func_021B2958  0x021B2958  arm  ov013
 *   func_021B2564 0x021B2564 arm ov013
 *   func_021B25B0 0x021B25B0 arm ov013
 *   d_021B4BD0     0x021B4BD0  data  ov013  a4
 *   func_021B2A20  0x021B2A20  arm   ov013
 */
struct N;
struct Msg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct Voice {
    u32 f0;
    struct Voice *prev;
    struct Voice *next;
    int fC;
    u8 f10;
    u8 f11;
    u8 pad12[2];
    u32 f14;
    u32 f18;
    u8 buf[0x45c - 0x1c];
    u32 f45C;
    u32 f460;
    u64 tick;
    u32 f46C;
    u32 f470;
    void *f474;
} Voice;

typedef struct Node {
    u32 f0;
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
    Node *activeHead;
    void *tick;
    u32 mul;
    u32 add;
    Node freeList;
    Node active;
} Pool;

typedef struct Sess {
    u8 id;
    u8 pad1[3];
    void (*cb)(int, int, void *, unsigned int);
    u32 arg;
    int fC;
    int state;
    u32 f14;
} Sess;

typedef struct Stat {
    int f0;
    int mask;
} Stat;

struct Src {
    u32 f0;
    u32 delay;                  /* 0x04 */
    u32 f8;
    int drift;                  /* 0x0C */
    u32 lastSeq;                /* 0x10 */
    u32 dropped;                /* 0x14 */
    int jitterOut;              /* 0x18 */
    u32 reordered;              /* 0x1C */
    u8 pad20[8];
    u32 f28;
    u32 f2C;
    u32 f30;
    u32 f34;
    int f38;
    Voice *f3C;
    u32 f40;
    u64 tick0;                  /* 0x44 */
    u32 ts0;                    /* 0x4C */
    u32 f50;
    u32 maxSeq;                 /* 0x54 */
    u32 f58;
    u32 probation;              /* 0x5C */
    u32 cycles;                 /* 0x60 */
    u32 badSeq;                 /* 0x64 */
    u16 baseSeq;                /* 0x68 */
    u16 f6a;
    u32 count;                  /* 0x6C */
    u32 driftEvents;            /* 0x70 */
    int avg;                    /* 0x74 */
    int base;                   /* 0x78 */
    int jitter;                 /* 0x7C */
    int transit;                /* 0x80 */
    int hold;                   /* 0x84 */
    int lo;                     /* 0x88 */
    u32 hi;                     /* 0x8C */
    u32 lowCount;               /* 0x90 */
};

struct Pkt {
    unsigned char pad0[0x18];
    unsigned int seq;           /* 0x18 */
    unsigned char pad1c[0x440];
    unsigned int marker;        /* 0x45C */
    unsigned int ts;            /* 0x460 */
    unsigned long long tick;    /* 0x464 */
    unsigned long long play;    /* 0x46C */
};

struct Config {
    Node *nodes;
    unsigned int count;
};

extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern void func_021B2FE4(Voice *n);
extern void func_02082BCC(void *p, int v, int n);
extern unsigned long long func_020870D0(void);
extern Node *func_021B24FC(unsigned int);
extern void func_021B2848(void *a, void *b, unsigned int c);
extern int func_021B29A4(int *obj, const u8 *q);
extern int func_021B2958(struct N *p);
extern int func_021B2564(int, int);
extern int func_021B25B0(int, int);
extern struct N *func_021B2A20(int id);
int func_021B1498(unsigned int i);
Voice *func_021B14A8(u32 type);
u32 func_021B14F8(Voice *n);
void func_021B1588(unsigned char *dst, const short *src, unsigned int n);
void func_021B1634(unsigned char *src, short *dst, unsigned int n);
void func_021B1688(unsigned char *dst, short *src, unsigned int n);
void func_021B16B4(signed char *src, short *dst, unsigned int n, int fmt);
void func_021B16E4(unsigned int i);
void func_021B1720(u32 t);
void func_021B1790(void);
int func_021B1810(Voice *n, u32 idx);
void *func_021B190C(unsigned int i);
Voice *func_021B1944(u32 t);
int func_021B19AC(unsigned int i);
void func_021B19BC(struct Src *p, u32 a1, int a2);
void func_021B1A48(struct Src *p);
void func_021B1A74(struct Src *p, Voice *a1);
void func_021B1AA0(struct Src *p, u16 v);
int func_021B1AC0(struct Src *p, struct Pkt *pkt, u16 seq);
int func_021B1B94(struct Src *s, struct Pkt *pkt);
Node *func_021B1F2C(unsigned int i);
int func_021B1F54(Node *p);
int func_021B2010(void *a, unsigned int b, unsigned char *buf, unsigned int c);
int func_021B20B0(int a, int b);
int func_021B20D4(Node *a, unsigned int b, unsigned char *buf, unsigned int c);
int func_021B2180(int a, int b);
int func_021B21A4(unsigned char id);
int func_021B2254(int a);
int func_021B22B4(struct Config *cfg);
extern Voice *d_021B4B98[2];
extern int d_021B4BA0[];
extern Voice *d_021B4BAC[3];
extern u32 d_021B4BB8[3];
extern Voice *d_021B4BC4[3];
extern Stat d_021B4BD0;
extern Pool d_021B4BE0;
extern Sess d_021B60D8;
extern const int d_021B3C28[8];








int func_021B1498(unsigned int i) { return d_021B4BA0[i]; }









Voice *func_021B14A8(u32 type)
{
    Voice *p = d_021B4B98[0];
    u32 h = func_02087988();

    for (; p; p = p->next) {
        if (p->f11 == type) {
            func_0208799C(h);
            return p;
        }
    }
    func_0208799C(h);
    return 0;
}









u32 func_021B14F8(Voice *n)
{
    u32 h = func_02087988();

    if (n->prev)
        n->prev->next = n->next;
    else {
        d_021B4B98[0] = n->next;
        if (n->next)
            n->next->prev = 0;
    }
    if (n->next)
        n->next->prev = n->prev;
    else {
        d_021B4B98[1] = n->prev;
        if (n->prev)
            n->prev->next = 0;
    }
    d_021B4BA0[n->f11]--;
    func_0208799C(h);
    return d_021B4BA0[n->f11];
}









/*
 * note: 2026-10-05 tried forms (all DIFF 26/172): an inline encode() with an
 *   inline seg_search() helper, mask types and orders, clamp spellings,
 *   pragmas opt_lifetimes, scheduling, peephole, opt_common_subs,
 *   opt_propagation, opt_dead_assignments, opt_dead_code,
 *   opt_strength_reduction, opt_loop_invariants.
 * note: pass 2 2026-10-06 P2L37: EXACT. The u-law encode is written in the
 *   loop body (no inline helpers). The segment search uses seg as its own
 *   counter, with a goto on a hit and seg = 8 on fall-through, as the helper's
 *   "return size". The code value goes through an int uval and the store is
 *   dst[i] = uval ^ mask. With the inline helpers, the mask and the segment
 *   counter swapped registers (r5/r6).
 */
void func_021B1588(unsigned char *dst, const short *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++) {
        int s, seg, uval;
        unsigned char mask;
        const int *tab;

        s = src[i] >> 2;
        if (s < 0) {
            mask = 0x7f;
            s = -s;
        } else {
            mask = 0xff;
        }
        if (s > 8159)
            s = 8159;
        tab = d_021B3C28;
        for (seg = 0; seg < 8; seg++)
            if (s + 0x21 <= *tab++)
                goto found;
        seg = 8;
    found:
        if (seg >= 8) {
            dst[i] = 0x7f ^ mask;
        } else {
            uval = (seg << 4) | (((s + 0x21) >> (seg + 1)) & 0xf);
            dst[i] = uval ^ mask;
        }
    }
}








void func_021B1634(unsigned char *src, short *dst, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++) {
        int u = ~src[i];
        int t = (((u & 0xf) << 3) + 0x84) << ((u & 0x70) >> 4);

        dst[i] = (u & 0x80) ? 0x84 - t : t - 0x84;
    }
}








void func_021B1688(unsigned char *dst, short *src, unsigned int n)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        dst[i] = (signed char)(src[i] >> 8);
}








void func_021B16B4(signed char *src, short *dst, unsigned int n, int fmt)
{
    unsigned int i;

    for (i = 0; i < n; i++)
        dst[i] = (short)(src[i] << 8);
}







void func_021B16E4(unsigned int i)
{
    u32 h = func_02087988();
    d_021B4BC4[i] = 0;
    d_021B4BAC[i] = 0;
    d_021B4BB8[i] = 0;
    func_0208799C(h);
}








void func_021B1720(u32 t)
{
    Voice *n;
    u32 h = func_02087988();

    n = d_021B4BAC[t];
    while (n) {
        Voice *nx = n->next;
        d_021B4BAC[t] = nx;
        if (nx)
            nx->prev = 0;
        func_021B2FE4(n);
        n = d_021B4BAC[t];
    }
    d_021B4BC4[t] = 0;
    d_021B4BB8[t] = 0;
    func_0208799C(h);
}








void func_021B1790(void)
{
    int t;
    Voice *n;
    u32 h = func_02087988();

    t = 0;
    while (t < 3) {
        while ((n = d_021B4BAC[t]) != 0) {
            Voice *nx = n->next;

            d_021B4BAC[t] = nx;
            if (nx)
                nx->prev = 0;
            func_021B2FE4(n);
        }
        d_021B4BC4[t] = 0;
        d_021B4BB8[t] = 0;
        t++;
    }
    func_0208799C(h);
}







int func_021B1810(Voice *n, u32 idx)
{
    int irq;
    Voice *cur;

    if (n == 0)
        return -1;
    if (idx >= 3)
        return -1;

    irq = func_02087988();
    if (d_021B4BAC[idx] == 0) {
        d_021B4BAC[idx] = n;
        n->prev = 0;
        d_021B4BAC[idx]->next = 0;
        d_021B4BC4[idx] = d_021B4BAC[idx];
    } else {
        for (cur = d_021B4BC4[idx]; cur != 0; cur = cur->prev) {
            if (cur->f18 < n->f18) {
                n->prev = cur;
                n->next = cur->next;
                cur->next = n;
                if (n->next != 0)
                    n->next->prev = n;
                if (cur == d_021B4BC4[idx])
                    d_021B4BC4[idx] = n;
                goto done;
            }
        }
        n->prev = 0;
        n->next = d_021B4BAC[idx];
        d_021B4BAC[idx]->prev = n;
        d_021B4BAC[idx] = n;
    }
done:
    d_021B4BB8[idx]++;
    func_0208799C(irq);
    return d_021B4BB8[idx];
}






void *func_021B190C(unsigned int i)
{
    u32 h = func_02087988();
    if (d_021B4BAC[i] != 0) {
        func_0208799C(h);
        return d_021B4BAC[i];
    }
    func_0208799C(h);
    return 0;
}







Voice *func_021B1944(u32 t)
{
    Voice *n;
    u32 h = func_02087988();

    n = d_021B4BAC[t];
    if (n) {
        Voice *next = n->next;

        d_021B4BAC[t] = next;
        d_021B4BB8[t]--;
        if (next)
            next->prev = 0;
        else
            d_021B4BC4[t] = 0;
    }
    func_0208799C(h);
    return (Voice *)d_021B4BB8[t];
}






int func_021B19AC(unsigned int i) { return d_021B4BB8[i]; }







void func_021B19BC(struct Src *p, u32 a1, int a2)
{
    func_02082BCC(p, 0, 0x28);
    p->delay = 0x134DF;
    p->f28 = 0;
    p->f2C = 0;
    p->f34 = a1;
    p->f38 = a2;
    p->jitter = 0;
    p->transit = 0;
    p->hold = 0;
    p->lo = 0;
    p->hi = 0x134DF;
    p->lowCount = 0;
    p->ts0 = 0;
    p->tick0 = 0;
    p->count = 0;
    p->driftEvents = 0;
    p->f50 = 0;
    p->maxSeq = 0;
    p->f58 = 0;
    p->probation = 1;
    p->f3C = 0;
    p->f40 = 0;
    p->f30 = 0;
}







void func_021B1A48(struct Src *p)
{
    if (p->f3C) {
        func_021B2FE4(p->f3C);
        p->f3C = 0;
    }
    p->f38 = -1;
}







void func_021B1A74(struct Src *p, Voice *a1)
{
    if (p->f3C)
        func_021B2FE4(p->f3C);
    p->f3C = a1;
    func_021B1944(p->f34);
}







void func_021B1AA0(struct Src *p, u16 v)
{
    p->baseSeq = v;
    p->badSeq = 0x00010001;
    p->cycles = 0;
    p->probation = 0;
}







/*
 * RFC 3550 update_seq shape: MAX_DROPOUT 3000, MAX_MISORDER 100.
 */
int func_021B1AC0(struct Src *p, struct Pkt *pkt, u16 seq)
{
    u16 last = p->baseSeq;
    u16 delta = seq - last;

    if (delta < 3000) {
        if (seq < last)
            p->cycles += 0x10000;
        p->baseSeq = seq;
    } else if (delta <= 0x10000 - 100) {
        if (seq == p->badSeq) {
            func_021B1AA0(p, seq);
            p->maxSeq = (u16)(seq - 1);
        } else {
            p->badSeq = (u16)(seq + 1);
            return 0;
        }
    } else if (seq + p->cycles > p->maxSeq + 0x10000 - 100) {
        pkt->seq = seq + p->cycles - 0x10000;
        return 1;
    }
    pkt->seq = seq + p->cycles;
    return 1;
}







/*
 * RTP receive bookkeeping: sequence check (func_021B1AC0), interarrival
 * jitter (J += (|D| - J) / 16), playout-time and drift tracking. The
 * constants are OS ticks (OS_MilliSecondsToTicks folded): 0x8B18 = 68 ms,
 * 0x7FD88 ~ 1 s, 0x134DF = 151 ms, 0x68520 = 816 ms, 0x8701 = 66 ms.
 * The `(unsigned int)q` in the delay store is what keeps the original's
 * second `q * 0x8B18` (fresh pool load, fresh mul) from being CSE'd with
 * the one in `s->lo`.
 */
int func_021B1B94(struct Src *s, struct Pkt *pkt)
{
    int transit;
    int flag = 0;
    int tsd;
    int d;
    int q;
    int j3;
    unsigned long long now;

    if (s->probation != 0) {
        func_021B1AA0(s, pkt->seq);
    } else {
        if (!func_021B1AC0(s, pkt, pkt->seq)) {
            s->dropped++;
            return flag;
        }
        s->lastSeq = pkt->seq;
        if (s->maxSeq == pkt->seq) {
            s->dropped++;
            return flag;
        }
        if (s->maxSeq + 1 != pkt->seq && pkt->marker == 0) {
            d = pkt->seq - s->maxSeq;
            if (d < 0)
                d = -d;
            if (d > 100) {
                s->maxSeq = pkt->seq;
                return 0;
            }
            if (s->maxSeq > pkt->seq)
                s->reordered++;
        }
    }
    s->maxSeq = pkt->seq;
    if (s->ts0 == 0) {
        s->ts0 = pkt->ts;
        s->tick0 = pkt->tick;
        s->count = 0;
    }
    tsd = (pkt->ts - s->ts0) << 6;
    transit = (int)((unsigned int)tsd - (pkt->tick - s->tick0));
    if (s->transit == 0 || pkt->marker != 0) {
        s->transit = transit;
    } else {
        d = transit - s->transit;
        if (d < 0)
            d = -d;
        s->transit = transit;
        if ((unsigned long long)d > (long long)((s->jitter + 0x8B18) * 2) + 0xCC8DULL)
            s->hold = d / 0x8B18 + 2;
        if (s->hold <= 0)
            s->jitterOut = s->jitter = s->jitter + ((d - s->jitter) >> 4);
    }
    pkt->play = s->delay + ((unsigned int)tsd + s->tick0);
    now = func_020870D0();
    if (pkt->play + 0x8B18 < now)
        return 0;
    if (pkt->play > now + 0x7FD88)
        return 0;
    if (s->hold <= 0) {
        j3 = s->jitter * 3;
        q = j3 / 0x8B18;
        if (j3 > s->hi) {
            s->hi = (q + 1) * 0x8B18 + 0x134DF;
            s->lo = s->hi - 0xD0A4;
            s->delay = (unsigned int)q * 0x8B18 + 0x134DF;
            s->lowCount = 0;
        } else if (j3 < s->lo) {
            if (++s->lowCount > 70) {
                s->hi = (q + 1) * 0x8B18 + 0x134DF;
                s->lo = q * 0x8B18 - 0x458C;
                if (s->lo < 0)
                    s->lo = 0;
                s->delay = (unsigned int)q * 0x8B18 + 0x134DF;
                s->lowCount = 0;
            }
        }
        if (s->delay > 0x68520)
            s->delay = 0x68520;
        if (s->count < 16) {
            s->count++;
            s->avg = transit;
            s->base = transit;
        } else {
            s->avg = (transit + s->avg * 31) / 32;
        }
        s->drift = s->base - s->avg;
        if (s->drift > 0x8701)
            flag = 1;
        if (s->drift < -0x8701) {
            s->driftEvents++;
            flag = -1;
        }
        if (flag != 0) {
            s->count = 0;
            s->ts0 = 0;
        }
    }
    s->hold--;
    return 1;
}






Node *func_021B1F2C(unsigned int i)
{
    if (d_021B60D8.state == 0 || d_021B60D8.state == 2)
        return 0;
    return func_021B24FC(i);
}






int func_021B1F54(Node *p)
{
    Node *prev = 0;
    Node *cur = d_021B4BE0.activeHead;

    if (p == 0)
        return 0;
    if (d_021B60D8.state == 2) {
        if (p == &d_021B4BE0.active)
            d_021B4BE0.active.f0 = 0;
        return 1;
    }
    for (; cur; prev = cur, cur = cur->next) {
        if (cur == p) {
            p->f0 = 0;
            if (prev)
                prev->next = p->next;
            else if (cur->next)
                d_021B4BE0.activeHead = cur->next;
            else
                d_021B4BE0.activeHead = 0;
            p->next = d_021B4BE0.nodes;
            d_021B4BE0.nodes = p;
            return 1;
        }
    }
    return 0;
}






int func_021B2010(void *a, unsigned int b, unsigned char *buf, unsigned int c)
{
    int r = 0xff;

    if (a == 0)
        return -1;
    if (c < 0x10)
        return -1;
    if (d_021B60D8.fC == 1)
        return -3;
    if (b >= 5)
        return -3;
    buf[4] = r;
    func_021B2848(a, buf, b & 0xff);
    if (func_021B29A4(a, buf) == 0)
        return 0xfc - r;
    if (d_021B60D8.state == 1 && b == 0) {
        if (func_021B2958(a) == 0)
            return 0xfc - r;
    }
    return 0;
}





int func_021B20B0(int a, int b)
{
    if (d_021B60D8.state == 2)
        return -3;
    return func_021B2564(a,b);
}






int func_021B20D4(Node *a, unsigned int b, unsigned char *buf, unsigned int c)
{
    int z = 0;

    if (a == 0)
        return -1;
    if (c < 0x10)
        return -1;
    if (b >= 6)
        return -3;
    buf[4] = z;
    func_021B2848((u8 *)a, (struct Msg *)buf, b & 0xff);
    if (b == 0) {
        if (d_021B60D8.state == 1 && a->fC == 4) {
            if (func_021B2958((struct N *)a) == 0)
                return z - 3;
        }
        a->f8 = a->f4 ? 1 << a->f4 : 1;
    }
    if (func_021B29A4((int *)a, buf) == 0)
        return -3;
    return 0;
}




int func_021B2180(int a, int b)
{
    if (d_021B60D8.state == 2)
        return -3;
    return func_021B25B0(a,b);
}



int func_021B21A4(unsigned char id)
{
    Node *c;

    if (d_021B60D8.state != 3)
        return -2;
    if (d_021B4BD0.f0 == 3)
        return -6;
    if (id == d_021B60D8.id)
        return -1;
    if (func_021B2A20(id))
        return 0;
    c = func_021B1F2C(id);
    if (c == 0)
        return -1;
    c->f4 = id;
    c->f5 = id;
    c->fC = 2;
    c->f8 = 1 << id;
    d_021B60D8.cb(id, 7, c, d_021B60D8.arg);
    d_021B4BD0.f0++;
    return 0;
}



int func_021B2254(int a)
{
    struct N *r;

    if (d_021B60D8.state != 3)
        return -2;
    r = func_021B2A20(a);
    if (r == 0)
        return -1;
    d_021B60D8.cb(a, 9, r, d_021B60D8.arg);
    d_021B4BD0.f0--;
    return 0;
}



int func_021B22B4(struct Config *cfg)
{
    unsigned int i;

    if (cfg->nodes == 0 || cfg->count == 0 || cfg->count > 8)
        return 0;
    d_021B4BE0.nodes = cfg->nodes;
    func_02082BCC(cfg->nodes, 0, cfg->count * sizeof(Node));
    func_02082BCC(&d_021B4BE0.active, 0, sizeof(Node));
    func_02082BCC(&d_021B4BE0.freeList, 0, sizeof(Node));
    for (i = 0; i < cfg->count - 1; i++)
        d_021B4BE0.nodes[i].next = &d_021B4BE0.nodes[i + 1];
    (d_021B4BE0.nodes + cfg->count - 1)->next = 0;
    d_021B4BE0.activeHead = 0;
    d_021B4BD0.mask = 0;
    d_021B4BD0.f0 = 0;
    d_021B60D8.f14 = 0;
    d_021B4BE0.tick = (void *)func_020870D0;
    d_021B4BE0.mul = 0x5D588B65;
    d_021B4BE0.add = 0x269EC3;
    return 1;
}
