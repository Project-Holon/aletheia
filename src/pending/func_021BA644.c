/*
 * function: func_021BA644
 * address:  0x021BA644
 * packet:   pkt_021BA644
 * region:   ov225
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 *
 * blocker:  original stores -1 into p+0x24/p+0x28 as `movs r3,#0; subs r1,r3,#1`
 * (two stores of one r3-1 value), which mwcc never emits for the C shapes tried:
 * a named `int z=0` compiles the zero to r1 and `mvns`; an exponent-obscured
 * 0xFFFFFFFF literal also `mvns`; a loop over the two words becomes a counted
 * lsls/adds loop.  The original's second instruction is `subs r1,r3,#1` with
 * the zero still live in r3 and r1 as the -1 result, i.e. the compiler folded a
 * loop/copy whose counter register is r3 rather than the r1 an if-expression
 * uses.  No C shape found reaches it.  Nothing else differs.
 */

typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

void func_021BA644(char *p)
{
    int z = 0;

    *(int *)(p + 0x24) = z - 1;
    *(int *)(p + 0x28) = z - 1;
    *(int *)(p + 0x20) = z;
    *(u8 *)(p + 0x40) = 0xFF;
    *(int *)(p + 0x44) = z;
}
