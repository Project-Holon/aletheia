/*
 * file:     union_oneself.c
 * unit:     yes
 * function: func_0217BD9C, func_0217BE44, func_0217BE64, func_0217C03C, func_0217C04C, func_0217C074, func_0217C1F0, func_0217C200, func_0217C2AC, func_0217C444, func_0217C450, func_0217C518, func_0217C5A8, func_0217C888, func_0217C88C, func_0217CAAC, func_0217CEB8, func_0217CFA8, func_0217D18C, func_0217D314, func_0217D51C, func_0217D5B8, func_0217D7A4, func_0217D890, func_0217D9A8, func_0217DC64, func_0217DC94, func_0217DCA8, func_0217DE88, func_0217DEA0, func_0217DFB4, func_0217E0A4, func_0217E188, func_0217E378, func_0217E440, func_0217E5A0, func_0217E838, func_0217E904, func_0217EAD8
 * address:  0x0217BD9C
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
 *   func_020061E4  0x020061E4  thumb
 *   func_02030734  0x02030734  arm
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0217422C  0x0217422C  thumb  ov012
 *   func_02174268  0x02174268  thumb  ov012
 *   func_021736A0  0x021736A0  thumb  ov012
 *   func_020307B0  0x020307B0  arm
 *   d_021807E8     0x021807E8  data  a4
 *   func_0217BB04  0x0217BB04  thumb  ov019
 *   func_0217B8E4  0x0217B8E4  thumb  ov019
 *   func_02172D20  0x02172D20  thumb  ov012
 *   func_02172D68  0x02172D68  thumb  ov012
 *   func_021734A8  0x021734A8  thumb  ov012
 *   func_02173AFC  0x02173AFC  thumb  ov012
 *   func_0203D14C  0x0203D14C  arm
 *   func_0203D1B4  0x0203D1B4  arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_0203D1E8  0x0203D1E8  arm
 *   func_0203D7BC  0x0203D7BC  arm
 *   func_020392B8  0x020392B8  arm
 *   func_020399A8  0x020399A8  arm
 *   func_020362DC  0x020362DC  arm
 *   memcmp         0x0203EFC8  arm
 *   func_0217BAF0 0x0217BAF0 thumb ov019
 *   d_021807E4     0x021807E4  data a1
 *   func_02034714  0x02034714  arm
 *   func_02173A90  0x02173A90  thumb ov012
 *   func_02173518  0x02173518  thumb  ov012
 *   func_021735FC  0x021735FC  thumb  ov012
 *   func_02039C68  0x02039C68  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_02173B4C  0x02173B4C  thumb  ov012
 *   func_02080D24  0x02080D24  arm
 *   func_02012934  0x02012934  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_0201AAD4  0x0201AAD4  thumb
 *   func_0201AA88  0x0201AA88  thumb
 *   func_02173A04  0x02173A04  thumb ov012
 *   func_0217B9BC  0x0217B9BC  thumb ov019
 *   func_0217BA10  0x0217BA10  thumb ov019
 *   func_0217B974  0x0217B974  thumb ov019
 *   func_0217BAA8  0x0217BAA8  thumb ov019
 *   func_02173A48  0x02173A48  thumb ov012
 *   func_0217AEFC 0x0217AEFC thumb ov019
 *   func_0217AF04  0x0217AF04  thumb ov019
 *   func_0216F40C  0x0216F40C  thumb  ov010
 *   func_02082D44  0x02082D44  arm
 *   func_02173BB0  0x02173BB0  thumb  ov012
 *   func_0216F7F4  0x0216F7F4  thumb  ov010
 *   func_0203D378  0x0203D378  arm
 *   func_0200ED48  0x0200ED48  thumb
 *   func_0203D1A4  0x0203D1A4  arm
 *   func_02012950  0x02012950  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_0201A920  0x0201A920  thumb
 *   func_021736E0  0x021736E0  thumb  ov012
 *   func_02172EDC  0x02172EDC  thumb  ov012
 *   func_0203CDBC  0x0203CDBC  arm
 *   func_02173650  0x02173650  thumb  ov012
 *   func_02172D50  0x02172D50  thumb  ov012
 *   func_02012F2C  0x02012F2C  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_02173D38  0x02173D38  thumb  ov012
 *   func_02174F4C  0x02174F4C  thumb  ov012
 *   func_02012944  0x02012944  thumb
 *   func_0217BB20  0x0217BB20  thumb  ov019
 *   func_02173CB4  0x02173CB4  thumb  ov012
 *   func_021CD48C  0x021CD48C  thumb  ov021
 *   func_021CD5A4  0x021CD5A4  thumb  ov021
 *   func_021CD60C  0x021CD60C  thumb  ov021
 *   func_021CD688  0x021CD688  thumb  ov021
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_0217357C  0x0217357C  thumb  ov012
 *   func_02173614  0x02173614  thumb  ov012
 *   func_02174B40  0x02174B40  thumb  ov012
 *   func_02174BB8  0x02174BB8  thumb  ov012
 *   func_02174C34  0x02174C34  thumb  ov012
 *   func_02175094  0x02175094  thumb  ov012
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021750B0  0x021750B0  thumb  ov012
 *   func_021A3460  0x021A3460  thumb  ov021
 *   func_021679A4  0x021679A4  thumb  ov010
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_02174CE4  0x02174CE4  thumb  ov012
 *   func_021750D0  0x021750D0  thumb  ov012
 *   func_0216D3CC  0x0216D3CC  thumb  ov010
 *   func_0216D410  0x0216D410  thumb  ov010
 *   func_0216D454  0x0216D454  thumb  ov010
 *   func_0216D480  0x0216D480  thumb  ov010
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBA8  0x0200BBA8  thumb
 *   func_0217BA48  0x0217BA48  thumb  ov019
 *   func_0217BA6C  0x0217BA6C  thumb  ov019
 *   func_0217B9CC  0x0217B9CC  thumb  ov019
 *   func_021CC720  0x021CC720  thumb  ov021
 *   func_021CC810  0x021CC810  thumb  ov021
 *   func_021CC7B4  0x021CC7B4  thumb  ov021
 *   func_0217B9F4  0x0217B9F4  thumb  ov019
 *   func_02174E20  0x02174E20  thumb  ov012
 *   func_02174E64  0x02174E64  thumb  ov012
 *   func_02175240  0x02175240  thumb  ov012
 *   func_02175208  0x02175208  thumb  ov012
 *   func_02175214  0x02175214  thumb  ov012
 *   func_02174D98  0x02174D98  thumb  ov012
 *   func_02174DF0  0x02174DF0  thumb  ov012
 *   func_0201AC2C  0x0201AC2C  thumb
 *   func_0201A2A8  0x0201A2A8  thumb
 *   func_0201292C  0x0201292C  thumb
 *   func_0200873C  0x0200873C  thumb
 *   func_020084F4  0x020084F4  thumb
 *   func_0217AE20  0x0217AE20  thumb  ov019
 *   func_02174F34  0x02174F34  thumb  ov012
 *   func_02172D38  0x02172D38  thumb  ov012
 *   func_02173408  0x02173408  thumb  ov012
 *   func_02173524  0x02173524  thumb  ov012
 *   func_0217505C  0x0217505C  thumb  ov012
 *   func_02012124  0x02012124  thumb
 *   func_02039338  0x02039338  arm
 *   func_0200855C  0x0200855C  thumb
 *   func_0201F02C  0x0201F02C  thumb
 *   sub_020490F4   0x020490F4  arm
 *   sub_02034714   0x02034714  arm
 *   MTX_Identity33_  0x0207ADC4  arm
 *   func_0217EC04  0x0217EC04  thumb  ov019
 *   func_0217EC1C  0x0217EC1C  thumb  ov019
 *   func_0217EC28  0x0217EC28  thumb  ov019
 *   func_0217EC34  0x0217EC34  thumb  ov019
 *   func_0217EC40  0x0217EC40  thumb  ov019
 *   func_0217EC54  0x0217EC54  thumb  ov019
 *   func_0217EC68  0x0217EC68  thumb  ov019
 *   func_0217EC78  0x0217EC78  thumb  ov019
 *   func_0217EC88  0x0217EC88  thumb  ov019
 *   func_0217EC94  0x0217EC94  thumb  ov019
 *   func_0217ECA0  0x0217ECA0  thumb  ov019
 *   func_0217ECAC  0x0217ECAC  thumb  ov019
 *   func_0217ECB8  0x0217ECB8  thumb  ov019
 *   func_0217ECD0  0x0217ECD0  thumb  ov019
 *   func_0217ECE8  0x0217ECE8  thumb  ov019
 *   func_0217ED04  0x0217ED04  thumb  ov019
 *   func_0217ED10  0x0217ED10  thumb  ov019
 *   func_0217ED2C  0x0217ED2C  thumb  ov019
 *   func_0217ED48  0x0217ED48  thumb  ov019
 *   func_0217ED64  0x0217ED64  thumb  ov019
 *   func_0217ED80  0x0217ED80  thumb  ov019
 *   func_0217ED8C  0x0217ED8C  thumb  ov019
 *   func_0217ED98  0x0217ED98  thumb  ov019
 *   func_0217EDA4  0x0217EDA4  thumb  ov019
 *   func_0217EDB0  0x0217EDB0  thumb  ov019
 *   func_0217EDBC  0x0217EDBC  thumb  ov019
 *   func_0217EDC8  0x0217EDC8  thumb  ov019
 *   func_0217EDD4  0x0217EDD4  thumb  ov019
 *   func_0217EDE0  0x0217EDE0  thumb  ov019
 *   func_0217EDEC  0x0217EDEC  thumb  ov019
 *   func_0217EDF8  0x0217EDF8  thumb  ov019
 *   func_0217EE04  0x0217EE04  thumb  ov019
 *   func_0217EE10  0x0217EE10  thumb  ov019
 *   func_0217EE1C  0x0217EE1C  thumb  ov019
 *   func_0217EE28  0x0217EE28  thumb  ov019
 *   func_0217EE34  0x0217EE34  thumb  ov019
 *   func_0217EE40  0x0217EE40  thumb  ov019
 *   func_0217EE4C  0x0217EE4C  thumb  ov019
 *   func_0217F060  0x0217F060  thumb  ov019
 *   func_0217F074  0x0217F074  thumb  ov019
 *   func_0217F098  0x0217F098  thumb  ov019
 *   func_0217F188  0x0217F188  thumb  ov019
 *   func_0217F1EC  0x0217F1EC  thumb  ov019
 *   func_0217F210  0x0217F210  thumb  ov019
 *   func_0217F22C  0x0217F22C  thumb  ov019
 *   func_0217F24C  0x0217F24C  thumb  ov019
 *   func_0217F268  0x0217F268  thumb  ov019
 *   func_0217F360  0x0217F360  thumb  ov019
 *   func_0217F378  0x0217F378  thumb  ov019
 *   func_0217F380  0x0217F380  thumb  ov019
 *   func_0217F388  0x0217F388  thumb  ov019
 *   func_0217F4AC  0x0217F4AC  thumb  ov019
 *   func_0217F4B4  0x0217F4B4  thumb  ov019
 *   func_0217F5E0  0x0217F5E0  thumb  ov019
 *   func_0217F624  0x0217F624  thumb  ov019
 *   func_0217F640  0x0217F640  thumb  ov019
 *   func_0217F794  0x0217F794  thumb  ov019
 *   func_0217F7B8  0x0217F7B8  thumb  ov019
 *   func_0217FDC8  0x0217FDC8  thumb  ov019
 *   func_0217FDF8  0x0217FDF8  thumb  ov019
 *   func_0217FE24  0x0217FE24  thumb  ov019
 *   func_0217FE38  0x0217FE38  thumb  ov019
 *   func_0217FE44  0x0217FE44  thumb  ov019
 *   func_0217FEB8  0x0217FEB8  thumb  ov019
 *   func_0217FEF4  0x0217FEF4  thumb  ov019
 *   func_0217FF14  0x0217FF14  thumb  ov019
 */
typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;
typedef int            s32;

typedef struct { s32 x, y, z; } VecFx32;
#include "../ov012/union_comm_types.h"
#include "unit_0217AE20_types.h"

#ifndef NULL
#define NULL ((void *)0)
#endif

struct WordSet;

/* Setup of the trade scene (0x14 bytes, scene 2). */
typedef struct UnionTradeSetup {
    int gameData;     /* 0x00 */
    int party;        /* 0x04 received party */
    u16 tradeMode;    /* 0x08 */
    u8  isEvent;      /* 0x0A */
    u8  isDemo;       /* 0x0B */
    int isComm;       /* 0x0C */
    int result;       /* 0x10 */
} UnionTradeSetup;

/* Parameter of the trade scene (0x30 bytes). */
typedef struct UnionTradeParam {
    u8  pad00[8];
    int result;               /* 0x08 */
    u8  pad0c[0x14 - 0x0c];
    int gameData;             /* 0x14 */
    int pad18;
    int party;                /* 0x1C */
    UnionTradeSetup *setup;   /* 0x20 */
} UnionTradeParam;

/* One opponent of the colosseum battle (0x0C bytes). */
typedef struct UnionBattleOpponent {
    void *party;      /* 0x68 */
    const void *myStatus;     /* 0x6C */
    u8  trainerView;  /* 0x70 */
} UnionBattleOpponent;

/* Battle setup of the colosseum battle scene (0xC4 bytes, scene 0x1A). */
typedef struct UnionBattleParam {
    void *party;                        /* 0x00 */
    void *myStatus;                     /* 0x04 */
    int pad08;
    void *config;                       /* 0x0C */
    int pad10;
    void *regulation;                   /* 0x14 */
    u8  pad18[0x34 - 0x18];
    int commMode;                       /* 0x34 */
    u8  pad38[0x60 - 0x38];
    u16 result;                         /* 0x60 */
    u8  pad62[0x64 - 0x62];
    int rule;                           /* 0x64 1 single, 2 multi */
    UnionBattleOpponent opponent[3];    /* 0x68 */
    int isComm;                         /* 0x8C */
    int recordMode;                     /* 0x90 */
    u8  pad94[0xc0 - 0x94];
    int *recordBuffer;                  /* 0xC0 */
} UnionBattleParam;

/* Parameter of the easy chat input scene (scene 0x1D, 12 bytes). */
typedef struct UnionChatInputParam {
    void *saveData;        /* 0x00 */
    int cancelled;         /* 0x04 nonzero: the player backed out */
    UnionPmsData *pms;     /* 0x08 sentence to edit */
} UnionChatInputParam;

/* Parameter of the scene 3 (8 bytes). */
typedef struct UnionSceneThreeParam {
    int pad00;
    struct GameData *gameData;   /* 0x04 */
} UnionSceneThreeParam;

/* Parameter of the scene 4 (0x18 bytes). */
typedef struct UnionSceneFourParam {
    int pad00;
    struct GameData *gameData;   /* 0x04 */
    void *party;                 /* 0x08 */
    void *saveData;              /* 0x0C */
    void *bag;                   /* 0x10 */
    int pad14;
} UnionSceneFourParam;

/* Draw parameters of G3D_SYSTEM_DrawObjectCulling (0x3C bytes). */

extern void func_020061E4(u32 seId);
extern void *func_02030734(unsigned int heapId, unsigned int size, int clear, const void *site, unsigned short tag);
extern void *func_02012EBC(void *gameData);
extern void func_0217422C(UnionRoomWork *unisys, int sceneId, int param);
extern int func_02174268(UnionRoomWork *unisys);
extern void func_021736A0(UnionRoomWork *unisys, UnionPmsData *pms);
extern u32 func_020307B0(void *block);
extern int func_0217BB04(UnionRoomWork *unisys);
extern int func_0217B8E4(UnionRoomWork *unisys, int nextState);
extern void func_02172D20(void *unisys);
extern int func_02172D68(void *unisys);
extern void func_021734A8(void *unisys, u32 commandId, u32 value);
extern int  func_02173AFC(int expected);
extern void func_0203D14C(int mode, int flag, void *mac);
extern int  func_0203D1B4(void);
extern u32 func_0203D1C0(u32 index);
extern void func_0203D1E8(u32 unused, void *value);
extern void func_0203D7BC(u8 enable);
extern int  func_020392B8(void);
extern void *func_020399A8(void);
extern u32 func_020362DC(void);
extern int  memcmp(const void *a, const void *b, u32 n);
extern void func_0217BAF0(UnionRoomWork *unisys, void *fieldMap, unsigned int busy);
void func_02034714(const void *expr, u32 line, const void *file);
int func_02173A90(void);
extern void func_02173518(void *connect);
extern int func_021735FC(void *connect, const void *connectPc);
extern void func_02039C68(void *link, u32 phase, u32 count);
extern u32 func_02039CB4(void *link, u32 phase, u32 count);
extern int func_02173B4C(void *unisys);
extern unsigned int func_02080D24(int bits);
void *func_02012934(const void *gameData);
void *func_020120F4(const void *gameSystem);
u32 func_0201AA1C(void *party);
u32 func_0201AAD4(void *party);
u32 func_0201AA88(void *party);
int func_02173A04(int choice, ...);
int func_0217B9BC(unsigned int category);
void func_0217BA10(UnionRoomWork *unisys, int category);
int func_0217B974(int category);
int func_0217BAA8(UnionRoomWork *unisys, int category, void *partyFailMask, void *teamFailMask);
int func_02173A48(int answer, ...);
u16 func_0217AEFC(u32);
int func_0217AF04(void *unisys, u16 requestId);
extern void func_0216F40C(void *out, void *save, int mode, int flag, volatile u16 heap);
extern void func_02082D44(const void *src, void *dst, int size);
extern u32 func_02173BB0(void *unisys);
extern void *func_0216F7F4(struct GameData *gameData, void *trainerCard, int heapId);
extern u32 func_0203D378(void);
extern void *func_0200ED48(void *saveData);
extern u32 func_0203D1A4(void *link);
extern void *func_02012950(void *gameData, u32 playerIndex);
extern u32 func_02008530(const void *obj);
extern void func_0200ED54(void *commState, u32 value);
extern void *func_0201A920(u32 heap);
extern void func_021736E0(unsigned int category);
extern void func_02172EDC(void *unisys);
extern int func_0203CDBC(void);
extern void func_02173650(int connect, void *connectPc);
extern void func_02172D50(void *unisys);
extern void *func_02012F2C(void *gameData);
extern u32 func_0200FB24(void);
extern u32 func_02173D38(void *unisys);
extern ColosseumWork *func_02174F4C(struct GameData *gameData, struct GameSystem *gameSystem, struct MyStatus *myStatus, int isChild);
extern u8 *func_02012944(void *gameData);
extern int func_0217BB20(UnionRoomWork *unisys);
extern int func_02173CB4(void);
extern void *func_021CD48C(void *fieldCtrl, void *fieldMap, int minPlayers, int maxPlayers, int heapId, int mode, int flagA, int flagB);
extern u32 func_021CD5A4(void *entryMenu);
extern void func_021CD60C(void *entryMenu, void *work, void *onAdd, void *onRemove);
extern u32 func_021CD688(void *entryMenu);
extern u8 func_02008554(const void *myStatus);
extern int func_02008550(const void *myStatus);
extern void func_0217357C(void *self, const u8 *mac, int gender, int trainerView);
extern void func_02173614(void *self, const u8 *mac);
extern void func_02174B40(UnionRoomWork *unisys);
extern u32 func_02174BB8(void *player, u32 flags);
extern int func_02174C34(void *trainerCard);
extern void func_02175094(void *colosseum, int value);
extern void *func_02188CB4(void *fieldMap);
extern void func_021750B0(ColosseumWork *colosseum, int value);
extern int func_021A3460(u32 fieldCtrl, u32 outZ, u32 outY, u32 outX);
extern int func_021679A4(void *commPlayer, int z, int y, int x, int outPlayer, int outFound);
extern void *func_021A3074(void *fieldView);
extern u32 func_02174CE4(void *colosseum);
extern u8 func_021750D0(void *colosseum);
extern int func_0216D3CC(int transition);
extern void func_0216D410(void *transition, u16 kind);
extern int func_0216D454(void *transition);
extern int func_0216D480(void *transition);
extern void *func_0200BAC8(void *saveData);
extern u32 func_0200BBA8(void *object);
extern int func_0217BA48(UnionRoomWork *unisys, void *mask);
extern int func_0217BA6C(UnionRoomWork *unisys, void *mask);
extern void *func_0217B9CC(UnionRoomWork *unisys);
extern void *func_021CC720(u32 fieldMap, u32 party, u32 regulationParam, u32 partyFlag, u32 teamFlag, u16 heapId);
extern int func_021CC810(void *partySelect);
extern u32 func_021CC7B4(void *partySelect, void *outIndex);
extern void func_0217B9F4(UnionRoomWork *unisys);
u32 func_02174E20(void);
u32 func_02174E64(void);
void func_02175240(void *colosseum, int value);
void func_02175208(void *colosseum);
int func_02175214(void *colosseum);
u32 func_02174D98(struct Party *party);
int func_02174DF0(u32 choice);
void func_0201AC2C(const void *src, void *dst);
void func_0201A2A8(void *regulation, void *party);
void *func_0201292C(const void *gameData);
void *func_0200873C(void *sys);
const void *func_020084F4(const void *player);
void func_0217AE20(void *unisys);
int func_02174F34(void);
void func_02172D38(void *unisys);
void func_02173408(void *unisys);
void func_02173524(void *unisys, void *connect);
void func_0217505C(ColosseumWork *colosseum, struct GameSystem *gameSystem);
void func_02012124(void *gameSystem, u32 value);
u16 func_02039338(void);
u8 func_0200855C(const void *obj);
void func_0201F02C(void *wordSet, u32 slot, void *player);
extern void *sub_020490F4(u32 id, u32 heap);
extern void sub_02034714(const char *expr, u32 line, const char *file);
extern void MTX_Identity33_(void *m);
u16 func_0217EC04(UnionRoomWork *unisys);
u16 func_0217EC1C(int sex);
u16 func_0217EC28(int sex);
u16 func_0217EC34(int sex);
u16 func_0217EC40(int category, int sex);
u16 func_0217EC54(int category, int sex);
u16 func_0217EC68(int category);
u16 func_0217EC78(int category);
u16 func_0217EC88(int sex);
u16 func_0217EC94(int sex);
u16 func_0217ECA0(int sex);
u16 func_0217ECAC(int sex);
u16 func_0217ECB8(UnionRoomWork *unisys);
u16 func_0217ECD0(UnionRoomWork *unisys);
u16 func_0217ECE8(int sex);
u16 func_0217ED04(int sex);
u16 func_0217ED10(int sex);
u16 func_0217ED2C(int sex);
u16 func_0217ED48(int sex);
u16 func_0217ED64(int sex);
u16 func_0217ED80(int sex);
u16 func_0217ED8C(int sex);
u16 func_0217ED98(int sex);
u16 func_0217EDA4(int sex);
u16 func_0217EDB0(int sex);
u16 func_0217EDBC(int sex);
u16 func_0217EDC8(int sex);
u16 func_0217EDD4(int sex);
u16 func_0217EDE0(int sex);
u16 func_0217EDEC(int sex);
u16 func_0217EDF8(int sex);
u16 func_0217EE04(int sex);
u16 func_0217EE10(int sex);
u16 func_0217EE1C(int sex);
u16 func_0217EE28(int sex);
u16 func_0217EE34(int sex);
u16 func_0217EE40(int sex);
int func_0217EE4C(UnionRoomWork *unisys, int nation, int area);
int func_0217F060(int category);
void func_0217F074(UnionRoomWork *unisys);
void func_0217F098(UnionRoomWork *unisys, u8 *fieldMap);
void func_0217F188(UnionRoomWork *unisys, u32 messageId);
u32 func_0217F1EC(UnionRoomWork *unisys);
void func_0217F210(UnionRoomWork *unisys, u8 *fieldMap, u32 messageId);
void func_0217F22C(UnionRoomWork *unisys, u32 fieldMap);
void func_0217F24C(UnionRoomWork *unisys);
int func_0217F268(UnionRoomWork *unisys, u32 *out);
void func_0217F360(UnionRoomWork *unisys, u32 fieldMap);
void func_0217F378(UnionRoomWork *unisys);
int func_0217F380(UnionRoomWork *unisys, int fieldMap);
void func_0217F388(UnionRoomWork *unisys, int fieldMap, int menuId, u8 *outArg);
void func_0217F4AC(UnionRoomWork *unisys);
int func_0217F4B4(UnionRoomWork *unisys, int *enteredSubmenu, u8 *arg, int *showHelp, u32 fieldMap);
void func_0217F5E0(UnionRoomWork *unisys, u32 fieldMap);
void func_0217F624(UnionRoomWork *unisys);
void func_0217F640(UnionRoomWork *unisys, u32 fieldMap, u32 failMask, int ruleId, int stage);
u32 func_0217F794(UnionRoomWork *unisys, u32 fieldMap);
void func_0217F7B8(UnionRoomWork *unisys);
int func_0217FDC8(ColosseumWork *colosseum);
int func_0217FDF8(ColosseumWork *colosseum);
int func_0217FE24(ColosseumWork *colosseum);
void func_0217FE38(ColosseumWork *colosseum);
int func_0217FE44(void *fieldMap, int mode, unsigned *out);
int func_0217FEB8(ColosseumWork *colosseum);
int func_0217FEF4(ColosseumWork *colosseum);
int func_0217FF14(UnionRoomWork *unisys);
extern int d_021807E8[];
extern char d_021807E4[];

int func_0217BD9C(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217BE44(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap);
int func_0217BE64(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217C03C(UnionRoomWork *unisys);
int func_0217C04C(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap);
int func_0217C074(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217C1F0(UnionRoomWork *unisys);
int func_0217C200(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217C2AC(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217C444(UnionRoomWork *unisys);
int func_0217C450(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217C518(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217C5A8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217C888(void);
int func_0217C88C(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217CAAC(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217CEB8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217CFA8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217D18C(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217D314(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217D51C(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217D5B8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217D7A4(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217D890(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217D9A8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
void func_0217DC64(UnionRoomWork *unisys, const void *myStatus, const u8 *mac);
void func_0217DC94(UnionRoomWork *unisys, const void *myStatus, const u8 *mac);
int func_0217DCA8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217DE88(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap);
int func_0217DEA0(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217DFB4(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217E0A4(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217E188(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217E378(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217E440(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217E5A0(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217E838(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217E904(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);
int func_0217EAD8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq);

int func_0217BD9C(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    UnionChatInputParam *param;
    UnionChatInputParam *finished;
    UnionPmsData *sentence;
    int cancelled;
    switch (*seq) {
    case 0:
        if (unisys->talkCancel == 0)
            return 1;
        unisys->talkCancel = 0;
        func_020061E4(0x54B);
        param = func_02030734(4, 12, 1, (const char *)d_021807E8, 0x41A);
        param->saveData = func_02012EBC(unisys->parent->gameData);
        unisys->sceneParam = param;
        func_0217422C(unisys, 0x1d, (int)param);
        (*seq)++;
        break;
    case 1:
        if (func_02174268(unisys) == 0)
            (*seq)++;
        break;
    case 2:
        finished = ((UnionChatInputParam *)unisys->sceneParam);
        sentence = finished->pms;
        cancelled = finished->cancelled;
        if (cancelled == 0)
            func_021736A0(unisys, sentence);
        func_020307B0(((UnionChatInputParam *)unisys->sceneParam));
        unisys->sceneParam = 0;
        return 1;
    }
    return 0;
}




int func_0217BE44(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap)
{
    func_020061E4(0x547);
    func_0217F210(unisys, fieldMap, 0xE2);
    return 1;
}





/*
 * Addresses are Black-image addresses.
 */
int func_0217BE64(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int slot;

    if (func_0217BB04(unisys) == 1) {
        return 1;
    }
    switch (*seq) {
    case 0:
        func_0203D14C(1, 1, 0);
        situation->waitTimer = 0;
        (*seq)++;
        break;
    case 1:
        if (func_0217F1EC(unisys) == 0) {
            break;
        }
        if (func_0203D1B4() > 1) {
            for (slot = 2; slot < 5; slot++) {
                if ((int)func_0203D1C0((u8)slot) == 1) {
                    break;
                }
            }
            if (slot < 5 || func_020392B8() > 2) {
                func_0217F210(unisys, fieldMap, func_0217EC04(unisys));
                func_0217B8E4(unisys, 0);
                func_02172D20(unisys);
                *seq = 4;
            } else {
                func_0203D7BC(1);
                func_0203D1E8((u32)func_020399A8(), 0);
                *seq = 2;
            }
        } else {
            situation->waitTimer++;
            if (situation->waitTimer > 600 || (func_020362DC() & 2)) {
                func_02172D20(unisys);
                func_0217B8E4(unisys, 0);
                func_021734A8(unisys, 1, 0);
                if (situation->waitTimer > 600) {
                    func_0217F210(unisys, fieldMap, func_0217EC04(unisys));
                } else {
                    func_0217F210(unisys, fieldMap, 10);
                }
                *seq = 5;
            }
        }
        break;
    case 2:
        if (situation->connect.partnerMac.enabled == 1) {
            if (memcmp(situation->connect.partnerMac.mac, situation->connect.talkPc->mac, 6) != 0) {
                if (func_02173AFC(2) == 1) {
                    func_0203D7BC(0);
                    *seq = 6;
                }
            } else {
                if (func_02173AFC(1) == 1) {
                    func_020061E4(0x806);
                    func_0217B8E4(unisys, 7);
                    func_021734A8(unisys, 3, (u32)situation->connect.talkPc);
                    func_021734A8(unisys, 1, 0);
                    *seq = 3;
                }
            }
        }
        break;
    case 3:
        if (func_0217F1EC(unisys) == 1) {
            return 1;
        }
        break;
    case 4:
        if (func_0217F1EC(unisys) == 1 && (func_020362DC() & 0xF3)) {
            return 1;
        }
        break;
    case 5:
        if (func_02172D68(unisys) == 0) {
            *seq = 4;
        }
        break;
    case 6:
        if (func_020392B8() <= 1) {
            func_02172D20(unisys);
            (*seq)++;
        }
        break;
    case 7:
        if (func_02172D68(unisys) == 0) {
            situation->connect.partnerMac.enabled = 0;
            *seq = 0;
        }
        break;
    }
    return 0;
}




/*
 * Remaining two bytes are alignment padding.
 */
int func_0217C03C(UnionRoomWork *unisys)
{
    func_021734A8(unisys, 1, 0);
    return 1;
}




int func_0217C04C(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap)
{
    func_020061E4(0x806);
    func_0217F210(unisys, fieldMap, 7);
    func_0217BAF0(unisys, fieldMap, 1);
    return 1;
}





int func_0217C074(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    if (func_0217BB04(unisys) == 1)
        return 1;

    switch (*seq) {
    case 0:
        if (situation->connect.connectParam == 0)
            func_02034714(d_021807E4, 0, d_021807E4);
        func_0203D14C(2, 1, situation->connect.connectParam->mac);
        situation->waitTimer = 0;
        *seq = 1;
        break;
    case 1:
        if (func_0203D1B4() > 1) {
            func_0203D7BC(1);
            *seq = 3;
            break;
        }
        situation->waitTimer++;
        if (situation->waitTimer > 600 || (func_020362DC() & 2)) {
            func_02172D20(unisys);
            func_0217B8E4(unisys, 0);
            func_021734A8(unisys, 2, 0);
            if (situation->waitTimer > 600)
                func_0217F210(unisys, fieldMap, 8);
            else
                func_0217F210(unisys, fieldMap, 10);
            *seq = 2;
        }
        break;
    case 2:
        if (func_02172D68(unisys) == 0 && func_0217F1EC(unisys) == 1 && (func_020362DC() & 0xf3))
            return 1;
        break;
    case 3:
        if (func_02173A90() == 1)
            *seq = 4;
        break;
    case 4:
        switch (situation->connect.partnerMode) {
        case 1:
            func_021734A8(unisys, 3, (u32)situation->connect.connectParam);
            func_021734A8(unisys, 2, 0);
            func_0217B8E4(unisys, 9);
            return 1;
        case 2:
            func_021734A8(unisys, 2, 0);
            func_0217F210(unisys, fieldMap, 8);
            func_02172D20(unisys);
            *seq = 5;
            break;
        }
        break;
    case 5:
        if (func_02172D68(unisys) == 0 && func_0217F1EC(unisys) == 1 && (func_020362DC() & 0xf3)) {
            func_0217B8E4(unisys, 0);
            return 1;
        }
        break;
    }
    return 0;
}




int func_0217C1F0(UnionRoomWork *unisys)
{
    func_021734A8(unisys, 2, 0);
    return 1;
}





int func_0217C200(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    void *commLink;
    if (func_0217BB04(unisys) == 1)
        return 1;
    if (situation->prevPlayCategory == 10) {
        situation->subState = 1;
        return 1;
    }
    situation->subState = 0;
    switch (*seq) {
    case 0:
        func_02173518(&situation->connect);
        func_021734A8(unisys, 4, 1);
        func_021735FC(&situation->connect, (situation->connect.connectPc));
        commLink = func_020399A8();
        func_02039C68(commLink, 2, 0x14);
        (*seq)++;
        break;
    case 1:
        commLink = func_020399A8();
        if (func_02039CB4(commLink, 2, 0x14) == 1)
            (*seq)++;
        break;
    case 2:
        if (func_02173B4C(unisys) == 1)
            (*seq)++;
        break;
    case 3:
        if (func_02080D24(situation->connect.myStatusRecvBits) > 1)
            return 1;
        break;
    }
    return 0;
}





int func_0217C2AC(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    void *party;
    int menuResult;

    if (func_0217BB04(unisys) == 1)
        return 1;

    switch (*seq) {
    case 0:
        if (situation->subState == 1) {
            situation->subState = 0;
        } else if (situation->connect.talkCount == 0) {
            func_0217F210(unisys, fieldMap, func_0217EC1C(situation->connect.talkParam->sex));
            situation->connect.talkCount++;
        } else {
            func_0217F210(unisys, fieldMap, func_0217EC88(situation->connect.talkParam->sex));
        }
        (*seq)++;
        break;
    case 1:
        if (func_0217F1EC(unisys) == 1)
            (*seq)++;
        break;
    case 2:
        func_0217F360(unisys, (u32)fieldMap);
        (*seq)++;
        break;
    case 3:
        party = func_02012934(unisys->parent->gameData);
        menuResult = func_0217F380(unisys, (int)fieldMap);
        if (menuResult == -1)
            break;
        func_0217F378(unisys);
        if (menuResult == -2 || menuResult == 0) {
            func_0217F210(unisys, fieldMap, func_0217EC28(situation->connect.talkParam->sex));
            situation->connect.partnerSelectA = 0;
            func_0217B8E4(unisys, 8);
            return 1;
        }
        if (menuResult == 0x18) {
            func_020120F4(unisys->parent->gameSystem);
            if ((int)func_0201AA1C(party) < 2) {
                func_0217F210(unisys, fieldMap, func_0217ECA0(situation->connect.talkParam->sex));
                *seq = 4;
                break;
            }
        } else if (menuResult == 0x19) {
            if ((int)func_0201AAD4(party) > 0) {
                func_0217F210(unisys, fieldMap, func_0217ECB8(unisys));
                *seq = 4;
                break;
            } else if (func_0201AA88(party) == 0) {
                func_0217F210(unisys, fieldMap, func_0217ECAC(situation->connect.talkParam->sex));
                *seq = 4;
                break;
            }
        }
        if (menuResult == 0x1b) {
            func_0217B8E4(unisys, 10);
            return 1;
        }
        situation->connect.partnerSelectA = menuResult;
        func_0217B8E4(unisys, 8);
        return 1;
    case 4:
        if (func_0217F1EC(unisys) == 1)
            *seq = 0;
        break;
    }
    return 0;
}





int func_0217C444(UnionRoomWork *unisys)
{
    func_0217F378(unisys);
    return 1;
}





int func_0217C450(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    if (func_0217BB04(unisys) == 1)
        return 1;

    switch (*seq) {
    case 0:
        if (func_02173A04(situation->connect.partnerSelectA) == 1) {
            if (situation->connect.partnerSelectA == 0) {
                func_0217B8E4(unisys, 0x27);
                return 1;
            }
            func_0217F210(unisys, fieldMap, func_0217EC40(situation->connect.partnerSelectA, situation->connect.talkParam->sex));
            (*seq)++;
        }
        break;
    case 1:
        if (func_0217F1EC(unisys) != 0) {
            if (situation->connect.partnerSelectB == 1) {
                func_0217B8E4(unisys, situation->connect.partnerSelectA + 11);
                (*seq)++;
            } else if (situation->connect.partnerSelectB == 0) {
                func_0217B8E4(unisys, 0x27);
                func_0217F210(unisys, fieldMap, func_0217EC54(situation->connect.partnerSelectA, situation->connect.talkParam->sex));
                return 1;
            }
        }
        break;
    case 2:
        if (func_0217F1EC(unisys) == 1)
            return 1;
        break;
    }
    return 0;
}





int func_0217C518(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    void *commLink;
    if (func_0217BB04(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        func_02173518(&situation->connect);
        func_021734A8(unisys, 4, 1);
        func_021735FC(&situation->connect, (situation->connect.connectPc));
        commLink = func_020399A8();
        func_02039C68(commLink, 2, 0x14);
        (*seq)++;
        break;
    case 1:
        commLink = func_020399A8();
        if (func_02039CB4(commLink, 2, 0x14) == 1)
            (*seq)++;
        break;
    case 2:
        if (func_02173B4C(unisys) == 1)
            (*seq)++;
        break;
    case 3:
        if (func_02080D24(situation->connect.myStatusRecvBits) > 1)
            return 1;
        break;
    }
    return 0;
}





int func_0217C5A8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int accepted;
    void *party;

    if (func_0217BB04(unisys) == 1)
        return 1;
    if (func_0217F1EC(unisys) == 0)
        return 0;

    switch (*seq) {
    case 0:
        func_0217F210(unisys, fieldMap, 9);
        (*seq)++;
        break;
    case 1:
        if (situation->connect.partnerSelectA == 0xff)
            break;
        if (situation->connect.partnerSelectA == 0) {
            func_0217F210(unisys, fieldMap, func_0217EC34(situation->connect.talkParam->sex));
            func_0217B8E4(unisys, 0x27);
            return 1;
        }
        if (situation->connect.partnerSelectA < 0x1b) {
            func_0217F210(unisys, fieldMap, func_0217EC68(situation->connect.partnerSelectA));
            if (func_0217B9BC(situation->connect.partnerSelectA) == 1) {
                func_0217BA10(unisys, situation->connect.partnerSelectA);
                func_0217F640(unisys, (u32)fieldMap, 0, func_0217B974(situation->connect.partnerSelectA), 0);
                *seq = 2;
            } else {
                *seq = 3;
            }
        } else if (func_02173A48(0) == 1) {
            func_0217F210(unisys, fieldMap, 0x13d);
            func_0217B8E4(unisys, 0x27);
            return 1;
        }
        break;
    case 2:
        if (func_0217F794(unisys, (u32)fieldMap) == 1)
            *seq = 3;
        break;
    case 3:
        func_0217F7B8(unisys);
        func_0217F22C(unisys, (u32)fieldMap);
        (*seq)++;
        break;
    case 4:
        situation->subState = 0;
        if (func_0217F268(unisys, (u32 *)(&accepted)) != 1)
            break;
        party = func_02012934(unisys->parent->gameData);
        func_0217F24C(unisys);
        if (func_0217BAA8(unisys, situation->connect.partnerSelectA, &situation->partyFailMask, &situation->teamFailMask) == 0) {
            func_0217F210(unisys, fieldMap, 0x13e);
            accepted = 0;
        } else if (situation->connect.partnerSelectA == 0x18 && accepted == 1) {
            func_020120F4(unisys->parent->gameSystem);
            if ((int)func_0201AA1C(party) < 2) {
                accepted = 0;
                situation->subState = 1;
            }
        } else if (situation->connect.partnerSelectA == 0x19 && accepted == 1) {
            if ((int)func_0201AAD4(party) > 0) {
                accepted = 0;
                situation->subState = 3;
            } else if (func_0201AA88(party) == 0) {
                accepted = 0;
                situation->subState = 2;
            }
        }
        situation->connect.partnerSelectB = accepted;
        (*seq)++;
        break;
    case 5:
        if (func_02173A48(situation->connect.partnerSelectB) == 1) {
            if (situation->partyFailMask != 0 && situation->teamFailMask != 0)
                *seq = 6;
            else
                *seq = 10;
        }
        break;
    case 6:
        func_0217F640(unisys, (u32)fieldMap, situation->partyFailMask, func_0217B974(situation->connect.partnerSelectA), 1);
        (*seq)++;
        break;
    case 7:
        if (func_0217F794(unisys, (u32)fieldMap) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(unisys);
            if (situation->teamFailMask == -1)
                *seq = 10;
            else
                (*seq)++;
        }
        break;
    case 8:
        func_0217F640(unisys, (u32)fieldMap, situation->partyFailMask, func_0217B974(situation->connect.partnerSelectA), 2);
        (*seq)++;
        break;
    case 9:
        if (func_0217F794(unisys, (u32)fieldMap) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(unisys);
            *seq = 10;
        }
        break;
    case 10:
        if (situation->connect.partnerSelectB == 0) {
            if (situation->subState == 1)
                func_0217F210(unisys, fieldMap, 0x28);
            else if (situation->subState == 2)
                func_0217F210(unisys, fieldMap, 0x2f);
            else if (situation->subState == 3)
                func_0217F210(unisys, fieldMap, func_0217ECD0(unisys));
            else
                func_0217F210(unisys, fieldMap, func_0217EC78(situation->connect.partnerSelectA));
            func_0217B8E4(unisys, 0x27);
            return 1;
        }
        func_0217B8E4(unisys, situation->connect.partnerSelectA + 11);
        *seq = 11;
        break;
    case 11:
        return 1;
    }
    return 0;
}




int func_0217C888(void)
{
    return 1;
}




int func_0217C88C(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int enteredSubmenu;
    int showHelp;
    int choice;

    if (func_0217BB04(unisys) == 1)
        return 1;
    if (func_0217F1EC(unisys) == 0)
        return 0;

    switch (*seq) {
    case 0:
        situation->subState = 0;
        (*seq)++;
        break;
    case 1:
        if (situation->subState == 5)
            func_0217F5E0(unisys, (u32)fieldMap);
        else if (situation->subState == 0)
            func_0217F624(unisys);
        func_0217F388(unisys, (int)fieldMap, situation->subState, (u8 *)(&situation->subMenuArg));
        (*seq)++;
        break;
    case 2:
        choice = func_0217F4B4(unisys, &enteredSubmenu, (u8 *)(&situation->subMenuArg), &showHelp, (u32)fieldMap);
        if (enteredSubmenu == 1) {
            situation->subState = choice;
            func_0217F4AC(unisys);
            (*seq)--;
        } else if (choice == -2 || choice == 0) {
            func_0217F4AC(unisys);
            if (situation->subState > 0) {
                situation->subState = 0;
                (*seq)--;
            } else {
                func_0217F624(unisys);
                func_0217B8E4(unisys, 7);
                return 1;
            }
        } else if (showHelp == 1) {
            func_0217F624(unisys);
            func_0217F4AC(unisys);
            func_0217BA10(unisys, choice);
            situation->connect.partnerSelectA = choice;
            *seq = 3;
        } else if (choice != -1) {
            func_0217F624(unisys);
            func_0217F4AC(unisys);
            if (func_0217BAA8(unisys, choice, &situation->partyFailMask, &situation->teamFailMask) == 0) {
                func_0217F210(unisys, fieldMap, 0x13e);
                *seq = 5;
            } else {
                situation->connect.partnerSelectA = choice;
                func_0217B8E4(unisys, 8);
                return 1;
            }
        }
        break;
    case 3:
        func_0217F640(unisys, (u32)fieldMap, 0, func_0217B974(situation->connect.partnerSelectA), 0);
        (*seq)++;
        break;
    case 4:
        if (func_0217F794(unisys, (u32)fieldMap) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(unisys);
            *seq = 1;
        }
        break;
    case 5:
        func_0217F640(unisys, (u32)fieldMap, situation->partyFailMask, func_0217B974(situation->connect.partnerSelectA), 1);
        (*seq)++;
        break;
    case 6:
        if (func_0217F794(unisys, (u32)fieldMap) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(unisys);
            if (situation->teamFailMask == -1)
                *seq = 9;
            else
                (*seq)++;
        }
        break;
    case 7:
        func_0217F640(unisys, (u32)fieldMap, situation->partyFailMask, func_0217B974(situation->connect.partnerSelectA), 2);
        (*seq)++;
        break;
    case 8:
        if (func_0217F794(unisys, (u32)fieldMap) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(unisys);
            *seq = 9;
        }
        break;
    case 9:
        func_0217F210(unisys, fieldMap, func_0217EC88(situation->connect.talkParam->sex));
        *seq = 0;
        break;
    }
    return 0;
}




int func_0217CAAC(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int beaconIndex, partnerStatus;
    u32 firstAnswer, secondAnswer;
    void *party;
    beaconIndex = func_0217AEFC(situation->connect.requestId);
    partnerStatus = unisys->beaconPc[beaconIndex].beacon.status;
    switch (*seq) {
    case 0:
        situation->connect.partnerSelectA = partnerStatus;
        switch (partnerStatus) {
        case 1: func_0217F210(unisys,fieldMap,func_0217ED04(situation->connect.talkParam->sex)); func_0217B8E4(unisys, 0); *seq=2; goto done;
        case 2: func_0217F210(unisys,fieldMap,func_0217ED10(situation->connect.talkParam->sex)); func_0217B8E4(unisys, 0); *seq=2; goto done;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
            func_0217F210(unisys,fieldMap,func_0217ECE8(situation->connect.talkParam->sex)); func_0217B8E4(unisys, 0); *seq=2; goto done;
        case 20: case 21: case 22: case 23:
            if ((int)unisys->beaconPc[beaconIndex].beacon.connectNum < func_0217F060(partnerStatus)) {
                func_0217F210(unisys,fieldMap,func_0217ED80(situation->connect.talkParam->sex));
                func_0217BA10(unisys,partnerStatus);
                func_0217F640(unisys,(int)fieldMap,(int)0,func_0217B974(partnerStatus),0);
                *seq = 3;
                goto done;
            }
            func_0217F210(unisys,fieldMap,func_0217ECE8(situation->connect.talkParam->sex));
            func_0217B8E4(unisys, 0); *seq=2; goto done;
        case 25:
            if ((int)unisys->beaconPc[beaconIndex].beacon.connectNum < func_0217F060(partnerStatus) &&
                unisys->beaconPc[beaconIndex].beacon.appActive == 0) {
                func_0217F210(unisys,fieldMap,func_0217ED8C(situation->connect.talkParam->sex));
                *seq = 10;
                goto done;
            }
            func_0217F210(unisys,fieldMap,func_0217ED64(situation->connect.talkParam->sex)); func_0217B8E4(unisys, 0); *seq=2; goto done;
        case 3:
            if ((int)unisys->beaconPc[beaconIndex].beacon.connectNum < func_0217F060(partnerStatus)) {
                func_0217F210(unisys,fieldMap,func_0217ED98(situation->connect.talkParam->sex));
                *seq = 10;
                goto done;
            }
            func_0217F210(unisys,fieldMap,func_0217ED2C(situation->connect.talkParam->sex)); func_0217B8E4(unisys, 0); *seq=2; goto done;
        case 24: func_0217F210(unisys,fieldMap,func_0217ED48(situation->connect.talkParam->sex)); func_0217B8E4(unisys, 0); *seq=2; goto done;
        case 0: default: func_0217F210(unisys,fieldMap,0x151); func_0217B8E4(unisys, 0); *seq=2; goto done;
        }
        break;
    case 2:
        if (func_0217F1EC(unisys) == 1 && (func_020362DC() & 0xf3)) return 1;
        break;
    case 1:
        if (func_0217F1EC(unisys) == 1) return 1;
        break;
    case 3:
        if (func_0217F794(unisys,(u32)fieldMap) == 1) *seq = 4;
        break;
    case 4:
        if (func_0217F1EC(unisys) == 1) {
            func_0217F7B8(unisys); func_0217F22C(unisys,(u32)fieldMap); (*seq)++;
        }
        break;
    case 5:
        if (func_0217F268(unisys,&firstAnswer) == 1) {
            func_0217F24C(unisys);
            if (firstAnswer == 0) {
                func_0217F210(unisys,fieldMap,func_0217EDA4(situation->connect.talkParam->sex));
                func_0217B8E4(unisys, 0); *seq = 2;
            } else if (func_0217BAA8(unisys,situation->connect.partnerSelectA,&situation->partyFailMask,&situation->teamFailMask) == 0) {
                func_0217F210(unisys,fieldMap,0x13e); func_0217B8E4(unisys, 0); *seq = 6;
            } else {
                situation->connect.partnerSelectB = firstAnswer; func_0217B8E4(unisys, 0x26);
                func_0217F210(unisys,fieldMap,func_0217EE28(situation->connect.talkParam->sex)); *seq = 1;
            }
        }
        break;
    case 6:
        if (func_0217F1EC(unisys) == 1) return 1;
        func_0217F640(unisys,(int)fieldMap,(int)situation->partyFailMask,func_0217B974(situation->connect.partnerSelectA),1); (*seq)++;
        break;
    case 7:
        if (func_0217F794(unisys,(u32)fieldMap) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(unisys);
            if (situation->teamFailMask == -1) *seq = 1; else (*seq)++;
        }
        break;
    case 8:
        func_0217F640(unisys,(int)fieldMap,(int)situation->partyFailMask,func_0217B974(situation->connect.partnerSelectA),2); (*seq)++;
        break;
    case 9:
        if (func_0217F794(unisys,(u32)fieldMap) == 1 && (func_020362DC() & 3)) {
            func_0217F7B8(unisys); *seq = 1;
        }
        break;
    case 10:
        if (func_0217F1EC(unisys) == 1) {
            func_0217F22C(unisys,(u32)fieldMap); (*seq)++;
        }
        break;
    case 11:
        if (func_0217F268(unisys,&secondAnswer) == 1) {
            func_0217F24C(unisys);
            if (secondAnswer == 0) {
                switch (situation->connect.partnerSelectA) {
                case 3: func_0217F210(unisys,fieldMap,func_0217EDBC(situation->connect.talkParam->sex)); break;
                case 25: func_0217F210(unisys,fieldMap,func_0217EDB0(situation->connect.talkParam->sex)); break;
                }
                func_0217B8E4(unisys, 0); *seq = 2;
            } else {
                situation->connect.partnerSelectB = secondAnswer; func_0217B8E4(unisys, 0x26); *seq = 1;
                switch (situation->connect.partnerSelectA) {
                case 3: func_0217F210(unisys,fieldMap,func_0217EE04(situation->connect.talkParam->sex)); break;
                case 25:
                    party = func_02012934(unisys->parent->gameData);
                    if ((int)func_0201AAD4(party) > 0) {
                        func_0217F210(unisys,fieldMap,func_0217EDD4(situation->connect.talkParam->sex));
                        func_0217B8E4(unisys, 0); *seq = 2;
                    } else if (func_0201AA88(party) == 0) {
                        func_0217F210(unisys,fieldMap,func_0217EDC8(situation->connect.talkParam->sex));
                        func_0217B8E4(unisys, 0); *seq = 2;
                    } else func_0217F210(unisys,fieldMap,func_0217EDE0(situation->connect.talkParam->sex));
                    break;
                }
            }
        }
        break;
    }
done:
    return 0;
}









int func_0217CEB8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int partnerSex;

    switch (*seq) {
    case 0:
        partnerSex = func_0217AF04(unisys, situation->connect.requestId);
        switch (unisys->beaconPc[func_0217AEFC(situation->connect.requestId)].beacon.status) {
        case 1:
            func_0217F210(unisys, fieldMap, func_0217ED04(partnerSex));
            break;
        case 2:
            func_0217F210(unisys, fieldMap, func_0217ED10(partnerSex));
            break;
        case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11:
        case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19:
        case 20: case 21: case 22: case 23:
            func_0217F210(unisys, fieldMap, func_0217ECE8(partnerSex));
            break;
        case 25:
            func_0217F210(unisys, fieldMap, func_0217ED64(partnerSex));
            break;
        case 3:
            func_0217F210(unisys, fieldMap, func_0217ED2C(partnerSex));
            break;
        case 24:
            func_0217F210(unisys, fieldMap, func_0217ED48(partnerSex));
            break;
        case 0:
        default:
            func_0217F210(unisys, fieldMap, 0x151);
            break;
        }
        func_0217B8E4(unisys, 0);
        (*seq)++;
        break;
    case 1:
        if (func_0217F1EC(unisys) == 1 && (func_020362DC() & 0xf3))
            return 1;
        break;
    }
    return 0;
}









int func_0217CFA8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    u8 *cardBytes;
    if (func_0217BB04(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        if (unisys->myTrainerCard != 0 || unisys->recvTrainerCard != 0)
            func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
        unisys->myTrainerCard = func_02030734(0x41, 0x678, 1, (const char *)d_021807E8, 0x9B3);
        unisys->recvTrainerCard = func_02030734(0x41, 0x678, 1, (const char *)d_021807E8, 0x9B5);
        func_0216F40C(unisys->myTrainerCard, unisys->parent->gameData, 1, 0, 0x41);
        func_02082D44(unisys->myTrainerCard, unisys->recvTrainerCard, 0x678);
        func_02039C68(func_020399A8(), 3, 0x14);
        func_0217F210(unisys, fieldMap, func_0217EE4C(unisys, situation->connect.talkParam->nation, situation->connect.talkParam->area));
        (*seq)++;
        break;
    case 1:
        if (func_02039CB4(func_020399A8(), 3, 0x14) == 1)
            (*seq)++;
        break;
    case 2:
        if (func_02173BB0(unisys) == 1)
            (*seq)++;
        break;
    case 3:
        if (situation->connect.trainerCardReceived == 1 && func_0217F1EC(unisys) == 1) {
            cardBytes = unisys->recvTrainerCard;
            cardBytes[4] |= 0x20;
            unisys->partnerCard = func_0216F7F4(unisys->parent->gameData, unisys->recvTrainerCard, 0x41);
            (*seq)++;
        }
        break;
    case 4:
        func_02039C68(func_020399A8(), 4, 0x14);
        (*seq)++;
        break;
    case 5:
        if (func_02039CB4(func_020399A8(), 4, 0x14) == 1)
            (*seq)++;
        break;
    case 6:
        func_0217422C(unisys, 1, (int)(unisys->partnerCard));
        (*seq)++;
        break;
    case 7:
        if (func_02174268(unisys) == 0)
            (*seq)++;
        break;
    case 8:
        func_0217F210(unisys, fieldMap, 0x10);
        func_02039C68(func_020399A8(), 5, 0x14);
        (*seq)++;
        break;
    case 9:
        if (func_0217F1EC(unisys) != 0 && func_02039CB4(func_020399A8(), 5, 0x14) == 1) {
            func_020307B0(unisys->myTrainerCard);
            func_020307B0(unisys->recvTrainerCard);
            unisys->partnerCard = 0;
            unisys->myTrainerCard = 0;
            unisys->recvTrainerCard = 0;
            if (func_0203D378() == 1)
                func_0217B8E4(unisys, 7);
            else
                func_0217B8E4(unisys, 9);
            return 1;
        }
        break;
    }
    return 0;
}









int func_0217D18C(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    void *gameData;
    void *commState;
    UnionTradeParam *param;
    UnionTradeSetup *setup;
    if (*seq != 4 && func_0217BB04(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        func_0217F210(unisys, fieldMap, 0x26);
        (*seq)++;
        break;
    case 1:
        if (func_0217F1EC(unisys) == 1) {
            func_02039C68(func_020399A8(), 6, 0x14);
            (*seq)++;
        }
        break;
    case 2:
        if (func_02039CB4(func_020399A8(), 6, 0x14) == 1) {
            gameData = func_020120F4(unisys->parent->gameSystem);
            commState = func_0200ED48(func_02012EBC(gameData));
            func_0200ED54(commState, func_02008530(func_02012950(gameData, func_0203D1A4(func_020399A8()) ^ 1)));
            (*seq)++;
        }
        break;
    case 3:
        param = func_02030734(0x41, 0x30, 1, (const char *)d_021807E8, 0xA54);
        param->gameData = (int)func_020120F4(unisys->parent->gameSystem);
        param->party = (int)func_0201A920(0x41);
        setup = func_02030734(4, 0x14, 0, (const char *)d_021807E8, 0xA5B);
        setup->gameData = param->gameData;
        setup->party = param->party;
        setup->tradeMode = 0;
        setup->isEvent = 0;
        setup->isDemo = 0;
        setup->isComm = 1;
        setup->result = 0;
        param->setup = setup;
        param->result = 0;
        unisys->sceneParam = param;
        func_0217422C(unisys, 2, (int)param);
        (*seq)++;
        break;
    case 4:
        if (func_02174268(unisys) == 0) {
            param = ((UnionTradeParam *)unisys->sceneParam);
            func_020307B0(param->setup);
            func_020307B0((void *)param->party);
            func_020307B0(((UnionTradeParam *)unisys->sceneParam));
            unisys->sceneParam = 0;
            (*seq)++;
        }
        break;
    case 5:
        func_0217F210(unisys, fieldMap, 0x10);
        func_02039C68(func_020399A8(), 7, 0x14);
        (*seq)++;
        break;
    case 6:
        if (func_0217F1EC(unisys) != 0 && func_02039CB4(func_020399A8(), 7, 0x14) == 1) {
            if (func_0203D378() == 1)
                func_0217B8E4(unisys, 7);
            else
                func_0217B8E4(unisys, 9);
            return 1;
        }
        break;
    }
    return 0;
}









int func_0217D314(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int beaconIndex;
    int requiredCount;
    beaconIndex = func_0217AEFC(situation->connect.requestId);
    if (func_0217BB04(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        situation->connect.serviceLocked = 1;
        func_021736E0(situation->connect.partnerSelectA);
        func_0203D14C(2, 1, unisys->beaconPc[beaconIndex].mac);
        situation->waitTimer = 0;
        (*seq)++;
        break;
    case 1:
        if (func_0217F1EC(unisys) == 0)
            break;
        if (func_0203D1B4() > 1) {
            func_0203D7BC(1);
            requiredCount = func_0217F060(situation->connect.partnerSelectA);
            if (requiredCount <= (int)func_0203D1A4(func_020399A8())) {
                *seq = 4;
            } else {
                func_021734A8(unisys, 3, (u32)&unisys->beaconPc[beaconIndex]);
                situation->connect.serviceFlag = 1;
                switch (situation->connect.partnerSelectA) {
                case 0x14:
                    func_0217B8E4(unisys, (int)0x1f);
                    break;
                case 0x15:
                    func_0217B8E4(unisys, (int)0x20);
                    break;
                case 0x16:
                    func_0217B8E4(unisys, (int)0x21);
                    break;
                case 0x17:
                    func_0217B8E4(unisys, (int)0x22);
                    break;
                case 3:
                    func_0217B8E4(unisys, (int)0xe);
                    break;
                case 0x19:
                    func_0217B8E4(unisys, (int)0x24);
                    break;
                default:
                    func_02034714((const char *)d_021807E4, (int)0, (const char *)d_021807E4);
                    break;
                }
                *seq = 3;
            }
        } else {
            situation->waitTimer++;
            if (situation->waitTimer > 600 || (func_020362DC() & 2)) {
                situation->connect.serviceLocked = 0;
                func_0217B8E4(unisys, (int)0);
                *seq = 4;
            }
        }
        break;
    case 2:
        switch (situation->connect.partnerSelectA) {
        case 0x14:
        case 0x15:
        case 0x16:
        case 0x17:
            func_0217F210(unisys, fieldMap, func_0217EE40(situation->connect.talkParam->sex));
            break;
        case 3:
            func_0217F210(unisys, fieldMap, func_0217EE1C(situation->connect.talkParam->sex));
            break;
        case 0x19:
            func_0217F210(unisys, fieldMap, func_0217EDF8(situation->connect.talkParam->sex));
            break;
        }
        *seq = 3;
        break;
    case 3:
        if (func_0217F1EC(unisys) == 1)
            return 1;
        break;
    case 4:
        func_02172D20(unisys);
        (*seq)++;
        break;
    case 5:
        if (func_02172D68(unisys) == 0)
            *seq = 2;
        break;
    }
    return 0;
}









int func_0217D51C(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    int linkState;
    UnionBeaconPc *connectPc;
    if (*seq < 3 && func_0217BB04(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        func_02172EDC(unisys);
        (*seq)++;
        break;
    case 1:
        if (func_02172D68(unisys) != 0)
            break;
        linkState = func_0203CDBC();
        if (linkState == 1) {
            connectPc = situation->connect.connectPc;
            if (connectPc != 0) {
                func_02173650((int)(&situation->connect), connectPc);
                func_021734A8(unisys, 3, 0);
            }
            func_02172D50(unisys);
            (*seq)++;
        }
        break;
    case 2:
        if (func_02172D68(unisys) == 0)
            (*seq)++;
        break;
    case 3:
        if (func_0217F1EC(unisys) == 1) {
            if (func_020362DC() & 0xf3)
                return 1;
        }
        break;
    }
    return 0;
}









int func_0217D5B8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    UnionSceneThreeParam *paramThree;
    UnionSceneFourParam *paramFour;
    if (*seq != 4 && *seq != 5 && *seq != 8 && func_0217BB04(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        if (situation->connect.serviceFlag == 1)
            *seq = 6;
        else
            (*seq)++;
        break;
    case 1:
        func_02039C68(func_020399A8(), 8, 0x14);
        (*seq)++;
        break;
    case 2:
        if (func_02039CB4(func_020399A8(), 8, 0x14) == 1)
            (*seq)++;
        break;
    case 3:
        if (func_0217F1EC(unisys) == 1) {
            if (situation->playCategory == 0xe) {
                paramThree = func_02030734(0x41, 8, 1, (const char *)d_021807E8, 0xB9A);
                paramThree->gameData = unisys->parent->gameData;
                unisys->sceneParam = paramThree;
                func_0217422C(unisys, 3, (int)paramThree);
            } else {
                paramFour = func_02030734(0x41, 0x18, 1, (const char *)d_021807E8, 0xBA2);
                paramFour->gameData = unisys->parent->gameData;
                paramFour->party = func_02012934(unisys->parent->gameData);
                paramFour->saveData = func_02012EBC(unisys->parent->gameData);
                paramFour->bag = func_02012F2C(unisys->parent->gameData);
                unisys->sceneParam = paramFour;
                func_0217422C(unisys, 4, (int)paramFour);
            }
            (*seq)++;
        }
        break;
    case 4:
        if (func_02174268(unisys) == 0) {
            func_020307B0(unisys->sceneParam);
            unisys->sceneParam = 0;
            if (func_0200FB24() != 0) {
                func_0217B8E4(unisys, 1);
                return 1;
            }
            func_02172D50(unisys);
            (*seq)++;
        }
        break;
    case 5:
        if (func_02172D68(unisys) == 0)
            return 1;
        break;
    case 6:
        if (func_02173D38(unisys) == 1)
            (*seq)++;
        break;
    case 7:
        switch (unisys->entryResult) {
        case 1:
            if (situation->playCategory == 0xe)
                func_0217F210(unisys, fieldMap, func_0217EE10(situation->connect.talkParam->sex));
            else
                func_0217F210(unisys, fieldMap, func_0217EDEC(situation->connect.talkParam->sex));
            *seq = 3;
            break;
        case 2:
            if (situation->playCategory == 0xe)
                func_0217F210(unisys, fieldMap, func_0217EE1C(situation->connect.talkParam->sex));
            else
                func_0217F210(unisys, fieldMap, func_0217EDF8(situation->connect.talkParam->sex));
            func_02172D20(unisys);
            *seq = 8;
            break;
        }
        break;
    case 8:
        if (func_0217F1EC(unisys) == 1 && func_02172D68(unisys) == 0) {
            func_021734A8(unisys, 3, 0);
            return 1;
        }
        break;
    }
    return 0;
}









int func_0217D7A4(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    UnionParentWork *parent;
    if (*seq < 4 && func_0217BB04(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        if (unisys->colosseum != 0)
            func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
        parent = unisys->parent;
        unisys->colosseum = func_02174F4C(parent->gameData, parent->gameSystem, parent->myStatus, situation->connect.serviceFlag);
        func_0217F210(unisys, fieldMap, func_0217EC94(situation->connect.talkParam->sex));
        (*seq)++;
        break;
    case 1:
        if (func_0217F1EC(unisys) == 1)
            (*seq)++;
        break;
    case 2:
        func_02039C68(func_020399A8(), 0xb, 0x14);
        (*seq)++;
        break;
    case 3:
        if (func_02039CB4(func_020399A8(), 0xb, 0x14) == 1)
            (*seq)++;
        break;
    case 4:
        func_0217422C(unisys, situation->connect.partnerSelectA + 1, 0);
        (*seq)++;
        break;
    case 5:
        if (func_02174268(unisys) == 0) {
            func_0217BAF0(unisys, fieldMap, 1);
            func_0217B8E4(unisys, 0x28);
            return 1;
        }
        break;
    }
    return 0;
}








int func_0217D890(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    UnionParentWork *parent;
    if (*seq < 4 && func_0217BB04(unisys) == 1)
        return 1;
    switch (*seq) {
    case 0:
        if (situation->connect.serviceFlag == 0)
            func_0217F210(unisys, fieldMap, func_0217EC94(situation->connect.talkParam->sex));
        else
            func_0217F210(unisys, fieldMap, func_0217EE34(situation->connect.talkParam->sex));
        (*seq)++;
        break;
    case 1:
        if (func_0217F1EC(unisys) == 1)
            (*seq)++;
        break;
    case 2:
        if (situation->connect.serviceFlag == 0)
            func_02039C68(func_020399A8(), 0xb, 0x14);
        (*seq)++;
        break;
    case 3:
        if (situation->connect.serviceFlag == 0) {
            if (func_02039CB4(func_020399A8(), 0xb, 0x14) == 1)
                (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 4:
        func_0217422C(unisys, situation->connect.partnerSelectA + 1, 0);
        (*seq)++;
        break;
    case 5:
        if (func_02174268(unisys) == 0) {
            if (unisys->colosseum != 0)
                func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
            parent = unisys->parent;
            unisys->colosseum = func_02174F4C(parent->gameData, parent->gameSystem, parent->myStatus, situation->connect.serviceFlag);
            func_0217BAF0(unisys, fieldMap, 1);
            func_0217B8E4(unisys, 0x28);
            return 1;
        }
        break;
    }
    return 0;
}








int func_0217D9A8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    int entryResult;

    func_0203D1A4(func_020399A8());
    if (colosseum == 0)
        func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);

    if (func_0217BB20(unisys) == 1) {
        if (colosseum->entryMenu != 0)
            func_021CD5A4(colosseum->entryMenu);
        func_0217F074(unisys);
        return 1;
    }

    switch (*seq) {
    case 0:
        if (func_0217F060(situation->connect.partnerSelectA) == 2) {
            colosseum->parentSetting = 1;
            if (func_0203D378() == 1) {
                if (func_02173CB4() == 1)
                    *seq = 100;
            } else {
                *seq = 100;
            }
            break;
        }
        func_0203D7BC(0);
        if (func_0203D378() == 1) {
            colosseum->entryMenu = func_021CD48C(func_02012944(unisys->parent->gameData), fieldMap,
                                    func_0217F060(situation->connect.partnerSelectA),
                                    func_0217F060(situation->connect.partnerSelectA), 0x41, 0, 0, 0);
            func_021CD60C(colosseum->entryMenu, unisys, func_0217DC64, func_0217DC94);
        } else if (situation->connect.serviceFlag == 0) {
            colosseum->entryMenu = func_021CD48C(func_02012944(unisys->parent->gameData), fieldMap,
                                    func_0217F060(situation->connect.partnerSelectA),
                                    func_0217F060(situation->connect.partnerSelectA), 0x41, 2, 0, 0);
        } else {
            colosseum->entryMenu = func_021CD48C(func_02012944(unisys->parent->gameData), fieldMap,
                                    func_0217F060(situation->connect.partnerSelectA),
                                    func_0217F060(situation->connect.partnerSelectA), 0x41, 3, 0, 0);
        }
        if (situation->connect.serviceFlag == 0) {
            func_021736E0(situation->status);
            func_02039C68(func_020399A8(), 0xc, 0x14);
        }
        (*seq)++;
        break;
    case 1:
        if (situation->connect.serviceFlag == 0) {
            if (func_02039CB4(func_020399A8(), 0xc, 0x14) == 1) {
                func_0203D1E8((int)func_020399A8(), (void *)1);
                (*seq)++;
            }
        } else {
            (*seq)++;
        }
        break;
    case 2:
        (*seq)++;
        break;
    case 3:
        entryResult = func_021CD688(colosseum->entryMenu);
        if (entryResult != 0) {
            colosseum->entryBits = func_021CD5A4(colosseum->entryMenu);
            colosseum->entryMenu = 0;
            switch (entryResult) {
            case 1:
                *seq = 100;
                func_0203D7BC(1);
                break;
            case 2:
                *seq = 200;
                break;
            case 3:
                *seq = 200;
                break;
            case 4:
                *seq = 200;
                break;
            default:
                func_02034714((const char *)d_021807E4, 0, (const char *)d_021807E4);
                break;
            }
        }
        break;
    case 4:
        break;
    case 100:
        colosseum->parentSetting = 1;
        func_0217B8E4(unisys, 0x29);
        return 1;
    case 200:
        func_0217F210(unisys, fieldMap, 0x14c);
        colosseum->parentSetting = 2;
        (*seq)++;
        break;
    case 201:
        if (func_0217F1EC(unisys) == 1) {
            func_0217B8E4(unisys, 0x32);
            func_0217BAF0(unisys, fieldMap, 1);
            return 1;
        }
        break;
    case 300:
        colosseum->parentSetting = 2;
        func_0217B8E4(unisys, 0x32);
        func_0217BAF0(unisys, fieldMap, 1);
        return 1;
    }
    return 0;
}






void func_0217DC64(UnionRoomWork *unisys, const void *myStatus, const u8 *mac)
{
    int gender = func_02008554(myStatus);
    int trainerView = func_02008550(myStatus);
    func_0217357C(&unisys->mySituation.connect, mac, gender, (u8)trainerView);
}






void func_0217DC94(UnionRoomWork *unisys, const void *myStatus, const u8 *mac)
{
    func_02173614(&unisys->mySituation.connect, mac);
}






int func_0217DCA8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    int myIndex;
    int playerCount;
    int playerIndex;
    int gender;
    void *commState;

    myIndex = func_0203D1A4(func_020399A8());
    if (colosseum == 0)
        func_02034714((const char *)d_021807E4, (int)0, (const char *)d_021807E4);

    if (func_0217BB20(unisys) == 1) {
        func_0217F074(unisys);
        return 1;
    }

    switch (*seq) {
    case 0:
        func_02039C68(func_020399A8(), 0xd, 0x14);
        (*seq)++;
        break;
    case 1:
        if (func_02039CB4(func_020399A8(), 0xd, 0x14) == 1)
            (*seq)++;
        break;
    case 2:
        func_02174B40(unisys);
        func_02039C68(func_020399A8(), 0xe, 0x14);
        (*seq)++;
        break;
    case 3:
        if (func_02039CB4(func_020399A8(), 0xe, 0x14) == 1)
            (*seq)++;
        break;
    case 4:
        if (func_02174BB8(&colosseum->player[myIndex], 0) == 1)
            (*seq)++;
        break;
    case 5:
        if (func_0217FDC8(colosseum) == 1) {
            playerCount = func_0203D1B4();
            for (playerIndex = 0; playerIndex < playerCount; playerIndex++) {
                if (colosseum->player[playerIndex].isEntered == 1) {
                    gender = func_02008554(&colosseum->player[playerIndex]);
                    func_0217357C(&situation->connect, colosseum->player[playerIndex].statusExtra, gender,
                                  (u8)func_02008550(&colosseum->player[playerIndex]));
                }
            }
            (*seq)++;
        }
        break;
    case 6:
        func_02039C68(func_020399A8(), 0xf, 0x14);
        (*seq)++;
        break;
    case 7:
        if (func_02039CB4(func_020399A8(), 0xf, 0x14) == 1)
            (*seq)++;
        break;
    case 8:
        if (func_02174C34(colosseum->trainerCard[myIndex]) == 1)
            (*seq)++;
        break;
    case 9:
        if (func_0217FDF8(colosseum) == 1)
            (*seq)++;
        break;
    case 10:
        commState = func_0200ED48(func_02012EBC(func_020120F4(unisys->parent->gameSystem)));
        playerCount = func_0203D1B4();
        for (playerIndex = 0; playerIndex < playerCount; playerIndex++) {
            if (colosseum->player[playerIndex].isEntered == 1 && playerIndex != func_0203D1A4(func_020399A8()))
                func_0200ED54(commState, func_02008530(&colosseum->player[playerIndex]));
        }
        func_02175094(colosseum, 1);
        func_0217B8E4(unisys, 0x2a);
        return 1;
    }
    return 0;
}





int func_0217DE88(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap)
{
    func_0217F074(unisys);
    func_0217BAF0(unisys, fieldMap, 0);
    return 1;
}






int func_0217DEA0(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    void *fieldCtrl;
    int talkPlayer;
    unsigned sideFlags;
    int found;
    s16 position[3];

    fieldCtrl = func_02188CB4((void *)fieldMap);
    if (func_0217BB20(unisys) == 1) {
        func_0217F074(unisys);
        return 1;
    }

    if (*seq == 0) {
        if (func_0217FE44(fieldMap, func_0217F060(situation->connect.partnerSelectA), &sideFlags) == 1) {
            func_021750B0(colosseum, sideFlags);
            func_0217B8E4(unisys, 0x2b);
            func_0217BAF0(unisys, fieldMap, 1);
            return 1;
        }
        if (func_0217FEF4(colosseum) == 1) {
            func_0217B8E4(unisys, 0x32);
            func_0217BAF0(unisys, fieldMap, 1);
            return 1;
        }
        if (func_0217FF14((void *)fieldMap) == 1) {
            func_0217B8E4(unisys, 0x31);
            func_0217BAF0(unisys, fieldMap, 1);
            return 1;
        }
        if (func_020362DC() & 1) {
            found = 0;
            func_021A3460((u32)fieldCtrl, (u32)(&position[2]), (u32)(&position[1]), (u32)(&position[0]));
            if (func_021679A4((void *)(colosseum->commPlayer), position[2], position[1], position[0], (int)(&talkPlayer), (int)(&found)) == 1) {
                colosseum->talkPlayer = talkPlayer;
                func_0217B8E4(unisys, 0x33);
                func_0217BAF0(unisys, fieldMap, 1);
                return 1;
            }
        }
    }
    return 0;
}






int func_0217DFB4(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    void *transition;
    unsigned sideFlags;
    int answer;

    if (func_0217BB20(unisys) == 1) {
        func_0217F074(unisys);
        return 1;
    }

    switch (*seq) {
    case 0:
        (*seq)++;
        break;
    case 1:
        if (func_02174CE4(colosseum) == 1)
            (*seq)++;
        break;
    case 2:
        if (func_0217F1EC(unisys) != 0) {
            answer = func_021750D0(colosseum);
            if (answer == 1) {
                (*seq)++;
            } else if (answer == 0) {
                func_0217B8E4(unisys, 0x2c);
                return 1;
            }
        }
        break;
    case 3:
        transition = func_021A3074(func_02188CB4((void *)fieldMap));
        if (func_0216D3CC((int)transition) == 1) {
            func_0217FE44(fieldMap, func_0217F060(situation->connect.partnerSelectA), &sideFlags);
            func_0216D410(transition, (sideFlags & 1) ? 2 : 3);
            (*seq)++;
        }
        break;
    case 4:
        transition = func_021A3074(func_02188CB4((void *)fieldMap));
        if (func_0216D454(transition) == 1) {
            func_0216D480(transition);
            func_0217B8E4(unisys, 0x2d);
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217E0A4(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    void *transition;
    unsigned sideFlags;

    transition = func_021A3074(func_02188CB4((void *)fieldMap));
    if (func_0217BB20(unisys) == 1) {
        func_0217F074(unisys);
        return 1;
    }

    switch (*seq) {
    case 0:
        func_021750B0(colosseum, 0xff);
        (*seq)++;
        break;
    case 1:
        if (func_02174CE4(colosseum) == 1)
            (*seq)++;
        break;
    case 2:
        if (func_021750D0(colosseum) != 0xff)
            (*seq)++;
        break;
    case 3:
        func_0217F074(unisys);
        (*seq)++;
        break;
    case 4:
        if (func_0216D3CC((int)transition) == 1) {
            func_0217FE44(fieldMap, func_0217F060(situation->connect.partnerSelectA), &sideFlags);
            func_0216D410(transition, (sideFlags & 1) ? 0xb : 0xa);
            (*seq)++;
        }
        break;
    case 5:
        if (func_0216D454(transition) == 1) {
            func_0216D480(transition);
            func_0217B8E4(unisys, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217E188(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum = unisys->colosseum;
    int partyFailMask;
    int teamFailMask;
    int selectedIndex;
    int failMask;
    int modeFlag;
    int teamFlag;
    int menuResult;

    if (func_0217F1EC(unisys) == 0)
        return 0;

    switch (*seq) {
    case 0:
        situation->subState = 0;
        (*seq)++;
    case 1:
        if (func_0200BBA8(func_0200BAC8(func_02012EBC(unisys->parent->gameData))) == 1) {
            (*seq)++;
        } else {
            colosseum->partySource = 0;
            situation->subState++;
            *seq = 4;
        }
        break;
    case 2:
        func_0217F074(unisys);
        func_0217BA48(unisys, (unsigned int *)(&partyFailMask));
        func_0217BA6C(unisys, (unsigned int *)(&teamFailMask));
        modeFlag = partyFailMask != 0;
        teamFlag = teamFailMask != 0;
        unisys->partySelectParam = func_0217B9CC(unisys);
        unisys->partySelect = func_021CC720((u32)fieldMap, (u32)func_02012934(unisys->parent->gameData), (u32)unisys->partySelectParam, modeFlag, teamFlag, 0x15);
        (*seq)++;
        break;
    case 3:
        if (func_021CC810(unisys->partySelect) == 1) {
            menuResult = func_021CC7B4(unisys->partySelect, (u32 *)(&selectedIndex));
            unisys->partySelect = 0;
            if (menuResult == 2) {
                func_0217B9F4(unisys->partySelectParam);
                unisys->partySelectParam = 0;
                func_0217B8E4(unisys, 0x2c);
                return 1;
            }
            switch (menuResult) {
            case 0:
                colosseum->partySource = 0;
                break;
            case 1:
                colosseum->partySource = 1;
                break;
            }
            func_0217B9F4(unisys->partySelectParam);
            unisys->partySelectParam = 0;
            (*seq)++;
        }
        break;
    case 4:
        failMask = 0;
        if (colosseum->partySource == 0) {
            func_0217BA48(unisys, (unsigned int *)(&failMask));
            modeFlag = 1;
        } else {
            func_0217BA6C(unisys, (unsigned int *)(&failMask));
            modeFlag = 2;
        }
        if (failMask != 0) {
            func_0217F098(unisys, fieldMap);
            func_0217F640(unisys, (u32)fieldMap, failMask, func_0217B974(situation->status), modeFlag);
            *seq = 5;
        } else {
            func_0217B8E4(unisys, 0x2e);
            return 1;
        }
        break;
    case 5:
        if (func_0217F794(unisys, (u32)fieldMap) == 1) {
            func_0217F210(unisys, (u8 *)fieldMap, 0x115);
            (*seq)++;
        }
        break;
    case 6:
        if (func_020362DC() & 3) {
            func_0217F7B8(unisys);
            if (situation->subState == 0) {
                *seq = 0;
            } else {
                func_0217B8E4(unisys, 0x2c);
                return 1;
            }
        }
        break;
    }
    return 0;
}






int func_0217E378(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum;

    colosseum = unisys->colosseum;
    if (func_0217BB20(unisys) == 1) {
        func_0217F074(unisys);
        return 1;
    }
    if (colosseum->allReady == 1) {
        func_0217B8E4(unisys, 0x2f);
        colosseum->allReady = 0;
        colosseum->readySent = 0;
        return 1;
    }
    switch (*seq) {
    case 0:
        func_0217F210(unisys, fieldMap, 0x116);
        (*seq)++;
        break;
    case 1:
        if (func_02174E20() == 1) {
            colosseum->readySent = 1;
            (*seq)++;
        }
        break;
    case 2:
        if (func_0217F1EC(unisys) == 1 && (func_020362DC() & 2))
            *seq = 100;
        break;
    case 100:
        if (func_02174E64() == 1)
            (*seq)++;
        break;
    case 101:
        if (colosseum->readySent == 0) {
            func_0217B8E4(unisys, 0x2c);
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217E440(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum;
    int myIndex;
    void *party;

    colosseum = unisys->colosseum;
    myIndex = func_0203D1A4(func_020399A8());
    if (func_0217BB20(unisys) == 1) {
        func_0217F074(unisys);
        return 1;
    }
    switch (*seq) {
    case 0:
        switch (colosseum->partySource) {
        case 0:
        default:
            func_0201AC2C(func_02012934(unisys->parent->gameData), (colosseum->party[myIndex]));
            break;
        case 1:
            party = func_0217B9CC(unisys);
            func_0201AC2C(party, (colosseum->party[myIndex]));
            func_0217B9F4(party);
            break;
        }
        func_0201A2A8((void *)(unisys->regulation), (void *)(colosseum->party[myIndex]));
        (*seq)++;
        break;
    case 1:
        func_02175240(colosseum, 1);
        func_0217FE38(colosseum);
        func_02175208(colosseum);
        func_02039C68(func_020399A8(), 0x14, 0x14);
        (*seq)++;
        break;
    case 2:
        if (func_02039CB4(func_020399A8(), 0x14, 0x14) == 1)
            (*seq)++;
        break;
    case 3:
        if (func_02174D98(colosseum->party[myIndex]) == 1)
            (*seq)++;
        break;
    case 4:
        if (func_02175214(colosseum) == 1)
            (*seq)++;
        break;
    case 5:
        func_02039C68(func_020399A8(), 0x10, 0x14);
        (*seq)++;
        break;
    case 6:
        if (func_02039CB4(func_020399A8(), 0x10, 0x14) == 1)
            (*seq)++;
        break;
    case 7:
        if (func_0203D378() == 1) {
            if (func_02174DF0((u32)colosseum->choice) == 1)
                (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 8:
        if (func_0217FE24(colosseum) == 1) {
            func_0217B8E4(unisys, 0x30);
            return 1;
        }
        break;
    }
    return 0;
}






int func_0217E5A0(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum;
    int myIndex;
    int messageId;
    UnionBattleParam *battle;
    int playerIndex;
    int opponentCount;
    int opponentSlot;

    colosseum = unisys->colosseum;
    myIndex = func_0203D1A4(func_020399A8());
    if (*seq < 3 && func_0217BB20(unisys) == 1) {
        func_0217F074(unisys);
        return 1;
    }
    switch (*seq) {
    case 0:
        if (func_0217F1EC(unisys) != 1)
            break;
        switch (situation->connect.partnerSelectA) {
        default:
            messageId = 0x117;
            break;
        case 6:
        case 7:
        case 22:
        case 23:
            messageId = 0x118;
            break;
        case 20:
        case 21:
            messageId = 0x11b;
            break;
        case 10:
        case 11:
        case 18:
        case 19:
            messageId = 0x119;
            break;
        case 14:
        case 15:
            messageId = 0x11a;
            break;
        }
        func_0217F210(unisys, fieldMap, messageId);
        (*seq)++;
        break;
    case 1:
        if (func_0217F1EC(unisys) == 1) {
            func_02039C68(func_020399A8(), 0x11, 0x14);
            (*seq)++;
        }
        break;
    case 2:
        if (func_02039CB4(func_020399A8(), 0x11, 0x14) == 1) {
            func_0217F074(unisys);
            (*seq)++;
        }
        break;
    case 3:
        battle = func_02030734(0x41, 0xc4, 1, (const char *)d_021807E8, 0x10c4);
        battle->party = colosseum->party[myIndex];
        battle->myStatus = func_0201292C(unisys->parent->gameData);
        battle->config = func_0200873C(func_02012EBC(unisys->parent->gameData));
        battle->commMode = 0x1a;
        battle->regulation = unisys->regulation;
        battle->recordBuffer = func_02030734(0x41, 0x70, 1, (const char *)d_021807E8, 0x10ce);
        opponentCount = 0;
        for (playerIndex = 0; playerIndex < func_0203D1B4(); playerIndex++) {
            if (playerIndex == myIndex)
                continue;
            if ((colosseum->battlePosition[myIndex] & 1) == (colosseum->battlePosition[playerIndex] & 1))
                opponentSlot = 0;
            else
                opponentSlot = ++opponentCount;
            battle->opponent[opponentSlot].party = colosseum->party[playerIndex];
            battle->opponent[opponentSlot].myStatus = func_020084F4(&colosseum->player[playerIndex]);
            battle->opponent[opponentSlot].trainerView = func_02008550(&colosseum->player[playerIndex]);
        }
        switch (situation->connect.partnerSelectA) {
        case 20:
        case 21:
        case 22:
        case 23:
            battle->rule = 2;
            break;
        default:
            battle->rule = 1;
            break;
        }
        battle->isComm = 1;
        battle->recordMode = 0;
        battle->result = 0;
        unisys->sceneParam = battle;
        func_0217422C(unisys, 0x1a, (int)battle);
        (*seq)++;
        break;
    case 4:
        if (func_02174268(unisys) == 1)
            break;
        func_020307B0(((UnionBattleParam *)unisys->sceneParam)->recordBuffer);
        func_020307B0(((UnionBattleParam *)unisys->sceneParam));
        unisys->sceneParam = 0;
        func_0217B8E4(unisys, 0x2c);
        return 1;
    }
    return 0;
}






int func_0217E838(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    void *transition;
    int confirmed;

    transition = func_021A3074(func_02188CB4(fieldMap));
    if (func_0217BB20(unisys) == 1) {
        func_0217F074(unisys);
        return 1;
    }
    switch (*seq) {
    case 0:
        func_0217F210(unisys, (u8 *)fieldMap, 0x14e);
        (*seq)++;
        break;
    case 1:
        if (func_0217F1EC(unisys) != 0) {
            func_0217F22C(unisys, (u32)fieldMap);
            (*seq)++;
        }
        break;
    case 2:
        if (func_0217F268(unisys, (u32 *)(&confirmed)) == 1) {
            func_0217F24C(unisys);
            if (confirmed == 0) {
                *seq = 3;
            } else {
                func_0217B8E4(unisys, 0x32);
                return 1;
            }
        }
        break;
    case 3:
        if (func_0216D3CC((int)transition) == 1) {
            func_0216D410(transition, 8);
            (*seq)++;
        }
        break;
    case 4:
        if (func_0216D454(transition) == 1) {
            func_0216D480(transition);
            func_0217B8E4(unisys, 0x2a);
            return 1;
        }
        break;
    }
    return 0;
}





int func_0217E904(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum;
    int entryBits;
    int aid;

    colosseum = unisys->colosseum;
    if (*seq < 7 && func_0200FB24() != 0 && func_0217F1EC(unisys) == 1) {
        func_0217BAF0(unisys, fieldMap, 1);
        *seq = 7;
    }
    switch (*seq) {
    case 0:
        func_0217BAF0(unisys, fieldMap, 1);
        if (colosseum->parentSetting == 2) {
            if (func_0217F1EC(unisys) == 1)
                *seq = 6;
        } else {
            func_0217F210(unisys, fieldMap, 0x14c);
            (*seq)++;
        }
        break;
    case 1:
        if (func_02174F34() == 1)
            (*seq)++;
        break;
    case 2:
        if (func_0217FEB8(colosseum) == 1)
            (*seq)++;
        break;
    case 3:
        if (func_0217F1EC(unisys) == 1)
            (*seq)++;
        break;
    case 4:
        func_02039C68(func_020399A8(), 0x13, 0x14);
        (*seq)++;
        break;
    case 5:
        if (func_02039CB4(func_020399A8(), 0x13, 0x14) == 1) {
            func_0203D7BC(0);
            (*seq)++;
        }
        break;
    case 6:
        if (func_0203D378() == 1) {
            entryBits = colosseum->entryBits;
            if (func_020392B8() <= 1) {
                (*seq)++;
                break;
            }
            for (aid = 0; aid < 5; aid++) {
                if (aid != func_02039338() && ((1 << aid) & entryBits)) {
                    if ((int)func_0203D1C0((u8)aid) == 1)
                        break;
                }
            }
            if (aid == 5)
                (*seq)++;
        } else {
            (*seq)++;
        }
        break;
    case 7:
        if (colosseum->leaveSent == 1 && func_02172D68(unisys) == 1)
            return 0;
        if (func_0200FB24() != 0) {
            func_0217F074(unisys);
            func_02012124((unisys->parent->gameSystem), 1);
            return 0;
        }
        func_02172D38(unisys);
        (*seq)++;
        break;
    case 8:
        if (func_02172D68(unisys) == 0)
            (*seq)++;
        break;
    case 9:
        colosseum->exitRequested = 1;
        func_02173408(unisys);
        func_0217AE20(unisys);
        func_02173524(unisys, &situation->connect);
        func_0217422C(unisys, 0x19, 0);
        (*seq)++;
        break;
    case 10:
        if (func_02174268(unisys) == 0) {
            if (unisys->colosseum != 0) {
                func_0217505C(unisys->colosseum, unisys->parent->gameSystem);
                unisys->colosseum = 0;
            }
            func_02172D50(unisys);
            (*seq)++;
        }
        break;
    case 11:
        if (func_02172D68(unisys) == 0)
            return 1;
        break;
    }
    return 0;
}





int func_0217EAD8(UnionRoomWork *unisys, UnionMySituation *situation, void *fieldMap, u8 *seq)
{
    ColosseumWork *colosseum;
    int partnerStatus;
    int cardRank;
    int messageId;
    void *partnerCard;

    colosseum = unisys->colosseum;
    switch (*seq) {
    case 0:
        func_0217BAF0(unisys, fieldMap, 1);
        partnerStatus = func_0200855C((&colosseum->player[colosseum->talkPlayer]));
        if (partnerStatus == 0x14 || partnerStatus == 0x15) {
            cardRank = ((u8 *)colosseum->trainerCard[colosseum->talkPlayer])[3];
            if (cardRank < 5) {
                messageId = 0x156 + cardRank;
            } else if (cardRank == 5) {
                switch (partnerStatus) {
                case 0x15:
                    messageId = 0x15c;
                    break;
                case 0x14:
                    messageId = 0x15b;
                    break;
                default:
                    messageId = 0x15d;
                    break;
                }
            } else {
                messageId = 0x15d;
            }
        } else {
            messageId = 0x15d;
        }
        func_0217F098(unisys, fieldMap);
        func_0201F02C((struct WordSet *)(unisys->msgWork.wordSet), 0, &colosseum->player[colosseum->talkPlayer]);
        func_0217F188(unisys, messageId);
        (*seq)++;
        break;
    case 1:
        if (func_0217F1EC(unisys) == 1 && (func_020362DC() & 3)) {
            func_0217F074(unisys);
            ((u8 *)colosseum->trainerCard[colosseum->talkPlayer])[4] |= 0x20;
            partnerCard = func_0216F7F4(unisys->parent->gameData, (u8 *)colosseum->trainerCard[colosseum->talkPlayer], 0x41);
            unisys->sceneParam = partnerCard;
            func_0217422C(unisys, 0x1c, (int)partnerCard);
            (*seq)++;
        }
        break;
    case 2:
        if (func_02174268(unisys) == 0) {
            unisys->sceneParam = 0;
            (*seq)++;
        }
        break;
    case 3:
        func_0217B8E4(unisys, 0x2a);
        return 1;
    }
    return 0;
}
