/*
 * function: MATH_MD5GetHash
 * address:  0x0208122C
 * packet:   pkt_0208122C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MATH_MD5GetHash (dgt_md5.o)
 *
 * symbols:
 *   MATH_MD5Update  0x02081164  arm
 *   MI_CpuFill8     0x02082BCC  arm
 *   ProcessBlock    0x02080D68  arm
 *   MI_CpuCopy8     0x02082D44  arm
 *   _ZZ15MATH_MD5GetHashP14MATHMD5ContextPvE7padding  0x020A84C4  data
 */

typedef unsigned long u32;
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

extern void MATH_MD5Update(MATHMD5Context *context, const void *input, u32 length);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern void ProcessBlock(MATHMD5Context *context);
extern void MI_CpuCopy8(const void *src, void *dest, u32 size);

/* MATH_MD5GetHash's function-local static "padding" */
extern const u8 _ZZ15MATH_MD5GetHashP14MATHMD5ContextPvE7padding[64];

void MATH_MD5GetHash(MATHMD5Context *context, void *digest)
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
