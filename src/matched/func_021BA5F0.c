/*
 * function: func_021BA5F0
 * address:  0x021BA5F0
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA264  0x021BA264  thumb  ov099
 *   func_021BA2A4  0x021BA2A4  thumb  ov099
 *
 * Dispatches on the class byte: case 0 runs func_021BA264, case 1 runs
 * func_021BA2A4, then the class is recorded at +0x0B of the object.  The pair
 * is a switch, not an if/else-if chain: only the switch form lays the case
 * bodies out of line the way the image does.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;

extern void func_021BA264(void *a, void *b);
extern void func_021BA2A4(void *a, void *b);

void func_021BA5F0(void *a, char *b, u8 c)
{
    switch (c) {
    case 0:
        func_021BA264(a, b);
        break;
    case 1:
        func_021BA2A4(a, b);
        break;
    }

    b[0xB] = c;
}
