/*
 * function: GSMD5Final
 * address:  0x02184A34
 * packet:   pkt_ov009_02184A34
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GSMD5Final (md5c)
 *
 * symbols:
 *   Encode        0x02185798 arm ov009
 *   GSMD5Update   0x0218497C arm ov009
 *   GSMD5_memset  0x02185848 arm ov009
 *   g_021A3FC0    0x021A3FC0 data
 */

struct GSMD5_CTX {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
};

extern void Encode(unsigned char * output, unsigned int * input, unsigned int len);
extern void GSMD5Update(struct GSMD5_CTX * context, unsigned char * input, unsigned int inputLen);
extern void GSMD5_memset(unsigned char * output, int value, unsigned int len);
extern unsigned char g_021A3FC0[64];

void GSMD5Final(unsigned char * digest, struct GSMD5_CTX * context)
{
    unsigned char bits[8];
    unsigned int index, padLen;

    Encode(bits, context->count, 8);
    index = (unsigned int)((context->count[0] >> 3) & 0x3f);
    padLen = (index < 56) ? (56 - index) : (120 - index);
    GSMD5Update(context, g_021A3FC0, padLen);
    GSMD5Update(context, bits, 8);
    Encode(digest, context->state, 16);
    GSMD5_memset((unsigned char *)context, 0, sizeof(*context));
}
