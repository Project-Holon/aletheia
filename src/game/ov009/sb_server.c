/*
 * file:     sb_server.c
 * unit:     yes
 * function: func_0219DF30, func_0219DF40, func_0219DF54, func_0219DF64, func_0219DFC0, func_0219DFF8, func_0219E01C, func_0219E084, func_0219E0C0, func_0219E120, func_0219E1B8, SBServerGetPublicInetAddress, func_0219E1F4, SBServerGetPublicQueryPortNBO, func_0219E220, SBServerGetPrivateInetAddress, func_0219E240, SBServerSetNext, SBServerGetNext, func_0219E274, func_0219E2D4, func_0219E33C, func_0219E3CC, func_0219E5B8, func_0219E848, func_0219E89C, func_0219E8C4, func_0219E8D4, SBServerGetPing, func_0219E900, SBServerSetFlags, func_0219E9B4, SBServerSetICMPIP, SBServerSetState, SBServerGetState, func_0219E9D8
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
 *   func_0209ABF8                0x0209ABF8  arm
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
 *   func_020948E0  0x020948E0  arm
 *   func_020964E0  0x020964E0  arm
 *   g_021A8158  0x021A8158  data
 *   g_020A61DC  0x020A61DC  data
 *   SBServerGetStringValueA  0x0219E0C0  arm
 *   atof                     0x02095B2C  arm
 *   strcmp                         0x020948E0  arm
 *   g_021A8120                     0x021A8120  data
 *   _ZZ5mytokPccE6thestr            0x021AEAF8  data
 *   func_0219E2D4  0x0219E2D4  arm  ov009
 *   func_0219D114  0x0219D114  arm  ov009
 *   func_0219E01C  0x0219E01C  arm  ov009
 *   g_021A8160  0x021A8160  data
 *   g_021A8164  0x021A8164  data
 *   func_0219F978  0x0219F978  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   func_0209477C  0x0209477C  arm
 *   g_021A816C  0x021A816C  data
 *   g_021A8178  0x021A8178  data
 *   g_021A81AC  0x021A81AC  data
 *   func_0209ABEC  0x0209ABEC  arm
 *   func_0217D254  0x0217D254  arm  ov009
 *   _u32_div_f     0x0209C2B0  arm
 *   __lower_mapC   0x020A60DC  data
 *   SBReleaseStr  0x0219F920  arm
 *   strcasecmp  0x0209ABF8  arm
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02184638  0x02184638  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 *   func_0219E8D4  0x0219E8D4  arm  ov009
 *   func_0219E89C  0x0219E89C  arm  ov009
 *   func_0219E8C4  0x0219E8C4  arm  ov009
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

extern int func_0209ABF8(char *s1, char *s2);
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
extern int func_020948E0(const char *a, const char *b);
extern int func_020964E0(u32 a0);
extern char *SBServerGetStringValueA(SBServer *server, char *keyname,
                                     char *def);
extern double atof(char *s);
extern int strcmp(char *a, char *b);
extern char *func_0219E2D4(char *instr, char delim);
extern int func_0219D114(char *keyname);
extern void func_0219E01C(SBServer *server, char *keyname, char *value);
extern int func_0219F978(char *buf, int len);
extern unsigned int func_0209477C(const char *s);
extern int func_0209ABEC(const char *s1, const char *s2, unsigned int n);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern unsigned int _u32_div_f(unsigned int a, unsigned int b);
extern void SBReleaseStr(SBServerList *slist, char *str);
extern int strcasecmp(char *a, char *b);
extern void *func_0217EAB0(unsigned long size);
extern void *func_02184638(int elemSize, int nBuckets, int nChains, int (*hashFn)(void *, int),
                           int (*compFn)(void *, void *), void (*freeFn)(void *));
extern void func_0217EAE0(void *ptr);
extern int func_0219E8D4(void *a, void *b);
extern void func_0219E89C(void *elem);
extern int func_0219E8C4(void *elem, int numbuckets);
int RefStringHash(void *elem, int numbuckets);
int RefStringCompare(void *entry1, void *entry2);
void RefStringFree(void *elem);
struct HashImplementation *SBRefStrHash(void);
void SBRefStrHashCleanup(void);
void SBServerFree(void *elem);
void SBServerAddKeyValue(SBServer *server, char *keyname, char *value);
void SBServerAddIntKeyValue(SBServer *server, char *keyname, int value);
char *func_0219E0C0(SBServer *server, char *keyname, char *def);
int func_0219E120(SBServer *server, char *key, int idefault);
double SBServerGetFloatValueA(SBServer *server, char *key, double fdefault);
unsigned int SBServerGetPublicInetAddress(const SBServer *server);
unsigned short func_0219E1F4(const unsigned short *p);
unsigned short SBServerGetPublicQueryPortNBO(const SBServer *server);
int func_0219E220(const unsigned char *p);
unsigned int SBServerGetPrivateInetAddress(const SBServer *server);
unsigned short func_0219E240(const unsigned short *p);
void SBServerSetNext(SBServer *server, SBServer *next);
SBServer *SBServerGetNext(const SBServer *server);
int func_0219E274(char *key);
char *mytok(char *instr, char delim);
void func_0219E33C(SBServer *server, char *keyvals);
void func_0219E3CC(SBServer *server, char *data, int len);
void func_0219E5B8(SBServer *server, char *data, int len);
int KeyValHashKey(void *elem, int numbuckets);
int SBServerGetPing(const SBServer *server);
SBServer *func_0219E900(int unused, unsigned int publicip, unsigned short publicport);
void SBServerSetFlags(SBServer *server, unsigned char flags);
void func_0219E9B4(char *p, int v, unsigned short w);
void SBServerSetICMPIP(SBServer *server, unsigned int icmpIp);
void SBServerSetState(SBServer *server, unsigned char state);
unsigned char SBServerGetState(const SBServer *server);
int func_0219E9D8(int v);
extern struct HashImplementation *g_021AEAF8[];
extern char g_021A8130[];
extern char g_021A8154[];
extern char g_021A8158[];
extern const unsigned short g_020A61DC[];
extern char *g_021A8120[2];
extern char g_021A8160[];
extern char g_021A8164[];
extern char g_021A816C[];
extern char g_021A8178[];
extern char g_021A81AC[];
extern unsigned char __lower_mapC[];




int RefStringHash(void *elem, int numbuckets)
{
    return StringHash(*(char **)elem, numbuckets);
}





int RefStringCompare(void *entry1, void *entry2)
{
    return func_0209ABF8(*(char **)entry1, *(char **)entry2);
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
char *func_0219E0C0(SBServer *server, char *keyname, char *def)
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




static inline int isdigit(unsigned int c) { return (c >= 0x80) ? 0 : (g_020A61DC[c] & 8); }




/*
 * sdk:      SBServerGetIntValueA (libdwcgsserverbrowsing.TWL.HYB.a(sb_server.o))
 */
int func_0219E120(SBServer *server, char *key, int idefault)
{
    char *s;

    if (server == 0)
        return idefault;
    if (func_020948E0(key, g_021A8158) == 0)
        return SBServerGetPing(server);
    s = func_0219E0C0((SBServer *)server, key, 0);
    if (s == 0)
        return idefault;
    if (!isdigit(*(unsigned char *)(*s != 0x2d ? s : s + 1)))
        return idefault;
    return func_020964E0((u32)s);
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

unsigned short func_0219E1F4(const unsigned short *p)
{
    int v = p[2];

    return (unsigned short)(((v >> 8) & 0xff) | ((v << 8) & 0xff00));
}


unsigned short SBServerGetPublicQueryPortNBO(const SBServer *server)
{
    return server->publicport;
}

int func_0219E220(const unsigned char *p)
{
    return (p[0x15] & 2) == 2;
}


unsigned int SBServerGetPrivateInetAddress(const SBServer *server)
{
    return server->privateip;
}

unsigned short func_0219E240(const unsigned short *p)
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
int func_0219E274(char *key)
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
void func_0219E33C(SBServer *server, char *keyvals)
{
    char *k;
    char *v;

    k = func_0219E2D4(keyvals + 1, 0x5c);
    while (k != 0) {
        v = func_0219E2D4(0, 0x5c);
        if (v == 0)
            v = g_021A8160;
        if (func_0219E274(k) && !func_0219D114(k))
            func_0219E01C(server, k, v);
        k = func_0219E2D4(0, 0x5c);
    }
}




/*
 * sdk:      SBServerParseQR2FullKeysSingle (sb_server.o)
 *
 * The two-byte nunits copy is memcpy from string.h, which mwccarm inlines as the
 * object's ldrb/strb pair; a prototype in this file would emit a call.
 */
void func_0219E3CC(SBServer *server, char *data, int len)
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
                OS_SPrintf(tempkey, g_021A8164, k, i);
                func_0219E01C(server, tempkey, data);
                data += dlen;
                len -= dlen;
                k += func_0209477C(k) + 1;
            }
        }
    }
}




/*
 * sdk:      SBServerParseQR2FullKeysSplit (sb_server.o)
 */
void func_0219E5B8(SBServer *server, char *data, int len)
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
    if (func_0209ABEC(g_021A816C, k, func_0209477C(g_021A816C)) != 0)
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


SBServer *func_0219E900(int unused, unsigned int publicip, unsigned short publicport)
{
    SBServer *server;

    server = func_0217EAB0(sizeof(SBServer));
    if (server == 0)
        return 0;
    server->keyvals = func_02184638(8, 8, 4, func_0219E8C4, func_0219E8D4, func_0219E89C);
    if (server->keyvals == 0) {
        func_0217EAE0(server);
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

void func_0219E9B4(char *p, int v, unsigned short w)
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


int func_0219E9D8(int v)
{
    return v == (int)g_021AEAF8[2];
}
