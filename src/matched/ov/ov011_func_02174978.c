/*
 * function: func_02174978
 * address:  0x02174978
 * packet:   pkt_ov011_02174978
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   GFL_NET_IsParentAid  0x0203D378  arm
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GAME_DATA_SetEnterMode  0x02012B4C  thumb
 *   INTRUDE_COMM_SendMemberCount  0x02173758  thumb  ov011
 *   INTRUDE_COMM_UpdateSeasonState  0x02174AE0  thumb  ov011
 *   INTRUDE_COMM_UpdateRequest  0x0217546C  thumb  ov011
 *   INTRUDE_COMM_RefreshSelfRecord  0x02174E3C  thumb  ov011
 *   INTRUDE_COMM_SendStatusRecord  0x02173828  thumb  ov011
 *   INTRUDE_COMM_UpdateMemberJoin  0x02174B2C  thumb  ov011
 *   INTRUDE_COMM_UpdateMemberLeave  0x02174B7C  thumb  ov011
 *   INTRUDE_COMM_UpdatePendingNotices  0x02174BC4  thumb  ov011
 *   INTRUDE_COMM_SendTally  0x021743B4  thumb  ov011
 *   INTRUDE_COMM_UpdateSession  0x021757C4  thumb  ov011
 *   INTRUDE_CMD_SendProfile  0x02174374  thumb  ov011
 *   INTRUDE_COMM_UpdateUnionInfoAndReturnSlots  0x02174C38  thumb  ov011
 *   INTRUDE_COMM_UpdatePageRequests  0x02174CCC  thumb  ov011
 *   INTRUDE_COMM_UpdateQueuedRequest  0x02174DF4  thumb  ov011
 *   INTRUDE_COMM_UpdateSelfRecord  0x021752DC  thumb  ov011
 *   INTRUDE_COMM_SendPeerStatus  0x02173984  thumb  ov011
 *   GAME_DATA_IsSaving  0x02012E40  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   INTRUDE_COMM_IsValidProfileCode  0x021756D0  thumb  ov011
 *   func_0200BE84  0x0200BE84  thumb
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00269.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Bits;

struct Big;
struct BigObj;
extern u32 func_02026478(void *obj);
extern u32 GFL_NET_IsParentAid(void);
extern int GFL_NET_GetNegotiationNum(void);
extern void GAME_DATA_SetEnterMode(struct BigObj *p, u8 v);
extern int INTRUDE_COMM_SendMemberCount(int a, int b, ...);
extern void INTRUDE_COMM_UpdateSeasonState(u8 *);
extern void INTRUDE_COMM_UpdateRequest(u8 *);
extern void INTRUDE_COMM_RefreshSelfRecord(u8 *);
extern int INTRUDE_COMM_SendStatusRecord(char *p);
extern void INTRUDE_COMM_UpdateMemberJoin(u8 *);
extern void INTRUDE_COMM_UpdateMemberLeave(u8 *);
extern void INTRUDE_COMM_UpdatePendingNotices(u8 *);
extern int INTRUDE_COMM_SendTally(char *p);
extern void INTRUDE_COMM_UpdateSession(u8 *, u8 *);
extern int INTRUDE_CMD_SendProfile(int *a);
extern void INTRUDE_COMM_UpdateUnionInfoAndReturnSlots(u8 *);
extern void INTRUDE_COMM_UpdatePageRequests(u8 *);
extern void INTRUDE_COMM_UpdateQueuedRequest(u8 *);
extern int INTRUDE_COMM_UpdateSelfRecord(u8 *);
extern int INTRUDE_COMM_SendPeerStatus(char *p, int b);
extern u8 GAME_DATA_IsSaving(const u8 *o);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern int INTRUDE_COMM_IsValidProfileCode(u32 x);
extern void func_0200BE84(void *, u8 *);

void func_02174978(u8 *s)
{
    int h;
    int n;
    void *w;

    h = func_02026478((void *)(((struct Obj00269 *)s)->f4));
    if (GFL_NET_IsParentAid() == 1) {
        n = GFL_NET_GetNegotiationNum();
        if (n > s[0x902]) {
            s[0x902] = n;
            s[0x903] = 1;
            GAME_DATA_SetEnterMode((struct BigObj *)h, s[0x902]);
        }
    }
    if (s[0x903] == 1 && INTRUDE_COMM_SendMemberCount((int)s, s[0x902]) == 1) {
        s[0x903] = 0;
    }
    INTRUDE_COMM_UpdateSeasonState(s);
    INTRUDE_COMM_UpdateRequest(s);
    if (s[0x8fe] == 1) {
        INTRUDE_COMM_RefreshSelfRecord(s);
        INTRUDE_COMM_SendStatusRecord((char *)s);
    }
    INTRUDE_COMM_UpdateMemberJoin(s);
    INTRUDE_COMM_UpdateMemberLeave(s);
    INTRUDE_COMM_UpdatePendingNotices(s);
    if (s[0x93e] == 1 && INTRUDE_COMM_SendTally((char *)s) == 1) {
        s[0x93e] = 0;
    }
    INTRUDE_COMM_UpdateSession(s, s + 0x1ac);
    if (s[0x907] == 1 && INTRUDE_CMD_SendProfile((int *)s) == 1) {
        s[0x907] = 0;
    }
    INTRUDE_COMM_UpdateUnionInfoAndReturnSlots(s);
    INTRUDE_COMM_UpdatePageRequests(s);
    INTRUDE_COMM_UpdateQueuedRequest(s);
    if (INTRUDE_COMM_UpdateSelfRecord(s) == 1) {
        s[0x900] = 1;
    }
    if (s[0x900] == 1 && ((Bits *)(s + 0x904))->b1 == 0 && INTRUDE_COMM_SendPeerStatus((char *)s, (int)(s + 0x70)) == 1) {
        s[0x900] = 0;
    }
    if (GAME_DATA_IsSaving((const u8 *)h) == 0 && ((Bits *)(s + 0x8f8))->b0 == 1) {
        w = func_0200BE48(GAME_DATA_GetSaveControl((struct Big *)h));
        if (INTRUDE_COMM_IsValidProfileCode(((struct Obj00269 *)s)->f8F4) == 0) {
            ((struct Obj00269 *)s)->f8F4 = 0x11;
        }
        func_0200BE84(w, s + 0x8e4);
        ((Bits *)(s + 0x8f8))->b0 = 0;
    }
}
