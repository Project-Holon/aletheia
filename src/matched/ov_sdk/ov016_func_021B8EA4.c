/*
 * function: APC_End
 * address:  0x021B8EA4
 * packet:   pkt_ov016_021B89DC
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   apc_bss               0x021DCF80  data
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   WCM_CleanupAsync      0x02165088  arm
 *   APCi_MoveIdleState    0x021B8C94  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(apc.o), symbol APC_End (name from the vendor object).
 * apc.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8EA4.c \
 *       --func APC_End --addr 0x021B8EA4 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

#include "../include/G_APC_BSS.h"

typedef struct {
    long  dmano;
    void *pbdbuffer;
    long  nbdbuffer;
    long  nbdmode;
} WCMConfig;

/*
 * apc.o's .bss statics from 0x021DCF80 (the ten words before apci_bssid_buf): the
 * vendor object addresses them through apci_WCMBuffer's pool word plus an offset, so
 * they are declared as one object in the object's own order; members are the vendor names.
 */
typedef struct {
    void          *apci_WCMBuffer;        /* +0x00 */
    unsigned long  apci_search_option;    /* +0x04 */
    WCMConfig     *apci_WCMConfig;        /* +0x08 */
    unsigned long  apci_connect_option;   /* +0x0C */
    unsigned char *apci_bssid_ptr;        /* +0x10 */
    unsigned char *apci_essid_ptr;        /* +0x14 */
    int            apci_state;            /* +0x18 */
    void         (*apci_user_callback)(int, void *); /* +0x1C */
    void          *apci_wmbssdesc;        /* +0x20 */
    unsigned char *apci_Wep;              /* +0x24 */
} APC_BSS;

extern struct APC_BSS apc_bss;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

extern int WCM_CleanupAsync(void);
extern int APCi_MoveIdleState(void);

int APC_End(void)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    if (apc_bss.apci_state == 3) {
        if (WCM_CleanupAsync() != 3) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        apc_bss.apci_state = 2;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (APCi_MoveIdleState() == 1) {
        apc_bss.apci_state = 2;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}
