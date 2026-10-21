/*
 * file:     qr2.c
 * unit:     yes
 * function: qr2_init_socketA, qr2_register_natneg_callback, qr2_register_clientmessage_callback, qr2_register_publicaddress_callback, qr2_think, qr2_check_queries, qr2_check_send_heartbeat, qr2_send_statechanged, qr2_shutdown, qr2_keybuffer_add, qr2_buffer_add_int, qr2_buffer_addA, enum_local_ips, get_sockaddrin, swap_byte, encode_ct, gs_encode, gs_encrypt, NatNegProgressCallback, NatNegCompletedCallback, qr_add_packet_header, compute_challenge_response, handle_public_address, qr_build_partial_query_reply, qr_build_query_reply, qr_build_split_query_reply, qr_process_query, qr_process_client_message, qr_got_recent_message, qr2_process_ip_verify, qr2_check_ip_verify, qr2_expire_ip_verify, qr2_parse_queryA, send_keepalive, send_heartbeat
 * address:  0x0219AEB4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * Merged by hand (round 5, lane s06): one canonical qr2 type block in qr2_types.h.
 * Swaps two bytes.
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
 *   MSL_C_LIB_MemsetPtr         0x020923B0  arm
 *   rand           0x02094694  arm
 *   srand          0x020946C8  arm
 *   strlen         0x0209477C  arm
 *   strcmp         0x020948E0  arm
 *   NNFreeNegotiateList  0x0219922C  arm  ov009
 *   NNThink        0x0219A4A4  arm  ov009
 *   qr2_parse_queryA  0x0219C7C0  arm  ov009
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
 *   sQr2NumLocalIps  0x021AE9A0  data
 *   local_ip_list  0x021AE9A4  data
 *   g_021AE9B8     0x021AE9B8  data
 *   g_021AE9F8     0x021AE9F8  data
 *   encode_ct  0x0219B810  arm  ov009
 *   _s32_div_f     0x0209C0A4  arm
 *   sendto                 0x0217ECA4  arm  ov009
 *   STD_TSScanf            0x0208CF34  arm
 *   gs_encode              0x0219B858  arm  ov009
 *   gs_encrypt             0x0219B918  arm  ov009
 *   g_021A769C             0x021A769C  data
 *   g_021A76A8             0x021A76A8  data
 *   g_021A76CC             0x021A76CC  data
 *   g_021A76D4             0x021A76D4  data
 *   g_021A76D8             0x021A76D8  data
 *   g_021A76E4             0x021A76E4  data
 *   g_021A7720             0x021A7720  data
 *   g_021A775C             0x021A775C  data
 *   g_021A7798             0x021A7798  data
 *   g_021A77D4             0x021A77D4  data
 *   g_021A7804             0x021A7804  data
 *   g_021A7830             0x021A7830  data
 *   gQr2RegKeys             0x021A7C90  data
 *   NNBeginNegotiationWithSocket 0x02199DFC  arm  ov009
 *   g_021A7858             0x021A7858  data
 *   gGsAvailabilityState             0x021ACEF8  data
 *   gGsAvailabilityGameName             0x021ACEFC  data
 *   memcmp                 0x020923F0  arm
 *   NNProcessData          0x0219AB8C  arm  ov009
 *   gNatNegMagic             0x021A5A7C  data
 *   g_021A7874             0x021A7874  data
 *   g_021A788C             0x021A788C  data
 *   g_021A78B4             0x021A78B4  data
 *   g_021A78F0             0x021A78F0  data
 *   g_021A791C             0x021A791C  data
 *   g_021A7944             0x021A7944  data
 *   g_021A7960             0x021A7960  data
 *   g_021A7980             0x021A7980  data
 *   g_021A7988             0x021A7988  data
 *   g_021A79A8             0x021A79A8  data
 *   g_021A79D8             0x021A79D8  data
 *   g_021A79F4             0x021A79F4  data
 *   g_021A7A14             0x021A7A14  data
 *   g_021A7A38             0x021A7A38  data
 *   g_021A7A58             0x021A7A58  data
 *   g_021A7A74             0x021A7A74  data
 *   g_021A7A9C             0x021A7A9C  data
 *   g_021A7AB8             0x021A7AB8  data
 *   g_021A7AC4             0x021A7AC4  data
 *   g_021A7AD0             0x021A7AD0  data
 *   g_021A7AD8             0x021A7AD8  data
 *   g_021A7ADC             0x021A7ADC  data
 *   g_021A7AE0             0x021A7AE0  data
 *   g_021A7AF0             0x021A7AF0  data
 *   g_021A7AFC             0x021A7AFC  data
 *   g_021A7B08             0x021A7B08  data
 *   g_021A7B14             0x021A7B14  data
 *   @460                   0x021A1B64  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "qr2_types.h"
#include "../arm9/msl_string_mem.h"

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | \
                   (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))
#define QR2_OPTION_USE_QUERY_CHALLENGE 0x80
#define QR2_IPVERIFY_ARRAY_SIZE 200
#define QR2_IPVERIFY_MAXDUPLICATES 5
typedef enum { QRSplitQueryState_Server, QRSplitQueryState_Player, QRSplitQueryState_Team, QRSplitQueryState_Finished } QRSplitQueryState;

typedef struct QRSplitQueryProgress {
    QRSplitQueryState mState;
    int mPacketNum;
    int mCurKeyIndex;
    int mNumPlayersOrTeams;
    int mCurSubCount;
    qr2_keybuffer_s mKeyBuffer;
} QRSplitQueryProgress;

typedef struct key4_t {
    char b[4];
} key4_t;

#include "gsdebug.h"
#include "gsmemory.h"
#include "gsplatformsocket.h"
#include "gsplatformutil.h"
#include "gsstringutil.h"
#include "soc.h"
#include "../arm9/os_printf.h"
#ifdef __MWERKS__
#define rand randHeader
#endif
#include "../arm9/msl_stdlib.h"
#ifdef __MWERKS__
/* original prototypes: the DS code declares these with other argument or return types than the definitions */
#undef rand
extern int rand(void);
#endif
extern void srand(unsigned int seed);
extern int strcmp(const char *a, const char *b);
#include "natneg.h"
extern void qr2_parse_queryA(qr2_implementation_s *qrec, char *query, int len, SOCSockAddr *sender);
static unsigned char encode_ct(unsigned char c);
extern int STD_TSScanf(char *src, char *fmt, ...);
extern void gs_encode(unsigned char *ins, int size, unsigned char *result);
extern void gs_encrypt(unsigned char *key, int key_len, unsigned char *buffer_ptr, int buffer_len);
int qr2_init_socketA(qr2_implementation_s **qrec, int s, int boundport, char *gamename, char *secret_key, int ispublic, int natnegotiate, void (*server_key_callback)(int, qr2_buffer_s *, void *), void (*player_key_callback)(int, int, qr2_buffer_s *, void *), void (*team_key_callback)(int, int, qr2_buffer_s *, void *), void (*key_list_callback)(qr2_key_type, qr2_keybuffer_s *, void *), int (*playerteam_count_callback)(qr2_key_type, void *), void (*adderror_callback)(int, char *, void *), void *userdata);
void qr2_register_natneg_callback(qr2_implementation_s *qrec, void (*nncallback)(int, void *));
void qr2_register_clientmessage_callback(qr2_implementation_s *qrec, void (*cmcallback)(char *, int, void *));
void qr2_register_publicaddress_callback( qr2_implementation_s *qrec, void (*pacallback)(unsigned int, unsigned short, void *));
void qr2_think(qr2_implementation_s *qrec);
void qr2_check_queries(qr2_implementation_s *qrec);
void qr2_check_send_heartbeat(qr2_implementation_s *qrec);
void qr2_send_statechanged(qr2_implementation_s *qrec);
void qr2_shutdown(qr2_implementation_s *qrec);
int qr2_keybuffer_add(qr2_keybuffer_s *keybuffer, int keyid);
int qr2_buffer_add_int(qr2_buffer_s *outbuf, int value);
int qr2_buffer_addA(qr2_buffer_s *outbuf, char *value);
static int get_sockaddrin(char *host, int port, SOCSockAddrIn *saddr, SOCHostEnt **savehent);
void swap_byte(unsigned char *p, unsigned char *q);
void NatNegProgressCallback(int state, void *userdata);
void NatNegCompletedCallback(int result, int gamesocket, SOCSockAddrIn *remoteaddr, void *userdata);
void qr_add_packet_header(qr2_buffer_s *buf, char ptype, char *reqkey);
void compute_challenge_response(qr2_implementation_s *qrec, qr2_buffer_s *buf, char *challenge, int challengelen);
void handle_public_address(qr2_implementation_s *qrec, char *buffer);
void qr_build_partial_query_reply(qr2_implementation_s *qrec, qr2_buffer_s *buf, qr2_key_type keytype, int keycount, unsigned char *keys);
void qr_build_query_reply(qr2_implementation_s *qrec, qr2_buffer_s *buf, int serverkeycount, unsigned char *serverkeys, int playerkeycount, unsigned char *playerkeys, int teamkeycount, unsigned char *teamkeys);
int qr_build_split_query_reply(qr2_implementation_s *qrec, qr2_buffer_s *buf, QRSplitQueryProgress *progress);
void qr_process_query(qr2_implementation_s *qrec, qr2_buffer_s *buf, unsigned char *qdata, int len, SOCSockAddr *sender);
void qr_process_client_message(qr2_implementation_s *qrec, char *buf, int len);
int qr2_process_ip_verify(qr2_implementation_s *qrec, qr2_buffer_s *buf, SOCSockAddrIn *sender);
void qr2_expire_ip_verify(qr2_implementation_s *qrec);
void send_keepalive(qr2_implementation_s *qrec);
void send_heartbeat(qr2_implementation_s *qrec, int statechanged);
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
extern int sQr2NumLocalIps;
extern SOCInAddr local_ip_list[5];
extern char g_021AE9B8[64];
extern char g_021AE9F8[];
extern char g_021A769C[];
extern char g_021A76A8[];
extern char g_021A76CC[];
extern char g_021A76D4[];
extern char g_021A76D8[];
extern char g_021A76E4[];
extern char g_021A7720[];
extern char g_021A775C[];
extern char g_021A7798[];
extern char g_021A77D4[];
extern char g_021A7804[];
extern char g_021A7830[];
extern char *gQr2RegKeys[];
extern char g_021A7858[];
extern int gGsAvailabilityState;
extern char gGsAvailabilityGameName[];
extern struct Magic6 gNatNegMagic;
extern char g_021A7874[];
extern char g_021A788C[];
extern char g_021A78B4[];
extern char g_021A78F0[];
extern char g_021A791C[];
extern char g_021A7944[];
extern char g_021A7960[];
extern char g_021A7980[];
extern char g_021A7988[];
extern char g_021A79A8[];
extern char g_021A79D8[];
extern char g_021A79F4[];
extern char g_021A7A14[];
extern char g_021A7A38[];
extern char g_021A7A58[];
extern char g_021A7A74[];
extern char g_021A7A9C[];
extern char g_021A7AB8[];
extern char g_021A7AC4[];
extern char g_021A7AD0[];
extern char g_021A7AD8[];
extern char g_021A7ADC[];
extern char g_021A7AE0[];
extern char g_021A7AF0[];
extern char g_021A7AFC[];
extern char g_021A7B08[];
extern char g_021A7B14[];


static void enum_local_ips(void);


/*
 * sdk:      qr2_init_socketA (qr2.o)
 */
int qr2_init_socketA(qr2_implementation_s **qrec, int s, int boundport, char *gamename, char *secret_key,
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

    MSL_C_LIB_MemsetPtr(cr->ipverify, 0, sizeof(cr->ipverify));

    enum_local_ips();

    if (ispublic) {
        int override = g_021AE9B8[0];
        if (!override)
            OS_SPrintf(hostname, g_021A73B4, gamename);
        ret = get_sockaddrin(override ? g_021AE9B8 : hostname, 27900, &cr->hbaddr, 0);
        if (ret == 1)
            gsDebugFormat(3, 0, 0x10, g_021A73D4, override ? g_021AE9B8 : hostname, SOC_InetNtoA(*(SOCInAddr *)&cr->hbaddr.addr));
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
        qr2_check_send_heartbeat(qrec);
    qr2_check_queries(qrec);
    qr2_expire_ip_verify(qrec);
    NNThink();
}


/*
 * sdk:      qr2_check_queries (libdwcgsqr2.TWL.HYB.a qr2.o)
 */
void qr2_check_queries(qr2_implementation_s *qrec)
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
            qr2_parse_queryA(qrec, g_021AE9F8, error, (SOCSockAddr *)&saddr);
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
    send_heartbeat(qrec, 1);
    qrec->userstatechangerequested = 0;
}


/*
 * sdk: qr2_shutdown (qr2.o)
 */
void qr2_shutdown(qr2_implementation_s *qrec)
{
    gsDebugFormat(3, 0, 0x40, g_021A7674);
    if (!qrec)
        qrec = current_rec;
    if (qrec->ispublic)
        send_heartbeat(qrec, 2);
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
int qr2_keybuffer_add(qr2_keybuffer_s *keybuffer, int keyid)
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
    sQr2NumLocalIps = 0;
    for (i = 0; i < 5; i++) {
        if (phost->addrList[i] == 0)
            return;
        memcpy(&local_ip_list[i], phost->addrList[i], sizeof(SOCInAddr));
        sQr2NumLocalIps = i + 1;
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
 * (which CW leaves rolled) and MSL_C_LIB_MemsetPtr (a call) miss.  byte 0 and the family
 * byte are written afterwards, in that order.
 */
static int get_sockaddrin(char *host, int port, SOCSockAddrIn *saddr, SOCHostEnt **savehent)
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
        saddr->addr = inet_addr(host);
    else
        saddr->addr = 0;
    if (saddr->addr == 0xFFFFFFFF) {
        if (strcmp(host, g_021A768C) != 0) {
            hent = SOC_GetHostByName(host);
            if (!hent)
                return 0;
            saddr->addr = *(unsigned int *)*hent->addrList;
        }
    }
    if (savehent)
        *savehent = hent;
    return 1;
}

void swap_byte(unsigned char *p, unsigned char *q)
{
    unsigned char t = *p;

    *p = *q;
    *q = t;
}


static unsigned char encode_ct(unsigned char c)
{
    if (c < 26)
        return (unsigned char)(c + 'A');
    if (c < 52)
        return (unsigned char)(c + 'G');
    if (c < 62)
        return (unsigned char)(c - 4);
    if (c == 62)
        return '+';
    if (c == 63)
        return '/';
    return 0;
}



/*
 * sdk:      gs_encode (qr2.o)
 */
void gs_encode(unsigned char *ins, int size, unsigned char *result)
{
    int i;
    int pos;
    unsigned char trip[3];
    unsigned char kwart[4];

    i = 0;
    while (i < size) {
        for (pos = 0; pos <= 2; pos++, i++) {
            if (i < size)
                trip[pos] = *ins++;
            else
                trip[pos] = 0;
        }
        kwart[0] = trip[0] >> 2;
        kwart[1] = ((trip[0] & 3) << 4) + (trip[1] >> 4);
        kwart[2] = ((trip[1] & 15) << 2) + (trip[2] >> 6);
        kwart[3] = trip[2] & 63;
        for (pos = 0; pos <= 3; pos++)
            *result++ = encode_ct(kwart[pos]);
    }
    *result = 0;
}



/*
 * sdk:      gs_encrypt (libdwcgsqr2.TWL.HYB.a qr2.o)
 */
void gs_encrypt(unsigned char *key, int key_len, unsigned char *buffer_ptr, int buffer_len)
{
    short counter;
    unsigned char x;
    unsigned char y;
    unsigned char state[256];
    unsigned char xorIndex;

    for (counter = 0; counter < 256; counter++)
        state[counter] = (unsigned char)counter;
    x = 0;
    y = 0;
    for (counter = 0; counter < 256; counter++) {
        y = (key[x] + state[counter] + y) % 256;
        x = (x + 1) % key_len;
        swap_byte(&state[counter], &state[y]);
    }
    x = 0;
    y = 0;
    for (counter = 0; counter < buffer_len; counter++) {
        x = (buffer_ptr[counter] + x + 1) % 256;
        y = (state[x] + y) % 256;
        swap_byte(&state[x], &state[y]);
        xorIndex = (state[x] + state[y]) % 256;
        buffer_ptr[counter] ^= state[xorIndex];
    }
}



/* sdk:      NatNegProgressCallback (qr2.o) */
void NatNegProgressCallback(int state, void *userdata)
{
}



/* sdk:      NatNegCompletedCallback (qr2.o) */
void NatNegCompletedCallback(int result, int gamesocket, SOCSockAddrIn *remoteaddr, void *userdata)
{
    qr2_implementation_s *qrec = userdata;

    if (qrec->cc_callback == 0)
        return;
    if (result != 0)
        return;
    qrec->cc_callback(gamesocket, remoteaddr, qrec->udata);
}



/* sdk:      qr_add_packet_header (qr2.o) */
void qr_add_packet_header(qr2_buffer_s *buf, char ptype, char *reqkey)
{
    buf->buffer[0] = ptype;
    *(key4_t *)&buf->buffer[1] = *(key4_t *)reqkey;
    buf->len = 5;
}



/* sdk:      compute_challenge_response (qr2.o) */
void compute_challenge_response(qr2_implementation_s *qrec, qr2_buffer_s *buf, char *challenge, int challengelen)
{
    char encrypted_val[65];

    if (challengelen < 1 || challengelen > 65 || challenge[challengelen - 1] != 0)
        return;
    gsiSafeStrcpyA(encrypted_val, challenge, 65);
    gs_encrypt((unsigned char *)qrec->secret_key, strlen(qrec->secret_key), (unsigned char *)encrypted_val, challengelen - 1);
    gs_encode((unsigned char *)encrypted_val, challengelen - 1, (unsigned char *)&buf->buffer[buf->len]);
    buf->len += strlen(&buf->buffer[buf->len]) + 1;
}



/* sdk:      handle_public_address (qr2.o) */
void handle_public_address(qr2_implementation_s *qrec, char *buffer)
{
    unsigned int ip;
    unsigned int portTemp;
    unsigned short port;
    SOCInAddr addr;

    STD_TSScanf(buffer, g_021A769C, &ip, &portTemp);
    port = (unsigned short)portTemp;
    ip = SWAP32(ip);
    if (ip == 0 || port == 0)
        return;
    addr.addr = ip;
    gsDebugFormat(3, 0, 8, g_021A76A8, SOC_InetNtoA(addr), port);
    if (qrec->publicip == ip && qrec->publicport == port)
        return;
    qrec->publicip = ip;
    qrec->publicport = port;
    qrec->pa_callback(ip, port, qrec->udata);
}



/* sdk:      qr_build_partial_query_reply (qr2.o) */
void qr_build_partial_query_reply(qr2_implementation_s *qrec, qr2_buffer_s *buf, qr2_key_type keytype, int keycount, unsigned char *keys)
{
    qr2_keybuffer_s kb;
    int playerteamcount;
    unsigned short cttemp;
    int i;
    int pindex;
    char *k;
    int len;

    kb.numkeys = 0;
    if (keycount == 0)
        return;

    if (keytype == key_player || keytype == key_team) {
        if (1400 - buf->len < (int)sizeof(cttemp))
            return;
        playerteamcount = qrec->playerteam_count_callback(keytype, qrec->udata);
        cttemp = (unsigned short)((((unsigned short)playerteamcount >> 8) & 0xFF)
                                  | (((unsigned short)playerteamcount << 8) & 0xFF00));
        memcpy(buf->buffer + buf->len, &cttemp, sizeof(cttemp));
        buf->len += sizeof(cttemp);
    } else
        playerteamcount = 1;

    if (keycount == 0xFF) {
        qrec->key_list_callback(keytype, &kb, qrec->udata);
        for (i = 0; i < kb.numkeys; i++) {
            k = gQr2RegKeys[kb.keys[i]];
            if (k == 0)
                k = g_021A76CC;
            qr2_buffer_addA(buf, k);
            if (keytype == key_server) {
                len = buf->len;
                qrec->server_key_callback(kb.keys[i], buf, qrec->udata);
                if (len == buf->len)
                    qr2_buffer_addA(buf, g_021A76D4);
            }
        }
        if (1400 - buf->len < 1)
            return;
        buf->buffer[buf->len++] = 0;
        keycount = kb.numkeys;
        keys = kb.keys;
        if (keytype == key_server)
            return;
    }

    for (pindex = 0; pindex < playerteamcount; pindex++) {
        for (i = 0; i < keycount; i++) {
            len = buf->len;
            if (keytype == key_server)
                qrec->server_key_callback(keys[i], buf, qrec->udata);
            else if (keytype == key_player)
                qrec->player_key_callback(keys[i], pindex, buf, qrec->udata);
            else if (keytype == key_team)
                qrec->team_key_callback(keys[i], pindex, buf, qrec->udata);
            if (len == buf->len)
                qr2_buffer_addA(buf, g_021A76D4);
        }
    }
}



/* sdk:      qr_build_query_reply (qr2.o) */
void qr_build_query_reply(qr2_implementation_s *qrec, qr2_buffer_s *buf, int serverkeycount, unsigned char *serverkeys,
                          int playerkeycount, unsigned char *playerkeys,
                          int teamkeycount, unsigned char *teamkeys)
{
    qr_build_partial_query_reply(qrec, buf, key_server, serverkeycount, serverkeys);
    qr_build_partial_query_reply(qrec, buf, key_player, playerkeycount, playerkeys);
    qr_build_partial_query_reply(qrec, buf, key_team, teamkeycount, teamkeys);
}



/* sdk:      qr_build_split_query_reply (qr2.o) */
int qr_build_split_query_reply(qr2_implementation_s *qrec, qr2_buffer_s *buf, QRSplitQueryProgress *progress)
{
    unsigned char *packetNumPos;
    int aRegisteredKeyIndex;

    if (progress->mState >= 3)
        return 0;
    if (0x578 - buf->len < 32)
        return 0;

    qr2_buffer_addA(buf, g_021A76D8);
    packetNumPos = (unsigned char *)&buf->buffer[buf->len++];
    *packetNumPos = (unsigned char)progress->mPacketNum++;

    while (progress->mState < 3) {
        if (progress->mKeyBuffer.numkeys == 0)
            qrec->key_list_callback(*(qr2_key_type *)&progress->mState, &progress->mKeyBuffer, qrec->udata);
        if (progress->mNumPlayersOrTeams == 0 && progress->mState != 0)
            progress->mNumPlayersOrTeams = qrec->playerteam_count_callback((qr2_key_type)progress->mState, qrec->udata);

        if (0x578 - buf->len < 100)
            return 1;
        buf->buffer[buf->len++] = (unsigned char)progress->mState;

        while (progress->mCurKeyIndex < progress->mKeyBuffer.numkeys) {
            aRegisteredKeyIndex = progress->mKeyBuffer.keys[progress->mCurKeyIndex];
            if (qr2_buffer_addA(buf, gQr2RegKeys[aRegisteredKeyIndex]) == 0)
                return 1;
            if (progress->mState == 0) {
                qrec->server_key_callback(aRegisteredKeyIndex, buf, qrec->udata);
                if (0x578 - buf->len < 1)
                    return 1;
            } else {
                if (0x578 - buf->len < 1)
                    return 1;
                buf->buffer[buf->len++] = (unsigned char)progress->mCurSubCount;
                while (progress->mCurSubCount < progress->mNumPlayersOrTeams) {
                    if (progress->mState == 1)
                        qrec->player_key_callback(aRegisteredKeyIndex, progress->mCurSubCount, buf, qrec->udata);
                    else if (progress->mState == 2)
                        qrec->team_key_callback(aRegisteredKeyIndex, progress->mCurSubCount, buf, qrec->udata);
                    if (0x578 - buf->len < 1)
                        return 1;
                    progress->mCurSubCount++;
                }
                if (0x578 - buf->len > 0)
                    buf->buffer[buf->len++] = 0;
            }
            progress->mCurKeyIndex++;
            progress->mCurSubCount = 0;
        }
        if (0x578 - buf->len > 0)
            buf->buffer[buf->len++] = 0;
        progress->mState++;
        progress->mCurKeyIndex = 0;
        progress->mNumPlayersOrTeams = 0;
        progress->mCurSubCount = 0;
        progress->mKeyBuffer.numkeys = 0;
    }
    *packetNumPos |= 0x80;
    return 1;
}



/* sdk:      qr_process_query (qr2.o) */
void qr_process_query(qr2_implementation_s *qrec, qr2_buffer_s *buf, unsigned char *qdata, int len, SOCSockAddr *sender)
{
    unsigned char serverkeycount;
    unsigned char playerkeycount;
    unsigned char teamkeycount;
    unsigned char exflags = 0;
    unsigned char *serverkeys = 0;
    unsigned char *playerkeys = 0;
    unsigned char *teamkeys = 0;

    if (len < 3) {
        gsDebugFormat(3, 0, 2, g_021A76E4, len);
        return;
    }
    serverkeycount = *qdata++;
    len--;
    if (serverkeycount != 0 && serverkeycount != 0xFF) {
        serverkeys = qdata;
        len -= serverkeycount;
        qdata += serverkeycount;
    }

    if (len < 2) {
        gsDebugFormat(3, 0, 2, g_021A7720, len);
        return;
    }
    playerkeycount = *qdata++;
    len--;
    if (playerkeycount != 0 && playerkeycount != 0xFF) {
        playerkeys = qdata;
        len -= playerkeycount;
        qdata += playerkeycount;
    }

    if (len < 1) {
        gsDebugFormat(3, 0, 2, g_021A775C, len);
        return;
    }
    teamkeycount = *qdata++;
    len--;
    if (teamkeycount != 0 && teamkeycount != 0xFF) {
        teamkeys = qdata;
        len -= teamkeycount;
        qdata += teamkeycount;
    }

    if (len < 0) {
        gsDebugFormat(3, 0, 2, g_021A7798, len);
        return;
    }
    if (len > 0)
        exflags = *qdata;

    if ((exflags & 1) == 1) {
        QRSplitQueryProgress progress;

        progress.mPacketNum = 0;
        progress.mState = QRSplitQueryState_Server;
        progress.mCurKeyIndex = 0;
        progress.mNumPlayersOrTeams = 0;
        progress.mCurSubCount = 0;
        progress.mKeyBuffer.numkeys = 0;

        gsDebugFormat(3, 0, 0x10, g_021A77D4);
        while (qr_build_split_query_reply(qrec, buf, &progress) == 1) {
            sendto(qrec->hbsock, buf->buffer, buf->len, 0, sender, 8);
            buf->len = 5;
            if (progress.mPacketNum > 7)
                return;
        }
        gsDebugFormat(3, 0, 0x10, g_021A7804, progress.mPacketNum);
        return;
    }

    gsDebugFormat(3, 0, 0x10, g_021A7830);
    qr_build_query_reply(qrec, buf, serverkeycount, serverkeys, playerkeycount, playerkeys, teamkeycount, teamkeys);
    sendto(qrec->hbsock, buf->buffer, buf->len, 0, sender, 8);
}




/*
 * sdk:      qr_process_client_message (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * The six natneg magic bytes are a local initialiser; the vendor object's
 * template for them sits at 0x021A1B64.
 */
void qr_process_client_message(qr2_implementation_s *qrec, char *buf, int len)
{
    unsigned char natNegBytes[6] = {0xFD, 0xFC, 0x1E, 0x66, 0x6A, 0xB2};
    int i;
    int isnatneg = 1;
    int cookie;

    gsDebugFormat(3, 4, 8, g_021A7858);

    if (len >= 10) {
        for (i = 0; i < 6; i++) {
            if ((unsigned char)buf[i] != natNegBytes[i]) {
                isnatneg = 0;
                break;
            }
        }
    } else
        isnatneg = 0;

    if (isnatneg) {
        memcpy(&cookie, buf + 6, 4);
        cookie = (int)((((unsigned int)cookie >> 24) & 0xFF) | (((unsigned int)cookie >> 8) & 0xFF00)
                       | (((unsigned int)cookie << 8) & 0xFF0000) | (((unsigned int)cookie << 24) & 0xFF000000));
        if (qrec->cc_callback) {
            if (gGsAvailabilityState != 1) {
                gGsAvailabilityState = 1;
                gsiSafeStrcpyA(gGsAvailabilityGameName, qrec->gamename, 64);
            }
            NNBeginNegotiationWithSocket(qrec->hbsock, cookie, 1, NatNegProgressCallback, NatNegCompletedCallback, qrec);
        } else if (qrec->nn_callback)
            qrec->nn_callback(cookie, qrec->udata);
    } else if (qrec->cm_callback)
        qrec->cm_callback(buf, len, qrec->udata);
}




/* SOC_HtoNl, nitroWiFi/soc.h */
#define SOC_HtoNl(hostlong) \
    ((unsigned int)((((unsigned int)(hostlong) >> 24) & 0x000000ff) | (((unsigned int)(hostlong) >> 8) & 0x0000ff00) | \
                    (((unsigned int)(hostlong) << 8) & 0x00ff0000) | (((unsigned int)(hostlong) << 24) & 0xff000000)))




/* sdk:      qr_got_recent_message (qr2.o) */
static int qr_got_recent_message(qr2_implementation_s *qrec, int msgkey)
{
    int i;

    for (i = 0; i < 10; i++) {
        if (msgkey == qrec->client_message_keys[i])
            return 1;
    }
    qrec->cur_message_key = (qrec->cur_message_key + 1) % 10;
    qrec->client_message_keys[qrec->cur_message_key] = msgkey;
    return 0;
}




/*
 * sdk:      qr2_process_ip_verify (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * The vendor's own spelling: the declarations carry their initialisers in the
 * vendor's order (i, now, firstFreeIndex, numDuplicates) and the loop's init is
 * empty, which is what puts i in r5 and numDuplicates in r0.
 */
int qr2_process_ip_verify(qr2_implementation_s *qrec, qr2_buffer_s *buf, SOCSockAddrIn *sender)
{
    int i = 0;
    unsigned int now = current_time();
    int firstFreeIndex = -1;
    int numDuplicates = 0;

    /* if the query challenge is disabled, return 0 as the challenge */
    if ((qrec->backendoptions & QR2_OPTION_USE_QUERY_CHALLENGE) == 0) {
        qr2_buffer_add_int(buf, 0);
        return 1;
    }

    /* check if this ip/port combo is already in the list */
    for (; i < QR2_IPVERIFY_ARRAY_SIZE; i++) {
        /* Mark the first free index when/if found */
        if (firstFreeIndex == -1 && qrec->ipverify[i].addr.addr == 0)
            firstFreeIndex = i;
        /* Count any indexes that match this IP/port */
        if (qrec->ipverify[i].addr.addr == sender->addr &&
            qrec->ipverify[i].addr.port == sender->port) {
            numDuplicates++;
        }
    }

    /* discard if too many duplicates or no index found */
    if (numDuplicates > QR2_IPVERIFY_MAXDUPLICATES)
        return 0;
    if (firstFreeIndex == -1)
        return 0; /* no free indexes */

    /* create a random challenge for this ip/port combo */
    qrec->ipverify[firstFreeIndex].addr = *sender;
    qrec->ipverify[firstFreeIndex].challenge = SOC_HtoNl((rand() << 16) | rand());
    qrec->ipverify[firstFreeIndex].time = now;

    qr2_buffer_add_int(buf, (int)qrec->ipverify[firstFreeIndex].challenge);
    return 1; /* buffer ready to be sent */
}




/* sdk:      qr2_check_ip_verify (qr2.o) */
static int qr2_check_ip_verify(qr2_implementation_s *qrec, SOCSockAddrIn *sender, unsigned int ipverify)
{
    int i;

    for (i = 0; i < 200; i++) {
        if (sender->addr == qrec->ipverify[i].addr.addr &&
            sender->port == qrec->ipverify[i].addr.port &&
            ipverify == qrec->ipverify[i].challenge) {
            qrec->ipverify[i].addr.addr = 0;
            qrec->ipverify[i].addr.port = 0;
            return 1;
        }
    }
    return 0;
}




/* sdk:      qr2_expire_ip_verify (qr2.o) */
void qr2_expire_ip_verify(qr2_implementation_s *qrec)
{
    int i = 0;
    unsigned int now = current_time();

    for (; i < 0xc8; i++) {
        if (qrec->ipverify[i].addr.addr != 0 &&
            now - qrec->ipverify[i].time > 0xfa0)
            qrec->ipverify[i].addr.addr = 0;
    }
}




/* sdk:      qr2_parse_queryA (qr2.o) */
void qr2_parse_queryA(qr2_implementation_s *qrec, char *query, int len, SOCSockAddr *sender)
{
    qr2_buffer_s buf;
    char ptype;
    char *reqkey;
    char *pos;
    int i;
    unsigned int backendoptions;

    buf.len = 0;
    gsDebugFormat(3, 0, 0x40, g_021A7874);
    if (qrec == 0)
        qrec = current_rec;
    i = query[0];
    if (i == ';') {
        if (qrec->cdkeyprocess != 0) {
            gsDebugFormat(3, 0, 8, g_021A788C);
            qrec->cdkeyprocess(query, len, sender);
        } else {
            gsDebugFormat(3, 0, 2, g_021A78B4);
        }
        return;
    }
    if (len >= 6 && memcmp((unsigned char *)query, ((unsigned char *)&gNatNegMagic), 6) == 0) {
        gsDebugFormat(3, 0, 8, g_021A78F0);
        NNProcessData(query, len, (SOCSockAddrIn *)sender);
        return;
    }
    if (len < 7 || (unsigned char)i != 0xfe || (unsigned char)query[1] != 0xfd)
        return;
    if (qrec->listed_state > 0)
        qrec->listed_state = 0;
    reqkey = query + 3;
    ptype = query[2];
    pos = query + 7;
    len -= 7;
    qr_add_packet_header(&buf, ptype, reqkey);

    switch (ptype) {
    case 9:
        gsDebugFormat(3, 0, 8, g_021A791C);
        if (qr2_process_ip_verify(qrec, &buf, (SOCSockAddrIn *)sender) == 0)
            return;
        break;
    case 0:
        gsDebugFormat(3, 0, 8, g_021A7944);
        if ((qrec->backendoptions & 0x80) == 0x80) {
            if (len < 4)
                return;
            i = *(int *)pos;
            pos += 4;
            len -= 4;
            if (qr2_check_ip_verify(qrec, (SOCSockAddrIn *)sender, SWAP32((unsigned int)i)) == 0)
                return;
        }
        qr_process_query(qrec, &buf, (unsigned char *)pos, len, sender);
        return;
    case 1:
        gsDebugFormat(3, 0, 8, g_021A7960);
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len >= 15) {
            STD_TSScanf(pos + len - 15, g_021A7980, &backendoptions);
            qrec->backendoptions = (unsigned char)backendoptions;
            gsDebugFormat(3, 4, 8, g_021A7988, qrec->backendoptions);
            if (qrec->pa_callback != 0)
                handle_public_address(qrec, pos + len - 13);
            else
                gsDebugFormat(3, 0, 8, g_021A79A8);
        }
        compute_challenge_response(qrec, &buf, pos, len);
        break;
    case 2:
        gsDebugFormat(3, 0, 8, g_021A79D8);
        if (len > 32)
            len = 32;
        buf.buffer[0] = 5;
        memcpy(buf.buffer + buf.len, pos, len);
        buf.len += len;
        break;
    case 4:
        gsDebugFormat(3, 0, 2, g_021A79F4);
        if (qrec->listed_state == -1)
            return;
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len < 2)
            return;
        qrec->listed_state = -1;
        qrec->adderror_callback(pos[0], pos + 1, qrec->udata);
        return;
    case 6:
        gsDebugFormat(3, 0, 8, g_021A7A14);
        for (i = 0; i < 4; i++)
            if (reqkey[i] != qrec->instance_key[i])
                return;
        if (len < 4)
            return;
        buf.buffer[0] = 7;
        memcpy(buf.buffer + buf.len, pos, 4);
        buf.len += 4;
        memcpy(&i, pos, 4);
        if (qr_got_recent_message(qrec, i) == 0)
            qr_process_client_message(qrec, pos + 4, len - 4);
        break;
    case 8:
        gsDebugFormat(3, 0, 0x10, g_021A7A38);
        return;
    case 10:
        gsDebugFormat(3, 0, 0x10, g_021A7A58);
        if (qrec->hr_callback == 0)
            return;
        qrec->hr_callback(qrec->udata);
        return;
    default:
        return;
    }

    sendto(qrec->hbsock, buf.buffer, buf.len, 0, sender, 8);
    gsDebugFormat(3, 0, 0x10, g_021A7A74, buf.len);
    gsDebugBinary(3, 0, 0x20, buf.buffer, buf.len);
}




/* sdk:      send_keepalive (qr2.o) */
void send_keepalive(qr2_implementation_s *qrec)
{
    qr2_buffer_s buf;

    buf.len = 0;
    qr_add_packet_header(&buf, 8, qrec->instance_key);
    sendto(qrec->hbsock, buf.buffer, buf.len, 0, (SOCSockAddr *)&qrec->hbaddr, 8);
    qrec->lastka = current_time();
    gsDebugFormat(3, 0, 0x10, g_021A7A9C, buf);
}




/* sdk:      send_heartbeat (qr2.o) */
void send_heartbeat(qr2_implementation_s *qrec, int statechanged)
{
    qr2_buffer_s buf;
    int i;
    char ipkey[20];

    buf.len = 0;
    qr_add_packet_header(&buf, 3, qrec->instance_key);
    for (i = 0; i < sQr2NumLocalIps; i++) {
        OS_SPrintf(ipkey, g_021A7AB8, i);
        qr2_buffer_addA(&buf, ipkey);
        qr2_buffer_addA(&buf, SOC_InetNtoA(local_ip_list[i]));
    }
    qr2_buffer_addA(&buf, g_021A7AC4);
    qr2_buffer_add_int(&buf, qrec->qport);
    qr2_buffer_addA(&buf, g_021A7AD0);
    qr2_buffer_addA(&buf, qrec->nat_negotiate ? g_021A7AD8 : g_021A7ADC);
    if (statechanged) {
        qr2_buffer_addA(&buf, g_021A7AE0);
        qr2_buffer_add_int(&buf, statechanged);
    }
    qr2_buffer_addA(&buf, g_021A7AF0);
    qr2_buffer_addA(&buf, qrec->gamename);
    if (qrec->pa_callback) {
        qr2_buffer_addA(&buf, g_021A7AFC);
        qr2_buffer_add_int(&buf, (int)qrec->publicip);
        qr2_buffer_addA(&buf, g_021A7B08);
        qr2_buffer_add_int(&buf, qrec->publicport);
    }
    if (statechanged != 2) {
        qr2_buffer_s temp;

        memcpy(&temp, &buf, buf.len);
        temp.len = buf.len;
        qr_build_query_reply(qrec, &temp, 0xff, 0, 0xff, 0, 0xff, 0);
        if (0x578 - temp.len < 1) {
            temp.len = buf.len;
            qr_build_query_reply(qrec, &temp, 0xff, 0, 0, 0, 0, 0);
        }
        memcpy(&buf, &temp, temp.len);
        buf.len = temp.len;
    } else {
        if (0x578 - buf.len >= 1)
            buf.buffer[buf.len++] = 0;
    }
    sendto(qrec->hbsock, buf.buffer, buf.len, 0, (SOCSockAddr *)&qrec->hbaddr, sizeof(SOCSockAddrIn));
    qrec->lastheartbeat = current_time();
    qrec->lastka = qrec->lastheartbeat;
    if (statechanged)
        qrec->userstatechangerequested = 0;
    gsDebugFormat(3, 0, 0x10, g_021A7B14, buf.len);
    gsDebugBinary(3, 0, 0x20, buf.buffer, buf.len);
}
