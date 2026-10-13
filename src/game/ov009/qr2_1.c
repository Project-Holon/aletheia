/*
 * file:     qr2_1.c
 * unit:     yes
 * function: func_0219AEB4, qr2_register_natneg_callback, qr2_register_clientmessage_callback, qr2_register_publicaddress_callback, qr2_think, func_0219B228, func_0219B350, qr2_send_statechanged, func_0219B540, func_0219B5EC, qr2_buffer_add_int, qr2_buffer_addA, enum_local_ips, func_0219B73C
 * address:  0x0219AEB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by hand (round 5, lane s06): one canonical qr2 type block in qr2_types.h.
 *
 * symbols:
 *   gsDebugFormat  0x0217D254  arm  ov009
 *   gsDebugBinary  0x0217D32C  arm  ov009
 *   gsimalloc      0x0217EAB0  arm  ov009
 *   gsifree        0x0217EAE0  arm  ov009
 *   closesocket    0x0217EB2C  arm  ov009
 *   recvfrom       0x0217EC60  arm  ov009
 *   inet_addr      0x0217ED38  arm  ov009
 *   GOAGetLastError  0x0217ED54  arm  ov009
 *   CanReceiveOnSocket  0x0217EF50  arm  ov009
 *   getlocalhost   0x0217EFB8  arm  ov009
 *   SocketShutDown  0x0217F260  arm  ov009
 *   current_time   0x0217F264  arm  ov009
 *   gsiSafeStrcpyA 0x021803BC  arm  ov009
 *   SOC_GetHostByName  0x0215F650  arm  ov009
 *   SOC_InetNtoA   0x0215FA9C  arm  ov009
 *   OS_SPrintf     0x02084F40  arm
 *   memcpy         0x02092344  arm
 *   memset         0x020923B0  arm
 *   rand           0x02094694  arm
 *   srand          0x020946C8  arm
 *   strlen         0x0209477C  arm
 *   strcmp         0x020948E0  arm
 *   NNFreeNegotiateList  0x0219922C  arm  ov009
 *   NNThink        0x0219A4A4  arm  ov009
 *   qr2_expire_ip_verify  0x0219C77C  arm  ov009
 *   func_0219C7C0  0x0219C7C0  arm  ov009
 *   func_0219CDBC  0x0219CDBC  arm  ov009
 *   func_0219CE58  0x0219CE58  arm  ov009
 *   current_rec    0x021A6600  data
 *   g_021A6604     0x021A6604  data
 *   g_021A73A0     0x021A73A0  data
 *   g_021A73B4     0x021A73B4  data
 *   g_021A73D4     0x021A73D4  data
 *   g_021A73E8     0x021A73E8  data
 *   g_021A7408     0x021A7408  data
 *   g_021A7438     0x021A7438  data
 *   g_021A745C     0x021A745C  data
 *   g_021A7484     0x021A7484  data
 *   g_021A74AC     0x021A74AC  data
 *   g_021A74D0     0x021A74D0  data
 *   g_021A751C     0x021A751C  data
 *   g_021A7564     0x021A7564  data
 *   g_021A7578     0x021A7578  data
 *   g_021A75B8     0x021A75B8  data
 *   g_021A75F0     0x021A75F0  data
 *   g_021A760C     0x021A760C  data
 *   g_021A7644     0x021A7644  data
 *   g_021A7674     0x021A7674  data
 *   g_021A7688     0x021A7688  data
 *   g_021A768C     0x021A768C  data
 *   num_local_ips  0x021AE9A0  data
 *   local_ip_list  0x021AE9A4  data
 *   g_021AE9B8     0x021AE9B8  data
 *   g_021AE9F8     0x021AE9F8  data
 */

#include "../../matched/arm9_sdk/libc/string.h"
#include "qr2_types.h"

extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern void gsDebugBinary(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength);
extern void *gsimalloc(unsigned long size);
extern void gsifree(void *ptr);
extern int closesocket(int sock);
extern int recvfrom(int sock, char *buf, int len, int flags, SOCSockAddr *addr, int *fromlen);
extern int inet_addr(int host);
extern int GOAGetLastError(int sock);
extern int CanReceiveOnSocket(int sock);
extern SOCHostEnt *getlocalhost(void);
extern void SocketShutDown(void);
extern unsigned int current_time(void);
extern int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
extern SOCHostEnt *SOC_GetHostByName(char *name);
extern char *SOC_InetNtoA(SOCInAddr in);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int rand(void);
extern void srand(unsigned int seed);
extern int strcmp(const char *a, const char *b);
extern void NNFreeNegotiateList(void);
extern void NNThink(void);
extern void qr2_expire_ip_verify(qr2_implementation_s *qrec);
extern void func_0219C7C0(qr2_implementation_s *qrec, char *query, int len, SOCSockAddr *sender);
extern void func_0219CDBC(qr2_implementation_s *qrec);
extern void func_0219CE58(qr2_implementation_s *qrec, int statechanged);

extern qr2_implementation_s *current_rec;
extern qr2_implementation_s g_021A6604;
extern char g_021A73A0[];
extern char g_021A73B4[];
extern char g_021A73D4[];
extern char g_021A73E8[];
extern char g_021A7408[];
extern char g_021A7438[];
extern char g_021A745C[];
extern char g_021A7484[];
extern char g_021A74AC[];
extern char g_021A74D0[];
extern char g_021A751C[];
extern char g_021A7564[];
extern char g_021A7578[];
extern char g_021A75B8[];
extern char g_021A75F0[];
extern char g_021A760C[];
extern char g_021A7644[];
extern char g_021A7674[];
extern char g_021A7688[];
extern char g_021A768C[];
extern int num_local_ips;
extern SOCInAddr local_ip_list[5];
extern char g_021AE9B8[64];
extern char g_021AE9F8[];

static void enum_local_ips(void);
void func_0219B228(qr2_implementation_s *qrec);
void func_0219B350(qr2_implementation_s *qrec);
int qr2_buffer_addA(qr2_buffer_s *outbuf, char *value);
int func_0219B73C(char *host, int port, SOCSockAddrIn *saddr, SOCHostEnt **savehent);

/*
 * sdk:      qr2_init_socketA (qr2.o)
 */
int func_0219AEB4(qr2_implementation_s **qrec, int s, int boundport, char *gamename, char *secret_key,
                  int ispublic, int natnegotiate,
                  void (*server_key_callback)(int, qr2_buffer_s *, void *),
                  void (*player_key_callback)(int, int, qr2_buffer_s *, void *),
                  void (*team_key_callback)(int, int, qr2_buffer_s *, void *),
                  void (*key_list_callback)(qr2_key_type, qr2_keybuffer_s *, void *),
                  int (*playerteam_count_callback)(qr2_key_type, void *),
                  void (*adderror_callback)(int, char *, void *),
                  void *userdata)
{
    char hostname[64];
    int ret;
    int i;
    qr2_implementation_s *cr;

    gsDebugFormat(3, 4, 0x40, g_021A73A0);

    if (qrec == 0) {
        cr = &g_021A6604;
    } else {
        *qrec = (qr2_implementation_s *)gsimalloc(sizeof(qr2_implementation_s));
        cr = *qrec;
    }
    srand(current_time());
    gsiSafeStrcpyA(cr->gamename, gamename, sizeof(cr->gamename));
    gsiSafeStrcpyA(cr->secret_key, secret_key, sizeof(cr->secret_key));
    cr->qport = boundport;
    cr->lastheartbeat = 0;
    cr->lastka = 0;
    cr->hbsock = s;
    cr->listed_state = 1;
    cr->udata = userdata;
    cr->server_key_callback = server_key_callback;
    cr->player_key_callback = player_key_callback;
    cr->team_key_callback = team_key_callback;
    cr->key_list_callback = key_list_callback;
    cr->playerteam_count_callback = playerteam_count_callback;
    cr->adderror_callback = adderror_callback;
    cr->nn_callback = 0;
    cr->cm_callback = 0;
    cr->cdkeyprocess = 0;
    cr->ispublic = ispublic;
    cr->read_socket = 0;
    cr->nat_negotiate = natnegotiate;
    cr->publicip = 0;
    cr->publicport = 0;
    cr->pa_callback = 0;
    cr->hr_callback = 0;
    cr->cc_callback = 0;
    cr->userstatechangerequested = 0;
    cr->backendoptions = 0;

    for (i = 0; i < 4; i++)
        cr->instance_key[i] = (char)(rand() % 0xFF);
    for (i = 0; i < 10; i++)
        cr->client_message_keys[i] = -1;
    cr->cur_message_key = 0;

    memset(cr->ipverify, 0, sizeof(cr->ipverify));

    enum_local_ips();

    if (ispublic) {
        int override = g_021AE9B8[0];
        if (!override)
            OS_SPrintf(hostname, g_021A73B4, gamename);
        ret = func_0219B73C(override ? g_021AE9B8 : hostname, 27900, &cr->hbaddr, 0);
        if (ret == 1)
            gsDebugFormat(3, 0, 0x10, g_021A73D4, override ? g_021AE9B8 : hostname, SOC_InetNtoA(cr->hbaddr.addr));
        else
            gsDebugFormat(3, 0, 1, g_021A73E8, override ? g_021AE9B8 : hostname);
    } else {
        ret = 1;
    }
    if (!ret) {
        gsDebugFormat(3, 4, 1, g_021A7408);
        return 3;
    }
    return 0;
}

void qr2_register_natneg_callback(qr2_implementation_s *qrec,
                                  void (*nncallback)(int, void *))
{
    gsDebugFormat(3, 4, 0x40, g_021A7438);
    if (qrec == 0)
        qrec = current_rec;
    qrec->nn_callback = nncallback;
}

void qr2_register_clientmessage_callback(qr2_implementation_s *qrec,
                                         void (*cmcallback)(char *, int, void *))
{
    gsDebugFormat(3, 4, 0x40, g_021A745C);
    if (qrec == 0)
        qrec = current_rec;
    qrec->cm_callback = cmcallback;
}

void qr2_register_publicaddress_callback(
    qr2_implementation_s *qrec,
    void (*pacallback)(unsigned int, unsigned short, void *))
{
    gsDebugFormat(3, 4, 0x40, g_021A7484);
    if (qrec == 0)
        qrec = current_rec;
    qrec->pa_callback = pacallback;
}

void qr2_think(qr2_implementation_s *qrec)
{
    if (qrec == 0)
        qrec = current_rec;
    if (qrec->ispublic != 0)
        func_0219B350(qrec);
    func_0219B228(qrec);
    qr2_expire_ip_verify(qrec);
    NNThink();
}

/*
 * sdk:      qr2_check_queries (libdwcgsqr2.TWL.HYB.a qr2.o)
 */
void func_0219B228(qr2_implementation_s *qrec)
{
    SOCSockAddrIn saddr;
    int saddrlen = sizeof(SOCSockAddrIn);

    if (qrec->read_socket == 0)
        return;
    while (CanReceiveOnSocket(qrec->hbsock)) {
        int error = recvfrom(qrec->hbsock, g_021AE9F8, 255, 0, (SOCSockAddr *)&saddr, &saddrlen);
        if (error != -1) {
            g_021AE9F8[error] = 0;
            gsDebugFormat(3, 0, 16, g_021A74AC, error);
            gsDebugBinary(3, 0, 32, g_021AE9F8, error);
            func_0219C7C0(qrec, g_021AE9F8, error, (SOCSockAddr *)&saddr);
        } else if (error == 0) {
            gsDebugFormat(3, 0, 16, g_021A74D0, error);
        } else {
            int error2 = GOAGetLastError(qrec->hbsock);
            gsDebugFormat(3, 0, 16, g_021A751C, error2);
        }
    }
}

/*
 * sdk:      qr2_check_send_heartbeat (libdwcgsqr2.TWL.HYB.a qr2.o)
 */
void func_0219B350(qr2_implementation_s *qrec)
{
    unsigned int tc = current_time();

    if (qrec->hbsock == -1) {
        gsDebugFormat(3, 0, 2, g_021A7564);
        return;
    }
    if (qrec->listed_state > 0 && tc - qrec->lastheartbeat > 10000) {
        if (qrec->listed_state >= 4) {
            gsDebugFormat(3, 0, 1, g_021A7578);
            qrec->listed_state = 0;
            qrec->adderror_callback(5, g_021A75B8, qrec->udata);
            return;
        }
        func_0219CE58(qrec, 3);
        qrec->listed_state++;
    } else if (qrec->userstatechangerequested && tc - qrec->lastheartbeat > 10000) {
        func_0219CE58(qrec, 1);
    } else if (tc - qrec->lastheartbeat > 60000 || qrec->lastheartbeat == 0 || tc < qrec->lastheartbeat) {
        func_0219CE58(qrec, 0);
    }
    if (current_time() - qrec->lastka > 20000)
        func_0219CDBC(qrec);
}

void qr2_send_statechanged(qr2_implementation_s *qrec)
{
    gsDebugFormat(3, 4, 0x40, g_021A75F0);
    if (qrec == 0)
        qrec = current_rec;
    if (qrec->ispublic == 0) {
        gsDebugFormat(3, 4, 4, g_021A760C);
        return;
    }
    if (current_time() - qrec->lastheartbeat < 0x2710) {
        gsDebugFormat(3, 4, 8, g_021A7644);
        qrec->userstatechangerequested = 1;
        return;
    }
    func_0219CE58(qrec, 1);
    qrec->userstatechangerequested = 0;
}

/*
 * sdk: qr2_shutdown (qr2.o)
 */
void func_0219B540(qr2_implementation_s *qrec)
{
    gsDebugFormat(3, 0, 0x40, g_021A7674);
    if (!qrec)
        qrec = current_rec;
    if (qrec->ispublic)
        func_0219CE58(qrec, 2);
    if (qrec->hbsock != -1 && qrec->read_socket)
        closesocket(qrec->hbsock);
    qrec->hbsock = -1;
    qrec->lastheartbeat = 0;
    if (qrec->read_socket)
        SocketShutDown();
    if (qrec->cc_callback)
        NNFreeNegotiateList();
    if (qrec != &g_021A6604)
        gsifree(qrec);
}

/*
 * sdk: qr2_keybuffer_add (qr2.o)
 *
 * Appends a key id to the key buffer while the count is under 0xfe and the
 * id is 1..0xfe; 0 when either bound is hit.
 */
int func_0219B5EC(qr2_keybuffer_s *keybuffer, int keyid)
{
    int n = keybuffer->numkeys;

    if (n >= 0xfe) return 0;
    if (keyid < 1 || keyid > 0xfe) return 0;
    keybuffer->numkeys = n + 1;
    keybuffer->keys[n] = keyid;
    return 1;
}

int qr2_buffer_add_int(qr2_buffer_s *outbuf, int value)
{
    char temp[20];

    OS_SPrintf(temp, g_021A7688, value);
    return qr2_buffer_addA(outbuf, temp);
}

int qr2_buffer_addA(qr2_buffer_s *outbuf, char *value)
{
    int copylen = strlen(value) + 1;

    if (copylen > 1400 - outbuf->len)
        copylen = 1400 - outbuf->len;
    if (copylen <= 0)
        return 0;
    memcpy(outbuf->buffer + outbuf->len, value, copylen);
    outbuf->len += copylen;
    outbuf->buffer[outbuf->len - 1] = 0;
    return 1;
}

/*
 * Closed (w4_nm): the address copy is memcpy(&local_ip_list[i], addr,
 * sizeof(SOCInAddr)) through string.h, which mwccarm inlines as the
 * 1-aligned ldrb/strb copy.
 */
static void enum_local_ips(void)
{
    SOCHostEnt *phost;
    int i;

    phost = getlocalhost();
    if (phost == 0)
        return;
    num_local_ips = 0;
    for (i = 0; i < 5; i++) {
        if (phost->addrList[i] == 0)
            return;
        memcpy(&local_ip_list[i], phost->addrList[i], sizeof(SOCInAddr));
        num_local_ips = i + 1;
    }
}

/*
 * sdk:      get_sockaddrin (TwlDWC/libdwcgsqr2.TWL.HYB.a(qr2.o))
 *
 * Fills a SOCSockAddrIn: len 0, family 2, byte-swapped port, then the address
 * (resolved by name, or from the host entry when the resolver fails and the
 * name matches g_021A768C).  Optionally hands the host entry back.
 *
 * The six byte stores that clear the port/address half of the struct are SIX
 * INDIVIDUAL STATEMENTS through an unsigned char *, not a loop and not a
 * memset: the image keeps them as six `strb`s (offsets 2..7, in that order,
 * with the port-swap `orr` scheduled into the middle) and both a byte loop
 * (which CW leaves rolled) and memset (a call) miss.  byte 0 and the family
 * byte are written afterwards, in that order.
 */
int func_0219B73C(char *host, int port, SOCSockAddrIn *saddr, SOCHostEnt **savehent)
{
    SOCHostEnt *hent = 0;
    unsigned char *p = (unsigned char *)saddr;

    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    saddr->len = 0;
    saddr->family = 2;
    saddr->port = (unsigned short)((((unsigned short)port >> 8) & 0xff) | (((unsigned short)port << 8) & 0xff00));
    if (host)
        saddr->addr.addr = inet_addr((int)host);
    else
        saddr->addr.addr = 0;
    if (saddr->addr.addr == 0xFFFFFFFF) {
        if (strcmp(host, g_021A768C) != 0) {
            hent = SOC_GetHostByName(host);
            if (!hent)
                return 0;
            saddr->addr.addr = *(unsigned int *)*hent->addrList;
        }
    }
    if (savehent)
        *savehent = hent;
    return 1;
}
