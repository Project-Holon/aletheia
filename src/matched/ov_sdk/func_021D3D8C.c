/*
 * function: DWCi_MOVStartDownloadandBootChild
 * address:  0x021D3D8C
 * packet:   pkt_021D3D8C
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_MOVStartDownloadandBootChild 0x021D3D8C arm
 *   DWCi_MOV_MBP_StartDownloadAll  0x021D21CC  arm
 *
 * Advance the state byte at +0xa90 from 5 to 6.
 * Addresses are Black-image addresses.
 */

extern void DWCi_MOV_MBP_StartDownloadAll(void);

int DWCi_MOVStartDownloadandBootChild(void)
{
    char *p = *(char **)0x021DE668;

    if (*(unsigned char *)(p + 0xa90) != 5)
        return 0;
    *(unsigned char *)(p + 0xa90) = 6;
    DWCi_MOV_MBP_StartDownloadAll();
    return 1;
}
