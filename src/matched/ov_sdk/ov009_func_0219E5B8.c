/*
 * function: func_0219E5B8
 * address:  0x0219E5B8
 * packet:   pkt_ov009_0219E5B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerParseQR2FullKeysSplit (sb_server.o)
 *
 * symbols:
 *   g_021A816C  0x021A816C  data
 *   g_021A8178  0x021A8178  data
 *   g_021A8164  0x021A8164  data
 *   g_021A81AC  0x021A81AC  data
 *   NTSLengthSB  0x0219F978  arm  ov009
 *   strlen  0x0209477C  arm
 *   strnicmp  0x0209ABEC  arm
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0219D114  0x0219D114  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 */

typedef struct _SBServer {
    unsigned int publicip;
    unsigned short publicport;
    unsigned int privateip;
    unsigned short privateport;
    unsigned int icmpip;
    unsigned char state;
    unsigned char flags;
    void *keyvals;
    unsigned int updatetime;
    unsigned int querychallenge;
    struct _SBServer *next;
    unsigned char splitResponseBitmap;
} _SBServer;

extern char g_021A816C[];
extern char g_021A8178[];
extern char g_021A8164[];
extern char g_021A81AC[];

extern int NTSLengthSB(char *buf, int len);
typedef unsigned char  u8;
extern int strlen(const u8 *s);
extern int strnicmp(const char *s1, const char *s2, unsigned int n);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_0219D114(char *keyname);
extern void func_0219E01C(_SBServer *server, char *keyname, char *value);
extern int OS_SPrintf(char *dst, const char *fmt, ...);

void func_0219E5B8(_SBServer *server, char *data, int len)
{
    int dlen;
    char *k;
    char *v;
    unsigned int packetNum = 0;
    int isFinal = 0;
    int keyType = 0;
    int nindex = 0;
    char tempkey[128];

    if (*data == '\0')
        return;
    dlen = NTSLengthSB(data, len);
    if (dlen < 0)
        return;
    k = data;
    data += dlen;
    len -= dlen;
    if (strnicmp(g_021A816C, k, strlen((const u8 *)g_021A816C)) != 0)
        return;

    if (len < 1)
        return;
    packetNum = (unsigned int)(unsigned char)*data;
    data++;
    len--;

    if ((packetNum & 0x80) == 0x80) {
        isFinal = 1;
        packetNum ^= 0x80;
    }
    if (packetNum > 7)
        return;

    if (isFinal == 1)
        server->splitResponseBitmap |= (char)(0xFF << packetNum);
    else
        server->splitResponseBitmap |= (1 << packetNum);

    if (len < 1)
        return;
    while (len > 0) {
        keyType = *data;
        data++;
        len--;
        if (keyType < 0 || keyType > 2) {
            func_0217D254(4, 0, 2, g_021A8178, keyType);
            return;
        }
        while (*data != '\0') {
            dlen = NTSLengthSB(data, len);
            if (dlen < 0)
                return;
            k = data;
            data += dlen;
            len -= dlen;
            if (keyType == 0) {
                dlen = NTSLengthSB(data, len);
                if (dlen < 0)
                    return;
                v = data;
                data += dlen;
                len -= dlen;
                if (!func_0219D114(k))
                    func_0219E01C(server, k, v);
            } else {
                if (len < 1)
                    return;
                nindex = *data;
                data++;
                len--;
                while (*data != '\0') {
                    dlen = NTSLengthSB(data, len);
                    if (dlen < 0)
                        return;
                    v = data;
                    data += dlen;
                    len -= dlen;
                    OS_SPrintf(tempkey, g_021A8164, k, nindex);
                    func_0219E01C(server, tempkey, v);
                    nindex++;
                }
                if (len > 0) {
                    data++;
                    len--;
                }
            }
        }
        if (len > 0) {
            if (*data != '\0') {
                func_0217D254(4, 0, 2, g_021A81AC);
                return;
            }
            data++;
            len--;
        }
    }
}
