/*
 * file:     unit_02162FC0_p02.c
 * unit:     yes
 * function: func_021633F0, func_02163438, func_021634F0
 * address:  0x021633F0
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
 *   MI_CpuCopy8    0x02082D44  arm
 *   CPSi_md5_block 0x02162FF0  arm
 *   char_from_long  0x02162FC0  arm
 *   padding         0x021A1DE8  data
 */
typedef unsigned long u32;

typedef struct CPSMd5Ctx {
    u32 state[4];
    u32 count[2];
    unsigned char buffer[64];
} CPSMd5Ctx;

extern void MI_CpuFill8(void *dstp, unsigned char val, unsigned long size);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void CPSi_md5_block(CPSMd5Ctx *ctx, unsigned char *m);
extern void char_from_long(unsigned char *d, unsigned long *s, unsigned int len);
void CPSi_md5_init(CPSMd5Ctx *ctx);
void CPSi_md5_calc(CPSMd5Ctx *ctx, void *data0, int datalen);
void CPSi_md5_result(CPSMd5Ctx *ctx, unsigned char *digest);
extern unsigned char padding[64];


void CPSi_md5_init(CPSMd5Ctx *ctx)
{
    MI_CpuFill8(ctx, 0, 0x58);
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;
}


void CPSi_md5_calc(CPSMd5Ctx *ctx, void *data0, int datalen)
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


void CPSi_md5_result(CPSMd5Ctx *ctx, unsigned char *digest)
{
    int index;

    char_from_long(digest, (unsigned long *)((char *)ctx + 0x10), 8);
    index = (ctx->count[0] >> 3) & 0x3f;
    CPSi_md5_calc(ctx, padding, index < 0x38 ? 0x38 - index : 0x78 - index);
    CPSi_md5_calc(ctx, digest, 8);
    char_from_long(digest, (unsigned long *)ctx, 0x10);
}
