/*
 * function: DWC_RAP_IsVchatActive
 * address: 0x021563EC
 * packet: pkt_ov009_021563EC
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Unlabelled accessor blocking owned ov099 caller 021BFDA8.
 * symbols:
 *   _pRapWork 0x021A8264 data ov009 a4
 */
extern char *_pRapWork;
int DWC_RAP_IsVchatActive(void) {
 return *(int *)(_pRapWork+0x76c);
}
