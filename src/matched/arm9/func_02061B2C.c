/*
 * function: NNSi_GfdRunVramTransferTask
 * address:  0x02061B2C
 * packet:   pkt_02061B2C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p -proc arm946e
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * symbols:
 *   gNNSiGfdVramLoadFuncTable     0x020A1718  data
 *   DWCi_ScreenDC_FlushRange  0x020862F0  arm
 *
 * Table dispatch: the handler gNNSiGfdVramLoadFuncTable[s[0]] is fetched first, DWCi_ScreenDC_FlushRange
 * gets (s[1], s[3]), then the handler gets (s[1], s[2], s[3]).  The re-read
 * tell (docs/FRONTEND-PINS.md): the image reloads all three fields after the
 * first call with one `ldmib r5, {r0, r1, r2}` at 0x02061B4C; 1.1p1 keeps s[3]
 * live from the first call's argument and emits `ldr r2, [r5, #0xc]` plus a
 * two-register ldmib (52 bytes, 20 out).  Under ../2.0/sp2 the same C is 44
 * bytes, 0 mismatches; EXACT* only because the follower 0x02061B5C
 * (src/matched/NNSi_GfdResetVramTransferTaskQueue.c) has no label.
 */

typedef unsigned int u32;
typedef void (*Fn)(u32, u32, u32);
extern Fn gNNSiGfdVramLoadFuncTable[];
extern void DWCi_ScreenDC_FlushRange(u32, u32);

void NNSi_GfdRunVramTransferTask(u32 *s)
{
    Fn f = gNNSiGfdVramLoadFuncTable[s[0]];
    DWCi_ScreenDC_FlushRange(s[1], s[3]);
    f(s[1], s[2], s[3]);
}
