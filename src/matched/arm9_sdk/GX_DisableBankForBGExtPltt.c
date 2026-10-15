/*
 * function: GX_ResetBankForBGExtPltt
 * address:  0x0208091C
 * packet:   pkt_0208091C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   resetBankForX_ 0x020808BC arm
 *   g_02150E5A 0x02150E5A data
 */

typedef unsigned short u16;
typedef volatile unsigned long vu32;
#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)
extern int resetBankForX_(u16 *g3bit);

void GX_ResetBankForBGExtPltt(void)
{
    reg_GX_DISPCNT &= ~0x40000000;
    resetBankForX_((u16 *)((int)0x2150E5A));
}
