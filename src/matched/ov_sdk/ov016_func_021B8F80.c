/*
 * function: APC_Init
 * address:  0x021B8F80
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
 *   APCi_Notify           0x021B89DC  thumb
 *   WCM_Init              0x02164D64  arm
 *   WCM_StartupAsync      0x02164F98  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(apc.o), symbol APC_Init (name from the vendor object).
 * apc.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (aoss_release.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8F80.c \
 *       --func APC_Init --addr 0x021B8F80 --region ov016 --cc ../2.0/sp1p2 --thumb
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

extern void APCi_Notify(void *arg);
extern int WCM_Init(void *buf, long len);
extern int WCM_StartupAsync(WCMConfig *config, void (*notify)(void *));

int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    apc_bss.apci_Wep = workbuffer;
    apc_bss.apci_WCMConfig = (WCMConfig *)(((unsigned long)workbuffer + 0x50 + 3) & ~3);
    apc_bss.apci_WCMBuffer = (void *)(((unsigned long)((WCMConfig *)apc_bss.apci_WCMConfig) + sizeof(WCMConfig) + 0x1F) & ~0x1F);
    apc_bss.apci_wmbssdesc = (void *)(((unsigned long)apc_bss.apci_WCMBuffer + 0x2300 + 0x1F) & ~0x1F);
    ((WCMConfig *)apc_bss.apci_WCMConfig)->pbdbuffer = (void *)(((unsigned long)apc_bss.apci_wmbssdesc + 0xC0 + 0x1F) & ~0x1F);
    ((WCMConfig *)apc_bss.apci_WCMConfig)->nbdbuffer = ((unsigned long)workbuffer + work_size) - (unsigned long)((WCMConfig *)apc_bss.apci_WCMConfig)->pbdbuffer;
    ((WCMConfig *)apc_bss.apci_WCMConfig)->nbdmode = 0;
    ((WCMConfig *)apc_bss.apci_WCMConfig)->dmano = 3;
    apc_bss.apci_user_callback = user_callback;
    if (apc_bss.apci_state == 0) {
        if (WCM_Init(apc_bss.apci_WCMBuffer, 0x2300) != 0) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        apc_bss.apci_state = 1;
    }
    if (apc_bss.apci_state == 1) {
        if (WCM_StartupAsync(apc_bss.apci_WCMConfig, APCi_Notify) != 3) {
            OS_RestoreInterrupts(enabled);
            return 0;
        }
        apc_bss.apci_state = 4;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}
