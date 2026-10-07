/*
 * function: APCi_Notify
 * address:  0x021B89DC
 * packet:   pkt_ov016_021B89DC
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   apc_bss           0x021DCF80  data
 *   WCM_SearchAsync   0x02165144  arm
 *   WCM_ConnectAsync  0x021652A4  arm
 *   WCM_CleanupAsync  0x02165088  arm
 *   WCM_Finish        0x02164EE0  arm
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(apc.o), symbol APCi_Notify (name from the vendor object).
 * apc.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B89DC.c \
 *       --func APCi_Notify --addr 0x021B89DC --region ov016 --cc ../2.0/sp1p2 --thumb
 */

#include "../../../matched/include/G_APC_BSS.h"

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

typedef union {
    void *p;
} WCMNoticeParameter;

typedef struct WCMNotice {
    short              notify;
    short              result;
    WCMNoticeParameter parameter[3];
} WCMNotice;

extern long WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
extern long WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option);
extern long WCM_CleanupAsync(void);
extern long WCM_Finish(void);

#define APCI_CALLBACK(event)                                  \
    if (apc_bss.apci_user_callback != 0)                      \
        apc_bss.apci_user_callback((event), 0)

void APCi_Notify(WCMNotice *notice)
{
    if (notice == 0)
        return;
    switch (notice->notify) {
    case 1:
        if (notice->result == 0) {
            if (apc_bss.apci_state == 4) {
                apc_bss.apci_state = 3;
                APCI_CALLBACK(6);
            } else if (apc_bss.apci_state == 6) {
                if (WCM_SearchAsync(apc_bss.apci_bssid_ptr, apc_bss.apci_essid_ptr, apc_bss.apci_search_option) != 3) {
                    apc_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (apc_bss.apci_state == 8) {
                if (WCM_ConnectAsync(apc_bss.apci_wmbssdesc, apc_bss.apci_Wep, apc_bss.apci_connect_option) != 3) {
                    apc_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            }
        } else {
            apc_bss.apci_state = 1;
            APCI_CALLBACK(2);
        }
        break;
    case 3:
        if (notice->result == 0) {
            if (apc_bss.apci_state == 6) {
                apc_bss.apci_state = 5;
                APCI_CALLBACK(8);
            }
        } else {
            apc_bss.apci_state = 3;
            APCI_CALLBACK(9);
        }
        break;
    case 5:
        if (notice->result == 0) {
            if (apc_bss.apci_state == 8) {
                apc_bss.apci_state = 7;
                APCI_CALLBACK(12);
            }
        } else {
            apc_bss.apci_state = 3;
            APCI_CALLBACK(13);
        }
        break;
    case 4:
        if (notice->result == 0) {
            if (apc_bss.apci_state == 4) {
                apc_bss.apci_state = 3;
                APCI_CALLBACK(10);
            } else if (apc_bss.apci_state == 6) {
                if (WCM_SearchAsync(apc_bss.apci_bssid_ptr, apc_bss.apci_essid_ptr, apc_bss.apci_search_option) != 3) {
                    apc_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (apc_bss.apci_state == 2) {
                if (WCM_CleanupAsync() != 3) {
                    apc_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (apc_bss.apci_state == 8) {
                if (WCM_ConnectAsync(apc_bss.apci_wmbssdesc, apc_bss.apci_Wep, apc_bss.apci_connect_option) != 3) {
                    apc_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            }
        } else {
            apc_bss.apci_state = 3;
            APCI_CALLBACK(11);
        }
        break;
    case 6:
        if (notice->result == 0) {
            if (apc_bss.apci_state == 4) {
                apc_bss.apci_state = 3;
                APCI_CALLBACK(14);
            } else if (apc_bss.apci_state == 6) {
                if (WCM_SearchAsync(apc_bss.apci_bssid_ptr, apc_bss.apci_essid_ptr, apc_bss.apci_search_option) != 3) {
                    apc_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (apc_bss.apci_state == 2) {
                if (WCM_CleanupAsync() != 3) {
                    apc_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else if (apc_bss.apci_state == 8) {
                if (WCM_ConnectAsync(apc_bss.apci_wmbssdesc, apc_bss.apci_Wep, apc_bss.apci_connect_option) != 3) {
                    apc_bss.apci_state = 3;
                    APCI_CALLBACK(2);
                }
            } else {
                apc_bss.apci_state = 3;
            }
        } else {
            apc_bss.apci_state = 3;
            APCI_CALLBACK(15);
        }
        break;
    case 2:
        if (notice->result == 0) {
            if (apc_bss.apci_state == 2) {
                WCM_Finish();
                apc_bss.apci_state = 0;
                APCI_CALLBACK(20);
            }
        } else {
            apc_bss.apci_state = 3;
            APCI_CALLBACK(2);
        }
        break;
    case 7:
        if (apc_bss.apci_state == 5) {
            APCI_CALLBACK(5);
        }
        break;
    case 0:
    default:
        APCI_CALLBACK(1);
        break;
    }
}
