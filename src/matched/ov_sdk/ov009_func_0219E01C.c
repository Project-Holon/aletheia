/*
 * function: SBServerAddKeyValue
 * address:  0x0219E01C
 * packet:   pkt_ov009_0219E01C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      SBServerAddKeyValue (sb_server.o)
 *
 * symbols:
 *   SBRefStr       0x0219F8B0  arm
 *   TableEnter     0x0218474C  arm
 *   gsDebugFormat  0x0217D254  arm
 *   g_021A8130     0x021A8130  data
 */

struct HashImplementation;
struct _SBServerList;
struct _SBServer {
    char pad[0x18];
    struct HashImplementation *keys;
};
struct _SBKeyValuePair {
    char *key;
    char *value;
};

extern char *SBRefStr(struct _SBServerList *slist, char *str);
extern void TableEnter(struct HashImplementation *table, void *newElem);
extern void gsDebugFormat(int theCat, int theType, unsigned char theLevel,
                          char *theTokenStr, ...);
extern char g_021A8130[];

void SBServerAddKeyValue(struct _SBServer *server, char *keyname, char *value)
{
    struct _SBKeyValuePair kv;

    kv.key = SBRefStr(0, keyname);
    kv.value = SBRefStr(0, value);
    TableEnter(server->keys, &kv);
    gsDebugFormat(4, 4, 0x10, g_021A8130, keyname, value);
}
