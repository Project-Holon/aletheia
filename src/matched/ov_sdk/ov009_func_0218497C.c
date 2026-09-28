/*
 * function: GSMD5Update
 * address:  0x0218497C
 * packet:   pkt_ov009_0218497C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      GSMD5Update (md5c.o)
 *
 * symbols:
 *   GSMD5_memcpy                     0x0218583c arm
 *   GSMD5Transform                   0x02184ab4 arm
 */

struct GSMD5_CTX {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
};

extern void GSMD5_memcpy(unsigned char * output, unsigned char * input, unsigned int len);
extern void GSMD5Transform(unsigned int * state, unsigned char * block);

void GSMD5Update(struct GSMD5_CTX * context, unsigned char * input, unsigned int inputLen)
{
    unsigned int i, index, partLen;

    index = (unsigned int)((context->count[0] >> 3) & 0x3f);
    if ((context->count[0] += ((unsigned int)inputLen << 3)) < ((unsigned int)inputLen << 3))
        context->count[1]++;
    context->count[1] += ((unsigned int)inputLen >> 29);
    partLen = 64 - index;

    if (inputLen >= partLen)
    {
        GSMD5_memcpy(&context->buffer[index], input, partLen);
        GSMD5Transform(context->state, context->buffer);
        for (i = partLen; i + 63 < inputLen; i += 64)
            GSMD5Transform(context->state, &input[i]);
        index = 0;
    }
    else
        i = 0;

    GSMD5_memcpy(&context->buffer[index], &input[i], inputLen - i);
}
