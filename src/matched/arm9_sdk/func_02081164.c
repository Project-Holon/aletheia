/*
 * function: MATH_MD5Update
 * address:  0x02081164
 * packet:   pkt_02081164
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MATH_MD5Update (dgt_md5.o)
 *
 * symbols:
 *   MI_CpuCopy8   0x02082D44  arm
 *   ProcessBlock  0x02080D68  arm
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

void MATH_MD5Update(MATHMD5Context *context, const void *input, u32 length)
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
