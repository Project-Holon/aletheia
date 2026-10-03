/*
 * function: func_0203C068
 * address:  0x0203C068
 * packet:   pkt_0203C068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203AD80  0x0203AD80  arm
 *
 * Calls the virtual at +0xC of the object at *(net context + 0x340) with a
 * zero argument and reports through func_0203AD80 when it answers a negative
 * result.  The `mov r4, #0` local is what feeds both the call's r0 and the
 * report's r2, hence its placement; the `popge` is the `>= 0` half of the
 * signed comparison.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C068.c  *       --func func_0203C068 --addr 0x0203C068 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void  func_0203AD80(int a0, int a1, int a2, int a3);

void func_0203C068(void)
{
    if (((int (*)(u32))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0xC))(0) < 0)
        func_0203AD80((int)*(int *)((char *)(0x21469DC)), (int)0x203C05C, 0, (int)0x52C);
}
