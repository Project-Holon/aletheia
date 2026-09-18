/*
 * function: func_020728E8
 * address:  0x20728E8
 * packet:   pkt_02072894
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 * note:     promoted after 0x02073EE4 (this function's own only callee without
 *           an outside witness) was matched: src/matched/func_02073EE4.c, whose
 *           shard entry pkt_02073BF0 makes that site `matched x1`
 *
 * The four zero arguments share one `mov r0, #0` and three register moves out
 *  * of it, which is what passing four literal zeros to a four-argument callee
 *  * gives here instead of four `mov rN, #0`.
 *  *
 *  * The verdict reads MATCH* because the follower at 0x02072920 carries no
 *  * func_ label -- it is a linker veneer, labelled veneer_02072920 -- so the
 *  * inferred extent runs 68 bytes instead of the 56 this file reproduces. No
 *  * byte of the 56 differs.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_02073EE4(void);
extern void func_020894DC(u32, u32, u32, u32);
extern u32  func_02089D40(void);
extern void func_02089B38(u32);
extern void func_02089CD4(u32);

void func_020728E8(void)
{
    u32 r;

    func_02073EE4();
    func_020894DC(0, 0, 0, 0);
    r = func_02089D40();
    func_02089B38(1);
    func_02089CD4(r);
}
