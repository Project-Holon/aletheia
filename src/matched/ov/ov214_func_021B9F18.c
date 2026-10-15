/*
 * function: BTL_REC_SEL_VBlank
 * packet: pkt_ov214_021B9F18
 * address: 0x021B9F18
 * region: ov214
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker-leaf: sole callback blocker of ov214 021B95A0; no existing source/unit/shard, parent ownership cleared.
 * symbols:
 *   BTL_REC_SEL_TransferPalettes 0x021BB0C4 thumb ov214
 */
extern void BTL_REC_SEL_TransferPalettes(char *);
void BTL_REC_SEL_VBlank(void *unused, char *p)
{
    BTL_REC_SEL_TransferPalettes(p);
}
