/*
 * function: SCREENTEX_CaptureDisplay
 * address:  0x0202E610
 * packet:   pkt_0202E560
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * PARKED AT MATCH.  Every concrete byte is right; the three open sites are
 * the pool words for the 0x020A02D0 table (at +0, +4 and +8), and the only
 * words in the image that hold 0x020A02D0 are this function's own pool at
 * 0x0202E674..0x0202E684, inside the compared range, so `literal` has no
 * outside witness.  It closes the day another function elsewhere in the
 * image loads the same table, or when a shard entry covers one.
 *   blocker: ABS32 0x020A02D0 x3 - no witness outside this range
 *
 * symbols:
 *   SCREENTEX_CaptureBanks      0x020A02D0  data
 *   GX_GetBankForTex   0x02080C44  arm
 *   GX_SetBankForLCDC  0x0208068C  arm
 *   GX_SetBankForTex   0x02080294  arm
 *   MIi_CpuCopyFast    0x02082B0C  arm
 *   OS_WaitVBlankIntr   0x02087AE4  arm
 *   GX_DisableBankForLCDC   0x02080B98  arm
 *   GX_ResetBankForTex   0x02080964  arm
 *
 * Bank 0x80300010 is selected for the 12-byte record a0 in 0x020A02D0, its
 * texture slot is remapped to a1's, and a0's frame buffer (0xC000 words per
 * bank, hence the `0xc << 13`) is copied into a1's.  The hardware word at
 * 0x04000064 is a cast constant, not a relocation.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/SCREENTEX_CaptureDisplay.c \
 *       --func SCREENTEX_CaptureDisplay --addr 0x0202E610 --cc 1.1p1 --thumb
 */

typedef unsigned int u32;

struct Bank {
    u32 f0;
    u32 f4;
    u32 f8;
};

extern struct Bank SCREENTEX_CaptureBanks[];

extern u32  GX_GetBankForTex(void);
extern void GX_SetBankForLCDC(u32 a);
extern void GX_SetBankForTex(u32 a);
extern void MIi_CpuCopyFast(u32 src, u32 dst, u32 size);
extern void OS_WaitVBlankIntr(void);
extern void GX_DisableBankForLCDC(void);
extern int GX_ResetBankForTex(void);

void SCREENTEX_CaptureDisplay(u32 a0, u32 a1)
{
    u32 prev = GX_GetBankForTex();
    u32 st;

    GX_SetBankForLCDC(SCREENTEX_CaptureBanks[a0].f0);
    *(u32 *)0x04000064 = (SCREENTEX_CaptureBanks[a0].f4 << 16) | 0x80300010;

    OS_WaitVBlankIntr();
    OS_WaitVBlankIntr();
    GX_DisableBankForLCDC();
    GX_SetBankForTex(prev);

    if (a0 != a1) {
        st = GX_ResetBankForTex();
        MIi_CpuCopyFast(SCREENTEX_CaptureBanks[a0].f8, SCREENTEX_CaptureBanks[a1].f8, 0xC << 13);
        GX_DisableBankForLCDC();
        GX_SetBankForTex(st);
    }
}
