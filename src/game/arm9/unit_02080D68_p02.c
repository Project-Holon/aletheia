/*
 * file:     unit_02080D68_p02.c
 * unit:     yes
 * function: func_02081164, func_0208122C
 * address:  0x02081164
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
 *   MI_CpuCopy8   0x02082D44  arm
 *   ProcessBlock  0x02080D68  arm
 *   MATH_MD5Update  0x02081164  arm
 *   MI_CpuFill8     0x02082BCC  arm
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

extern void MI_CpuCopy8(const void *src, void *dest, u32 size);
extern void ProcessBlock(MATHMD5Context *context);
extern void MATH_MD5Update(MATHMD5Context *context, const void *input, u32 length);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
void func_02081164(MATHMD5Context *context, const void *input, u32 length);
void func_0208122C(MATHMD5Context *context, void *digest);
/* MATH_MD5GetHash's function-local static "padding" */
extern const u8 _ZZ15MATH_MD5GetHashP14MATHMD5ContextPvE7padding[64];


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
