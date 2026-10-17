/*
 * file:     sb_server.c
 * unit:     yes
 * function: RefStringHash, RefStringCompare, RefStringFree, SBRefStrHash, SBRefStrHashCleanup, SBServerFree, SBServerAddKeyValue, SBServerAddIntKeyValue, SBServerGetStringValueA, SBServerGetIntValueA, SBServerGetFloatValueA, SBServerGetPublicInetAddress, SBServerGetPublicQueryPort, SBServerGetPublicQueryPortNBO, SBServerHasPrivateAddress, SBServerGetPrivateInetAddress, SBServerGetPrivateQueryPort, SBServerSetNext, SBServerGetNext, CheckValidKey, mytok, SBServerParseKeyVals, SBServerParseQR2FullKeysSingle, SBServerParseQR2FullKeysSplit, func_0219E848, KeyValFree, KeyValHashKey, KeyValCompareKey, SBServerGetPing, SBAllocServer, SBServerSetFlags, SBServerSetPrivateAddr, SBServerSetICMPIP, SBServerSetState, SBServerGetState, SBIsNullServer
 * address:  0x0219DF30
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Public address of a server.
 * Halfword at +4 with its two bytes exchanged.
 * Public query port of a server, as stored (network byte order).
 * Tests bit 1 of the byte at +0x15.
 * Private address of a server.
 * Halfword at +0xc with its two bytes exchanged.
 * Ping time of a server (the update time field).
 * sdk:      SBAllocServer (libdwcgsserverbrowsing.TWL.HYB.a(sb_server.o))
 * Sets the flag bits of a server.
 * Stores a word at +8 and a halfword at +0xc.
 * True when the argument equals the word at +0x8 of the module state object.
 *
 * symbols:
 *   strcmp_nocase                0x0209ABF8  arm
 *   gsifree                      0x0217EAE0  arm
 *   TableNew2         0x02184638  arm
 *   g_021AEAF8        0x021AEAF8  data
 *   TableCount   0x02184700  arm
 *   TableFree    0x021846B4  arm
 *   SBRefStr       0x0219F8B0  arm
 *   TableEnter     0x0218474C  arm
 *   gsDebugFormat  0x0217D254  arm
 *   g_021A8130     0x021A8130  data
 *   OS_SPrintf            0x02084F40  arm
 *   g_021A8154            0x021A8154  data
 *   TableLookup                    0x0218482C  arm ov009
 *   strlen                         0x0209477C  arm
 *   strcmp  0x020948E0  arm
 *   atoi  0x020964E0  arm
 *   g_021A8158  0x021A8158  data
 *   gCtypeMap  0x020A61DC  data
 *   SBServerGetStringValueA  0x0219E0C0  arm
 *   atof                     0x02095B2C  arm
 *   strcmp                         0x020948E0  arm
 *   g_021A8120                     0x021A8120  data
 *   _ZZ5mytokPccE6thestr            0x021AEAF8  data
 *   mytok  0x0219E2D4  arm  ov009
 *   qr2_internal_is_master_only_key  0x0219D114  arm  ov009
 *   SBServerAddKeyValue  0x0219E01C  arm  ov009
 *   g_021A8160  0x021A8160  data
 *   g_021A8164  0x021A8164  data
 *   NTSLengthSB  0x0219F978  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   strlen  0x0209477C  arm
 *   g_021A816C  0x021A816C  data
 *   g_021A8178  0x021A8178  data
 *   g_021A81AC  0x021A81AC  data
 *   strnicmp  0x0209ABEC  arm
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   _u32_div_f     0x0209C2B0  arm
 *   __lower_mapC   0x020A60DC  data
 *   SBReleaseStr  0x0219F920  arm
 *   strcasecmp  0x0209ABF8  arm
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   TableNew2  0x02184638  arm  ov009
 *   gsifree  0x0217EAE0  arm  ov009
 *   KeyValCompareKey  0x0219E8D4  arm  ov009
 *   KeyValFree  0x0219E89C  arm  ov009
 *   KeyValHashKey  0x0219E8C4  arm  ov009
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "sb_server_types.h"

struct HashImplementation;
typedef struct SBKeyValuePair {
    char *key;
    char *value;
} SBKeyValuePair;

typedef unsigned int   u32;

typedef struct {
    char *k[2];
} InvalidKeyList;

typedef unsigned char  u8;

extern int strcmp_nocase(char *s1, char *s2);
extern void gsifree(void *ptr);
extern struct HashImplementation *TableNew2(int elemSize, int nBuckets,
    int nChains, int (*hashFn)(void *, int), int (*compFn)(void *, void *),
    void (*freeFn)(void *));
extern int TableCount(struct HashImplementation *table);
extern void TableFree(struct HashImplementation *table);
extern char *SBRefStr(SBServerList *slist, char *str);
extern void TableEnter(struct HashImplementation *table, void *newElem);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr, ...);
extern int OS_SPrintf(char *dst, char *fmt, ...);
extern void *TableLookup(struct HashImplementation *table, void *elemKey);
extern char *SBServerGetStringValueA(SBServer *server, char *keyname,
                                     char *def);
extern double atof(char *s);
extern int qr2_internal_is_master_only_key(char *keyname);
extern int NTSLengthSB(char *buf, int len);
extern unsigned int _u32_div_f(unsigned int a, unsigned int b);
extern void SBReleaseStr(SBServerList *slist, char *str);
extern int strcasecmp(char *a, char *b);
extern void *gsimalloc(unsigned long size);
extern void gsifree(void *ptr);
extern int KeyValCompareKey(void *a, void *b);
extern void KeyValFree(void *elem);
extern int KeyValHashKey(void *elem, int numbuckets);
int RefStringHash(void *elem, int numbuckets);
int RefStringCompare(void *entry1, void *entry2);
void RefStringFree(void *elem);
struct HashImplementation *SBRefStrHash(void);
void SBRefStrHashCleanup(void);
void SBServerFree(void *elem);
void SBServerAddKeyValue(SBServer *server, char *keyname, char *value);
void SBServerAddIntKeyValue(SBServer *server, char *keyname, int value);
char *SBServerGetStringValueA(SBServer *server, char *keyname, char *def);
int SBServerGetIntValueA(SBServer *server, char *key, int idefault);
double SBServerGetFloatValueA(SBServer *server, char *key, double fdefault);
unsigned int SBServerGetPublicInetAddress(const SBServer *server);
unsigned short SBServerGetPublicQueryPort(const unsigned short *p);
unsigned short SBServerGetPublicQueryPortNBO(const SBServer *server);
int SBServerHasPrivateAddress(const unsigned char *p);
unsigned int SBServerGetPrivateInetAddress(const SBServer *server);
unsigned short SBServerGetPrivateQueryPort(const unsigned short *p);
void SBServerSetNext(SBServer *server, SBServer *next);
SBServer *SBServerGetNext(const SBServer *server);
int CheckValidKey(char *key);
char *mytok(char *instr, char delim);
void SBServerParseKeyVals(SBServer *server, char *keyvals);
void SBServerParseQR2FullKeysSingle(SBServer *server, char *data, int len);
void SBServerParseQR2FullKeysSplit(SBServer *server, char *data, int len);
int KeyValHashKey(void *elem, int numbuckets);
int SBServerGetPing(const SBServer *server);
SBServer *SBAllocServer(int unused, unsigned int publicip, unsigned short publicport);
void SBServerSetFlags(SBServer *server, unsigned char flags);
void SBServerSetPrivateAddr(char *p, int v, unsigned short w);
void SBServerSetICMPIP(SBServer *server, unsigned int icmpIp);
void SBServerSetState(SBServer *server, unsigned char state);
unsigned char SBServerGetState(const SBServer *server);
int SBIsNullServer(int v);
extern struct HashImplementation *g_021AEAF8[];
extern char g_021A8130[];
extern char g_021A8154[];
extern char g_021A8158[];
extern const unsigned short gCtypeMap[];
extern char *g_021A8120[2];
extern char g_021A8160[];
extern char g_021A8164[];
extern char g_021A816C[];
extern char g_021A8178[];
extern char g_021A81AC[];
extern unsigned char __lower_mapC[];




extern int strcmp(const char *a, const char *b);
extern int atoi(u32 a0);
extern int strnicmp(const char *s1, const char *s2, unsigned int n);
int RefStringHash(void *elem, int numbuckets)
{
    return StringHash(*(char **)elem, numbuckets);
}





int RefStringCompare(void *entry1, void *entry2)
{
    return strcmp_nocase(*(char **)entry1, *(char **)entry2);
}




void RefStringFree(void *elem)
{
    gsifree(*(void **)elem);
}





struct HashImplementation *SBRefStrHash(void)
{
    if (g_021AEAF8[1] != 0)
        return g_021AEAF8[1];
    g_021AEAF8[1] = TableNew2(8, 100, 2, RefStringHash, RefStringCompare,
                              RefStringFree);
    return g_021AEAF8[1];
}





void SBRefStrHashCleanup(void)
{
    if (g_021AEAF8[1] == 0)
        return;
    if (TableCount(g_021AEAF8[1]) != 0)
        return;
    TableFree(g_021AEAF8[1]);
    g_021AEAF8[1] = 0;
}






void SBServerFree(void *elem)
{
    SBServer *server = *(SBServer **)elem;

    TableFree(server->keyvals);
    server->keyvals = 0;
    gsifree(server);
}






void SBServerAddKeyValue(SBServer *server, char *keyname, char *value)
{
    SBKeyValuePair kv;

    kv.key = SBRefStr(0, keyname);
    kv.value = SBRefStr(0, value);
    TableEnter(server->keyvals, &kv);
    gsDebugFormat(4, 4, 0x10, g_021A8130, keyname, value);
}



void SBServerAddIntKeyValue(SBServer *server, char *keyname, int value)
{
    char stemp[20];

    OS_SPrintf(stemp, g_021A8154, value);
    SBServerAddKeyValue(server, keyname, stemp);
}



/*
 * sdk:      SBServerGetStringValueA (sb_server.o)
 *
 * Closed (w5_nm): one guard `if (ptr == 0 || strlen(ptr->value) == 0) return def;`
 * followed by `return ptr->value;`, with strlen from string.h so the value stays
 * in r4 across the call. The positive-test order duplicated the epilogue.
 */
char *SBServerGetStringValueA(SBServer *server, char *keyname, char *def)
{
    SBKeyValuePair *ptr;
    SBKeyValuePair kv;

    if (server == 0)
        return 0;
    kv.key = keyname;
    ptr = TableLookup(server->keyvals, &kv);
    if (ptr == 0 || strlen(ptr->value) == 0)
        return def;
    return ptr->value;
}




static inline int isdigit(unsigned int c) { return (c >= 0x80) ? 0 : (gCtypeMap[c] & 8); }




/*
 * sdk:      SBServerGetIntValueA (libdwcgsserverbrowsing.TWL.HYB.a(sb_server.o))
 */
int SBServerGetIntValueA(SBServer *server, char *key, int idefault)
{
    char *s;

    if (server == 0)
        return idefault;
    if (strcmp(key, g_021A8158) == 0)
        return SBServerGetPing(server);
    s = SBServerGetStringValueA((SBServer *)server, key, 0);
    if (s == 0)
        return idefault;
    if (!isdigit(*(unsigned char *)(*s != 0x2d ? s : s + 1)))
        return idefault;
    return atoi((u32)s);
}



double SBServerGetFloatValueA(SBServer *server, char *key,
                              double fdefault)
{
    char *s = SBServerGetStringValueA(server, key, 0);

    if (s != 0)
        fdefault = atof(s);
    return fdefault;
}


unsigned int SBServerGetPublicInetAddress(const SBServer *server)
{
    return server->publicip;
}

unsigned short SBServerGetPublicQueryPort(const unsigned short *p)
{
    int v = p[2];

    return (unsigned short)(((v >> 8) & 0xff) | ((v << 8) & 0xff00));
}


unsigned short SBServerGetPublicQueryPortNBO(const SBServer *server)
{
    return server->publicport;
}

int SBServerHasPrivateAddress(const unsigned char *p)
{
    return (p[0x15] & 2) == 2;
}


unsigned int SBServerGetPrivateInetAddress(const SBServer *server)
{
    return server->privateip;
}

unsigned short SBServerGetPrivateQueryPort(const unsigned short *p)
{
    int v = p[6];

    return (unsigned short)(((v >> 8) & 0xff) | ((v << 8) & 0xff00));
}


/*
 * Sets the next server in a list.
 */
void SBServerSetNext(SBServer *server, SBServer *next)
{
    server->next = next;
}


/*
 * Next server in a list.
 */
SBServer *SBServerGetNext(const SBServer *server)
{
    return server->next;
}






/*
 * sdk:      CheckValidKey (sb_server.o)
 *
 * Closed (w5_nm): InvalidKeys is filled by one 8-byte struct assignment from the
 * initializer template, which loads both words before either store.  The vendor
 * initializer is @13711 (two relocated string pointers, 0x021A8128 and
 * 0x021A8118), which the template class cannot compare, so it is declared as
 * the data label g_021A8120.
 */
int CheckValidKey(char *key)
{
    char *InvalidKeys[2];
    unsigned int i;

    *(InvalidKeyList *)InvalidKeys = *(InvalidKeyList *)g_021A8120;
    for (i = 0; i < 2; i++) {
        if (strcmp(key, InvalidKeys[i]) == 0)
            return 0;
    }
    return 1;
}





char *mytok(char *instr, char delim)
{
    char *result;
    static char *thestr;

    if (instr)
        thestr = instr;
    result = thestr;
    while (*thestr && *thestr != delim)
        thestr++;
    if (thestr == result)
        result = 0;
    if (*thestr)
        *thestr++ = '\0';
    return result;
}





/*
 * sdk:      SBServerParseKeyVals (libdwcgsserverbrowsing.TWL.HYB.a(sb_server.o))
 */
void SBServerParseKeyVals(SBServer *server, char *keyvals)
{
    char *k;
    char *v;

    k = mytok(keyvals + 1, 0x5c);
    while (k != 0) {
        v = mytok(0, 0x5c);
        if (v == 0)
            v = g_021A8160;
        if (CheckValidKey(k) && !qr2_internal_is_master_only_key(k))
            SBServerAddKeyValue(server, k, v);
        k = mytok(0, 0x5c);
    }
}




/*
 * sdk:      SBServerParseQR2FullKeysSingle (sb_server.o)
 *
 * The two-byte nunits copy is memcpy from string.h, which mwccarm inlines as the
 * object's ldrb/strb pair; a prototype in this file would emit a call.
 */
void SBServerParseQR2FullKeysSingle(SBServer *server, char *data, int len)
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
        dlen = NTSLengthSB(data, len);
        if (dlen < 0)
            return;
        k = data;
        data += dlen;
        len -= dlen;
        dlen = NTSLengthSB(data, len);
        if (dlen < 0)
            return;
        v = data;
        data += dlen;
        len -= dlen;
        if (!qr2_internal_is_master_only_key(k))
            SBServerAddKeyValue(server, k, v);
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
            dlen = NTSLengthSB(data, len);
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
                dlen = NTSLengthSB(data, len);
                if (dlen < 0)
                    return;
                OS_SPrintf(tempkey, g_021A8164, k, i);
                SBServerAddKeyValue(server, tempkey, data);
                data += dlen;
                len -= dlen;
                k += strlen(k) + 1;
            }
        }
    }
}




/*
 * sdk:      SBServerParseQR2FullKeysSplit (sb_server.o)
 */
void SBServerParseQR2FullKeysSplit(SBServer *server, char *data, int len)
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
    if (strnicmp(g_021A816C, k, strlen(g_021A816C)) != 0)
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
            gsDebugFormat(4, 0, 2, g_021A8178, keyType);
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
                if (!qr2_internal_is_master_only_key(k))
                    SBServerAddKeyValue(server, k, v);
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
                    SBServerAddKeyValue(server, tempkey, v);
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
                gsDebugFormat(4, 0, 2, g_021A81AC);
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
    SBReleaseStr(0, ((SBKeyValuePair *)elem)->key);
    SBReleaseStr(0, ((SBKeyValuePair *)elem)->value);
}



int KeyValHashKey(void *elem, int numbuckets)
{
    return StringHash(*(char **)elem, numbuckets);
}




static int KeyValCompareKey(void *entry1, void *entry2)
{
    if (((SBKeyValuePair *)entry1)->key != 0 &&
        ((SBKeyValuePair *)entry2)->key != 0)
        return strcasecmp(((SBKeyValuePair *)entry1)->key,
                          ((SBKeyValuePair *)entry2)->key);
    return 1;
}


int SBServerGetPing(const SBServer *server)
{
    return server->updatetime;
}


SBServer *SBAllocServer(int unused, unsigned int publicip, unsigned short publicport)
{
    SBServer *server;

    server = gsimalloc(sizeof(SBServer));
    if (server == 0)
        return 0;
    server->keyvals = TableNew2(8, 8, 4, KeyValHashKey, KeyValCompareKey, KeyValFree);
    if (server->keyvals == 0) {
        gsifree(server);
        return 0;
    }
    server->state = 0;
    server->flags = 0;
    server->next = 0;
    server->updatetime = 0;
    server->icmpip = 0;
    server->publicip = publicip;
    server->publicport = publicport;
    server->privateip = 0;
    server->privateport = 0;
    return server;
}


void SBServerSetFlags(SBServer *server, unsigned char flags)
{
    server->flags = flags;
}

void SBServerSetPrivateAddr(char *p, int v, unsigned short w)
{
    *(int *)(p + 8) = v;
    *(unsigned short *)(p + 0xc) = w;
}


/*
 * Sets the address used for the ICMP ping of a server.
 */
void SBServerSetICMPIP(SBServer *server, unsigned int icmpIp)
{
    server->icmpip = icmpIp;
}


/*
 * Sets the state bits of a server.
 */
void SBServerSetState(SBServer *server, unsigned char state)
{
    server->state = state;
}


/*
 * State bits of a server.
 */
unsigned char SBServerGetState(const SBServer *server)
{
    return server->state;
}


int SBIsNullServer(int v)
{
    return v == (int)g_021AEAF8[2];
}
