/*
 * function: send_heartbeat
 * address:  0x0219CE58
 * packet:   pkt_ov009_0219CE58
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      send_heartbeat (qr2.o)
 *
 * symbols:
 *   g_021AE9A0  0x021AE9A0  data
 *   g_021A7AB8  0x021A7AB8  data
 *   g_021AE9A4  0x021AE9A4  data
 *   g_021A7AC4  0x021A7AC4  data
 *   g_021A7AD0  0x021A7AD0  data
 *   g_021A7AD8  0x021A7AD8  data
 *   g_021A7ADC  0x021A7ADC  data
 *   g_021A7AE0  0x021A7AE0  data
 *   g_021A7AF0  0x021A7AF0  data
 *   g_021A7AFC  0x021A7AFC  data
 *   g_021A7B08  0x021A7B08  data
 *   g_021A7B14  0x021A7B14  data
 *   qr_add_packet_header  0x0219BA84  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   func_0219B660  0x0219B660  arm  ov009
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   func_0219B628  0x0219B628  arm  ov009
 *   func_02092344  0x02092344  arm
 *   qr_build_query_reply  0x0219BE80  arm  ov009
 *   func_0217ECA4  0x0217ECA4  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0217D32C  0x0217D32C  arm  ov009
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

typedef struct qr2_buffer_s {
    char buffer[0x578];
    int len;
} qr2_buffer_s;

typedef struct qr2_implementation_s {
    int hbsock;
    char gamename[64];
    char secret_key[64];
    char instance_key[4];
    unsigned char pad88[0x20];
    void (*pa_callback)(unsigned int, unsigned short, void *);
    unsigned char padAC[0x8];
    unsigned int lastheartbeat;
    unsigned int lastka;
    int userstatechangerequested;
    int listed_state;
    int ispublic;
    int qport;
    int read_socket;
    int nat_negotiate;
    SOCSockAddrIn hbaddr;
    unsigned char padDC[0x30];
    unsigned int publicip;
    unsigned short publicport;
} qr2_implementation_s;

extern int g_021AE9A0;
extern char g_021A7AB8[];
extern SOCInAddr g_021AE9A4[5];
extern char g_021A7AC4[];
extern char g_021A7AD0[];
extern char g_021A7AD8[];
extern char g_021A7ADC[];
extern char g_021A7AE0[];
extern char g_021A7AF0[];
extern char g_021A7AFC[];
extern char g_021A7B08[];
extern char g_021A7B14[];

extern void qr_add_packet_header(qr2_buffer_s *buf, char ptype, char *reqkey);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int func_0219B660(qr2_buffer_s *outbuf, char *value);
extern char *func_0215FA9C(SOCInAddr in);
extern int func_0219B628(qr2_buffer_s *outbuf, int value);
extern void *func_02092344(void *dst, const void *src, unsigned int n);
extern void qr_build_query_reply(qr2_implementation_s *qrec, qr2_buffer_s *buf, int serverkeycount, unsigned char *serverkeys,
                          int playerkeycount, unsigned char *playerkeys, int teamkeycount, unsigned char *teamkeys);
struct SOCSockAddr;
extern int func_0217ECA4(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen);
extern unsigned int func_0217F264(void);
extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void func_0217D32C(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength);

void send_heartbeat(qr2_implementation_s *qrec, int statechanged)
{
    qr2_buffer_s buf;
    int i;
    char ipkey[20];

    buf.len = 0;
    qr_add_packet_header(&buf, 3, qrec->instance_key);
    for (i = 0; i < g_021AE9A0; i++) {
        OS_SPrintf(ipkey, g_021A7AB8, i);
        func_0219B660(&buf, ipkey);
        func_0219B660(&buf, func_0215FA9C(g_021AE9A4[i]));
    }
    func_0219B660(&buf, g_021A7AC4);
    func_0219B628(&buf, qrec->qport);
    func_0219B660(&buf, g_021A7AD0);
    func_0219B660(&buf, qrec->nat_negotiate ? g_021A7AD8 : g_021A7ADC);
    if (statechanged) {
        func_0219B660(&buf, g_021A7AE0);
        func_0219B628(&buf, statechanged);
    }
    func_0219B660(&buf, g_021A7AF0);
    func_0219B660(&buf, qrec->gamename);
    if (qrec->pa_callback) {
        func_0219B660(&buf, g_021A7AFC);
        func_0219B628(&buf, (int)qrec->publicip);
        func_0219B660(&buf, g_021A7B08);
        func_0219B628(&buf, qrec->publicport);
    }
    if (statechanged != 2) {
        qr2_buffer_s temp;

        func_02092344(&temp, &buf, buf.len);
        temp.len = buf.len;
        qr_build_query_reply(qrec, &temp, 0xff, 0, 0xff, 0, 0xff, 0);
        if (0x578 - temp.len < 1) {
            temp.len = buf.len;
            qr_build_query_reply(qrec, &temp, 0xff, 0, 0, 0, 0, 0);
        }
        func_02092344(&buf, &temp, temp.len);
        buf.len = temp.len;
    } else {
        if (0x578 - buf.len >= 1)
            buf.buffer[buf.len++] = 0;
    }
    func_0217ECA4(qrec->hbsock, buf.buffer, buf.len, 0, (struct SOCSockAddr *)(&qrec->hbaddr), sizeof(SOCSockAddrIn));
    qrec->lastheartbeat = func_0217F264();
    qrec->lastka = qrec->lastheartbeat;
    if (statechanged)
        qrec->userstatechangerequested = 0;
    func_0217D254(3, 0, 0x10, g_021A7B14, buf.len);
    func_0217D32C(3, 0, 0x20, buf.buffer, buf.len);
}
