/*
 * function: CPSi_md5_init
 * address:  0x021633F0
 * packet:   pkt_ov009_021633F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_md5_init (md5.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
*/

typedef unsigned long u32;

typedef struct CPSMd5Ctx {
    u32 state[4];
    u32 count[2];
    unsigned char buffer[64];
} CPSMd5Ctx;

extern void MI_CpuFill8(void *dstp, unsigned char val, unsigned long size);

void CPSi_md5_init(CPSMd5Ctx *ctx)
{
    MI_CpuFill8(ctx, 0, 0x58);
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;
}
