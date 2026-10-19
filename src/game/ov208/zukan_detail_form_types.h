/*
 * Object layout of the Pokedex detail form screen (ov208), shared by the
 * zukan_detail_form parts. Offsets are checked against every view.
 */
#ifndef ZUKAN_DETAIL_FORM_TYPES_H
#define ZUKAN_DETAIL_FORM_TYPES_H

typedef signed int fx32;

typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} Vec;

typedef struct {
    float x;
    float y;
    float z;
} VecF;

struct Ov208AnmState {
    unsigned int itemIndex;
    struct Ov208Form *form;
    unsigned char  stopCount;
    unsigned char  pad9[3];
    int active;
};

struct Ov208Mdl {
    unsigned int obj;
    struct Ov208AnmState *state;
    VecF pos[5];
};

struct Ov208Ent {
    unsigned int kind;
    unsigned int mode;
    unsigned short groupKey;
    unsigned char  gender;
    unsigned char  shiny;
    unsigned short form;
    unsigned short pade;
};

struct Ov208Row {
    short x;
    short y;
    unsigned int res[3];
    unsigned char  hit[4];
    unsigned char  idleAnim;
    unsigned char  pressAnim;
    unsigned char  pad16[2];
    unsigned int mask;
    unsigned int se;
    unsigned int st;
    unsigned int obj;
};

struct Ov208Form {
    unsigned int actorUnit;
    unsigned int font;
    unsigned int cam;
    struct Ov208Mdl item[4];
    void *mem;
    void *heap3d;
    unsigned int side0Shown;
    void *arc;
    unsigned int res[2];
    unsigned int iconPalette;
    unsigned int iconCellAnim;
    unsigned int obj[2];
    int cur;
    struct Ov208Ent ents[8];
    unsigned char  pad1c8[0x548 - 0x1c8];
    unsigned short count;
    unsigned short groupCount;
    unsigned short shinyCount;
    unsigned short sel;
    unsigned short sel2;
    unsigned short pad552;
    unsigned int win[5];
    unsigned int active[5];
    unsigned int print[5];
    unsigned int msg;
    unsigned int marc;
    unsigned int msg2;
    unsigned int str[6];
    unsigned int bgCharRange;
    unsigned int mainBgPalette;
    unsigned int subBgPalette;
    unsigned int rs[9];
    unsigned int act[4];
    struct Ov208Row row[4];
    unsigned int pressedArrow;
    unsigned int scrollKeyMoved;
    unsigned int scrollDragging;
    unsigned int effectTask;
    unsigned int blendMain;
    unsigned int blendSub;
    unsigned int paletteAnim;
    unsigned int mode;
    unsigned int keyFlag;
    unsigned int state;
    unsigned int slideMoving;
    int slideProgress;
    unsigned int sideSlideStage;
    unsigned int slideForward;
    unsigned int mainSlideDone;
    unsigned int sideSlideDone;
    unsigned int scrollInputPending;
    unsigned int pressPending;
    unsigned int pressAnimDone;
    unsigned int pressReleased;
};

#endif
