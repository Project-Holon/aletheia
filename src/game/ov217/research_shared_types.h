#ifndef RESEARCH_SHARED_TYPES_H
#define RESEARCH_SHARED_TYPES_H

#include "research_types.h"

/* Forward declarations shared across the research overlay files. */
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
struct Big;
struct Vec2;
struct S02021D50;
struct Bmp;
struct Sys;
struct Grid;
struct PalAnmSlot;
struct Node;
struct PalAnmObj;
struct U16Vec;
struct Cfg;

/* Message record used by MSGDATA_Delete. */
typedef struct {
    u32 w[5];
    u32 a;
} Rec;

struct Vec2 { signed short x,y; };
typedef struct PalAnmObj PalAnmObj;
struct Arg { s16 x,y,z; u8 a,b; };

#endif
