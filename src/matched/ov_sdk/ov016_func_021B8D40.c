/*
 * function: APC_SearchStart
 * address:  0x021B8D40
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
 *   apci_bssid_buf        0x021DCFA8  data
 *   apci_essid_buf        0x021DCFB0  data
 *   WCM_Bssid_Any         0x021A1988  data
 *   WCM_Essid_Any         0x021A1990  data
 *   MI_CpuFill8           0x02082BCC  arm
 *   WCM_SearchAsync       0x02165144  arm
 *   APCi_MoveIdleState    0x021B8C94  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(apc.o), symbol APC_SearchStart (name from the vendor object).
 * apc.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B8D40.c \
 *       --func APC_SearchStart --addr 0x021B8D40 --region ov016 --cc ../2.0/sp1p2 --thumb
 */
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

extern APC_BSS apc_bss;
extern unsigned long OS_DisableInterrupts(void);
extern unsigned long OS_RestoreInterrupts(unsigned long state);

extern unsigned char apci_bssid_buf[6];
extern unsigned char apci_essid_buf[32];
extern unsigned char WCM_Bssid_Any[];
extern unsigned char WCM_Essid_Any[];
extern void MI_CpuFill8(void *dstp, unsigned char data, unsigned long size);
extern int WCM_SearchAsync(void *bssid, void *essid, unsigned long option);
extern int APCi_MoveIdleState(void);

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
