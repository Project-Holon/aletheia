/*
 * function: func_02163628
 * address:  0x02163628
 * packet:   pkt_ov009_02163628
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      CPSi_sha1_block (libssl.TWL.HYB.a(sha1.o))
 *
 * blocker:  register assignment only.  The body is size-exact (1652 bytes) and every
 *           instruction sequence has the image's shape; about 140 concrete bytes differ
 *           because the allocator gives the w base, c and d different registers (image:
 *           w=r7 a=r5 b=r6 d=r8 e=r9 c=r10 with r4 and fp as temporaries; here c=r7,
 *           d=r4, w=r8).  Structure recovered from the image and the vendor's two
 *           locals (i, j): stage 1 is 3 x 5 unrolled rounds with w[i+k], then w[15] and
 *           R(0..3); stages 2-4 are 4 x 5 rounds calling R(i + k) with the round index i
 *           masked with & 0xf after 2, 3 and 4 rounds respectively; each stage's j
 *           counter is its own spilled live range.  Tried without effect: all
 *           declaration orders of the eight locals (sampled), the order of the five
 *           state loads (all 120), the operand order of the rotate, unsigned long
 *           typedefs, and 4000 permuter compiles (best 116 bytes, by adding temporaries
 *           the vendor does not have).
 *
 * U63 (measured): 142/1592 concrete bytes with the size exact at 1652; every
 * differing slot is the same instruction carrying a different register.  The
 * image is a=r5 b=r6 c=r10 d=r8 e=r9 w=r7 with r4 and fp as its two fresh
 * temporaries; this build is c=r7, d=r4, w=r8 with sl and fp as its two -- so
 * {c, d, w, temp} is a 4-way permutation of {r7, r4, r8, sl} and the two
 * forms of the same instruction sequence are otherwise identical, including
 * the 4 x 5 stage structure and the fed-in w[15]/R(0..3) tail.  U63 tried 30
 * orderings of the six setup statements (the five state loads and
 * long_from_char): every one of them changes the emitted size to 1656 or
 * 1660, so the parked order is the only size-exact one and the residue is
 * allocation, not statement order or declaration order.
 *
 * symbols:
 *   long_from_char   0x021635E0  arm  ov009
 *   R                0x02163558  arm  ov009
 */

typedef unsigned char u8;
typedef unsigned long u32;

typedef struct {
    u32 state[5];
} CPSSha1Ctx;

extern void long_from_char(u32 *d, u8 *s, u32 len);
extern u32 R(int t, u32 *w);

#define ROL(x, n) (((x) << (n)) | ((u32)(x) >> (32 - (n))))
#define F1(b, c, d) (((b) & ((c) ^ (d))) ^ (d))
#define F2(b, c, d) ((b) ^ (c) ^ (d))
#define F3(b, c, d) (((b) & (c)) | ((b) & (d)) | ((c) & (d)))

#define RND(a, b, c, d, e, f, x, k) \
    e += ROL(a, 5) + f(b, c, d) + (x) + (k); \
    b = ROL(b, 30);

void func_02163628(CPSSha1Ctx *ctx, u8 *m)
{
    u32 w[16];
    u32 a, b, c, d, e;
    int i;
    int j;

    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    e = ctx->state[4];
    long_from_char(w, m, 64);

    i = 0;
    for (j = 0; j < 3; j++) {
        RND(a, b, c, d, e, F1, w[i + 0], 0x5a827999)
        RND(e, a, b, c, d, F1, w[i + 1], 0x5a827999)
        RND(d, e, a, b, c, F1, w[i + 2], 0x5a827999)
        RND(c, d, e, a, b, F1, w[i + 3], 0x5a827999)
        RND(b, c, d, e, a, F1, w[i + 4], 0x5a827999)
        i += 5;
    }
    RND(a, b, c, d, e, F1, w[15], 0x5a827999)
    RND(e, a, b, c, d, F1, R(0, w), 0x5a827999)
    RND(d, e, a, b, c, F1, R(1, w), 0x5a827999)
    RND(c, d, e, a, b, F1, R(2, w), 0x5a827999)
    RND(b, c, d, e, a, F1, R(3, w), 0x5a827999)

    i = 4;
    for (j = 0; j < 4; j++) {
        RND(a, b, c, d, e, F2, R(i, w), 0x6ed9eba1)
        RND(e, a, b, c, d, F2, R(i + 1, w), 0x6ed9eba1)
        i = (i + 2) & 0xf;
        RND(d, e, a, b, c, F2, R(i, w), 0x6ed9eba1)
        RND(c, d, e, a, b, F2, R(i + 1, w), 0x6ed9eba1)
        RND(b, c, d, e, a, F2, R(i + 2, w), 0x6ed9eba1)
        i += 3;
    }
    for (j = 0; j < 4; j++) {
        RND(a, b, c, d, e, F3, R(i, w), 0x8f1bbcdc)
        RND(e, a, b, c, d, F3, R(i + 1, w), 0x8f1bbcdc)
        RND(d, e, a, b, c, F3, R(i + 2, w), 0x8f1bbcdc)
        i = (i + 3) & 0xf;
        RND(c, d, e, a, b, F3, R(i, w), 0x8f1bbcdc)
        RND(b, c, d, e, a, F3, R(i + 1, w), 0x8f1bbcdc)
        i += 2;
    }
    for (j = 0; j < 4; j++) {
        RND(a, b, c, d, e, F2, R(i, w), 0xca62c1d6)
        RND(e, a, b, c, d, F2, R(i + 1, w), 0xca62c1d6)
        RND(d, e, a, b, c, F2, R(i + 2, w), 0xca62c1d6)
        RND(c, d, e, a, b, F2, R(i + 3, w), 0xca62c1d6)
        i = (i + 4) & 0xf;
        RND(b, c, d, e, a, F2, R(i, w), 0xca62c1d6)
        i += 1;
    }

    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
    ctx->state[4] += e;
}
