/*
 * unit:     no
 * function: func_02041090
 * address:  0x02041090
 * packet:   pkt_02040F84
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020410D0  0x020410D0  arm
 *
 * The short public entry point in front of src/matched/func_020410D0.c: it
 * drops the caller's second argument out of the register block, shifts the
 * third and fourth down into r1/r2, and rebuilds the ten-argument call with
 * the two u8 tail arguments duplicated and a pair of zeroes in between.
 *
 * Reading the callee's argument list back, this is the "no clip rectangle"
 * form: arguments 7 and 8 of func_020410D0 are the clip origin and are passed
 * as zero, while arguments 9 and 10 repeat the size pair given here, so the
 * clip box is the whole destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02041090.c \
 *       --func func_02041090 --addr 0x02041090 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5,
                          u8 a6, u8 a7, u8 a8, u8 a9);

void func_02041090(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u8 a5)
{
    func_020410D0(index, a2, a3, a4, a5, a1, 0, 0, a4, a5);
}
