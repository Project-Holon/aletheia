/*
 * function: CARDi_StartRomPageTransfer
 * address:  0x02076C88
 * packet:   pkt_02076C88
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_StartRomPageTransfer (libcard.TWL.HYB.a card_rom.o)
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

extern BOOL CARDi_IsNormalMode(void);
extern void CARDi_SetRomOp(u32 command, u32 offset);

void CARDi_StartRomPageTransfer(u32 offset)
{
    u8 op = 0xB7;

    if (CARDi_IsNormalMode())
    {
        op = 0x00;
    }
    CARDi_SetRomOp(op, offset);
    reg_MI_MCCNT1 = (CARDi_romctrl & ~0x07000000) | 0xA1000000;
}
