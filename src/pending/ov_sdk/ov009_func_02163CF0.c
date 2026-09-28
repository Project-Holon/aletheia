/*
 * function: CPSi_sha1_calc
 * address:  0x02163CF0
 * packet:   pkt_ov009_02163CF0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      CPSi_sha1_calc (sha1.o)
 *
 * blocker:  same register-allocation shift as CPSi_md5_calc: the image keeps
 *           ctx/data0/datalen/index/room in r8/r7/r6/r4/r5, the compiler form
 *           uses r7/r6/r5/r3/r4.  All differing bytes are register numbers.
 *
 * symbols:
 *   MI_CpuCopy8     0x02082D44  arm
 *   CPSi_sha1_block 0x02163628  arm
*/

typedef unsigned long u32;

typedef struct CPSSha1Ctx {
    u32 state[5];
    u32 count[2];
    unsigned char buffer[64];
} CPSSha1Ctx;

extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void CPSi_sha1_block(CPSSha1Ctx *ctx, unsigned char *m);

void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen)
{
    unsigned char *data = data0;
    unsigned int saved;
    unsigned int room, index;
    unsigned int i;

    saved = ctx->count[1];
    ctx->count[1] += datalen << 3;
    if (ctx->count[1] < (unsigned int)(datalen << 3))
        ctx->count[0]++;
    ctx->count[0] += (unsigned int)datalen >> 29;
    index = (saved >> 3) & 0x3f;
    room = 64 - index;

    if ((unsigned int)datalen >= room) {
        MI_CpuCopy8(data, ctx->buffer + index, room);
        CPSi_sha1_block(ctx, ctx->buffer);
        for (i = room; i + 63 < (unsigned int)datalen; i += 64)
            CPSi_sha1_block(ctx, data + i);
        index = 0;
    } else {
        i = 0;
    }
    MI_CpuCopy8(data + i, ctx->buffer + index, datalen - i);
}
