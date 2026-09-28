/*
 * function: func_0203C938
 * address:  0x0203C938
 * packet:   pkt_0203C938
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   unk_021469DC   0x021469DC  data
 *   func_02039548  0x02039548  arm
 *   func_02039578  0x02039578  arm
 *
 * Opens the state: with no live object the answer is 0, otherwise the mode
 * byte at +0x4D is written, the two setup calls run and the answer is 1.
 * src/matched/func_0203C968.c is the matching close.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203C938.c \
 *       --func func_0203C938 --addr 0x0203C938 --cc 1.1p1 --arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 unk_021469DC;
extern void func_02039548(void);
extern void func_02039578(void);

u32 func_0203C938(u8 mode)
{
    u8 *p;

    p = (u8 *)unk_021469DC;
    if (p == 0)
        return 0;
    p[0x4D] = mode;
    func_02039548();
    func_02039578();
    return 1;
}
