/*
 * function: func_0219BED8
 * address:  0x0219BED8
 * packet:   pkt_ov009_0219BED8
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      qr_build_split_query_reply (qr2.o)
 *
 * symbols:
 *   g_021A76D8  0x021A76D8  data
 *   g_021A7C90  0x021A7C90  data
 *   func_0219B660  0x0219B660  arm  ov009
 *
 * notes: DIFF by one instruction (636 B object, 632 B here). At the top of the key-type
 * loop body the object reloads progress->mCurKeyType (ldr r0, [r8]) for the
 * key_list_callback argument after the numkeys test; this build reuses the value of
 * the loop test, so numkeys lands in r1 instead of r0 and every later pool offset
 * and branch shifts by 4. Tried: int / enum / cast field and parameter types,
 * while / for / do-while / if+goto loop shapes, for-increment, a named block local,
 * moving the call, volatile (reloads everywhere, 12 B too long).
 */

typedef struct qr2_buffer_s {
    char buffer[0x578];
    int len;
} qr2_buffer_s;

typedef struct qr2_keybuffer_s {
    unsigned char keys[256];
    int numkeys;
} qr2_keybuffer_s;

typedef enum { QRSplitQueryState_Server, QRSplitQueryState_Player, QRSplitQueryState_Team, QRSplitQueryState_Finished } QRSplitQueryState;
typedef enum { key_server, key_player, key_team } qr2_key_type;
typedef struct QRSplitQueryProgress {
    QRSplitQueryState mState;
    int mPacketNum;
    int mCurKeyIndex;
    int mNumPlayersOrTeams;
    int mCurSubCount;
    qr2_keybuffer_s mKeyBuffer;
} QRSplitQueryProgress;

typedef struct qr2_implementation_s {
    unsigned char pad0[0x88];
    void (*server_key_callback)(int keyid, qr2_buffer_s *outbuf, void *userdata);
    void (*player_key_callback)(int keyid, int index, qr2_buffer_s *outbuf, void *userdata);
    void (*team_key_callback)(int keyid, int index, qr2_buffer_s *outbuf, void *userdata);
    void (*key_list_callback)(qr2_key_type keytype, qr2_keybuffer_s *keybuffer, void *userdata);
    int (*playerteam_count_callback)(qr2_key_type keytype, void *userdata);
    unsigned char pad9C[0x78];
    void *udata;
} qr2_implementation_s;

extern char g_021A76D8[];
extern char *g_021A7C90[];
extern int func_0219B660(qr2_buffer_s *outbuf, char *value);

int func_0219BED8(qr2_implementation_s *qrec, qr2_buffer_s *buf, QRSplitQueryProgress *progress)
{
    unsigned char *packetNumPos;
    int aRegisteredKeyIndex;

    if (progress->mState >= 3)
        return 0;
    if (0x578 - buf->len < 32)
        return 0;

    func_0219B660(buf, g_021A76D8);
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
            if (func_0219B660(buf, g_021A7C90[aRegisteredKeyIndex]) == 0)
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
