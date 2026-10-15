/*
 * function: ServerBrowserBeginUpdate2
 * address:  0x0219ED80
 * packet:   pkt_ov009_0219ED80
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ServerBrowserBeginUpdate2 (libdwcgsserverbrowsing.TWL.HYB.a sb_serverbrowsing.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   strlen  0x0209477C  arm
 *   OS_SPrintf  0x02084F40  arm
 *   SBQueryEngineAddQueryKey  0x0219DEE8  arm  ov009
 *   SBServerListConnectAndQuery  0x0219FFD4  arm  ov009
 *   msleep  0x0217F2BC  arm  ov009
 *   ServerBrowserThink  0x0219EFD0  arm  ov009
 *   g_021A81DC  0x021A81DC  data
 *   g_021A7C90  0x021A7C90  data
 *   g_021A8218  0x021A8218  data
 */

typedef struct {
    char pad0[0x10];
    int numpending;
    char pad14[0x40];
    int dontUpdateList;
    char pad58[8];
    int liststate;
    char pad64[0x7d8];
    int disconnectFlag;
} ServerBrowser;

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern unsigned long strlen(const char *s);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
struct SBServerList;
extern void SBQueryEngineAddQueryKey(char *p, int v);
extern int SBServerListConnectAndQuery(struct SBServerList *slist, char *fieldList, char *serverFilter, int options, int maxServers);
extern void msleep(unsigned int msec);
extern int ServerBrowserThink(char *p);
extern char g_021A81DC[];
extern char *g_021A7C90[];
extern char g_021A8218[];

int ServerBrowserBeginUpdate2(ServerBrowser *sb, int async, int disconnectOnComplete, unsigned char *basicFields,
                  int numBasicFields, char *serverFilter, int updateOptions, int maxServers)
{
    char keyList[256] = {0};
    int listLen = 0;
    int i;
    int keylen;
    int err;
    char *key;

    if (numBasicFields > 40) {
        func_0217D254(4, (char *)4, 2, g_021A81DC);
        return 6;
    }
    sb->disconnectFlag = disconnectOnComplete;
    sb->dontUpdateList = 0;
    for (i = 0; i < numBasicFields; i++) {
        key = g_021A7C90[basicFields[i]];
        keylen = strlen(key);
        if (listLen + keylen + 1 >= 256)
            break;
        listLen += OS_SPrintf(keyList + listLen, g_021A8218, key);
        SBQueryEngineAddQueryKey((char *)sb, basicFields[i]);
    }
    err = SBServerListConnectAndQuery((struct SBServerList *)(&sb->liststate), keyList, serverFilter, updateOptions, maxServers);
    if (err != 0 || async)
        return err;
    while (sb->liststate == 3 || (sb->numpending > 0 && err == 0)) {
        msleep(10);
        err = ServerBrowserThink((char *)sb);
    }
    return err;
}
