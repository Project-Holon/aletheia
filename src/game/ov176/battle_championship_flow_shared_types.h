#ifndef BATTLE_CHAMPIONSHIP_FLOW_SHARED_TYPES_H
#define BATTLE_CHAMPIONSHIP_FLOW_SHARED_TYPES_H

struct GfFont;

struct MsgBank;

struct Rec;

struct Big;

typedef unsigned int   u32;

typedef unsigned char  u8;

typedef signed char    s8;

typedef unsigned short u16;

typedef signed int     s32;

/* Partial view of the arm9 regulation card (0x160 bytes); only the BGM byte
 * at 0x15B is read here. The arm9 owner is src/game/arm9/regulation.c. */
struct RegulationCard {
    u8 pad_0[0x15B];
    s8 bgm;
};

/* Callback descriptor used by the ov177 flow helpers. */
typedef struct {void (*fn)(void *,int *,int);int a;int b;} FlowCallback;

/* Menu descriptor handed to func_021E88B0 (ov177 names this type Desc). */
typedef struct {
    u32 x0,x1,x2;
    u32 items[4];
    u32 count;
    u16 a,b,c,d;
    u32 enabled;
    u16 kind,pad;
} Desc;

/* 40-byte init block copied into the live battle match object. */
typedef struct { u32 words[10]; } LiveBattleMatchInit;

#endif
