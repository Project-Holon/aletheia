#ifndef OV009_UNIT_0219E1EC_TYPES_H
#define OV009_UNIT_0219E1EC_TYPES_H
/*
 * GameSpy server browsing types (sb_server, sb_serverlist, sb_queryengine):
 * one definition per object, field names are the library's own.
 */

struct SBQueryEngine;
struct SBServerList;
struct ServerBrowser;
typedef struct SBServer {
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
    struct SBServer *next;
    unsigned char splitResponseBitmap;
} SBServer;

typedef struct SBServerFIFO {
    SBServer *first;
    SBServer *last;
    int count;
} SBServerFIFO;

typedef void (*SBEngineCB)(struct SBQueryEngine *engine, int reason, SBServer *server, void *instance);

typedef void (*SBListCB)(struct SBServerList *, int, SBServer *, void *);

typedef void (*SBMaploopCB)(struct SBServerList *slist, void *server, long changeTime, int count, char **mapList, void *instance);

typedef void (*SBPlayerSearchCB)(struct SBServerList *, char *, unsigned int, unsigned short, long, char *, void *);

typedef void (*SBBrowserCB)(struct ServerBrowser *, int, SBServer *, void *);

typedef struct SBQueryEngine {
    int queryversion;
    int maxupdates;
    SBServerFIFO querylist;
    SBServerFIFO pendinglist;
    int querysock;
    int icmpsock;
    unsigned int mypublicip;
    unsigned char serverkeys[40];
    int numserverkeys;
    SBEngineCB ListCallback;
    void *instance;
} SBQueryEngine;

typedef struct SBSortInfo {
    char sortkey[256];
    int comparemode;
} SBSortInfo;

typedef struct SBServerList {
    int state;
    void *servers;
    void *keylist;
    char queryforgamename[36];
    char queryfromgamename[36];
    char queryfromkey[32];
    char mychallenge[8];
    unsigned char *inbuffer;
    int inbufferlen;
    char *popularvalues[255];
    int numpopularvalues;
    int expectedelements;
    SBListCB ListCallback;
    SBMaploopCB MaploopCallback;
    SBPlayerSearchCB PlayerSearchCallback;
    void *instance;
    SBSortInfo currsortinfo;
    SBSortInfo prevsortinfo;
    int sortascending;
    unsigned int mypublicip;
    unsigned int srcip;
    unsigned short defaultport;
    char *lasterror;
    int slsocket;
    unsigned int lanstarttime;
    int fromgamever;
    char cryptkey[0x108];
    int queryoptions;
    int pstate;
    unsigned short backendgameflags;
    char *mLanAdapterOverride;
    SBServer *deadlist;
} SBServerList;

typedef struct ServerBrowser {
    SBQueryEngine engine;
    SBServerList list;
    int disconnectFlag;
    int dontUpdateList;
    unsigned int triggerIP;
    unsigned short triggerPort;
    SBBrowserCB BrowserCallback;
    void *ConnectCallback;
    void *instance;
} ServerBrowser;


#endif
