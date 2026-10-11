/*
 * file:     unit_0219BA58.c
 * unit:     yes
 * function: func_0219BA54, func_0219BA58, func_0219BA84, func_0219BAB4, func_0219BB54, func_0219BC2C, func_0219BE80, func_0219BED8, func_0219C154, func_0219C3A4, qr_got_recent_message, func_0219C5B8, qr2_check_ip_verify, qr2_expire_ip_verify, qr2_parse_queryA, func_0219CDBC, func_0219CE58
 * address:  0x0219BA54
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
 *   gsDebugFormat          0x0217D254  arm  ov009
 *   sendto                 0x0217ECA4  arm  ov009
 *   gsiSafeStrcpyA         0x021803BC  arm  ov009
 *   SOC_InetNtoA           0x0215FA9C  arm  ov009
 *   STD_TSScanf            0x0208CF34  arm
 *   gs_encode              0x0219B858  arm  ov009
 *   gs_encrypt             0x0219B918  arm  ov009
 *   qr2_buffer_addA        0x0219B660  arm  ov009
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
 *   g_021A7C90             0x021A7C90  data
 *   memcpy                 0x02092344  arm
 *   strlen                 0x0209477C  arm
 *   NNBeginNegotiationWithSocket 0x02199DFC  arm  ov009
 *   g_021A7858             0x021A7858  data
 *   g_021ACEF8             0x021ACEF8  data
 *   g_021ACEFC             0x021ACEFC  data
 *   gsDebugBinary          0x0217D32C  arm  ov009
 *   current_time           0x0217F264  arm  ov009
 *   OS_SPrintf             0x02084F40  arm
 *   memcmp                 0x020923F0  arm
 *   rand                   0x02094694  arm  ov009
 *   NNProcessData          0x0219AB8C  arm  ov009
 *   qr2_buffer_add_int     0x0219B628  arm  ov009
 *   current_rec            0x021A6600  data
 *   g_021A5A7C             0x021A5A7C  data
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
 *   num_local_ips          0x021AE9A0  data
 *   local_ip_list          0x021AE9A4  data
 *   @13818                 0x021A1B64  data
 */
#include "../../matched/arm9_sdk/libc/string.h"
#include "qr2_types.h"

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

extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern int sendto(int sock, char *buf, int len, int flags, SOCSockAddr *addr, int tolen);
extern int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
extern char *SOC_InetNtoA(SOCInAddr in);
extern int STD_TSScanf(char *src, char *fmt, ...);
extern void gs_encode(unsigned char *ins, int size, unsigned char *result);
extern void gs_encrypt(unsigned char *key, int key_len, unsigned char *buffer_ptr, int buffer_len);
extern int qr2_buffer_addA(qr2_buffer_s *outbuf, char *value);
extern int NNBeginNegotiationWithSocket(int gamesocket, int cookie, int clientindex,
                                        void (*progresscallback)(int, void *),
                                        void (*completedcallback)(int, int, SOCSockAddrIn *, void *), void *userdata);
extern void gsDebugBinary(int theCat, int theType, unsigned char theLevel, char *theBuffer, int theLength);
extern unsigned int current_time(void);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int memcmp(const void *s1, const void *s2, int n);
extern int rand(void);
extern void NNProcessData(char *data, int len, SOCSockAddrIn *fromaddr);
extern int qr2_buffer_add_int(qr2_buffer_s *outbuf, int value);
void func_0219BA54(int state, void *userdata);
void func_0219BA58(int result, int gamesocket, SOCSockAddrIn *remoteaddr, void *userdata);
void func_0219BA84(qr2_buffer_s *buf, char ptype, char *reqkey);
void func_0219BAB4(qr2_implementation_s *qrec, qr2_buffer_s *buf, char *challenge, int challengelen);
void func_0219BB54(qr2_implementation_s *qrec, char *buffer);
void func_0219BC2C(qr2_implementation_s *qrec, qr2_buffer_s *buf, qr2_key_type keytype, int keycount, unsigned char *keys);
void func_0219BE80(qr2_implementation_s *qrec, qr2_buffer_s *buf, int serverkeycount, unsigned char *serverkeys, int playerkeycount, unsigned char *playerkeys, int teamkeycount, unsigned char *teamkeys);
int func_0219BED8(qr2_implementation_s *qrec, qr2_buffer_s *buf, QRSplitQueryProgress *progress);
void func_0219C154(qr2_implementation_s *qrec, qr2_buffer_s *buf, unsigned char *qdata, int len, SOCSockAddr *sender);
void func_0219C3A4(qr2_implementation_s *qrec, char *buf, int len);
int func_0219C5B8(qr2_implementation_s *qrec, qr2_buffer_s *buf, SOCSockAddrIn *sender);
void qr2_expire_ip_verify(qr2_implementation_s *qrec);
void qr2_parse_queryA(qr2_implementation_s *qrec, char *query, int len, SOCSockAddr *sender);
void func_0219CDBC(qr2_implementation_s *qrec);
void func_0219CE58(qr2_implementation_s *qrec, int statechanged);
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
extern char *g_021A7C90[];
extern char g_021A7858[];
extern int g_021ACEF8;
extern char g_021ACEFC[];
extern qr2_implementation_s *current_rec;
extern struct Magic6 g_021A5A7C;
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
extern int num_local_ips;
extern SOCInAddr local_ip_list[5];


/* sdk:      NatNegProgressCallback (qr2.o) */
void func_0219BA54(int state, void *userdata)
{
}


/* sdk:      NatNegCompletedCallback (qr2.o) */
void func_0219BA58(int result, int gamesocket, SOCSockAddrIn *remoteaddr, void *userdata)
{
    qr2_implementation_s *qrec = userdata;

    if (qrec->cc_callback == 0)
        return;
    if (result != 0)
        return;
    qrec->cc_callback(gamesocket, remoteaddr, qrec->udata);
}


/* sdk:      qr_add_packet_header (qr2.o) */
void func_0219BA84(qr2_buffer_s *buf, char ptype, char *reqkey)
{
    buf->buffer[0] = ptype;
    *(key4_t *)&buf->buffer[1] = *(key4_t *)reqkey;
    buf->len = 5;
}


/* sdk:      compute_challenge_response (qr2.o) */
void func_0219BAB4(qr2_implementation_s *qrec, qr2_buffer_s *buf, char *challenge, int challengelen)
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
void func_0219BB54(qr2_implementation_s *qrec, char *buffer)
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
void func_0219BC2C(qr2_implementation_s *qrec, qr2_buffer_s *buf, qr2_key_type keytype, int keycount, unsigned char *keys)
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
            k = g_021A7C90[kb.keys[i]];
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
void func_0219BE80(qr2_implementation_s *qrec, qr2_buffer_s *buf, int serverkeycount, unsigned char *serverkeys,
                          int playerkeycount, unsigned char *playerkeys,
                          int teamkeycount, unsigned char *teamkeys)
{
    func_0219BC2C(qrec, buf, key_server, serverkeycount, serverkeys);
    func_0219BC2C(qrec, buf, key_player, playerkeycount, playerkeys);
    func_0219BC2C(qrec, buf, key_team, teamkeycount, teamkeys);
}


/* sdk:      qr_build_split_query_reply (qr2.o) */
int func_0219BED8(qr2_implementation_s *qrec, qr2_buffer_s *buf, QRSplitQueryProgress *progress)
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
            if (qr2_buffer_addA(buf, g_021A7C90[aRegisteredKeyIndex]) == 0)
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
void func_0219C154(qr2_implementation_s *qrec, qr2_buffer_s *buf, unsigned char *qdata, int len, SOCSockAddr *sender)
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
        while (func_0219BED8(qrec, buf, &progress) == 1) {
            sendto(qrec->hbsock, buf->buffer, buf->len, 0, sender, 8);
            buf->len = 5;
            if (progress.mPacketNum > 7)
                return;
        }
        gsDebugFormat(3, 0, 0x10, g_021A7804, progress.mPacketNum);
        return;
    }

    gsDebugFormat(3, 0, 0x10, g_021A7830);
    func_0219BE80(qrec, buf, serverkeycount, serverkeys, playerkeycount, playerkeys, teamkeycount, teamkeys);
    sendto(qrec->hbsock, buf->buffer, buf->len, 0, sender, 8);
}



/*
 * sdk:      qr_process_client_message (libdwcgsqr2.TWL.HYB.a qr2.o)
 *
 * The six natneg magic bytes are a local initialiser; the vendor object's
 * template for them sits at 0x021A1B64.
 */
void func_0219C3A4(qr2_implementation_s *qrec, char *buf, int len)
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
            if (g_021ACEF8 != 1) {
                g_021ACEF8 = 1;
                gsiSafeStrcpyA(g_021ACEFC, qrec->gamename, 64);
            }
            NNBeginNegotiationWithSocket(qrec->hbsock, cookie, 1, func_0219BA54, func_0219BA58, qrec);
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
int func_0219C5B8(qr2_implementation_s *qrec, qr2_buffer_s *buf, SOCSockAddrIn *sender)
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
        if (firstFreeIndex == -1 && qrec->ipverify[i].addr.addr.addr == 0)
            firstFreeIndex = i;
        /* Count any indexes that match this IP/port */
        if (qrec->ipverify[i].addr.addr.addr == sender->addr.addr &&
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
        if (sender->addr.addr == qrec->ipverify[i].addr.addr.addr &&
            sender->port == qrec->ipverify[i].addr.port &&
            ipverify == qrec->ipverify[i].challenge) {
            qrec->ipverify[i].addr.addr.addr = 0;
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
        if (qrec->ipverify[i].addr.addr.addr != 0 &&
            now - qrec->ipverify[i].time > 0xfa0)
            qrec->ipverify[i].addr.addr.addr = 0;
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
    if (len >= 6 && memcmp(query, ((unsigned char *)&g_021A5A7C), 6) == 0) {
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
    func_0219BA84(&buf, ptype, reqkey);

    switch (ptype) {
    case 9:
        gsDebugFormat(3, 0, 8, g_021A791C);
        if (func_0219C5B8(qrec, &buf, (SOCSockAddrIn *)sender) == 0)
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
        func_0219C154(qrec, &buf, (unsigned char *)pos, len, sender);
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
                func_0219BB54(qrec, pos + len - 13);
            else
                gsDebugFormat(3, 0, 8, g_021A79A8);
        }
        func_0219BAB4(qrec, &buf, pos, len);
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
            func_0219C3A4(qrec, pos + 4, len - 4);
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
void func_0219CDBC(qr2_implementation_s *qrec)
{
    qr2_buffer_s buf;

    buf.len = 0;
    func_0219BA84(&buf, 8, qrec->instance_key);
    sendto(qrec->hbsock, buf.buffer, buf.len, 0, (SOCSockAddr *)&qrec->hbaddr, 8);
    qrec->lastka = current_time();
    gsDebugFormat(3, 0, 0x10, g_021A7A9C, buf);
}



/* sdk:      send_heartbeat (qr2.o) */
void func_0219CE58(qr2_implementation_s *qrec, int statechanged)
{
    qr2_buffer_s buf;
    int i;
    char ipkey[20];

    buf.len = 0;
    func_0219BA84(&buf, 3, qrec->instance_key);
    for (i = 0; i < num_local_ips; i++) {
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
        func_0219BE80(qrec, &temp, 0xff, 0, 0xff, 0, 0xff, 0);
        if (0x578 - temp.len < 1) {
            temp.len = buf.len;
            func_0219BE80(qrec, &temp, 0xff, 0, 0, 0, 0, 0);
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
