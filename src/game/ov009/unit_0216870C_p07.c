/*
 * file:     unit_0216870C_p07.c
 * unit:     yes
 * function: DWCi_GPProfileSearchCallback
 * address:  0x02169934
 * packet:   pkt_ov009_02169934
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * lane08 (2026-09-30): the {r5,r6,r7} rotation was the second-loop counter's
 *   VARIABLE IDENTITY.  A fresh `j` colours as r5, pushing the persistent
 *   match-index offset to r7 and the scale temp to r6.  Reusing `i` for the
 *   second loop (no separate `j`) merges the two loop live ranges and gives the
 *   image's r5=scale temp, r6=param*0xc, r7=second-loop counter (rotated down
 *   from a-o.., i.e. docs/idioms/reusing-a-loop-variable-across-phases-changes-the-allocation.md).
 * sdk:      DWCi_GPProfileSearchCallback (libdwcmatch.TWL.HYB.a dwc_friend.o)
 *
 * symbols:
 *   DWC_GetFriendDataType            0x020591cc arm
 *   DWCi_RefreshFriendListForth      0x021695f0 arm
 *   gpGetBuddyIndex                  0x02186108 arm
 *   DWCi_HandleGPError               0x021698c0 arm
 *   DWCi_GPSendBuddyRequest          0x021697d8 arm
 *   DWCi_SetSentBuddyReqFlag         0x020592a0 arm
 *   DWC_SetGsProfileId               0x02059a10 arm
 *   DWCi_SetBuddyFriendData          0x02059214 arm
 *   DWCi_SetReverseBuddyFlag         0x02059240 arm
 *   DWC_IsBuddyFriendData            0x0205912c arm
 *   DWCi_SetExpIsBuddyFriendFlag     0x02059270 arm
 *   DWCi_CallBuddyFriendCallback     0x02169174 arm
 *   s_bNeedCloseStatsConnection      0x021aa860 data
 */

typedef union DWCstAccFriendData {
    char data[0xc];
} DWCstAccFriendData;

typedef struct GPProfileSearchMatch {
    int profileID;
    char pad[0xb0 - 4];
} GPProfileSearchMatch;

typedef struct GPProfileSearchResponseArg {
    int result;
    int numMatches;
    int more;
    GPProfileSearchMatch *matches;
} GPProfileSearchResponseArg;

typedef struct FriendList {
    int field0;
    void **connection;
    int field8;
    int pad1;
    int pad2;
    int count;
    DWCstAccFriendData *list;
    unsigned char field1c;
    unsigned char field1d;
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

extern int DWC_GetFriendDataType(DWCstAccFriendData *frienddata);
extern int DWCi_RefreshFriendListForth(DWCstAccFriendData *friendList, int index, int profileID);
extern int gpGetBuddyIndex(void **connection, int profile, int *index);
extern int DWCi_HandleGPError(int result);
extern int DWCi_GPSendBuddyRequest(int profileID);
extern void DWCi_SetSentBuddyReqFlag(DWCstAccFriendData *frienddata, int setflag);
extern void DWC_SetGsProfileId(DWCstAccFriendData *frienddata, int gs_profile_id);
extern void DWCi_SetBuddyFriendData(DWCstAccFriendData *frienddata);
extern void DWCi_SetReverseBuddyFlag(DWCstAccFriendData *frienddata, int setflag);
extern int DWC_IsBuddyFriendData(DWCstAccFriendData *frienddata);
extern void DWCi_SetExpIsBuddyFriendFlag(DWCstAccFriendData *frienddata, int setflag);
extern void DWCi_CallBuddyFriendCallback(int index);
extern FriendState s_bNeedCloseStatsConnection;

#define FL (s_bNeedCloseStatsConnection.fl)

void DWCi_GPProfileSearchCallback(void **connection, GPProfileSearchResponseArg *arg, void *param)
{
    int i;
    int idx;
    int match_index = (int)param;

    if (arg->result != 0 || arg->numMatches == 0)
        goto err;
    if (DWC_GetFriendDataType(&FL->list[match_index]) == 0)
        goto err;
    if (FL->field0 != 1)
        return;

    for (i = 0; i < arg->numMatches; i++) {
        if (DWCi_RefreshFriendListForth(FL->list, match_index, arg->matches[i].profileID) != 0) {
            FL->field1c++;
            FL->reason = 1;
            arg->more = 0x601;
            return;
        }
    }

    for (i = 0; i < arg->numMatches; i++) {
        DWCi_HandleGPError(gpGetBuddyIndex(connection, arg->matches[i].profileID, &idx));
        if (idx == -1) {
            DWCi_GPSendBuddyRequest(arg->matches[i].profileID);
            DWCi_SetSentBuddyReqFlag(&FL->list[match_index], 1);
        } else {
            DWC_SetGsProfileId(&FL->list[match_index], arg->matches[0].profileID);
            DWCi_SetBuddyFriendData(&FL->list[match_index]);
            DWCi_SetReverseBuddyFlag(&FL->list[match_index], 1);
            if (DWC_IsBuddyFriendData(&FL->list[match_index]) != 0)
                DWCi_SetExpIsBuddyFriendFlag(&FL->list[match_index], 1);
            DWCi_CallBuddyFriendCallback(match_index);
            FL->field1c++;
            FL->reason = 1;
            arg->more = 0x601;
            FL->field1d = 1;
            return;
        }
    }

    if (arg->more == 0x600)
        return;
    FL->field1c++;
    FL->reason = 1;
    return;

err:
    if (arg->result != 0) {
        DWCi_HandleGPError(arg->result);
        return;
    }
    if (FL->field0 != 1 && DWC_GetFriendDataType(&FL->list[match_index]) != 0)
        return;
    FL->field1c++;
    FL->reason = 1;
}
