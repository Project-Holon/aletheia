/*
 * function: func_02016984
 * address:  0x02016984
 * packet:   pkt_020163C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_020A72CC  0x020A72CC  data
 *
 * A two-call registrar.  The first call is five arguments wide: the value
 * loaded from +0x14c is an `int` truncated to `u16` at the call (the listing
 * shows `ldr` + the lsls/lsrs 0x10 pair, not a `ldrh` - declaring the field
 * itself `u16` is what produces a `ldrh` and loses four bytes), and 0x970 is
 * the fifth argument on the stack.  The result is stored back into +0x98,
 * which the second call reads as its own second argument, so the field is a
 * genuine `int`.
 *
 * The pool word at 0x020169D0 is 0x020A72CC; that same word sits in eight
 * other functions' pools in this image (0x02014B9C, 0x02015B94, 0x02016240,
 * 0x02016360, 0x02016624, 0x02016870, 0x02016B84, ...), all outside the
 * compared range, which is what attests the site through the `literal` class.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02016984.c \
 *       --func func_02016984 --addr 0x02016984 --cc 1.1p1 --thumb
 */

typedef unsigned int   u32;
extern int func_020648B4(u32 a, u32 b);
extern void *func_02030734(u32 a0, u32 a1, int a2, const char *a3, unsigned short a4);
extern void func_02064754(int a0, int a1, int a2, int a3, int a4, int a5);

extern char data_020A72CC[];

void func_02016984(char *a0, int a1)
{
    *(int *)(a0 + 0x98) = (int)func_02030734((unsigned short)*(int *)(a0 + 0x14c),
                                        func_020648B4(*(int *)(a0 + 0x18), a1),
                                        0, data_020A72CC, 0x970);
    func_02064754((int)(a0 + 0x34), *(int *)(a0 + 0x98), *(int *)(a0 + 0x20),
                  *(int *)(a0 + 0x10), *(int *)(a0 + 0x18), a1);
}
