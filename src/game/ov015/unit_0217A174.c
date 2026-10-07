/*
 * file:     unit_0217A174.c
 * unit:     yes
 * function: func_0217A174, func_0217A178, func_0217A1FC, func_0217A280, func_0217A334
 * address:  0x0217A174
 * region:   ov015
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_0217ABD8     0x0217ABD8  data  ov015
 *   d_0217ABA8     0x0217ABA8  data  ov015
 *   func_020870D0  0x020870D0  arm
 *   _ll_udiv       0x0209C00C  arm
 *   func_0217A0CC  0x0217A0CC  arm  ov015
 *   func_02179EE0  0x02179EE0  arm  ov015
 *   func_02179F28  0x02179F28  arm  ov015
 *   func_0217A7AC  0x0217A7AC  arm    ov015
 *   func_0217A034  0x0217A034  arm    ov015
 *   g_0217ABDC     0x0217ABDC  data   ov015
 *   g_0217AAB0     0x0217AAB0  data   ov015
 */
#include "../../matched/include/G_ov015_0217ABA8.h"

typedef unsigned int u32;

typedef unsigned long long u64;

typedef unsigned char u8;

extern u64 func_020870D0(void);
extern void func_0217A0CC(int a);
extern unsigned short func_02179EE0(void *input, unsigned long length);
extern void func_02179F28(void);
extern int func_0217A7AC(u8 *buf);
extern void func_0217A034(unsigned char *data, unsigned char size, int command, unsigned char id);
void func_0217A174(void);
int func_0217A178(unsigned long n);
int func_0217A1FC(void);
int func_0217A280(unsigned long n);
int func_0217A334(void);
extern unsigned char g_0217ABD8[];
extern struct G_ov015_0217ABA8 d_0217ABA8;
extern u8 g_0217ABDC[];
extern u8 g_0217AAB0[];

/*
 * notes:    empty function, a lone bx lr. Witness for the call in func_0217A334 (2026-10-05, wave P10 lane Y8).
 */
void func_0217A174(void)
{
}


/*
 * notes:    2026-10-05 wave P16 lane E4: libirc check on a packet length n. n == 1 returns 1 when the field at
 *           d_0217ABA8 + 0x24 is set, else whether the first receive byte is not 0xFC. n == 2 or 3 runs two empty
 *           delay loops (bottom-test form (i < n) ? 1 : 0, otherwise mwcc deletes them) and returns 1. Other n returns 0.
 *           The 2/3 test must be a switch after the if: `n == 2 || n == 3` folds to a range test and `n != 2 && n != 3`
 *           gives cmpne/movne. Called from func_0217A334 as int(u32).
 */
int func_0217A178(unsigned long n)
{
    unsigned long i;

    if (n == 1) {
        if (*(int *)(((char *)&d_0217ABA8) + 0x24))
            return 1;
        return g_0217ABD8[0] != 0xFC;
    }
    switch (n) {
    case 2:
    case 3:
        for (i = 0; (i < 4) ? 1 : 0; i++)
            ;
        for (i = 0; (i < n) ? 1 : 0; i++)
            ;
        return 1;
    }
    return 0;
}


int func_0217A1FC(void)
{
    u64 d;

    if (d_0217ABA8.f24 == 0 && d_0217ABA8.f1C == 0)
        return 0;
    d = func_020870D0() - d_0217ABA8.tick;
    d = (d << 6) / 33514ULL;
    if (d < 100)
        return 0;
    func_0217A0CC(1);
    d_0217ABA8.f1C = 0;
    return 1;
}


/*
 * notes:    2026-10-05 wave P13 lane B9: libirc receive check. The empty delay loop needs the bottom-test form
 *           (i < n) ? 1 : 0, otherwise mwcc deletes it. Callee func_02179EE0 is IRCi_CalcSum (u16 return, matched);
 *           func_02179F28 is void. Plain C, no pragmas.
 */
int func_0217A280(unsigned long n)
{
    unsigned char *pk = g_0217ABD8;
    unsigned long i;
    unsigned short sum;
    unsigned short calc;

    if (n == 1)
        return pk[0] == 0xFC;
    if (n < 4)
        return 0;
    sum = pk[2] + (pk[3] << 8);
    pk[2] = 0;
    pk[3] = 0;
    calc = func_02179EE0(pk, n);
    pk[3] = sum >> 8;
    pk[2] = sum;
    if (calc == sum) {
        ((char *)&d_0217ABA8)[0] = 0;
        return 1;
    }
    if (*(int *)(((char *)&d_0217ABA8) + 0x24)) {
        for (i = 0; (i < n) ? 1 : 0; i++)
            ;
        func_02179F28();
    }
    return 0;
}


#pragma opt_common_subs off

/*
 * notes:    Packet handler of the libirc link (state block 0x0217ABA8). 2026-10-05 wave P10 lane Y8 first draft; final push
 *           2026-10-05 G8L6 closed it. The 0xF8 residue was a hidden callee argument list: the onDone callback is called
 *           as onDone(pk[1], 0), so r0 keeps the byte just stored to g_0217AAB0[1] and r1 keeps the zero used for the
 *           f14/f1C stores, and the callback pointer lands in r2. The earlier draft called it with no arguments
 *           (onDone is void (*)(u8, int)). The dead `n = 1` in the 0xFA arm was not needed (the literal 1 is pooled in r5
 *           by itself) and was dropped. Pragma opt_common_subs off reproduces the three separate loads of the packet
 *           command byte. Callee types: A7AC(u8 *) returns u32, A178(u32) int, A1FC() int, A280(u32) int, 020870D0
 *           returns u64, A034 four ints. func_0217A174 is an empty leaf (bx lr), filed as ov015_func_0217A174.c.
 */
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
                (d_0217ABA8.onDone)(pk[1], 0);
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
