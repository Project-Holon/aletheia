/*
 * Part of a translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/000_02004000.s.
 *
 * unit:     yes
 * address:  0x020064F4
 * packet:   pkt_020064F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: sub_020064F4, sub_02006504, sub_02006518
 *
 * symbols:
 *   sub_0200590C   0x0200590C  thumb
 *   sub_020059C8   0x020059C8  thumb
 *   func_02072E7C  0x02072E7C  arm
 *   func_02074324  0x02074324  arm
 *   func_020743EC  0x020743EC  arm
 *   func_02074694  0x02074694  arm
 *   func_02075560  0x02075560  arm
 *
 * Three short entry points that take the current connection slot's payload
 * from sub_0200590C, which is the last function of
 * src/matched/unit_020057DC.c, and hand it to the library.  sub_02006518 is
 * the odd one: it does not use the slot at all but looks the same object up
 * twice, through two different library entry points, with the same constant
 * 0x3F2, and shuts both results down.  0x3F2 is past the range of a Thumb
 * `movs` immediate, so it arrives in r4 through a literal pool word and is
 * used twice from there.
 */

typedef unsigned int u32;

extern u32 *sub_0200590C(void);
extern void sub_020059C8(void);
extern void func_02072E7C(u32 *a, u32 b);
extern u32 *func_02074324(u32 a);
extern u32 *func_020743EC(u32 a);
extern void func_02074694(u32 a, u32 b);
extern u32 func_02075560(u32 a, u32 b);

void sub_020064F4(u32 a)
{
    func_02075560((u32)sub_0200590C(), a);
}

void sub_02006504(void)
{
    func_02072E7C(sub_0200590C(), 0);
    sub_020059C8();
}

void sub_02006518(void)
{
    u32 a = *func_020743EC(0x3F2);
    u32 b = *func_02074324(0x3F2);

    func_02074694(a, 0);
    func_02074694(b, 0);
}
