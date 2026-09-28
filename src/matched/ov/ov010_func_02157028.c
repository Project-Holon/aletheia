/*
 * function: func_02157028
 * address:  0x02157028
 * packet:   pkt_ov010_02157028
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Deals four stat bonuses and picks three of six entries at random. The
 * candidate buffer is `u8 buf[6] = {0, ...}` in a nested block (see
 * docs/idioms/an-initialised-local-array-takes-its-address-before-the-stores.md):
 * six explicit zero stores rematerialise sp+8 for the fill loop, and a plain
 * block-scope array hoists d->f0C out of it. RandN is the inline
 * `(u64)rand * n >> 32` helper; its n != 0 test folds away for constant n.
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   func_0203F0A8  0x0203F0A8  arm
 *   _ull_mul  0x0209C054  arm
 *   d_02172768  0x02172768  data
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef struct Ent {
    u8 f00;             /* 0x00 */
    u8 f01[4];          /* 0x01 */
    u8 f05;             /* 0x05 */
    u8 pad06[0x14 - 0x06];
    u16 f14;            /* 0x14 */
    u8 pad16[0x2C - 0x16];
} Ent;

typedef struct Src {
    u32 f00;
    Ent *f04;           /* 0x04 */
} Src;

typedef struct Deal {
    u8 f00[4];          /* 0x00 */
    u8 f04[4];          /* 0x04 */
    u8 f08[4];          /* 0x08 */
    Ent *f0C;           /* 0x0C */
} Deal;

extern void *func_02030734(u32 heap, u32 size, int clear, const char *site, u16 tag);
extern u32 func_0203F0A8(void);
extern const char d_02172768[];

static inline u32 RandN(u32 n)
{
    u32 r = func_0203F0A8();

    if (n != 0)
        r = ((u64)r * n) >> 32;
    return r;
}

Deal *func_02157028(u32 heap, Src *src, u16 lim)
{
    Deal *d;
    u8 i;
    u8 n;
    u8 k;
    u8 cnt;
    u8 a;
    u8 b;
    u8 t;

    d = func_02030734(heap, 0x10, 0, d_02172768, 100);
    d->f0C = src->f04;
    for (i = 0; i < 4; i++) {
        d->f00[i] = 0;
        d->f04[i] = 0;
    }
    for (i = 0; i < 4; i++)
        d->f00[i] = d->f0C->f01[i];
    n = d->f0C->f05 / 5;
    while (n != 0) {
        k = RandN(3) + 1;
        if (k > n)
            k = n;
        d->f00[RandN(4)] += (u8)(k * 5);
        n -= k;
    }
    {
        u8 buf[6] = {0, 0, 0, 0, 0, 0};

        cnt = 0;
        for (i = 0; i < 6; i++) {
            if (d->f0C[i].f14 <= lim) {
                buf[cnt] = i;
                cnt++;
            }
        }
        if (cnt < 3) {
            buf[0] = 0;
            buf[1] = 1;
            buf[2] = 2;
            cnt = 3;
        }
        for (t = 0; t < 30; t++) {
            a = RandN(cnt);
            b = RandN(cnt);
            k = buf[a];
            buf[a] = buf[b];
            buf[b] = k;
        }
        for (i = 0; i < 3; i++)
            d->f08[i] = buf[i];
    }
    return d;
}
