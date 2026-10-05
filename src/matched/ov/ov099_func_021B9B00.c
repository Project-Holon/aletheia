/*
 * function: func_021B9B00
 * address:  0x021B9B00
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BA5DC  0x021BA5DC  thumb  ov099
 *   func_021BA5F0  0x021BA5F0  thumb  ov099
 *
 * Stores the byte at +0x0B of b when b is not claimed, else hands it to the arm9 owner.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021BA5DC(void *b);
extern void func_021BA5F0(void *a, char *b, u8 c);

void func_021B9B00(void *a, char *b, u8 c)
{
    if (func_021BA5DC(b) == 0) {
        b[0xB] = c;
    } else {
        func_021BA5F0(a, b, c);
    }
}
