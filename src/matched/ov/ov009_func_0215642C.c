/*
 * function: DWC_RAP_SetVchatTalkLock
 * address: 0x0215642C
 * packet: pkt_ov009_0215642C
 * region: ov009
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * Retains the live result of DWC_GetMyAID as VCT_MAIN_DisconnectPeers's argument.
 * symbols:
 *   _pRapWork 0x021A8264 data ov009 a4
 *   DWC_GetMyAID 0x0216B838 arm ov009
 *   VCT_MAIN_DisconnectPeers 0x021AF2AC thumb ov013
 *   VCT_MAIN_SetMuted 0x021AF30C thumb ov013
 */
typedef unsigned char u8;
extern u8 *_pRapWork;
extern unsigned char DWC_GetMyAID(void);
extern int VCT_MAIN_DisconnectPeers(int);
extern void VCT_MAIN_SetMuted(int);
void DWC_RAP_SetVchatTalkLock(int flag)
{
    if (flag) {
        VCT_MAIN_DisconnectPeers(DWC_GetMyAID());
        _pRapWork[0x79F] = 1;
    } else {
        _pRapWork[0x79F] = 0;
    }
    VCT_MAIN_SetMuted(_pRapWork[0x79F]);
}
