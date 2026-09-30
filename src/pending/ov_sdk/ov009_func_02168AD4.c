/*
 * function: DWCi_FriendProcess
 * address:  0x02168AD4
 * packet:   pkt_ov009_02168AD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      DWCi_FriendProcess (libdwcmatch.TWL.HYB.a dwc_friend.o)
 *
 * blocker:  near miss.  All 19 relocations resolve and the body/control flow
 *           match (including the odd fl->list==0 -> DWCi_GPProcess early
 *           exit).  Remaining diff is register choice: the singleton lands
 *           in r6 and the shared zero in r7, the reverse of the image
 *           (state r4, zero r5), which cascades into the two counting loops
 *           and costs 4 bytes.  Needs a declaration/init-order nudge.
 *           Re-tested (lane U34) and inert at 684 bytes / 428: `FriendState
 *           *state` declared first, `int i, j, pidcnt;` on one line, and
 *           `state` declared but assigned on its own later statement.  Note
 *           this build is not a pure rotation of the image - image {state r4,
 *           zero r5, singleton-loaded-at-+8}, ours {state sb, zero r6} - and
 *           the two stores at +0x80 are emitted in the reverse order
 *           (image `str r0,[r4,#4]` then `str r5,[r4]`; ours `str r6,[sb]`
 *           then `str r0,[sb,#4]`).  First divergence: image `ldr r4, [pc,
 *           #0x28c]` | ours `ldr sb, [pc, #0x290]`.
 *
 * symbols:
 *   DWCi_IsError                    0x02059F38 arm
 *   DWCi_GPProcess                  0x02169210 arm ov009
 *   DWCi_GetPersCallbackLevel       0x02169FE4 arm ov009
 *   IsStatsConnected                0x02193D64 arm ov009
 *   PersistThink                    0x02193D80 arm ov009
 *   CloseStatsConnection            0x02193D00 arm ov009
 *   DWCi_UpdateFriendReq            0x021692C4 arm ov009
 *   DWC_GetFriendDataType           0x020591CC arm
 *   DWCi_EndUpdateServers           0x02169568 arm ov009
 *   DWC_Alloc                       0x0205A16C arm
 *   DWCi_StopFriendProcess          0x02168E50 arm ov009
 *   DWCi_GetUserData                0x0216A39C arm ov009
 *   DWC_GetGsProfileId              0x020598EC arm
 *   gpGetReversBuddiesList          0x02186564 arm ov009
 *   DWCi_HandleGPError              0x021698C0 arm ov009
 *   DWCi_GetReverseBuddiesCallback  0x0216A020 arm ov009
 *   s_bNeedCloseStatsConnection     0x021AA860 data
 */

typedef struct DWCstAccFriendData {
    char data[0xc];
} DWCstAccFriendData;

typedef struct FriendList {
    int field0;
    void **connection;
    int field8;
    int pad1;
    int pad2;
    int count;
    DWCstAccFriendData *list;
    unsigned char field1c;
    unsigned char pad3[0x1e - 0x1d];
    unsigned char reason;
    unsigned char field1f;
    unsigned char pad4[0x5c - 0x20];
    int *field5c;
} FriendList;

typedef struct FriendState {
    int field0;
    int field4;
    int pad2;
    FriendList *fl;
} FriendState;

extern int DWCi_IsError(void);
extern int DWCi_GPProcess(void);
extern unsigned long DWCi_GetPersCallbackLevel(void);
extern int IsStatsConnected(void);
extern int PersistThink(void);
extern void CloseStatsConnection(void);
extern void DWCi_UpdateFriendReq(DWCstAccFriendData *friendList, int friendListLen);
extern int DWC_GetFriendDataType(DWCstAccFriendData *frienddata);
extern void DWCi_EndUpdateServers(void);
extern void *DWC_Alloc(int name, unsigned long size);
extern void DWCi_StopFriendProcess(int error, int errorCode);
extern DWCstAccFriendData *DWCi_GetUserData(void);
extern int DWC_GetGsProfileId(void *userdata, DWCstAccFriendData *frienddata);
extern int gpGetReversBuddiesList(void **connection, int *targets, int numOfTargets, int blocking, void (*callback)(void **, void *, void *), void *param);
extern int DWCi_HandleGPError(int result);
extern void DWCi_GetReverseBuddiesCallback(void **connection, void *arg, void *param);
extern char s_bNeedCloseStatsConnection[];

void DWCi_FriendProcess(void)
{
    int i;
    int j;
    int pidcnt;
    FriendState *state = (FriendState *)s_bNeedCloseStatsConnection;

    if (state->fl == 0)
        return;
    if (DWCi_IsError())
        return;

    if (state->fl->list == 0) {
        if (state->fl->connection == 0 || *state->fl->connection == 0)
            return;
        DWCi_GPProcess();
        return;
    }

    if (DWCi_GetPersCallbackLevel() != 0 || IsStatsConnected()) {
        state->field4 = 1;
        state->field0 = 0;
        PersistThink();
        state->field4 = 0;
        if (state->field0 == 1) {
            state->field0 = 0;
            CloseStatsConnection();
        }
    }

    if (state->fl->connection != 0 && *state->fl->connection != 0) {
        if (DWCi_GPProcess() != 0)
            return;
        if (state->fl->field0 == 0)
            return;
        if (!(state->fl->list != 0 && state->fl->reason == 3) && state->fl->field8 > 7) {
            if (state->fl->reason <= 1)
                DWCi_UpdateFriendReq(state->fl->list, state->fl->count);
            if (state->fl->field1c >= state->fl->count) {
                state->fl->reason = 3;
                state->fl->field1f++;
            }
        }
    }

    if (state->fl->field1f < 2)
        return;
    if (state->fl->connection == 0 || *state->fl->connection == 0)
        goto end;

    pidcnt = 0;
    for (i = 0; i < state->fl->count; i++)
        if (DWC_GetFriendDataType(&state->fl->list[i]) == 3)
            pidcnt++;
    if (pidcnt == 0) {
        state->fl->field1f = 0;
        DWCi_EndUpdateServers();
        return;
    }
    state->fl->field5c = DWC_Alloc(4, pidcnt * 4);
    if (state->fl->field5c == 0) {
        DWCi_StopFriendProcess(9, (int)0xfffeee8fU);
        return;
    }
    j = 0;
    for (i = 0; i < state->fl->count; i++) {
        if (DWC_GetFriendDataType(&state->fl->list[i]) == 3) {
            state->fl->field5c[j] = DWC_GetGsProfileId(DWCi_GetUserData(), &state->fl->list[i]);
            j++;
        }
    }
    if (DWCi_HandleGPError(gpGetReversBuddiesList(state->fl->connection, state->fl->field5c, pidcnt, 0, DWCi_GetReverseBuddiesCallback, 0)) != 0)
        return;
end:
    state->fl->field1f = 0;
}
