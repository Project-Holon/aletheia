/*
 * file:     unit_0219BA58_p01.c
 * unit:     yes
 * function: func_0219BA54, func_0219BA58, func_0219BA84, func_0219BAB4, func_0219BB54, func_0219BC2C, func_0219BE80, func_0219BED8, func_0219C154
 * address:  0x0219BA54
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by hand (round 5, lane s06): one canonical qr2 type block in qr2_types.h.
 * func_0219BA54 (a 4-byte bx lr, NatNegProgressCallback) was its own unit file.
 * func_0219BA54, BA58, BA84 and BE80 are file-local in the vendor object; they
 * are not static here because func_0219C3A4 and the later part call them.
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
 */

#include "../../matched/arm9_sdk/libc/string.h"
#include "qr2_types.h"

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

#define SWAP32(x) ((((x) >> 24) & 0xff) | (((x) >> 8) & 0xff00) | \
                   (((x) << 8) & 0xff0000) | (((x) << 24) & 0xff000000))

extern int gsDebugFormat(int theCat, int theType, unsigned char theLevel, const char *theTokenStr, ...);
extern int sendto(int sock, char *buf, int len, int flags, SOCSockAddr *addr, int tolen);
extern int gsiSafeStrcpyA(char *dst, const char *src, unsigned int n);
extern char *SOC_InetNtoA(SOCInAddr in);
extern int STD_TSScanf(char *src, char *fmt, ...);
extern void gs_encode(unsigned char *ins, int size, unsigned char *result);
extern void gs_encrypt(unsigned char *key, int key_len, unsigned char *buffer_ptr, int buffer_len);
extern int qr2_buffer_addA(qr2_buffer_s *outbuf, char *value);
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
