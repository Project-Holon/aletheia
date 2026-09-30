/*
 * function: CPSi_md5_calc
 * address:  0x02163438
 * packet:   pkt_ov009_02163438
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_md5_calc (md5.o)
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   CPSi_md5_block 0x02162FF0  arm
 *
 * Folds `datalen` bytes into the MD5 context, blocking on the 64-byte
 * boundary: flush the partial block, then block on every whole one.
 *
 * The parked form wrote `index = 0;` after the block loop; the image writes it
 * before the `CPSi_md5_block(ctx, ctx->buffer)` call that follows the partial
 * copy, and that placement is what settles the whole function: it shortens the
 * if-branch so `room` dies into the loop counter, and it lifts the callee-saved
 * pool from r3-r7 to r8-r4, matching the image's push {r4,r5,r6,r7,r8,lr} and
 * the register ranking ctx/data/datalen/room/index = r8/r7/r6/r5/r4.  With the
 * statement at the end of the branch the same locals sit one register lower
 * (76 bytes).  Declaration order is inert.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov_sdk/ov009_func_02163438.c \
 *     --func CPSi_md5_calc --addr 0x02163438 --region ov009 --arm --cc 1.1p1 \
 *     --lang c99 --diff
 */

typedef unsigned long u32;

typedef struct CPSMd5Ctx {
    u32 state[4];
    u32 count[2];
    unsigned char buffer[64];
} CPSMd5Ctx;

extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern void CPSi_md5_block(CPSMd5Ctx *ctx, unsigned char *m);

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
