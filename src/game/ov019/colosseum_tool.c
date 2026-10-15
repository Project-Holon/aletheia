/*
 * file:     colosseum_tool.c
 * unit:     yes
 * function: COLOSSEUM_CheckAllEntered, COLOSSEUM_CheckAllTrainerCardsReceived, COLOSSEUM_IsPositionsReceived, COLOSSEUM_ClearPositionsReceived, COLOSSEUM_GetStandPosIndex, COLOSSEUM_CheckAllFinished, COLOSSEUM_IsAnyFinished, COLOSSEUM_IsOnCounterPos, COLOSSEUM_UpdateCommPlayers
 * address:  0x0217FDC8
 * region:   ov019
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   GFL_NET_GetNegotiationNum  0x0203D1B4  arm
 *   GFL_NET_HANDLE_GetCurrentHandle  0x020399A8  arm
 *   func_02080D24  0x02080D24  arm
 *   GFL_NET_GetHandleNetID  0x0203D1A4  arm
 *   func_02008550  0x02008550  thumb
 *   FIELDMAP_GetFieldPlayer  0x02188CB4  thumb  ov021
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb  ov021
 *   func_0200873C  0x0200873C  thumb
 *   FIELD_PLAYER_GetPos  0x021A3038  thumb  ov021
 *   ARC_TOOL_CreateHandle   0x020490F4  arm
 *   SAVEDATA_PanicFail   0x02034714  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   d_02180794     0x02180794  data  ov019  a4
 *   d_0218079C     0x0218079C  data  ov019  a4
 *   FIELDMAP_GetZoneId  0x02188C9C  thumb  ov021
 *   d_021807AC     0x021807AC  data  ov019  a4
 *   d_021807C0     0x021807C0  data  ov019  a4
 *   UNION_ONESELF_ColosseumPartyExchangeMain  0x0217E440  thumb  ov019
 *   COLOSSEUM_TakePackage   0x021751DC  thumb  ov012
 *   COMM_PLAYER_CheckOccupy   0x021677E4  thumb
 *   COMM_PLAYER_Add   0x021675D0  thumb
 *   COMM_PLAYER_SetPackage   0x02167848  thumb  ov010
 */

struct VecFx32;
typedef unsigned char u8;

typedef unsigned int   u32;

typedef unsigned short u16;

typedef short          s16;
typedef int            s32;

typedef struct { int x,y,z; } VecFx32;
#include "../ov012/union_comm_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

extern int  GFL_NET_GetNegotiationNum(void);
extern void *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned int func_02080D24(int a);
extern u32 GFL_NET_GetHandleNetID(void *p);
extern u8 func_02008550(const void *obj);
extern void *FIELDMAP_GetFieldPlayer(void *p);
extern void *FIELD_PLAYER_GetMmdl(void *p);
extern void FIELD_PLAYER_GetPos(void *a, void *v);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void SAVEDATA_PanicFail(const char *expr, u32 line, const char *file);
extern void MTX_Identity33_(void *m);
extern int FLDMMDL_GetGridNowX(void *);
extern int FLDMMDL_GetGridNowZ(void *);
extern u16 FIELDMAP_GetZoneId(void *p);
int COLOSSEUM_CheckAllEntered(ColosseumWork *colosseum);
int COLOSSEUM_CheckAllTrainerCardsReceived(ColosseumWork *colosseum);
int COLOSSEUM_IsPositionsReceived(ColosseumWork *colosseum);
void COLOSSEUM_ClearPositionsReceived(ColosseumWork *colosseum);
int COLOSSEUM_GetStandPosIndex(int a, int mode, unsigned *out);
int COLOSSEUM_CheckAllFinished(ColosseumWork *colosseum);
int COLOSSEUM_IsAnyFinished(ColosseumWork *colosseum);
int COLOSSEUM_IsOnCounterPos(void *a);
extern s16 d_02180794[][2];
extern s16 d_0218079C[][2];
extern s16 d_021807AC[][2];
extern s16 d_021807C0[][2];

#define COLOSSEUM_PLAYER_MAX 4

struct CommPlayer;
struct MyStatus;
extern int COLOSSEUM_TakePackage(ColosseumWork *work, int netId, CommPlayerPackage *out);
extern int COMM_PLAYER_CheckOccupy(struct CommPlayer *commPlayer, int netId);
extern void COMM_PLAYER_Add(struct CommPlayer *commPlayer, int netId, int mode, CommPlayerPackage *package);
extern void COMM_PLAYER_SetPackage(struct CommPlayer *commPlayer, int netId, CommPlayerPackage *package);




int COLOSSEUM_CheckAllEntered(ColosseumWork *colosseum)
{
    int n=0; int i;
    for (i=0;i<4;i++) { if (colosseum->player[i].isEntered == 1) n++; }
    if (n >= GFL_NET_GetNegotiationNum()) return 1;
    return 0;
}








int COLOSSEUM_CheckAllTrainerCardsReceived(ColosseumWork *colosseum)
{
    int i;
    int n = 0;

    for (i = 0; i < 4; i++) {
        if (colosseum->trainerCardReceived[i] == 1)
            n++;
    }
    if (n >= GFL_NET_GetNegotiationNum())
        return 1;
    return 0;
}








/*
 * note:     unlabelled leaf (prints as .word in ov019.s); called from
 *           UNION_ONESELF_ColosseumPartyExchangeMain.
 */
int COLOSSEUM_IsPositionsReceived(ColosseumWork *colosseum)
{
    if (colosseum->positionsReceived == 1)
        return 1;
    return 0;
}








void COLOSSEUM_ClearPositionsReceived(ColosseumWork *colosseum)
{
    colosseum->positionsReceived = 0;
}








int COLOSSEUM_GetStandPosIndex(int a, int mode, unsigned *out)
{
    unsigned i;
    int x;
    void *y;
    int y2;
    void *h;

    h = FIELDMAP_GetFieldPlayer((void *)a);
    *out = 0;
    y = FIELD_PLAYER_GetMmdl((void *)h);
    x = FLDMMDL_GetGridNowX(y);
    y2 = FLDMMDL_GetGridNowZ(y);
    if (mode == 2) {
        for (i = 0; i < 2; i++) {
            if (d_02180794[i][0] == x && d_02180794[i][1] == y2) {
                *out = i;
                return 1;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (d_0218079C[i][0] == x && d_0218079C[i][1] == y2) {
                *out = i;
                return 1;
            }
        }
    }
    return 0;
}







int COLOSSEUM_CheckAllFinished(ColosseumWork *colosseum)
{
    int n = 0;
    int i;
    int value = colosseum->entryBits;

    for (i = 0; i < 4; i++) {
        if (colosseum->finished[i] == 1)
            n++;
    }
    if (n >= GFL_NET_GetNegotiationNum() || n >= (int)func_02080D24(value))
        return 1;
    return 0;
}


int COLOSSEUM_IsAnyFinished(ColosseumWork *colosseum)
{
    int i;
    for (i = 0; i < 4; i++) {
        if (colosseum->finished[i] == 1) return 1;
    }
    return 0;
}








int COLOSSEUM_IsOnCounterPos(void *a)
{
    int v[3];
    s16 (*t)[2];
    int i;
    int n;

    FIELD_PLAYER_GetPos(FIELDMAP_GetFieldPlayer(a), (struct VecFx32 *)v);
    v[0] >>= 12;
    v[2] >>= 12;
    if (FIELDMAP_GetZoneId(a) == 0x96) {
        t = d_021807AC;
        n = 5;
    } else {
        t = d_021807C0;
        n = 5;
    }
    for (i = 0; i < n; i++) {
        if (v[0] == t[i][0] && v[2] == t[i][1])
            return 1;
    }
    return 0;
}





/* Copies the packages that arrived for the other (up to four) colosseum
 * players into the comm player: adds a player not yet present, otherwise
 * updates its package. */
void COLOSSEUM_UpdateCommPlayers(ColosseumWork *work)
{
    int ownNetId;
    int netId;
    CommPlayerPackage package;

    ownNetId = GFL_NET_GetHandleNetID(GFL_NET_HANDLE_GetCurrentHandle());

    for (netId = 0; netId < COLOSSEUM_PLAYER_MAX; netId++) {
        if (ownNetId != netId && COLOSSEUM_TakePackage(work, netId, &package) == 1) {
            if (COMM_PLAYER_CheckOccupy(work->commPlayer, netId) == 0) {
                int outfitVariant = func_02008550((const struct MyStatus *)&work->player[netId]);
                int addMode = 1;

                if (outfitVariant)
                    addMode = 4;
                COMM_PLAYER_Add(work->commPlayer, netId, addMode, &package);
            } else {
                COMM_PLAYER_SetPackage(work->commPlayer, netId, &package);
            }
        }
    }
}
