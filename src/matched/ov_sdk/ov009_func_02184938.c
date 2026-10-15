/*
 * function: GSMD5Init
 * address:  0x02184938
 * packet:   pkt_ov009_02184938
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GSMD5Init (md5c)
 *
 * symbols:
 *   (none)
 */

struct GSMD5_CTX {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
};

void GSMD5Init(struct GSMD5_CTX * context)
{
    context->count[0] = context->count[1] = 0;
    context->state[0] = 0x67452301;
    context->state[1] = 0xefcdab89;
    context->state[2] = 0x98badcfe;
    context->state[3] = 0x10325476;
}
