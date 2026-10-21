/*
 * Shared object layouts of the Pokedex detail screen (ov208), used by the
 * zukan_detail_graphic parts. Offsets are checked against every view.
 */
#ifndef ZUKAN_DETAIL_TYPES_H
#define ZUKAN_DETAIL_TYPES_H

struct Ov208ActDesc {
    int key;
    short x;
    short y;
    unsigned short hitWidth;
    unsigned short charRes;
    unsigned short palRes;
    unsigned short cellRes;
    unsigned short idleAnim;
    unsigned short disabledAnim;
    unsigned short pressedAnim;
    unsigned short pad16;
    unsigned int keyMask;
    unsigned int seId;
};

struct Ov208ActList {
    struct Ov208ActDesc *descs;
    unsigned int count;
    unsigned int owner;
    unsigned int channel;
    unsigned int pal;
    unsigned int objPal;
    unsigned int kind;
    unsigned int skip;
};

struct Ov208ActSrc {
    int id;
    unsigned short x;
    unsigned short y;
    unsigned short hitWidth;
    unsigned short pad;
    unsigned int pressedId;
    unsigned int heldId;
};

struct Ov208Bg {
    unsigned int palette;
    unsigned int character;
    unsigned int cellAnim;
    unsigned int channel;
    unsigned int charRange;
};

/* One 0x38-byte entry of the manager's table. */
struct Ov208Rec {
    unsigned int actor;
    unsigned int enabled;
    unsigned int animSeq;
    void (*onPress)(void);
    unsigned int pressKind;
    struct Ov208ActDesc desc;
    unsigned int forcePress;
};

struct Ov208Mgr {
    int pressedIndex;
    unsigned int count;
    int phase;
    int touchEnabled;
    int latched;
    struct Ov208Bg bg;
    struct Ov208Rec recs[1];
};

struct Ov208Slot {
    struct Ov208ActSrc *src;
    unsigned int obj;
};

struct Unit;
struct Node;

/*
 * Work object of the touch bar, 0x11c bytes, built by
 * ZUKAN_DETAIL_TOUCHBAR_Create. state is the slide state (0 hidden, 1 sliding
 * in, 2 shown, 3 sliding out), mode selects the button set (0 bar, 1 left
 * arrow, 2 right arrow), prevMode/prevKind/kind/arrowKind track the last two
 * palette selections, scrollIdx indexes the slide tables and slotsEnabled arms
 * the buttons. clactUnit/task are the CLACT unit and the vblank task, mgr the
 * button manager. palResN/charResN/cellResN are the CLACT resources of the
 * three button sets. slots/count hold the button actors, palA/palB/palOut the
 * cross-faded palette and phase its angle.
 */
struct Ov208Scene {
    unsigned short heap;
    unsigned short pad2;
    unsigned int dexFlags;
    int state;
    int prevMode;
    int mode;
    unsigned int prevKind;
    unsigned int kind;
    unsigned int arrowKind;
    int scrollIdx;
    unsigned char step;
    unsigned char pad25[3];
    struct Unit *clactUnit;
    struct Node *task;
    struct Ov208Mgr *mgr;
    unsigned int slotsEnabled;
    unsigned char bgPriority;
    unsigned char pad39[3];
    unsigned int bgDirty;
    unsigned int buttonFlag;
    unsigned int palRes0;
    unsigned int charRes0;
    unsigned int cellRes0;
    unsigned int palRes1;
    unsigned int charRes1;
    unsigned int cellRes1;
    unsigned int palRes2;
    unsigned int charRes2;
    unsigned int cellRes2;
    unsigned char count;
    unsigned char pad69[3];
    struct Ov208Slot slots[9];
    short pos;
    unsigned short palA[16];
    unsigned short palB[16];
    unsigned short palOut[16];
    short pad116;
    int phase;
};

#endif
