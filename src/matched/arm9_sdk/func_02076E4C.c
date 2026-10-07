/*
 * function: func_02076E4C
 * address:  0x02076E4C
 * packet:   pkt_02076E4C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * notes:    CARDi_cache_buf is a 512-byte static in card_rom.o .bss with sh_addralign 32;
 *            declaring that alignment keeps n as a real copy at the compare.
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

#include "../include/G_CARDiRomCacheState.h"

typedef unsigned char u8;
typedef unsigned long u32;
typedef volatile u32 vu32;
typedef int BOOL;

#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)
#define reg_MI_MCD1 (*(vu32 *)0x04100010)

typedef struct CARDiRomCacheState CARDiRomCacheState;

extern struct CARDiRomCacheState CARDiEnableCacheInvalidationDC;
extern u8 CARDi_cache_buf[512] __attribute__((aligned(32)));

extern void CARDi_StartRomPageTransfer(u32 offset);
extern void MI_CpuCopy8(const void *srcp, void *dstp, u32 size);
extern u32 CARDi_ReadRomIDCore(void);
extern void CARDi_CheckPulledOutCore(u32 id);

#define CARD_ROM_PAGE_SIZE 512
#define MATH_ROUNDDOWN(x, align) ((x) & ~((align) - 1))
#define MATH_MIN(a, b) (((a) <= (b)) ? (a) : (b))
#define REG_MI_MCCNT1_RDY_MASK 0x00800000
#define REG_MI_MCCNT1_START_MASK 0x80000000

BOOL func_02076E4C(void *userdata, void *buffer, u32 offset, u32 length)
{
    BOOL retval = (BOOL)length;
    u32 cachedPage = CARDiEnableCacheInvalidationDC.cached_page;
    u8 *const cacheBuffer = CARDi_cache_buf;
    while (length > 0)
    {
        u8 *ptr = (u8 *)buffer;
        u32 n = CARD_ROM_PAGE_SIZE;
        u32 pos = MATH_ROUNDDOWN(offset, CARD_ROM_PAGE_SIZE);
        if (pos == cachedPage)
        {
            ptr = cacheBuffer;
        }
        else
        {
            if ((pos != offset) || (((u32)buffer & 3) != 0) || (length < n))
            {
                ptr = cacheBuffer;
                cachedPage = pos;
            }
            CARDi_StartRomPageTransfer(pos);
            {
                u32 word = 0;
                for (;;)
                {
                    u32 ctrl = reg_MI_MCCNT1;
                    if ((ctrl & REG_MI_MCCNT1_RDY_MASK) != 0)
                    {
                        u32 data = reg_MI_MCD1;
                        if (word < CARD_ROM_PAGE_SIZE / sizeof(u32))
                        {
                            ((u32 *)ptr)[word++] = data;
                        }
                    }
                    if ((ctrl & REG_MI_MCCNT1_START_MASK) == 0)
                    {
                        break;
                    }
                }
            }
        }
        if (ptr == cacheBuffer)
        {
            u32 mod = offset - pos;
            n = MATH_MIN(length, CARD_ROM_PAGE_SIZE - mod);
            MI_CpuCopy8(cacheBuffer + mod, buffer, n);
        }
        buffer = (u8 *)buffer + n;
        offset += n;
        length -= n;
    }
    
    CARDi_CheckPulledOutCore(CARDi_ReadRomIDCore());
    CARDiEnableCacheInvalidationDC.cached_page = cachedPage;
    return retval;
}
