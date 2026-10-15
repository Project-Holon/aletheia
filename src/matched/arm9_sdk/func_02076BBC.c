/*
 * function: CARDi_SetRomOp
 * address:  0x02076BBC
 * packet:   pkt_02076BBC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_SetRomOp (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 */

typedef unsigned short u16;
typedef unsigned long u32;
typedef volatile u16 vu16;
typedef volatile u32 vu32;

#define reg_MI_MCCNT0 (*(vu16 *)0x040001A0)
#define reg_MI_MCCNT1 (*(vu32 *)0x040001A4)
#define reg_MI_MCCMD0 (*(vu32 *)0x040001A8)
#define reg_MI_MCCMD1 (*(vu32 *)0x040001AC)

#define MI_HToBE32(x) ((((x) & 0xFF000000) >> 24) | (((x) & 0x00FF0000) >> 8) | (((x) & 0x0000FF00) << 8) | ((x) << 24))

void CARDi_SetRomOp(u32 command, u32 offset)
{
    u32 cmd1 = (u32)((offset >> 8) | (command << 24));
    u32 cmd2 = (u32)((offset << 24));

    while ((reg_MI_MCCNT1 & 0x80000000) != 0)
    {
    }
    reg_MI_MCCNT0 = (u16)((reg_MI_MCCNT0 & ~0x2000) | 0xC000);
    reg_MI_MCCMD0 = MI_HToBE32(cmd1);
    reg_MI_MCCMD1 = MI_HToBE32(cmd2);
}
