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
 *   sub_02034714   0x02034714  arm
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

struct Entry;
struct Ctx_0217BD9C;
struct Self;
struct Obj_0217E188;
struct Sub02008700Obj;
struct Rec;
struct Pair;
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

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
} Sys_0217BD9C;

typedef struct {
    Sys_0217BD9C *sys;
} Ctx_0217BD9C;

typedef struct {
    u8 f00;
    u8 pad01[0x6e - 1];
    s16 f6e;
} Obj_0217E188;

typedef struct {
    u8 b0 : 1;
    u8 b1 : 1;
} Bits_0217DC94;

typedef struct Rec {
    u8  pad0[7];
    u8  lo7 : 3;
    u8  flag7 : 1;
    u8  hi7 : 4;
    u8  pad8;
    u8  f9;
    u8  padA[2];
    u16 name[13];
    u8  f26;
    u8  f27;
} Rec;

typedef struct Sys {
    u32 f0;
    u32 pad4;
    u32 f8;
} Sys;

typedef struct Sub_0217DC94 {
    u8   pad0[0x14];
    Rec *rec;
} Sub_0217DC94;

typedef struct Pair {
    u32 f0;
    u32 f4;
} Pair;

typedef struct Tiles {
    u32 f0;
    u32 a[6];
    u32 b[6];
} Tiles;

typedef struct Self {
    Sys   *sys;
    u8     pad4[0x2800];
    void  *win2804;
    void  *msg2808;
    u8     pad280C[0xc];
    void  *f2818;
    u8     pad281C[0x2830 - 0x281C];
    Sub_0217DC94    sub;
    u8     pad2848[0x352C - 0x2848];
    void  *f352C;
    Tiles *f3530;
} Self;

struct Bits_0217DC94 { u8 pad[7]; unsigned char low:3; unsigned char kind:1; unsigned char high:4; };


/* One effect model over a field model (0x14 bytes, union_eff.c). */

/* Animated reaction effect (0x20 bytes). */

/* Still icons over players (0xD4 bytes). */

/* union_eff work (0xF4 bytes, heap tag 0x8E). */

/* Draw parameters of G3D_SYSTEM_DrawObjectCulling (0x3C bytes). */

extern int  GFL_NET_GetNegotiationNum(void);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern unsigned int func_02080D24(int a);
extern u32 GFL_NET_GetHandleNetID(void *p);
extern u8 func_02008550(const void *obj);
extern void *FIELDMAP_GetFieldPlayer(void *p);
extern void *FIELD_PLAYER_GetMmdl(void *p);
struct Sub02008700Obj *func_0200873C(void *sys);
extern void FIELD_PLAYER_GetPos(void *a, void *v);
extern void *ARC_TOOL_CreateHandle(u32 id, u32 heap);
extern void sub_02034714(const char *expr, u32 line, const char *file);
extern void MTX_Identity33_(void *m);
extern int FLDMMDL_GetGridNowX(void *);
extern int FLDMMDL_GetGridNowZ(void *);
extern u16 FIELDMAP_GetZoneId(void *p);
int UNION_ONESELF_ColosseumPartyExchangeMain(u8 *w, void *obj, int a2, u8 *state);
int COLOSSEUM_CheckAllEntered(ColosseumWork *colosseum);
int COLOSSEUM_CheckAllTrainerCardsReceived(ColosseumWork *colosseum);
int COLOSSEUM_IsPositionsReceived(ColosseumWork *colosseum);
void COLOSSEUM_ClearPositionsReceived(ColosseumWork *colosseum);
int COLOSSEUM_GetStandPosIndex(int a, int mode, unsigned *out);
int COLOSSEUM_CheckAllFinished(u8 *p);
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







int COLOSSEUM_CheckAllFinished(u8 *p)
{
    int n=0; int i; int value=p[0x16e];
    for (i=0;i<4;i++) { if(p[0x162+i] == 1) n++; }
    if (n >= GFL_NET_GetNegotiationNum() || n >= (int)func_02080D24(value)) return 1;
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
