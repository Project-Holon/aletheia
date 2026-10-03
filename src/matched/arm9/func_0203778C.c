/*
 * function: func_0203778C
 * address:  0x0203778C
 * packet:   pkt_02037288
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   func_0203D788   0x0203D788  arm
 *
 * 32-byte hook dispatcher: func_0203D788 returns the current context, whose
 * word at +0x340 names a vtable whose slot +0x90 is called with the incoming
 * argument.  The call is a real `blx r1` and not a tail call because r4 has to
 * be restored afterwards, which is what makes it `return f(p)` and not a
 * `bx`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203778C.c \
 *       --func func_0203778C --addr 0x0203778C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *func_0203D788(void);

u32 func_0203778C(u32 p)
{
    char *c = func_0203D788();
    u32 (*f)(u32) = *(u32 (**)(u32))(*(char **)(c + 0x340) + 0x90);

    return f(p);
}
