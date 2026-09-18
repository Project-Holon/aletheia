/*
 * function: func_0203B170
 * address:  0x0203B170
 * packet:   pkt_0203B170
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * The same 0x200-byte channel-1 start as func_0203B084 with no context
 * refresh, reporting at line 0x1AE (430).  0x1AE is not ARM-encodable, so the
 * constant is materialised off the 0x200 argument register as
 * `sub r3, r4, #0x52`.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B170.c \
 *       --func func_0203B170 --addr 0x0203B170 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern u32  func_02037928(int a0, int a1);
extern void func_0203AD80(int a0, int a1, int a2, int a3);

void func_0203B170(void)
{
    if (func_02037928(1, 0x200) != 0)
        func_0203AD80((int)*(int *)((char *)(0x21469DC)), (int)0x203B16C, 0, 0x1AE);
}
