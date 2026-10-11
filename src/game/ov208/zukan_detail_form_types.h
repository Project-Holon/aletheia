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
    unsigned int f0;
    struct Ov208Form *form;
    unsigned char  f8;
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
    unsigned short f8;
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
    unsigned char  f14;
    unsigned char  f15;
    unsigned char  pad16[2];
    unsigned int mask;
    unsigned int se;
    unsigned int st;
    unsigned int obj;
};

struct Ov208Form {
    unsigned int f0;
    unsigned int font;
    unsigned int cam;
    struct Ov208Mdl item[4];
    void *mem;
    void *heap3d;
    unsigned int w124;
    void *arc;
    unsigned int res[2];
    unsigned int j;
    unsigned int k;
    unsigned int obj[2];
    int cur;
    struct Ov208Ent ents[8];
    unsigned char  pad1c8[0x548 - 0x1c8];
    unsigned short count;
    unsigned short f54a;
    unsigned short f54c;
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
    unsigned int w5b4;
    unsigned int w5b8;
    unsigned int w5bc;
    unsigned int rs[9];
    unsigned int act[4];
    struct Ov208Row row[4];
    unsigned int w694;
    unsigned int w698;
    unsigned int w69c;
    unsigned int w6a0;
    unsigned int w6a4;
    unsigned int w6a8;
    unsigned int w6ac;
    unsigned int w6b0;
    unsigned int w6b4;
    unsigned int state;
    unsigned int w6bc;
    int w6c0;
    unsigned int w6c4;
    unsigned int w6c8;
    unsigned int w6cc;
    unsigned int w6d0;
    unsigned int w6d4;
    unsigned int w6d8;
    unsigned int w6dc;
    unsigned int w6e0;
};

#endif
