/*
 * file:     unit_0219AEB4_p06.c
 * unit:     yes
 * function: func_0219B228, func_0219B350
 * address:  0x0219B228
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
 *   func_0217EF50  0x0217EF50  arm   ov009
 *   func_0217EC60  0x0217EC60  arm   ov009
 *   func_0217D254  0x0217D254  arm   ov009
 *   func_0217D32C  0x0217D32C  arm   ov009
 *   func_0219C7C0  0x0219C7C0  arm   ov009
 *   func_0217ED54  0x0217ED54  arm   ov009
 *   g_021AE9F8     0x021AE9F8  data
 *   g_021A74AC     0x021A74AC  data
 *   g_021A74D0     0x021A74D0  data
 *   g_021A751C     0x021A751C  data
 *   func_0217F264  0x0217F264  arm   ov009
 *   func_0219CE58  0x0219CE58  arm   ov009
 *   func_0219CDBC  0x0219CDBC  arm   ov009
 *   g_021A7564     0x021A7564  data
 *   g_021A7578     0x021A7578  data
 *   g_021A75B8     0x021A75B8  data
 */
struct qr2_buffer_s;
struct qr2_keybuffer_s;
typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    SOCInAddr addr;
} SOCSockAddrIn;

typedef struct qr2_ipverify_info_s {
    unsigned int words[4];
} qr2_ipverify_info_s;

typedef struct qr2_implementation_s {
    int hbsock;
    char gamename[64];
    char secret_key[64];
    char instance_key[4];
    void (*server_key_callback)(int, struct qr2_buffer_s *, void *);
    void (*player_key_callback)(int, int, struct qr2_buffer_s *, void *);
    void (*team_key_callback)(int, int, struct qr2_buffer_s *, void *);
    void (*key_list_callback)(int, struct qr2_keybuffer_s *, void *);
    int (*playerteam_count_callback)(int, void *);
    void (*adderror_callback)(int, char *, void *);
    void (*nn_callback)(int, void *);
    void (*cm_callback)(char *, int, void *);
    void (*pa_callback)(unsigned int, unsigned short, void *);
    void (*cc_callback)(int, SOCSockAddrIn *, void *);
    void (*hr_callback)(void *);
    unsigned int lastheartbeat;
    unsigned int lastka;
    int userstatechangerequested;
    int listed_state;
    int ispublic;
    int qport;
    int read_socket;
    int nat_negotiate;
    SOCSockAddrIn hbaddr;
    void (*cdkeyprocess)(char *, int, void *);
    int client_message_keys[10];
    int cur_message_key;
    unsigned int publicip;
    unsigned short publicport;
    void *udata;
    unsigned char backendoptions;
    qr2_ipverify_info_s ipverify[200];
} qr2_implementation_s;

extern int func_0217EF50(int sock);
extern int func_0217EC60(int sock, char *buf, int len, int flags, SOCSockAddrIn *addr, int *fromlen);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217D32C(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength);
extern void func_0219C7C0(qr2_implementation_s *qrec, char *query, int len, SOCSockAddrIn *sender);
extern int func_0217ED54(int sock);
extern unsigned int func_0217F264(void);
extern void func_0219CE58(qr2_implementation_s *qrec, int statechanged);
extern void func_0219CDBC(qr2_implementation_s *qrec);
void func_0219B228(qr2_implementation_s *qrec);
void func_0219B350(qr2_implementation_s *qrec);
extern char g_021AE9F8[];
extern char g_021A74AC[];
extern char g_021A74D0[];
extern char g_021A751C[];
extern char g_021A7564[];
extern char g_021A7578[];
extern char g_021A75B8[];


/*
 * sdk:      qr2_check_queries (libdwcgsqr2.TWL.HYB.a qr2.o)
 */
void func_0219B228(qr2_implementation_s *qrec)
{
    SOCSockAddrIn saddr;
    int saddrlen = sizeof(SOCSockAddrIn);

    if (qrec->read_socket == 0)
        return;
    while (func_0217EF50(qrec->hbsock)) {
        int error = func_0217EC60(qrec->hbsock, g_021AE9F8, 255, 0, &saddr, &saddrlen);
        if (error != -1) {
            g_021AE9F8[error] = 0;
            func_0217D254(3, 0, 16, g_021A74AC, error);
            func_0217D32C(3, 0, 32, g_021AE9F8, error);
            func_0219C7C0(qrec, g_021AE9F8, error, &saddr);
        } else if (error == 0) {
            func_0217D254(3, 0, 16, g_021A74D0, error);
        } else {
            int error2 = func_0217ED54(qrec->hbsock);
            func_0217D254(3, 0, 16, g_021A751C, error2);
        }
    }
}


/*
 * sdk:      qr2_check_send_heartbeat (libdwcgsqr2.TWL.HYB.a qr2.o)
 */
void func_0219B350(qr2_implementation_s *qrec)
{
    unsigned int tc = func_0217F264();

    if (qrec->hbsock == -1) {
        func_0217D254(3, 0, 2, g_021A7564);
        return;
    }
    if (qrec->listed_state > 0 && tc - qrec->lastheartbeat > 10000) {
        if (qrec->listed_state >= 4) {
            func_0217D254(3, 0, 1, g_021A7578);
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
    if (func_0217F264() - qrec->lastka > 20000)
        func_0219CDBC(qrec);
}
