/*
 * file:     md5.c
 * unit:     yes
 * function: func_02162FC0, func_02162FD8, func_02162FF0, func_021633F0, func_02163438, func_021634F0
 * address:  0x02162FC0
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
 *   g_021A1E28     0x021A1E28  data ov009
 *   g_021A1DA8     0x021A1DA8  data ov009
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   CPSi_md5_block 0x02162FF0  arm
 *   char_from_long  0x02162FC0  arm
 *   padding         0x021A1DE8  data
 */
#define ROTL(v, s)  (((v) << (s)) | ((v) >> (32 - (s))))
#define F(x, y, z)  ((z) ^ ((x) & ((y) ^ (z))))
#define G(x, y, z)  ((y) ^ ((z) & ((x) ^ (y))))
#define H(x, y, z)  ((x) ^ (y) ^ (z))
#define I(x, y, z)  ((y) ^ ((x) | ~(z)))
#define STEP(f, a, b, c, d, k, s) \
    a += f(b, c, d) + x[g_021A1DA8[k]] + g_021A1E28[k]; \
    a = ROTL(a, s) + b
typedef struct CPSMd5Ctx_02162FC0 {
    unsigned long state[4];
    unsigned long count[2];
    unsigned char buffer[64];
} CPSMd5Ctx_02162FC0;

typedef unsigned long u32;

typedef struct CPSMd5Ctx_021633F0 {
    u32 state[4];
    u32 count[2];
    unsigned char buffer[64];
} CPSMd5Ctx_021633F0;

extern void MI_CpuCopy8(void *a, void *b, int n);
extern void MI_CpuFill8(void *dstp, unsigned char val, unsigned long size);
extern void CPSi_md5_block(CPSMd5Ctx_021633F0 *ctx, unsigned char *m);
extern void char_from_long(unsigned char *d, unsigned long *s, unsigned int len);
void func_02162FC0(void *a, void *b, int n);
void func_02162FD8(void *a, void *b, int n);
void func_02162FF0(CPSMd5Ctx_02162FC0 *ctx, unsigned char *m);
void CPSi_md5_init(CPSMd5Ctx_021633F0 *ctx);
void CPSi_md5_calc(CPSMd5Ctx_021633F0 *ctx, void *data0, int datalen);
void CPSi_md5_result(CPSMd5Ctx_021633F0 *ctx, unsigned char *digest);
extern unsigned long g_021A1E28[64];
extern unsigned char g_021A1DA8[64];
extern unsigned char padding[64];



/*
 * Tail call to MI_CpuCopy8 with its first two arguments swapped.
 */
void func_02162FC0(void *a, void *b, int n)
{
    MI_CpuCopy8(b, a, n);
}



void func_02162FD8(void *a, void *b, int n)
{
    MI_CpuCopy8(b, a, n);
}



/*
 * sdk:      CPSi_md5_block (libssl.TWL.HYB.a md5.o)
 *
 * Table-driven MD5 block: four rounds of four iterations, each iteration
 * doing four steps indexed through itab (message word) and ktab (constant).
 */
void func_02162FF0(CPSMd5Ctx_02162FC0 *ctx, unsigned char *m)
{
    unsigned long x[16];
    unsigned long a, b, c, d;
    int i, j;

    a = ctx->state[0];
    b = ctx->state[1];
    c = ctx->state[2];
    d = ctx->state[3];
    func_02162FD8(x, m, 64);

    i = 0;
    for (j = 0; j < 4; j++) {
        STEP(F, a, b, c, d, i,     7);
        STEP(F, d, a, b, c, i + 1, 12);
        STEP(F, c, d, a, b, i + 2, 17);
        STEP(F, b, c, d, a, i + 3, 22);
        i += 4;
    }
    for (j = 0; j < 4; j++) {
        STEP(G, a, b, c, d, i,     5);
        STEP(G, d, a, b, c, i + 1, 9);
        STEP(G, c, d, a, b, i + 2, 14);
        STEP(G, b, c, d, a, i + 3, 20);
        i += 4;
    }
    for (j = 0; j < 4; j++) {
        STEP(H, a, b, c, d, i,     4);
        STEP(H, d, a, b, c, i + 1, 11);
        STEP(H, c, d, a, b, i + 2, 16);
        STEP(H, b, c, d, a, i + 3, 23);
        i += 4;
    }
    for (j = 0; j < 4; j++) {
        STEP(I, a, b, c, d, i,     6);
        STEP(I, d, a, b, c, i + 1, 10);
        STEP(I, c, d, a, b, i + 2, 15);
        STEP(I, b, c, d, a, i + 3, 21);
        i += 4;
    }

    ctx->state[0] += a;
    ctx->state[1] += b;
    ctx->state[2] += c;
    ctx->state[3] += d;
}



void CPSi_md5_init(CPSMd5Ctx_021633F0 *ctx)
{
    MI_CpuFill8(ctx, 0, 0x58);
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;
}



void CPSi_md5_calc(CPSMd5Ctx_021633F0 *ctx, void *data0, int datalen)
{
    unsigned char *data = data0;
    unsigned int i, index, room;

    index = (ctx->count[0] >> 3) & 0x3f;
    if ((ctx->count[0] += (unsigned int)datalen << 3) < ((unsigned int)datalen << 3))
        ctx->count[1]++;
    ctx->count[1] += (unsigned int)datalen >> 29;
    room = 64 - index;
    if ((unsigned int)datalen >= room) {
        MI_CpuCopy8(data, ctx->buffer + index, room);
        index = 0;
        CPSi_md5_block(ctx, ctx->buffer);
        for (i = room; i + 63 < (unsigned int)datalen; i += 64)
            CPSi_md5_block(ctx, data + i);
    } else {
        i = 0;
    }
    MI_CpuCopy8(data + i, ctx->buffer + index, datalen - i);
}



void CPSi_md5_result(CPSMd5Ctx_021633F0 *ctx, unsigned char *digest)
{
    int index;

    char_from_long(digest, (unsigned long *)((char *)ctx + 0x10), 8);
    index = (ctx->count[0] >> 3) & 0x3f;
    CPSi_md5_calc(ctx, padding, index < 0x38 ? 0x38 - index : 0x78 - index);
    CPSi_md5_calc(ctx, digest, 8);
    char_from_long(digest, (unsigned long *)ctx, 0x10);
}
