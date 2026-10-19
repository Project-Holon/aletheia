/*
 * function: EVENT_COMM_COMMON_InitCommonWork
 * address: 0x0217FDA0
 * packet: pkt_ov018_0217FDA0
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: enum local keeps the distinct full-word spill of f; its narrowed
 * byte value remains live in r1 and is forwarded to EVENT_COMM_COMMON_GetPeerTalkStatus.
 * symbols:
 *   COMM_PLAYER_GetMmdl 0x02167A14 thumb ov010
 *   EVENT_COMM_COMMON_GetPeerTalkStatus 0x0217F5F0 thumb ov018
 *   GAMESYSTEM_GetGameData 0x020120F4 thumb
 *   GAME_DATA_GetMyStatusByNetId 0x021583EC thumb ov010
 *   MYSTATUS_Copy 0x02008494 thumb
 *   INTRUDE_COMM_IsSessionActive 0x02175B14 thumb ov011
 *   INTRUDE_COMM_GetActiveSessionRequest 0x02175B34 thumb ov011
 *   MI_CpuCopy8 0x02082D44 arm
 *   EVENT_COMM_COMMON_InitMsgBox 0x0217F2B4 thumb ov018
 *   INTRUDE_COMM_SetState 0x02174E14 thumb ov011
 *   INTRUDE_COMM_ClearNotice 0x02175368 thumb ov011
 */
#include "../include/Obj00566.h"
#include "../include/Obj03562.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Ctx;
struct Work;
u32 COMM_PLAYER_GetMmdl(struct Work *w, int i);
int EVENT_COMM_COMMON_GetPeerTalkStatus(u8 *a, int b);
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
int GAME_DATA_GetMyStatusByNetId(void *a0, int a1);
void MYSTATUS_Copy(void *src, void *dst);
int INTRUDE_COMM_IsSessionActive(u8 *a);
u8 *INTRUDE_COMM_GetActiveSessionRequest(u8 *p);
void MI_CpuCopy8(void *src, void *dst, int n);
void EVENT_COMM_COMMON_InitMsgBox(void *a, int b);
void INTRUDE_COMM_SetState(u8 *a, int b);
void INTRUDE_COMM_ClearNotice(char *p);

void EVENT_COMM_COMMON_InitCommonWork(int a, u8 *b, u8 *c, int d, int e, int f, u16 g)
{
    enum Local { LOCAL_ZERO } loc;

    ((struct Obj03562 *)c)->f0 = g;
    ((struct Obj03562 *)c)->f4 = e;
    loc = f;
    ((struct Obj03562 *)c)->f8 = COMM_PLAYER_GetMmdl((struct Work *)(((struct Obj00566 *)b)->f8), loc);
    ((struct Obj03562 *)c)->fC = d;
    c[0x40] = (u8)f;
    c[0x42] = EVENT_COMM_COMMON_GetPeerTalkStatus(b, (u8)f);
    MYSTATUS_Copy((void *)GAME_DATA_GetMyStatusByNetId(GAMESYSTEM_GetGameData((const struct Ctx *)a), loc), c + 0x78);
    if (INTRUDE_COMM_IsSessionActive(b + 0x1ac) == 1) {
        MI_CpuCopy8(INTRUDE_COMM_GetActiveSessionRequest(b + 0x1ac), c + 0x44, 0x34);
    }
    EVENT_COMM_COMMON_InitMsgBox(c + 0x10, a);
    INTRUDE_COMM_SetState(b, 1);
    INTRUDE_COMM_ClearNotice((char *)b);
    b[0x93f] = b[0x93f] & ~0x30;
}
