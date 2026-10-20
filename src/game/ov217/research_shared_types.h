#ifndef RESEARCH_SHARED_TYPES_H
#define RESEARCH_SHARED_TYPES_H

#include "../types.h"

/* Forward declarations shared across the research overlay files. */
struct Ctx;
struct BigObj;
struct IcaAnime;
#include "../arm9/bg_sys_types.h"

struct ArcFile;
struct Ring;
struct Obj;
struct Actor;
struct GfFont;
struct MsgBank;
struct ResearchRec;
struct Config;
struct Record;
struct Bank;
struct Big;
struct ResearchVec2;
struct PaletteFade;
struct Bmp;
struct Sys;
struct Grid;
struct PaletteFade;
struct Node;
struct PaletteFade;
struct U16Vec;
struct Cfg;

/* Message record used by MSGDATA_Delete. */
typedef struct {
    u32 w[5];
    u32 a;
} ResearchRec;

struct ResearchVec2 { signed short x,y; };
typedef struct PaletteFade PalAnmObj;
struct Arg { s16 x,y,z; u8 a,b; };

#endif
