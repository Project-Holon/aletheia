/*
 * function: func_021BDB08
 * address:  0x021BDB08
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020399A8  0x020399A8  arm
 *   func_02039CB4  0x02039CB4  arm
 *
 * Feeds the block to the arm9 predicate at 0x020399A8 and hands that answer,
 * with the constants 0x18 and 0x0A, to the arm9 predicate at 0x02039CB4; when
 * it answers non-zero, stamps selector 0x79.  Returns the second argument.
 *
 * The early return (`if (r == 0) return v; <stamp>; return v;`) is the shape
 * the image has - the plain `if (r != 0) { stamp }` makes 1.1p1 inline the
 * stamp block and invert the test to `beq`, where the image branches out of
 * line with `bne`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int func_020399A8(void *p);
extern int func_02039CB4(int a, int b, int c);

int func_021BDB08(char *p, int v)
{
    if (func_02039CB4(func_020399A8(p), 0x18, 0xA) == 0) {
        return v;
    }

    *(u32 *)(p + 0x1CC) = 0x79;
    return v;
}
