/*
 * file:     unit_021B1498_p04.c
 * unit:     yes
 * function: func_021B1944, func_021B19AC, func_021B19BC, func_021B1A48, func_021B1A74, func_021B1AA0, func_021B1AC0, func_021B1B94, func_021B1F2C
 * address:  0x021B1944
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
 *   func_02087988  0x02087988  arm
 *   func_0208799C  0x0208799C  arm
 *   func_021B2FE4  0x021B2FE4  arm  ov013
 *   d_021B4BAC  0x021B4BAC  data  a4
 *   d_021B4BB8  0x021B4BB8  data  a4
 *   d_021B4BC4  0x021B4BC4  data  a4
 *   func_02082BCC  0x02082BCC  arm
 *   func_020870D0  0x020870D0  arm
 *   d_021B60D8 0x021B60D8 data a4
 *   func_021B24FC 0x021B24FC arm ov013
 */
#include "../../matched/include/Obj00751.h"
#include "../../matched/include/Obj07347.h"
#include "../../matched/include/Obj07348.h"
#include "../../matched/include/Obj01641.h"
#include "../../matched/include/Obj12461.h"
#include "../../matched/include/G_Sess.h"

struct Node;
typedef unsigned int u32;

typedef struct Node { u32 f0; struct Node *prev; struct Node *next; u32 f0c; unsigned char f10; unsigned char type; } Node;

struct Src {
    unsigned int f0;
    unsigned int delay;         /* 0x04 */
    unsigned int f8;
    int drift;                  /* 0x0C */
    unsigned int lastSeq;       /* 0x10 */
    unsigned int dropped;       /* 0x14 */
    int jitterOut;              /* 0x18 */
    unsigned int reordered;     /* 0x1C */
    unsigned char pad20[0x24];
    unsigned long long tick0;   /* 0x44 */
    unsigned int ts0;           /* 0x4C */
    unsigned int f50;
    unsigned int maxSeq;        /* 0x54 */
    unsigned int f58;
    unsigned int probation;     /* 0x5C */
    unsigned int cycles;        /* 0x60 */
    unsigned int badSeq;        /* 0x64 */
    unsigned short baseSeq;     /* 0x68 */
    unsigned short f6a;
    unsigned int count;         /* 0x6C */
    unsigned int driftEvents;   /* 0x70 */
    int avg;                    /* 0x74 */
    int base;                   /* 0x78 */
    int jitter;                 /* 0x7C */
    int transit;                /* 0x80 */
    int hold;                   /* 0x84 */
    int lo;                     /* 0x88 */
    unsigned int hi;            /* 0x8C */
    unsigned int lowCount;      /* 0x90 */
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

extern u32 func_02087988(void);
extern void func_0208799C(u32 h);
extern void func_021B2FE4(Node *n);
extern void func_02082BCC(void *p, int v, int n);
extern unsigned long long func_020870D0(void);
extern struct Node *func_021B24FC(unsigned int);
Node *func_021B1944(u32 t);
int func_021B19AC(unsigned int i);
void func_021B19BC(char *p, int a1, int a2);
void func_021B1A48(char *p);
void func_021B1A74(char *p, int a1);
void func_021B1AA0(char *p, unsigned short v);
/* * RFC 3550 update_seq shape: MAX_DROPOUT 3000, MAX_MISORDER 100. */ int func_021B1AC0(char *p, char *pkt, unsigned short seq);
/* * RTP receive bookkeeping: sequence check (func_021B1AC0), interarrival * jitter (J += (|D| - J) / 16), playout-time and drift tracking. The * constants are OS ticks (OS_MilliSecondsToTicks folded): 0x8B18 = 68 ms, * 0x7FD88 ~ 1 s, 0x134DF = 151 ms, 0x68520 = 816 ms, 0x8701 = 66 ms. * The `(unsigned int)q` in the delay store is what keeps the original's * second `q * 0x8B18` (fresh pool load, fresh mul) from being CSE'd with * the one in `s->lo`. */ int func_021B1B94(struct Src *s, struct Pkt *pkt);
struct Node *func_021B1F2C(unsigned int i);
extern Node *d_021B4BAC[];
extern u32 d_021B4BB8[];
extern Node *d_021B4BC4[];
extern struct Sess d_021B60D8;



Node *func_021B1944(u32 t)
{
    Node *n;
    u32 h = func_02087988();

    n = d_021B4BAC[t];
    if (n) {
        Node *next = n->next;

        d_021B4BAC[t] = next;
        d_021B4BB8[t]--;
        if (next)
            next->prev = 0;
        else
            d_021B4BC4[t] = 0;
    }
    func_0208799C(h);
    return (Node *)d_021B4BB8[t];
}


int func_021B19AC(unsigned int i) { return d_021B4BB8[i]; }



void func_021B19BC(char *p, int a1, int a2)
{
    func_02082BCC(p, 0, 0x28);
    ((struct Obj00751 *)p)->f4 = 0x134DF;
    ((struct Obj00751 *)p)->f28 = 0;
    ((struct Obj00751 *)p)->f2C = 0;
    ((struct Obj00751 *)p)->f34 = a1;
    ((struct Obj00751 *)p)->f38 = a2;
    ((struct Obj00751 *)p)->f7C = 0;
    ((struct Obj00751 *)p)->f80 = 0;
    ((struct Obj00751 *)p)->f84 = 0;
    ((struct Obj00751 *)p)->f88 = 0;
    ((struct Obj00751 *)p)->f8C = 0x134DF;
    ((struct Obj00751 *)p)->f90 = 0;
    ((struct Obj00751 *)p)->f4C = 0;
    ((struct Obj00751 *)p)->f44 = 0;
    ((struct Obj00751 *)p)->f48 = 0;
    ((struct Obj00751 *)p)->f6C = 0;
    ((struct Obj00751 *)p)->f70 = 0;
    ((struct Obj00751 *)p)->f50 = 0;
    ((struct Obj00751 *)p)->f54 = 0;
    ((struct Obj00751 *)p)->f58 = 0;
    ((struct Obj00751 *)p)->f5C = 1;
    ((struct Obj00751 *)p)->f3C = 0;
    ((struct Obj00751 *)p)->f40 = 0;
    ((struct Obj00751 *)p)->f30 = 0;
}



void func_021B1A48(char *p)
{
    if (((struct Obj07347 *)p)->f3C) {
        func_021B2FE4(((struct Obj07347 *)p)->f3C);
        *(int *)&((struct Obj07347 *)p)->f3C = 0;
    }
    ((struct Obj07347 *)p)->f38 = -1;
}



void func_021B1A74(char *p, int a1)
{
    if (((struct Obj07348 *)p)->f3C)
        func_021B2FE4(((struct Obj07348 *)p)->f3C);
    *(int *)&((struct Obj07348 *)p)->f3C = a1;
    func_021B1944((u32)(((struct Obj07348 *)p)->f34));
}



void func_021B1AA0(char *p, unsigned short v)
{
    ((struct Obj01641 *)p)->f68 = v;
    *(int *)&((struct Obj01641 *)p)->f64 = 0x00010001;
    *(int *)&((struct Obj01641 *)p)->f60 = 0;
    ((struct Obj01641 *)p)->f5C = 0;
}



/*
 * RFC 3550 update_seq shape: MAX_DROPOUT 3000, MAX_MISORDER 100.
 */
int func_021B1AC0(char *p, char *pkt, unsigned short seq)
{
    unsigned short last = ((struct Obj01641 *)p)->f68;
    unsigned short delta = seq - last;

    if (delta < 3000) {
        if (seq < last)
            ((struct Obj01641 *)p)->f60 += 0x10000;
        ((struct Obj01641 *)p)->f68 = seq;
    } else if (delta <= 0x10000 - 100) {
        if (seq == ((struct Obj01641 *)p)->f64) {
            func_021B1AA0(p, seq);
            ((struct Obj01641 *)p)->f54 = (unsigned short)(seq - 1);
        } else {
            ((struct Obj01641 *)p)->f64 = (unsigned short)(seq + 1);
            return 0;
        }
    } else if (seq + ((struct Obj01641 *)p)->f60 > ((struct Obj01641 *)p)->f54 + 0x10000 - 100) {
        ((struct Obj12461 *)pkt)->f18 = seq + ((struct Obj01641 *)p)->f60 - 0x10000;
        return 1;
    }
    ((struct Obj12461 *)pkt)->f18 = seq + ((struct Obj01641 *)p)->f60;
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
        func_021B1AA0((char *)s, pkt->seq);
    } else {
        if (!func_021B1AC0((char *)s, (char *)pkt, pkt->seq)) {
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


struct Node *func_021B1F2C(unsigned int i)
{
    if (((unsigned int *)&d_021B60D8)[4] == 0 || ((unsigned int *)&d_021B60D8)[4] == 2) return 0;
    return func_021B24FC(i);
}
