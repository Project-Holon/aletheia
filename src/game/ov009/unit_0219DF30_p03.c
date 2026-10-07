/*
 * file:     unit_0219DF30_p03.c
 * unit:     yes
 * function: func_0219DFF8, func_0219E01C, func_0219E084
 * address:  0x0219DFF8
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
 *   TableFree    0x021846B4  arm
 *   gsifree      0x0217EAE0  arm
 *   SBRefStr       0x0219F8B0  arm
 *   TableEnter     0x0218474C  arm
 *   gsDebugFormat  0x0217D254  arm
 *   g_021A8130     0x021A8130  data
 *   OS_SPrintf            0x02084F40  arm
 *   g_021A8154            0x021A8154  data
 */
struct HashImplementation;
struct _SBServerList;
struct _SBServer;
struct _SBServer {
    char pad[0x18];
    struct HashImplementation *keys;
};

struct _SBKeyValuePair {
    char *key;
    char *value;
};

extern void TableFree(struct HashImplementation *table);
extern void gsifree(void *ptr);
extern char *SBRefStr(struct _SBServerList *slist, char *str);
extern void TableEnter(struct HashImplementation *table, void *newElem);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr, ...);
extern int OS_SPrintf(char *dst, char *fmt, ...);
void SBServerFree(void *elem);
void SBServerAddKeyValue(struct _SBServer *server, char *keyname, char *value);
void SBServerAddIntKeyValue(struct _SBServer *server, char *keyname, int value);
extern char g_021A8130[];
extern char g_021A8154[];


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
