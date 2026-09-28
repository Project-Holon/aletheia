/*
 * function: func_02076CD0
 * address:  0x02076CD0
 * packet:   pkt_02076CD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_ReadRomIDCore (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   CARDi_IsNormalMode  0x02076C3C  arm
 *   CARDi_SetRomOp  0x02076BBC  arm
 */

typedef unsigned char u8;
typedef unsigned long u32;
typedef volatile u32 vu32;
typedef int BOOL;

#define CARDi_romctrl (*(vu32 *)0x02FFFAE0)
#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)
#define reg_MI_MCD1 (*(vu32 *)0x04100010)

extern BOOL CARDi_IsNormalMode(void);
extern void CARDi_SetRomOp(u32 command, u32 offset);

u32 func_02076CD0(void)
{
    u8 op = 0xB8;

    if (CARDi_IsNormalMode())
    {
        op = 0x90;
    }
    CARDi_SetRomOp(op, 0);
    reg_MI_MCCNT1 = (u32)((CARDi_romctrl & ~0x07000000) | 0xA7000000) & ~0x1FFF;
    while ((reg_MI_MCCNT1 & 0x00800000) == 0)
    {
    }
    return reg_MI_MCD1;
}
