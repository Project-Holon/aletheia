#ifndef PDC_TYPES_H
#define PDC_TYPES_H
/*
 * ov098 symbol Pokemon item screen (pdc.c, pdc_main.c, pdc_msg.c): types shared by the three files.
 * PdcArgs is built by the caller (PDC_Create), PdcProc is the work of the PROCSYS proc,
 * PdcSys is the screen work, PdcMsg is the message window with its fade blend.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct GameData;
struct PokemonParam;
struct MyStatus;
struct MyItem;
struct Config;
struct PokedexSave;
struct BmpWin;
struct MsgBank;
struct Strbuf;
struct WordSet;
struct GfFont;
struct Tcbl;
struct PdcMenu;
struct PdcSys;
struct Proc;

/* Message window blend states (PdcBlend.state). */
#define PDC_BLEND_HIDDEN 0
#define PDC_BLEND_FADING_IN 1
#define PDC_BLEND_SHOWN 2
#define PDC_BLEND_FADING_OUT 3
#define PDC_BLEND_FADE_OUT_REQUESTED 4

/* Message states (PdcMsg.state). */
#define PDC_MSG_START 0
#define PDC_MSG_WAIT_BLEND 1
#define PDC_MSG_WAIT_STREAM 2
#define PDC_MSG_WAIT_INPUT 3
#define PDC_MSG_WAIT_TIMER 4
#define PDC_MSG_NEXT_PAGE 5
#define PDC_MSG_DONE 6

/* Arguments the caller gives to the screen (0x20 bytes, PDC_Create). */
struct PdcArgs {
    struct GameData *gameData;
    struct PokemonParam *mon;
    void *scene;
    struct MyStatus *myStatus;
    struct MyItem *myItem;
    struct Config *config;
    struct PokedexSave *pokedexSave;
    int result;
};

/* Work of the PROCSYS proc (0xC bytes). */
struct PdcProc {
    struct PdcSys *sys;
    struct PdcArgs *args;
    u16 heapId;
};

/* Alpha blend ramp that fades the message window in and out (0x18 bytes). */
struct PdcBlend {
    struct BmpWin *window;
    int alphaA;
    int alphaB;
    int stepA;
    int stepB;
    u8 state;
    u8 framesLeft;
};

/* Message window and text printing (0x48 bytes, created by PDC_MSG_Create). */
struct PdcMsg {
    void *printStream;
    struct PdcBlend blend;
    struct BmpWin *window;
    struct MsgBank *msgBank;
    struct GfFont *font;
    struct Tcbl *tcbl;
    struct Strbuf *strbuf;
    struct WordSet *wordSet;
    int textSpeed;
    u8 instant;
    u8 state;
    u8 streamEnded;
    u8 pad3B;
    u32 streamState;
    u16 waitFrames;
    u16 waitReload;
    u16 heapId;
    u16 pad46;
};

/* Parameter block of the item list screen of overlay 197 (0x44 bytes, at PdcSys.select). */
struct PdcItemSelect {
    struct MyItem *myItem;
    struct GfFont *font;
    u32 mode;
    u16 heapId;
    u8 pad0E[6];
    u8 cursorPos;
    u8 scrollPos;
    u16 chosenItem;
    u8 pad18;
    u8 done;
    u8 pad1A[2];
    void *workBuf;
    u32 reserved20;
    u8 pad24[8];
    u8 *menuWork;
    u8 pad30[16];
    u32 enabled;
};

typedef int (*PdcStep)(struct PdcSys *sys);

/* Screen work (0x78 bytes, PDC_MAIN_Create). */
struct PdcSys {
    struct PdcArgs *args;
    struct PokemonParam *mon;
    struct GfFont *font;
    struct GfFont *msgFont;
    struct PdcMenu *menu;
    struct PdcMsg *msg;
    struct Tcbl *tcbl;
    struct PdcItemSelect select;
    u32 state;
    int timer;
    PdcStep step;
    u16 heapId;
    u16 pad6E;
    void *workBuf;
    u32 menuWork;
};

#endif
