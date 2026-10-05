/*
 * function: func_0217A334
 * address:  0x0217A334
 * packet:   pkt_ov015_0217A334
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * notes:    2026-10-05 wave P10 lane Y8: first draft, DIFF 111 B of 592 (588 compiled). Real struct
 *           St for the state block at 0x0217ABA8 (raw-offset char* form hoists both bases and gives 417 B off;
 *           the struct form leaves only the packet base in r0 as the listing has it). Pragma opt_common_subs off
 *           reproduces the three separate loads of the packet command byte (first test, switch, default arm).
 *           Plain literal 0 for n=0 is the same bytes as a zero local. Residue: the 0xF8 arm. The listing keeps
 *           the stores 1/0/0 in r1 (mov r1,#1 / mov r1,#0) where this body uses the hoisted zero r4 (one insn
 *           shorter, 4 B), so every later branch offset shifts. Tried without effect: store order 14/1C/24,
 *           chained f1C = f14 = 0, opt_propagation off, opt_lifetimes off. func_0217A174 is an empty leaf (bx lr),
 *           filed as ov015_func_0217A174.c. Callee types: A7AC(u8 *) returns u32, A178(u32) int, A1FC() int,
 *           A280(u32) int, 020870D0 returns u64, A034 four ints; all return values used, no void problem.
 *
 * symbols:
 *   func_0217A7AC  0x0217A7AC  arm    ov015
 *   func_0217A178  0x0217A178  arm    ov015
 *   func_0217A1FC  0x0217A1FC  arm    ov015
 *   func_0217A280  0x0217A280  arm    ov015
 *   func_020870D0  0x020870D0  arm
 *   func_0217A034  0x0217A034  arm    ov015
 *   func_02179F28  0x02179F28  arm    ov015
 *   func_0217A174  0x0217A174  arm    ov015
 *   g_0217ABD8     0x0217ABD8  data   ov015
 *   g_0217ABDC     0x0217ABDC  data   ov015
 *   g_0217AAB0     0x0217AAB0  data   ov015
 *   d_0217ABA8     0x0217ABA8  data   ov015
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u8 g_0217ABD8[];
extern u8 g_0217ABDC[];
extern u8 g_0217AAB0[];
typedef struct {
    int f0;
    int f4;
    void (*onData)(u8 *, u8, u8, u8);
    int fC;
    void (*onDone)(void);
    int f14;
    int f18;
    int f1C;
    int f20;
    int f24;
    u64 tick;
} St;
extern St d_0217ABA8;

extern u32 func_0217A7AC(u8 *buf);
extern int func_0217A178(u32 n);
extern int func_0217A1FC(void);
extern int func_0217A280(u32 n);
extern u64 func_020870D0(void);
extern void func_0217A034(int a0, int a1, int a2, int a3);
extern void func_02179F28(void);
extern void func_0217A174(void);

#pragma opt_common_subs off
int func_0217A334(void)
{
    u32 n;
    u8 *pk;

    n = func_0217A7AC(g_0217ABD8);
    if (func_0217A178(n))
        n = 0;
    if (n == 0)
        return func_0217A1FC() != 0;
    if (!func_0217A280(n))
        return 0;
    d_0217ABA8.tick = func_020870D0();
    pk = g_0217ABD8;
    if (pk[0] < 0xF0) {
        if (d_0217ABA8.f24 == 0)
            return 0;
        if (pk[1] != g_0217AAB0[0])
            return 0;
    }
    switch (pk[0]) {
    case 0xFC:
        switch (d_0217ABA8.f20) {
        case 0:
        case 2:
        case 3:
        case 4:
            break;
        case 1:
            d_0217ABA8.f20 = 2;
            func_0217A034(0, 0, 0xFA, g_0217AAB0[0]);
            break;
        }
        if (d_0217ABA8.f1C == 0) {
            d_0217ABA8.f1C = 1;
            d_0217ABA8.f20 = 2;
            d_0217ABA8.f18 = 0;
            if (n <= 1 || d_0217ABA8.f24 != 0) {
                func_0217A034(0, 0, 0xFA, g_0217AAB0[0]);
                if (d_0217ABA8.f24 != 0)
                    func_02179F28();
                func_0217A174();
            }
        }
        break;
    case 0xFA:
        if (d_0217ABA8.f20 == 1) {
            d_0217ABA8.f20 = 3;
            n = 1;
            d_0217ABA8.f18 = 1;
            g_0217AAB0[1] = pk[1];
            if (pk[1] == g_0217AAB0[0]) {
                func_0217A034(0, 0, 0xF8, g_0217AAB0[0]);
                d_0217ABA8.f24 = 1;
                d_0217ABA8.f14 = 0;
                d_0217ABA8.f1C = 0;
            }
        }
        break;
    case 0xF8:
        if (d_0217ABA8.f20 == 2) {
            d_0217ABA8.f20 = 4;
            g_0217AAB0[1] = pk[1];
            d_0217ABA8.f24 = 1;
            d_0217ABA8.f14 = 0;
            d_0217ABA8.f1C = 0;
            if (d_0217ABA8.onDone)
                (d_0217ABA8.onDone)();
        }
        break;
    case 0xF6:
        func_02179F28();
        break;
    default:
        if (d_0217ABA8.f14 != 1 && d_0217ABA8.f24 != 0)
            d_0217ABA8.onData(g_0217ABDC, n - 4, g_0217ABD8[0], g_0217ABD8[1]);
        break;
    }
    return 0;
}

#pragma opt_common_subs reset
