/*
 * function: func_021C1A14
 * address:  0x021C1A14
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C1C64  0x021C1C64  thumb  ov099
 *   func_021C19DC  0x021C19DC  thumb  ov099
 *
 * When the byte 0x8ED bytes in matches, hands the block and the third argument on.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_021C1C64(char *p);
extern void func_021C19DC(void *a, void *b);

void func_021C1A14(char *p, int b, void *c)
{
    if (b == func_021C1C64(p)) {
        func_021C19DC(p, c);
    }
}
