/*
 * function: func_0203B448
 * address:  0x0203B448
 * packet:   pkt_0203B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Reports at line 0x25D (605) when the transport's +0x78 virtual answers
 * non-zero.  The condition is the negated guard - the `pop` is on the equal
 * arm - so the C is the report inside a `!= 0` if, not a return.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B448.c \
 *       --func func_0203B448 --addr 0x0203B448 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void  func_0203AD80(int a0, int a1, int a2, int a3);

void func_0203B448(void)
{
    if (((u32 (*)(void))*(u32 *)(*(u32 *)((char *)func_0203D788() + 0x340) + 0x78))() != 0)
        func_0203AD80((int)*(int *)((char *)(0x21469DC)), (int)0x203B390, 0, (int)0x25D);
}
