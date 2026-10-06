/*
 * function: func_021B6240
 * address:  0x021B6240
 * packet:   pkt_ov091_021B6240
 * region:   ov091
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Byte-correct; the one wildcard is the arm9 call to 0x0201A354 (+0x10E).
 * blocker: func_0201A354 (arm9, unlabelled Thumb thunk inside the listing's
 *   data run, Ilias's) has no witness outside this range. Verified C for it
 *   (from src/pending/ov/ov021_func_021B57CC.c, match.py one --thumb, EXACT,
 *   16 bytes):
 *     extern int func_02048F60();  (symbols: func_02048F60 0x02048F60 arm)
 *     int func_0201A354(int a, int b) { return func_02048F60(0x69, a, b); }
 *   Levers: the four 10-byte stack copies declared b, d, c, a (reverse of
 *   their frame order); t[4] spelled `k + 0xff11` (pool word, then +0xee
 *   for t[5]); `k = 0` before the b49 clear loop, which stores k.
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02030734  0x02030734  arm
 *   func_0201A920  0x0201A920  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_020173F0  0x020173F0  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_0203630C  0x0203630C  arm
 *   func_0201A354  0x0201A354  thumb
 *   func_02005728  0x02005728  thumb
 *   func_0201A59C  0x0201A59C  thumb
 *   func_020355D8  0x020355D8  arm
 *   func_021B660C  0x021B660C  thumb  ov091
 *   d_021BED0C     0x021BED0C  data  a1
 *   d_021BEA78     0x021BEA78  data  a2
 *   d_021BEA84     0x021BEA84  data  a2
 *   d_021BEA90     0x021BEA90  data  a2
 *   d_021BEA9C     0x021BEA9C  data  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct {
    u16 v[5];
} Ten;

typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
    u8 b4;
    u8 b5;
    u16 h6;
    u8 pad8[0xa8 - 8];
    u16 ha8;
} S;

typedef struct {
    void *list;
    u16 *t;
    u8 b;
} E;

typedef struct {
    void *party;
    u8 pad04[0x14 - 4];
    S *s;
    u8 pad18[0x34 - 0x18];
    int v34;
    u8 pad38[0x3c - 0x38];
    int v3c;
    u8 pad40[0x44 - 0x40];
    u16 h44;
    u8 pad46[0x49 - 0x46];
    u8 b49[6];
    u8 pad4f[0x60 - 0x4f];
    u16 h60;
    u8 pad62[0x64 - 0x62];
    int v64;
    E e[3];
    int v8c;
    int v90;
    u8 b94;
} Q;

typedef struct {
    u16 heap;
    u8 pad[0x280 - 2];
    Q *q;
} P;

typedef signed int     s32;
struct Party;
struct PartyMon;
extern void func_0203064C(u32 a, u32 b, u32 c);
extern P *func_0203159C(int, int, int);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern struct Party *func_0201A920(u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern void *func_020173F0(u16 species, u16 level, u64 id, u16 heap);
extern void func_02017E40(void *p, u32 id, u32 v);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern void func_020307B0(void *p);
extern u32 func_0203630C(void);
extern void *func_0201A354(int a, int b);
extern u32 func_02005728(u32 range);
extern int func_0201A59C(void *a0, void *a1, void *a2);
extern void func_020355D8(u8 v);
extern int func_021B660C(u8 *p);

extern const char d_021BED0C[];
extern const Ten d_021BEA78;
extern const Ten d_021BEA84;
extern const u16 d_021BEA90[];
extern const u16 d_021BEA9C[];

int func_021B6240(int a0, int *seq, Q *q, P *p)
{
    Ten b;
    Ten d;
    Ten c;
    Ten a;
    u8 i;
    u8 k;
    void *mon;
    S *s;
    u16 *t;

    switch (*seq) {
    case 0:
        func_0203064C(1, 0x17, 0x30000);
        p = func_0203159C(a0, 0x284, 0x17);
        p->heap = 0x17;
        if (q == 0) {
            q = func_02030734(0x17, 0x98, 1, d_021BED0C, 0x52);
            q->party = func_0201A920(0x17);
            q->v3c = 0;
            func_0201A954(q->party, 6);
            a = d_021BEA78;
            for (i = 0; i < 6; i++) {
                mon = func_020173F0(d_021BEA90[i], d_021BEA9C[i], 0xffffffff, 0x17);
                b = a;
                func_02017E40(mon, 0x8e, (u32)&b);
                func_02017E40(mon, 0x9a, 0);
                func_0201A98C(q->party, mon);
                func_020307B0(mon);
            }
            q->v34 = 0;
            if (func_0203630C() & 0x100) {
                s = func_0201A354(0xf, 0x17);
                q->s = s;
                s->b2 = 1;
                s->b3 = 6;
                s->b4 = 1;
                s->b5 = 0;
                s->ha8 = 0;
                s->h6 = 0xc8;
                k = 0;
                for (i = 0; i < 6; i++)
                    q->b49[i] = 0;
                q->v34 = 0x16;
                for (k = 0; k < 3; k++) {
                    c = d_021BEA84;
                    q->e[k].list = func_0201A920(0x17);
                    for (i = 0; i < 6; i++) {
                        mon = func_020173F0(func_02005728(0xfa), 0x64, 0xffffffff, 0x17);
                        d = c;
                        func_02017E40(mon, 0x8e, (u32)&d);
                        func_02017E40(mon, 0x9a, 0);
                        func_02017E40(mon, 6, func_02005728(2));
                        func_0201A98C(q->e[k].list, mon);
                        func_020307B0(mon);
                    }
                    t = func_02030734(0x17, 0xc, 0, d_021BED0C, 0xae);
                    t[0] = 0x3077;
                    t[1] = 0x308c;
                    t[2] = 0x3044;
                    t[3] = 0x3084;
                    t[4] = k + 0xff11;
                    t[5] = 0xffff;
                    q->e[k].t = t;
                    q->e[k].b = func_02005728(2);
                }
                q->v64 = 2;
                q->v8c = 1;
                q->v90 = 1;
                q->h60 = 0xff;
                q->b94 = 0;
                func_0201A59C(s, q->party, 0);
            } else if (func_0203630C() & 0x400) {
                q->v34 = 5;
                q->h44 = 0x2c;
            } else if (func_0203630C() & 0x800) {
                q->v34 = 0x19;
            }
            func_020355D8(1);
        }
        p->q = q;
        *seq = 1;
    case 1:
        if (func_021B660C((u8 *)p) == 1)
            return 1;
        break;
    }
    return 0;
}
