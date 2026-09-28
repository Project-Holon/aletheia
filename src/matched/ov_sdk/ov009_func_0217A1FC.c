/*
 * function: func_0217A1FC
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
 *   func_0209477C  0x0209477C  arm
 *   func_02094860  0x02094860  arm
 *   func_02094B20  0x02094B20  arm
 *   func_020964E0  0x020964E0  arm
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

extern unsigned long func_0209477C(const char *s);
extern char *func_02094860(char *dst, const char *src, unsigned long n);
extern char *func_02094B20(const char *s, const char *find);
extern int func_020964E0(const char *s);

extern const char g_021A2698[];
extern const char g_021A26A0[];
extern const char g_021A26AC[];
extern const char g_021A26B0[];

int func_0217A1FC(DWCHttp *http, char *url)
{
    char *temp;
    char *portnum = 0;

    if (func_0209477C(url) >= 256)
        return 0;
    func_02094860(http->url, url, 256);
    if (func_0209477C(url) != func_0209477C(http->url))
        return 0;

    if (func_02094B20(http->url, g_021A2698) != 0) {
        http->hostname = &http->url[7];
        http->ssl_enabled = 0;
        http->port = 80;
    } else {
        temp = func_02094B20(http->url, g_021A26A0);
        if (temp == 0)
            return 0;
        http->hostname = temp + 8;
        http->ssl_enabled = 1;
        http->port = 443;
    }

    temp = func_02094B20(http->hostname, g_021A26AC);
    if (temp != 0) {
        *temp = 0;
        portnum = temp + 1;
    }
    temp = func_02094B20(http->hostname, g_021A26B0);
    if (temp != 0) {
        *temp = 0;
        http->filepath = temp + 1;
    } else {
        http->filepath = 0;
    }
    if (portnum != 0)
        http->port = func_020964E0(portnum);
    return 1;
}
