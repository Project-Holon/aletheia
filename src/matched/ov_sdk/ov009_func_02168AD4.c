/*
 * function: func_02168AD4
 * address:  0x02168AD4
 * packet:   pkt_ov009_02168AD4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DWCi_FriendProcess (libdwcmatch.TWL.HYB.a dwc_friend.o)
 *
 * closed (lane 09, 2026-10-01): the object's statics (s_bNeedCloseStatsConnection +0,
 *   s_bInPersistThink +4, stpFriendCnt +0xc, all local data in dwc_friend.o) are defined
 *   here as TU `static ... = 0;` so mwcc pools them on one .bss anchor; that anchor web
 *   colours first (base r4, zero r5, then i/j/pidcnt r6/r7/r8) and the stpFriendCnt
 *   reload after loop 2 comes back (680 B). An extern struct at the anchor colours i
 *   first and CSEs the reload. Declaration order sets the .bss layout (third declared
 *   lands at +0, fourth at +0xc). Locals are the DWARF set (gpResult, i, j, pidcnt);
 *   field8 is unsigned (bls).
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
    unsigned int field8;
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
static int s_bInCloseStatsConnection = 0;
static int s_bInPersistThink = 0;
static int s_bNeedCloseStatsConnection = 0;
static FriendList *stpFriendCnt = 0;

void func_02168AD4(void)
{
    int gpResult;
    int i;
    int j;
    int pidcnt;

    if (stpFriendCnt == 0)
        return;
    if (DWCi_IsError())
        return;

    if (stpFriendCnt->list == 0) {
        if (stpFriendCnt->connection == 0 || *stpFriendCnt->connection == 0)
            return;
        DWCi_GPProcess();
        return;
    }

    if (DWCi_GetPersCallbackLevel() != 0 || IsStatsConnected()) {
        s_bInPersistThink = 1;
        s_bNeedCloseStatsConnection = 0;
        PersistThink();
        s_bInPersistThink = 0;
        if (s_bNeedCloseStatsConnection == 1) {
            s_bNeedCloseStatsConnection = 0;
            CloseStatsConnection();
        }
    }

    if (stpFriendCnt->connection != 0 && *stpFriendCnt->connection != 0) {
        if (DWCi_GPProcess() != 0)
            return;
        if (stpFriendCnt->field0 == 0)
            return;
        if (stpFriendCnt->list != 0 && stpFriendCnt->reason != 3 && stpFriendCnt->field8 > 7) {
            if (stpFriendCnt->reason <= 1)
                DWCi_UpdateFriendReq(stpFriendCnt->list, stpFriendCnt->count);
            if (stpFriendCnt->field1c >= stpFriendCnt->count) {
                stpFriendCnt->reason = 3;
                stpFriendCnt->field1f++;
            }
        }
    }

    if (stpFriendCnt->field1f < 2)
        return;
    if (stpFriendCnt->connection == 0 || *stpFriendCnt->connection == 0)
        goto end;

    j = 0;
    pidcnt = 0;
    for (i = 0; i < stpFriendCnt->count; i++)
        if (DWC_GetFriendDataType(&stpFriendCnt->list[i]) == 3)
            pidcnt++;
    if (pidcnt == 0) {
        stpFriendCnt->field1f = 0;
        DWCi_EndUpdateServers();
        return;
    }
    stpFriendCnt->field5c = DWC_Alloc(4, pidcnt * 4);
    if (stpFriendCnt->field5c == 0) {
        DWCi_StopFriendProcess(9, (int)0xfffeee8fU);
        return;
    }
    for (i = 0; i < stpFriendCnt->count; i++) {
        if (DWC_GetFriendDataType(&stpFriendCnt->list[i]) == 3) {
            stpFriendCnt->field5c[j] = DWC_GetGsProfileId(DWCi_GetUserData(), &stpFriendCnt->list[i]);
            j++;
        }
    }
    gpResult = gpGetReversBuddiesList(stpFriendCnt->connection, stpFriendCnt->field5c, pidcnt, 0, DWCi_GetReverseBuddiesCallback, 0);
    if (DWCi_HandleGPError(gpResult) != 0)
        return;
end:
    stpFriendCnt->field1f = 0;
}
