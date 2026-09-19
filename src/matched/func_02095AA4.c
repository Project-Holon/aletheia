/*
 * function: func_02095AA4
 * address:  0x02095AA4
 * packet:   pkt_02095AA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * PROMOTED from src/pending/ with no change to the C (lane r5c, 2026-09-19):
 * the park's only blocker was the PC24 at +0x34, and 0x02094B8C is now a
 * layout/runtime_arm9.txt entry (_msl_scanf_strtod_core), so that site
 * attests as `runtime` and every relocation resolves:
 *
 *   +0034 PC24 func_02094B8C   -> 02094B8C  [runtime x1, e.g. 02094B8C]
 *   +0058 PC24 func_0209A504   -> 0209A504  [label x15, e.g. 02093310]
 *   +0080 ABS32 func_020946D8  -> 020946D8  [literal x15, e.g. 02095F38]
 *   +0084 ABS32 g_02153FAC     -> 02153FAC  [literal x35, e.g. 02091D34]
 *
 * EXACT* and not EXACT: the compiled body is 136 bytes and the listing extent
 * is 152, because the follower at 0x02095B2C is the linker stub
 * (`ldr ip,[pc,#4]; mov r1,#0; bx ip; .word 0x02095AA4`), which carries no
 * func_ label and is not producible from C, so the inferred extent runs long
 * over it.  No byte inside the compared range differs.
 *
 * symbols:
 *   func_020946D8  0x020946D8  arm
 *   func_02094B8C  0x02094B8C  arm
 *   func_0209A504  0x0209A504  arm
 *   g_02153FAC     0x02153FAC  data
 */

typedef unsigned int u32;
typedef unsigned long long u64;

extern u64 func_02094B8C(u32 a0, u32 cb, u32 *buf, u32 *end, u32 *flag);
extern void func_0209A504(u32 lo, u32 hi);
extern int func_020946D8(u32 *p, u32 a1, u32 a2);
extern u32 g_02153FAC;

u64 func_02095AA4(u32 a0, u32 *a1)
{
    u32 buf[4];
    u64 r;

    buf[1] = 0;
    buf[0] = a0;
    r = func_02094B8C(0x7FFFFFFFu, (u32)func_020946D8, buf, &buf[3], &buf[2]);
    if (a1 != 0)
        *a1 = a0 + buf[3];
    func_0209A504((u32)r, (u32)(r >> 32));
    if (buf[2] != 0)
        g_02153FAC = 0x22;
    return r;
}
