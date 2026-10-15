/*
 * function: NNS_G2dSetupCellBank
 * address:  0x02061390
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A8150     0x020A8150  data
 *   g_020A816C     0x020A816C  data
 *
 * The two pool words at 0x020613D0 / 0x020613D4 resolve through `literal`
 * witnesses in other functions (0x020614D0 for the table, 0x0206163C for the
 * global), so the file is EXACT; its section is 72 bytes, the 64 code bytes
 * the worklist records plus its own pool.
 *
 * The function indexes a table of 0x18-byte records (mla r6, r0, ip, r5 with
 * ip = 0x18) five times, once per parameter, and stores the five computed
 * addresses into consecutive words at +8..+0x18 of a global at 0x020A8150.
 * The fifth parameter arrives on the stack, at [sp, #0x10] before the push.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/NNS_G2dSetupCellBank.c \
 *       --func NNS_G2dSetupCellBank --addr 0x02061390 --arm --cc 1.1p1
 *   EXACT, 72 bytes, 2 relocation sites, all 2 resolved.
 */

#include "../include/G_Ptrs020A8150.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ent020A816C {
    u32 w[6];
};

extern struct Ent020A816C  g_020A816C[];
extern struct Ptrs020A8150 g_020A8150;

void NNS_G2dSetupCellBank(u32 a, u32 b, u32 c, u32 d, u32 e)
{
    g_020A8150.p[0] = (u32)&g_020A816C[a];
    g_020A8150.p[1] = (u32)&g_020A816C[b];
    g_020A8150.p[2] = (u32)&g_020A816C[c];
    g_020A8150.p[3] = (u32)&g_020A816C[d];
    g_020A8150.p[4] = (u32)&g_020A816C[e];
}
