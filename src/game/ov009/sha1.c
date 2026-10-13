/*
 * file:     sha1.c
 * unit:     yes
 * function: func_02163558, func_0216359C, func_021635E0, func_02163628, func_02163C9C, func_02163CF0, func_02163DA8, func_02163E10
 * address:  0x02163558
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   long_from_char   0x021635E0  arm  ov009
 *   R                0x02163558  arm  ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *   CPSi_sha1_block 0x02163628  arm
 *   padding         0x021A1F28  data
 *   func_02163CF0  0x02163CF0  arm  ov009
 *   func_0216359C  0x0216359C  arm  ov009
 *   g_021A1F28  0x021A1F28  data
 */
#define ROL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define F1(b, c, d) (((b) & ((c) ^ (d))) ^ (d))
#define F2(b, c, d) ((b) ^ (c) ^ (d))
#define F3(b, c, d) (((b) & ((c) | (d))) | ((c) & (d)))
#define RND(a, b, c, d, e, f, x, k) \
    e += ROL(a, 5) + f(b, c, d) + (x) + (k); \
    b = ROL(b, 30);
typedef unsigned long u32_0216359C;

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32_021635E0;

typedef unsigned long u32_02163628;

typedef struct {
    u32_02163628 state[5];
} CPSSha1Ctx_02163558;

typedef unsigned long u32;

typedef struct CPSSha1Ctx_02163C9C {
    u32 state[5];
    u32 count[2];
    unsigned char buffer[64];
} CPSSha1Ctx_02163C9C;

extern void long_from_char(u32_02163628 *d, u8 *s, u32_02163628 len);
extern u32_02163628 R(int t, u32_02163628 *w);
extern void MI_CpuFill8(void *dstp, unsigned char val, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void CPSi_sha1_block(CPSSha1Ctx_02163C9C *ctx, unsigned char *m);
extern void func_02163CF0(void *ctx, void *data0, int datalen);
extern void func_0216359C(unsigned char *d, unsigned long *s, unsigned int len);
unsigned long func_02163558(int t, unsigned long *w);
void func_021635E0(u32_021635E0 *dst, const u8 *src, u32_021635E0 count);
void func_02163628(CPSSha1Ctx_02163558 *ctx, u8 *m);
void CPSi_sha1_init(CPSSha1Ctx_02163C9C *ctx);
void CPSi_sha1_calc(CPSSha1Ctx_02163C9C *ctx, void *data0, int datalen);
void CPSi_sha1_result(CPSSha1Ctx_02163C9C *ctx, unsigned char *digest);
void func_02163E10(void *ctx, unsigned char *digest);
extern unsigned char padding[64];
extern unsigned char g_021A1F28[64];


/*
 * sdk:      R (libssl.TWL.HYB.a(sha1.o))
 */
unsigned long func_02163558(int t, unsigned long *w)
{
	unsigned long temp;

	temp = w[(t + 13) & 15] ^ w[t ^ 8] ^ w[(t + 2) & 15] ^ w[t];
	temp = (temp << 1) | (temp >> 31);
	w[t] = temp;
	return temp;
}



static void char_from_long(unsigned char *d, unsigned long *s, unsigned int len)
{
    unsigned int i;

    len >>= 2;
    for (i = 0; i < len; i++) {
        u32_0216359C v = *s++;
        d[0] = v >> 24;
        d[1] = v >> 16;
        d[2] = v >> 8;
        d[3] = v;
        d += 4;
    }
}



void func_021635E0(u32_021635E0 *dst, const u8 *src, u32_021635E0 count)
{
    u32_021635E0 i = 0;
    while (i < count) {
        u32_021635E0 b0 = src[i];
        u32_021635E0 b1 = src[i + 1];
        u32_021635E0 b2 = src[i + 2];
        u32_021635E0 b3 = src[i + 3];
        *dst++ = (b0 << 24) | (b1 << 16) | (b2 << 8) | b3;
        i += 4;
    }
}



/*
 * sdk:      CPSi_sha1_block (libssl.TWL.HYB.a(sha1.o))
 *
 * closed (2026-10-01, wave 3): two source-shape errors, not an allocator wall.
 * ROL had a no-op `(u32)(x)` cast on the right shift; the cast node alone
 * rotated the {c, d, w, temp} colouring (142 -> 18 B). F3 is the majority
 * function spelled (b & (c | d)) | (c & d), as the image evaluates it (18 -> 0).
 */
void func_02163628(CPSSha1Ctx_02163558 *ctx, u8 *m)
{
    u32_02163628 w[16];
    u32_02163628 a, b, c, d, e;
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



void CPSi_sha1_init(CPSSha1Ctx_02163C9C *ctx)
{
    MI_CpuFill8(ctx, 0, 0x5c);
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;
    ctx->state[4] = 0xc3d2e1f0;
}



void CPSi_sha1_calc(CPSSha1Ctx_02163C9C *ctx, void *data0, int datalen)
{
    unsigned char *data = data0;
    unsigned int index, room, i;

    index = (ctx->count[1] >> 3) & 0x3f;
    if ((ctx->count[1] += datalen << 3) < (unsigned int)(datalen << 3))
        ctx->count[0]++;
    ctx->count[0] += (unsigned int)datalen >> 29;
    room = 64 - index;

    if ((unsigned int)datalen >= room) {
        MI_CpuCopy8(data, ctx->buffer + index, room);
        index = 0;
        CPSi_sha1_block(ctx, ctx->buffer);
        for (i = room; i + 63 < (unsigned int)datalen; i += 64)
            CPSi_sha1_block(ctx, data + i);
    } else {
        i = 0;
    }
    MI_CpuCopy8(data + i, ctx->buffer + index, datalen - i);
}



void CPSi_sha1_result(CPSSha1Ctx_02163C9C *ctx, unsigned char *digest)
{
    int index;

    char_from_long(digest, (unsigned long *)((char *)ctx + 0x14), 8);
    index = (ctx->count[1] >> 3) & 0x3f;
    CPSi_sha1_calc(ctx, padding, index < 0x38 ? 0x38 - index : 0x78 - index);
    CPSi_sha1_calc(ctx, digest, 8);
    char_from_long(digest, (unsigned long *)ctx, 0x14);
}



/*
 * sdk:      CPSi_sha1_result_prng (libssl.TWL.HYB.a(sha1.o))
 *
 * note: the pool word is padding+1 (0x021A1F29); the extern is the padding
 *   array itself and the call passes its second byte.
 */
void func_02163E10(void *ctx, unsigned char *digest)
{
	func_02163CF0(ctx, g_021A1F28 + 1, 44);
	func_0216359C(digest, ctx, 20);
}
