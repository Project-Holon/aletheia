/*
 * function: func_021BA1FC
 * address:  0x021BA1FC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Six-entry dispatch on the halfword at +0x0C: selectors 0, 3 and 4 answer true.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x0C];
    u16 f0C;
} S;

BOOL func_021BA1FC(S *s)
{
    switch (s->f0C) {
    case 0:
    case 3:
    case 4:
        return 1;
    case 1:
    case 2:
    case 5:
        return 0;
    }

    return 0;
}
