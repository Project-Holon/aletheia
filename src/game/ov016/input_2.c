/*
 * file:     input_2.c
 * function: DWCi_IPTlUpdate
 * address:  0x021D656C
 * packet:   pkt_021D656C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_IPTlUpdate   0x021D656C  arm
 *
 * Call func_021D657C, func_021D668C.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_IPTlUpdate.c \
 *       --func DWCi_IPTlUpdate --addr 0x021D656C --region ov016 --cc dsi/1.1p1 --arm
 */

extern void func_021D657C(void);
extern void func_021D668C(void);

void DWCi_IPTlUpdate(void)
{
    func_021D657C();
    func_021D668C();
}
