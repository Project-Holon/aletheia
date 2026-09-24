/*
 * function: func_021BA7BC
 * address:  0x021BA7BC
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BA78C  0x021BA78C  thumb
 *
 * When the byte at +0x0D is set, runs the reset at func_021BA78C on the block.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

typedef struct {
    char pad[0x0D];
    u8 f0D;
} S;

extern void func_021BA78C(S *s);

void func_021BA7BC(S *s)
{
    if (s->f0D != 0) {
        func_021BA78C(s);
    }
}
