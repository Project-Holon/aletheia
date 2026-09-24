/*
 * function: func_021BA594
 * address:  0x021BA594
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5F44  0x021C5F44  thumb  ov127
 *
 * Packs the three value arguments into a four-byte stack record (halfword,
 * byte, byte) and hands it, with the pointer at +0x59C, to the ov127 routine
 * at 0x021C5F44.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern void func_021C5F44(void *a, void *b);

void func_021BA594(char *p, u16 a, u8 b, u8 c)
{
    struct S { u16 a; u8 b; u8 c; } s;

    s.a = a;
    s.b = b;
    s.c = c;
    func_021C5F44(*(void **)(p + 0x59C), &s);
}
