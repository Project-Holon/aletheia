/*
 * function: CARDi_ReadRomStatusCore
 * address:  0x02076D38
 * packet:   pkt_02076D38
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_ReadRomStatusCore (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   CARDi_SetRomOp  0x02076BBC  arm
 */

typedef unsigned long u32;
typedef volatile u32 vu32;

#define CARDi_romctrl (*(vu32 *)0x02FFFAE0)
#define CARDi_romid (*(vu32 *)0x02FFFC00)
#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)
#define reg_MI_MCD1 (*(vu32 *)0x04100010)

extern void CARDi_SetRomOp(u32 command, u32 offset);

u32 CARDi_ReadRomStatusCore(void)
{
    if ((CARDi_romid & 0x20000000) == 0)
    {
        return 0x20;
    }
    CARDi_SetRomOp(0xD6, 0);
    reg_MI_MCCNT1 = (u32)((CARDi_romctrl & ~0x07000000) | 0xA7000000) & ~0x1FFF;
    while ((reg_MI_MCCNT1 & 0x00800000) == 0)
    {
    }
    return reg_MI_MCD1;
}
