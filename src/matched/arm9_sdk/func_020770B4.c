/*
 * function: func_020770B4
 * address:  0x020770B4
 * packet:   pkt_020770B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_IsRomDmaAvailable (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   OS_GetDTCMAddress  0x02086CE0  arm
 */

typedef unsigned long u32;
typedef int BOOL;

extern void *OS_GetDTCMAddress(void);

static inline BOOL CARDi_IsNotITCM(const void *dst, u32 len)
{
    return ((u32)dst + len <= 0x01FF8000) || ((u32)dst >= 0x02000000);
}

static inline BOOL CARDi_IsNotDTCM(const void *dst, u32 len)
{
    return ((u32)dst + len <= (u32)OS_GetDTCMAddress()) || ((u32)dst >= (u32)OS_GetDTCMAddress() + 0x4000);
}

static inline BOOL CARDi_IsDmaTarget(u32 dma, const void *dst, u32 len)
{
    return (dma <= 3) && (len > 0) && (((u32)dst & 31) == 0) && CARDi_IsNotITCM(dst, len);
}

static inline BOOL CARDi_IsDmaDestination(u32 dma, const void *dst, u32 len)
{
    return CARDi_IsDmaTarget(dma, dst, len) && CARDi_IsNotDTCM(dst, len);
}

BOOL func_020770B4(u32 dma, void *dst, u32 src, u32 len)
{
    return CARDi_IsDmaDestination(dma, dst, len) && (((src | len) & 0x1FF) == 0);
}
