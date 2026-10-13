/*
 * function: WIFICLUB_TryStartPartnerRequest
 * address: 0x021C08F8
 * packet: pkt_ov099_021C08F8
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: enum offset K274 with p+(off-delta) preserves register-offset
 *   stores; unparenthesized p+off-delta gave DIFF20/200.
 * prototype-evidence: C23B8 forwards the index to ov009 56860 and returns
 *   its address in r0; C23C8's final 0203C2B0 body returns the consumed bool.
 *   BDD48 retains the visibly loaded unused first input.
 * symbols:
 *   WIFICLUBACTOR_GetPickResult 0x021B97F4 thumb ov099
 *   POKEPARTY_GetAliveNonEggCount 0x0201AC80 thumb
 *   WIFICLUB_GetFriendStatus 0x021C23B8 thumb ov099
 *   WIFICLUB_GetStatusKind 0x021BDD48 thumb ov099
 *   WIFICLUB_GetStatusSeatFlag 0x021C27E0 thumb ov099
 *   WIFICLUB_AddNetCommandsAndCheckFriend 0x021C23C8 thumb ov099
 *   WIFICLUB_CountChangeAndCopyPeerAddr 0x021C2810 thumb ov099
 *   WIFICLUB_ChangeNetMode 0x021BDE30 thumb ov099
 *   WIFICLUB_SetOwnStatusAndPublish 0x021C18C8 thumb ov099
 *   WIFICLUB_SetPartnerNameWord 0x021BA874 thumb ov099
 *   WIFICLUB_ShowMessage 0x021BAADC thumb ov099
 *   WIFICLUB_ResetTimeIcon 0x021BC090 thumb ov099
 *   WIFICLUB_ShowStreamedMessage 0x021BAAB8 thumb ov099
 */
#include "../include/Obj06358.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { K274=0x274 } Off;
struct W;
struct S;
struct Work;
extern u8 WIFICLUBACTOR_GetPickResult(struct W *);
extern u32 POKEPARTY_GetAliveNonEggCount(void *);
extern int WIFICLUB_GetFriendStatus(int i);
extern u8 WIFICLUB_GetStatusKind(int, struct S *);
extern int WIFICLUB_GetStatusSeatFlag(struct S *);
extern int WIFICLUB_AddNetCommandsAndCheckFriend(void *, void *);
extern void WIFICLUB_CountChangeAndCopyPeerAddr(struct S *, char *);
extern void WIFICLUB_ChangeNetMode(void *, int, int);
extern void WIFICLUB_SetOwnStatusAndPublish(char *, int, int);
extern void WIFICLUB_SetPartnerNameWord(struct Work *, int);
extern void WIFICLUB_ShowMessage(char *p, int a, int b);
extern void WIFICLUB_ResetTimeIcon(void *);
extern void WIFICLUB_ShowStreamedMessage(char *, int, int);
int WIFICLUB_TryStartPartnerRequest(char *p)
{
    int n;
    int index;
    struct S *state;
    u32 kind;
    Off off = K274;
    n = WIFICLUBACTOR_GetPickResult((struct W *)(p + off));
    *(u16 *)(p + (off - 0x32)) = n;
    if (n != 0) {
        POKEPARTY_GetAliveNonEggCount(((struct Obj06358 *)p)->fC8);
        index = n - 1;
        state = (struct S *)WIFICLUB_GetFriendStatus(index);
        kind = WIFICLUB_GetStatusKind((int)p, state);
        WIFICLUB_GetStatusSeatFlag(state);
        if (kind == 6) return 0;
        if (WIFICLUB_AddNetCommandsAndCheckFriend(p, (void *)-1)) {
            WIFICLUB_CountChangeAndCopyPeerAddr(*(struct S * *)&((struct Obj06358 *)p)->f8, (char *)WIFICLUB_GetFriendStatus(index));
            *(int *)(p + (off - 0xb0)) = 0xe10;
            WIFICLUB_ChangeNetMode(p, 3, 3);
            WIFICLUB_SetOwnStatusAndPublish(p, 3, 3);
            WIFICLUB_SetPartnerNameWord((struct Work *)p, n - 1);
            ((struct Obj06358 *)p)->f1351 = n;
            WIFICLUB_ShowMessage(p, 14, 0);
            WIFICLUB_ResetTimeIcon(p);
            *(int *)(p + (off - 0xa8)) = 0x88;
        } else {
            WIFICLUB_SetPartnerNameWord((struct Work *)p, n - 1);
            WIFICLUB_ShowStreamedMessage(p, 13, 0);
            *(int *)(p + (off - 0xa8)) = 0x15;
        }
    }
    return 1;
}
