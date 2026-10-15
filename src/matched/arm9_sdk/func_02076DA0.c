/*
 * function: CARDi_RefreshRom
 * address:  0x02076DA0
 * packet:   pkt_02076DA0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_RefreshRom (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   CARDi_ReadRomStatusCore  0x02076D38  arm
 *   CARDi_RefreshRomCore  0x02076E00  arm
 *   OS_IsAlarmAvailable  0x02087244  arm
 *   OS_Sleep  0x02085A38  arm
 *   OSi_IsThreadInitialized  0x02150FDC  data
 */

typedef unsigned long u32;
typedef int BOOL;

extern BOOL OSi_IsThreadInitialized;
extern u32 CARDi_ReadRomStatusCore(void);
extern void CARDi_RefreshRomCore(void);
extern BOOL OS_IsAlarmAvailable(void);
extern void OS_Sleep(u32 msec);

void CARDi_RefreshRom(u32 warn_mask)
{
    if ((CARDi_ReadRomStatusCore() & warn_mask) != 0)
    {
        CARDi_RefreshRomCore();
        while ((CARDi_ReadRomStatusCore() & 0x20) == 0)
        {
            if (OSi_IsThreadInitialized && OS_IsAlarmAvailable())
            {
                OS_Sleep(1);
            }
        }
    }
}
