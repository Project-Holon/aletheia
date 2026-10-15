/*
 * function: DWCi_Http_SetHostinfo
 * address:  0x0217A1FC
 * packet:   pkt_ov009_0217A1FC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_Http_SetHostinfo (libdwcauth.TWL.HYB.a dwc_http.o)
 *
 * symbols:
 *   strlen  0x0209477C  arm
 *   strncpy  0x02094860  arm
 *   strstr  0x02094B20  arm
 *   atoi  0x020964E0  arm
 *   g_021A2698     0x021A2698  data ov009
 *   g_021A26A0     0x021A26A0  data ov009
 *   g_021A26AC     0x021A26AC  data ov009
 *   g_021A26B0     0x021A26B0  data ov009
 */

typedef struct DWCHttp {
    unsigned char stack[0x1000];
    unsigned char initflag;
    char param[0x1c];
    int error;
    char url[256];
    char *hostname;
    char *filepath;
    unsigned long hostip;
    int ssl_enabled;
    unsigned short port;
} DWCHttp;

typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern u8 *strncpy(u8 *dest, const u8 *src, unsigned int n);
extern char *strstr(const char *s, const char *find);
typedef unsigned int   u32;
extern int atoi(u32 a0);

extern const char g_021A2698[];
extern const char g_021A26A0[];
extern const char g_021A26AC[];
extern const char g_021A26B0[];

int DWCi_Http_SetHostinfo(DWCHttp *http, char *url)
{
    char *temp;
    char *portnum = 0;

    if ((unsigned long)strlen((const u8 *)url) >= 256)
        return 0;
    strncpy((u8 *)http->url, (const u8 *)url, 256);
    if ((unsigned long)strlen((const u8 *)url) != (unsigned long)strlen((const u8 *)http->url))
        return 0;

    if (strstr(http->url, g_021A2698) != 0) {
        http->hostname = &http->url[7];
        http->ssl_enabled = 0;
        http->port = 80;
    } else {
        temp = strstr(http->url, g_021A26A0);
        if (temp == 0)
            return 0;
        http->hostname = temp + 8;
        http->ssl_enabled = 1;
        http->port = 443;
    }

    temp = strstr(http->hostname, g_021A26AC);
    if (temp != 0) {
        *temp = 0;
        portnum = temp + 1;
    }
    temp = strstr(http->hostname, g_021A26B0);
    if (temp != 0) {
        *temp = 0;
        http->filepath = temp + 1;
    } else {
        http->filepath = 0;
    }
    if (portnum != 0)
        http->port = atoi((u32)portnum);
    return 1;
}
