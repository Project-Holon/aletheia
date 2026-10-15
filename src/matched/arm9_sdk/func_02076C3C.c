/*
 * function: CARDi_IsNormalMode
 * address:  0x02076C3C
 * packet:   pkt_02076C3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      CARDi_IsNormalMode (libcard.TWL.HYB.a card_rom.o)
 *
 * symbols:
 *   CARD_GetOwnRomHeaderTWL  0x02075E04  arm
 *   OS_IsRunOnTwl  0x02085D3C  arm
 *   OS_GetBootType  0x02087B04  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;
typedef int BOOL;

typedef struct CARDRomHeaderTWL
{
    u8 ntr[0x1B4];
    struct
    {
        u32 bit00_04 : 5;
        u32 bit05 : 1;
        u32 bit06_07 : 2;
        u32 bit08 : 1;
        u32 bit09_31 : 23;
    } access_control;
} CARDRomHeaderTWL;

extern CARDRomHeaderTWL *CARD_GetOwnRomHeaderTWL(void);
extern BOOL OS_IsRunOnTwl(void);
extern u16 OS_GetBootType(void);

BOOL CARDi_IsNormalMode(void)
{
    const CARDRomHeaderTWL *oh = CARD_GetOwnRomHeaderTWL();

    return OS_IsRunOnTwl() &&
           (OS_GetBootType() != 1) &&
           oh->access_control.bit05 &&
           !oh->access_control.bit08;
}
