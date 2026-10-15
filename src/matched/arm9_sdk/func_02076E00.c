/*
 * function: CARDi_RefreshRomCore
 * address:  0x02076E00
 * packet:   pkt_02076E00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_RefreshRomCore (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   CARDi_SetRomOp  0x02076BBC  arm
 */

typedef unsigned long u32;
typedef volatile u32 vu32;

#define CARDi_romctrl (*(vu32 *)0x02FFFAE0)
#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)

extern void CARDi_SetRomOp(u32 command, u32 offset);

void CARDi_RefreshRomCore(void)
{
    CARDi_SetRomOp(0xB5, 0);
    reg_MI_MCCNT1 = (u32)((CARDi_romctrl & ~0x07000000) | 0xA0000000) & ~0x1FFF;
    while ((reg_MI_MCCNT1 & 0x80000000) != 0)
    {
    }
}
