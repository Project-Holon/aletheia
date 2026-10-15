/*
 * function: qr2_check_send_heartbeat
 * address:  0x0219B350
 * packet:   pkt_ov009_0219B350
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_check_send_heartbeat (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   current_time  0x0217F264  arm   ov009
 *   gsDebugFormat  0x0217D254  arm   ov009
 *   send_heartbeat  0x0219CE58  arm   ov009
 *   send_keepalive  0x0219CDBC  arm   ov009
 *   g_021A7564     0x021A7564  data
 *   g_021A7578     0x021A7578  data
 *   g_021A75B8     0x021A75B8  data
 */

typedef struct SOCInAddr {
    unsigned int addr;
} SOCInAddr;

typedef struct SOCSockAddrIn {
    unsigned char len;
    unsigned char family;
    unsigned short port;
    SOCInAddr addr;
} SOCSockAddrIn;

struct qr2_buffer_s;
struct qr2_keybuffer_s;

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


extern unsigned int current_time(void);
extern int gsDebugFormat(int index, char *table, int mask, const char *fmt, ...);
extern void send_heartbeat(qr2_implementation_s *qrec, int statechanged);
extern void send_keepalive(qr2_implementation_s *qrec);
extern char g_021A7564[];
extern char g_021A7578[];
extern char g_021A75B8[];

void qr2_check_send_heartbeat(qr2_implementation_s *qrec)
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
        send_heartbeat(qrec, 3);
        qrec->listed_state++;
    } else if (qrec->userstatechangerequested && tc - qrec->lastheartbeat > 10000) {
        send_heartbeat(qrec, 1);
    } else if (tc - qrec->lastheartbeat > 60000 || qrec->lastheartbeat == 0 || tc < qrec->lastheartbeat) {
        send_heartbeat(qrec, 0);
    }
    if (current_time() - qrec->lastka > 20000)
        send_keepalive(qrec);
}
