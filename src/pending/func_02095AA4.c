/*
 * function: func_02095AA4
 * address:  0x02095AA4
 * packet:   pkt_02095AA4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * blocker:  callee func_02094B8C (the 3824-byte function at 0x02094B8C,
 *           packet pkt_02094B8C) has no witness outside 02095AA4..02095B2C,
 *           so that one call site stays wildcarded; the trailing star is
 *           the linker stub at 0x02095B2C (`ldr ip,[pc,#4]; mov r1,#0;
 *           bx ip; .word 0x02095AA4`), which is not producible from C.
 *           Everything else is byte-identical: func_020946D8 resolved as
 *           `matched` once this window's own leaf shard was written.
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
