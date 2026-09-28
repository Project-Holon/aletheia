/*
 * function: func_021BC73C
 * address:  0x021BC73C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA928  0x021BA928  thumb  ov099
 *
 * Ages the counter at +0x1E0 into the guard call, then stamps the byte at
 * +0x1353 and selector 0x8A when it has gone negative; returns the selector.
 * The guard call takes the aged value, not the selector.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern int func_021BA928(void *p, int v);

int func_021BC73C(char *p, int v)
{
    func_021BA928(p, --*(s32 *)(p + 0x1E0));

    if (*(s32 *)(p + 0x1E0) < 0) {
        *(u8 *)(p + 0x1353) = 0x79;
        *(u32 *)(p + 0x1CC) = 0x8A;
    }

    return v;
}
