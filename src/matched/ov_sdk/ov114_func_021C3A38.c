/*
 * function: func_021C3A38
 * address:  0x021C3A38
 * packet:   pkt_ov114_021C3A38
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiParseURL (libdwcgsghttp.TWL.HYB.a ghttpprocess.o)
 *
 * symbols:
 *   func_020949F4  0x020949F4  arm
 *   func_02094A60  0x02094A60  arm
 *   func_02094A28  0x02094A28  arm
 *   func_020964E0  0x020964E0  arm
 *   func_0217F1E0  0x0217F1E0  arm   ov009
 *   g_021CEFDC     0x021CEFDC  data
 *   g_021CEFE4     0x021CEFE4  data
 *   g_021CEFF0     0x021CEFF0  data
 *   g_021CEFF4     0x021CEFF4  data
 */

typedef struct GHIConnection {
    unsigned char pad0[0x14];
    char *url;
    char *server;
    unsigned char pad1[4];
    unsigned short port;
    unsigned char pad2[2];
    char *path;
    int ssl;
} GHIConnection;

extern int func_020949F4(const char *, const char *, unsigned int);
typedef unsigned char  u8;
extern int func_02094A60(const u8 *s, const u8 *reject);
extern char *func_02094A28(const char *, int);
typedef unsigned int   u32;
extern int func_020964E0(u32 a0);
extern char *func_0217F1E0(char *);
extern char g_021CEFDC[];
extern char g_021CEFE4[];
extern char g_021CEFF0[];
extern char g_021CEFF4[];

typedef enum { GHI_FALSE, GHI_TRUE } GHIBool;

GHIBool func_021C3A38(GHIConnection *connection)
{
    char *URL;
    int nIndex;
    char tempChar;
    char *p;
    char *path;

    if (connection == 0)
        return GHI_FALSE;
    URL = connection->url;
    if (URL == 0)
        return GHI_FALSE;
    if (func_020949F4(URL, g_021CEFDC, 7) == 0) {
        connection->ssl = 0;
        URL += 7;
    } else if (func_020949F4(URL, g_021CEFE4, 8) == 0) {
        connection->ssl = 1;
        URL += 8;
    } else {
        return GHI_FALSE;
    }
    nIndex = func_02094A60((const u8 *)URL, (const u8 *)g_021CEFF0);
    tempChar = URL[nIndex];
    URL[nIndex] = 0;
    connection->server = func_0217F1E0(URL);
    if (connection->server == 0)
        return GHI_FALSE;
    URL[nIndex] = tempChar;
    URL += nIndex;
    if (*URL == ':') {
        URL++;
        connection->port = (unsigned short)func_020964E0((u32)URL);
        if (connection->port == 0)
            return GHI_FALSE;
        while (*++URL != 0 && *URL != '/')
            ;
    } else if (connection->ssl == 1) {
        connection->port = 443;
    } else {
        connection->port = 80;
    }
    if (*URL == 0)
        URL = g_021CEFF4;
    path = func_0217F1E0(URL);
    connection->path = path;
    while ((p = func_02094A28(path, ' ')) != 0) {
        *p = '+';
        path = connection->path;
    }
    if (path == 0)
        return GHI_FALSE;
    return GHI_TRUE;
}
