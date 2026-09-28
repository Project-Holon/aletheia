/*
 * function: CPSi_md5_calc
 * address:  0x02163438
 * packet:   pkt_ov009_02163438
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      CPSi_md5_calc (md5.o)
 *
 * blocker:  register allocation shift.  The instruction stream is identical,
 *           but the image keeps ctx/data0/datalen/index/room in r8/r7/r6/r4/r5
 *           while this compiler form uses r7/r6/r5/r3/r4 (one lower; r3 saved
 *           instead of r8 used).  All 76 differing bytes are register numbers.
 *           Tried: all 24 declaration-order permutations of the four locals,
 *           a named `saved` old-count temp in every position, unsigned/long/
 *           int datalen, index-computed-before vs after the count update,
 *           no `data` local, declaration initialisers.  None moved the base.
 *
 * symbols:
 *   MI_CpuCopy8    0x02082D44  arm
 *   CPSi_md5_block 0x02162FF0  arm
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
        CPSi_md5_block(ctx, ctx->buffer);
        for (i = room; i + 63 < (unsigned int)datalen; i += 64)
            CPSi_md5_block(ctx, data + i);
        index = 0;
    } else {
        i = 0;
    }
    MI_CpuCopy8(data + i, ctx->buffer + index, datalen - i);
}
