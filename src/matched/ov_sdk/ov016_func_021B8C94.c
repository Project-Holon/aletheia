/*
 * function: APCi_MoveIdleState
 * address:  0x021B8C94
 * packet:   pkt_ov016_021B89DC
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   apc_bss              0x021DCF80  data
 *   APCi_Notify          0x021B89DC  thumb
 *   WCM_SearchAsync      0x02165144  arm
 *   WCM_DisconnectAsync  0x02165478  arm
 *   WCM_StartupAsync     0x02164F98  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(apc.o), symbol APCi_MoveIdleState (name from the vendor object).
 * apc.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8C94.c \
 *       --func APCi_MoveIdleState --addr 0x021B8C94 --region ov016 --cc ../2.0/sp1p2 --thumb
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
extern int WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
extern int WCM_DisconnectAsync(void);
extern int WCM_StartupAsync(WCMConfig *config, void (*notify)(void *));

int APCi_MoveIdleState(void)
{
    switch (apc_bss.apci_state) {
    case 5:
        if (WCM_SearchAsync(0, 0, 0) != 3)
            return 0;
        break;
    case 7:
        if (WCM_DisconnectAsync() != 3)
            return 0;
        break;
    case 1:
        if (WCM_StartupAsync(apc_bss.apci_WCMConfig, APCi_Notify) != 3)
            return 0;
        break;
    case 0:
    case 2:
    case 3:
    case 4:
    case 6:
    case 8:
    default:
        return 0;
    }
    return 1;
}
