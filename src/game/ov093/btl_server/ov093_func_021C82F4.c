/*
 * function: func_021C82F4
 * address:  0x021C82F4
 * packet:   pkt_ov093_021C82F4
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Tail-call stub: mov r0, r2; bx to the pool word 0x068982AD (a thumb
 * target in the 0x06xxxxxx window, not an image address).
 *
 * symbols:
 *   func_068982AC  0x068982AC  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

extern int func_068982AC(int);

int func_021C82F4(int a, int b, int c)
{
    return func_068982AC(c);
}
