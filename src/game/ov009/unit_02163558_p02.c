/*
 * file:     unit_02163558_p02.c
 * unit:     yes
 * function: func_02163C9C, func_02163CF0, func_02163DA8, func_02163E10
 * address:  0x02163C9C
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
 *   MI_CpuFill8  0x02082BCC  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *   CPSi_sha1_block 0x02163628  arm
 *   char_from_long  0x0216359C  arm
 *   padding         0x021A1F28  data
 *   func_02163CF0  0x02163CF0  arm  ov009
 *   func_0216359C  0x0216359C  arm  ov009
 *   g_021A1F28  0x021A1F28  data
 */
typedef unsigned long u32;

typedef struct CPSSha1Ctx {
    u32 state[5];
    u32 count[2];
    unsigned char buffer[64];
} CPSSha1Ctx;

extern void MI_CpuFill8(void *dstp, unsigned char val, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void CPSi_sha1_block(CPSSha1Ctx *ctx, unsigned char *m);
extern void char_from_long(unsigned char *d, unsigned long *s, unsigned int len);
extern void func_02163CF0(void *ctx, void *data0, int datalen);
extern void func_0216359C(unsigned char *d, unsigned long *s, unsigned int len);
void CPSi_sha1_init(CPSSha1Ctx *ctx);
void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen);
void CPSi_sha1_result(CPSSha1Ctx *ctx, unsigned char *digest);
void func_02163E10(void *ctx, unsigned char *digest);
extern unsigned char padding[64];
extern unsigned char g_021A1F28[64];


void CPSi_sha1_init(CPSSha1Ctx *ctx)
{
    MI_CpuFill8(ctx, 0, 0x5c);
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;
    ctx->state[4] = 0xc3d2e1f0;
}


void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen)
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


void CPSi_sha1_result(CPSSha1Ctx *ctx, unsigned char *digest)
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
