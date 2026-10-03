/*
 * function: func_021C23D8
 * address:  0x021C23D8
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B98F8  0x021B98F8  thumb  ov099
 *   func_021BAADC  0x021BAADC  thumb  ov099
 *
 * Raises the state word at +0x9B4 once, re-arms the block 0x274 bytes in, and
 * runs the six/zero setup when the selector is 1.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void func_021B98F8(char *p, int b);
extern void func_021BAADC(char *p, int a, int b);

void func_021C23D8(char *p, int v)
{
    if (*(u32 *)(p + 0x9B4) != 0) {
        return;
    }

    *(u32 *)(p + 0x9B4) = 1;
    func_021B98F8(p + 0x274, 1);

    if (v == 1) {
        func_021BAADC(p, 6, 0);
    }
}
