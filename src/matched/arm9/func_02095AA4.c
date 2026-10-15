/*
 * function: strtod
 * address:  0x02095AA4
 * packet:   pkt_02095AA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * PROMOTED from src/pending/ with no change to the C (lane r5c, 2026-09-19):
 * the park's only blocker was the PC24 at +0x34, and 0x02094B8C is now a
 * layout/runtime_arm9.txt entry (_msl_scanf_strtod_core), so that site
 * attests as `runtime` and every relocation resolves:
 *
 *   +0034 PC24 __strtold   -> 02094B8C  [runtime x1, e.g. 02094B8C]
 *   +0058 PC24 fabs   -> 0209A504  [label x15, e.g. 02093310]
 *   +0080 ABS32 MSL_C_LIB_StrReadProc  -> 020946D8  [literal x15, e.g. 02095F38]
 *   +0084 ABS32 errno     -> 02153FAC  [literal x35, e.g. 02091D34]
 *
 * EXACT* and not EXACT: the compiled body is 136 bytes and the listing extent
 * is 152, because the follower at 0x02095B2C is the linker stub
 * (`ldr ip,[pc,#4]; mov r1,#0; bx ip; .word 0x02095AA4`), which carries no
 * func_ label and is not producible from C, so the inferred extent runs long
 * over it.  No byte inside the compared range differs.
 *
 * symbols:
 *   MSL_C_LIB_StrReadProc  0x020946D8  arm
 *   __strtold  0x02094B8C  arm
 *   fabs  0x0209A504  arm
 *   errno     0x02153FAC  data
 */

typedef unsigned int u32;
typedef unsigned long long u64;

extern u64 __strtold(u32 a0, u32 cb, u32 *buf, u32 *end, u32 *flag);
extern void fabs(u32 lo, u32 hi);
extern int MSL_C_LIB_StrReadProc(u32 *p, u32 a1, u32 a2);
extern u32 errno;

u64 strtod(u32 a0, u32 *a1)
{
    u32 buf[4];
    u64 r;

    buf[1] = 0;
    buf[0] = a0;
    r = __strtold(0x7FFFFFFFu, (u32)MSL_C_LIB_StrReadProc, buf, &buf[3], &buf[2]);
    if (a1 != 0)
        *a1 = a0 + buf[3];
    fabs((u32)r, (u32)(r >> 32));
    if (buf[2] != 0)
        errno = 0x22;
    return r;
}
