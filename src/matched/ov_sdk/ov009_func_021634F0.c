/*
 * function: CPSi_md5_result
 * address:  0x021634F0
 * packet:   pkt_ov009_021634F0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CPSi_md5_result (md5.o)
 *
 * symbols:
 *   char_from_long  0x02162FC0  arm
 *   CPSi_md5_calc   0x02163438  arm
 *   padding         0x021A1DE8  data
*/

typedef unsigned long u32;

typedef struct CPSMd5Ctx {
    u32 state[4];
    u32 count[2];
    unsigned char buffer[64];
} CPSMd5Ctx;

extern void char_from_long(unsigned char *d, unsigned long *s, unsigned int len);
extern void CPSi_md5_calc(CPSMd5Ctx *ctx, void *data0, int datalen);
extern unsigned char padding[64];

void CPSi_md5_result(CPSMd5Ctx *ctx, unsigned char *digest)
{
    int index;

    char_from_long(digest, (unsigned long *)((char *)ctx + 0x10), 8);
    index = (ctx->count[0] >> 3) & 0x3f;
    CPSi_md5_calc(ctx, padding, index < 0x38 ? 0x38 - index : 0x78 - index);
    CPSi_md5_calc(ctx, digest, 8);
    char_from_long(digest, (unsigned long *)ctx, 0x10);
}
