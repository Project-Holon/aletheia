/*
 * function: checkAP
 * address:  0x021B6FA8
 * packet:   pkt_ov016_021B62C0
 * region:   ov016
 * compiler: ../2.0/sp1p2
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   aoss_str_10367  0x021DAB14  data
 *   AOSS_Strlen     0x021B8364  thumb
 *   AOSS_Memcmp     0x021B8210  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol checkAP (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 * aoss_str_10367 is the object's anonymous .data string literal @10367 (11 bytes).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B6FA8.c \
 *       --func checkAP --addr 0x021B6FA8 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct wlla_ssid {
    unsigned long Len;
    unsigned char Ssid[32];
} WLLA_SSID;

typedef struct wlla_rateset {
    unsigned long Num;
    unsigned char Rates[14];
} WLLA_RATESET;

typedef struct wlla_bss_info {
    WLLA_SSID     Ssid;
    unsigned long Channel;
    unsigned long Noise;
    unsigned long Signal;
    unsigned char Bssid[6];
    WLLA_RATESET  SupportRates;
    unsigned long BeaconPeriod;
    unsigned long Capability;
} WLLA_BSS_INFO;

typedef struct wlla_bss_list {
    unsigned long Num;
    WLLA_BSS_INFO BssInfo[1];
} WLLA_BSS_LIST;

extern char aoss_str_10367[];
extern int AOSS_Strlen(char *s);
extern int AOSS_Memcmp(void *s1, void *s2, int n);

int checkAP(WLLA_BSS_LIST *list)
{
    int count, ret, num;
    int find;

    ret = 0;
    find = 0;
    num = list->Num;
    if (num == 0)
        return 5;
    if (list->Num > 64)
        num = 64;
    for (count = 0; count < num; count++) {
        if (list->BssInfo[count].Capability & 1) {
            if (list->BssInfo[count].Ssid.Len == AOSS_Strlen(aoss_str_10367) &&
                AOSS_Memcmp(list->BssInfo[count].Ssid.Ssid, aoss_str_10367, AOSS_Strlen(aoss_str_10367)) == 0)
                find++;
        }
    }
    if (find > 1)
        ret = 4;
    if (find == 0)
        ret = 5;
    return ret;
}
