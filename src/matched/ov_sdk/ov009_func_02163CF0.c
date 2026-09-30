/*
 * function: CPSi_sha1_calc
 * address:  0x02163CF0
 * packet:   pkt_ov009_02163CF0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_sha1_calc (sha1.o)
 *
 * symbols:
 *   MI_CpuCopy8     0x02082D44  arm
 *   CPSi_sha1_block 0x02163628  arm
 *
 * The SHA-1 twin of CPSi_md5_calc (0x02163438) in the same library, and the
 * same two levers close it.  `index` is taken from count[1] *before* the count
 * pair is updated, in the md5 shape (`index = (ctx->count[1] >> 3) & 0x3f;`
 * first, then the guarded compound add, then count[0] += datalen >> 29, then
 * `room = 64 - index`), which is what schedules `lsr r2, r3, #3` above the
 * predicated count[0]++ the image has; and `index = 0;` goes *before* the
 * `CPSi_sha1_block(ctx, ctx->buffer)` call, which is what moves the
 * callee-saved pool from r3-r7 to the image's r8-r4.  With the statement after
 * the loop and index derived from a `saved` copy the row is a 90-byte DIFF.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02163CF0.c \
 *     --func CPSi_sha1_calc --addr 0x02163CF0 --region ov009 --arm --cc 1.1p1 \
 *     --lang c99 --diff
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
