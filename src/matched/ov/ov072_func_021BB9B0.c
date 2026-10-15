/*
 * function: TOWNMAP_GRH_TransferBgData
 * address:  0x021BB9B0
 * packet:   pkt_021BB9B0
 * region:   ov072
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BG_SYS_Update  0x020419E4  arm
 */

void BG_SYS_Update(void);

void TOWNMAP_GRH_TransferBgData(void *a0)
{
    BG_SYS_Update();
}
