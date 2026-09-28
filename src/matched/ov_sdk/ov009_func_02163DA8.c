/*
 * function: CPSi_sha1_result
 * address:  0x02163DA8
 * packet:   pkt_ov009_02163DA8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_sha1_result (sha1.o)
 *
 * symbols:
 *   char_from_long  0x0216359C  arm
 *   CPSi_sha1_calc  0x02163CF0  arm
 *   padding         0x021A1F28  data
*/

typedef unsigned long u32;

typedef struct CPSSha1Ctx {
    u32 state[5];
    u32 count[2];
    unsigned char buffer[64];
} CPSSha1Ctx;

extern void char_from_long(unsigned char *d, unsigned long *s, unsigned int len);
extern void CPSi_sha1_calc(CPSSha1Ctx *ctx, void *data0, int datalen);
extern unsigned char padding[64];

void CPSi_sha1_result(CPSSha1Ctx *ctx, unsigned char *digest)
{
    int index;

    char_from_long(digest, (unsigned long *)((char *)ctx + 0x14), 8);
    index = (ctx->count[1] >> 3) & 0x3f;
    CPSi_sha1_calc(ctx, padding, index < 0x38 ? 0x38 - index : 0x78 - index);
    CPSi_sha1_calc(ctx, digest, 8);
    char_from_long(digest, (unsigned long *)ctx, 0x14);
}
