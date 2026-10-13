/*
 * function: qr2_init_socketA
 * address:  0x0219AEB4
 * packet:   pkt_ov009_0219AEB4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr2_init_socketA (qr2.o)
 *
 * symbols:
 *   func_0217D254  0x0217D254  arm  ov009
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_0217F264  0x0217F264  arm  ov009
 *   func_020946C8  0x020946C8  arm
 *   func_021803BC  0x021803BC  arm  ov009
 *   func_02094694  0x02094694  arm
 *   func_020923B0  0x020923B0  arm
 *   func_0219B6CC  0x0219B6CC  arm  ov009
 *   OS_SPrintf  0x02084F40  arm
 *   func_0219B73C  0x0219B73C  arm  ov009
 *   func_0215FA9C  0x0215FA9C  arm  ov009
 *   g_021A73A0  0x021A73A0  data
 *   g_021A6604  0x021A6604  data
 *   g_021AE9B8  0x021AE9B8  data
 *   g_021A73B4  0x021A73B4  data
 *   g_021A73D4  0x021A73D4  data
 *   g_021A73E8  0x021A73E8  data
 *   g_021A7408  0x021A7408  data
 */

#include "../include/G_021A6604.h"

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

extern char g_021A73A0[];
extern struct G_021A6604 g_021A6604;
extern char g_021AE9B8[64];
extern char g_021A73B4[];
extern char g_021A73D4[];
extern char g_021A73E8[];
extern char g_021A7408[];

extern int func_0217D254(int index, char *table, int mask, const char *fmt, ...);
extern void *func_0217EAB0(unsigned long size);
extern unsigned int func_0217F264(void);
extern void func_020946C8(unsigned int seed);
struct SOCHostEnt;
extern int func_021803BC(char *dst, const char *src, unsigned int n);
extern int func_02094694(void);
extern void *func_020923B0(void *dst, int c, unsigned int n);
extern void func_0219B6CC(void);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int func_0219B73C(char *host, int port, struct SOCSockAddrIn *saddr, struct SOCHostEnt **savehent);
extern char *func_0215FA9C(SOCInAddr in);

int qr2_init_socketA(qr2_implementation_s **qrec, int s, int boundport, char *gamename, char *secret_key,
                  int ispublic, int natnegotiate,
                  void (*server_key_callback)(int, struct qr2_buffer_s *, void *),
                  void (*player_key_callback)(int, int, struct qr2_buffer_s *, void *),
                  void (*team_key_callback)(int, int, struct qr2_buffer_s *, void *),
                  void (*key_list_callback)(int, struct qr2_keybuffer_s *, void *),
                  int (*playerteam_count_callback)(int, void *),
                  void (*adderror_callback)(int, char *, void *),
                  void *userdata)
{
    char hostname[64];
    int ret;
    int i;
    qr2_implementation_s *cr;

    func_0217D254(3, (char *)4, 0x40, g_021A73A0);

    if (qrec == 0) {
        cr = ((qr2_implementation_s *)&g_021A6604);
    } else {
        *qrec = (qr2_implementation_s *)func_0217EAB0(sizeof(qr2_implementation_s));
        cr = *qrec;
    }
    func_020946C8(func_0217F264());
    func_021803BC(cr->gamename, gamename, sizeof(cr->gamename));
    func_021803BC(cr->secret_key, secret_key, sizeof(cr->secret_key));
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
        cr->instance_key[i] = (char)(func_02094694() % 0xFF);
    for (i = 0; i < 10; i++)
        cr->client_message_keys[i] = -1;
    cr->cur_message_key = 0;

    func_020923B0(cr->ipverify, 0, sizeof(cr->ipverify));

    func_0219B6CC();

    if (ispublic) {
        int override = g_021AE9B8[0];
        if (!override)
            OS_SPrintf(hostname, g_021A73B4, gamename);
        ret = func_0219B73C(override ? g_021AE9B8 : hostname, 27900, &cr->hbaddr, 0);
        if (ret == 1)
            func_0217D254(3, 0, 0x10, g_021A73D4, override ? g_021AE9B8 : hostname, func_0215FA9C(cr->hbaddr.addr));
        else
            func_0217D254(3, 0, 1, g_021A73E8, override ? g_021AE9B8 : hostname);
    } else {
        ret = 1;
    }
    if (!ret) {
        func_0217D254(3, (char *)4, 1, g_021A7408);
        return 3;
    }
    return 0;
}
