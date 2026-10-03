/*
 * function: func_02177044
 * address:  0x02177044
 * packet:   pkt_ov009_02177044
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWC_SendUnreliable (libdwcmatch.TWL.HYB.a dwc_transport.o)
 *
 * symbols:
 *   func_02059F38   0x02059F38  arm
 *   DWC_IsValidAID  0x0216B94C  arm  ov009
 *   func_0216B838   0x0216B838  arm  ov009
 *   DWCi_SendUnreliable  0x02177848  arm  ov009
 *   g_021AB180      0x021AB180  data
 */

typedef struct TransInfo {
    unsigned char pad0[0x700];
    void (*f700)(int size, int aid, int param);
    unsigned char pad1[0x710 - 0x704];
    int f710;
} TransInfo;

extern int func_02059F38(void);
extern int DWC_IsValidAID(int aid);
extern unsigned char func_0216B838(void);
extern void DWCi_SendUnreliable(int myaid, int aid, void *buffer, int size, int flag);
extern TransInfo *g_021AB180;

int func_02177044(unsigned char aid, void *buffer, int size)
{
    if (func_02059F38() != 0)
        return 0;
    if (DWC_IsValidAID(aid) == 0)
        return 0;
    if (size > 0x5B6)
        return 0;
    DWCi_SendUnreliable(func_0216B838(), aid, buffer, size, 1);
    if (g_021AB180->f700 != 0)
        g_021AB180->f700(size, aid, g_021AB180->f710);
    return 1;
}
