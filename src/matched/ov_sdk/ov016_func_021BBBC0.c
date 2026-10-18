/*
 * function: MY_MD5Update
 * address:  0x021BBBC0
 * packet:   pkt_ov016_021BBC8C
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MD5_memcpy    0x021BC52C  thumb
 *   MD5Transform  0x021BBC8C  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(atermset.o), symbol MY_MD5Update (name from the vendor object).
 * atermset.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021BBBC0.c \
 *       --func MY_MD5Update --addr 0x021BBBC0 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
typedef unsigned long UINT4;
typedef unsigned char *POINTER;

typedef struct {
    UINT4         state[4];
    UINT4         count[2];
    unsigned char buffer[64];
} MY_MD5_CTX;

extern void MD5_memcpy(POINTER output, POINTER input, unsigned int len);
extern void MD5Transform(UINT4 state[4], unsigned char block[64]);

void MY_MD5Update(MY_MD5_CTX *context, unsigned char *input, unsigned int inputLen)
{
    unsigned int i, index, partLen;

    index = (unsigned int)((context->count[0] >> 3) & 0x3F);
    if ((context->count[0] += ((UINT4)inputLen << 3)) < ((UINT4)inputLen << 3))
        context->count[1]++;
    context->count[1] += ((UINT4)inputLen >> 29);
    partLen = 64 - index;
    if (inputLen >= partLen) {
        MD5_memcpy((POINTER)&context->buffer[index], (POINTER)input, partLen);
        MD5Transform(context->state, context->buffer);
        for (i = partLen; i + 63 < inputLen; i += 64)
            MD5Transform(context->state, &input[i]);
        index = 0;
    } else {
        i = 0;
    }
    MD5_memcpy((POINTER)&context->buffer[index], (POINTER)&input[i], inputLen - i);
}
