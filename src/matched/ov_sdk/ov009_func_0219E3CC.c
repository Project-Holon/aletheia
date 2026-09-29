/*
 * function: func_0219E3CC
 * address:  0x0219E3CC
 * packet:   pkt_ov009_0219E3CC
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerParseQR2FullKeysSingle (sb_server.o)
 *
 * symbols:
 *   g_021A8164  0x021A8164  data
 *   func_0219F978  0x0219F978  arm  ov009
 *   func_0219D114  0x0219D114  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   func_02084F40  0x02084F40  arm
 *   func_0209477C  0x0209477C  arm
 *
 * The two-byte nunits copy is memcpy from string.h, which mwccarm inlines as the
 * object's ldrb/strb pair; a prototype in this file would emit a call.
 */

#include "../arm9_sdk/libc/string.h"
typedef struct _SBServer _SBServer;

extern char g_021A8164[];

extern int func_0219F978(char *buf, int len);
extern int func_0219D114(char *keyname);
extern void func_0219E01C(_SBServer *server, char *keyname, char *value);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern unsigned int func_0209477C(const char *s);

void func_0219E3CC(_SBServer *server, char *data, int len)
{
    int dlen;
    char *k;
    char *v;
    char *keys;
    int nkeys;
    unsigned short nunits;
    int pflag;
    int i;
    int j;
    char tempkey[128];

    while (*data) {
        dlen = func_0219F978(data, len);
        if (dlen < 0)
            return;
        k = data;
        data += dlen;
        len -= dlen;
        dlen = func_0219F978(data, len);
        if (dlen < 0)
            return;
        v = data;
        data += dlen;
        len -= dlen;
        if (!func_0219D114(k))
            func_0219E01C(server, k, v);
    }
    data++;
    len--;
    for (pflag = 0; pflag < 2; pflag++) {
        if (len < 2)
            return;
        memcpy(&nunits, data, 2);
        nunits = (unsigned short)(((nunits >> 8) & 0xff) | ((nunits << 8) & 0xff00));
        data += 2;
        len -= 2;
        keys = data;
        nkeys = 0;
        while (*data) {
            dlen = func_0219F978(data, len);
            if (dlen < 0)
                return;
            if (dlen > 100)
                return;
            data += dlen;
            nkeys++;
            len -= dlen;
        }
        data++;
        len--;
        for (i = 0; i < (int)nunits; i++) {
            k = keys;
            for (j = 0; j < nkeys; j++) {
                dlen = func_0219F978(data, len);
                if (dlen < 0)
                    return;
                func_02084F40(tempkey, g_021A8164, k, i);
                func_0219E01C(server, tempkey, data);
                data += dlen;
                len -= dlen;
                k += func_0209477C(k) + 1;
            }
        }
    }
}
