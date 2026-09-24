/*
 * function: func_021BA5DC
 * address:  0x021BA5DC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA2D4  0x021BA2D4  thumb
 *
 * True unless the pointer at +0x18 is func_021BA2D4 itself.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x18];
    void *f18;
} S;

extern void func_021BA2D4(void);

BOOL func_021BA5DC(S *s)
{
    if (s->f18 != (void *)func_021BA2D4) {
        return 1;
    }

    return 0;
}
