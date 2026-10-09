/*
 * file:     unit_0219D4B4.c
 * unit:     yes
 * function: func_0219D4B4, func_0219D4E8, func_0219D510, func_0219D544, func_0219D5B0, func_0219D5C4, func_0219D864
 * address:  0x0219D4B4
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
 *   current_time     0x0217f264  arm
 *   sendto           0x0217eca4  arm
 *   FIFOAddRear      0x0219d4b4  arm
 *   g_021A80E8       0x021a80e8  data
 *   g_021A80F8       0x021a80f8  data
 *   SocketStartUp    0x0217f25c  arm
 *   socket           0x0217eb18  arm
 *   FIFOClear        0x0219d5b0  arm
 *   __GSIACResult    0x021acef8  data
 */
struct _SBServer {
    char pad[0x24];
    struct _SBServer *next;
};

struct _SBServerFIFO_0219D4B4 {
    struct _SBServer *first;
    struct _SBServer *last;
    int count;
};

struct _SBServer_0219D544 {
    char pad[0x24];
    struct _SBServer_0219D544 *next;
};

struct _SBServerFIFO_0219D544 {
    struct _SBServer_0219D544 *first;
    struct _SBServer_0219D544 *last;
    int count;
};

struct _SBServer_0219D5C4 {
    unsigned int ip;
    unsigned short port;
    char pad6[2];
    unsigned int ip2;
    unsigned short port2;
    char padE[6];
    unsigned char flags;
    unsigned char flags2;
    char pad16[6];
    unsigned char challenge[4];
    unsigned int field20;
    struct _SBServer_0219D5C4 *next;
};

struct _SBQueryEngine_0219D5C4 {
    int queryversion;
    int maxupdates;
    struct _SBServerFIFO_0219D544 pending;
    struct _SBServerFIFO_0219D544 active;
    int socket;
    int field24;
    unsigned int publicIP;
    unsigned char keybuf[0x28];
    int keycount;
};

struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    unsigned int addr;
};

struct _SBServer_0219D864 {
    char pad[0x24];
    struct _SBServer_0219D864 *next;
};

struct _SBQueryEngine_0219D864 {
    int queryversion;
    int maxupdates;
    struct _SBServerFIFO_0219D544 pending;
    struct _SBServerFIFO_0219D544 active;
    int socket;
    int field24;
    int field28;
    char keybuf[0x28];
    int keycount;
    void (*callback)(struct _SBQueryEngine_0219D864 *, int, struct _SBServer_0219D864 *, void *);
    void *instance;
};

extern unsigned int current_time(void);
extern int sendto(int sock, char *buf, int len, int flags,
                  struct SOCSockAddrIn *addr, int tolen);
extern void FIFOAddRear(struct _SBServerFIFO_0219D544 *fifo, struct _SBServer_0219D5C4 *server);
extern void SocketStartUp(void);
extern int socket(int pf, int type, int protocol);
extern void FIFOClear(struct _SBServerFIFO_0219D544 *fifo);
void func_0219D4B4(int *p, int *n);
void func_0219D4E8(int **p, int *q);
struct _SBServer *FIFOGetFirst(struct _SBServerFIFO_0219D4B4 *fifo);
int FIFORemove(struct _SBServerFIFO_0219D544 *fifo, struct _SBServer_0219D544 *server);
void func_0219D5B0(int *p);
void SBQueryEngineInit(struct _SBQueryEngine_0219D864 *engine, int maxupdates, int queryversion, int lanBrowse, void (*callback)(struct _SBQueryEngine_0219D864 *, int, struct _SBServer_0219D864 *, void *), void *instance);
extern unsigned char g_021A80E8[];
extern unsigned char g_021A80F8[];
extern int __GSIACResult;


/*
 * Pushes a node onto a three-word list head: the node's +0x24 link is
 * cleared, the old head is linked to it, the tail is filled in when the list
 * was empty, and the count at +8 is bumped.
 */
void func_0219D4B4(int *p, int *n)
{
    if (p[1] != 0) ((int *)p[1])[9] = (int)n;
    p[1] = (int)n;
    n[9] = 0;
    if (p[0] == 0) p[0] = (int)n;
    p[2]++;
}


/*
 * Pushes an element onto the singly linked list rooted in *p.
 */
void func_0219D4E8(int **p, int *q)
{
    int *head = p[0];
    int *tail;

    *(int **)((char *)q + 0x24) = head;
    tail = p[1];
    p[0] = q;
    if (tail == 0)
        p[1] = q;
    *(int *)((char *)p + 8) = *(int *)((char *)p + 8) + 1;
}



struct _SBServer *FIFOGetFirst(struct _SBServerFIFO_0219D4B4 *fifo)
{
    struct _SBServer *hold = fifo->first;

    if (hold != 0)
    {
        fifo->first = hold->next;
        if (fifo->first == 0)
            fifo->last = 0;
        fifo->count = fifo->count - 1;
    }
    return hold;
}



int FIFORemove(struct _SBServerFIFO_0219D544 *fifo, struct _SBServer_0219D544 *server)
{
    struct _SBServer_0219D544 *hold = fifo->first;
    struct _SBServer_0219D544 *prev = 0;

    while (hold != 0)
    {
        if (hold == server)
        {
            if (prev != 0)
                prev->next = hold->next;
            if (fifo->first == hold)
                fifo->first = hold->next;
            if (fifo->last == hold)
                fifo->last = prev;
            fifo->count = fifo->count - 1;
            return 1;
        }
        prev = hold;
        hold = hold->next;
    }
    return 0;
}


/*
 * Clears the two words and the word after them.
 */
void func_0219D5B0(int *p)
{
    p[1] = 0;
    p[0] = 0;
    p[2] = 0;
}



static void QEStartQuery(struct _SBQueryEngine_0219D5C4 *engine, struct _SBServer_0219D5C4 *server)
{
    int querySuccess = 0;
    unsigned char queryBuffer[256];
    int queryLen;
    struct SOCSockAddrIn saddr;
    unsigned int challengeNBO;
    unsigned int ip;
    int pos;
    int i;

    saddr.family = 2;
    *(unsigned int *)server->challenge = current_time();

    if (server->flags & 0x20)
        goto done;

    if (engine->queryversion == 1)
    {
        if (server->flags & 0x80)
        {
            queryBuffer[0] = 0xfe;
            queryBuffer[1] = 0xfd;
            queryBuffer[2] = 9;
            __memcpy(&queryBuffer[3], server->challenge, 4);
            queryLen = 7;
            goto send;
        }

        ip = server->field20;
        challengeNBO = ((ip >> 24) & 0xff) |
                       ((ip >> 8) & 0xff00) |
                       ((ip << 8) & 0xff0000) |
                       ((ip << 24) & 0xff000000);
        pos = 0;
        queryBuffer[pos] = 0xfe; pos++;
        queryBuffer[pos] = 0xfd; pos++;
        queryBuffer[pos] = 0; pos++;
        __memcpy(&queryBuffer[pos], server->challenge, 4);
        pos += 4;
        if (challengeNBO != 0)
        {
            __memcpy(&queryBuffer[pos], &challengeNBO, 4);
            pos += 4;
        }

        if (server->flags & 4)
        {
            queryBuffer[pos] = (unsigned char)engine->keycount;
            pos++;
            for (i = 0; i < engine->keycount; i++)
            {
                queryBuffer[pos] = engine->keybuf[i];
                pos++;
            }
            queryBuffer[pos] = 0;
            queryBuffer[pos + 1] = 0;
            queryLen = pos + 2;
        }
        else
        {
            queryBuffer[pos] = 0xff;
            queryBuffer[pos + 1] = 0xff;
            queryBuffer[pos + 2] = 0xff;
            queryBuffer[pos + 3] = 1;
            queryLen = pos + 4;
        }
        goto send;
    }

    if (server->flags & 4)
    {
        __memcpy(queryBuffer, g_021A80E8, 13);
        queryLen = 13;
    }
    else
    {
        __memcpy(queryBuffer, g_021A80F8, 8);
        queryLen = 8;
    }

send:
    if (server->ip == engine->publicIP && (server->flags2 & 2))
    {
        saddr.addr = server->ip2;
        saddr.port = server->port2;
    }
    else
    {
        saddr.addr = server->ip;
        saddr.port = server->port;
    }
    sendto(engine->socket, (char *)queryBuffer, queryLen, 0, &saddr, 8);
    querySuccess = 1;

done:
    if (!querySuccess)
    {
        *(unsigned int *)server->challenge = 0;
        return;
    }
    FIFOAddRear(&engine->pending, server);
}



void SBQueryEngineInit(struct _SBQueryEngine_0219D864 *engine, int maxupdates,
                       int queryversion, int lanBrowse,
                       void (*callback)(struct _SBQueryEngine_0219D864 *, int,
                                        struct _SBServer_0219D864 *, void *),
                       void *instance)
{
    if (lanBrowse == 0 && __GSIACResult != 1)
        return;

    SocketStartUp();

    engine->queryversion = queryversion;
    engine->maxupdates = maxupdates;
    engine->keycount = 0;
    engine->callback = callback;
    engine->instance = instance;
    engine->field28 = 0;
    engine->socket = socket(2, 2, 0);
    FIFOClear(&engine->active);
    FIFOClear(&engine->pending);
}
