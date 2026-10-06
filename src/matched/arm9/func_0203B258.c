/*
 * function: func_0203B258
 * address:  0x0203B258
 * packet:   pkt_0203B258
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   func_02037894  0x02037894  arm
 *   func_0203AD80  0x0203AD80  arm
 *   unk_0203B228   0x0203B228  data
 *   unk_0203B22C   0x0203B22C  arm
 *
 * Starts a 0x200-entry transfer over channel 1 and reports through
 * func_0203AD80 at line 517 when the start call answers zero.  The line comes
 * out as `add r3, r4, #5` because r4 already holds the 0x200 argument, the
 * same constant-rematerialisation the consecutive-`__LINE__` idiom records.
 *
 * Both callback addresses (0x0203B22C and 0x0203B228, the two `bx lr` filler
 * words in the pool of func_0203B1D8) are declared as symbols: written as
 * plain integer literals this compiler folds the pair into one pool word plus
 * a `sub r1, r4, #4`, which is four bytes short of the original's two pool
 * words.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203B258.c \
 *       --func func_0203B258 --addr 0x0203B258 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *func_0203D798(void);
extern u32   func_02037894(int a0, int a1, int a2, int a3);
typedef unsigned short u16;
struct NetState;
extern void func_0203AD80(struct NetState *s, void *p, u16 v, int line);
extern char  unk_0203B228[];
extern char  unk_0203B22C[];

void func_0203B258(void)
{
    func_0203D798();
    if (func_02037894(1, 0x200, 1, (int)unk_0203B22C) != 0)
        func_0203AD80((struct NetState *)((int)*(int *)((char *)(0x21469DC))), (void *)unk_0203B228, 0, 0x205);
}
