/*
 * function: func_021BAAB8
 * address:  0x021BAAB8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA8BC  0x021BA8BC  thumb  ov099
 *   func_021BA978  0x021BA978  thumb  ov099
 *
 * Releases the pointer at +0x19C and re-arms the block with the one-flag.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021BA8BC(void *p);
extern void func_021BA978(char *p, int a, int b, int c);

void func_021BAAB8(char *p, int a, int b)
{
    *(void **)(p + 0x19C) = (void *)func_021BA8BC(*(void **)(p + 0x19C));
    func_021BA978(p, a, b, 1);
}
