/*
 * function: func_021BCBBC
 * address:  0x021BCBBC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201A090  0x0201A090  thumb
 *
 * Returns 4 or whatever func_0201A090 answers, and writes 0 or -1 through
 * the third argument.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_0201A090(int a);

int func_021BCBBC(int a, int b, int *out)
{
    int r = 4;

    *out = 0;

    if (b != 0) {
        r = func_0201A090(a);
    } else {
        *out = -1;
    }

    return r;
}
