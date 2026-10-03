/*
 * function: func_021B9D5C
 * address:  0x021B9D5C
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5608  0x021C5608  thumb  ov127
 *
 * Tail call into ov127 on the pointer 0x590 bytes into the block.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021C5608(u8 *p);

void func_021B9D5C(char *p)
{
    func_021C5608(*(void **)(p + 0x590));
}
