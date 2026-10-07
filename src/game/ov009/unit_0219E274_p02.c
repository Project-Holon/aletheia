/*
 * file:     unit_0219E274_p02.c
 * unit:     yes
 * function: func_0219E5B8, func_0219E848, func_0219E89C, func_0219E8C4, func_0219E8D4
 * address:  0x0219E5B8
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_021A816C  0x021A816C  data
 *   g_021A8178  0x021A8178  data
 *   g_021A8164  0x021A8164  data
 *   g_021A81AC  0x021A81AC  data
 *   func_0219F978  0x0219F978  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   func_0209ABEC  0x0209ABEC  arm
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0219D114  0x0219D114  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   func_02084F40  0x02084F40  arm
 *   _u32_div_f     0x0209C2B0  arm
 *   __lower_mapC   0x020A60DC  data
 *   SBReleaseStr  0x0219F920  arm
 *   strcasecmp  0x0209ABF8  arm
 */
struct _SBServerList;
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

typedef unsigned char  u8;

struct _SBKeyValuePair {
    char *key;
    char *value;
};

extern int func_0219F978(char *buf, int len);
extern int func_0209477C(const u8 *s);
extern int func_0209ABEC(const char *s1, const char *s2, unsigned int n);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern int func_0219D114(char *keyname);
extern void func_0219E01C(_SBServer *server, char *keyname, char *value);
extern int func_02084F40(char *dst, const char *fmt, ...);
extern unsigned int _u32_div_f(unsigned int a, unsigned int b);
extern void SBReleaseStr(struct _SBServerList *slist, char *str);
extern int strcasecmp(char *a, char *b);
void func_0219E5B8(_SBServer *server, char *data, int len);
asm void KeyValHashKey(void);
extern char g_021A816C[];
extern char g_021A8178[];
extern char g_021A8164[];
extern char g_021A81AC[];
extern unsigned char __lower_mapC[];


/*
 * sdk:      SBServerParseQR2FullKeysSplit (sb_server.o)
 */
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
    dlen = func_0219F978(data, len);
    if (dlen < 0)
        return;
    k = data;
    data += dlen;
    len -= dlen;
    if (func_0209ABEC(g_021A816C, k, func_0209477C((const u8 *)g_021A816C)) != 0)
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
            dlen = func_0219F978(data, len);
            if (dlen < 0)
                return;
            k = data;
            data += dlen;
            len -= dlen;
            if (keyType == 0) {
                dlen = func_0219F978(data, len);
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
                    dlen = func_0219F978(data, len);
                    if (dlen < 0)
                        return;
                    v = data;
                    data += dlen;
                    len -= dlen;
                    func_02084F40(tempkey, g_021A8164, k, nindex);
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


static int StringHash(char *s, int numbuckets)
{
    unsigned int hashcode = 0;
    char *p = s;
    int c;

    while ((c = *p) != 0)
    {
        if (c >= 0 && c < 0x80)
            c = __lower_mapC[c];
        hashcode = hashcode * 0x9CCF9319 + c;
        p++;
    }
    return hashcode % numbuckets;
}


static void KeyValFree(void *elem)
{
    SBReleaseStr(0, ((struct _SBKeyValuePair *)elem)->key);
    SBReleaseStr(0, ((struct _SBKeyValuePair *)elem)->value);
}

asm void KeyValHashKey(void)
{
	ldr r0, [r0]
	ldr ip, =StringHash
	bx ip
}


static int KeyValCompareKey(void *entry1, void *entry2)
{
    if (((struct _SBKeyValuePair *)entry1)->key != 0 &&
        ((struct _SBKeyValuePair *)entry2)->key != 0)
        return strcasecmp(((struct _SBKeyValuePair *)entry1)->key,
                          ((struct _SBKeyValuePair *)entry2)->key);
    return 1;
}
