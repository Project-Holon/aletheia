/*
 * function: func_020727B4
 * address:  0x020727B4
 * packet:   pkt_020727B4
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Double-buffered SND_ReadDriverInfo pump over the 0x0214BAC0 control block
 * (the same base src/pending/func_020726D0.c initialises) and the pair of
 * 0x11E0-byte info buffers at 0x0214BB00.
 *
 * BYTE-CORRECT at 212 bytes, 0 concrete mismatches.  PARKED, NOT FILED: the two
 * PC24 sites at +0x68 and +0xB8 both name SND_ReadDriverInfo (0x02089794),
 * whose ONLY branches anywhere in the image are those two `bl`s, both inside
 * this one function.  `label` refuses a witness that lives inside the compared
 * range, and the two calls sit in mutually exclusive arms of the same function,
 * so no --suggest-split cut can separate them.  Capped at MATCH until some
 * other caller of SND_ReadDriverInfo is filed.
 *
 * PIN ../2.0/sp2, the "kept constants" tell (docs/FRONTEND-PINS.md).  The image
 * RELOADS the 0x0214BAC0 base pool word FOUR separate times -- `ldr r0,[pc,#0xc8]`
 * at 0x020727B8, `ldr r0,[pc,#0xa4]` at 0x020727DC, `ldr r0,[pc,#0x8c]` at
 * 0x020727F4 and `ldr r1,[pc,#0x5c]` at 0x02072824, plus a fifth at 0x02072844
 * and a sixth at 0x02072874 -- all resolving to the single pool word at
 * 0x02072888, which is why the frame is a bare `push {r4, lr}` (`10 40 2d e9`).
 * 1.1p1 -O4,p hoists the base into callee-saved r4 and CSEs the `mov r0, #0`
 * arguments into r5, needing `push {r3, r4, r5, lr}`: the same 212 bytes with
 * 45 concrete bytes out.  Under the pin the same C is 212 bytes, 0 mismatches.
 *
 * One lever needed only under the pin: the index toggle must be written as an
 * explicit if/else pair of stores (`if (idx == 0) idx = 1; else idx = 0;`).
 * The boolean form `idx = (s8)(idx == 0);` schedules the third base reload one
 * instruction late and is 6 bytes out; `volatile` on the struct and on the
 * field alone are both 6 out as well.
 *
 * symbols:
 *   g_0214BAC0     0x0214BAC0  data
 *   g_0214BB00     0x0214BB00  data
 *   SND_RecvCommandReply      0x02089978  arm
 *   SND_IsFinishedCommandTag  0x02089D6C  arm
 *   SND_ReadDriverInfo        0x02089794  arm
 *   SND_GetCurrentCommandTag  0x02089D40  arm
 *   DC_InvalidateRange        0x020862B8  arm
 *   SND_FlushCommand          0x02089B38  arm
 */

#include "../include/G_Ctl.h"

typedef signed char s8;
typedef unsigned char u8;
typedef unsigned int u32;

extern struct Ctl g_0214BAC0;
extern u8 g_0214BB00[];

extern u32  SND_RecvCommandReply(u32 mode);
extern u32  SND_IsFinishedCommandTag(u32 tag);
extern void SND_ReadDriverInfo(void *dst);
extern u32  SND_GetCurrentCommandTag(void);
extern void DC_InvalidateRange(void *p, u32 n);
extern void SND_FlushCommand(u32 flags);

u32 func_020727B4(void)
{
    if (g_0214BAC0.pending == 0) {
        while (SND_RecvCommandReply(0) != 0)
            ;

        if (SND_IsFinishedCommandTag(g_0214BAC0.tag) == 0)
            return 0;

        if (g_0214BAC0.b00 < 0)
            g_0214BAC0.b00 = 1;

        SND_ReadDriverInfo(&g_0214BB00[g_0214BAC0.b00 * 0x11E0]);
        g_0214BAC0.tag = SND_GetCurrentCommandTag();
        if (g_0214BAC0.b00 == 0)
            g_0214BAC0.b00 = 1;
        else
            g_0214BAC0.b00 = 0;
        DC_InvalidateRange(&g_0214BB00[g_0214BAC0.b00 * 0x11E0], 0x11E0);
        SND_FlushCommand(0);
        return 1;
    }

    SND_ReadDriverInfo(&g_0214BB00[0]);
    g_0214BAC0.tag = SND_GetCurrentCommandTag();
    g_0214BAC0.pending = 0;
    return 0;
}
