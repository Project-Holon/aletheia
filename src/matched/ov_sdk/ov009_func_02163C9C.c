/*
 * function: CPSi_sha1_init
 * address:  0x02163C9C
 * packet:   pkt_ov009_02163C9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_sha1_init (sha1.o)
 *
 * symbols:
 *   MI_CpuFill8  0x02082BCC  arm
*/

typedef unsigned long u32;

typedef struct CPSSha1Ctx {
    u32 state[5];
    u32 count[2];
    unsigned char buffer[64];
} CPSSha1Ctx;

extern void MI_CpuFill8(void *dstp, unsigned char val, unsigned long size);

void CPSi_sha1_init(CPSSha1Ctx *ctx)
{
    MI_CpuFill8(ctx, 0, 0x5c);
    ctx->state[0] = 0x67452301;
    ctx->state[1] = 0xefcdab89;
    ctx->state[2] = 0x98badcfe;
    ctx->state[3] = 0x10325476;
    ctx->state[4] = 0xc3d2e1f0;
}
