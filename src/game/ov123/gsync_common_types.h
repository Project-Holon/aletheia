/* Basic types and forward declarations shared by the ov123 Game Sync and Dream World account files. */
#ifndef GSYNC_COMMON_TYPES_H
#define GSYNC_COMMON_TYPES_H

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;

/* Opaque handle of a CLACT sprite actor. */
struct ClActor;

/* Background layer template read by BG_SYS_SetBgTemplate (0x20 bytes). */
struct BgTemplate {
    u32 x;                  /* 0x00 */
    u32 y;                  /* 0x04 */
    u32 bufSize;            /* 0x08 */
    u32 baseTile;           /* 0x0C */
    u8 screenSize;          /* 0x10 */
    u8 colorMode;           /* 0x11 */
    u8 screenBase;          /* 0x12 */
    u8 charBase;            /* 0x13 */
    u32 extPaletteSlot;     /* 0x14 */
    u8 priority;            /* 0x18 */
    u8 areaOver;            /* 0x19 */
    u8 dummy;               /* 0x1A */
    u8 mosaic;              /* 0x1B */
    u32 bgType;             /* 0x1C */
};

typedef struct { u16 value; char *object; void (*callback)(char *); } NotifyCallback;

struct Ctx;
struct TaskMenu;
struct Actor;
struct MsgBank;
struct Cfg;
struct CharBuf;
struct GfFont;
struct U16Vec;
struct Cmd;
struct TaskMenuTmpl;
struct Rec3;
struct Big;
struct Obj0203159C;
struct Bank;
struct R;
struct Tcbl;
struct DispConfig;
struct DispVram;
struct PrintSys;
struct Node;
struct S02031140;
struct S020315D4;
struct TaskMenuState;

/* Temporary until gsync_disp.c is cleaned. */
struct Record { void *h; u16 x,y,a,b,age,c,d,e,f,g; };
struct Obj { u8 pad[0x40f4]; struct Record records[30]; };

#endif
