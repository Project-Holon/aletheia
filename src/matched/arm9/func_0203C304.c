/*
 * function: func_0203C304
 * address:  0x0203C304
 * packet:   pkt_0203C304
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_02037D78  0x02037D78  arm
 *   func_020398B4  0x020398B4  arm
 *   func_02039834  0x02039834  arm
 *   func_0203AD80  0x0203AD80  arm
 *
 * Teardown of one half of the net context: flags the +0x48 sentinel as -2
 * (`mvn r1, #1`, which is only reachable when the field is a signed char -
 * an unsigned one would narrow to `mov r1, #0xfe`), tears the two handles
 * down and reports at line 0x5D9, returning success.  The twin at 0x0203C35C is
 * byte-identical apart from its own line literal.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C304.c  *       --func func_0203C304 --addr 0x0203C304 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void func_02037D78(void);
extern void func_020398B4(u8 *h);
extern void func_02039834(u8 *h);
extern void func_0203AD80(int a0, int a1, int a2, int a3);

u32 func_0203C304(void)
{
    u8 *h = func_0203D788();

    *(signed char *)(*(u32 *)((char *)(0x21469DC)) + 0x48) = -2;
    func_02037D78();
    func_020398B4(h);
    func_02039834(h);
    func_0203AD80((int)*(int *)((char *)(0x21469DC)), (int)0x203C0F4, 0, (int)0x5D9);
    return 1;
}
