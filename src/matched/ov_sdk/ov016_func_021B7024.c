/*
 * function: AOSS_set_APInfo
 * address:  0x021B7024
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
 *   aoss_str_10375  0x021DAB20  data
 *   AOSS_Strlen     0x021B8364  thumb
 *   AOSS_Memcpy     0x021B8230  thumb
 *
 * SDK: TwlDWC libdwcutil.TWL.HYB.a(aoss.o), symbol AOSS_set_APInfo (name from the vendor object).
 * aoss.o was built by Metrowerks C/C++ for ARM 3.0.0.126 (its .comment), which is
 * the 2.0/sp1p2 front end; see aoss_release (ov016_func_021B6CF0.c) for the byte tell.
 * aoss_str_10367 and aoss_str_10375 are the object's anonymous .data string
 * literals @10367 (11 bytes) and @10375 (6 bytes).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ov016_func_021B7024.c \
 *       --func AOSS_set_APInfo --addr 0x021B7024 --region ov016 --cc ../2.0/sp1p2 --thumb
 */

typedef struct wlla_ssid {
    unsigned long Len;
    unsigned char Ssid[32];
} WLLA_SSID;

typedef struct wlla_key {
    unsigned long Len;
    unsigned char Key[13];
} WLLA_KEY;

typedef struct wlla_connect_param {
    WLLA_SSID     Ssid;
    unsigned long AuthAlgo;
    WLLA_KEY      Key;
} WLLA_CONNECT_PARAM;

extern char aoss_str_10367[];
extern char aoss_str_10375[];
extern int AOSS_Strlen(char *s);
extern void *AOSS_Memcpy(void *dest, void *src, int n);

int AOSS_set_APInfo(WLLA_CONNECT_PARAM *ap)
{
    ap->Ssid.Len = AOSS_Strlen(aoss_str_10367);
    AOSS_Memcpy(ap->Ssid.Ssid, aoss_str_10367, ap->Ssid.Len);
    ap->AuthAlgo = 1;
    ap->Key.Len = AOSS_Strlen(aoss_str_10375);
    if (ap->Key.Len > 13)
        return -1;
    AOSS_Memcpy(ap->Key.Key, aoss_str_10375, ap->Key.Len);
    return 0;
}
