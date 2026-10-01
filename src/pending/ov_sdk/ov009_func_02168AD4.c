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
 * blocker:  near miss.  All 19 relocations resolve.  Control flow fixed this
 *           lane: the original test is `list != 0 && reason != 3 &&
 *           field8 > 7`, not the previously written negated
 *           `!(list != 0 && reason == 3) && field8 > 7` (which is
 *           `list == 0 || reason != 3`, a different predicate).  That cut
 *           size 684 -> 672 (function 668) and removed the extra branch.
 *           Remaining diff is register choice: the shared zero is r5 as the
 *           image, but the singleton `state` lands in r6 where the image has
 *           r4, cascading into both counting loops (image loop1 i=r6/size=sb,
 *           loop2 i=sb/size=sl/temp=r6; ours reuses lower regs).  Tested inert:
 *           `FriendState *state` declared first; splitting the reused loop
 *           counter into a distinct `k` merely regained 2 bytes, no colour
 *           change.  Needs a lever that pins `state` to r4.
 *
 *           Wave 8 findings: the global is a `FriendState` object in the
 *           sibling dwc_friend.o function (DWCi_UpdateFriendReq:
 *           `extern FriendState s_bNeedCloseStatsConnection;`).  Spelling it
 *           that way and accessing `s_bNeedCloseStatsConnection.field`
 *           directly (or `#define state (&...)`) cuts the diff 397 -> 393/392
 *           and moves the base from r6 to r5 (zero moves r5 -> r6), but the
 *           image wants base r4 / zero r5.  The residual tie: loop-1 index
 *           `i` always grabs r4 and pushes the base up one (r6 with the
 *           pointer local, r5 with the direct-object form); the plain `int i`
 *           outranks the global-base pointer.  Measured inert: declaration
 *           order of state/i/j/k/pidcnt (each earlier int below state shifts
 *           state up: 1st->r6, 3rd->r7, 4th->r8), const/volatile/register on
 *           state, loop-scoped `for (int ...)`, sibling-style `i=0; for(;;i++)`,
 *           unsigned counters, reusing `i` for loop 2 (worse, r7).  The extra
 *           4 bytes are loop-2's `mov r7,#0` for `j`, which the image instead
 *           coalesces with the loop-1 zero source in r7; freeing r7 there
 *           needs the base off r4/r5 first.
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

void func_02168AD4(void)
{
    FriendState *state = (FriendState *)s_bNeedCloseStatsConnection;
    int i;
    int j;
    int k;
    int pidcnt;

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
        if (state->fl->list != 0 && state->fl->reason != 3 && state->fl->field8 > 7) {
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
    for (k = 0; k < state->fl->count; k++) {
        if (DWC_GetFriendDataType(&state->fl->list[k]) == 3) {
            state->fl->field5c[j] = DWC_GetGsProfileId(DWCi_GetUserData(), &state->fl->list[k]);
            j++;
        }
    }
    if (DWCi_HandleGPError(gpGetReversBuddiesList(state->fl->connection, state->fl->field5c, pidcnt, 0, DWCi_GetReverseBuddiesCallback, 0)) != 0)
        return;
end:
    state->fl->field1f = 0;
}
