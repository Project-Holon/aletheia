/*
 * file:     apc.c
 * unit:     yes
 * function: APCi_Notify, APCi_MoveIdleState, APC_GetAPList, APC_SearchStart, APC_SearchEnd, APC_Disconnect, APC_End, APC_Connect, APC_Init
 * address:  0x021B89DC
 * region:   ov016
 * compiler: dsi/../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   apc_bss           0x021DCF80  data
 *   WCM_SearchAsync   0x02165144  arm
 *   WCM_ConnectAsync  0x021652A4  arm
 *   WCM_CleanupAsync  0x02165088  arm
 *   WCM_Finish        0x02164EE0  arm
 *   WCM_DisconnectAsync  0x02165478  arm
 *   WCM_StartupAsync     0x02164F98  arm
 *   WCM_LockApList   0x02165C28  arm
 *   WCM_CountApList  0x02165BD0  arm
 *   WCM_PointApList  0x02165CA0  arm
 *   MIi_CpuCopy32    0x02082A90  arm
 *   OS_DisableInterrupts  0x02087988  arm
 *   OS_RestoreInterrupts  0x0208799C  arm
 *   apci_bssid_buf        0x021DCFA8  data
 *   apci_essid_buf        0x021DCFB0  data
 *   WCM_Bssid_Any         0x021A1988  data
 *   WCM_Essid_Any         0x021A1990  data
 *   MI_CpuFill8           0x02082BCC  arm
 *   MI_CpuCopy8           0x02082D44  arm
 *   WCM_Init              0x02164D64  arm
 */
#include "../../matched/include/G_APC_BSS.h"

/*
 * apc.o's .bss statics from 0x021DCF80 (the ten words before apci_bssid_buf): the
 * vendor object addresses them through apci_WCMBuffer's pool word plus an offset, so
 * they are declared as one object in the object's own order; members are the vendor names.
 */
#include "../sdk_wm.h"

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

struct wlla_ssid {
    unsigned long Len;
    unsigned char Ssid[32];
};

struct wlla_rateset {
    unsigned long Count;
    unsigned char Rate[16];
};

struct wlla_bss_info {
    struct wlla_ssid    Ssid;
    unsigned long       Channel;
    unsigned long       Noise;
    unsigned long       Signal;
    unsigned char       Bssid[6];
    struct wlla_rateset SupportRates;
    unsigned long       BeaconPeriod;
    unsigned long       Capability;
};

#include "../sdk_wm.h"

extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);
extern int WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
extern int WCM_ConnectAsync(void *bssDesc, void *wepDesc, unsigned long option);
extern int WCM_CleanupAsync(void);
extern long WCM_Finish(void);
extern int WCM_DisconnectAsync(void);
extern int WCM_StartupAsync(void *config, void (*notify)(struct WCMNotice *));
extern int WCM_LockApList(int lock);
extern int WCM_CountApList(void);
extern struct WMBssDesc *WCM_PointApList(unsigned short index);
extern void MIi_CpuCopy32(void *srcp, void *destp, unsigned long size);
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
int APC_GetAPList(struct WMBssDesc *WMBssdescBuf, int list_max);
int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option);
extern void MI_CpuCopy8(void *srcp, void *dstp, unsigned long size);
extern int WCM_Init(void *buf, long len);
int APC_Connect(struct WMBssDesc *wmbssdesc, unsigned char *wep_buf, unsigned long option);
int APC_Init(void (*user_callback)(int, void *), void *workbuffer, int work_size);
int APC_SearchEnd(void);
int APC_Disconnect(void);
int APC_End(void);
void APCi_Notify(WCMNotice *notice);
int APCi_MoveIdleState(void);
extern struct APC_BSS apc_bss;
extern unsigned char apci_bssid_buf[6];
extern unsigned char apci_essid_buf[32];
extern unsigned char WCM_Bssid_Any[];
extern unsigned char WCM_Essid_Any[];


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


int APC_GetAPList(struct WMBssDesc *WMBssdescBuf, int list_max)
{
    int ap_count;
    int ap_index;
    struct WMBssDesc *wmbssdesc;
    struct WMBssDesc *dest;

    WCM_LockApList(1);
    ap_count = WCM_CountApList();
    if (ap_count > 0) {
        for (ap_index = 0; ap_index < ap_count; ap_index++) {
            if (ap_index >= list_max)
                break;
            wmbssdesc = WCM_PointApList(ap_index);
            dest = &WMBssdescBuf[ap_index];
            MIi_CpuCopy32(wmbssdesc, dest, sizeof(struct WMBssDesc));
        }
    }
    WCM_LockApList(0);
    return ap_count;
}


int APC_SearchStart(unsigned char *bssid, unsigned char *essid, int essid_len, unsigned long option)
{
    unsigned long enabled;
    int i;

    enabled = OS_DisableInterrupts();
    apc_bss.apci_search_option = option;
    if (bssid != 0) {
        for (i = 0; i < 6; i++)
            apci_bssid_buf[i] = *bssid++;
        apc_bss.apci_bssid_ptr = apci_bssid_buf;
    } else {
        MI_CpuFill8(apci_bssid_buf, 0xFF, 6);
        apc_bss.apci_bssid_ptr = WCM_Bssid_Any;
    }
    if (essid != 0 && essid_len > 0 && essid_len <= 32) {
        for (i = 0; i < essid_len; i++)
            apci_essid_buf[i] = *essid++;
        for (; i < 32; i++)
            apci_essid_buf[i] = 0;
        apc_bss.apci_essid_ptr = apci_essid_buf;
    } else {
        MI_CpuFill8(apci_essid_buf, 0xFF, 32);
        apc_bss.apci_essid_ptr = WCM_Essid_Any;
    }
    if (apc_bss.apci_state == 3) {
        if (WCM_SearchAsync(apc_bss.apci_bssid_ptr, apc_bss.apci_essid_ptr, apc_bss.apci_search_option) == 3) {
            apc_bss.apci_state = 6;
            OS_RestoreInterrupts(enabled);
            return 1;
        }
    } else if (APCi_MoveIdleState() == 1) {
        apc_bss.apci_state = 6;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}


int APC_SearchEnd(void)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    if (apc_bss.apci_state == 5 && WCM_SearchAsync(0, 0, 0) == 3) {
        apc_bss.apci_state = 4;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}


int APC_Disconnect(void)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    if (apc_bss.apci_state == 7 && WCM_DisconnectAsync() == 3) {
        apc_bss.apci_state = 4;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}


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


int APC_Connect(struct WMBssDesc *wmbssdesc, unsigned char *wep_buf, unsigned long option)
{
    unsigned long enabled;

    enabled = OS_DisableInterrupts();
    apc_bss.apci_connect_option = option;
    if (wep_buf != 0)
        MI_CpuCopy8(wep_buf, apc_bss.apci_Wep, 0x50);
    else
        MI_CpuFill8(apc_bss.apci_Wep, 0, 0x50);
    MIi_CpuCopy32(wmbssdesc, apc_bss.apci_wmbssdesc, sizeof(struct WMBssDesc));
    if (APCi_MoveIdleState() == 1) {
        apc_bss.apci_state = 8;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    if (apc_bss.apci_state == 3 &&
        WCM_ConnectAsync(apc_bss.apci_wmbssdesc, apc_bss.apci_Wep, apc_bss.apci_connect_option) == 3) {
        apc_bss.apci_state = 8;
        OS_RestoreInterrupts(enabled);
        return 1;
    }
    OS_RestoreInterrupts(enabled);
    return 0;
}


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
