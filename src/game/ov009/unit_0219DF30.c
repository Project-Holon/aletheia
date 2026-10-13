/*
 * file:     unit_0219DF30.c
 * unit:     yes
 * function: func_0219DF30, func_0219DF40, func_0219DF54, func_0219DF64, func_0219DFC0, func_0219DFF8, func_0219E01C, func_0219E084, func_0219E0C0, func_0219E120, func_0219E1B8
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
 * symbols:
 *   StringHash                   0x0219E848  arm
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
 *   func_0219E8F8  0x0219E8F8  arm  ov009
 *   func_0219E0C0  0x0219E0C0  arm  ov009
 *   func_020964E0  0x020964E0  arm
 *   g_021A8158  0x021A8158  data
 *   g_020A61DC  0x020A61DC  data
 *   SBServerGetStringValueA  0x0219E0C0  arm
 *   atof                     0x02095B2C  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"

struct HashImplementation;
struct _SBServerList;
struct _SBServer;
struct SBServer;
struct _SBServer {
    char pad[0x18];
    struct HashImplementation *keys;
};

struct _SBKeyValuePair {
    char *key;
    char *value;
};

typedef unsigned int   u32;

extern int StringHash(char *s, int numbuckets);
extern int func_0209ABF8(char *s1, char *s2);
extern void gsifree(void *ptr);
extern struct HashImplementation *TableNew2(int elemSize, int nBuckets,
    int nChains, int (*hashFn)(void *, int), int (*compFn)(void *, void *),
    void (*freeFn)(void *));
extern int TableCount(struct HashImplementation *table);
extern void TableFree(struct HashImplementation *table);
extern char *SBRefStr(struct _SBServerList *slist, char *str);
extern void TableEnter(struct HashImplementation *table, void *newElem);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr, ...);
extern int OS_SPrintf(char *dst, char *fmt, ...);
void SBServerAddKeyValue(struct _SBServer *server, char *keyname, char *value);
void SBServerAddIntKeyValue(struct _SBServer *server, char *keyname, int value);
extern void *TableLookup(struct HashImplementation *table, void *elemKey);
extern int func_020948E0(const char *a, const char *b);
extern int func_0219E8F8(const int *p);
extern char *func_0219E0C0(struct _SBServer *server, char *keyname, char *def);
extern int func_020964E0(u32 a0);
extern char *SBServerGetStringValueA(struct _SBServer *server, char *keyname,
                                     char *def);
extern double atof(char *s);
int func_0219E120(struct SBServer *server, char *key, int idefault);
double SBServerGetFloatValueA(struct _SBServer *server, char *key, double fdefault);
int RefStringHash(void *elem, int numbuckets);
int RefStringCompare(void *entry1, void *entry2);
void RefStringFree(void *elem);
struct HashImplementation *SBRefStrHash(void);
void SBRefStrHashCleanup(void);
void SBServerFree(void *elem);
extern struct HashImplementation *g_021AEAF8[];
extern char g_021A8130[];
extern char g_021A8154[];
extern char g_021A8158[];
extern const unsigned short g_020A61DC[];



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
    struct _SBServer *server = *(struct _SBServer **)elem;

    TableFree(server->keys);
    server->keys = 0;
    gsifree(server);
}





void SBServerAddKeyValue(struct _SBServer *server, char *keyname, char *value)
{
    struct _SBKeyValuePair kv;

    kv.key = SBRefStr(0, keyname);
    kv.value = SBRefStr(0, value);
    TableEnter(server->keys, &kv);
    gsDebugFormat(4, 4, 0x10, g_021A8130, keyname, value);
}


void SBServerAddIntKeyValue(struct _SBServer *server, char *keyname, int value)
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
char *func_0219E0C0(struct _SBServer *server, char *keyname, char *def)
{
    struct _SBKeyValuePair *ptr;
    struct _SBKeyValuePair kv;

    if (server == 0)
        return 0;
    kv.key = keyname;
    ptr = TableLookup(server->keys, &kv);
    if (ptr == 0 || strlen(ptr->value) == 0)
        return def;
    return ptr->value;
}



static inline int isdigit(unsigned int c) { return (c >= 0x80) ? 0 : (g_020A61DC[c] & 8); }



/*
 * sdk:      SBServerGetIntValueA (libdwcgsserverbrowsing.TWL.HYB.a(sb_server.o))
 */
int func_0219E120(struct SBServer *server, char *key, int idefault)
{
    char *s;

    if (server == 0)
        return idefault;
    if (func_020948E0(key, g_021A8158) == 0)
        return func_0219E8F8((const int *)server);
    s = func_0219E0C0((struct _SBServer *)server, key, 0);
    if (s == 0)
        return idefault;
    if (!isdigit(*(unsigned char *)(*s != 0x2d ? s : s + 1)))
        return idefault;
    return func_020964E0((u32)s);
}


double SBServerGetFloatValueA(struct _SBServer *server, char *key,
                              double fdefault)
{
    char *s = SBServerGetStringValueA(server, key, 0);

    if (s != 0)
        fdefault = atof(s);
    return fdefault;
}
