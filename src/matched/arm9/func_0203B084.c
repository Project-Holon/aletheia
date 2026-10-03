/*
 * function: func_0203B084
 * address:  0x0203B084
 * packet:   pkt_0203B084
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Starts a 0x200-byte transfer over channel 1 and reports at line 0x17C
 * (380) when it answers zero.  The report site names func_0203B038, the
 * sibling entry that put the read in flight.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B084.c \
 *       --func func_0203B084 --addr 0x0203B084 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *func_0203D798(void);
typedef unsigned short u16;
extern u32 func_02037928(u32 a0, u16 a1);
extern void  func_0203AD80(int a0, int a1, int a2, int a3);

void func_0203B084(void)
{
    func_0203D798();
    if (func_02037928(1, 0x200) != 0)
        func_0203AD80((int)*(int *)((char *)(0x21469DC)), (int)0x203B038, 0, (int)0x17C);
}
