#ifndef RESEARCH_TOP_SHARED_TYPES_H
#define RESEARCH_TOP_SHARED_TYPES_H

struct Ctx;

struct BigObj;

struct IcaAnime;

struct BgTemplate;

struct DispConfig;

struct ArcFile;

struct Ring;

struct Obj;

struct Actor;

struct GfFont;

struct MsgBank;

struct Rec;

struct Config;

struct Record;

struct Bank;

typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed int     s32;

typedef struct {
    u32 w[5];
    u32 a;
} Rec;

#endif
