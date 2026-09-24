/*
 * function: func_021BD41C
 * address:  0x021BD41C
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
 * Ages the counter at +0x1E0 under the guard and stamps selector 0x6A when it
 * underflows; returns the selector.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern int func_021BA928(void *p, int v);

int func_021BD41C(char *p, int v)
{
    if (func_021BA928(p, v) != 0) {
        int x = *(int *)(p + 0x1E0);

        *(int *)(p + 0x1E0) = x - 1;

        if (x < 0) {
            *(u32 *)(p + 0x1CC) = 0x6A;
        }
    }

    return v;
}
