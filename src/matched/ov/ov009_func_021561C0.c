/*
 * function: DWC_RAP_StepSession
 * address:  0x021561C0
 * packet:   pkt_ov009_021561C0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   _pRapWork     0x021A8264  data  ov009  a4
 *   DWC_RAP_FlushDeletedFriends  0x02156CF4  thumb  ov009
 *   DWC_ProcessFriendsMatch  0x0216AE88  arm
 *   DWC_RAP_PollFriendStatus  0x021567B8  thumb  ov009
 *   VCT_MAIN_Update  0x021AEE14  thumb  ov013
 *   DWC_GetAIDBitmap  0x0216B908  arm
 *   DWC_GetMyAID  0x0216B838  arm
 *   VCT_MAIN_ConnectPeers  0x021AF238  thumb  ov013
 *   DWC_RAP_HandleError  0x02155F58  thumb  ov009
 *   DWC_RAP_SendHeartbeat  0x0215615C  thumb  ov009
 *   DWC_RAP_ClearPeerCounters  0x02155C70  thumb  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    char pad[0x754];
    int state;          /* 0x754 */
    char pad1[0x760 - 0x758];
    int f760;           /* 0x760 */
    int n;              /* 0x764 */
    int aid;            /* 0x768 */
    int f76c;           /* 0x76c */
    char pad2[0x782 - 0x770];
    short s782;         /* 0x782 */
    int cnt[3];         /* 0x784 */
    int f790;           /* 0x790 */
    u16 h794;           /* 0x794 */
    u16 h796;           /* 0x796 */
    char pad3[0x79f - 0x798];
    u8 b79f;            /* 0x79f */
} G;

extern G *_pRapWork;
void DWC_RAP_FlushDeletedFriends(void);
void DWC_ProcessFriendsMatch(void);
void DWC_RAP_PollFriendStatus(void);
void VCT_MAIN_Update(int);
int DWC_GetAIDBitmap(void);
unsigned char DWC_GetMyAID(void);
int VCT_MAIN_ConnectPeers(u32 mask, int n);
int DWC_RAP_HandleError(void);
int DWC_RAP_SendHeartbeat(u32 idx);
void DWC_RAP_ClearPeerCounters(void);

int DWC_RAP_StepSession(void)
{
    G *g;
    int i;

    DWC_RAP_FlushDeletedFriends();
    DWC_ProcessFriendsMatch();
    DWC_RAP_PollFriendStatus();
    if (_pRapWork->f76c != 0) {
        int v;
        if (_pRapWork->h794 == 1 && _pRapWork->f790 == 1 && _pRapWork->h796 == 1)
            v = 0;
        else
            v = 1;
        VCT_MAIN_Update(v);
        g = _pRapWork;
        if (g->aid != DWC_GetAIDBitmap() && g->b79f == 0 && g->s782 != 0) {
            if (VCT_MAIN_ConnectPeers(DWC_GetAIDBitmap(), DWC_GetMyAID()) != 0)
                _pRapWork->aid = DWC_GetAIDBitmap();
        }
    }
    if (_pRapWork->state == 0x14) {
        int r = DWC_RAP_HandleError();
        if (r == 0)
            return 0x3eb;
        return r;
    }
    if (_pRapWork->state == 0x13)
        return 0x3ec;
    if (_pRapWork->state == 9 || _pRapWork->state == 10) {
        for (i = 0; i < _pRapWork->n; i++) {
            if (_pRapWork->cnt[i]++ >= 0xf0 && _pRapWork->f760 == 0 && DWC_RAP_SendHeartbeat(i) != 0) {
                DWC_RAP_ClearPeerCounters();
                break;
            }
        }
    }
    return DWC_RAP_HandleError();
}
