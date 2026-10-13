/*
 * function: GX_ResetBankForSubBGExtPltt
 * address:  0x020809C8
 * packet:   pkt_020809C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020808BC 0x020808BC arm
 *   g_02150E62 0x02150E62 data
 */

typedef unsigned short u16;
typedef volatile unsigned long vu32;
#define reg_GX_DISPCNT     (*(vu32 *)0x04000000)
#define reg_GXS_DB_DISPCNT (*(vu32 *)0x04001000)
extern int func_020808BC(u16 *g3bit);

void GX_ResetBankForSubBGExtPltt(void)
{
    reg_GXS_DB_DISPCNT &= ~0x40000000;
    func_020808BC((u16 *)((int)0x2150E62));
}
