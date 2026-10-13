/*
 * function: DWCi_FNTlDeleteBgLcd
 * address:  0x021D5CA8
 * packet:   pkt_021D5CA8
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_FNTlDeleteBgLcd 0x021D5CA8 arm
 *   DWCi_FNTlDeleteBg  0x021D5C48  arm
 *
 * Tail-call DWCi_FNTlDeleteBg with the argument scaled by 0x30 into the table at 0x021DE680 + 0x610.
 * Addresses are Black-image addresses.
 */

extern void DWCi_FNTlDeleteBg(void *);

void DWCi_FNTlDeleteBgLcd(int a)
{
    DWCi_FNTlDeleteBg((void *)(*(int *)0x021DE680 + 0x610 + a * 0x30));
}
