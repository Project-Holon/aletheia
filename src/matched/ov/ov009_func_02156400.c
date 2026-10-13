/*
 * function: DWC_RAP_CleanupVchat
 * address: 0x02156400
 * packet: pkt_ov009_02156400
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   _pRapWork 0x021A8264 data ov009 a4
 *   VCT_MAIN_Exit 0x021AF1A0 thumb ov013
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern u8 *_pRapWork;
extern void VCT_MAIN_Exit(void);
void DWC_RAP_CleanupVchat(void)
{
    VCT_MAIN_Exit();
    if (_pRapWork) {
        *(int *)(_pRapWork + 0x76C) = 0;
        *(int *)(_pRapWork + 0x768) = 0;
        *(u16 *)(_pRapWork + 0x794) = 0;
    }
}
