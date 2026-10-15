/*
 * function: ZUKAN_NICKNAME_TransferPalette
 * address: 0x0220B944
 * packet: pkt_ov207_0220B944
 * region: ov207
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   PALANM_TransferPalettes 0x02021D50 thumb
 */
typedef unsigned int u32;
struct S02021D50;
extern void PALANM_TransferPalettes(struct S02021D50 *p);
void ZUKAN_NICKNAME_TransferPalette(void *a, u32 *p){if(p[22])PALANM_TransferPalettes((void*)p[22]);}
