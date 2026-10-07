/*
 * file:     unit_021BA2F8_p02.c
 * unit:     yes
 * function: func_021BBBC0, func_021BBC38
 * address:  0x021BBBC0
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   MD5_memcpy    0x021BC52C  thumb
 *   MD5Transform  0x021BBC8C  thumb
 *   Encode        0x021BC4D4  thumb
 *   MD5_memset    0x021BC544  thumb
 *   PADDING       0x021DABD8  data
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
extern void Encode(unsigned char *output, UINT4 *input, unsigned int len);
extern void MD5_memset(POINTER output, int value, unsigned int len);
void MY_MD5Update(MY_MD5_CTX *context, unsigned char *input, unsigned int inputLen);
void MY_MD5Final(unsigned char digest[16], MY_MD5_CTX *context);
extern unsigned char PADDING[64];


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


void MY_MD5Final(unsigned char digest[16], MY_MD5_CTX *context)
{
    unsigned char bits[8];
    unsigned int index;

    Encode(bits, context->count, 8);
    index = (unsigned int)((context->count[0] >> 3) & 0x3f);
    MY_MD5Update(context, PADDING, (index < 56) ? (56 - index) : (120 - index));
    MY_MD5Update(context, bits, 8);
    Encode(digest, context->state, 16);
    MD5_memset((POINTER)context, 0, sizeof(*context));
}
