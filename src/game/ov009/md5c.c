/*
 * file:     md5c.c
 * unit:     yes
 * function: GSMD5Init, GSMD5Update, GSMD5Final, GSMD5Transform, Encode, Decode, GSMD5_memcpy, GSMD5_memset, GSMD5Print, GSMD5Digest
 * address:  0x02184938
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GSMD5Transform                   0x02184ab4 arm
 *   Encode        0x02185798 arm ov009
 *   gMd5cPad    0x021A3FC0 data
 *   gMd5cHexDigits  0x021A1A40 data
 *   GSMD5Init    0x02184938 arm ov009
 *   GSMD5Final   0x02184A34 arm ov009
 *   GSMD5Print   0x02185854 arm ov009
 *   MSL_C_LIB_MemsetPtr  0x020923B0  arm  arm9
 */
#define S11 7
#define S12 12
#define S13 17
#define S14 22
#define S21 5
#define S22 9
#define S23 14
#define S24 20
#define S31 4
#define S32 11
#define S33 16
#define S34 23
#define S41 6
#define S42 10
#define S43 15
#define S44 21
#define F(x, y, z) (((x) & (y)) | ((~x) & (z)))
#define G(x, y, z) (((x) & (z)) | ((y) & (~z)))
#define H(x, y, z) ((x) ^ (y) ^ (z))
#define I(x, y, z) ((y) ^ ((x) | (~z)))
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))
#define FF(a, b, c, d, x, s, ac) { \
    (a) += F((b), (c), (d)) + (x) + (u32)(ac); \
    (a) = ROTATE_LEFT((a), (s)); \
    (a) += (b); \
}
#define GG(a, b, c, d, x, s, ac) { \
    (a) += G((b), (c), (d)) + (x) + (u32)(ac); \
    (a) = ROTATE_LEFT((a), (s)); \
    (a) += (b); \
}
#define HH(a, b, c, d, x, s, ac) { \
    (a) += H((b), (c), (d)) + (x) + (u32)(ac); \
    (a) = ROTATE_LEFT((a), (s)); \
    (a) += (b); \
}
#define II(a, b, c, d, x, s, ac) { \
    (a) += I((b), (c), (d)) + (x) + (u32)(ac); \
    (a) = ROTATE_LEFT((a), (s)); \
    (a) += (b); \
}
struct GSMD5_CTX {
    unsigned int state[4];
    unsigned int count[2];
    unsigned char buffer[64];
};

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

static void Encode(unsigned char * output, unsigned int * input, unsigned int len);
extern void *func_02092344(void *dest, const void *src, unsigned int n);
extern void *MSL_C_LIB_MemsetPtr(void *p, int c, u32 n);
extern void GSMD5Init(struct GSMD5_CTX * context);
extern void GSMD5Final(unsigned char * digest, struct GSMD5_CTX * context);
extern void GSMD5Print(unsigned char * digest, char * output);
void GSMD5Init(struct GSMD5_CTX * context);
void GSMD5Update(struct GSMD5_CTX * context, unsigned char * input, unsigned int inputLen);
void GSMD5Final(unsigned char * digest, struct GSMD5_CTX * context);
void GSMD5Transform(u32 state[4], const u8 block[64]);
static void Encode(unsigned char * output, unsigned int * input, unsigned int len);
static void Decode(u32 *dst, const u8 *src, u32 count);
void *GSMD5_memcpy(void *dest, const void *src, unsigned int n);
void *GSMD5_memset(void *p, int c, u32 n);
void GSMD5Print(unsigned char * digest, char * output);
void GSMD5Digest(unsigned char * input, unsigned int len, char * output);
extern unsigned char gMd5cPad[64];
extern char gMd5cHexDigits[];



/*
 * sdk:      GSMD5Init (md5c)
 */
void GSMD5Init(struct GSMD5_CTX * context)
{
    context->count[0] = context->count[1] = 0;
    context->state[0] = 0x67452301;
    context->state[1] = 0xefcdab89;
    context->state[2] = 0x98badcfe;
    context->state[3] = 0x10325476;
}



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



/*
 * sdk:      GSMD5Final (md5c)
 */
void GSMD5Final(unsigned char * digest, struct GSMD5_CTX * context)
{
    unsigned char bits[8];
    unsigned int index, padLen;

    Encode(bits, context->count, 8);
    index = (unsigned int)((context->count[0] >> 3) & 0x3f);
    padLen = (index < 56) ? (56 - index) : (120 - index);
    GSMD5Update(context, gMd5cPad, padLen);
    GSMD5Update(context, bits, 8);
    Encode(digest, context->state, 16);
    GSMD5_memset((unsigned char *)context, 0, sizeof(*context));
}



void GSMD5Transform(u32 state[4], const u8 block[64])
{
    u32 a = state[0];
    u32 b = state[1];
    u32 c = state[2];
    u32 d = state[3];
    u32 x[16];

    Decode(x, block, 64);

    /* Round 1 */
    FF(a, b, c, d, x[ 0], S11, 0xd76aa478);
    FF(d, a, b, c, x[ 1], S12, 0xe8c7b756);
    FF(c, d, a, b, x[ 2], S13, 0x242070db);
    FF(b, c, d, a, x[ 3], S14, 0xc1bdceee);
    FF(a, b, c, d, x[ 4], S11, 0xf57c0faf);
    FF(d, a, b, c, x[ 5], S12, 0x4787c62a);
    FF(c, d, a, b, x[ 6], S13, 0xa8304613);
    FF(b, c, d, a, x[ 7], S14, 0xfd469501);
    FF(a, b, c, d, x[ 8], S11, 0x698098d8);
    FF(d, a, b, c, x[ 9], S12, 0x8b44f7af);
    FF(c, d, a, b, x[10], S13, 0xffff5bb1);
    FF(b, c, d, a, x[11], S14, 0x895cd7be);
    FF(a, b, c, d, x[12], S11, 0x6b901122);
    FF(d, a, b, c, x[13], S12, 0xfd987193);
    FF(c, d, a, b, x[14], S13, 0xa679438e);
    FF(b, c, d, a, x[15], S14, 0x49b40821);

    /* Round 2 */
    GG(a, b, c, d, x[ 1], S21, 0xf61e2562);
    GG(d, a, b, c, x[ 6], S22, 0xc040b340);
    GG(c, d, a, b, x[11], S23, 0x265e5a51);
    GG(b, c, d, a, x[ 0], S24, 0xe9b6c7aa);
    GG(a, b, c, d, x[ 5], S21, 0xd62f105d);
    GG(d, a, b, c, x[10], S22, 0x02441453);
    GG(c, d, a, b, x[15], S23, 0xd8a1e681);
    GG(b, c, d, a, x[ 4], S24, 0xe7d3fbc8);
    GG(a, b, c, d, x[ 9], S21, 0x21e1cde6);
    GG(d, a, b, c, x[14], S22, 0xc33707d6);
    GG(c, d, a, b, x[ 3], S23, 0xf4d50d87);
    GG(b, c, d, a, x[ 8], S24, 0x455a14ed);
    GG(a, b, c, d, x[13], S21, 0xa9e3e905);
    GG(d, a, b, c, x[ 2], S22, 0xfcefa3f8);
    GG(c, d, a, b, x[ 7], S23, 0x676f02d9);
    GG(b, c, d, a, x[12], S24, 0x8d2a4c8a);

    /* Round 3 */
    HH(a, b, c, d, x[ 5], S31, 0xfffa3942);
    HH(d, a, b, c, x[ 8], S32, 0x8771f681);
    HH(c, d, a, b, x[11], S33, 0x6d9d6122);
    HH(b, c, d, a, x[14], S34, 0xfde5380c);
    HH(a, b, c, d, x[ 1], S31, 0xa4beea44);
    HH(d, a, b, c, x[ 4], S32, 0x4bdecfa9);
    HH(c, d, a, b, x[ 7], S33, 0xf6bb4b60);
    HH(b, c, d, a, x[10], S34, 0xbebfbc70);
    HH(a, b, c, d, x[13], S31, 0x289b7ec6);
    HH(d, a, b, c, x[ 0], S32, 0xeaa127fa);
    HH(c, d, a, b, x[ 3], S33, 0xd4ef3085);
    HH(b, c, d, a, x[ 6], S34, 0x04881d05);
    HH(a, b, c, d, x[ 9], S31, 0xd9d4d039);
    HH(d, a, b, c, x[12], S32, 0xe6db99e5);
    HH(c, d, a, b, x[15], S33, 0x1fa27cf8);
    HH(b, c, d, a, x[ 2], S34, 0xc4ac5665);

    /* Round 4 */
    II(a, b, c, d, x[ 0], S41, 0xf4292244);
    II(d, a, b, c, x[ 7], S42, 0x432aff97);
    II(c, d, a, b, x[14], S43, 0xab9423a7);
    II(b, c, d, a, x[ 5], S44, 0xfc93a039);
    II(a, b, c, d, x[12], S41, 0x655b59c3);
    II(d, a, b, c, x[ 3], S42, 0x8f0ccc92);
    II(c, d, a, b, x[10], S43, 0xffeff47d);
    II(b, c, d, a, x[ 1], S44, 0x85845dd1);
    II(a, b, c, d, x[ 8], S41, 0x6fa87e4f);
    II(d, a, b, c, x[15], S42, 0xfe2ce6e0);
    II(c, d, a, b, x[ 6], S43, 0xa3014314);
    II(b, c, d, a, x[13], S44, 0x4e0811a1);
    II(a, b, c, d, x[ 4], S41, 0xf7537e82);
    II(d, a, b, c, x[11], S42, 0xbd3af235);
    II(c, d, a, b, x[ 2], S43, 0x2ad7d2bb);
    II(b, c, d, a, x[ 9], S44, 0xeb86d391);

    state[0] += a;
    state[1] += b;
    state[2] += c;
    state[3] += d;

    GSMD5_memset(x, 0, 64);
}


/*
 * sdk:      Encode (md5c)
 */
static void Encode(unsigned char * output, unsigned int * input, unsigned int len)
{
    unsigned int i, j;

    for (i = 0, j = 0; j < len; i++, j += 4)
    {
        output[j] = (unsigned char)(input[i] & 0xff);
        output[j + 1] = (unsigned char)((input[i] >> 8) & 0xff);
        output[j + 2] = (unsigned char)((input[i] >> 16) & 0xff);
        output[j + 3] = (unsigned char)((input[i] >> 24) & 0xff);
    }
}



static void Decode(u32 *dst, const u8 *src, u32 count)
{
    u32 j = 0;
    u32 i = 0;
    while (i < count) {
        u32 b0 = src[i];
        u32 b1 = src[i + 1];
        u32 b2 = src[i + 2];
        u32 b3 = src[i + 3];
        dst[j] = b0 | (b1 << 8) | (b2 << 16) | (b3 << 24);
        i += 4;
        j++;
    }
}



/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
void *GSMD5_memcpy(void *dest, const void *src, unsigned int n)
{
    return func_02092344(dest, src, n);
}



void *GSMD5_memset(void *p, int c, u32 n)
{
    return MSL_C_LIB_MemsetPtr(p, c, n);
}



void GSMD5Print(unsigned char * digest, char * output)
{
    unsigned int i;

    for (i = 0; i < 16; i++)
    {
        output[i * 2] = gMd5cHexDigits[digest[i] / 16];
        output[i * 2 + 1] = gMd5cHexDigits[digest[i] % 16];
    }
    output[32] = 0;
}



/*
 * sdk:      GSMD5Digest (md5c)
 */
void GSMD5Digest(unsigned char * input, unsigned int len, char * output)
{
    struct GSMD5_CTX ctx;
    unsigned char digest[16];

    GSMD5Init(&ctx);
    GSMD5Update(&ctx, input, len);
    GSMD5Final(digest, &ctx);
    GSMD5Print(digest, output);
}
