/*
 * function: func_02081120
 * address:  0x02081120
 * packet:   pkt_02081120
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      MATH_MD5Init (dgt_md5.o)
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

void func_02081120(MATHMD5Context *context)
{
    context->a = 0x67452301;
    context->b = 0xefcdab89;
    context->c = 0x98badcfe;
    context->d = 0x10325476;
    context->length = 0;
}
