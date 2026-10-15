/*
 * function: GX_ResetBankForSubOBJExtPltt
 * address:  0x020809F0
 * packet:   pkt_020809F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   resetBankForX_ 0x020808BC arm
 *   g_02150E64 0x02150E64 data
 */

typedef unsigned short u16;
typedef volatile unsigned long vu32;
#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)
extern int resetBankForX_(u16 *g3bit);

void GX_ResetBankForSubOBJExtPltt(void)
{
    reg_GXS_DB_DISPCNT &= ~0x80000000;
    resetBankForX_((u16 *)((int)0x2150E64));
}
