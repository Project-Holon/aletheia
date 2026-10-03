/*
 * function: func_02037858
 * address:  0x02037858
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
 * Byte-for-byte twin of func_0203781C (same 60 bytes, same call order): two
 * context getters, the per-slot reset for `arg`, then the hook at +8 of the
 * first context when it is installed, called with the first context's word at
 * +0x34C and the argument.  Two copies of the same 60 bytes exist in the image
 * and this is the second, so the pair also demonstrates that the listing's
 * duplicate-glue pattern is real code and not one function reached twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037858.c \
 *       --func func_02037858 --addr 0x02037858 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern void *func_0203D798(void);
extern void *func_0203D788(void);
extern void func_02037680(int i);

void func_02037858(u32 arg)
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
