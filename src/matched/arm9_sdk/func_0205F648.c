/*
 * function: NCFGi_InitBackupMemory
 * address:  0x0205F648
 * packet:   pkt_0205F648
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      NCFGi_InitBackupMemory (libncfg.TWL.HYB.a backup.o)
 *
 * symbols:
 *   NVRAMi_Init         0x02083644 arm
 *   DC_InvalidateRange  0x020862B8 arm
 *   ReadNVRAM           0x0205F970 arm
 *   BaseAddress         0x020A813C data a4
 *   FormatVersionNumber 0x02146B00 data a1
 *   nvramBuf            0x02146B20 data a16
 *   nvramBuf2           0x02146B40 data a16
 */

#include "../include/G_NCFGBackupBss.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed long    s32;

extern void NVRAMi_Init(void);
extern void DC_InvalidateRange(void *startAddr, u32 nBytes);
extern int  ReadNVRAM(u32 address, u32 size, void *pData);

extern u32 BaseAddress;
/* backup.o's .bss statics from FormatVersionNumber on, in their laid-out order: the object
 * reads nvramBuf[0] and nvramBuf2[0] off the .bss base (FormatVersionNumber) while the
 * calls take each buffer's own literal */
typedef struct {
    u8  FormatVersionNumber;
    u8  pad[31];
    u8  nvramBuf[32];
    u16 nvramBuf2[16];
} NCFGBackupBss;

extern struct NCFGBackupBss FormatVersionNumber;
extern u8 nvramBuf[32];
extern u8 nvramBuf2[32];

s32 NCFGi_InitBackupMemory(void)
{
    s32 result;

    if (BaseAddress != (u32)-1)
        return 0;
    NVRAMi_Init();
    result = 0;
    DC_InvalidateRange(nvramBuf, sizeof(nvramBuf));
    if (ReadNVRAM(0x1FE, sizeof(nvramBuf), nvramBuf) == 0) {
        FormatVersionNumber.FormatVersionNumber = FormatVersionNumber.nvramBuf[0];
    } else {
        result = -1;
        goto end;
    }
    DC_InvalidateRange(nvramBuf2, sizeof(nvramBuf2));
    if (ReadNVRAM(0x20, sizeof(nvramBuf2), nvramBuf2) == 0)
        BaseAddress = (FormatVersionNumber.nvramBuf2[0] << 3) - 0x400;
    else
        result = -1;
end:
    return result;
}
