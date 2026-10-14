/*
 * function: IRC_Move
 * address:  0x0217A334
 * packet:   pkt_ov015_0217A334
 * region:   ov015
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * notes:    Packet handler of the libirc link (state block 0x0217ABA8). 2026-10-05 wave P10 lane Y8 first draft; final push
 *           2026-10-05 G8L6 closed it. The 0xF8 residue was a hidden callee argument list: the onDone callback is called
 *           as onDone(pk[1], 0), so r0 keeps the byte just stored to g_0217AAB0[1] and r1 keeps the zero used for the
 *           f14/f1C stores, and the callback pointer lands in r2. The earlier draft called it with no arguments
 *           (onDone is void (*)(u8, int)). The dead `n = 1` in the 0xFA arm was not needed (the literal 1 is pooled in r5
 *           by itself) and was dropped. Pragma opt_common_subs off reproduces the three separate loads of the packet
 *           command byte. Callee types: A7AC(u8 *) returns u32, A178(u32) int, A1FC() int, A280(u32) int, 020870D0
 *           returns u64, A034 four ints. IRCi_Nop is an empty leaf (bx lr), filed as ov015_func_0217A174.c.
 *
 * symbols:
 *   IRCi_Read  0x0217A7AC  arm    ov015
 *   IRCi_CheckLength  0x0217A178  arm    ov015
 *   IRCi_CheckTimeout  0x0217A1FC  arm    ov015
 *   IRCi_CheckPacket  0x0217A280  arm    ov015
 *   func_020870D0  0x020870D0  arm
 *   IRCi_Send  0x0217A034  arm    ov015
 *   IRCi_Restore  0x02179F28  arm    ov015
 *   IRCi_Nop  0x0217A174  arm    ov015
 *   gIrcBuffer     0x0217ABD8  data   ov015
 *   gIrcBufferPayload     0x0217ABDC  data   ov015
 *   g_0217AAB0     0x0217AAB0  data   ov015
 *   d_0217ABA8     0x0217ABA8  data   ov015
 */

#include "../include/G_ov015_0217ABA8.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;

extern u8 gIrcBuffer[];
extern u8 gIrcBufferPayload[];
extern u8 g_0217AAB0[];
extern struct G_ov015_0217ABA8 d_0217ABA8;

extern int IRCi_Read(u8 *buf);
extern int IRCi_CheckLength(u32 n);
extern int IRCi_CheckTimeout(void);
extern int IRCi_CheckPacket(u32 n);
extern u64 func_020870D0(void);
extern void IRCi_Send(unsigned char *data, unsigned char size, int command, unsigned char id);
extern void IRCi_Restore(void);
extern void IRCi_Nop(void);

#pragma opt_common_subs off
int IRC_Move(void)
{
    u32 n;
    u8 *pk;

    n = IRCi_Read(gIrcBuffer);
    if (IRCi_CheckLength(n))
        n = 0;
    if (n == 0)
        return IRCi_CheckTimeout() != 0;
    if (!IRCi_CheckPacket(n))
        return 0;
    d_0217ABA8.tick = func_020870D0();
    pk = gIrcBuffer;
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
            IRCi_Send(0, 0, 0xFA, g_0217AAB0[0]);
            break;
        }
        if (d_0217ABA8.f1C == 0) {
            d_0217ABA8.f1C = 1;
            d_0217ABA8.f20 = 2;
            d_0217ABA8.f18 = 0;
            if (n <= 1 || d_0217ABA8.f24 != 0) {
                IRCi_Send(0, 0, 0xFA, g_0217AAB0[0]);
                if (d_0217ABA8.f24 != 0)
                    IRCi_Restore();
                IRCi_Nop();
            }
        }
        break;
    case 0xFA:
        if (d_0217ABA8.f20 == 1) {
            d_0217ABA8.f20 = 3;
            d_0217ABA8.f18 = 1;
            g_0217AAB0[1] = pk[1];
            if (pk[1] == g_0217AAB0[0]) {
                IRCi_Send(0, 0, 0xF8, g_0217AAB0[0]);
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
        IRCi_Restore();
        break;
    default:
        if (d_0217ABA8.f14 != 1 && d_0217ABA8.f24 != 0)
            d_0217ABA8.onData(gIrcBufferPayload, n - 4, gIrcBuffer[0], gIrcBuffer[1]);
        break;
    }
    return 0;
}

#pragma opt_common_subs reset
