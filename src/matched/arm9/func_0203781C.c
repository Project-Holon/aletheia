/*
 * function: func_0203781C
 * address:  0x0203781C
 * packet:   pkt_02037288
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D798   0x0203D798  arm
 *   func_0203D788   0x0203D788  arm
 *   func_02037680   0x02037680  arm
 *
 * Reset-and-notify hook: two context getters, the per-slot reset for `arg`,
 * and then the hook at +8 of the first context if it is installed, called with
 * the first context's word at +0x34C and the incoming argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203781C.c \
 *       --func func_0203781C --addr 0x0203781C --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern void func_02037680(int i);

void func_0203781C(u32 arg)
{
    char *a = func_0203D798();
    char *b = func_0203D788();
    void (*hook)(u32, u32);

    func_02037680(arg);

    hook = *(void (**)(u32, u32))(a + 8);
    if (hook == 0)
        return;
    hook(*(u32 *)(b + 0x34C), arg);
}
