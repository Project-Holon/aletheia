#ifndef BATTLE_CHAMPIONSHIP_FLOW_SHARED_TYPES_H
#define BATTLE_CHAMPIONSHIP_FLOW_SHARED_TYPES_H

struct GfFont;

struct MsgBank;

struct Rec;

struct Big;

struct Rec160;

typedef unsigned int   u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef struct {void (*fn)(void *,int *,int);int a;int b;} CB;

typedef signed int     s32;

typedef unsigned int   u32_0217B014;

typedef unsigned int   u32_0217B2E4;

typedef unsigned int u32_0217B344;

typedef struct {
    u32 f00,f04,f08,option0,option1,f14,f18,count;
    u16 f20,f22,f24,f26;
    u32 f28;
    u16 f2c,f2e;
} Menu_0217AE20;

typedef unsigned u32_0217B984;

typedef struct {u32_0217B984 w[10];} Init_0217B970;

#endif
