/*
 * function: func_0219C5B8
 * address:  0x0219C5B8
 * packet:   pkt_ov009_0219C5B8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      qr2_process_ip_verify (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * symbols:
 *   func_0217F264  0x0217F264  arm   ov009
 *   func_0219B628  0x0219B628  arm   ov009
 *   func_02094694  0x02094694  arm
 *
 * notes: DIFF, register allocation only: the image keeps i in r5 and
 * numDuplicates in r0, this source swaps them (17 differing lines, same
 * instructions otherwise). About 30 attempts at declaration and init order.
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
    SOCSockAddrIn addr;
    unsigned int challenge;
    unsigned int time;
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



extern unsigned int func_0217F264(void);
extern int func_0219B628(struct qr2_buffer_s *outbuf, int value);
extern int func_02094694(void);

int func_0219C5B8(qr2_implementation_s *qrec, struct qr2_buffer_s *buf, SOCSockAddrIn *sender)
{
    int i;
    unsigned int now;
    int firstFreeIndex;
    int numDuplicates;

    i = 0;
    numDuplicates = 0;
    now = func_0217F264();
    firstFreeIndex = -1;
    if (!(qrec->backendoptions & 0x80)) {
        func_0219B628(buf, 0);
        return 1;
    }
    for (i = 0; i < 200; i++) {
        if (firstFreeIndex == -1 && qrec->ipverify[i].addr.addr.addr == 0)
            firstFreeIndex = i;
        if (sender->addr.addr == qrec->ipverify[i].addr.addr.addr && sender->port == qrec->ipverify[i].addr.port)
            numDuplicates++;
    }
    if (numDuplicates > 5)
        return 0;
    if (firstFreeIndex == -1)
        return 0;
    qrec->ipverify[firstFreeIndex].addr = *sender;
    qrec->ipverify[firstFreeIndex].challenge =
        ((((unsigned int)func_02094694() << 16) | func_02094694()) >> 24 & 0xff) |
        ((((unsigned int)func_02094694() << 16) | func_02094694()) >> 8 & 0xff00) |
        ((((unsigned int)func_02094694() << 16) | func_02094694()) << 8 & 0xff0000) |
        ((((unsigned int)func_02094694() << 16) | func_02094694()) << 24 & 0xff000000);
    qrec->ipverify[firstFreeIndex].time = now;
    func_0219B628(buf, qrec->ipverify[firstFreeIndex].challenge);
    return 1;
}
