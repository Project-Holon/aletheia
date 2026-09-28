/*
 * function: func_02076E4C
 * address:  0x02076E4C
 * packet:   pkt_02076E4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 * notes:    structure right; image enters the page loop by a branch to the bottom test (no guard), keeps n=512 in a register for the length<n test, and spills retval/cachedPage in the other order
 *
 * sdk:      CARDi_ReadRomWithCPU (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   CARDi_StartRomPageTransfer  0x02076C88  arm
 *   MI_CpuCopy8  0x02082D44  arm
 *   CARDi_ReadRomIDCore  0x02076CD0  arm
 *   CARDi_CheckPulledOutCore  0x02077518  arm
 *   CARDiEnableCacheInvalidationDC  0x020A8498  data
 *   CARDi_cache_buf  0x02150900  data
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef volatile u32 vu32;
typedef int BOOL;

#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)
#define reg_MI_MCD1 (*(vu32 *)0x04100010)

typedef struct CARDiRomCacheState
{
    BOOL enable_dc_invalidation;
    u32 cached_page;
} CARDiRomCacheState;

extern CARDiRomCacheState CARDiEnableCacheInvalidationDC;
extern u8 CARDi_cache_buf[512];

extern void CARDi_StartRomPageTransfer(u32 offset);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern u32 CARDi_ReadRomIDCore(void);
extern void CARDi_CheckPulledOutCore(u32 id);

BOOL func_02076E4C(void *userdata, void *buffer, u32 offset, u32 length)
{
#pragma unused(userdata)
    u32 cachedPage = CARDiEnableCacheInvalidationDC.cached_page;
    BOOL retval = (BOOL)length;

    while (length > 0)
    {
        const u32 pos = offset & ~(512 - 1);
        u8 *ptr = (u8 *)buffer;
        u32 n = 512;

        if (pos == cachedPage)
        {
            ptr = CARDi_cache_buf;
        }
        else
        {
            if ((pos != offset) || (((u32)buffer & 3) != 0) || (length < n))
            {
                ptr = CARDi_cache_buf;
                cachedPage = pos;
            }
            CARDi_StartRomPageTransfer(pos);
            {
                u32 word = 0;
                u32 ctrl;

                do
                {
                    ctrl = reg_MI_MCCNT1;
                    if ((ctrl & 0x00800000) != 0)
                    {
                        u32 data = reg_MI_MCD1;

                        if (word < 512 / sizeof(u32))
                        {
                            ((u32 *)ptr)[word++] = data;
                        }
                    }
                } while ((ctrl & 0x80000000) != 0);
            }
        }
        if (ptr == CARDi_cache_buf)
        {
            u32 mod = offset - pos;

            n = 512 - mod;
            if (n > length)
            {
                n = length;
            }
            MI_CpuCopy8(CARDi_cache_buf + mod, buffer, n);
        }
        buffer = (u8 *)buffer + n;
        offset += n;
        length -= n;
    }
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    CARDiEnableCacheInvalidationDC.cached_page = cachedPage;
    return retval;
}
