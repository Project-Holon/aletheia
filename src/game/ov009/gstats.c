/*
 * file:     gstats.c
 * unit:     yes
 * function: CloseStatsConnection, IsStatsConnected, PersistThink, xcode_buf, value_for_key, value_for_key_safe, PersistCanReceiveOnSocket, FindFinal, FindRequest, ProcessPlayerAuth, ProcessGetPid, ProcessGetData, ProcessSetData, ProcessStatement, ProcessInBuffer, CallReqCallback, ClosePendingCallbacks, GetTeamIndex, GetPlayerIndex, ServerOpInt, ServerOpFloat, ServerOpString, TeamOpInt, TeamOpFloat, TeamOpString, PlayerOpInt, PlayerOpFloat, PlayerOpString
 * address:  0x02193D00
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p -inline deferred
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * GameSpy persistent stats, vendor object gstats.o
 * (libdwcgsgstats.TWL.HYB.a), merged from three unit files.
 *
 * gstats.o was built with -inline deferred: mwccarm then emits the functions
 * in reverse definition order, so the definitions below run from the last
 * function in the image (PlayerOpString) back to CloseStatsConnection.
 * Deferred code generation also gives the vendor order of the two local
 * array templates: @14079 (connerror, ClosePendingCallbacks, 0x10 bytes at
 * 0x021A1A54) before @13818 (keyspec, value_for_key, 0x100 bytes at
 * 0x021A1A64).
 *
 * symbols:
 *   shutdown 0x0217EB9C  arm
 *   closesocket 0x0217EB2C  arm
 *   ClosePendingCallbacks 0x02194614  arm
 *   gsifree 0x0217EAE0  arm
 *   gGstatsSocket   0x021A57C8  data
 *   gGstatsConn   0x021ADFE0  data
 *   PersistCanReceiveOnSocket  0x02193fe8  arm   ov009
 *   gsirealloc  0x0217eac8  arm   ov009
 *   recv  0x0217ec4c  arm   ov009
 *   ProcessInBuffer  0x02194494  arm   ov009
 *   memmove  0x02092364  arm
 *   strcat 0x020948B0  arm
 *   strstr 0x02094B20  arm
 *   strlen 0x0209477C  arm
 *   gGstatsKeyBackslash   0x021A5894  data
 *   gGstatsValueBuffers   0x021AE21C  data
 *   gGstatsEmptyString  0x021A5890  data
 *   @13818       0x021A1A64  data
 *   CanReceiveOnSocket 0x0217EF50 arm
 *   ArrayLength 0x02184200  arm
 *   ArrayNth 0x02184208  arm
 *   value_for_key_safe 0x02193FD0  arm
 *   atoi 0x020964E0  arm
 *   gGstatsKeyPauthr   0x021A5898  data
 *   gGstatsKeyLid   0x021A58A0  data
 *   gGstatsKeyErrmsg   0x021A58A4  data
 *   gGstatsKeyGetpidr   0x021A58AC  data
 *   gGstatsKeyGetpdr   0x021A58B4  data
 *   gGstatsKeyPid   0x021A58BC  data
 *   gGstatsKeyMod   0x021A58C0  data
 *   gGstatsKeyLength   0x021A58C4  data
 *   gGstatsKeyData   0x021A58CC  data
 *   gGstatsEmptyString   0x021A5890  data
 *   gGstatsKeySetpdr   0x021A58D4  data
 *   strncmp 0x020949F4  arm
 *   gGstatsKeySecPauthr   0x021A58DC  data
 *   gGstatsKeySecGetpidr   0x021A58E8  data
 *   gGstatsKeySecGetpdr   0x021A58F4  data
 *   gGstatsKeySecSetpdr   0x021A5900  data
 *   xcode_buf 0x02193EB8  arm
 *   gGstatsNullKey   0x021A57F0  data
 *   ArrayDeleteAt 0x0218437C  arm
 *   ArrayFree 0x021841B0  arm
 *   @14079       0x021A1A54  data
 *   gGstatsCryptKey   0x021A5800  data
 *   BucketNew 0x021937D0  arm
 *   OS_SPrintf  0x02084F40  arm
 *   gGstatsTeamOpFormat   0x021A590C  data
 *   gGstatsPlayerOpFormat   0x021A5914  data
 */
#include "../types.h"
#include "darray.h"

/* The persistent-stats socket wrapper (vendor object gstats.o). */
typedef struct StatsSocket {
    char *key;  /* current xor key string */
    int sock;   /* socket, -1 when closed */
} StatsSocket;

/*
 * The persistent-stats connection state (vendor object gstats.o).
 * Offsets 0x00, 0x04, 0x10, 0x1C and 0x24 are never read by any function in
 * this object; they are kept as padding so the used fields keep their vendor
 * offsets.
 */
typedef struct StatsConn {
    int pad0[2];      /* 0x00, never read */
    int inLen;        /* 0x08, bytes used in inBuff */
    int *game;        /* 0x0C, stats game object passed to the value callbacks */
    int pad10;        /* 0x10, never read */
    void *requests;   /* 0x14, darray of pending serverreq_t */
    int inSize;       /* 0x18, allocated size of inBuff */
    int pad1C;        /* 0x1C, never read */
    int bufIndex;     /* 0x20, alternates 0/1 between the two value buffers */
    int pad24;        /* 0x24, never read */
    char *inBuff;     /* 0x28, receive buffer */
    int state;        /* 0x2C, 5 while the connection is open */
} StatsConn;

typedef struct {
    int type;
    int localid;
    int profileid;
    int extra0;
    int extra1;
    void *userdata;
    void *callback;
} serverreq_t;

#include "gsplatformsocket.h"
#include "gsmemory.h"
#include "../arm9/msl_string_mem.h"
#include "../arm9/msl_string_str.h"
#include "../arm9/msl_strtod.h"
struct DArrayImplementation;
extern void ArrayFree(struct DArrayImplementation *array);
struct bucketset_s;
#include "gbucket.h"
#include "../arm9/os_printf.h"

void CloseStatsConnection(void);
int IsStatsConnected(void);
int PersistThink(void);
void xcode_buf(char *buf, int len);
char *value_for_key(char *s, char *key);
char *value_for_key_safe(char *s, char *key);
int PersistCanReceiveOnSocket(int sock);
char *FindFinal(char *buff, int len);
int FindRequest(int reqtype, int localid, int profileid);
void ProcessPlayerAuth(char *buf, int len);
void ProcessGetPid(char *buf, int len);
void ProcessGetData(char *buf, int len);
void ProcessSetData(char *buf, int len);
void ProcessStatement(char *buff, int len);
int ProcessInBuffer(char *buff, int len);
void CallReqCallback(int reqindex, int success, long modified, char *data, int length);
void ClosePendingCallbacks(void);
int GetTeamIndex(int *game, int tnum);
int GetPlayerIndex(int *game, int pnum);
int ServerOpInt(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index);
double ServerOpFloat(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index);
void *ServerOpString(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index);
void TeamOpInt(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index);
double TeamOpFloat(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index);
void TeamOpString(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index);
void PlayerOpInt(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index);
double PlayerOpFloat(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index);
void PlayerOpString(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index);

extern struct StatsSocket gGstatsSocket;
extern struct StatsConn gGstatsConn;
extern char gGstatsNullKey[];
extern char gGstatsCryptKey[];
extern char gGstatsEmptyString[];
extern char gGstatsKeyBackslash[];
extern char gGstatsKeyPauthr[];
extern char gGstatsKeyLid[];
extern char gGstatsKeyErrmsg[];
extern char gGstatsKeyGetpidr[];
extern char gGstatsKeyGetpdr[];
extern char gGstatsKeyPid[];
extern char gGstatsKeyMod[];
extern char gGstatsKeyLength[];
extern char gGstatsKeyData[];
extern char gGstatsKeySetpdr[];
extern char gGstatsKeySecPauthr[];
extern char gGstatsKeySecGetpidr[];
extern char gGstatsKeySecGetpdr[];
extern char gGstatsKeySecSetpdr[];
extern char gGstatsValueBuffers[];
extern char gGstatsTeamOpFormat[];
extern char gGstatsPlayerOpFormat[];

/*
 * sdk:      PlayerOpString (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void PlayerOpString(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index)
{
    char buf[0x40];
    OS_SPrintf(buf, gGstatsPlayerOpFormat, name, GetPlayerIndex(game, index));
    ServerOpString(game, buf, func, value, index);
}

double PlayerOpFloat(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index)
{
    char fullname[64];

    OS_SPrintf(fullname, gGstatsPlayerOpFormat, name, GetPlayerIndex(game, index));
    return ServerOpFloat(game, fullname, func, value, index);
}

/*
 * sdk:      PlayerOpInt (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void PlayerOpInt(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index)
{
    char buf[0x40];
    OS_SPrintf(buf, gGstatsPlayerOpFormat, name, GetPlayerIndex(game, index));
    ServerOpInt(game, buf, func, value, index);
}

/*
 * sdk:      TeamOpString (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void TeamOpString(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index)
{
    char buf[0x40];
    OS_SPrintf(buf, gGstatsTeamOpFormat, name, GetTeamIndex(game, index));
    ServerOpString(game, buf, func, value, index);
}

/*
 * sdk:      TeamOpFloat (gstats.o)
 */
double TeamOpFloat(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index)
{
    char fullname[64];

    OS_SPrintf(fullname, gGstatsTeamOpFormat, name, GetTeamIndex(game, index));
    return ServerOpFloat(game, fullname, func, value, index);
}

/*
 * sdk:      TeamOpInt (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void TeamOpInt(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index)
{
    char buf[0x40];
    OS_SPrintf(buf, gGstatsTeamOpFormat, name, GetTeamIndex(game, index));
    ServerOpInt(game, buf, func, value, index);
}

/*
 * sdk:      ServerOpString (gstats.o)
 */
void *ServerOpString(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index)
{
    void *ret;

    if (game == 0)
        game = gGstatsConn.game;
    if (game == 0)
        return value;
    ret = func((void *)game[3], name, value);
    if (ret != 0)
        return ret;
    return BucketNew((void *)game[3], name, 2, value);
}

/*
 * sdk:      ServerOpFloat (gstats.o)
 */
double ServerOpFloat(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index)
{
    double *ret;

    if (game == 0)
        game = gGstatsConn.game;
    if (game == 0)
        ret = &value;
    else {
        ret = func((void *)game[3], name, &value);
        if (ret == 0)
            ret = BucketNew((void *)game[3], name, 1, &value);
    }
    return *ret;
}

/*
 * sdk:      ServerOpInt (gstats.o)
 */
int ServerOpInt(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index)
{
    int *ret;

    if (game == 0)
        game = gGstatsConn.game;
    if (game == 0)
        ret = &value;
    else {
        ret = func((void *)game[3], name, &value);
        if (ret == 0)
            ret = BucketNew((void *)game[3], name, 0, &value);
    }
    return *ret;
}

/*
 * sdk:      GetPlayerIndex (gstats.o)
 */
int GetPlayerIndex(int *game, int pnum)
{
    if (game == 0)
        game = gGstatsConn.game;
    if (game == 0)
        return pnum;
    return *(int *)ArrayNth((void *)game[7], pnum);
}

/*
 * sdk:      GetTeamIndex (gstats.o)
 */
int GetTeamIndex(int *game, int tnum)
{
    if (game == 0)
        game = gGstatsConn.game;
    if (game == 0)
        return tnum;
    return *(int *)ArrayNth((void *)game[8], tnum);
}

/*
 * sdk:      ClosePendingCallbacks (gstats.o)
 *
 * Byte-correct (224/224); the connerror\ninitializer copies from the vendor template @14079 at 0x021A1A54 in ov009 data,\nattested by the `template` class (unique in ov009).\nA struct copy from an extern spelling was tried: one copy instead of two, DIFF.
 */
void ClosePendingCallbacks(void)
{
    int i;

    if (gGstatsConn.requests == 0)
        return;
    for (i = ArrayLength(gGstatsConn.requests) - 1; i >= 0; i--) {
        char connerror[16] = {0x13, 0x1d, 0x01, 0x04, 0, 0, 0, 0x28, 0x1f, 0x06, 0x45, 0x34, 0x3f, 0x01, 0x1b, 0};
        gGstatsSocket.key = gGstatsCryptKey;
        xcode_buf(connerror, 15);
        CallReqCallback(i, 0, 0, connerror, 0);
    }
    ArrayFree(gGstatsConn.requests);
    gGstatsConn.requests = 0;
}

/*
 * sdk:      CallReqCallback (gstats.o)
 */
void CallReqCallback(int reqindex, int success, long modified, char *data, int length)
{
    serverreq_t *req;

    if (reqindex < 0 || reqindex >= ArrayLength(gGstatsConn.requests))
        return;
    req = (serverreq_t *)ArrayNth(gGstatsConn.requests, reqindex);
    if (req->callback != 0) {
        switch (req->type) {
        case 0:
            ((void (*)(int, int, int, char *, void *))req->callback)(req->localid, req->profileid, success, data, req->userdata);
            break;
        case 1:
            ((void (*)(int, int, int, int, int, long, char *, int, void *))req->callback)(req->localid, req->profileid, req->extra0, req->extra1, success, modified, data, length, req->userdata);
            break;
        case 2:
            ((void (*)(int, int, int, int, int, long, void *))req->callback)(req->localid, req->profileid, req->extra0, req->extra1, success, modified, req->userdata);
            break;
        case 3:
            ((void (*)(int, int, int, void *))req->callback)(req->localid, req->profileid, success, req->userdata);
            break;
        }
    }
    ArrayDeleteAt(gGstatsConn.requests, reqindex);
}

/*
 * sdk:      ProcessInBuffer (gstats.o)
 */
int ProcessInBuffer(char *buff, int len)
{
    char *pos;
    int oldlen;

    oldlen = len;
    pos = FindFinal(buff, len);

    while (len > 0 && pos != 0) {
        gGstatsSocket.key = gGstatsNullKey;
        xcode_buf(buff, pos - buff);
        ProcessStatement(buff, pos - buff);
        len -= (pos - buff) + 7;
        buff = pos + 7;
        if (len > 0)
            pos = FindFinal(buff, len);
    }
    return oldlen - len;
}

/*
 * sdk:      ProcessStatement (gstats.o)
 */
void ProcessStatement(char *buff, int len)
{
    buff[len] = 0;
    if (strncmp(buff, gGstatsKeySecPauthr, 8) == 0)
        ProcessPlayerAuth(buff, len);
    else if (strncmp(buff, gGstatsKeySecGetpidr, 9) == 0)
        ProcessGetPid(buff, len);
    else if (strncmp(buff, gGstatsKeySecGetpidr, 9) == 0)
        ProcessGetPid(buff, len);
    else if (strncmp(buff, gGstatsKeySecGetpdr, 8) == 0)
        ProcessGetData(buff, len);
    else if (strncmp(buff, gGstatsKeySecSetpdr, 8) == 0)
        ProcessSetData(buff, len);
}

/*
 * sdk:      ProcessSetData (gstats.o)
 */
void ProcessSetData(char *buf, int len)
{
    int success;
    int pid;
    int lid;
    int modified;
    int reqindex;

    success = atoi(value_for_key_safe(buf, gGstatsKeySetpdr));
    pid = atoi(value_for_key_safe(buf, gGstatsKeyPid));
    lid = atoi(value_for_key_safe(buf, gGstatsKeyLid));
    modified = atoi(value_for_key_safe(buf, gGstatsKeyMod));
    reqindex = FindRequest(2, lid, pid);
    if (reqindex == -1)
        return;
    CallReqCallback(reqindex, success, modified, 0, 0);
}

/*
 * sdk:      ProcessGetData (gstats.o)
 */
void ProcessGetData(char *buf, int len)
{
    int reqindex;
    int pid;
    int lid;
    int success;
    int length;
    long modified;
    char *data;

    success = atoi(value_for_key_safe(buf, gGstatsKeyGetpdr));
    lid = atoi(value_for_key_safe(buf, gGstatsKeyLid));
    pid = atoi(value_for_key_safe(buf, gGstatsKeyPid));
    modified = atoi(value_for_key_safe(buf, gGstatsKeyMod));
    reqindex = FindRequest(1, lid, pid);
    if (reqindex == -1)
        return;
    length = atoi(value_for_key_safe(buf, gGstatsKeyLength));
    data = (char *)strstr(buf, gGstatsKeyData);
    if (data == 0) {
        data = gGstatsEmptyString;
        length = 0;
    } else
        data += 6;
    CallReqCallback(reqindex, success, modified, data, length);
}

/*
 * sdk:      ProcessGetPid (gstats.o)
 */
void ProcessGetPid(char *buf, int len)
{
    int lid;
    int pid;
    int reqindex;

    pid = atoi(value_for_key_safe(buf, gGstatsKeyGetpidr));
    lid = atoi(value_for_key_safe(buf, gGstatsKeyLid));
    reqindex = FindRequest(3, lid, 0);
    if (reqindex == -1)
        return;
    ((int *)ArrayNth(gGstatsConn.requests, reqindex))[2] = pid;
    CallReqCallback(reqindex, pid > 0, 0, 0, 0);
}

/*
 * sdk:      ProcessPlayerAuth (gstats.o)
 */
void ProcessPlayerAuth(char *buf, int len)
{
    int reqindex;
    char *errmsg;
    int pid;
    int lid;

    pid = atoi(value_for_key_safe(buf, gGstatsKeyPauthr));
    lid = atoi(value_for_key_safe(buf, gGstatsKeyLid));
    errmsg = value_for_key_safe(buf, gGstatsKeyErrmsg);
    reqindex = FindRequest(0, lid, 0);
    if (reqindex == -1)
        return;
    ((int *)ArrayNth(gGstatsConn.requests, reqindex))[2] = pid;
    CallReqCallback(reqindex, pid > 0, 0, errmsg, 0);
}

/*
 * sdk:      FindRequest (gstats.o)
 */
int FindRequest(int reqtype, int localid, int profileid)
{
    int *req;
    int i;

    if (gGstatsConn.requests == 0)
        return -1;
    for (i = 0; i < ArrayLength(gGstatsConn.requests); i++) {
        req = ArrayNth(gGstatsConn.requests, i);
        if (req[0] == reqtype && req[1] == localid && req[2] == profileid)
            return i;
    }
    return -1;
}

/*
 * sdk:      FindFinal (gstats.o)
 */
char *FindFinal(char *buff, int len)
{
    char *pos = buff;

    while (pos - buff < len - 6) {
        if (pos[0] == 0x5c && pos[1] == 'f' && pos[2] == 'i' && pos[3] == 'n' &&
            pos[4] == 'a' && pos[5] == 'l' && pos[6] == 0x5c)
            return pos;
        pos++;
    }
    return 0;
}

/*
 * Tail-call wrapper: the image spells it `ldr ip, [pc]; bx ip; .word
 * target`, which this compiler emits for a tail call to a callee whose
 * address has to come from a pool.
 */
int PersistCanReceiveOnSocket(int sock)
{
    return CanReceiveOnSocket(sock);
}

/*
 * The module block when the test passes, else the fallback object.
 */
char *value_for_key_safe(char *s, char *key)
{
    char *p = value_for_key(s, key);

    return p ? p : gGstatsEmptyString;
}

/*
 * sdk:      value_for_key (gstats.o)
 *
 * value_for_key. The keyspec initializer is the vendor template @13818 at 0x021A1A64
 * (template class, overlay scope). strcat 0x020948B0 attests as matched through
 * unit_02094860, whose functions list names strcat since 2026-09-29 (w4_nm).
 */
char *value_for_key(char *s, char *key)
{
    char keyspec[256] = "\\";
    char *pos;
    char *pos2;
    char *value;

    gGstatsConn.bufIndex ^= 1;
    strcat((u8 *)keyspec, (const u8 *)key);
    strcat((u8 *)keyspec, (const u8 *)gGstatsKeyBackslash);
    pos = (char *)strstr(s, keyspec);
    if (pos == 0)
        return 0;
    pos += strlen(keyspec);
    value = gGstatsValueBuffers + gGstatsConn.bufIndex * 256;
    pos2 = value;
    while (*pos != 0 && *pos != 0x5c)
        *pos2++ = *pos++;
    *pos2 = 0;
    return value;
}

/*
 * sdk:      xcode_buf (gstats.o)
 */
void xcode_buf(char *buf, int len)
{
    int i;
    char *pos;

    pos = gGstatsSocket.key;
    for (i = 0; i < len; i++) {
        buf[i] ^= *pos;
        pos++;
        if (*pos == 0)
            pos = gGstatsSocket.key;
    }
}

/*
 * sdk:      PersistThink (libdwcgsgstats.TWL.HYB.a gstats.o)
 */
int PersistThink(void)
{
    int processed;
    int len;

    if (gGstatsSocket.sock == -1)
        return 0;
    if (gGstatsConn.state != 5)
        return 0;
    while (PersistCanReceiveOnSocket(gGstatsSocket.sock)) {
        if (gGstatsConn.inSize - gGstatsConn.inLen < 0x80) {
            len = gGstatsConn.inSize;
            if (len < 0x100) {
                len = 0x100;
                gGstatsConn.inSize = len;
            } else {
                len = len * 2;
                gGstatsConn.inSize = len;
            }
            gGstatsConn.inBuff = (char *)gsirealloc(gGstatsConn.inBuff, len + 1);
            if (gGstatsConn.inBuff == 0)
                return 0;
        }
        len = recv(gGstatsSocket.sock, gGstatsConn.inBuff + gGstatsConn.inLen,
                            gGstatsConn.inSize - gGstatsConn.inLen, 0);
        if (len <= 0) {
            CloseStatsConnection();
            return 0;
        }
        gGstatsConn.inLen += len;
        gGstatsConn.inBuff[gGstatsConn.inLen] = 0;
        processed = ProcessInBuffer(gGstatsConn.inBuff, gGstatsConn.inLen);
        if (processed == gGstatsConn.inLen) {
            gGstatsConn.inLen = 0;
        } else {
            memmove(gGstatsConn.inBuff, gGstatsConn.inBuff + processed, gGstatsConn.inLen - processed);
            gGstatsConn.inLen -= processed;
        }
    }
    if (gGstatsSocket.sock == -1)
        return 0;
    return 1;
}

/*
 * Set while the word at +4 of the state object is not -1.
 */
int IsStatsConnected(void)
{
    return gGstatsSocket.sock != -1;
}

/*
 * sdk:      CloseStatsConnection (gstats.o)
 */
void CloseStatsConnection(void)
{
    if (gGstatsSocket.sock != -1) {
        shutdown(gGstatsSocket.sock, 2);
        closesocket(gGstatsSocket.sock);
    }
    gGstatsSocket.sock = -1;
    ClosePendingCallbacks();
    if (gGstatsConn.inBuff != 0) {
        gsifree((void *)gGstatsConn.inBuff);
        gGstatsConn.inBuff = 0;
        gGstatsConn.inSize = 0;
        gGstatsConn.inLen = 0;
    }
}
