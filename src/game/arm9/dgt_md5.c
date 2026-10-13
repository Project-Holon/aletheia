/*
 * file:     dgt_md5.c
 * unit:     yes
 * function: func_02080D68, func_02081120, func_02081164, func_0208122C
 * address:  0x02080D68
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   _ZZ12ProcessBlockP14MATHMD5ContextE1t      0x020A8588  data
 *   _ZZ12ProcessBlockP14MATHMD5ContextE1k_0    0x020A84C8  data
 *   MI_CpuCopy8   0x02082D44  arm
 *   MATH_MD5Update  0x02081164  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   _ZZ15MATH_MD5GetHashP14MATHMD5ContextPvE7padding  0x020A84C4  data
 */
#define ROUND(FUNC, A, B, C, D, X, S) \
    (A) = (B) + ROTATE_LEFT((A) + FUNC((B), (C), (D)) + (X) + *tp++, (S))
typedef unsigned long u32;

typedef unsigned long long u64;

typedef unsigned char u8;

typedef struct MATHMD5Context {
    union {
        struct {
            u32 a;
            u32 b;
            u32 c;
            u32 d;
        };
        u32 state[4];
    };
    unsigned long long length;
    union {
        u32 buffer32[16];
        u8 buffer8[64];
    };
} MATHMD5Context;

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void MATH_MD5Update(MATHMD5Context *context, const void *input, u32 length);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
void func_02081120(MATHMD5Context *context);
void func_02081164(MATHMD5Context *context, const void *input, u32 length);
void func_0208122C(MATHMD5Context *context, void *digest);
extern const u32 _ZZ12ProcessBlockP14MATHMD5ContextE1t[64];
extern const u32 _ZZ12ProcessBlockP14MATHMD5ContextE1k_0[48];
/* MATH_MD5GetHash's function-local static "padding" */
extern const u8 _ZZ15MATH_MD5GetHashP14MATHMD5ContextPvE7padding[64];



static inline u32 F(u32 x, u32 y, u32 z)
{
    return (x & y) | (~x & z);
}



static inline u32 G(u32 x, u32 y, u32 z)
{
    return (x & z) | (y & ~z);
}



static inline u32 H(u32 x, u32 y, u32 z)
{
    return x ^ y ^ z;
}



static inline u32 I(u32 x, u32 y, u32 z)
{
    return y ^ (x | ~z);
}



static inline u32 ROTATE_LEFT(u32 x, int n)
{
    return (x << n) | (x >> (32 - n));
}



static void ProcessBlock(MATHMD5Context *context)
{
    u32 *kp;
    u32 a, b, c, d;
    u32 *x;
    u32 *xp;
    const u32 *tp;
    int j;

    a = context->a;
    b = context->b;
    c = context->c;
    d = context->d;
    x = context->buffer32;
    tp = _ZZ12ProcessBlockP14MATHMD5ContextE1t;
    xp = x;
    for (j = 0; j < 4; j++) {
        ROUND(F, a, b, c, d, *xp++, 7);
        ROUND(F, d, a, b, c, *xp++, 12);
        ROUND(F, c, d, a, b, *xp++, 17);
        ROUND(F, b, c, d, a, *xp++, 22);
    }
    kp = (u32 *)_ZZ12ProcessBlockP14MATHMD5ContextE1k_0;
    for (j = 0; j < 4; j++) {
        ROUND(G, a, b, c, d, x[*kp++], 5);
        ROUND(G, d, a, b, c, x[*kp++], 9);
        ROUND(G, c, d, a, b, x[*kp++], 14);
        ROUND(G, b, c, d, a, x[*kp++], 20);
    }
    for (j = 0; j < 4; j++) {
        ROUND(H, a, b, c, d, x[*kp++], 4);
        ROUND(H, d, a, b, c, x[*kp++], 11);
        ROUND(H, c, d, a, b, x[*kp++], 16);
        ROUND(H, b, c, d, a, x[*kp++], 23);
    }
    for (j = 0; j < 4; j++) {
        ROUND(I, a, b, c, d, x[*kp++], 6);
        ROUND(I, d, a, b, c, x[*kp++], 10);
        ROUND(I, c, d, a, b, x[*kp++], 15);
        ROUND(I, b, c, d, a, x[*kp++], 21);
    }
    context->a += a;
    context->b += b;
    context->c += c;
    context->d += d;
}



/*
 * sdk:      MATH_MD5Init (dgt_md5.o)
 */
void func_02081120(MATHMD5Context *context)
{
    context->a = 0x67452301;
    context->b = 0xefcdab89;
    context->c = 0x98badcfe;
    context->d = 0x10325476;
    context->length = 0;
}



/*
 * sdk:      MATH_MD5Update (dgt_md5.o)
 */
void func_02081164(MATHMD5Context *context, const void *input, u32 length)
{
    const u8 *p = (const u8 *)input;
    long i;
    u32 buffer_space;
    u32 buffer_index;

    buffer_index = (u32)(context->length & 0x3f);
    buffer_space = 64 - buffer_index;
    context->length += length;

    if (buffer_space > length) {
        if (length != 0) {
            MI_CpuCopy8(p, context->buffer8 + buffer_index, length);
        }
        return;
    }

    MI_CpuCopy8(p, context->buffer8 + buffer_index, buffer_space);
    ProcessBlock(context);
    length -= buffer_space;
    p += buffer_space;

    for (i = (long)(length >> 6); i > 0; i--) {
        MI_CpuCopy8(p, context->buffer8, 64);
        p += 64;
        ProcessBlock(context);
    }

    length &= 0x3f;
    if (length != 0) {
        MI_CpuCopy8(p, context->buffer8, length);
    }
}



/*
 * sdk:      MATH_MD5GetHash (dgt_md5.o)
 */
void func_0208122C(MATHMD5Context *context, void *digest)
{
    unsigned long long total_length;
    u32 buffer_index;
    u32 buffer_space;

    total_length = context->length << 3;

    MATH_MD5Update(context, _ZZ15MATH_MD5GetHashP14MATHMD5ContextPvE7padding, 1);

    buffer_index = (u32)(context->length & 0x3f);
    buffer_space = 64 - buffer_index;
    if (buffer_space < 8) {
        MI_CpuFill8(context->buffer8 + buffer_index, 0, buffer_space);
        ProcessBlock(context);
        buffer_index = 0;
        buffer_space = 64;
    }
    if (buffer_space > 8) {
        MI_CpuFill8(context->buffer8 + buffer_index, 0, buffer_space - 8);
    }
    *(unsigned long long *)&context->buffer32[14] = total_length;
    ProcessBlock(context);

    MI_CpuCopy8(context, digest, 16);
    MI_CpuFill8(context, 0, sizeof(MATHMD5Context));
}
