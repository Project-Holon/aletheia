/*
 * function: DWC_RAP_CanSendToAllPeers
 * address:  0x0215610C
 * packet:   pkt_ov009_0215610C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009  a4
 *   DWC_GetMyAID  0x0216B838  arm  ov009
 *   DWC_IsValidAID  0x0216B94C  arm  ov009
 *   DWC_IsSendableReliable  0x02176DEC  arm  ov009
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

extern char *g_021A8264;
extern unsigned char DWC_GetMyAID(void);
extern int DWC_IsValidAID(u8);
extern int DWC_IsSendableReliable(int a);

int DWC_RAP_CanSendToAllPeers(void)
{
    int i;
    int found = 0;
    for (i = 0; i < *(int *)(g_021A8264 + 0x764); i++) {
        if (i != DWC_GetMyAID() && DWC_IsValidAID(i)) {
            found = 1;
            if (DWC_IsSendableReliable((u8)i) == 0) {
                return 0;
            }
        }
    }
    return found;
}
