/*
 * function: func_021B9B24
 * address:  0x021B9B24
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B9BC4  0x021B9BC4  thumb  ov099
 *   func_021B984C  0x021B984C  thumb  ov099
 *   func_021BA794  0x021BA794  thumb  ov099
 *
 * Toggles bit (state - 3) of the block 0x574 bytes in when the entry test answers 1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021B9BC4(void *p);
extern int func_021B984C(void *p);
extern void func_021BA794(u8 *p, u8 b);

void func_021B9B24(char *p)
{
    if (func_021B9BC4(p) == 1) {
        s8 x = (s8)func_021B984C(p);
        s8 y = x - 3;

        func_021BA794((u8 *)(p + 0x574), y);
    }
}
