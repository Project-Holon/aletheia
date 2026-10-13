/*
 * file:     gstats.c
 * unit:     yes
 * function: func_02193D00, func_02193D64, func_02193D80, func_02193EB8, func_02193F00, func_02193FD0, func_02193FE8, func_02193FF4, func_0219405C, func_021940DC, func_02194184, func_02194220, func_02194308, func_021943A4, func_02194494, func_0219451C, func_02194614, func_021946F4, func_02194724, func_02194754, func_021947C0, func_02194834, func_02194890, func_021948F0, func_02194954, func_021949B4, func_02194A14, func_02194A78
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
 *   func_0217EB9C 0x0217EB9C  arm
 *   func_0217EB2C 0x0217EB2C  arm
 *   func_02194614 0x02194614  arm
 *   func_0217EAE0 0x0217EAE0  arm
 *   g_021A57C8   0x021A57C8  data
 *   g_021ADFE0   0x021ADFE0  data
 *   func_02193FE8  0x02193fe8  arm   ov009
 *   func_0217EAC8  0x0217eac8  arm   ov009
 *   func_0217EC4C  0x0217ec4c  arm   ov009
 *   func_02194494  0x02194494  arm   ov009
 *   func_02092364  0x02092364  arm
 *   func_020948B0 0x020948B0  arm
 *   func_02094B20 0x02094B20  arm
 *   func_0209477C 0x0209477C  arm
 *   g_021A5894   0x021A5894  data
 *   g_021AE21C   0x021AE21C  data
 *   g_021A5890  0x021A5890  data
 *   @13818       0x021A1A64  data
 *   func_0217EF50 0x0217EF50 arm
 *   func_02184200 0x02184200  arm
 *   func_02184208 0x02184208  arm
 *   func_02193FD0 0x02193FD0  arm
 *   func_020964E0 0x020964E0  arm
 *   g_021A5898   0x021A5898  data
 *   g_021A58A0   0x021A58A0  data
 *   g_021A58A4   0x021A58A4  data
 *   g_021A58AC   0x021A58AC  data
 *   g_021A58B4   0x021A58B4  data
 *   g_021A58BC   0x021A58BC  data
 *   g_021A58C0   0x021A58C0  data
 *   g_021A58C4   0x021A58C4  data
 *   g_021A58CC   0x021A58CC  data
 *   g_021A5890   0x021A5890  data
 *   g_021A58D4   0x021A58D4  data
 *   func_020949F4 0x020949F4  arm
 *   g_021A58DC   0x021A58DC  data
 *   g_021A58E8   0x021A58E8  data
 *   g_021A58F4   0x021A58F4  data
 *   g_021A5900   0x021A5900  data
 *   func_02193EB8 0x02193EB8  arm
 *   g_021A57F0   0x021A57F0  data
 *   func_0218437C 0x0218437C  arm
 *   func_021841B0 0x021841B0  arm
 *   @14079       0x021A1A54  data
 *   g_021A5800   0x021A5800  data
 *   func_021937D0 0x021937D0  arm
 *   func_02084F40  0x02084F40  arm
 *   d_021A590C     0x021A590C  data  a4
 *   OS_SPrintf   0x02084F40  arm
 *   g_021A590C   0x021A590C  data
 *   d_021A5914     0x021A5914  data  a4
 *   g_021A5914   0x021A5914  data
 */
#include "../../matched/include/G_StatsSocket.h"

typedef unsigned char  u8;
typedef unsigned int   u32;

struct StatsConn {
    int pad0[2];
    int inLen;
    int pad1[3];
    int inSize;
    int pad2;
    int bufIndex;
    int pad3;
    char *inBuff;
    int state;
};

typedef struct {
    int type;
    int localid;
    int profileid;
    int extra0;
    int extra1;
    void *userdata;
    void *callback;
} serverreq_t;

extern int func_0217EB9C(int sock, int how);
extern int func_0217EB2C(int sock);
extern void func_0217EAE0(void *ptr);
extern void *func_0217EAC8(void *ptr, unsigned long size);
extern int func_0217EC4C(int sock, char *buf, int len, int flags);
extern int func_0217EF50(int sock);
extern void *func_02092364(void *dest, const void *src, unsigned int n);
extern u8 *func_020948B0(u8 *dest, const u8 *src);
extern char *func_02094B20(const char *s, const char *sub);
extern int func_0209477C(const u8 *s);
extern int func_02184200(const int *p);
extern int *func_02184208(void *array, int n);
extern int func_020964E0(u32 a0);
extern int func_020949F4(const u8 *s1, const u8 *s2, u32 n);
extern void func_0218437C(int a, int b);
extern void func_021841B0(void *array);
extern void *func_021937D0(void *set, char *name, int type, void *initialvalue);
extern void func_02084F40(char *buf, const char *fmt, char *b, int n);
extern int OS_SPrintf(char *dst, const char *fmt, ...);

void func_02193D00(void);
int func_02193D64(void);
int func_02193D80(void);
void func_02193EB8(char *buf, int len);
char *func_02193F00(char *s, char *key);
char *func_02193FD0(char *s, char *key);
int func_02193FE8(int sock);
char *func_02193FF4(char *buff, int len);
int func_0219405C(int reqtype, int localid, int profileid);
void func_021940DC(char *buf, int len);
void func_02194184(char *buf, int len);
void func_02194220(char *buf, int len);
void func_02194308(char *buf, int len);
void func_021943A4(char *buff, int len);
int func_02194494(char *buff, int len);
void func_0219451C(int reqindex, int success, long modified, char *data, int length);
void func_02194614(void);
int func_021946F4(int *game, int tnum);
int func_02194724(int *game, int pnum);
int func_02194754(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index);
double func_021947C0(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index);
void *func_02194834(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index);
void func_02194890(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index);
double func_021948F0(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index);
void func_02194954(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index);
void func_021949B4(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index);
double func_02194A14(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index);
void func_02194A78(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index);

extern struct StatsSocket g_021A57C8;
extern struct StatsConn g_021ADFE0;
extern char g_021A57F0[];
extern char g_021A5800[];
extern char g_021A5890[];
extern char g_021A5894[];
extern char g_021A5898[];
extern char g_021A58A0[];
extern char g_021A58A4[];
extern char g_021A58AC[];
extern char g_021A58B4[];
extern char g_021A58BC[];
extern char g_021A58C0[];
extern char g_021A58C4[];
extern char g_021A58CC[];
extern char g_021A58D4[];
extern char g_021A58DC[];
extern char g_021A58E8[];
extern char g_021A58F4[];
extern char g_021A5900[];
extern char g_021AE21C[];
extern char d_021A590C[];
extern char g_021A590C[];
extern char d_021A5914[];
extern char g_021A5914[];


/*
 * sdk:      PlayerOpString (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void func_02194A78(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index)
{
    char buf[0x40];
    func_02084F40(buf, d_021A5914, name, func_02194724(game, index));
    func_02194834(game, buf, func, value, index);
}

double func_02194A14(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index)
{
    char fullname[64];

    OS_SPrintf(fullname, g_021A5914, name, func_02194724(game, index));
    return func_021947C0(game, fullname, func, value, index);
}

/*
 * sdk:      PlayerOpInt (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void func_021949B4(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index)
{
    char buf[0x40];
    func_02084F40(buf, d_021A5914, name, func_02194724(game, index));
    func_02194754(game, buf, func, value, index);
}

/*
 * sdk:      TeamOpString (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void func_02194954(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index)
{
    char buf[0x40];
    func_02084F40(buf, d_021A590C, name, func_021946F4(game, index));
    func_02194834(game, buf, func, value, index);
}

/*
 * sdk:      TeamOpFloat (gstats.o)
 */
double func_021948F0(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index)
{
    char fullname[64];

    OS_SPrintf(fullname, g_021A590C, name, func_021946F4(game, index));
    return func_021947C0(game, fullname, func, value, index);
}

/*
 * sdk:      TeamOpInt (libdwcgsgstats.TWL.HYB.a(gstats.o))
 */
void func_02194890(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index)
{
    char buf[0x40];
    func_02084F40(buf, d_021A590C, name, func_021946F4(game, index));
    func_02194754(game, buf, func, value, index);
}

/*
 * sdk:      ServerOpString (gstats.o)
 */
void *func_02194834(int *game, char *name, void *(*func)(void *, char *, void *), void *value, int index)
{
    void *ret;

    if (game == 0)
        game = (int *)((int *)&g_021ADFE0)[3];
    if (game == 0)
        return value;
    ret = func((void *)game[3], name, value);
    if (ret != 0)
        return ret;
    return func_021937D0((void *)game[3], name, 2, value);
}

/*
 * sdk:      ServerOpFloat (gstats.o)
 */
double func_021947C0(int *game, char *name, double *(*func)(void *, char *, void *), double value, int index)
{
    double *ret;

    if (game == 0)
        game = (int *)((int *)&g_021ADFE0)[3];
    if (game == 0)
        ret = &value;
    else {
        ret = func((void *)game[3], name, &value);
        if (ret == 0)
            ret = func_021937D0((void *)game[3], name, 1, &value);
    }
    return *ret;
}

/*
 * sdk:      ServerOpInt (gstats.o)
 */
int func_02194754(int *game, char *name, int *(*func)(void *, char *, void *), int value, int index)
{
    int *ret;

    if (game == 0)
        game = (int *)((int *)&g_021ADFE0)[3];
    if (game == 0)
        ret = &value;
    else {
        ret = func((void *)game[3], name, &value);
        if (ret == 0)
            ret = func_021937D0((void *)game[3], name, 0, &value);
    }
    return *ret;
}

/*
 * sdk:      GetPlayerIndex (gstats.o)
 */
int func_02194724(int *game, int pnum)
{
    if (game == 0)
        game = (int *)((int *)&g_021ADFE0)[3];
    if (game == 0)
        return pnum;
    return *(int *)func_02184208((void *)game[7], pnum);
}

/*
 * sdk:      GetTeamIndex (gstats.o)
 */
int func_021946F4(int *game, int tnum)
{
    if (game == 0)
        game = (int *)((int *)&g_021ADFE0)[3];
    if (game == 0)
        return tnum;
    return *(int *)func_02184208((void *)game[8], tnum);
}

/*
 * sdk:      ClosePendingCallbacks (gstats.o)
 *
 * Byte-correct (224/224); the connerror\ninitializer copies from the vendor template @14079 at 0x021A1A54 in ov009 data,\nattested by the `template` class (unique in ov009).\nA struct copy from an extern spelling was tried: one copy instead of two, DIFF.
 */
void func_02194614(void)
{
    int i;

    if (((int *)&g_021ADFE0)[5] == 0)
        return;
    for (i = func_02184200((void *)((int *)&g_021ADFE0)[5]) - 1; i >= 0; i--) {
        char connerror[16] = {0x13, 0x1d, 0x01, 0x04, 0, 0, 0, 0x28, 0x1f, 0x06, 0x45, 0x34, 0x3f, 0x01, 0x1b, 0};
        (*(char * *)&g_021A57C8) = g_021A5800;
        func_02193EB8(connerror, 15);
        func_0219451C(i, 0, 0, connerror, 0);
    }
    func_021841B0((void *)((int *)&g_021ADFE0)[5]);
    ((int *)&g_021ADFE0)[5] = 0;
}

/*
 * sdk:      CallReqCallback (gstats.o)
 */
void func_0219451C(int reqindex, int success, long modified, char *data, int length)
{
    serverreq_t *req;

    if (reqindex < 0 || reqindex >= func_02184200((void *)((int *)&g_021ADFE0)[5]))
        return;
    req = (serverreq_t *)func_02184208((void *)((int *)&g_021ADFE0)[5], reqindex);
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
    func_0218437C((int)((void *)((int *)&g_021ADFE0)[5]), reqindex);
}

/*
 * sdk:      ProcessInBuffer (gstats.o)
 */
int func_02194494(char *buff, int len)
{
    char *pos;
    int oldlen;

    oldlen = len;
    pos = func_02193FF4(buff, len);

    while (len > 0 && pos != 0) {
        (*(char * *)&g_021A57C8) = g_021A57F0;
        func_02193EB8(buff, pos - buff);
        func_021943A4(buff, pos - buff);
        len -= (pos - buff) + 7;
        buff = pos + 7;
        if (len > 0)
            pos = func_02193FF4(buff, len);
    }
    return oldlen - len;
}

/*
 * sdk:      ProcessStatement (gstats.o)
 */
void func_021943A4(char *buff, int len)
{
    buff[len] = 0;
    if (func_020949F4((const u8 *)buff, (const u8 *)g_021A58DC, 8) == 0)
        func_021940DC(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)g_021A58E8, 9) == 0)
        func_02194184(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)g_021A58E8, 9) == 0)
        func_02194184(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)g_021A58F4, 8) == 0)
        func_02194220(buff, len);
    else if (func_020949F4((const u8 *)buff, (const u8 *)g_021A5900, 8) == 0)
        func_02194308(buff, len);
}

/*
 * sdk:      ProcessSetData (gstats.o)
 */
void func_02194308(char *buf, int len)
{
    int success;
    int pid;
    int lid;
    int modified;
    int reqindex;

    success = func_020964E0((u32)func_02193FD0(buf, g_021A58D4));
    pid = func_020964E0((u32)func_02193FD0(buf, g_021A58BC));
    lid = func_020964E0((u32)func_02193FD0(buf, g_021A58A0));
    modified = func_020964E0((u32)func_02193FD0(buf, g_021A58C0));
    reqindex = func_0219405C(2, lid, pid);
    if (reqindex == -1)
        return;
    func_0219451C(reqindex, success, modified, 0, 0);
}

/*
 * sdk:      ProcessGetData (gstats.o)
 */
void func_02194220(char *buf, int len)
{
    int reqindex;
    int pid;
    int lid;
    int success;
    int length;
    long modified;
    char *data;

    success = func_020964E0((u32)func_02193FD0(buf, g_021A58B4));
    lid = func_020964E0((u32)func_02193FD0(buf, g_021A58A0));
    pid = func_020964E0((u32)func_02193FD0(buf, g_021A58BC));
    modified = func_020964E0((u32)func_02193FD0(buf, g_021A58C0));
    reqindex = func_0219405C(1, lid, pid);
    if (reqindex == -1)
        return;
    length = func_020964E0((u32)func_02193FD0(buf, g_021A58C4));
    data = func_02094B20(buf, g_021A58CC);
    if (data == 0) {
        data = g_021A5890;
        length = 0;
    } else
        data += 6;
    func_0219451C(reqindex, success, modified, data, length);
}

/*
 * sdk:      ProcessGetPid (gstats.o)
 */
void func_02194184(char *buf, int len)
{
    int lid;
    int pid;
    int reqindex;

    pid = func_020964E0((u32)func_02193FD0(buf, g_021A58AC));
    lid = func_020964E0((u32)func_02193FD0(buf, g_021A58A0));
    reqindex = func_0219405C(3, lid, 0);
    if (reqindex == -1)
        return;
    func_02184208((void *)((int *)&g_021ADFE0)[5], reqindex)[2] = pid;
    func_0219451C(reqindex, pid > 0, 0, 0, 0);
}

/*
 * sdk:      ProcessPlayerAuth (gstats.o)
 */
void func_021940DC(char *buf, int len)
{
    int reqindex;
    char *errmsg;
    int pid;
    int lid;

    pid = func_020964E0((u32)func_02193FD0(buf, g_021A5898));
    lid = func_020964E0((u32)func_02193FD0(buf, g_021A58A0));
    errmsg = func_02193FD0(buf, g_021A58A4);
    reqindex = func_0219405C(0, lid, 0);
    if (reqindex == -1)
        return;
    func_02184208((void *)((int *)&g_021ADFE0)[5], reqindex)[2] = pid;
    func_0219451C(reqindex, pid > 0, 0, errmsg, 0);
}

/*
 * sdk:      FindRequest (gstats.o)
 */
int func_0219405C(int reqtype, int localid, int profileid)
{
    int *req;
    int i;

    if (((int *)&g_021ADFE0)[5] == 0)
        return -1;
    for (i = 0; i < func_02184200((void *)((int *)&g_021ADFE0)[5]); i++) {
        req = func_02184208((void *)((int *)&g_021ADFE0)[5], i);
        if (req[0] == reqtype && req[1] == localid && req[2] == profileid)
            return i;
    }
    return -1;
}

/*
 * sdk:      FindFinal (gstats.o)
 */
char *func_02193FF4(char *buff, int len)
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
int func_02193FE8(int sock)
{
    return func_0217EF50(sock);
}

/*
 * The module block when the test passes, else the fallback object.
 */
char *func_02193FD0(char *s, char *key)
{
    char *p = func_02193F00(s, key);

    return p ? p : g_021A5890;
}

/*
 * sdk:      value_for_key (gstats.o)
 *
 * value_for_key. The keyspec initializer is the vendor template @13818 at 0x021A1A64
 * (template class, overlay scope). strcat 0x020948B0 attests as matched through
 * unit_02094860, whose functions list names func_020948B0 since 2026-09-29 (w4_nm).
 */
char *func_02193F00(char *s, char *key)
{
    char keyspec[256] = "\\";
    char *pos;
    char *pos2;
    char *value;

    g_021ADFE0.bufIndex ^= 1;
    func_020948B0((u8 *)keyspec, (const u8 *)key);
    func_020948B0((u8 *)keyspec, (const u8 *)g_021A5894);
    pos = func_02094B20(s, keyspec);
    if (pos == 0)
        return 0;
    pos += func_0209477C((const u8 *)keyspec);
    value = g_021AE21C + g_021ADFE0.bufIndex * 256;
    pos2 = value;
    while (*pos != 0 && *pos != 0x5c)
        *pos2++ = *pos++;
    *pos2 = 0;
    return value;
}

/*
 * sdk:      xcode_buf (gstats.o)
 */
void func_02193EB8(char *buf, int len)
{
    int i;
    char *pos;

    pos = (*(char * *)&g_021A57C8);
    for (i = 0; i < len; i++) {
        buf[i] ^= *pos;
        pos++;
        if (*pos == 0)
            pos = (*(char * *)&g_021A57C8);
    }
}

/*
 * sdk:      PersistThink (libdwcgsgstats.TWL.HYB.a gstats.o)
 */
int func_02193D80(void)
{
    int processed;
    int len;

    if (g_021A57C8.sock == -1)
        return 0;
    if (g_021ADFE0.state != 5)
        return 0;
    while (func_02193FE8(g_021A57C8.sock)) {
        if (g_021ADFE0.inSize - g_021ADFE0.inLen < 0x80) {
            len = g_021ADFE0.inSize;
            if (len < 0x100) {
                len = 0x100;
                g_021ADFE0.inSize = len;
            } else {
                len = len * 2;
                g_021ADFE0.inSize = len;
            }
            g_021ADFE0.inBuff = (char *)func_0217EAC8(g_021ADFE0.inBuff, len + 1);
            if (g_021ADFE0.inBuff == 0)
                return 0;
        }
        len = func_0217EC4C(g_021A57C8.sock, g_021ADFE0.inBuff + g_021ADFE0.inLen,
                            g_021ADFE0.inSize - g_021ADFE0.inLen, 0);
        if (len <= 0) {
            func_02193D00();
            return 0;
        }
        g_021ADFE0.inLen += len;
        g_021ADFE0.inBuff[g_021ADFE0.inLen] = 0;
        processed = func_02194494(g_021ADFE0.inBuff, g_021ADFE0.inLen);
        if (processed == g_021ADFE0.inLen) {
            g_021ADFE0.inLen = 0;
        } else {
            func_02092364(g_021ADFE0.inBuff, g_021ADFE0.inBuff + processed, g_021ADFE0.inLen - processed);
            g_021ADFE0.inLen -= processed;
        }
    }
    if (g_021A57C8.sock == -1)
        return 0;
    return 1;
}

/*
 * Set while the word at +4 of the state object is not -1.
 */
int func_02193D64(void)
{
    return *(int *)(((char *)&g_021A57C8) + 4) != -1;
}

/*
 * sdk:      CloseStatsConnection (gstats.o)
 */
void func_02193D00(void)
{
    if (((int *)&g_021A57C8)[1] != -1) {
        func_0217EB9C(((int *)&g_021A57C8)[1], 2);
        func_0217EB2C(((int *)&g_021A57C8)[1]);
    }
    ((int *)&g_021A57C8)[1] = -1;
    func_02194614();
    if (g_021ADFE0.inBuff != 0) {
        func_0217EAE0((void *)g_021ADFE0.inBuff);
        g_021ADFE0.inBuff = 0;
        g_021ADFE0.inSize = 0;
        g_021ADFE0.inLen = 0;
    }
}
