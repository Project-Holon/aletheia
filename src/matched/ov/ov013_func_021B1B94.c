/*
 * function: func_021B1B94
 * address:  0x021B1B94
 * packet:   pkt_ov013_021B1B94
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * RTP receive bookkeeping: sequence check (func_021B1AC0), interarrival
 * jitter (J += (|D| - J) / 16), playout-time and drift tracking. The
 * constants are OS ticks (OS_MilliSecondsToTicks folded): 0x8B18 = 68 ms,
 * 0x7FD88 ~ 1 s, 0x134DF = 151 ms, 0x68520 = 816 ms, 0x8701 = 66 ms.
 * The `(unsigned int)q` in the delay store is what keeps the original's
 * second `q * 0x8B18` (fresh pool load, fresh mul) from being CSE'd with
 * the one in `s->lo`.
 *
 * symbols:
 *   func_021B1AA0  0x021B1AA0  arm  ov013
 *   func_021B1AC0  0x021B1AC0  arm  ov013
 *   func_020870D0  0x020870D0  arm
 */

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

extern void func_021B1AA0(char *p, unsigned short v);
extern int func_021B1AC0(char *p, char *pkt, unsigned short seq);
extern unsigned long long func_020870D0(void);

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
