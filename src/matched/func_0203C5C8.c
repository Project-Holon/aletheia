/*
 * function: func_0203C5C8
 * address:  0x0203C5C8
 * packet:   pkt_0203C494
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203C554  0x0203C554  arm
 *   unk_021469DC   0x021469DC  data
 *
 * Arms the sequence: the slot call with a literal 1, then the same 1 into the
 * object's byte at +0x4A.  The 1 lives in r4 across the call, which is why the
 * function pushes r4 at all.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C5C8.c \
 *       --func func_0203C5C8 --addr 0x0203C5C8 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0203C554(u32 a);
extern u32  unk_021469DC;

void func_0203C5C8(void)
{
    func_0203C554(1);
    ((u8 *)unk_021469DC)[0x4A] = 1;
}
