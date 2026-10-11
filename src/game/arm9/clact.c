/*
 * file:     clact.c
 * unit:     yes
 * function: sub_0204A48C, sub_0204A5AC, func_0204A600, func_0204A648, func_0204A698, sub_0204A6C8, func_0204A7A0, func_0204A8D4, func_0204A9D0, func_0204AA94, func_0204AB84, func_0204ABBC, func_0204ABF0, func_0204AC18, func_0204ACEC, sub_0204ADA4, sub_0204ADEC, sub_0204AEC0, sub_0204AF28, func_0204AFD8, func_0204B034, func_0204B084, func_0204B09C, func_0204B0C8, func_0204B0F4, func_0204B100, func_0204B1CC, func_0204B22C, func_0204B248, func_0204B258, func_0204B270, func_0204B294, func_0204B324, func_0204B3B4, func_0204B3DC, func_0204B3F4, func_0204B404, func_0204B454, func_0204B49C, func_0204B4EC, func_0204B528, func_0204B53C, func_0204B550, func_0204B560, sub_0204B570, sub_0204B59C, func_0204B5AC, sub_0204B5C0, func_0204B5D4, func_0204B5E4, func_0204B5F4, func_0204B5FC, func_0204B604, func_0204B658, func_0204B688, func_0204B6E4, func_0204B6F4, func_0204B714, func_0204B728, func_0204B764, func_0204B784, func_0204B7C8, func_0204B7F0, func_0204B7F8, func_0204B800, func_0204B838, func_0204B84C, func_0204B864, func_0204B878, func_0204B898, func_0204B8A0, func_0204B8C4, func_0204B8D4, func_0204B8F4, func_0204B908, func_0204B918, func_0204B92C, func_0204B944, func_0204B954, func_0204B95C, func_0204B974, func_0204B98C, func_0204B9A0, func_0204B9C4, func_0204BA00, func_0204BA10, func_0204BA20, func_0204BA38, func_0204BA7C, func_0204BAEC, func_0204BB04, func_0204BB20, func_0204BB38, func_0204BB54, func_0204BB8C, func_0204BBC8, func_0204BC40, func_0204BC94, func_0204BCD8, func_0204BCF4, func_0204BD18, func_0204BD3C, func_0204BD64, func_0204BD7C, func_0204BD94, func_0204BE28, func_0204BE38, func_0204BE84, func_0204BF28, func_0204BF40, func_0204BFC4, func_0204BFF4, func_0204C024, func_0204C040, func_0204C060, func_0204C214, func_0204C2C8, func_0204C3CC, func_0204C660, func_0204C6E4, func_0204C718, func_0204C788, func_0204C7A4, func_0204C804, func_0204C83C, func_0204C8A4, func_0204C8B8, func_0204C8E4, func_0204C944, func_0204C98C, func_0204CA30, func_0204CA74, func_0204CAAC, func_0204CAE4, func_0204CB44, func_0204CBB0, func_0204CC6C, func_0204CEB4, func_0204CED8, func_0204CF40, func_0204CF74, func_0204CFA4, func_0204CFDC, sub_0204D048, sub_0204D0C4, sub_0204D104, func_0204D134, func_0204D158, func_0204D18C, func_0204D224, func_0204D2C8, func_0204D2DC, func_0204D300, func_0204D324, func_0204D340, func_0204D360, func_0204D380, sub_0204D3A0, sub_0204D3C4, sub_0204D410, sub_0204D444, sub_0204D478, sub_0204D4B4, sub_0204D4C4, sub_0204D500, func_0204D494, func_0204D4A4, func_0204D510, func_0204D52C, func_0204D53C, func_0204D54C, func_0204D564, func_0204D5CC, func_0204D634, func_0204D69C, func_0204D6D4, func_0204D70C, func_0204D744, func_0204D750, func_0204D75C, func_0204D768, func_0204D7C4, func_0204D7E0, func_0204D8AC, func_0204D9B4, func_0204D9D4, func_0204DA5C, func_0204DACC, func_0204DC64, func_0204DC70, func_0204DCA8, func_0204DD08, func_0204DEE8, func_0204E010, func_0204E01C, func_0204E074, func_0204E0C4, func_0204E0D0
 * address:  0x0204A48C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   g_02146A74     0x02146A74  data
 *   s_clact_c      0x020A7F74  data
 *   sub_02030734   0x02030734  arm
 *   func_02082BCC  0x02082BCC  arm
 *   sub_020307B0   0x020307B0  arm
 *   lbl_02146A74  0x02146A74 data
 *   func_02066998 0x02066998 arm
 *   unk_02146A74   0x02146A74  data
 *   func_020307B0  0x020307B0  arm
 *   g_020A1430     0x020A1430  data
 *   sub_0204DACC   0x0204DACC  arm
 *   sub_02034640  0x02034640  arm
 *   sub_020346B8  0x020346B8  arm
 *   func_020637BC   0x020637BC  arm
 *   func_020637B4   0x020637B4  arm
 *   func_020862F0   0x020862F0  arm
 *   func_0207E780   0x0207E780  arm
 *   func_0207E804   0x0207E804  arm
 *   func_02049250  0x02049250  arm
 *   func_0206380C  0x0206380C  arm
 *   func_02063800  0x02063800  arm
 *   func_0207E51C  0x0207E51C  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0204CAE4  0x0204CAE4  arm
 *   func_0204D048  0x0204D048  arm
 *   func_0204D104  0x0204D104  arm
 *   func_0204CF74  0x0204CF74  arm
 *   func_0204B528  0x0204B528  arm
 *   sub_0204B5AC  0x0204B5AC  arm
 *   sub_0206380C  0x0206380C  arm
 *   sub_0204B95C   0x0204B95C  arm
 *   sub_02062F1C   0x02062F1C  arm
 *   func_0204D410  0x0204D410  arm
 *   func_0204D444  0x0204D444  arm
 *   g_020A7F3C     0x020A7F3C  data
 *   func_02063078  0x02063078  arm
 *   func_0206343C  0x0206343C  arm
 *   func_02063640  0x02063640  arm
 *   func_02065AA8   0x02065AA8  arm
 *   func_02030734   0x02030734  arm
 *   func_02065B64   0x02065B64  arm
 *   func_02065B74  0x02065B74  arm
 *   g_020A1418     0x020A1418  data
 *   g_020A13F4     0x020A13F4  data
 *   g_020A1388     0x020A1388  data
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_02063294  0x02063294  arm
 *   func_02063378  0x02063378  arm
 *   tbl_020A17D8   0x020A17D8  data
 *   tbl_020A17F0   0x020A17F0  data
 *   func_02066934  0x02066934  arm
 *   MI_CpuFill8    0x02082BCC  arm
 *   g_020A138C     0x020A138C  data
 *   DC_FlushRange  0x020862F0  arm
 *   sub_02034714  0x02034714  arm
 *   s_FileName    0x020A7F74  data
 *   func_0204CA74  0x0204CA74  arm
 *   func_0204CAAC  0x0204CAAC  arm
 *   sub_0204B838  0x0204B838  arm
 *   sub_02082BCC  0x02082BCC  arm
 *   sub_02063790  0x02063790  arm
 *   sub_020637D4  0x020637D4  arm
 *   func_02067AB8  0x02067AB8  arm
 *   func_0204B658  0x0204B658  arm
 *   func_02067B78  0x02067B78  arm
 *   func_020663D0  0x020663D0  arm
 *   func_020664CC  0x020664CC  arm
 *   func_02066620  0x02066620  arm
 *   g_020A1B38     0x020A1B38  data
 *   _fflt          0x0209BDBC  arm
 *   _ffix          0x0209C494  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   sub_0204B84C  0x0204B84C  arm
 *   sub_0204B784  0x0204B784  arm
 *   sub_0204C98C  0x0204C98C  arm
 *   gUnk_020A1394  0x020A1394  data
 *   sub_020627D8  0x020627D8  arm
 *   sub_0206428C  0x0206428C  arm
 *   func_02066AE0  0x02066AE0  arm
 *   func_020627D8  0x020627D8  arm
 *   func_020642C8  0x020642C8  arm
 *   func_020648B4  0x020648B4  arm
 *   func_02064754  0x02064754  arm
 *   func_0206469C  0x0206469C  arm
 *   sub_02066B38  0x02066B38  arm
 *   sub_0206434C  0x0206434C  arm
 *   sub_0206469C  0x0206469C  arm
 *   sub_02064364   0x02064364  arm
 *   sub_020649D4   0x020649D4  arm
 *   func_02064384  0x02064384  arm
 *   sub_02064AB4  0x02064AB4  arm
 *   gUnk_020A7F3C  0x020A7F3C  data
 *   sub_020643C4   0x020643C4  arm
 *   sub_02064B68  0x02064B68  arm
 *   g_DispatchTable_0204D510  0x020A7F48  data
 *   func_020643A4  0x020643A4  arm
 *   func_02063000  0x02063000  arm
 *   func_02063018  0x02063018  arm
 *   func_02034558  0x02034558  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_020345DC  0x020345DC  arm
 *   func_020834C0  0x020834C0  arm
 *   sub_02034630  0x02034630  arm
 *   func_02063790    0x02063790  arm
 *   func_02034660    0x02034660  arm
 *   func_020346D8    0x020346D8  arm
 *   func_02063828    0x02063828  arm
 *   func_02063A54    0x02063A54  arm
 *   func_02063C80    0x02063C80  arm
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 *   func_020637D4  0x020637D4  arm
 *   func_02063F4C  0x02063F4C  arm
 *   func_02080C34  0x02080C34  arm
 *   func_02080C74  0x02080C74  arm
 *   func_0208068C  0x0208068C  arm
 *   func_020801F8  0x020801F8  arm
 *   func_0208083C  0x0208083C  arm
 *   func_0204E01C_File 0x020A7F74 data
 *   func_02062820  0x02062820  arm
 *   func_02062670  0x02062670  arm
 *   func_02062A00  0x02062A00  arm
 */

#define CONV(d, v) do { s32 _t = (s16)(v); if (_t > 0) { (d) = (f32)(_t << 12) + 0.5f; } else { (d) = (f32)(_t << 12) - 0.5f; } } while (0)
struct Bank;
struct Caps;
struct OamMgrs;
struct Res;
struct Ovr;
struct Sink;
struct Sentinel;
struct ArcFile;
struct Holder;
struct Actor;
struct Pt16;
struct Obj0204D478;
struct Mtx;
struct Cmd;
struct NNSG2dOamManagerInstance;
struct Box;
struct ClipRect;
struct Obj_0204BE38;
struct Win;
struct OamEntry;
struct ClipRect;
struct ClipMtx;
struct Xfer;
struct Entry;
struct G2dOamState;
struct Obj02066080;
struct Mtx;
struct Xform;
struct AnimBank;
struct AnimSequence;
struct Obj0206469C;
struct CellAnim;
struct MultiCellAnim;
struct Obj02064C10;
struct Rec_0204D768;
struct Struct020345DC;
struct Cell;
struct Item020346D8;
struct Out;
struct TargetStruct;
struct NitroFileHeader;
struct List02063F4C;
struct Out02063F4C;
struct Self02063F4C;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

struct Xform {
    u32 w[5];
};

struct Mtx {
    u32 w[9];
};

struct Handle {
    u32 unk_00;
    u32 unk_04;
};

struct Slot {
    struct Mtx    mtx;
    void         *unk_24;
    u32           unk_28;
    struct Handle unk_2c;
    struct Handle unk_34;
    u32           unk_3c_0  : 1;
    u32           unk_3c_1  : 30;
    u32           unk_3c_31 : 1;
};

struct Record {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
};

struct Slot2 {
    struct Record record;
    u32           unk_14_0  : 31;
    u32           unk_14_31 : 1;
};

struct Entry3 {
    void            *unk_00;
    void            *unk_04;
    void            *unk_08;
    struct AnimBank *unk_0c;
    u32              unk_10;
};

struct Ctl {
    u32 kind;                /* 0x00 */
    void *unk_04;
    struct AnimBank *unk_08;
    u8  anim[0x30];          /* 0x0c */
    u32 unk_3c;
    u8  pad_40[0x24];
    u32 unk_64;
    u8  pad_68[8];
    u32 unk_70;
    struct AnimBank *unk_74;
    void *unk_78;
};

struct ActorInit {
    s16 x;           /* 0x00 */
    s16 y;           /* 0x02 */
    u16 unk_04;
    u8  unk_06;
    u8  unk_07;
    s16 unk_08;
    u8  pad_0a[2];
    u32 unk_0c;
    u32 unk_10;
    u16 unk_14;
    u16 unk_16;
};

struct ReqTail {
    u8  pad_00[0x10];
    u32 unk_10;
    u32 unk_14;
};

struct ActorReq {
    u16               cell;       /* 0x00 */
    u16               anim;       /* 0x02 */
    struct Slot      *cell_rec;   /* 0x04 */
    struct Slot2     *anim_rec;   /* 0x08 */
    void             *unk_0c;
    struct AnimBank  *unk_10;
    u32               unk_14;
    struct AnimBank  *unk_18;
    const struct ReqTail *unk_1c;
};

struct Pt16 {
    u16 x;
    u16 y;
};

struct Pair32 {
    u32 x;
    u32 y;
};

struct Actor {
    struct Actor *next;          /* 0x00 */
    struct Actor *prev;          /* 0x04 */
    struct Bank  *owner;         /* 0x08 */
    struct Pt16   pos;           /* 0x0c */
    struct Pt16   origin;        /* 0x10 */
    struct Pair32 scale;         /* 0x14 */
    struct Mtx    mtx;           /* 0x1c */
    struct Xform  xform;         /* 0x40 */
    u32           unk_54;
    u16           angle;         /* 0x58 */
    u16           unk_5a;
    u16           unk_5c;
    u16           unk_5e;
    u32           unk_60_00 : 8;
    u32           mode      : 4;
    u32           unk_60_12 : 4;
    u32           unk_60_16 : 2;
    u32           unk_60_18 : 2;
    u32           unk_60_20 : 2;
    u32           unk_60_22 : 2;
    u32           unk_60_24 : 1;
    u32           unk_60_25 : 1;
    u32           enabled   : 1;
    u32           unk_60_27 : 4;
    u32           unk_60_31 : 1;
    u32           hidden    : 1;
    u32           unk_64_01 : 31;
    struct Ctl    ctl;           /* 0x68 */
};

struct Bank {
    struct Actor *actors;
    struct Actor *head;
    struct OamState *unk_08;
    u16           count;
    u8            source : 4;
    u8            mode   : 4;
    u8            unk_0f;
    struct Bank  *next;
    struct Bank  *prev;
};

struct Res {
    void          *tiles;       /* 0x00 */
    void          *palettes;    /* 0x04 */
    struct Slot   *cell;        /* 0x08 */
    struct Slot2  *anim;        /* 0x0c */
    struct Entry3 *pattern;     /* 0x10 */
    volatile u16   n_cell;      /* 0x14 */
    volatile u16   n_anim;      /* 0x16 */
    volatile u16   n_pattern;   /* 0x18 */
    u16            n_unk_06;    /* 0x1a */
    u16            n_tiles;     /* 0x1c */
    u16            n_palettes;  /* 0x1e */
};

struct PoolEntry {
    u32 unk_00;
    u8  pad_04[0x0c];
};

struct Rec_0204BE38 {
    u8 pad_00[0x30];
};

struct Pool {
    struct Rec_0204BE38   *recs;    /* 0x00 */
    struct PoolEntry *ents;    /* 0x04 */
    u32           count;   /* 0x08 */
    u32           ready;   /* 0x0c */
};

typedef union {
    u32 attr01;
    struct {
        u32 y : 8;
        u32 rsMode : 2;
        u32 objMode : 2;
        u32 mosaic : 1;
        u32 colorMode : 1;
        u32 shape : 2;
        u32 x : 9;
        u32 rsParam : 5;
        u32 size : 2;
    };
} OamAttr;

struct OamRec;
struct ClipRect;
struct ClipMtx;
typedef void (*OamCullFn)(struct OamRec *rec, struct ClipRect *org, s32 unk_08, s32 unk_0c, struct ClipMtx *mtx);

struct OamRec {                   /* 0x48 */
    s32       x;                  /* 0x00 */
    s32       y;                  /* 0x04 */
    s32       unk_08;
    s32       unk_0c;
    u8        pad_10[4];
    u32       unk_14;
    u8        pad_18[0x10];
    s32       unk_28;
    s32       unk_2c;
    u32       visible;            /* 0x30 */
    s32       unk_34;
    OamAttr   oam;                /* 0x38 */
    u8        pad_3c[4];
    OamCullFn cull;               /* 0x40 */
    u8        pad_44[4];
};

struct OamState {                 /* 0xa0 */
    u8             pad_00[0x30];
    u32            unk_30;
    u8             pad_34[0x4c];
    u32            unk_80;
    u32            unk_84;
    u16            unk_88;
    u8             pad_8a[2];
    u32            unk_8c;
    u32            unk_90;
    u8             pad_94[4];
    struct OamRec *recs;          /* 0x98 */
    u32            count;         /* 0x9c */
};

struct OamMgr {                   /* 0x20 */
    u8  pad_00[0x1c];
    u32 bound;
};

struct OamMgrs {
    struct OamMgr w[2];
};

struct OamInit {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
    u32 unk_08;
    u32 unk_0c;
};

struct Vec2 {
    s16 x;
    s16 y;
};

struct ClipSrc { u16 f00; u16 f02; u16 f04; u16 f06; s16 f08; s16 f0a; s16 f0c; s16 f0e; };

struct ClipMtx { s32 f00; s32 f04; s32 f08; s32 f0c; s32 f10; s32 f14; };

struct ClipRect { s32 x; s32 y; s32 f08; s32 f0c; };

struct Sys {
    struct OamMgrs  mgrs;          /* 0x00 */
    struct OamState oam;           /* 0x40 */
    struct Pool  pool;           /* 0xe0 */
    u16          unk_f0[2];
    u32          unk_f4;
    u32          unk_0f8;
    u32          unk_0fc;
    struct Bank *head;
    struct Res res;
};

struct Cfg {
    s16 unk_00[4];
    u8  unk_08;
    u8  unk_09;
    u8  unk_0a;
    u8  unk_0b;
    u32 unk_0c;
    u16 unk_10;
    u16 unk_12;
    u16 unk_14;
    u16 unk_16;
    u16 unk_18;
    u16 unk_1a;
};

struct Templ { u32 w0, w1, w2, w3, w4; void *w5; };

struct Sub0204A9D0 {
    u8 pad[0x10];
    u32 f10;
    u32 f14;
};

struct Dest {
    u8    pad_00[8];
    u32   unk_08;
    void *unk_0c;
};

struct Anim {
    u8  pad_00[8];
    u32 unk_08;
    u32 unk_0c;
    u32 unk_10;
    u8  pad_14[4];
    u32 unk_18;
};

struct Clact {
    void      (*vt[6])(void);   /* 0x00 */
    struct OamInit  rec[2];         /* 0x18 */
};

typedef struct { u32 w0, w1, w2; } S12;

struct OamEntry {
    u16 attr[4];
};

typedef long long      s64;


struct Entry {
    u32 unk_00;   /* 0x00 */
    u32 unk_04;   /* 0x04 */
    u32 unk_08;   /* 0x08 */
    u32 unk_0c;   /* 0x0c */
};

struct Xfer {
    void *src;
    u32   unk_04;
    u32   size;
    u32   kind;
};

struct AssertStrings {
    char file[8];
    char expr0[4];
};

typedef float          f32;

struct Pt_0204CF74 {
    signed short x;
    signed short y;
};

struct Inner {
    u8    pad_00[8];
    void *unk_08;
};

struct Rec_0204D134 {
    u8 unk_00[1];
};

typedef void (*DispatchFn_0204D4C4)(struct Ctl *o, u32 arg);

typedef void (*Handler)(struct Ctl *c);

typedef struct {
    u16 count;
    u16 pad_02;
    u8 *items;
} ClactTbl;

typedef struct {
    u32 tag;
    u32 pad_04;
    ClactTbl tbl;
} ClactBlk;

typedef struct {
    u8 pad_00[0x10];
    ClactBlk *blk10;
    ClactBlk *blk14;
} ClactInner;

typedef struct {
    u32 pad_00;
    ClactInner *f04;
    ClactInner *f08;
    u8 pad_0c[0x70 - 0x0c];
    ClactInner *f70;
    ClactInner *f74;
} ClactObj;

struct Cmd {
    u16 op;     /* 0x00 */
    u16 arg0;   /* 0x02 */
    u32 arg1;   /* 0x04 */
    u32 arg2;   /* 0x08 */
};

struct Caps {
    u16 cell;      /* 0x00 */
    u16 anim;      /* 0x02 */
    u16 pattern;   /* 0x04 */
    u16 unk_06;    /* 0x06 */
    u16 tiles;     /* 0x08 */
    u16 palettes;  /* 0x0a */
};

struct ResCfg {
    u8  pad_00[0x10];
    u32 unk_10;    /* 0x10 */
    u8  pad_14[4];
    u32 unk_18;    /* 0x18 */
    u8  pad_1c[0x0c];
    u32 unk_28;    /* 0x28 */
    u32 unk_2c;    /* 0x2c */
};

struct CompHeader {
    u32 header;
};

struct Sentinel {
    u32 lo;
    u32 hi;
};

struct Rec_0204D768 {
    u8  pad_00[0x2c];
    struct Sentinel a;      /* 0x2c */
    struct Sentinel b;      /* 0x34 */
    u32 unk_3c_0  : 31;     /* 0x3c */
    u32 unk_3c_31 : 1;
};

struct Sink {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad0C[4];
    u32 f10;
};

struct Ovr {
    u8  pad00[0xc];
    u32 *f0C;
};

typedef volatile u32 vu32;

struct TargetStruct {
    char pad[8];
    u32 dispcnt;
};

struct Rec_0204DCA8 {
    u8  pad_00[0x14];
    u32 unk_14_0  : 31;     /* 0x14 */
    u32 unk_14_31 : 1;
};

struct Ent    { u8 pad_00[0x14]; u32 unk_14; };          /* 0x18 */

struct Surf   { u8 pad_00[8]; u32 unk_08; u32 unk_0c; };

struct Holder { u8 pad_00[0xc]; struct Ent *ents; };

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void  MI_CpuFill8(void *dst, int fill, u32 size);
extern u32 sub_020307B0(void *p);
extern void func_02066998(void);
extern void sub_0204DACC(struct Res *r, u32 idx, struct Sink *s, struct Ovr *ovr, u32 mode);
extern int sub_02034640(struct Sentinel *p);
extern void sub_020346B8(struct Res *owner, struct Sentinel *p);
extern int func_020637BC(const u32 *p, u32 i);
extern int func_020637B4(int *p, int i);
extern void DC_FlushRange(void *a, u32 b);
extern void func_0207E780(void *a, void *b, u32 c);
extern void func_0207E804(void *a, void *b, u32 c);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern int func_0206380C(char *p, int i);
extern int func_02063800(char *p, int i);
extern void func_0207E51C(void *dest, void *src, u32 size);
extern void func_0207E5D0(void *dest, void *src, u32 size);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0204CAE4(struct Actor *o);
extern void func_0204D104(struct Ctl *p);
extern void func_0204CF74(struct Actor *o, u32 id, u16 *out);
extern void func_0204B528(struct Actor *actor, const struct Pt16 *src);
extern void sub_0204B95C(struct Actor *a);
extern void *func_0204D478(struct Obj0204D478 *o, u32 arg);
extern u16 sub_02062F1C(const struct Anim *n);
extern struct Anim *func_0204D410(struct Ctl *c);
extern struct Anim *func_0204D444(struct Ctl *c);
extern void func_02063078(void);
extern unsigned int func_02063138(void *p, int a, int b, int which);
extern void func_0206343C(struct OamMgr *pMan, u32 bound);
extern void func_02063640(struct OamMgr *pMan);
extern void func_02065AA8(struct OamState *o);
extern void func_02065B64(struct OamState *p0, struct OamRec *p1);
extern void func_02065B74(struct OamRec *p);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32  func_02063294(struct OamMgr *win, struct OamEntry *entry, u32 mode);
extern void func_02063378(struct OamMgr *a0, u32 a1);
extern void  func_02066934(struct Rec_0204BE38 *recs, u32 n, void *cb);
extern void sub_02034714(const char *file, u32 line, const char *expr);
extern void *func_0204CA74(struct Actor *head, u32 key);
extern struct Actor *func_0204CAAC(struct Actor *head, u32 key);
extern void MI_CpuFill8(void *dst, int value, u32 len);
extern void func_02063790(u32 *p);
extern void func_020637D4(u32 *p);
extern void func_02066748(int *a0, int a1, int a2);
extern void func_02065BD0(struct OamState *obj);
extern void func_02065C78();
extern void func_02067AB8(struct OamState *p, u32 mode);
extern u32 func_0204B658(const struct Actor *actor, u32 which);
extern void func_02067B78(struct OamState *p, u32 h, u32 v);
extern void func_020663D0(s32 x, s32 y, s32 z);
extern void func_020664CC(s32 x, s32 y, s32 z);
extern void func_02066620(s32 a, s32 b);
extern void func_02065CE4(void *a0);
extern void func_02065D4C(void *p);
extern void func_02066080(struct Obj02066080 *c);
extern void sub_0204B84C(struct Actor *o, u8 value);
extern void sub_0204B784(char *dst, const struct Mtx *src);
extern void sub_0204C98C(void *owner, struct Actor *o);
extern struct AnimSequence *sub_020627D8(struct AnimBank *bank, u32 idx);
extern void sub_0206428C(char *self, int a1, char *c);
extern int func_02066AE0(void);
extern void func_020642C8(char *self, int a1, char *c, int d, int e, int f, int g, int h, int i, int j);
extern int func_020648B4(u32 a, u32 b);
extern void func_02064754(char *o, void *buf, void *set, void *a3, u32 bank, int kind);
extern void sub_0206469C(struct Obj0206469C *o, void *bank);
extern void sub_02066B38(u32 idx);
extern void  sub_0206434C(u8 *r, void *v);
extern void sub_02064364(struct CellAnim *anim, s32 frames);
extern void sub_020649D4(char *self, int a1);
extern void func_02064384(struct CellAnim *anim, u32 i);
extern void sub_02064AB4(char *self, unsigned int i);
extern void sub_020643C4(struct MultiCellAnim *mca, u32 value);
extern void sub_02064B68(u8 *o, void *arg);
extern void func_020643A4(struct CellAnim *anim);
extern void func_02064C10(struct Obj02064C10 *x);
extern void func_02063000(int p0, int p1, int p2, int p3);
extern void func_02063018(struct CellAnim *anim, u32 a, u32 b, u16 tag);
extern struct Bank *func_02034558(u32 heapId, u32 kind, u32 flags, u32 base, u32 b);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_020345DC(struct Struct020345DC *obj);
extern void func_020834C0(const void *src, void *dest);
extern void  sub_02034630(struct Sentinel *p);
extern int func_02034660(u8 *p, u32 a, void **out);
extern u32 func_020346D8(struct Item020346D8 *a, u32 *b);
extern void func_02063828(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063C80(struct Res *r, u32 dst, int mode, struct Out *out);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_02063E54(struct Surf *s, u32 size, int mode,
                         struct Ent *ent);
extern u16 func_02080C34(void);
extern u16 func_02080C74(void);
extern void func_0208068C(void);
extern void func_020801F8(int objExtPltt);
extern void func_0208083C(int sub_objExtPltt);
extern void func_02063F4C(struct Self02063F4C *self, struct List02063F4C *list, u32 base, int sel, struct Out02063F4C *out);
extern int func_02062820(int a, void **out);
extern s32 func_02062670(void *handle, struct AnimBank **slot);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void  func_020461F4(u32 a);
void sub_0204A48C(const struct Cfg *cfg, const struct ResCfg *res_cfg, u32 heapId);
void sub_0204A5AC(void);
void func_0204A600(void);
void func_0204A648(void);
void func_0204A698(void);
s32 sub_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
s32 func_0204A7A0(u32 size, u32 a2, u16 heapId);
void sub_0204A8D4(u32 i);
void func_0204A9D0(int a, struct Sub0204A9D0 *b);
void func_0204AA94(int a, void *b, u32 c, int d, int e);
void func_0204AB84(u32 idx, struct Mtx *dst);
int func_0204ABBC(u32 idx, u32 flag);
s32 sub_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
s32 sub_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
void sub_0204ADA4(u32 i);
void sub_0204ADEC(u32 idx, struct Dest *dest, u32 count, u32 size);
void sub_0204AEC0(u32 idx, struct Record *dest);
int sub_0204AEF4(u32 idx, u32 alternate);
s32 sub_0204AF28(void *owner, u32 first, u32 second, u32 mode);
void sub_0204AFD8(u32 i);
struct OamState *func_0204B034(const struct OamInit *a0, u32 a1, u32 heap);
asm void func_0204B084(void);
void func_0204B09C(struct OamState *o, int idx, struct Vec2 *v);
void sub_0204B0C8(struct OamState *owner, u32 index, struct Vec2 *out);
void func_0204B0F4(struct OamState *a0, int a1);
struct Bank *sub_0204B100(int count, u8 flag, u32 heapId);
u32 sub_0204B1CC(struct Bank *bank);
void sub_0204B22C(struct Bank *bank, u32 mode);
u32 sub_0204B248(struct Bank *bank);
void sub_0204B258(struct Bank *bank, void *p);
void sub_0204B270(struct Bank *bank);
struct Actor *sub_0204B294(struct Bank *owner, u32 i, u32 j, u32 k, const struct ActorInit *position, u16 f, u16 g);
struct Actor *func_0204B324(struct Bank *owner, u32 i, u32 j, u32 k, const struct ActorInit *e, u16 f, u16 g);
void sub_0204B3B4(struct Actor *p);
void sub_0204B3DC(struct Actor *p, u32 v);
u32 sub_0204B3F4(struct Actor *p);
void sub_0204B404(struct Actor *p, const struct Vec2 *delta, u32 which);
void sub_0204B454(struct Actor *actor, struct Vec2 *out, u16 space);
void sub_0204B49C(struct Actor *actor, s16 value, u32 space, u32 axis);
s16 sub_0204B4EC(struct Actor *actor, u32 space, u32 axis);
void sub_0204B528(struct Actor *actor, const struct Pt16 *src);
void sub_0204B53C(const struct Actor *actor, struct Pt16 *out);
void sub_0204B550(struct Actor *actor, signed short value, u32 axis);
s16 sub_0204B560(const struct Actor *actor, u32 axis);
void sub_0204B570(struct Actor *actor, u32 value);
void sub_0204B588(struct Actor *actor, const struct Pt16 *src);
void sub_0204B59C(struct Actor *o, signed short v, u32 sel);
void func_0204B5AC(struct Actor *dst, struct Pair32 *src);
void sub_0204B5C0(const struct Actor *o, struct Pair32 *p);
void sub_0204B5D4(struct Actor *actor, u32 value, u32 which);
u32 sub_0204B5E4(const struct Actor *actor, u32 which);
void sub_0204B5F4(struct Actor *actor, u16 value);
u16 sub_0204B5FC(const struct Actor *actor);
void func_0204B604(struct Actor *actor, u32 which, u32 set);
u32 sub_0204B658(const struct Actor *actor, u32 which);
void sub_0204B688(struct Actor *actor, u32 value);
u32 sub_0204B6E4(const struct Actor *actor);
void sub_0204B6F4(struct Actor *o, u32 v, u32 flag);
u32 sub_0204B714(struct Actor *o);
void sub_0204B728(struct Actor *o, const struct Xform *m);
void func_0204B764(const char *src, struct Xform *dst);
void func_0204B784(char *dst, const struct Mtx *src);
void func_0204B7C8(const char *src, struct Mtx *dst);
u16 func_0204B7F0(struct Actor *p);
u16 func_0204B7F8(struct Actor *p);
void func_0204B800(struct Actor *node, u32 val);
int func_0204B838(struct Actor *a0);
void func_0204B84C(struct Actor *p, unsigned int v);
u32 func_0204B864(struct Actor *a0);
void sub_0204B878(struct Actor *p, u16 value);
u16 sub_0204B898(struct Actor *p);
void sub_0204B8A0(struct Actor *p, u16 v);
void sub_0204B8C4(struct Actor *p, u32 value);
void sub_0204B8D4(struct Actor *p, u32 arg);
u32 sub_0204B8F4(struct Actor *p);
void func_0204B908(int a0, int a1);
u16 sub_0204B918(struct Actor *p);
void sub_0204B92C(struct Actor *p, u32 v);
u32 sub_0204B944(struct Actor *p);
void func_0204B954(struct Actor *a, u32 v);
void func_0204B95C(struct Actor *a);
void func_0204B974(struct Actor *a);
u32 func_0204B98C(struct Actor *a);
void func_0204B9A0(struct Actor *a);
void func_0204B9C4(struct Actor *a, u32 v);
void func_0204BA00(struct Actor *a, const struct Cmd *cmd);
void func_0204BA10(struct Actor *a);
void func_0204BA20(struct Actor *a, u32 v);
void func_0204BA38(struct OamState *a, const s16 *src, u32 mode);
void func_0204BA7C(u32 set, u16 bias, u32 v);
void func_0204BAEC(u32 v);
u32 func_0204BB04(void);
void func_0204BB20(u32 v);
u32 func_0204BB38(void);
void func_0204BB54(void);
void func_0204BB8C(void);
void func_0204BBC8(struct Bank *bank);
void func_0204BC40(struct Bank *bank);
void func_0204BC94(struct OamMgrs *o, u32 base, u32 count, u32 base2, u8 count2);
void func_0204BCD8(struct OamMgrs *o);
void func_0204BCF4(struct OamMgrs *o);
void func_0204BD18(struct OamMgrs *o);
void func_0204BD3C(struct OamMgr *p, int a, int b, int which);
void func_0204BD64(struct OamMgr *s);
void func_0204BD7C(struct OamMgr *s);
void func_0204BD94(struct OamState *obj, const struct OamInit *src, int count, u32 heap);
void func_0204BE28(struct OamState *p);
void func_0204BE38(struct OamState *obj, int on);
void func_0204BE84(struct OamRec *a0, const struct OamInit *a1);
void func_0204BF28(struct OamRec *p, u32 idx);
void func_0204BF40(struct OamMgr *win, struct OamEntry *src, u32 mode, u32 pal, u32 op);
void func_0204BFC4(struct OamEntry *a0, u32 a1);
void func_0204BFF4(struct OamEntry *a0, u32 a1);
void func_0204C024(u32 v);
void func_0204C040(u32 arg);
int func_0204C060(struct ClipSrc *a, struct ClipMtx *m, struct ClipRect *c);
int func_0204C214(struct ClipSrc *a, struct ClipMtx *b, struct ClipRect *c);
void func_0204C2C8(struct OamRec *e, struct ClipRect *p, s32 u2, s32 u3, struct ClipMtx *box);
int func_0204C3CC(s32 dx, s32 dy, s32 x0, s32 x1, s32 y0, s32 y1, const struct ClipMtx *m, const struct ClipRect *c);
void func_0204C660(struct Pool *p, u8 n, u32 heapId);
void func_0204C6E4(struct Pool *p);
void func_0204C718(struct Pool *p, u32 n, u32 heapId);
void func_0204C788(struct Pool *p);
void func_0204C7A4(struct Pool *t);
struct PoolEntry *func_0204C804(struct Pool *p);
u32 func_0204C83C(u32 kind, u32 a, u32 b, u32 c);
void func_0204C8A4(struct Entry *e, u32 sel, u32 a, u32 b, u32 c);
void func_0204C8B8(struct Xfer *x);
struct Actor *sub_0204C8E4(struct Bank *ow);
void func_0204C944(struct Bank *b);
void func_0204C98C(struct Bank *a0, struct Actor *a1);
void func_0204CA30(struct Bank *m, struct Actor *l);
void *sub_0204CA74(struct Actor *head, u32 key);
struct Actor *sub_0204CAAC(struct Actor *head, u32 key);
void sub_0204CAE4(struct Actor *o);
void func_0204CB44(struct Actor *e, struct OamState *arg);
void func_0204CBB0(struct Actor *e, struct OamState *r);
void func_0204CC6C(struct Actor *o);
void sub_0204CEB4(struct Actor *o);
void sub_0204CED8(struct Actor *o, const struct ActorInit *r, u32 space);
void sub_0204CF40(struct Actor *o, const struct ActorReq *r);
void sub_0204CF74(struct Actor *o, u32 id, u16 *out);
void sub_0204CFA4(struct ActorReq *r, u16 a, u16 b, struct Slot *c, struct Slot2 *d, void *e, struct AnimBank *f);
struct Actor *sub_0204CFDC(struct Bank *owner, const struct ActorInit *r, struct ActorReq *c, u32 space, u16 e);
struct Actor *sub_0204D048(struct Bank *owner, const struct ActorInit *r, struct ActorReq *c, u32 space, u16 e);
void sub_0204D0C4(struct Ctl *s, void *c, u32 e);
void sub_0204D104(struct Ctl *p);
s32 sub_0204D134(const struct ActorReq *r);
void sub_0204D158(struct Ctl *o, const struct ActorReq *s);
void func_0204D18C(struct Ctl *p, const struct ActorReq *a);
void func_0204D224(struct Ctl *p, const struct ActorReq *a1, u32 heap);
void func_0204D2C8(void *anim);
void sub_0204D2DC(struct Ctl *o);
void sub_0204D300(struct Ctl *o);
void func_0204D324(struct Ctl *obj, u32 arg);
void sub_0204D340(struct Ctl *o, u32 idx);
void sub_0204D360(struct Ctl *o, u32 idx);
void sub_0204D380(struct Ctl *o, u32 idx);
void sub_0204D3A0(struct Ctl *o, u32 value);
void *sub_0204D3C4(struct Ctl *o, u32 arg);
void sub_0204D3E0(struct Ctl *o, s32 frames);
void sub_0204D3F0(struct Ctl *o, s32 frames);
void sub_0204D400(struct Ctl *o, s32 frames);
struct Anim *sub_0204D410(struct Ctl *o);
void *sub_0204D42C(struct Ctl *o);
void *sub_0204D434(struct Ctl *o);
void *sub_0204D43C(struct Ctl *o);
struct Anim *sub_0204D444(struct Ctl *o);
void *sub_0204D460(struct Ctl *o);
void *sub_0204D468(struct Ctl *o);
void *sub_0204D470(struct Ctl *o);
void *sub_0204D478(struct Ctl *o, u32 arg);
void func_0204D494(u8 *a0, u32 i);
void func_0204D4A4(u8 *a0, u32 i);
void sub_0204D4B4(struct Ctl *o, u32 i);
void sub_0204D4C4(struct Ctl *o, u32 arg);
void sub_0204D4E0(struct Ctl *o, u32 arg);
void sub_0204D4F0(struct Ctl *o, u32 arg);
void sub_0204D500(struct Ctl *o, u32 arg);
void func_0204D510(struct Ctl *c);
void func_0204D52C(void *p);
void func_0204D53C(u8 *a0);
void func_0204D54C(void *p);
void *func_0204D564(ClactObj *o, u32 idx);
void *func_0204D5CC(ClactObj *o, u32 idx);
void *func_0204D634(ClactObj *o, u32 idx);
ClactTbl *func_0204D69C(ClactObj *o);
ClactTbl *func_0204D6D4(ClactObj *o);
ClactTbl *func_0204D70C(ClactObj *o);
u16 func_0204D744(ClactObj *o);
u16 func_0204D750(ClactObj *o);
u16 func_0204D75C(ClactObj *o);
void func_0204D768(struct Ctl *c, const struct Cmd *cmd);
void func_0204D7C4(struct Ctl *c);
void func_0204D7E0(struct Res *res, u32 heapId, const struct ResCfg *cfg, const struct Caps *caps);
void func_0204D8AC(struct Res *res);
u32 func_0204D9B4(u32 a, u32 b);
void *func_0204D9D4(void *owner, u32 which, u32 compressed, u32 heapId);
void *func_0204DA5C(u32 heapId, u32 count);
void func_0204DACC(struct Res *r, u32 idx, struct Sink *s, struct Ovr *ovr, u32 mode);
void func_0204DC64(void *ptr);
void func_0204DC70(struct TargetStruct *obj, int which);
void *func_0204DCA8(u32 heapId, u32 count);
void func_0204DD08(struct Holder *h, int idx, void *src, void *sel, u32 size, u16 head, u16 tail);
void func_0204DEE8(struct Holder *h, int idx, void *src, void *sel, u32 size);
void func_0204E010(void *ptr);
struct Entry3 *func_0204E01C(u32 heap, u32 count);
s32 func_0204E074(struct Res *pool, s32 idx, void *a, void *b);
void func_0204E0C4(void *ptr);
void func_0204E0D0(struct Res *owner, s32 idx, u32 handle, u32 a3, u32 a4);
extern struct Sys *g_02146A74;
extern const char s_clact_c[];
extern const struct Templ g_020A1430;
extern struct Clact g_020A7F3C;
extern S12  g_020A1418[];
extern u32  g_020A13F4[];
extern u16 g_020A1388[];
extern const u16 tbl_020A17D8[4][4];
extern const u16 tbl_020A17F0[4][4];
extern const struct AssertStrings s_FileName;
extern s16 g_020A1B38[];
extern DispatchFn_0204D4C4 const gUnk_020A7F3C[];
extern Handler g_DispatchTable_0204D510[];
extern const char func_0204E01C_File[];



/*
 * Blocked at MATCH: all 288 concrete bytes are correct and seven of the ten
 * relocation sites now resolve.  func_0204BA38 (+0x00C0) was closed by wave
 * 20C (src/matched/func_0204BA38.c).  The other three are each byte-correct
 * in src/pending/ but capped at MATCH by a fan-in-1 extern of their own, so
 * this file needs three `matched` entries that do not exist yet:
 *   func_0204D7E0 (+0x0090) waits on 0x02034558, 0x0204DA5C and 0x0204DCA8
 *   func_0204BC94 (+0x00AC) waits on func_0204BD3C, which waits on 0x02063138
 *   func_0204C660 (+0x00D8) waits on 0x02066934
 * All four of those addresses sit outside clact.c.
 *
 * Bring up the single global cell-actor system behind 0x02146A74, the exact
 * inverse of src/pending/sub_0204A5AC.c: one 0x124-byte allocation, zeroed,
 * then each of the four embedded sub-objects at +0x00, +0x40, +0x0e0 and
 * +0x104 initialised from the caller's config record, the two-entry u16 table
 * at +0xf0 cleared, and the system enabled.  The __FILE__ pointer is the same
 * s_clact_c the rest of clact.c uses.
 *
 * The six halfwords at +0x10..+0x1a of the config are copied into a stack
 * array one field at a time rather than as an aggregate: a twelve-byte struct
 * assignment would be an inlined `ldm`/`stm` pair
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), and the original spells out
 * six `ldrh`/`strh`.
 *
 * The zero that clears the +0xf0 table is the loop counter's own initial
 * value, hoisted out of the loop, and is the same register as the allocator's
 * `clear` argument and the fill byte
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md),
 * so `i` has to be a function-scope local.  The trailing 1 is shared by the
 * last two calls the same way.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204A48C.c \
 *       --func sub_0204A48C --addr 0x0204A48C --cc 1.1p1 --arm
 */
void sub_0204A48C(const struct Cfg *cfg, const struct ResCfg *res_cfg, u32 heapId)
{
    u16 dims[6];
    int i;

    g_02146A74 = sub_02030734(heapId, sizeof(struct Sys), 0, s_clact_c, 0x28f);
    MI_CpuFill8(g_02146A74, 0, sizeof(struct Sys));

    dims[0] = cfg->unk_10;
    dims[1] = cfg->unk_12;
    dims[2] = cfg->unk_14;
    dims[3] = cfg->unk_16;
    dims[4] = cfg->unk_18;
    dims[5] = cfg->unk_1a;

    func_0204D7E0(&g_02146A74->res, heapId, res_cfg, (const struct Caps *)dims);
    func_0204BC94(&g_02146A74->mgrs, cfg->unk_08, cfg->unk_09, cfg->unk_0a,
                  cfg->unk_0b);
    func_0204BA38(&g_02146A74->oam, cfg->unk_00, heapId);
    func_0204C660(&g_02146A74->pool, cfg->unk_0c, heapId);

    for (i = 0; i < 2; i++) {
        g_02146A74->unk_f0[i] = 0;
    }

    func_0204BAEC(1);
    func_0204BB20(1);
}



/*
 * Was blocked at MATCH pending func_0204D8AC (+0x003C), which was itself
 * capped at MATCH behind func_020345DC.  Both are now `matched`
 * (src/matched/func_0204D8AC.c, src/matched/func_020345DC.c), closing the
 * cell-actor system destructor.
 *
 * Tear down the single global cell-actor system behind 0x02146A74.  The block
 * is one allocation with four embedded sub-objects at +0x00, +0x40, +0x0e0 and
 * +0x104, each released by its own finaliser, after which the block is freed
 * and the global cleared.  src/matched/sub_0204B270.c points a bank at
 * +0x40 of the same block, so that sub-object is the shared default.
 *
 * The global is re-read from the pool word before every call because each
 * callee could store to it; that is not a `volatile` (see
 * docs/idioms/a-global-reread-across-a-call-to-a-visible-static-needs-volatile.md,
 * which is about the opposite case), it is just an extern the compiler cannot
 * see through.
 *
 * The zero passed to func_0204BAEC and the null stored back at the end are the
 * same register: the constant is materialised once into r5 and the argument
 * copied off it
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204A5AC.c \
 *       --func sub_0204A5AC --addr 0x0204A5AC --cc 1.1p1 --arm
 */
void sub_0204A5AC(void)
{
    func_0204BAEC(0);
    func_0204BCD8(&g_02146A74->mgrs);
    func_0204BE28(&g_02146A74->oam);
    func_0204C6E4(&g_02146A74->pool);
    func_0204D8AC((struct Res *)((u8 *)g_02146A74 + 0x104));
    sub_020307B0(g_02146A74);
    g_02146A74 = 0;
}



/*
 * note:     re-verified 2026-09-20: MATCH; see verify output
 */
void func_0204A600(void)
{
    struct Sys *p = g_02146A74;

    if (p == 0) {
        return;
    }

    func_0204BAEC(0);
    func_0204BB54();
    func_0204BB8C();

    p = g_02146A74;
    if (p->pool.ready != 0) {
        func_02066998();
    }

    func_0204BAEC(1);
}



/*
 * The cell-actor manager's teardown pass, and the exact inverse of
 * src/pending/sub_0204A600.c: each guard re-reads the context pointer from
 * its slot (the two `popeq` exits are the short-circuit returns, which is why
 * neither guard is predicated), the +0xEC latch decides whether the +0xE0
 * sub-object is released, and the flag goes back to 1.
 *
 * The 0x0204BCF4 call site resolves off the `label` class (its own
 * src/pending/func_0204BCF4.c is capped, but the branch has witnesses outside
 * this range), so this file is EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204A648.c \
 *       --func func_0204A648 --addr 0x0204A648 --cc 1.1p1 --arm
 */
void func_0204A648(void)
{
    if (g_02146A74 == 0)
        return;
    if (func_0204BB04() == 0)
        return;

    func_0204BCF4(&g_02146A74->mgrs);

    if (g_02146A74->pool.ready != 0)
        func_0204C7A4(&g_02146A74->pool);

    func_0204BB20(1);
}



/*
 * Cell-actor latch-only tick: latch off, flush the actor bank list, latch
 * back on.  No render update compared with func_0204A600.
 */
void func_0204A698(void)
{
    if (g_02146A74 == 0) {
        return;
    }
    func_0204BAEC(0);
    func_0204BB54();
    func_0204BAEC(1);
}



/*
 * Claims the first entry of the display-object table (0x40-byte slots at
 * +0x08 of the owner block, 0x104 into the object at 0x02146A74) whose
 * pending bit (bit 31 of +0x3c) is set, loads the object for it through
 * func_0204D9D4, publishes it with func_0204E0D0, frees the handle, then
 * clears +0x24 and bit 0 of +0x3c.  Returns the slot index, or -1 when
 * nothing was waiting.  Sibling of func_0204A7A0.
 *
 * Shape notes (docs/notes/sub_0204A6C8.c.txt has the full history):
 *  - `count` is volatile (reread every iteration), `sys` is kept live for
 *    the slot address, and the not-found exit falls out of the loop past a
 *    goto.
 *  - The body sits inside `if (i != (u32)-1) { ... return i; }` with a
 *    trailing `return -1;`.  The early-return spelling
 *    `if (i == (u32)-1) return -1;` gets every byte right except the order
 *    of `mov r8, r0` (the handle) and `mov r7, #0` (the shared zero) after
 *    the load call (4 out, flat over five waves).  See
 *    docs/idioms/an-inverted-guard-returns-the-compare-constant-register.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204A6C8.c  *       --func sub_0204A6C8 --addr 0x0204A6C8 --cc 1.1p1 --arm
 */
s32 sub_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags)
{
    struct Sys   *sys;
    struct Res *owner;
    struct Slot  *slot;
    u32 i;
    u32 handle;

    sys   = g_02146A74;
    owner = &sys->res;

    for (i = 0; i < owner->n_cell; i++) {
        if (owner->cell[i].unk_3c_31 != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i != (u32)-1) {
        slot   = &sys->res.cell[i];
        handle = (u32)func_0204D9D4(a, b, c, (u16)((flags & 0x7fff) | 0x8000));

        func_0204E0D0(&g_02146A74->res, i, handle, a3, 0);
        sub_020307B0((void *)handle);

        slot->unk_24 = 0;
        slot->unk_3c_0 = 0;
        return i;
    }
    return -1;
}



/*
 * Claims the first busy cell (bit 31 of +0x3c) of the singleton's table at
 * +0x104, like its sibling func_0204A6C8, but builds a fresh character
 * record: the 0x18-byte template at 0x020A1430 is copied to the stack, the
 * DISPCNT OBJ-mapping bits and the size patched in, and the sixth word
 * holds a scratch block from sub_02030734 (clact.c, line 0x3c8) that is
 * registered through sub_0204DACC and freed at the end.  Returns the cell
 * index, or -1 when none is found.
 *
 * Shape notes:
 *  - `struct Slot *slot` is declared before `u32 i` (wave 18): that order
 *    gives the image's whole allocation (size r8, a2 r7, heapId lr, the -1
 *    in sb, i r6, slot r5, &t r4).
 *  - The body sits inside `if (i != (u32)-1) { ... return i; }` with a
 *    trailing `return -1;`.  The image returns the compare's -1 register
 *    (`moveq r0, sb`).  An early `if (i == -1) return i;` returns r6
 *    (1 out); an early `return -1;` recolours the function (47).  With the
 *    guard inverted the -1 is returned from the same register the compare
 *    used and the colouring is kept.  See
 *    docs/idioms/an-inverted-guard-returns-the-compare-constant-register.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204A7A0.c  *       --func func_0204A7A0 --addr 0x0204A7A0 --cc 1.1p1 --arm
 */
s32 func_0204A7A0(u32 size, u32 a2, u16 heapId)
{
    struct Sys   *sys;
    struct Res *owner;
    struct Slot  *slot;
    u32 i;
    struct Templ t;

    sys   = g_02146A74;
    owner = &sys->res;

    for (i = 0; i < owner->n_cell; i++) {
        if (owner->cell[i].unk_3c_31 != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i != (u32)-1) {
        slot = &sys->res.cell[i];
        t = g_020A1430;
        t.w2 = *(volatile u32 *)0x04000000 & 0x00300010;
        t.w4 = size;
        t.w5 = sub_02030734((u16)((heapId & 0x7fff) | 0x8000), size, 1, s_clact_c, 0x3c8);

        sub_0204DACC((struct Res *)(&g_02146A74->res), i, (struct Sink *)(&t), 0, a2);

        slot->unk_3c_31 = 0;
        slot->unk_24 = 0;
        slot->unk_3c_0 = 0;
        sub_020307B0(t.w5);
        return i;
    }
    return -1;
}



/*
 * Retire one slot of the 0x40-byte table at +0x10c of the singleton behind
 * 0x02146A74.  The two eight-byte sub-objects at +0x2c and +0x34 are returned
 * to their owners (+0x104 and +0x108) unless sub_02034640 says they are
 * already detached, the payload at +0x24 is released, and the flag word at
 * +0x3c ends as "top bit set, everything else clear".
 *
 * Nothing is cached: every one of the eleven accesses reloads g_02146A74 and
 * re-indexes, because each intervening store may alias the global pointer
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md read from
 * the other side, the same shape as src/matched/sub_0204ADA4.c).  The payload
 * pointer is the one exception: it is bound to a local, which is why the `bl`
 * to sub_020307B0 needs no load in front of it.
 *
 * +0x3c is a bitfield word, not a mask word.  The evidence is the guard:
 * `lsl #31` / `lsrs #31` to read bit 0, where a plain `x & 1` compiles to
 * `ands` (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 * The other two writes confirm the partition: `bic`+`orr` with 0x80000000 is
 * an assignment to the one-bit field at bit 31, and `and #0x80000001` is an
 * assignment of zero to the thirty-bit field between them.  Field order is
 * LSB first, as in sub_0204ADA4.c.
 *
 * The release is the fall-through and the flag clear is the `else`, so the
 * guard is spelled `== 0` and the short arm is left to be if-converted into
 * `bicne`/`strne` (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204A8D4.c \
 *       --func sub_0204A8D4 --addr 0x0204A8D4 --cc 1.1p1 --arm
 */
void sub_0204A8D4(u32 i)
{
    void *payload;

    if (sub_02034640((struct Sentinel *)(&g_02146A74->res.cell[i].unk_2c)) == 0) {
        sub_020346B8(g_02146A74->res.tiles, (struct Sentinel *)(&g_02146A74->res.cell[i].unk_2c));
    }

    if (sub_02034640((struct Sentinel *)(&g_02146A74->res.cell[i].unk_34)) == 0) {
        sub_020346B8(g_02146A74->res.palettes, (struct Sentinel *)(&g_02146A74->res.cell[i].unk_34));
    }

    payload = g_02146A74->res.cell[i].unk_24;
    if (payload != 0) {
        if (g_02146A74->res.cell[i].unk_3c_0 == 0) {
            sub_020307B0(payload);
        } else {
            g_02146A74->res.cell[i].unk_3c_0 = 0;
        }
        g_02146A74->res.cell[i].unk_24 = 0;
    }

    g_02146A74->res.cell[i].unk_3c_31 = 1;
    g_02146A74->res.cell[i].unk_3c_1 = 0;
}



void func_0204A9D0(int a, struct Sub0204A9D0 *b)
{
    if (func_020637BC((const u32 *)((u32)g_02146A74->res.cell + (a << 6)), 1) != 0) {
        void *p = (void *)func_020637B4((int *)((u32)g_02146A74->res.cell + (a << 6)), 1);
        DC_FlushRange((void *)b->f14, b->f10);
        func_0207E780((void *)b->f14, p, b->f10);
    }
    if (func_020637BC((const u32 *)((u32)g_02146A74->res.cell + (a << 6)), 2) == 0)
        return;
    {
        void *p = (void *)func_020637B4((int *)((u32)g_02146A74->res.cell + (a << 6)), 2);
        DC_FlushRange((void *)b->f14, b->f10);
        func_0207E804((void *)b->f14, p, b->f10);
    }
}



void func_0204AA94(int a, void *b, u32 c, int d, int e)
{
    if (e == 0 || e == 2) {
        if (func_020637BC((const u32 *)((u32)g_02146A74->res.cell + (a << 6)), 1) != 0) {
            void *p = (void *)func_020637B4((int *)((u32)g_02146A74->res.cell + (a << 6)), 1);
            DC_FlushRange(b, c);
            func_0207E780(b, (char *)p + d, c);
        }
    }
    if (e == 1 || e == 2) {
        if (func_020637BC((const u32 *)((u32)g_02146A74->res.cell + (a << 6)), 2) == 0)
            return;
        {
            void *p = (void *)func_020637B4((int *)((u32)g_02146A74->res.cell + (a << 6)), 2);
            DC_FlushRange(b, c);
            func_0207E804(b, (char *)p + d, c);
        }
    }
}



/*
 * Copy the 36-byte header of a 64-byte-stride record out of the actor
 * table hung off the manager's pointer member at +0x10c into the caller's
 * buffer.  The whole copy is one aggregate assignment: two ldm/stm pairs
 * of four registers and a trailing word.
 */
void func_0204AB84(u32 idx, struct Mtx *dst)
{
    struct Mtx *src = (struct Mtx *)((u8 *)g_02146A74->res.cell + idx * 64);

    *dst = *src;
}



/*
 * Snapshot one actor record into a local 36-byte buffer and hand it to
 * func_020637B4 with mode 1, or mode 2 when the second argument is set.
 */
int func_0204ABBC(u32 idx, u32 flag)
{
    struct Mtx buf;
    u32 mode = 1;

    if (flag != 0) {
        mode = 2;
    }
    func_0204AB84(idx, &buf);
    return func_020637B4((int *)(&buf), mode);
}



/*
 * The short-form entry point of sub_0204AC18: same call with the two
 * optional halfword parameters defaulted to zero.
 *
 * All the frame does is rebuild the stack half of the argument list.  The
 * four register arguments pass through untouched, so nothing in the body
 * mentions them; `sub sp, sp, #0xc` is the callee's three stack words, the
 * two zeros go in the first two, and the caller's own single stack argument
 * is copied from +0x10 (four bytes of saved lr plus the twelve just
 * reserved) into the third.  It is read with `ldrh`, which is what fixes
 * that parameter as a halfword rather than a word.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204ABF0.c \
 *       --func sub_0204ABF0 --addr 0x0204ABF0 --cc 1.1p1 --arm
 */
s32 sub_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g)
{
    return sub_0204AC18(a, b, c, d, 0, 0, g);
}



/*
 *           the call inside this function, so `label` has no outside witness
 *           and no manifest entry covers it yet.  File 0x0204DD08 first and
 *           this graduates with no change to its C.
 */
s32 sub_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g)
{
    struct Res *owner;
    u32 i;
    u32 handle;

    owner = &g_02146A74->res;

    for (i = 0; i < owner->n_anim; i++) {
        if (owner->anim[i].unk_14_31 != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i == (u32)-1) {
        return i;
    }

    handle = (u32)func_02049250(a, b, (u16)((g & 0x7fff) | 0x8000));

    func_0204DD08((struct Holder *)(&g_02146A74->res), i, (void *)handle, (void *)c, d, e, f);
    sub_020307B0((void *)handle);

    return i;
}



/*
 * The clact.c record-claim scan: walk the ClRes cell table for a free slot
 * (bit 31 of the element's +0x14 word), load the archive member into it and
 * return the index, or -1.
 *
 * TWO LEVERS, and it is their COMBINATION that closes it.  docs/notes/
 * pkt_0204ACEC.c.txt had each of them separately and measured each as a loss:
 *
 *  1. A named `Inner0204ACEC *in` local for the +0x104 sub-object.  Without it
 *     mwcc 1.1p1 splits the 0x11a count offset as base 0x100 + 0x1a (the ldrh
 *     8-bit immediate reaches 0x1a from 0x100) and reaches `arr` straight off
 *     the global at +0x110 (inside the ldr 12-bit immediate), so the two
 *     fields never share a base.  The image materialises `g + 0x104` once and
 *     reads both through it: `add r7, r2, #0x104` / `ldrh r2, [r7, #0x16]` /
 *     `ldr ip, [r7, #0xc]`.  Nested sub-structs and casts all fold back to the
 *     0x100 base; only a live local pointer emits the 0x104 add.  The note
 *     measured this alone at 109-138 bytes out, because it also hoists the
 *     loop bound and drops the image's back-edge count re-read.
 *  2. `volatile u16 count`, which restores that back-edge re-read
 *     (`ldrh r3, [r7, #0x16]` at +0x40).  The note measured THIS alone at
 *     188 bytes against 184 -- four bytes long -- because with the 0x100 base
 *     the volatile load costs an extra instruction it does not pay for.
 *
 * Together they are exact: the local pointer removes the base split, and the
 * volatile puts back the one load the local pointer's hoist removed.  Each
 * lever alone is a regression; the pair is EXACT.  tools/permuter.py could not
 * move the 17-byte no-local baseline at all (169 single mutations), which is
 * the declarations-not-allocation signature.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0204ACEC.c \
 *       --func func_0204ACEC --addr 0x0204ACEC --cc 1.1p1 --arm
 */
int func_0204ACEC(void *a0, u32 a1, u32 a2, u32 a3, u16 a4)
{
    struct Res *in = &g_02146A74->res;
    u32 i;
    void *v;
    struct Slot2 *arr;

    for (i = 0; i < in->n_anim; i++) {
        arr = (struct Slot2 *)in->anim;
        if (arr[i].unk_14_31 != 0)
            goto found;
    }
    i = -1;
found:
    if (i == (u32)-1)
        return (int)i;
    v = func_02049250(a0, a1, (u16)((a4 & 0x7fff) | 0x8000));
    func_0204DEE8((struct Holder *)(&g_02146A74->res), i, v, (void *)a2, a3);
    sub_020307B0(v);
    return (int)i;
}



/*
 * Reset one entry of the 0x18-byte table hanging off +0x110 of the
 * singleton at 0x02146A74: set the top bit of the word at +0x14 and clear
 * the other 31 bits under it.
 *
 * The two statements do not share one address computation, even though
 * there is no call between them: the `str` of the first statement may
 * alias the global pointer itself, so the compiler has to reload
 * g_02146A74 and re-index before the second
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md, read
 * from the other side).  The index multiply is a real `mul` by a
 * register-held 0x18, not a shift pair, because 24 is not a power of two.
 *
 * `bic` immediately followed by `orr` with the same constant is the
 * bitfield-assignment shape, not a redundant pair: the field is cleared
 * and then the value inserted, and the value happening to be the constant
 * 1 does not collapse the two.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204ADA4.c \
 *       --func sub_0204ADA4 --addr 0x0204ADA4 --cc 1.1p1 --arm
 */
void sub_0204ADA4(u32 i)
{
    g_02146A74->res.anim[i].unk_14_31 = 1;
    g_02146A74->res.anim[i].unk_14_0 = 0;
}



/*
 * Flush both halves of one slot of the 0x18-byte-stride table at +0x110 of
 * the singleton behind 0x02146A74 into the destination the caller supplies.
 * Each half is guarded by func_0206380C, fetched with func_02063800 and
 * written through func_0207E51C (selector 1) or func_0207E5D0 (selector 2),
 * with DC_FlushRange invalidating the destination first.
 *
 * `count` is in 32-byte units; zero means "use the length the destination
 * already records at +8" instead.  The shift happens unconditionally and is
 * overwritten by the predicated `ldreq`, so the guard has to be written as
 * a plain `if` after the shift, not as a ternary around it.
 *
 * `size` has to be spelled as a fourth parameter that the body immediately
 * overwrites, not as a local: as a local it takes r4 and the `idx * 0x18`
 * temporary takes r5, which is the original's assignment exactly swapped
 * and the only difference in the whole function.  The image says the
 * fourth argument is not actually passed: the one call site, the `blx` at
 * 0x0202DAD2, sets r0, r1 and r2 and leaves r3 alone.  So read the fourth
 * parameter as a register-allocation device for this rewrite, not as
 * evidence about the function's real arity.
 */
void sub_0204ADEC(u32 idx, struct Dest *dest, u32 count, u32 size)
{
    size = count << 5;

    if (count == 0) {
        size = dest->unk_08;
    }

    if (func_0206380C((char *)(&g_02146A74->res.anim[idx]), 1) != 0) {
        void *src = (void *)func_02063800((char *)(&g_02146A74->res.anim[idx]), 1);

        DC_FlushRange(dest->unk_0c, size);
        func_0207E51C(dest->unk_0c, src, size);
    }

    if (func_0206380C((char *)(&g_02146A74->res.anim[idx]), 2) != 0) {
        void *src = (void *)func_02063800((char *)(&g_02146A74->res.anim[idx]), 2);

        DC_FlushRange(dest->unk_0c, size);
        func_0207E5D0(dest->unk_0c, src, size);
    }
}



/*
 * A getter and its one caller.  sub_0204AEC0 copies the 0x14-byte record
 * out of slot `idx` of the 0x18-byte-stride table at +0x110 of the
 * singleton behind 0x02146A74; the copy is an inlined `ldm`/`stm` pair plus
 * a trailing word, which is what a whole-struct assignment of this size
 * compiles to (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 * sub_0204AEF4 takes that copy on its own stack and submits it to
 * func_02063800 under selector 1 or 2.
 *
 * Kept as one unit so the `bl` at sub_0204AEF4+0x1c is `local`:
 * sub_0204AEF4 is sub_0204AEC0's only caller image-wide, so split into two
 * files the site would have no witness of any class.
 */
void sub_0204AEC0(u32 idx, struct Record *dest)
{
    *dest = g_02146A74->res.anim[idx].record;
}



int sub_0204AEF4(u32 idx, u32 alternate)
{
    struct Record record;
    u32 selector;

    selector = 1;
    if (alternate != 0) {
        selector = 2;
    }

    sub_0204AEC0(idx, &record);
    return func_02063800((char *)(&record), selector);
}



/*
 * Claim the first live slot of the 0x14-byte entry pool that lives at
 * +0x104 of the singleton behind 0x02146A74, build its two handles through
 * func_02049250 (same owner and same mode for both, second argument
 * differing), publish the pair with func_0204E074 and hand the slot index
 * back.
 *
 * The scan is an inlined helper, which is what puts the "not found" answer
 * on its own block: the `bne` out of the loop is the `return i` and the
 * `mvn sl, #0` it jumps over is the `return -1`.  Note that -1 is not
 * checked before it is used as a subscript, so a pool with no live entry
 * writes one stride below the array; that is the original's behaviour, not
 * a transcription slip.
 *
 * `count` is spelled `volatile` purely as a codegen device, not as a claim
 * about the hardware: without it the compiler proves the entry loads cannot
 * touch the halfword, CSEs the guard's read with the latch's, and the
 * resulting one-instruction-shorter loop shifts the whole tail by four
 * bytes.  The original reloads +0x18 on every iteration while keeping the
 * entries base cached, which is what the volatile reproduces.  The loop
 * must also be the guard-plus-do-while form: a plain `for` hoists the
 * entries load above the guard.
 *
 * Previously capped at MATCH: the PC24 at +0xa0 (func_0204E074) had no
 * witness outside 0204AF28..0204AFD8, this function being 0x0204E074's only
 * caller image-wide.  src/matched/func_0204E074.c now reproduces that range
 * EXACT, so the site resolves in the `matched` class and the file is EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204AF28.c \
 *       --func sub_0204AF28 --addr 0x0204AF28 --cc 1.1p1 --arm
 */
s32 sub_0204AF28(void *owner, u32 first, u32 second, u32 mode)
{
    struct Res *pool = &g_02146A74->res;
    struct Entry3 *entry;
    s32 idx;

    struct Entry3 *entries;

    idx = 0;
    if ((u32)idx < pool->n_pattern) {
        entries = pool->pattern;
        do {
            if (entries[idx].unk_10 != 0) {
                goto found;
            }
            idx++;
        } while ((u32)idx < pool->n_pattern);
    }
    idx = -1;
found:
    entry = &g_02146A74->res.pattern[idx];

    entry->unk_00 = func_02049250(owner, first, mode);
    entry->unk_04 = func_02049250(owner, second, mode);

    func_0204E074(&g_02146A74->res, idx, entry->unk_00, entry->unk_04);

    return idx;
}



/*
 * Tear down one entry of the 0x14-byte table hanging off +0x114 of the
 * singleton at 0x02146A74: free the two payload pointers at +0 and +4 if
 * they are set, NULL them, and mark the slot free with 1 at +0x10.
 *
 * The entry address is bound to a named local (r4) and survives both
 * calls, so neither the global nor the index multiply is recomputed after
 * the first store, unlike sub_0204ADA4 next door
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 * The first load reads through the register-offset form `ldr r0,[r2,r1]`
 * before the `add` that materialises the cursor; that is scheduling, not
 * a second addressing mode in the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204AFD8.c \
 *       --func sub_0204AFD8 --addr 0x0204AFD8 --cc 1.1p1 --arm
 */
void sub_0204AFD8(u32 i)
{
    struct Entry3 *s = &g_02146A74->res.pattern[i];

    if (s->unk_00 != 0) {
        sub_020307B0(s->unk_00);
        s->unk_00 = 0;
    }
    if (s->unk_04 != 0) {
        sub_020307B0(s->unk_04);
        s->unk_04 = 0;
    }
    s->unk_10 = 1;
}



/*
 * clact.c's 0xA0-byte cell-actor allocation helper: carve the record with the
 * three-argument allocator, hand it and the caller's three values to the
 * record initialiser, and return the record.  The third parameter is the heap
 * id and reaches the allocator as its first argument, so the two call sites
 * do not share an argument order.
 *
 * The file string at 0x020A7F74 is "clact.c" and the stacked fifth argument
 * is __LINE__ = 0x633; declared as an extern array pinned by address, never
 * as a literal __FILE__.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204B034.c \
 *       --func func_0204B034 --addr 0x0204B034 --cc 1.1p1 --arm
 */
struct OamState *func_0204B034(const struct OamInit *a0, u32 a1, u32 heap)
{
    struct OamState *p = sub_02030734(heap, sizeof(struct OamState), 0, s_clact_c, 0x633);

    func_0204BD94(p, a0, a1, heap);
    return p;
}



asm void func_0204B084(void)
{
    stmfd sp!, {r4, lr}
    mov	r4, r0
    bl func_0204BE28
    mov	r0, r4
    bl sub_020307B0
    ldmfd sp!, {r4, pc}
}



/*
 * Unlabelled arm9 leaf (the label at 0x0204B09C also spans the next leaf at
 * 0x0204B0C8); witness for ov021 func_021A87A8. Writes a 16-bit x/y pair,
 * scaled to fx32, into entry idx (0x48 bytes each) of the table at +0x98.
 */
void func_0204B09C(struct OamState *o, int idx, struct Vec2 *v)
{
    int x = v->x;
    int y = v->y;
    struct OamRec *e = &o->recs[idx];
    e->x = x << 12;
    e->y = y << 12;
}



/*
 * EXACT*, not EXACT: the listing extent runs 12 bytes long because what
 * follows at 0x0204B0F4 is not code from this file at all, it is a linker
 * veneer, `ldr ip, [pc]; bx ip; .word 0x0204BE38`
 * (docs/idioms/a-four-byte-arm-function-in-a-thumb-packet-is-a-long-branch-veneer.md
 * describes the Thumb-side form of the same stub).  0x0204B0F4 is a seed for
 * layout/function_starts.txt, and no `tu` range may span it.
 *
 * Read back one cell actor's position: the 0x48-byte records hang off +0x98 of
 * the owner, their first two words are the x and y coordinates in 20.12 fixed
 * point, and the caller gets them as a pair of whole-pixel s16 values.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B0C8.c \
 *       --func sub_0204B0C8 --addr 0x0204B0C8 --cc 1.1p1 --arm
 */
void sub_0204B0C8(struct OamState *owner, u32 index, struct Vec2 *out)
{
    struct OamRec *item = &owner->recs[index];

    out->x = item->x >> 12;
    out->y = item->y >> 12;
}



void func_0204B0F4(struct OamState *a0, int a1)
{
    func_0204BE38(a0, a1);
}



/*
 * The cell-actor bank constructor.  The __FILE__ pointer is the same
 * s_clact_c 0x020A7F74 that src/matched/func_0204D9D4.c pins, so this whole
 * 0x0204Bxxx run is clact.c.
 *
 * Allocate the 0x18-byte bank header, zero it, allocate `count` 0xE4-byte
 * actor records behind it, record the count at +0x0c and the caller's flag at
 * +0x0f, run each record through func_0204CAE4, then the three bank-wide
 * initialisers.  src/matched/sub_0204B1CC.c is the exact inverse.
 *
 * The two allocation sites are one pool word apart in the source's line
 * numbering: 0x6eb is materialised from the literal pool and 0x6ef is derived
 * with `add r0, r5, #4`
 * (docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md), so
 * the second call has to be written with the literal 0x6ef, not with a second
 * pooled constant.
 *
 * The zero shared by the two `clear` arguments, the fill byte and the loop
 * counter all live in r7 for the whole function; `i` therefore has to be a
 * function-scope local, not declared inside the `for`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B100.c \
 *       --func sub_0204B100 --addr 0x0204B100 --cc 1.1p1 --arm
 */
struct Bank *sub_0204B100(int count, u8 flag, u32 heapId)
{
    struct Bank *bank;
    int          i;

    bank = sub_02030734(heapId, sizeof(struct Bank), 0, s_clact_c, 0x6eb);
    MI_CpuFill8(bank, 0, sizeof(struct Bank));

    bank->actors = sub_02030734(heapId, count * sizeof(struct Actor), 0,
                                s_clact_c, 0x6ef);
    bank->count = count;
    bank->unk_0f = flag;

    for (i = 0; i < count; i++) {
        func_0204CAE4(&bank->actors[i]);
    }

    sub_0204B270(bank);
    sub_0204B22C(bank, 1);
    func_0204BBC8(bank);

    return bank;
}



/*
 * The inverse of src/matched/sub_0204B100.c: quiesce the cell-actor bank,
 * tear down every live actor record, then free the record array and the bank
 * header.  An actor counts as live when its first word (the resource handle
 * src/matched/sub_0204B3B4.c hands back) is non-null.
 *
 * `bank->count` is re-read on every iteration because sub_0204B3B4 is opaque
 * to the compiler, so the bound has to stay the field access in the `for`
 * condition rather than a local; the entry test at the top is the compiler's
 * own loop rotation of that same read, not a separate guard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B1CC.c \
 *       --func sub_0204B1CC --addr 0x0204B1CC --cc 1.1p1 --arm
 */
u32 sub_0204B1CC(struct Bank *bank)
{
    int i;

    func_0204BC40(bank);

    for (i = 0; i < bank->count; i++) {
        if (bank->actors[i].next != 0) {
            sub_0204B3B4(&bank->actors[i]);
        }
    }

    sub_020307B0(bank->actors);
    return sub_020307B0(bank);
}



/*
 * Three leaf accessors of clact.c's bank header, packed end to end with no
 * literal pool between them.  Only the first has a `func_` label in the
 * listing, because none of the three saves lr
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x0204B248 and
 * 0x0204B258 are unlabelled followers and are seeds for
 * layout/function_starts.txt.
 *
 * The byte at +0x0e is two 4-bit unsigned bitfields.  The low nibble is a
 * source selector paired with the pointer at +0x08: sub_0204B270 sets it to 0
 * for the shared default at g_02146A74 + 0x40, and 0x0204B258 sets it to 1
 * for a caller-supplied pointer.  The high nibble is written by 0x0204B22C
 * and read back by 0x0204B248, and never appears next to the pointer, so it
 * is an independent mode.
 *
 * The nibble accesses are the giveaway: a plain u8 field masked and shifted
 * would fold to `ands`, while the write here is `bic` plus a shifted `orr`
 * and the read is the unequal `lsl #24` / `lsr #28` pair, which is a bitfield
 * extraction (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B22C.c \
 *       --addr 0x0204B22C --cc 1.1p1 --arm
 */
void sub_0204B22C(struct Bank *bank, u32 mode)
{
    bank->mode = mode;
}



u32 sub_0204B248(struct Bank *bank)
{
    return bank->mode;
}



void sub_0204B258(struct Bank *bank, void *p)
{
    bank->unk_08 = p;
    bank->source = 1;
}



/*
 * The companion of sub_0204B258 in src/matched/unit_0204B22C.c: point the
 * bank at the shared default block 0x40 bytes into whatever 0x02146A74 holds
 * and clear the low nibble of the flag byte at +0x0e back to source 0, where
 * sub_0204B258 sets it to 1 for a caller-supplied pointer.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B270.c \
 *       --func sub_0204B270 --addr 0x0204B270 --cc 1.1p1 --arm
 */
void sub_0204B270(struct Bank *bank)
{
    bank->unk_08 = &g_02146A74->oam;
    bank->source = 0;
}



/*
 * Build a 0x20-byte request on the stack out of three of the singleton's
 * parallel tables, then dispatch it.  The singleton at 0x02146A74 carries
 * three table pointers in a row: 0x40-byte records at +0x10c, 0x18-byte
 * records at +0x110 and 0x14-byte records at +0x114.
 *
 * The global is read once and every index is computed off that one load,
 * because nothing between them can store to it; the two index multiplies
 * are real `mla`s against a register-held 0x18 and 0x14, since neither
 * size is a power of two, while the 0x40-byte stride folds into the
 * addressing as `add r3, r3, ip, lsl #6`.
 *
 * The `lsl #16` / `lsr #16` pairs on the two index arguments are the
 * narrowing casts sub_0204CFA4's u16 parameters force at the call site,
 * not evidence that this function's own parameters are u16: the same
 * values are used untruncated as table indices a few instructions
 * earlier.  Reading them the other way (declaring the parameters u16)
 * would have to truncate before the multiplies too.
 *
 * The last two arguments come back off the caller's own stack with
 * `ldrh`, which is what names those two u16.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B294.c \
 *       --func sub_0204B294 --addr 0x0204B294 --cc 1.1p1 --arm
 */
struct Actor *sub_0204B294(struct Bank *owner, u32 i, u32 j, u32 k,
                        const struct ActorInit *position, u16 f, u16 g)
{
    struct ActorReq req;

    sub_0204CFA4(&req, i, j, &g_02146A74->res.cell[i], &g_02146A74->res.anim[j],
                 g_02146A74->res.pattern[k].unk_08, g_02146A74->res.pattern[k].unk_0c);
    return sub_0204CFDC(owner, position, &req, f, g);
}



/*
 * Same request-builder shape as sub_0204B294: a 0x20-byte request is staged
 * on the stack from three of the singleton's parallel tables (0x40-byte
 * records at +0x10c, 0x18-byte records at +0x110, 0x14-byte records at
 * +0x114), then dispatched by func_0204D048, which is sub_0204CFDC's
 * five-argument sibling.
 *
 * The last two arguments come back off the caller's own stack with `ldrh`,
 * which is what names those two u16; the fifth arrives with a plain `ldr`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204B324.c \
 *       --func func_0204B324 --addr 0x0204B324 --cc 1.1p1 --arm
 */
struct Actor *func_0204B324(struct Bank *owner, u32 i, u32 j, u32 k, const struct ActorInit *e, u16 f, u16 g)
{
    struct ActorReq req;

    sub_0204CFA4((&req), i, j, (&g_02146A74->res.cell[i]), (&g_02146A74->res.anim[j]),
                 g_02146A74->res.pattern[k].unk_08, g_02146A74->res.pattern[k].unk_0c);
    return sub_0204D048(owner, e, &req, f, g);
}



/*
 * Tear-down for the 0x0204Bxxx object: hand the handle at +8 and the owner
 * to func_0204CA30, run the embedded sub-object at +0x68 through
 * func_0204D104, then func_0204CAE4 on the owner.
 *
 * This file was parked at MATCH on the PC24 site at +0x18: this is
 * 0x0204D104's only caller image-wide, and 0x0204D104 was itself stuck
 * because its handler table 0x020A13D0 appears in no other literal pool.
 * 0x020A13D0 is row 5 of the one array based at 0x020A1394, which is pooled
 * at 0x0204D490; src/matched/sub_0204D104.c is now EXACT and attests this
 * site `matched`.  The C here is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B3B4.c  *       --func sub_0204B3B4 --addr 0x0204B3B4 --cc 1.1p1 --arm
 */
void sub_0204B3B4(struct Actor *p)
{
    func_0204CA30(p->owner, p);
    func_0204D104((&p->ctl));
    func_0204CAE4(p);
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * Three consecutive members of one object's interface.  The object carries a
 * handle at +8, a packed flag word at +0x60 and an embedded sub-object at
 * +0x68 that the 0x0204Cxxx/0x0204Dxxx layer operates on.
 *
 *   sub_0204B3DC  set bit 26 of the flag word at +0x60.
 *   sub_0204B3F4  read it back.  Saves no lr, so disasm.py never labels it.
 *   sub_0204B404  move by a delta: ask func_0204CF74 for the current
 *                 position into a scratch pair, add the caller's s16 x/y
 *                 pair to it in a second scratch pair, and hand that to
 *                 func_0204B528.
 *
 * The two 4-byte scratch pairs sit at sp+0 and sp+4; the later declaration
 * takes the lower stack address, so `pos` is declared before `dest`.
 *
 * The range deliberately starts at 0x0204B3DC rather than at this file's
 * real first function, sub_0204B3B4: that one's call to func_0204D104 has
 * no witness anywhere in the image, so including it caps the whole unit at
 * MATCH.  --suggest-split names this exact cut; sub_0204B3B4 is parked in
 * src/pending/sub_0204B3B4.c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B3DC.c \
 *       --addr 0x0204B3DC --arm
 */
void sub_0204B3DC(struct Actor *p, u32 v)
{
    p->enabled = v;
}



u32 sub_0204B3F4(struct Actor *p)
{
    return p->enabled;
}



void sub_0204B404(struct Actor *p, const struct Vec2 *delta, u32 which)
{
    struct Vec2 pos;
    struct Vec2 dest;

    func_0204CF74(p, which, (u16 *)(&pos));
    dest.x = delta->x + pos.x;
    dest.y = delta->y + pos.y;
    func_0204B528(p, (const struct Pt16 *)(&dest));
}



/*
 * Read the actor's screen position back in the coordinate space named by
 * `space`: func_0204CF74 fills in that space's origin, src/matched/sub_0204B53C.c
 * fills in the absolute position, and the difference is written back over the
 * caller's buffer in place.
 *
 * The scratch pair is the `r3` slot of the prologue push rather than an
 * explicit `sub sp`, which is what a single four-byte local costs here.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B454.c \
 *       --func sub_0204B454 --addr 0x0204B454 --cc 1.1p1 --arm
 */
void sub_0204B454(struct Actor *actor, struct Vec2 *out, u16 space)
{
    struct Vec2 origin;

    func_0204CF74(actor, space, (u16 *)&origin);
    sub_0204B53C(actor, (struct Pt16 *)out);

    out->x = out->x - origin.x;
    out->y = out->y - origin.y;
}



/*
 * The write side of src/matched/sub_0204B4EC.c: set one axis of the actor's
 * position, given in the coordinate space named by `space`.
 *
 * THE LEVER (wave 18, lane ties_b; it was DIFF 76/80 for four waves,
 * docs/notes/sub_0204B49C.c.txt): the origin is added to the s16 parameter
 * by COMPOUND assignment in each arm, `value += origin.x;`. The image keeps
 * the narrowed sum in the parameter's home register r6 and copies it into r1
 * for the call; `value = value + origin.x` (or a fresh local, or one
 * expression) lets 1.1p1 narrow straight into r1 and elide the copy, four
 * bytes short.
 */
void sub_0204B49C(struct Actor *actor, s16 value, u32 space, u32 axis)
{
    struct Vec2 origin;

    func_0204CF74(actor, space, (unsigned short *)&origin);

    if (axis == 0) {
        value += origin.x;
    } else {
        value += origin.y;
    }

    sub_0204B550(actor, value, axis);
}



/*
 * The read side of src/matched/sub_0204B49C.c: one axis of the actor's
 * position, expressed in the coordinate space named by `space`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B4EC.c \
 *       --func sub_0204B4EC --addr 0x0204B4EC --cc 1.1p1 --arm
 */
s16 sub_0204B4EC(struct Actor *actor, u32 space, u32 axis)
{
    struct Vec2 origin;
    s16        v;
    s16        o;

    func_0204CF74(actor, space, (unsigned short *)&origin);
    v = sub_0204B560(actor, axis);

    if (axis == 0) {
        o = origin.x;
    } else {
        o = origin.y;
    }

    return v - o;
}



/*
 * Store the actor's screen position pair at +0x0c/+0x0e.  Copied field by
 * field rather than as a four-byte aggregate: a struct assignment of this
 * size would be one `ldr`/`str` pair
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md), and the original spells
 * out two halfword moves instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B528.c \
 *       --func sub_0204B528 --addr 0x0204B528 --cc 1.1p1 --arm
 */
void sub_0204B528(struct Actor *actor, const struct Pt16 *src)
{
    actor->pos.x = src->x;
    actor->pos.y = src->y;
}



/*
 * The read side of src/matched/sub_0204B528.c: copy the actor's screen
 * position pair out of +0x0c/+0x0e, field by field.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B53C.c \
 *       --func sub_0204B53C --addr 0x0204B53C --cc 1.1p1 --arm
 */
void sub_0204B53C(const struct Actor *actor, struct Pt16 *out)
{
    out->x = actor->pos.x;
    out->y = actor->pos.y;
}



/*
 * Write one axis of the actor's screen position: axis 0 is x at +0x0c, any
 * other value is y at +0x0e.  Both arms are a single store, so the compiler
 * if-converts the whole body to `strheq`/`strhne` and the function has no
 * branch at all.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B550.c \
 *       --func sub_0204B550 --addr 0x0204B550 --cc 1.1p1 --arm
 */
void sub_0204B550(struct Actor *actor, signed short value, u32 axis)
{
    if (axis == 0) {
        actor->pos.x = value;
    } else {
        actor->pos.y = value;
    }
}



/*
 * The read side of src/matched/sub_0204B550.c: one axis of the actor's screen
 * position, axis 0 being x at +0x0c.  Both arms are a single load, so the body
 * if-converts to `ldrsheq`/`ldrshne`.
 *
 * The `ldrsh` is the signedness tell
 * (docs/idioms/ldrsh-register-offset-is-signedness.md, here in its
 * immediate-offset form): the stored field itself is u16, since
 * src/matched/sub_0204B53C.c reads the same two halfwords with plain `ldrh`,
 * so the sign extension belongs to this function's s16 return type and not to
 * the struct.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B560.c \
 *       --func sub_0204B560 --addr 0x0204B560 --cc 1.1p1 --arm
 */
s16 sub_0204B560(const struct Actor *actor, u32 axis)
{
    if (axis == 0) {
        return actor->pos.x;
    } else {
        return actor->pos.y;
    }
}



/*
 * Two more leaf accessors of the 0xE4-byte cell actor.  0x0204B588 saves no
 * lr and so carries no label in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); it is a seed
 * for layout/function_starts.txt.
 *
 * sub_0204B570 writes a two-bit field at bits 18..19 of the u32 flag word at
 * +0x60.  The base type has to be u32, not u8 as in
 * src/matched/unit_0204B22C.c: a u8-based bitfield would truncate the
 * incoming value with an `and r1, r1, #0xff` first, and there is no such
 * instruction here.
 *
 * 0x0204B588 is the +0x10 twin of src/matched/sub_0204B528.c, so the actor
 * carries two halfword pairs, the screen position at +0x0c and this second
 * pair at +0x10.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B570.c \
 *       --addr 0x0204B570 --cc 1.1p1 --arm
 */
void sub_0204B570(struct Actor *actor, u32 value)
{
    actor->unk_60_18 = value;
}



void sub_0204B588(struct Actor *actor, const struct Pt16 *src)
{
    actor->origin.x = src->x;
    actor->origin.y = src->y;
}



/*
 * Three leaf accessors on the display object, 56 bytes end to end with no
 * padding.  Only the first carries a label in the listing: the other two
 * save nothing and so are invisible to disasm.py's prologue rule
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They are
 * folded into one unit here rather than three files, which also makes the
 * range self-contained: the unit has no relocation sites at all.
 *
 * sub_0204B59C selects between the +0x10 and +0x12 halfwords on a flag; the
 * front end if-converts it to a `strheq`/`strhne` pair with no branch, and
 * the `eq` arm being first is the source order of the `if`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * sub_0204B5AC and sub_0204B5C0 are the setter and getter for the 8-byte
 * pair at +0x14.  Both words are loaded before either is stored, which is
 * what two independent field assignments give when neither store can be
 * proved to feed the following load; writing them as one 8-byte struct
 * assignment is the same code.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B59C.c \
 *       --addr 0x0204B59C --arm
 */
void sub_0204B59C(struct Actor *o, signed short v, u32 sel)
{
    if (sel == 0) {
        o->origin.x = v;
    } else {
        o->origin.y = v;
    }
}



/*
 * Unlabelled ARM leaf: copy two words from src into the pair at +0x14/+0x18
 * of dst.  `ldr r2,[r1]; ldr r1,[r1,#4]; str r2,[r0,#0x14]; str r1,[r0,#0x18]`.
 */
void func_0204B5AC(struct Actor *dst, struct Pair32 *src)
{
    struct Pair32 v = *src;

    dst->scale = v;
}



void sub_0204B5C0(const struct Actor *o, struct Pair32 *p)
{
    p->x = o->scale.x;
    p->y = o->scale.y;
}



/*
 * Write and read one of the two u32 slots at +0x14 and +0x18 of the cell
 * actor, selected by the last argument.  0x0204B5E4 is an unlabelled leaf and
 * is a seed for layout/function_starts.txt.
 *
 * Both bodies if-convert to a single predicated memory access, the same shape
 * as src/matched/sub_0204B550.c and src/matched/sub_0204B560.c have for the
 * halfword pair at +0x0c.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B5D4.c \
 *       --addr 0x0204B5D4 --cc 1.1p1 --arm
 */
void sub_0204B5D4(struct Actor *actor, u32 value, u32 which)
{
    if (which == 0) {
        actor->scale.x = value;
    } else {
        actor->scale.y = value;
    }
}



u32 sub_0204B5E4(const struct Actor *actor, u32 which)
{
    if (which == 0) {
        return actor->scale.x;
    } else {
        return actor->scale.y;
    }
}



/*
 * The write and read of the u16 at +0x58 of the cell actor.  Neither saves lr,
 * so only the first carries a label in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); 0x0204B5FC is
 * a seed for layout/function_starts.txt.
 *
 * The unit deliberately stops here rather than running on to the end of the
 * listing extent at 0x0204B658.  The next leaf, 0x0204B604, is a closed near
 * miss recorded in docs/notes/sub_0204B604.c.txt, and folding it in would put
 * this range back to DIFF.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B5F4.c \
 *       --addr 0x0204B5F4 --cc 1.1p1 --arm
 */
void sub_0204B5F4(struct Actor *actor, u16 value)
{
    actor->angle = value;
}



u16 sub_0204B5FC(const struct Actor *actor)
{
    return actor->angle;
}



/*
 * The setter side of sub_0204B658 (src/matched/sub_0204B658.c): sets or
 * clears bit `which` of the two-bit field f_14 at bits 20..21 of the flag
 * word at +0x60.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204B604.c \
 *       --func func_0204B604 --addr 0x0204B604 --cc 1.1p1 --arm
 */
void func_0204B604(struct Actor *actor, u32 which, u32 set)
{
    u32 mask = (which == 0) ? 1 : 2;

    if (set == 0) {
        actor->unk_60_20 &= ~mask;
        return;
    }

    actor->unk_60_20 |= mask;
}



/*
 * The test side of sub_0204B604 in src/matched/unit_0204B5F4.c: is bit
 * `which` of the two-bit field at bits 20..21 of the flag word at +0x60 set.
 *
 * The mask is not built into a register here the way the setter builds it.
 * Each arm carries its own constant `tst`, and the `movne r1, #1` that both
 * arms reach is the shared exit
 * (docs/idioms/a-shared-exit-block-is-written-out-in-each-arm.md), so the
 * result has to be a named local initialised to zero before the branch and
 * assigned in both arms, not a returned expression.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B658.c \
 *       --func sub_0204B658 --addr 0x0204B658 --cc 1.1p1 --arm
 */
u32 sub_0204B658(const struct Actor *actor, u32 which)
{
    u32 result = 0;

    if (which == 0) {
        if ((actor->unk_60_20 & 1) != 0) {
            result = 1;
        }
    } else {
        if ((actor->unk_60_20 & 2) != 0) {
            result = 1;
        }
    }

    return result;
}



/*
 * Two accessors of the cell actor's u32 flag word at +0x60.  0x0204B6E4 saves
 * no lr and so carries no label in the listing
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md); it is a seed
 * for layout/function_starts.txt.
 *
 * The flag word is a dense pile of bitfields.  This pair owns the two-bit
 * field at bits 22..23, and writing it also maintains bit 3 of the four-bit
 * field at bits 8..11: setting a non-zero value sets that bit, setting zero
 * clears it.
 *
 * The clear is spelled `^= 8` under a `& 8` guard, not `&= ~8`.  That is
 * visible in the bytes: `&= ~8` on a four-bit field folds to a single
 * `bic r1, r1, #8`, while the original keeps the guard's `tst r1, #8` and then
 * an `eor r1, r1, #8`, which only a real exclusive or produces.
 *
 * Both arms re-read the field out of the value they just stored, so the write
 * of bits 22..23 has to come first as its own statement; the compiler forwards
 * the store and never reloads from +0x60.
 *
 * The polarity matters: the zero case is the source's then-arm
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md), and inside it the
 * `& 8` test is an early `return`, which is what the original's `bxeq lr` is.
 * Written the other way round the compiler predicates the whole clear
 * sequence, which is four bytes short and moves every instruction.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B688.c \
 *       --addr 0x0204B688 --cc 1.1p1 --arm
 */
void sub_0204B688(struct Actor *actor, u32 value)
{
    actor->unk_60_22 = value;

    if (value == 0) {
        if ((actor->mode & 8) == 0) {
            return;
        }
        actor->mode = actor->mode ^ 8;
    } else {
        actor->mode = actor->mode | 8;
    }
}



u32 sub_0204B6E4(const struct Actor *actor)
{
    return actor->unk_60_22;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * A packed bitfield word at +0x60 of the 0x0204Bxxx object: a 12-bit field
 * at bits 0-11 (untouched here), a 4-bit field at bits 12-15, 15 pad bits,
 * and a 1-bit flag at bit 31.
 *
 *   sub_0204B6F4  set the 4-bit field and the top flag bit together (one
 *                 read-modify-write of the whole word).
 *   sub_0204B714  read the 4-bit field back out.
 *
 * The setter's double shift (`lsl r1,r1,#28` then `orr r1,r3,r1,lsr#16`) is
 * the compiler's general bitfield-store formula, value << (32-width) then
 * >> (32-width-offset); the getter's `lsl #16`/`lsr #28` is the matching
 * read formula, << (32-width-offset) then >> (32-width).  The flag bit
 * collapses to a single `lsl #31` because its offset+width is 32.
 *
 * The getter's redundant `and r0, r0, #0xff` (the field is already 0-15) is
 * only there because the source narrows the result to `unsigned char`
 * before returning it; reading the bitfield straight through as `u32` loses
 * those four bytes.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B6F4.c \
 *       --addr 0x0204B6F4 --arm
 */
void sub_0204B6F4(struct Actor *o, u32 v, u32 flag)
{
    o->unk_60_12 = v;
    o->unk_60_31 = flag;
}



u32 sub_0204B714(struct Actor *o)
{
    return (unsigned char)o->unk_60_12;
}



/*
 * Install a transform into the object at +0x40: query the two axis slots
 * through the predicate at 0x0206380C, then copy all five words in.
 *
 * 0x0206380C is a pure reader (`return m->w[axis + 2] != -1;`, 28 bytes,
 * no store), so the source pointer is genuinely `const` here.  Both call
 * results are discarded, which is what an assertion-shaped call looks like
 * once the check itself is compiled out.
 *
 * The `const` is load-bearing for codegen, not decoration: with a plain
 * `struct Xform *` source this front end emits the destination address
 * (`add ip, r5, #0x40`) before the source block load, and with `const` it
 * emits the `ldm r4!, {r0, r1, r2, r3}` first, which is the original's
 * order.  That is the whole content of the DIFF recorded in
 * docs/notes/sub_0204B728.c.txt, and the reason nine non-const spellings
 * there all failed identically.  See
 * docs/idioms/const-source-pointer-schedules-the-block-load-first.md.
 *
 * The copy is twenty bytes, under the unroll threshold, so it inlines to a
 * writeback `ldm`/`stm` pair plus a trailing word for the odd fifth
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B728.c \
 *       --func sub_0204B728 --addr 0x0204B728 --cc 1.1p1 --arm
 */
void sub_0204B728(struct Actor *o, const struct Xform *m)
{
    func_0206380C((char *)m, 1);
    func_0206380C((char *)m, 2);
    o->xform = *m;
}



static inline void copy_inline1(const struct Mtx *src, struct Mtx *dst) {
    *dst = *src;
}



static inline void copy_inline2(struct Mtx *dst, const struct Mtx *src) {
    *dst = *src;
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * Three aggregate struct copies out of a cell actor, laid out as one unit so
 * the whole 140-byte range (padding included) is the evidence.
 *
 * docs/notes/pkt_0204B764.c.txt records these as a two-instruction scheduling
 * residue; that note is SUPERSEDED for all three.  The spelling that closes it
 * is in the body below: the unit's middle function binds the copy to a named
 * struct local (`struct Mtx s; ... s = *src; *(struct Mtx *)(dst + 0x1c) = s;`),
 * which is what puts the source address ahead of the destination move, and the
 * two wrappers cast the base once and assign through it.  `tu` reports EXACT,
 * 3 code sections, 140 bytes, 2 of 2 relocation sites resolved.
 *
 * The previous header carried one per-function block per function rather than
 * one `unit: yes` block, so `manifest --verify` recorded only the LAST of the
 * three and 0x0204B764 / 0x0204B784 stayed open in the worklist although the
 * bytes had been reproduced.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B764.c \
 *       --addr 0x0204B764 --arm
 */
void func_0204B764(const char *src, struct Xform *dst)
{
    const struct Xform *s = (const struct Xform *)(src + 0x40);
    *dst = *s;
}



void func_0204B784(char *dst, const struct Mtx *src)
{
    struct Mtx s;
    func_020637BC((void *)src, 1);
    func_020637BC((void *)src, 2);
    s = *src;
    *(struct Mtx *)(dst + 0x1c) = s;
}



void func_0204B7C8(const char *src, struct Mtx *dst)
{
    const struct Mtx *s = (const struct Mtx *)(src + 0x1c);
    *dst = *s;
}



/*
 * u16 field read at +0x5c.  Unlabelled in the current listings: the prologue
 * saves nothing, so disasm.py never auto-labelled it (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  It sits
 * between the literal pool of func_0204B7C8 and func_0204B800.
 */
u16 func_0204B7F0(struct Actor *p)
{
    return p->unk_5c;
}



/*
 * Same as func_0204B7F0 one field up, at +0x5e.  Unlabelled leaf for the
 * same reason.
 */
u16 func_0204B7F8(struct Actor *p)
{
    return p->unk_5e;
}



/*
 * Field at +0x60 is an 8-bit bitfield in a whole word: the original is a
 * word load, and/bic/orr, word store, never a ldrb/strb.
 */
void func_0204B800(struct Actor *node, u32 val)
{
    node->unk_60_00 = val;
    func_0204CA30(node->owner, node);
    func_0204C98C(node->owner, node);
}



int func_0204B838(struct Actor *a0)
{
    return (u8)a0->unk_60_00 & 0xff;
}



void func_0204B84C(struct Actor *p, unsigned int v)
{
    p->unk_60_16 = v;
}



u32 func_0204B864(struct Actor *a0)
{
    return (u8)a0->unk_60_16;
}



/*
 * Stores a 16-bit value at +0x5a of the object, then runs the sub-object at
 * +0x68 through func_0204D324 and re-runs the owner through func_0204B95C.
 * The same +0x68 sub-object is the one sub_0204B3B4 hands to func_0204D104.
 *
 * This file was parked at MATCH: sub_0204B878 is 0x0204D324's only caller
 * image-wide, so the PC24 site at +0x10 could only ever be attested by an
 * EXACT entry for 0x0204D324 itself, and that function looked unattestable
 * in turn because its handler-table pool word 0x020A13B8 appears in no
 * other literal pool.  It is not a table address: it is row 3 of the one
 * eight-by-three array based at 0x020A1394, which is pooled at 0x0204D490
 * as well.  src/matched/func_0204D324.c carries the reasoning; with that
 * entry EXACT this site resolves `matched` and nothing here changed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B878.c  *       --func sub_0204B878 --addr 0x0204B878 --cc 1.1p1 --arm
 */
void sub_0204B878(struct Actor *p, u16 value)
{
    p->unk_5a = value;
    func_0204D324((&p->ctl), value);
    func_0204B95C(p);
}



/*
 * A whole translation unit range, matched as one byte range.
 *
 * Two members of the interface of the object whose flag word sits at
 * +0x60 (see src/matched/unit_0204B3DC.c and unit_0204B92C.c).  The state
 * this corner of the file owns is the u16 at +0x5a:
 *
 *   sub_0204B898  read it.  Saves no lr, so disasm.py never labels it.
 *   sub_0204B8A0  the guarded write: do nothing when the value is
 *                 unchanged, otherwise hand it to sub_0204B878 (which
 *                 stores it and pushes it down into the 0x0204Dxxx layer)
 *                 and re-run sub_0204B95C on top.
 *
 * The `cmp r1, r2` operand order is the tell that the incoming value is
 * the left operand of the comparison and the field the right one
 * (docs/idioms/cmp-operand-order-names-the-temporary.md), so the guard is
 * written `v == p->unk_5a`, not the other way round.
 *
 * This is a cut out of a larger file: the neighbouring functions
 * 0x0204B8C4, 0x0204B8D4, 0x0204B908 and 0x0204B918 are all byte-correct
 * but each calls a 0x0204Dxxx (or, for 0x0204B918, an 0x02062F1C) entry
 * point that has no caller anywhere else in the image, so they are capped
 * at MATCH and parked in src/pending/, next to the 0x0204B878 that an
 * earlier wave parked there for the same reason.  0x0204B8F4,
 * the other clean one, is in src/matched/sub_0204B8F4.c; it is not
 * contiguous with this pair.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B898.c \
 *       --addr 0x0204B898 --arm
 */
u16 sub_0204B898(struct Actor *p)
{
    return p->unk_5a;
}



void sub_0204B8A0(struct Actor *p, u16 v)
{
    if (v == p->unk_5a) {
        return;
    }
    sub_0204B878(p, v);
    sub_0204B95C(p);
}



/*
 * Forward the sub-object embedded at +0x68 of the 0x0204Bxxx object to
 * sub_0204D3A0.  A pool word and a `bx ip`, never a displacement branch,
 * because each function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Byte-correct, capped at MATCH: 0x0204D3A0 has zero branch witnesses
 * anywhere in the image outside this ABS32 pool word, so the tail-call
 * target cannot be attested.  It unsticks when 0x0204D3A0 is itself
 * decompiled to EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B8C4.c  *       --func sub_0204B8C4 --addr 0x0204B8C4 --cc 1.1p1 --arm
 */
void sub_0204B8C4(struct Actor *p, u32 value)
{
    sub_0204D3A0((&p->ctl), value);
}



/*
 * Run sub_0204D4C4 over the sub-object embedded at +0x68 of the
 * 0x0204Bxxx object, then sub_0204D3C4 on it with 0x1000.  The address
 * is recomputed with a second `add r0, r4, #0x68` rather than kept in a
 * register across the call
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Was capped at MATCH: sub_0204D4C4 is called from this one site and
 * nowhere else in the image, so its PC24 had no outside witness, and
 * sub_0204D3C4 resolved fine (label).  0x0204D4C4 is now the lead function
 * of src/matched/unit_0204D4C4.c and this site resolves `matched` against
 * it.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B8D4.c  *       --func sub_0204B8D4 --addr 0x0204B8D4 --cc 1.1p1 --arm
 */
void sub_0204B8D4(struct Actor *p, u32 arg)
{
    sub_0204D4C4((&p->ctl), arg);
    sub_0204D3C4((&p->ctl), 0x1000);
}



/*
 * Read +0x10 of the record sub_0204D444 hands back for the sub-object
 * embedded at +0x68 of the 0x0204Bxxx object (see
 * src/matched/unit_0204B898.c for the family).  The call result is
 * dereferenced in place, so no register is spent copying it
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * EXACT*: the byte comparison passes, but the follower at 0x0204B908
 * saves no lr, so disasm.py never labelled it and the inferred extent
 * runs past the end of this function.  0x0204B908 wants seeding into
 * layout/function_starts.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B8F4.c \
 *       --func sub_0204B8F4 --addr 0x0204B8F4 --cc 1.1p1 --arm
 */
u32 sub_0204B8F4(struct Actor *p)
{
    return sub_0204D444(&p->ctl)->unk_10;
}



void func_0204B908(int a0, int a1){ func_0204D478((struct Obj0204D478 *)((int)(a0 + 0x68)), (int)a1); }



/*
 * Hand the record sub_0204D444 returns for the sub-object at +0x68
 * straight to sub_02062F1C: a plain forwarding call whose argument is
 * already in r0
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * sub_02062F1C is the one call this family makes outside the 0x0204Cxxx
 * / 0x0204Dxxx layer.
 *
 * Byte-correct, capped at MATCH: 0x02062F1C is called from this one site
 * and nowhere else in the image.  sub_0204D444 resolves fine (label).
 * It unsticks when 0x02062F1C is itself decompiled to EXACT.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204B918.c  *       --func sub_0204B918 --addr 0x0204B918 --cc 1.1p1 --arm
 */
u16 sub_0204B918(struct Actor *p)
{
    return sub_02062F1C(sub_0204D444(&p->ctl));
}



/*
 * A whole translation unit, matched as one byte range.
 *
 * A setter/getter pair for one bit of the flag word at +0x60 of a widely
 * passed object (bit 25).  The unlabelled getter at 0x0204B944 saves no lr,
 * so disasm.py never labels it; it is only visible by sweeping addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B92C.c \
 *       --addr 0x0204B92C --arm
 */
void sub_0204B92C(struct Actor *p, u32 v)
{
    p->unk_60_25 = v;
}



u32 sub_0204B944(struct Actor *p)
{
    return p->unk_60_25;
}



/*
 * A leaf setter for the word at +0x54 of the cell-actor record: two
 * instructions, no frame, no relocation.  It saves no lr, so `disasm.py`
 * would not have labelled it on its own; it is only visible because the
 * worklist walks the packet by address
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204B954.c \
 *       --func func_0204B954 --addr 0x0204B954 --cc 1.1p1 --arm
 */
void func_0204B954(struct Actor *a, u32 v)
{
    a->unk_54 = v;
}



/*
 * Set the flag at +0x0c of the animation record func_0204D410 selects out of
 * the cell actor's +0x68 sub-object.  func_0204B974 next door is the same
 * function storing 0 instead of 1.
 *
 * The store goes through the callee's return value, not through the actor, so
 * the actor pointer is dead after the call and nothing is saved across it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204B95C.c \
 *       --func func_0204B95C --addr 0x0204B95C --cc 1.1p1 --arm
 */
void func_0204B95C(struct Actor *a)
{
    func_0204D410(&a->ctl)->unk_0c = 1;
}



/*
 * Set the flag at +0x0c of the animation record func_0204D410 selects out of
 * the cell actor's +0x68 sub-object.  func_0204B95C next door is the same
 * function storing 1 instead of 0.
 *
 * The store goes through the callee's return value, not through the actor, so
 * the actor pointer is dead after the call and nothing is saved across it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204B974.c \
 *       --func func_0204B974 --addr 0x0204B974 --cc 1.1p1 --arm
 */
void func_0204B974(struct Actor *a)
{
    func_0204D410(&a->ctl)->unk_0c = 0;
}



/*
 * Read the u32 at +0x0c of the record func_0204D444 selects out of the cell
 * actor's +0x68 sub-object.  The pair func_0204B95C / func_0204B974 writes the
 * same field through func_0204D410's record instead.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204B98C.c \
 *       --func func_0204B98C --addr 0x0204B98C --cc 1.1p1 --arm
 */
u32 func_0204B98C(struct Actor *a)
{
    return func_0204D444(&a->ctl)->unk_0c;
}



/*
 * Blocked at MATCH: all 36 concrete bytes are correct, but the PC24 at +0x001C
 * (the call to func_0204D510) has no witness of any class.  0x0204D510 has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0204D510, which sits in
 * pkt_0204D4B0, outside this packet.
 *
 * func_0204B95C followed by a restart of the animation.  The actor pointer
 * has to survive the first call, so unlike func_0204B95C this one spends r4
 * and re-materialises `&a->ctl` for the second call.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204B9A0.c \
 *       --func func_0204B9A0 --addr 0x0204B9A0 --cc 1.1p1 --arm
 */
void func_0204B9A0(struct Actor *a)
{
    func_0204D410(&a->ctl)->unk_0c = 1;
    func_0204D510(&a->ctl);
}



/*
 * Three functions, 0x0204B9C4 / 0x0204BA00 / 0x0204BA10.  Only the first is
 * labelled: the other two save no lr, so `disasm.py` never named them and the
 * extent walk from 0x0204B9C4 runs straight through both
 * (docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  They are
 * folded into this unit because that is the only way they get a manifest
 * entry at all; neither can ever be attested by the `label` class.
 *
 * func_0204B9C4 stores a 4-bit field into the actor's +0x60 word and then
 * pushes the same value into the animation record.  The field is a bitfield,
 * not a mask-and-shift: `lsl #0x1c` followed by `orr ..., lsr #1` is the
 * compiler's insert sequence for width 4 at bit offset 27, where an explicit
 * `(v & 0xf) << 27` would have produced an `and` and a single shift
 * (docs/idioms/unequal-shift-pair-is-a-narrowing-cast-folded-with-a-shift.md).
 *
 * The zero arm clears two fields and the non-zero arm writes one, which is
 * what makes the compiler predicate all three stores off the single `cmp r4,
 * #0` instead of branching.
 *
 * func_0204BA00 and func_0204BA10 are tail-call thunks that only re-base the
 * actor pointer onto its +0x68 sub-object.  Each is a pool word and a `bx`,
 * never a displacement branch, because every function gets its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204B9C4.c \
 *       --addr 0x0204B9C4 --cc 1.1p1 --arm
 */
void func_0204B9C4(struct Actor *a, u32 v)
{
    struct Anim *an;

    a->unk_60_27 = v;

    an = func_0204D410(&a->ctl);
    if (v == 0) {
        an->unk_08 = 0;
        an->unk_18 = 0;
    } else {
        an->unk_18 = v;
    }
}



void func_0204BA00(struct Actor *a, const struct Cmd *cmd)
{
    func_0204D768(&a->ctl, cmd);
}



void func_0204BA10(struct Actor *a)
{
    func_0204D7C4(&a->ctl);
}



/*
 * Store the logical negation of the argument into bit 0 of the cell actor's
 * +0x64 flag word.  A leaf: no lr saved, no relocation.
 *
 * The bit has to be written as an `if`/`else` with a literal in each arm.
 * The assignment form `a->hidden = (v == 0)` materialises the boolean first
 * (`moveq r1, #1` / `movne r1, #0` / `and r1, r1, #1`) and then inserts it,
 * twelve bytes longer; only the two-arm form lets the compiler clear the bit
 * once with `bic` and predicate the set back onto the entry compare.  See
 * docs/idioms/a-one-bit-bitfield-wants-two-arms-not-a-boolean.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BA20.c \
 *       --func func_0204BA20 --addr 0x0204BA20 --cc 1.1p1 --arm
 */
void func_0204BA20(struct Actor *a, u32 v)
{
    if (v == 0) {
        a->hidden = 1;
    } else {
        a->hidden = 0;
    }
}



/*
 * Copy two signed halfword pairs from the caller's array into clact.c's
 * static two-record scratch block and hand the block to func_0204BD94.
 *
 * The two pool words 0x020A7F3C and 0x020A7F54 are one symbol, not two: the
 * stores reach the record array as +0x18/+0x1a/+0x28/+0x2a off the base, so
 * the scratch block is the tail of the same static object whose first 0x18
 * bytes are the six function pointers func_0204D4E0..func_0204D54C that
 * 0x0204D4DC also loads
 * (docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 * Reading them as two objects splits the symbol and loses the relocation.
 *
 * `ldrsh` with an immediate offset is what names the source elements s16
 * (docs/idioms/ldrsh-register-offset-is-signedness.md covers the register
 * form of the same tell).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BA38.c \
 *       --func func_0204BA38 --addr 0x0204BA38 --cc 1.1p1 --arm
 */
void func_0204BA38(struct OamState *a, const s16 *src, u32 mode)
{
    g_020A7F3C.rec[0].x = src[0];
    g_020A7F3C.rec[0].y = src[1];
    g_020A7F3C.rec[1].x = src[2];
    g_020A7F3C.rec[1].y = src[3];

    func_0204BD94(a, g_020A7F3C.rec, 2, mode);
}



/*
 * Record the two VRAM base offsets of a cell-actor resource set in the
 * singleton: func_02063800 returns a byte address per bank selector, the
 * halfword fields at +0xf0 and +0xf2 hold it in 32-byte units, and the
 * caller's bias is then folded into both.
 *
 * The bias is folded with `+=`, not by adding it into the expression above:
 * the compound form re-reads the halfword it just stored
 * (docs/idioms/compound-assignment-rereads-the-field-plain-assignment-reuses-the-cached-load.md),
 * which is what produces the four extra `ldr r1, [r6]` / `ldrh` / `strh`
 * groups instead of one `add` before each store.
 *
 * Only the address of the global is worth keeping in r6: the pointer itself
 * is re-read before every store because each call and each store may alias
 * it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BA7C.c \
 *       --func func_0204BA7C --addr 0x0204BA7C --cc 1.1p1 --arm
 */
void func_0204BA7C(u32 set, u16 bias, u32 v)
{
    g_02146A74->unk_f0[0] = (u32)func_02063800((char *)set, (u32)1) >> 5;
    g_02146A74->unk_f0[1] = (u32)func_02063800((char *)set, (u32)2) >> 5;

    g_02146A74->unk_f0[0] += bias;
    g_02146A74->unk_f0[1] += bias;

    g_02146A74->unk_f4 = v;
}



/*
 * Store a word at +0xf8 of the cell-actor singleton, silently doing nothing
 * before the system is constructed.  A leaf: the guarded store predicates to
 * `strne` and no lr is saved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BAEC.c \
 *       --func func_0204BAEC --addr 0x0204BAEC --cc 1.1p1 --arm
 */
void func_0204BAEC(u32 v)
{
    if (g_02146A74 != 0) {
        g_02146A74->unk_0f8 = v;
    }
}



/*
 * The reader for the word func_0204BAEC writes, returning 0 before the system
 * is constructed.  Both arms are predicated off the null test (`ldrne` and
 * `moveq` into the same register), which is why this has to be written as one
 * `if`/`else` over two returns rather than an early return followed by the
 * load.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BB04.c \
 *       --func func_0204BB04 --addr 0x0204BB04 --cc 1.1p1 --arm
 */
u32 func_0204BB04(void)
{
    if (g_02146A74 != 0) {
        return g_02146A74->unk_0f8;
    } else {
        return 0;
    }
}



/*
 * Store a word at +0xfc of the cell-actor singleton, silently doing nothing
 * before the system is constructed.  A leaf: the guarded store predicates to
 * `strne` and no lr is saved.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BB20.c \
 *       --func func_0204BB20 --addr 0x0204BB20 --cc 1.1p1 --arm
 */
void func_0204BB20(u32 v)
{
    if (g_02146A74 != 0) {
        g_02146A74->unk_0fc = v;
    }
}



/*
 * The reader for the word func_0204BB20 writes, returning 0 before the system
 * is constructed.  Both arms are predicated off the null test (`ldrne` and
 * `moveq` into the same register), which is why this has to be written as one
 * `if`/`else` over two returns rather than an early return followed by the
 * load.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BB38.c \
 *       --func func_0204BB38 --addr 0x0204BB38 --cc 1.1p1 --arm
 */
u32 func_0204BB38(void)
{
    if (g_02146A74 != 0) {
        return g_02146A74->unk_0fc;
    } else {
        return 0;
    }
}



/*
 * Drop the singleton's +0xfc latch: if it is set, release the two OAM
 * sub-records hanging off the singleton itself and clear the latch.
 *
 * Two early returns, each predicated into its own `popeq`, so they are two
 * separate `if`s rather than one `&&`
 * (docs/idioms/guard-chain-sharing-one-exit-block-is-a-single-conjunction.md
 * is the opposite shape: one shared exit block).  The address of the global
 * is held in r4 across both calls, but the pointer itself is re-read for the
 * third call because func_0204BB38 may have stored to it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BB54.c \
 *       --func func_0204BB54 --addr 0x0204BB54 --cc 1.1p1 --arm
 */
void func_0204BB54(void)
{
    if (g_02146A74 == 0) {
        return;
    }
    if (func_0204BB38() == 0) {
        return;
    }

    func_0204BD18(&g_02146A74->mgrs);
    func_0204BB20(0);
}



/*
 * Blocked at MATCH: all 60 concrete bytes are correct, but the PC24 at +0x001C
 * (the call to func_0204C944) has no witness of any class.  0x0204C944 has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0204C944, which sits in the
 * packet after pkt_0204BD64.
 *
 * Walk the singleton's bank ring at +0x100 and run func_0204C944 over every
 * member.  The ring is the one src/matched/func_0204BBC8.c builds, so the
 * walk is a do/while around the head test rather than a null-terminated
 * list.
 *
 * Unlike func_0204BBC8's insertion walk, this one needs no `goto`: the call
 * in the body is an optimisation barrier, so the compiler neither rotates the
 * loop nor hoists the `->head` reload, and the structured form already
 * reproduces the re-read at +0x20.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204BB8C.c \
 *       --func func_0204BB8C --addr 0x0204BB8C --cc 1.1p1 --arm
 */
void func_0204BB8C(void)
{
    struct Bank *cur;

    cur = g_02146A74->head;
    if (cur == 0) {
        return;
    }

    do {
        func_0204C944(cur);
        cur = cur->next;
    } while (cur != g_02146A74->head);
}



/*
 * Link a cell-actor bank into the singleton's priority-ordered ring at
 * +0x100.  The ring is circular and doubly linked through +0x10 (next) and
 * +0x14 (prev); the sort key is the u8 at +0x0f that
 * src/matched/sub_0204B100.c stores from its caller's flag.
 *
 * Empty ring: the bank becomes the head and both of its own links point at
 * itself.  The three stores are written through the global each time, which
 * is why the global is reloaded twice after the first store: a store through
 * a Bank pointer may alias the pointer variable itself, so the compiler
 * cannot keep the initial load live across it.  The walk in the other arm
 * performs no store and keeps the cached copy in ip throughout.
 *
 * The walk has to be written with explicit labels and `goto`.  Every
 * structured spelling (`while`, `do`/`while`, `for(;;)` with two breaks) is
 * rotated: the compiler peels the first priority test, and once the loop has
 * a single back edge it also hoists the `->head` reload out of it, which
 * costs twelve bytes and loses the `ldr r1, [ip, #0x100]` at +0x48.  See
 * docs/idioms/a-reloaded-loop-invariant-means-the-loop-was-not-rotated.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BBC8.c \
 *       --func func_0204BBC8 --addr 0x0204BBC8 --cc 1.1p1 --arm
 */
void func_0204BBC8(struct Bank *bank)
{
    struct Bank *cur;
    struct Bank *prev;

    if (g_02146A74->head == 0) {
        g_02146A74->head = bank;
        g_02146A74->head->next = bank;
        g_02146A74->head->prev = bank;
        return;
    }

    cur = g_02146A74->head;
loop:
    if (cur->unk_0f > bank->unk_0f) {
        goto found;
    }
    cur = cur->next;
    if (cur != g_02146A74->head) {
        goto loop;
    }
found:

    prev = cur->prev;
    bank->prev = prev;
    bank->next = prev->next;
    prev->next->prev = bank;
    prev->next = bank;
}



/*
 * The inverse of src/matched/func_0204BBC8.c: unlink a cell-actor bank from
 * the singleton's ring at +0x100 and NULL both of its own links.  When the
 * bank being removed is the head, the head moves to its successor, or to
 * NULL when the bank was the only member.
 *
 * The head update is one `if`/`else` whose two arms the compiler predicates
 * into `streq`/`strne` off a shared `moveq r1, #0`
 * (docs/idioms/a-factored-tail-lets-the-compiler-predicate-the-arms.md);
 * writing it as a conditional expression on the stored value instead loses
 * the paired store.
 *
 * Both link fields are re-read between the two ring stores because a store
 * through one Bank pointer may alias the other, so `bank->next` is loaded
 * twice and `bank->prev` twice.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BC40.c \
 *       --func func_0204BC40 --addr 0x0204BC40 --cc 1.1p1 --arm
 */
void func_0204BC40(struct Bank *bank)
{
    if (g_02146A74->head == bank) {
        if (bank->next == bank) {
            g_02146A74->head = 0;
        } else {
            g_02146A74->head = bank->next;
        }
    }

    bank->next->prev = bank->prev;
    bank->prev->next = bank->next;
    bank->next = 0;
    bank->prev = 0;
}



/*
 * Blocked at MATCH: all 68 concrete bytes are correct and the call to
 * func_02063078 resolves off the second call site in
 * src/matched/func_0204BCD8.c, but the two PC24 sites at +0x0028 and +0x003C
 * (the calls to func_0204BD3C) have no witness outside this range: those two
 * calls are the only branch references to 0x0204BD3C image wide.  No cut frees
 * them, and src/pending/func_0204BD3C.c cannot supply a `matched` entry
 * because it is itself capped at MATCH by func_02063138, a fan-in-1 extern.
 *
 * Bind both of a cell actor's 0x20-byte OAM sub-records to their hardware
 * spans: flush first, then the low record with span (base, count) and
 * selector 0, then the high record with (base2, count2) and selector 1.
 *
 * The fifth parameter is a u8: it arrives on the caller's stack and is read
 * back with `ldrb r2, [sp, #0x18]` past the six-register push, while the
 * third parameter reaches the same argument slot as a plain `mov`.  Widening
 * it to u32 would drop the `ldrb` to an `ldr`.
 *
 * The second sub-record is reached with `add r0, r7, #0x20`, the constant
 * subscript &o->w[1], not a running cursor.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204BC94.c \
 *       --func func_0204BC94 --addr 0x0204BC94 --cc 1.1p1 --arm
 */
void func_0204BC94(struct OamMgrs *o, u32 base, u32 count, u32 base2, u8 count2)
{
    func_02063078();
    func_0204BD3C(&o->w[0], base, count, 0);
    func_0204BD3C(&o->w[1], base2, count2, 1);
}



/*
 * Release both of a cell actor's 0x20-byte OAM sub-records and then flush the
 * hardware tables.  The pair-wise loops live in func_0204BD18 and
 * func_0204BCF4; this is only the ordering.
 *
 * The actor pointer is saved in r4 across the first call and restored for the
 * second; the third call takes no argument at all, so r0 still carries
 * func_0204BCF4's return value when it is made.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BCD8.c \
 *       --func func_0204BCD8 --addr 0x0204BCD8 --cc 1.1p1 --arm
 */
void func_0204BCD8(struct OamMgrs *o)
{
    func_0204BD18(o);
    func_0204BCF4(o);
    func_02063078();
}



/*
 * Blocked at MATCH: all 36 concrete bytes are correct, but the PC24 at
 * +0x0010 (the call to func_0204BD64) has no witness of any class.  Its only
 * caller image wide is that call, so no cut frees it; the unblock is a
 * `matched` entry at 0x0204BD64, and that file is itself capped on 0x0206343C
 * (508 bytes, pkt_02063078, claimed by lane-C).  Chain capped for this pass.
 *
 * Run func_0204BD64 over both of a cell actor's 0x20-byte OAM sub-records.
 * func_0204BD18 next door is the same loop against func_0204BD7C.
 */
void func_0204BCF4(struct OamMgrs *o)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_0204BD64(&o->w[i]);
    }
}



/*
 * Blocked at MATCH: all 36 concrete bytes are correct, but the PC24 at
 * +0x0010 (the call to func_0204BD7C) has no witness of any class.  Its only
 * caller image wide is that call, and that file is itself capped on 0x02063640
 * (316 bytes, pkt_02063640, claimed by lane-C).  Chain capped for this pass.
 *
 * Run func_0204BD7C over both of a cell actor's 0x20-byte OAM sub-records.
 */
void func_0204BD18(struct OamMgrs *o)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_0204BD7C(&o->w[i]);
    }
}



void func_0204BD3C(struct OamMgr *p, int a, int b, int which)
{
    if (b == 0) {
        p->bound = 0;
        return;
    }
    func_02063138(p, a, b, which);
    p->bound = 1;
}




/*
 * Blocked at MATCH: all 24 concrete bytes are correct, but the PC24 at +0x0010
 * (the call to func_0206343C) has no witness of any class.  0x0206343C has
 * exactly one branch reference image wide and it is that call, so no cut frees
 * it; the only unblock is a `matched` entry at 0x0206343C, a 508-byte function
 * in pkt_02063078, claimed by lane-C and far outside this lane.
 *
 * Release one bound 0x20-byte OAM sub-record of a cell actor.  The "bound"
 * flag at +0x1c is the same one func_0204BD3C sets, and an unbound record is
 * an early return predicated onto the compare (`popeq`).
 */
void func_0204BD64(struct OamMgr *s)
{
    if (s->bound == 0) {
        return;
    }

    func_0206343C(s, s->bound);
}




/*
 * Blocked at MATCH: all 24 concrete bytes are correct, but the PC24 at +0x0010
 * (the call to func_02063640) has no witness of any class.  0x02063640 has
 * exactly one branch reference image wide and it is that call; the only unblock
 * is a `matched` entry at 0x02063640, a 316-byte function in pkt_02063640,
 * claimed by lane-C.
 *
 * Release one bound 0x20-byte OAM sub-record of a cell actor.  The "bound"
 * flag at +0x1c is the same one func_0204BD3C sets, and an unbound record is
 * an early return predicated onto the compare (`popeq`).  The r1 read at the
 * call is a leftover, not an argument: 0x02063640 overwrites r1 at +0x1C with
 * `ldrh r1, [r5, #8]` before any use (docs/notes/func_02063640.c.txt).
 */
void func_0204BD7C(struct OamMgr *s)
{
    if (s->bound == 0) {
        return;
    }

    func_02063640(s);
}




/*
 *           this body (the tool prints "no witness outside 0204BD94..0204BE2C");
 *           func_0204BE84 lives in pkt_0204BE84, which is not this lane's.
 *
 * Byte-identical at 148 bytes; only the two PC24 call fields at +0x14 and
 * +0x68 stay wildcarded.  The 0x020A7F74 pool word is ABS32 into the string
 * area and resolves `literal`, and func_02065B64 resolves `matched`.
 *
 * Spellings that mattered: `for (i = 0; i < count; i++)` with an unsigned `i`
 * and a signed `count` is what gives the single `popls` loop guard and the
 * `blo` back-edge.  Adding an explicit `if (count <= 0) return;` in front of
 * the loop emits BOTH `pople` and `popls` and costs four bytes of layout.
 */
void func_0204BD94(struct OamState *obj, const struct OamInit *src, int count, u32 heap)
{
    u32 i;

    func_02065AA8(obj);
    obj->unk_80 = 1;
    obj->recs = sub_02030734(heap, count * sizeof(struct OamRec), 0, s_clact_c, 0xfc7);
    obj->count = count;
    for (i = 0; i < count; i++) {
        func_0204BE84(&obj->recs[i], &src[i]);
        func_02065B64(obj, &obj->recs[i]);
    }
}



void func_0204BE28(struct OamState *p){ sub_020307B0(p->recs); }






#define fxmul(a, b) ((s32)((((s64)(a) * (s64)(b)) + 0x800) >> 12))











/*
 * Culling on/off for a 0x48-stride element array (the same f98/f9c pair
 * func_0204BD94 allocates): on != 0 installs func_0204C2C8 as each element's
 * +0x40 callback, on == 0 sets obj->f30 = 1 and clears the callbacks.  Reached
 * only through a pool word at 0x0204B0FC; the pool word 0x0204C2C8 resolves
 * sole-ref/code.
 *
 * Two levers, both needed: the non-zero arm first (`if (on != 0)`), and `i`
 * declared before `fn` (tools/permuter.py found the decl-order swap).
 */
void func_0204BE38(struct OamState *obj, int on)
{
    u32 i;
    OamCullFn fn;

    if (on != 0) {
        fn = func_0204C2C8;
    } else {
        obj->unk_30 = 1;
        fn = 0;
    }
    for (i = 0; i < obj->count; i++) {
        obj->recs[i].cull = fn;
    }
}











/*
 * Wave 15 (register-tie lane).  Three facts closed the 104-byte residue of
 * docs/notes/pkt_0204BE84.c.txt:
 *  - func_0204BF28 takes TWO arguments (a0, a1->f8): its body is
 *    `a0->f14 = tbl_020A1388[idx]`, and the image's `ldr r1, [r4, #8]`
 *    inside the store block is that argument, not an early load of the
 *    table index.  The "missing mov r0, r5" of the older note follows.
 *  - `const T *a1` (the source record is read-only); the volatile +0x04
 *    device of the older note is no longer needed.
 *  - the f2 and f6 halfwords bound to s16 locals at the image's load points
 *    (found by permuter anneal, then reduced by hand): that fixes the
 *    f0, f2, f6, f4 load order and the r2/r3 pair.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BE84.c \
 *       --func func_0204BE84 --addr 0x0204BE84 --cc 1.1p1 --arm
 */
void func_0204BE84(struct OamRec *a0, const struct OamInit *a1)
{
    S12 t;
    s16 y;
    s16 x;

    func_02065B74(a0);
    x = a1->y;
    a0->x = (int)a1->x << 12;
    y = a1->h;
    a0->y = (int)x << 12;
    a0->unk_08 = (int)a1->w << 12;
    a0->unk_0c = (int)y << 12;
    func_0204BF28(a0, a1->unk_08);
    t = g_020A1418[a1->unk_08];
    t.w2 = g_020A13F4[a1->unk_0c];
    a0->unk_28 = (int)t.w0;
    a0->unk_2c = (int)t.w1;
    a0->unk_34 = (int)t.w2;
}











/*
 * Blocked at MATCH: all 24 concrete bytes are correct (20 code + the pool
 * word), but the ABS32 at +0x0014 has no witness of any class.  0x020A1388
 * is plain data, so only the `literal` class could attest it, and the pool
 * word inside this function is that address's only occurrence image wide.
 * The escape that unblocked 0x0204C83C in this same region (decompile the
 * target to EXACT and cite it as a `matched` witness) does not exist here:
 * nothing compiles a data table.  Same wall as src/matched/func_0204C8B8.c
 * and docs/notes/clact_c_fan_in_1_blockers.c.txt describe for 0x020A138C.
 *
 * Store the u16 entry `idx` of the table at 0x020A1388 into the caller's
 * word at +0x14, zero-extended.
 */
void func_0204BF28(struct OamRec *p, u32 idx)
{
    p->unk_14 = g_020A1388[idx];
}











/*
 * Push one OAM entry through the window at `win`, rewriting its palette field
 * on the way.  The caller's 8-byte entry is copied onto the stack first
 * (MI_CpuCopy8, not a struct assignment: the source is only 2-aligned), then
 * the 4-bit palette in bits 12..15 of the attribute halfword at +4 is either
 * BIASED by `pal` (mode 0) or REPLACED with it (mode 1); any other mode leaves
 * the entry alone.  The rewritten copy, not the caller's, is what reaches
 * func_02063294.
 *
 * The bias arm is written as a store through a pointer to the halfword's word
 * (`add r2, sp, #4` then `ldr`/`str` through r2), which is what makes the
 * image reload the base instead of re-using sp; the replace arm is small
 * enough that 1.1p1 predicates it whole
 * (`ldreq`/`lsleq`/`biceq`/`orreq`/`streq`) and needs no such pointer.
 *
 * Signature pinned from src/matched/func_0204BFC4.c, the one filed caller.
 *
 * BYTE-CORRECT, PARKED, NOT FILED.  132 bytes, 0 concrete mismatches; the sole
 * unresolved site is the PC24 to func_02063294 at +0x78.  Blocking evidence
 * class: `label` -- 0x02063294 has no branch anywhere in the image outside
 * 0x0204BF40..0x0204BFC4, and there is no `matched` entry for it
 * (docs/notes/pkt_02063078.c.txt records it as a DIFF, 228 bytes).  Filing
 * func_02063294 unblocks this file with no change to the C_0204BE38.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204BF40.c \
 *       --func func_0204BF40 --addr 0x0204BF40 --cc 1.1p1 --arm
 */
void func_0204BF40(struct OamMgr *win, struct OamEntry *src, u32 mode, u32 pal,
                   u32 op)
{
    struct OamEntry ent;
    u32 *attr2;

    MI_CpuCopy8(src, &ent, sizeof(ent));

    if (op == 0) {
        attr2 = (u32 *)&ent.attr[2];
        *attr2 = (*attr2 & ~0xf000) |
                 ((((u32)(u16)*attr2 >> 12) + pal) << 28 >> 16);
    } else if (op == 1) {
        *(u32 *)&ent.attr[2] = (*(u32 *)&ent.attr[2] & ~0xf000) |
                               (pal << 28 >> 16);
    }

    func_02063294(win, &ent, mode);
}











/*
 * Forward one command at the manager itself: the manager is the command
 * block, its u16 at +0xf0 is the id and the word at +0xf4 the payload.
 */
void func_0204BFC4(struct OamEntry *a0, u32 a1)
{
    func_0204BF40(&g_02146A74->mgrs.w[0], a0, a1, g_02146A74->unk_f0[0], g_02146A74->unk_f4);
}










/*
 * Same forward as func_0204BFC4, but aimed at the sub-command block at
 * +0x20 of the manager, whose id and payload sit at +0xf2 / +0xf4.
 */
void func_0204BFF4(struct OamEntry *a0, u32 a1)
{
    func_0204BF40(&g_02146A74->mgrs.w[1], a0, a1,
                  g_02146A74->unk_f0[1], g_02146A74->unk_f4);
}









/*
 * Tail call through the singleton pointer: the pool word for the global is
 * loaded, its value passed as the first argument, and the callee reached with
 * the compiler's usual `ldr ip, [pc, #4]` / `bx ip` plus a second pool word.
 */
void func_0204C024(u32 v)
{
    func_02063378(&g_02146A74->mgrs.w[0], v);
}








/*
 * Same forward as func_0204C024 but aimed at the sub-block at +0x20.
 *
 * Unlabelled in the current listings: the prologue saves nothing, so
 * disasm.py never auto-labelled it (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  The
 * function starts at the computed address and its body ends at 0x0204C060.
 */
void func_0204C040(u32 arg)
{
    func_02063378(&g_02146A74->mgrs.w[1], arg);
}







/*
 * The 2x2-matrix sibling of func_0204C214 (see docs/notes/pkt_0204C060.c.txt):
 * transform the sprite's four half-extents through the caller's 2x2 matrix in
 * 20.12 fixed point, translate by the camera delta, take the min/max of each
 * axis and cull against the viewport.
 *
 * Three levers, all measured, that this note's sibling row asked for:
 *  - The fall-through arm is the `flag == 1` field arm and the synthetic arm
 *    is the predicated one (`rsbne`/`lslne`/`movne` + `bne` over the fields),
 *    which only happens when the 6-bit extraction is hoisted ABOVE the `if`.
 *  - `dx` must be computed beside `dy`, before the `if`, not after it: with
 *    `dx` after the branch the whole 64-bit block reallocates (295 bytes out).
 *  - The extraction must go through an explicit u8 narrowing of the MASK,
 *    `(s32)(u8)(f & 0x3f)` then `(m6 << 2) & 0xff`. Every spelling that masks
 *    first and narrows the SHIFTED value -- `((f & 0x3f) << 2) & 0xff`,
 *    `(u8)((f & 0x3f) << 2)`, the u32 and the `* 4` forms -- lets 1.1p1 prove
 *    the field contiguous and fuse it into `lsl #26` + `lsr #24`, where the
 *    image keeps `and #0x3f` + `lsl #2` + `and #0xff`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C060.c \
 *       --func func_0204C060 --addr 0x0204C060 --cc 1.1p1 --arm
 */
int func_0204C060(struct ClipSrc *a, struct ClipMtx *m, struct ClipRect *c)
{
    u16 f = a->f02;
    s32 m6 = (s32)(u8)(f & 0x3f);
    s32 e = (m6 << 2) & 0xff;
    s32 dy = m->f10 - c->x;
    s32 dx = m->f14 - c->y;
    s32 v0, v1, v2, v3;
    s32 b04, b0c, b08, b00;
    s32 p0, p1, p2, p3;
    s32 t;

    if (((f >> 11) & 1) == 1) {
        v0 = a->f0e << 12;
        v1 = a->f0a << 12;
        v2 = a->f0c << 12;
        v3 = a->f08 << 12;
    } else {
        v1 = e << 12;
        v0 = (-e) << 12;
        v2 = v0;
        v3 = v1;
    }
    b04 = m->f04;
    b0c = m->f0c;
    b08 = m->f08;
    b00 = m->f00;

    p0 = dx + (fxmul(v0, b04) + fxmul(v0, b0c));
    p1 = dx + (fxmul(v1, b04) + fxmul(v1, b0c));
    p2 = dy + (fxmul(v2, b00) + fxmul(v2, b08));
    p3 = dy + (fxmul(v3, b00) + fxmul(v3, b08));

    t = p1;
    if (p1 < p0) {
        t = p0;
        p0 = p1;
    }
    if (p3 < p2) {
        s32 u = p3;
        p3 = p2;
        p2 = u;
    }
    if (t > 0 && p0 < c->f0c && p3 > 0 && p2 < c->f08)
        return 1;
    return 0;
}







/*
 * The axis-aligned sibling of func_0204C060 (clact.c): take the sprite's four
 * half-extents in 20.12 fixed point, translate by the camera delta and cull
 * against the viewport.  Where func_0204C060 runs the extents through a 2x2
 * matrix, this one adds the deltas straight to them.  No relocations.
 *
 * Four levers, all measured against the image (docs/notes/pkt_0204C060.c.txt
 * had this row at 37-148 bytes out before the second pass):
 *  - The fall-through arm is the `flag == 1` field arm and the synthetic arm
 *    is the predicated one (`rsbne`/`lslne`/`movne` + `bne` over the fields).
 *    That only happens when the 6-bit extraction is hoisted ABOVE the `if`.
 *  - `dy` is declared before `dx` (the image's first `sub` is
 *    `b->f10 - c->f00`); swapping them costs 8 bytes.
 *  - The four sums must be computed as named locals in the order
 *    ay, ax, bx, by BEFORE the `&&` chain; computing them inside the chain
 *    makes the compiler interleave the adds with the branches (115 out).
 *  - The extraction must go through an explicit u8 narrowing of the MASK,
 *    `(s32)(u8)(w & 0x3f)` then `(m6 << 2) & 0xff`, exactly as
 *    func_0204C060 documents.  Every spelling that masks first and narrows
 *    the SHIFTED value -- `(u8)((w & 0x3f) << 2)`, `((w & 0x3f) << 2) & 0xff`,
 *    the u32 and the `* 4` forms -- lets 1.1p1 prove the field contiguous and
 *    fuse it into `lsl #26` + `lsr #24`, where the image keeps
 *    `and #0x3f` + `lsl #2` + `and #0xff`.  This was the final 6-byte residue;
 *    tools/permuter.py exhausted 261 single mutations on it without moving it,
 *    which is the "residue is in the reading, not the allocation" signature.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/func_0204C214.c \
 *       --func func_0204C214 --addr 0x0204C214 --cc 1.1p1 --arm
 */
int func_0204C214(struct ClipSrc *a, struct ClipMtx *b, struct ClipRect *c)
{
    u16 w = a->f02;
    s32 m6 = (s32)(u8)(w & 0x3f);
    s32 v = (m6 << 2) & 0xff;
    s32 dy = b->f10 - c->x;
    s32 dx = b->f14 - c->y;
    s32 x0, y0, x1, y1;
    s32 ax, ay, bx, by;

    if (((w >> 11) & 1) == 1) {
        x0 = a->f0e << 12;
        y0 = a->f0a << 12;
        x1 = a->f0c << 12;
        y1 = a->f08 << 12;
    } else {
        x0 = -v << 12;
        y0 = v << 12;
        x1 = -v << 12;
        y1 = v << 12;
    }
    ay = y0 + dx;
    ax = x0 + dx;
    bx = x1 + dy;
    by = y1 + dy;
    return ay > 0 && ax < c->f0c && by > 0 && bx < c->f08;
}







static inline s32 RepeatX(s16 x)
{
    if (x > 0xff)
        x |= ~0xff;
    return x;
}







static inline s32 RepeatY(s16 y)
{
    if (y > 0x7f)
        y |= ~0xff;
    return y;
}






static inline u16 SizeX(s32 shape)
{
    return tbl_020A17F0[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
}







static inline u16 SizeY(s32 shape)
{
    return tbl_020A17D8[(shape & 0xc000) >> 14][(shape & 0xc0000000) >> 30];
}







/*
 * The OAM cull callback func_0204BE38 installs at element +0x40: read the
 * element's GXOamAttr attr01 word (+0x38), wrap x (9 bits) and y (8 bits),
 * size the object from the OBJ width/height tables indexed [shape][size],
 * and store func_0204C3CC's verdict into the element's visible flag (+0x30).
 * box is the 2x2 matrix plus translation (f10/f14), p the viewport.
 *
 * Lever (wave 16, declaration facts): the two OBJ size tables are
 * read-only data and are declared `const`.  Without const every register
 * name of the second half shuffled (58 bytes, flat under 120 declaration
 * orders, 80 index casts and two anneals); with it, EXACT.  const on the
 * p parameter is wrong (264 bytes); const on box and on the callee's
 * pointer parameters is neutral.
 */
void func_0204C2C8(struct OamRec *e, struct ClipRect *p, s32 u2, s32 u3, struct ClipMtx *box)
{
    s32 shape = e->oam.attr01 & 0xC000C000;
    s32 x0 = RepeatX(e->oam.x) << 12;
    s32 x1 = (RepeatX(e->oam.x) + SizeX(shape)) << 12;
    s32 y0 = RepeatY(e->oam.y) << 12;
    s32 y1 = (RepeatY(e->oam.y) + SizeY(shape)) << 12;

    e->visible = func_0204C3CC(box->f10 - p->x, box->f14 - p->y,
                               x0, x1, y0, y1, box, p) != 0;
}





#undef fxmul




#undef fxmul



#undef fxmul


#undef fxmul

#undef fxmul


#define fxmul(a, b) ((s32)((((s64)(a) * (s64)(b)) + 0x800) >> 12))







/*
 * The 2x2-matrix cull test behind func_0204C2C8 (its only caller): transform
 * the four corners (x0,y0) (x0,y1) (x1,y0) (x1,y1) of an OAM rectangle through
 * the matrix m (20.12, rounded +0x800), take min/max per axis, translate by the
 * camera delta (dx, dy) and test against the viewport c->f08 / c->f0c.  Eight
 * arguments: dx, dy, x0, x1 in r0-r3; y0, y1, m, c on the stack.
 *
 * Levers, all measured (wave 10):
 *  - the four translated bounds are added EAGERLY as statements
 *    (`minx += dx; maxx += dx; miny += dy; maxy += dy;`) before the `&&`
 *    chain, same lever as func_0204C214; inline in the chain: 41-66 out.
 *  - declaration order `maxx, minx, maxy, miny` and the seed order
 *    `min = p; max = p;` put the minimum in p's register and the maximum in
 *    the copy (r4/lr, sb/r7), as the image has it; any other order swaps the
 *    pair (25-37 out).  Found by tools/permuter.py (decl-order + reorder),
 *    then closed by sweeping all 240 decl/seed orders.
 *  - the umull/mla (not smull) products from the second use of each
 *    coordinate on are the CSE'd `(s64)` sign halves, not a different macro.
 */
int func_0204C3CC(s32 dx, s32 dy, s32 x0, s32 x1, s32 y0, s32 y1,
                  const struct ClipMtx *m, const struct ClipRect *c)
{
    s32 maxx, minx, maxy, miny;
    s32 p;

    p = fxmul(x0, m->f00) + fxmul(y0, m->f08);
    minx = p;
    maxx = p;
    p = fxmul(x0, m->f00) + fxmul(y1, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;
    p = fxmul(x1, m->f00) + fxmul(y0, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;
    p = fxmul(x1, m->f00) + fxmul(y1, m->f08);
    if (p < minx) minx = p; else if (p > maxx) maxx = p;

    p = fxmul(x0, m->f04) + fxmul(y0, m->f0c);
    miny = p;
    maxy = p;
    p = fxmul(x0, m->f04) + fxmul(y1, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;
    p = fxmul(x1, m->f04) + fxmul(y0, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;
    p = fxmul(x1, m->f04) + fxmul(y1, m->f0c);
    if (p < miny) miny = p; else if (p > maxy) maxy = p;

    minx += dx; maxx += dx; miny += dy; maxy += dy;
    if (maxy > 0 && miny < c->f0c && maxx > 0 && minx < c->f08)
        return 1;
    return 0;
}





/*
 * promoted: from src/pending 2026-09-19, no C change: blocker 0x02066934 is filed in layout/matched/arm9/pkt_02066890.json and every site resolves (gate: manifest --verify --shard layout/matched/arm9/pkt_0204C060.json, then 0 rewritten).
 *
 * Blocked at MATCH: all 132 concrete bytes are correct and four of the five
 * relocation sites resolve, but the PC24 at +0x0054 (the call to
 * func_02066934) has no witness of any class.  0x02066934 has exactly one
 * branch reference image wide and it is that call, so no cut frees it; the
 * only unblock is a `matched` entry at 0x02066934, far outside clact.c.
 *
 * Construct a pool of `n` 0x30-byte records: allocate the array, hand it to
 * func_02066934 with func_0204C83C as the per-record callback, build the
 * parallel 0x10-byte entry array through func_0204C718, and mark the object
 * constructed.  A zero capacity leaves the object unconstructed and is the
 * predicated early return off the `movs` that loads the count.
 *
 * The record size 0x30 is a real `mul` against a register, not a shift pair:
 * mwccarm only strength-reduces the multiply when the constant is a power of
 * two, and 0x30 is not.
 *
 * The allocation result is bound to a local, stored, and then passed on: the
 * call to func_02066934 reuses the value in r0 instead of reloading +0x00,
 * which is what the named temporary produces
 * (docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md).
 *
 * func_0204C83C is passed as data, so the relocation is an ABS32 into the
 * code section; it is an ordinary extern declared at its own address, not a
 * veneer.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204C660.c \
 *       --func func_0204C660 --addr 0x0204C660 --cc 1.1p1 --arm
 */
void func_0204C660(struct Pool *p, u8 n, u32 heapId)
{
    struct Rec_0204BE38 *recs;

    if (n == 0) {
        p->ready = 0;
        return;
    }

    p->count = n;
    recs = sub_02030734(heapId, n * sizeof(struct Rec_0204BE38), 0, s_clact_c, 0x1337);
    p->recs = recs;

    func_02066934(recs, n, func_0204C83C);
    func_0204C718((struct Pool *)p, n, heapId);

    p->ready = 1;
}





/*
 * The inverse of src/matched/func_0204C660.c: release the 0x30-byte record
 * array, drop the free-list built over it, and clear the constructed flag at
 * +0x0c.  An unconstructed object is an early return predicated onto the
 * entry compare.
 *
 * The zero is materialised once into a callee-saved register and used for
 * both stores, because the second store lands after the call to
 * func_0204C788; that is also what forces the store to +0x00 to be written
 * before the call rather than after
 * (docs/idioms/a-store-that-lands-after-the-next-call-names-a-local-temporary.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C6E4.c \
 *       --func func_0204C6E4 --addr 0x0204C6E4 --cc 1.1p1 --arm
 */
void func_0204C6E4(struct Pool *p)
{
    if (p->ready == 0) {
        return;
    }

    sub_020307B0(p->recs);
    p->recs = 0;
    func_0204C788((struct Pool *)p);
    p->ready = 0;
}





/*
 * Allocate the pool's parallel array of 0x10-byte entries and zero each one.
 * The __FILE__ pointer is the same s_clact_c the rest of clact.c uses; the
 * line number 0x137b is a plain pooled constant here, not derived from a
 * neighbouring one, because this is the only allocation in the function.
 *
 * The entry count for the loop is read back out of the object at +0x08 rather
 * than reused from the `n` that sized the allocation: the load right after the
 * call is the loop's rotated entry test, and the same field is re-read at the
 * bottom of every iteration because MI_CpuFill8 may alias it.
 *
 * The clear is a per-element call, not one call over the whole array, so the
 * zero and the 0x10 are hoisted into callee-saved registers for the loop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C718.c \
 *       --func func_0204C718 --addr 0x0204C718 --cc 1.1p1 --arm
 */
void func_0204C718(struct Pool *p, u32 n, u32 heapId)
{
    u32 i;

    p->ents = sub_02030734(heapId, n * sizeof(struct PoolEntry), 0, s_clact_c,
                           0x137b);

    for (i = 0; i < p->count; i++) {
        MI_CpuFill8(&p->ents[i], 0, sizeof(struct PoolEntry));
    }
}




/*
 * Release the 0x10-byte entry array func_0204C718 allocates at +0x04 and NULL
 * the pointer.  The pointer has to survive the free call, so the object is
 * kept in r4 and the store is written after it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C788.c \
 *       --func func_0204C788 --addr 0x0204C788 --cc 1.1p1 --arm
 */
void func_0204C788(struct Pool *p)
{
    sub_020307B0(p->ents);
    p->ents = 0;
}




/*
 * Blocked at MATCH: all 96 concrete bytes are correct, but the PC24 at
 * +0x0034 (the call to func_0204C8B8) has no witness of any class.
 * 0x0204C8B8 has exactly one branch reference image wide and it is that
 * call, so no cut frees it; the unblock is a `matched` entry at 0x0204C8B8,
 * which src/pending/func_0204C8B8.c cannot supply, being itself byte-correct
 * but capped at MATCH by the handler table at 0x020A138C having no second
 * pool word anywhere in the image.
 *
 * Tear down every live entry of a 16-byte-record table: the record count is
 * at +0x08 and the array base at +0x04, and a record is live when its first
 * word is non-null.  Each live record is handed to func_0204C8B8 and then
 * zeroed.
 *
 * The array base is re-read from +0x04 on both sides of the func_0204C8B8
 * call, which is what fixes it as a field load rather than a cached local:
 * the callee may move the table.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204C7A4.c \
 *       --func func_0204C7A4 --addr 0x0204C7A4 --cc 1.1p1 --arm
 */
void func_0204C7A4(struct Pool *t)
{
    u32 i;

    for (i = 0; i < t->count; i++) {
        if (t->ents[i].unk_00 != 0) {
            func_0204C8B8((struct Xfer *)(&t->ents[i]));
            MI_CpuFill8(&t->ents[i], 0, sizeof(struct PoolEntry));
        }
    }
}




/*
 * Find the first free 0x10-byte entry of a pool, free meaning a zero word at
 * +0x00.  Returns NULL when the pool is full.  A leaf: nothing here calls
 * anything, so both the entry array and the count are hoisted out of the loop
 * and the element address is only materialised on the arm that returns it
 * (`addeq r0, r2, r1, lsl #4`).
 *
 * The scaled register offset `ldr r0, [r2, r1, lsl #4]` is the subscript form
 * `p->ents[i].unk_00`; a walking cursor would have produced a post-indexed
 * load and an extra add
 * (docs/idioms/keeping-a-cursor-in-a-named-local-costs-a-callee-saved-register.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C804.c \
 *       --func func_0204C804 --addr 0x0204C804 --cc 1.1p1 --arm
 */
struct PoolEntry *func_0204C804(struct Pool *p)
{
    u32 i;

    for (i = 0; i < p->count; i++) {
        if (p->ents[i].unk_00 == 0) {
            return &p->ents[i];
        }
    }

    return 0;
}




/*
 * The per-record callback src/matched/func_0204C660.c hands to func_02066934,
 * which is why its address only ever appears as a pool word and never as a
 * branch target.
 *
 * The selector local really is uninitialised on the path where the first
 * argument is neither 0x13 nor 0x23: r4 is written only inside the two
 * predicated arms and is read again at the call below, with no `mov r4, ...`
 * on the fall-through.  Giving it a default value in the C adds that `mov`
 * and four bytes, so the original's C had an `if`/`else if` with no `else`.
 *
 * The handle passed to func_0204C8A4 is func_0204C804's return value left in
 * r0, not a reload; the selector chain in between touches only r4 and the
 * flags.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C83C.c \
 *       --func func_0204C83C --addr 0x0204C83C --cc 1.1p1 --arm
 */
u32 func_0204C83C(u32 kind, u32 a, u32 b, u32 c)
{
    void *h;
    u32   sel;

    h = func_0204C804(&g_02146A74->pool);

    if (kind == 0x13) {
        sel = 0;
    } else if (kind == 0x23) {
        sel = 1;
    }

    if (c != 0) {
        func_0204C8A4(h, sel, a, b, c);
    }

    return 1;
}




/*
 * Fill one 0x10-byte pool entry.  A leaf with five arguments, so the last one
 * is read straight back off the caller's stack with no frame at all.
 *
 * The store order in the source is +0x0c, +0x00, +0x04, +0x08: only the last
 * two are adjacent in both address and source order, which is what lets the
 * compiler fuse them into `stmib r0, {r2, ip}`.  Writing the four fields in
 * address order would fuse three of them instead and change the encoding.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C8A4.c \
 *       --func func_0204C8A4 --addr 0x0204C8A4 --cc 1.1p1 --arm
 */
void func_0204C8A4(struct Entry *e, u32 sel, u32 a, u32 b, u32 c)
{
    e->unk_0c = sel;
    e->unk_00 = b;
    e->unk_04 = a;
    e->unk_08 = c;
}




extern void (*g_020A138C[])(void *src, u32 arg, u32 size);




/*
 * Blocked at MATCH: all 44 concrete bytes are correct, but the ABS32 at
 * +0x0028 (the handler table at 0x020A138C) has no witness.  The table is
 * plain data, so only the `literal` class could attest it, and the pool word
 * inside this function is the address's only occurrence image wide; there is
 * no second site.  The same wall docs/notes/clact_c_fan_in_1_blockers.c.txt
 * describes for 0x0204C83C, but without its escape: there the address was a
 * function that could be decompiled to EXACT and become a `matched` witness,
 * here it is a table and nothing compiles it.
 *
 * Run one 16-byte transfer record: flush the source range out of the data
 * cache, then dispatch on the record's fourth word through the handler table
 * at 0x020A138C, passing the other three words.
 *
 * The four words are read back with a single `ldm r4, {r0, r1, r2, ip}`,
 * which is the compiler combining four consecutive field loads, not a struct
 * copy: the first and third are loaded a second time here because
 * DC_FlushRange may have written them.
 *
 * This function is the sole blocker for src/pending/func_0204C7A4.c, whose
 * only call to it is the one branch reference it has image wide.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204C8B8.c \
 *       --func func_0204C8B8 --addr 0x0204C8B8 --cc 1.1p1 --arm
 */
void func_0204C8B8(struct Xfer *x)
{
    DC_FlushRange(x->src, x->size);
    g_020A138C[x->kind](x->src, x->unk_04, x->size);
}




/*
 * The slot allocator for the 0xe4-byte display object: walk the owner's
 * array of `count` records and return the first whose word 0 is zero, or
 * fail the GF_ASSERT(0) at calct.c:5204 and return NULL.
 *
 * 0xe4 is not a power of two, so the index is a real `mul` against a
 * materialised element size rather than a shift; the size constant lands in
 * r0 on top of the owner pointer because the count and the array base are
 * both hoisted out of the loop before the first iteration and the owner is
 * dead from there on.  The `ble` guard is signed, which is what a plain
 * `int i` compared against a `u16` field gives: the field zero-extends into
 * an int and the comparison stays signed.
 *
 * The two `__FILE__`/expression strings are one object here, not two.  The
 * file-name string 0x020A7F74 has 92 pool witnesses image-wide, but the
 * expression string "0" at 0x020A7F7C is pooled only by this function, and
 * it is one character long, below the string class's minimum run, so
 * `string` cannot fix it from the preceding terminator either (which is
 * what docs/idioms/a-string-after-a-data-table-has-no-witness.md describes
 * from the other side).  Declaring this translation unit's string area as
 * a single object whose second member starts at +8, the length of
 * "calct.c" including its terminator, puts both relocations on the attested
 * base and takes the +8 from the C.  Same bytes, same two pool words.  See
 * docs/idioms/an-assert-expression-string-rides-the-file-name-symbol.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204C8E4.c \
 *       --func sub_0204C8E4 --addr 0x0204C8E4 --cc 1.1p1 --arm
 */
struct Actor *sub_0204C8E4(struct Bank *ow)
{
    int i;

    for (i = 0; i < ow->count; i++) {
        if (ow->actors[i].next == 0) {
            return &ow->actors[i];
        }
    }

    sub_02034714(s_FileName.file, 5204, s_FileName.expr0);
    return 0;
}




/*
 * Blocked at MATCH: all 72 concrete bytes are correct and sub_0204CEB4
 * resolves `matched`, but the call to func_0204CB44 (+0x0028) has no
 * witness: 0204CB44 has exactly one branch reference image wide, this
 * call, so no cut frees it. func_0204C944 itself was the blocker named in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt for func_0204BB8C; closing it
 * only traded one fan-in-1 blocker for another one level down
 * (func_0204CB44, 108 bytes, not otherwise investigated here).
 *
 * Guarded by the top nibble of the byte at +0xe (the low nibble is never
 * tested here, hence the `lsl #0x18; lsrs #0x1c` rather than a plain
 * `ldrb`/`ands`) and by the ring head at +0x04 being non-null. Then walk
 * that ring (the node's own +0x00 is its `next`, same shape as
 * func_0204BB8C's bank ring) running func_0204CB44 and sub_0204CEB4 (the
 * latter already matched, src/matched/sub_0204CEB4.c) over every member.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C944.c \
 *       --func func_0204C944 --addr 0x0204C944 --cc 1.1p1 --arm
 */
void func_0204C944(struct Bank *b)
{
    struct Actor *cur;

    if (b->mode == 0) {
        return;
    }

    cur = b->head;
    if (cur == 0) {
        return;
    }

    do {
        func_0204CB44(cur, b->unk_08);
        sub_0204CEB4(cur);
        cur = cur->next;
    } while (cur != b->head);
}




/*
 * Sorted insert into a circular doubly-linked list whose head pointer sits
 * at a0+4 and whose links are {next @0, prev @4}.  The empty list seeds a
 * self-loop; a first key below the head's key goes in front of the tail;
 * otherwise the average of the head and tail keys picks the half to search
 * and func_0204CA74/func_0204CAAC return the node to insert after.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204C98C.c \
 *       --func func_0204C98C --addr 0x0204C98C --cc 1.1p1
 */
void func_0204C98C(struct Bank *a0, struct Actor *a1)
{
    struct Actor *pos;

    if (a0->head == 0) {
        a0->head = a1;
        a1->next = a1;
        a0->head->prev = a1;
        return;
    }
    {
        u32 key = func_0204B838(a1);
        u32 headkey = func_0204B838(a0->head);
        u32 tailkey;
        u8  avg;

        if (key < headkey) {
            pos = a0->head->prev;
            a0->head = a1;
        } else {
            tailkey = func_0204B838(a0->head->prev);
            avg = (u8)((int)(headkey + tailkey) / 2);
            if (avg >= key) {
                pos = func_0204CA74(a0->head, key);
            } else {
                pos = func_0204CAAC(a0->head->prev, key);
            }
        }
    }
    a1->prev = pos;
    a1->next = pos->next;
    pos->next->prev = a1;
    pos->next = a1;
}




/*
 * Unlink a node from a doubly linked list whose head pointer lives at +4 of
 * the manager.  A node whose own forward pointer is itself is the only
 * entry, so the manager's head is cleared instead of taking the link.  Both
 * arms of that inner if write the head, which is why the store is a
 * conditional pair rather than one unconditional store.
 */
void func_0204CA30(struct Bank *m, struct Actor *l)
{
    if (m->head == l) {
        if (l->next == l) {
            m->head = 0;
        } else {
            m->head = l->next;
        }
    }
    l->next->prev = l->prev;
    l->prev->next = l->next;
    l->next = 0;
    l->prev = 0;
}




/*
 * Walk the circular list backwards from `head` and return the payload of
 * the first node whose key sorts strictly above `key`; if the walk comes
 * all the way round, the head's own payload is the answer.
 *
 * The list is circular, so the test is at the bottom and the loop is a
 * `do`/`while`: a `while` would have added an entry test the original does
 * not have.  `hi` rather than `gt` fixes the comparison as unsigned.  The
 * hit arm is two predicated instructions, `ldrhi` and `pophi`, so it never
 * reaches the shared tail.
 *
 * Its mirror image sub_0204CAAC walks the same list forwards, returns the
 * node instead of the payload and inverts the condition.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CA74.c \
 *       --func sub_0204CA74 --addr 0x0204CA74 --cc 1.1p1 --arm
 */
void *sub_0204CA74(struct Actor *head, u32 key)
{
    struct Actor *n = head;

    do {
        if (func_0204B838(n) > key) {
            return n->prev;
        }
        n = n->next;
    } while (n != head);

    return head->prev;
}




/*
 * The forward half of the pair that opens this packet: walk the circular
 * list through its `next` links and return the first node whose key does
 * not sort above `key`, falling back on the head's `prev` when the walk
 * comes all the way round.
 *
 * Where sub_0204CA74 returns a payload, this one returns the node itself,
 * which is the whole difference between `ldrhi r0, [r4, #4]` there and
 * `movls r0, r4` here.  The polarity is the other way round too: `ls`, the
 * complement of the sibling's `hi`.
 *
 * The two are separate translation units in the image, not one: each gets
 * its own `bl 0x204b838` and its own copy of the loop.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CAAC.c \
 *       --func sub_0204CAAC --addr 0x0204CAAC --cc 1.1p1 --arm
 */
struct Actor *sub_0204CAAC(struct Actor *head, u32 key)
{
    struct Actor *n = head;

    do {
        if (func_0204B838(n) <= key) {
            return n;
        }
        n = n->prev;
    } while (n != head);

    return head->next;
}




/*
 * The constructor for the 0xe4-byte object this packet operates on: wipe
 * it, initialise the two embedded sub-objects at +0x1c and +0x40, set the
 * three 0x1000 scale fields, and fix up the flag word at +0x60.
 *
 * The flag word is one load and one store for three separate bitfield
 * assignments, which is the whole reason this function is worth reading:
 * the 4-bit field at bit 8 is a read-modify-write (`lsl #20; lsr #28; orr
 * #1; lsl #28; ... lsr #20` around a `bic #0xf00`), while the two fields
 * being set to zero collapse into plain `bic`s of their masks.  Only the
 * field whose new value depends on its old one pays for the extract and
 * reinsert.
 *
 * 0x1000 is materialised once into r4 and reused for all three stores; the
 * compiler spreads those stores across the two calls rather than keeping
 * them together, so their position in the listing is not their position in
 * the source.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CAE4.c \
 *       --func sub_0204CAE4 --addr 0x0204CAE4 --cc 1.1p1 --arm
 */
void sub_0204CAE4(struct Actor *o)
{
    MI_CpuFill8(o, 0, 0xe4);
    o->unk_54 = 0x1000;
    func_02063790(o->mtx.w);
    func_020637D4(o->xform.w);
    o->scale.x = 0x1000;
    o->scale.y = 0x1000;
    o->mode |= 1;
    o->unk_60_31 = 0;
    o->unk_60_18 = 0;
}




/*
 * Blocked at MATCH on the `label`/`matched` classes: all 108 concrete bytes
 * are right, but every one of the six callees has exactly one branch
 * reference image-wide and it is the call in this function, so none of the
 * six can be witnessed and no cut frees any of them.  Four of the six are
 * now closed and the file is at 4 of 6 relocation sites resolved:
 *
 *   func_02066748  0x02066748   12 bytes  -- veneer, resolves `veneer`
 *   func_02065BD0  0x02065BD0  168 bytes  -- OPEN, docs/notes/func_02065BD0.c.txt
 *   func_0204CBB0  0x0204CBB0  188 bytes  -- closed, resolves `matched`
 *   func_0204BA7C  0x0204BA7C  112 bytes  -- closed, resolves `matched`
 *   func_0204CC6C  0x0204CC6C  584 bytes  -- OPEN, soft-float, multi-function
 *   func_02065C78  0x02065C78  108 bytes  -- closed, resolves `matched`
 *
 * func_02066748 is not decompilable and never will be.  It is a twelve-byte
 * ARM linker veneer, `ldr ip, [pc]; bx ip; .word 0x02067AA0`, and the
 * `veneer` attestation class used to refuse it because 0x02067AA0 was an
 * unlabelled three-instruction leaf (`str r1, [r0, #8]; str r2, [r0, #0xc];
 * bx lr`) that `disasm.py` never labels, so `names_known_code()` failed.  The
 * integrator seeded 0x02067AA0 into layout/function_starts.txt before wave
 * 25 and the site now resolves `veneer` with no change to any source file,
 * exactly as
 * docs/idioms/a-veneer-attests-nothing-while-its-target-is-an-unlabelled-leaf.md
 * predicted.
 *
 * What remains is func_02065BD0, a 24-byte codegen near miss over one
 * zero-register allocation (the note names every spelling tried), and
 * func_0204CC6C, 584 bytes of soft-float record publishing that nobody has
 * attempted yet.  This function is itself the sole blocker for
 * src/pending/func_0204C944.c, which is the sole blocker named in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt for src/pending/func_0204BB8C.c,
 * which is one of the two blockers of src/pending/sub_0204A600.c (the other
 * is 0x02066998).
 *
 * Per-element teardown.  Guarded by bit 26 of the flag word at +0x60; the
 * two values handed to func_0204BA7C are bits 12-15 (narrowed to u8, which
 * is what the otherwise redundant `and r1, r1, #0xff` after the shift pair
 * records) and bit 31 of the same word, read through one load.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204CB44.c \
 *       --func func_0204CB44 --addr 0x0204CB44 --cc 1.1p1 --arm
 */
void func_0204CB44(struct Actor *e, struct OamState *arg)
{
    if (e->enabled == 0)
        return;

    func_02066748((int *)arg, (int)&e->mtx, (int)&e->xform);
    func_02065BD0(arg);
    func_0204CBB0(e, arg);
    func_0204BA7C((u32)&e->xform, (u8)e->unk_60_12, e->unk_60_31);
    func_0204CC6C(e);
    func_02065C78();
}



/*
 * Publishes five bitfields of the element's flag word at +0x60 into the
 * render record: the two-bit mode at bits 18-19 through func_02067AB8, the
 * two corner values through func_02067B78 when that mode is zero, then the
 * four-bit value at bits 8-11 into +0x84, bit 24 into +0x90, bits 22-23 into
 * +0x8c and bits 16-17 into +0x88.
 *
 * The +0x84 store is three instructions of arithmetic that computes nothing:
 * `(v | m) & ~(~m)` is `m`, and mwccarm folds every direct spelling of it
 * away.  The cast between the two complements, and the statement boundaries
 * that put the first `mvn` ahead of the `orr`, are what keep all five
 * instructions:
 * docs/idioms/a-cast-between-two-complements-is-what-keeps-both-mvns.md.
 *
 * Decompiled so that it becomes a `matched` witness for the call at
 * 0x0204CB44+0x3c (src/pending/func_0204CB44.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204CBB0.c \
 *       --func func_0204CBB0 --addr 0x0204CBB0 --cc 1.1p1 --arm
 */
void func_0204CBB0(struct Actor *e, struct OamState *r)
{
    u32 a, b, v;
    int n;
    u8  m;

    func_02067AB8(r, e->unk_60_18);

    if (e->unk_60_18 == 0) {
        a = func_0204B658(e, 0);
        b = func_0204B658(e, 1);
        func_02067B78(r, b, a);
    }

    m = e->mode;
    n = ~m;
    v = r->unk_84 | m;
    r->unk_84 = v & ~(u32)n;
    r->unk_90 = e->unk_60_24;
    r->unk_8c = e->unk_60_22;
    r->unk_88 = (u8)e->unk_60_16;
}



/*
 * Byte-correct, MATCH-capped.  NOT in the manifest; see src/pending/README.md.
 *
 * All 584 concrete bytes are right; 36 of 40 relocation sites resolve.  The
 * four that do not are the three fan-in-1 callees of the trailing switch:
 *
 *   func_02065CE4  0x02065CE4  104 bytes  -- OPEN (pkt_02065CE4), 4 bytes
 *                                            from EXACT, see
 *                                            docs/notes/func_02065CE4.c.txt
 *   func_02065D4C  0x02065D4C  104 bytes  -- OPEN (pkt_02065D4C), twin of
 *                                            the above, same near miss
 *   func_02066080  0x02066080  220 bytes  -- OPEN (pkt_02065D4C), unattempted
 *
 * Each has exactly one branch reference image-wide and it is the call in this
 * function, so `label` cannot see them and a single function cannot be split.
 * Closing all three turns this file EXACT and makes it the `matched` witness
 * that src/pending/func_0204CB44.c's last open site needs.
 *
 * What it does.  Publishes the cell actor's two coordinate pairs into the
 * render state.  Each s16 field is converted with the same inlined helper:
 * the fixed-point value `v << 12` is turned into a float and rounded half
 * away from zero, `(f32)(v << 12) + 0.5f` for a positive v and
 * `(f32)(v << 12) - 0.5f` otherwise, then truncated back to s32 by the
 * soft-float runtime.  The
 * second pair is published only when the 2-bit field at 0x60 bits 18-19 is
 * set, is followed by a scale (func_020664CC, 0x1000 == FX32_ONE) and a
 * rotation read as a pair of s16 from the table at 0x020A1B38 indexed by
 * `unk_58 >> 4`, and is then undone by publishing the negated pair.  The
 * trailing switch on +0x68 picks the draw path; case 0 splits again on bit 0
 * of +0x64.
 *
 * The add in the first arm is the expression form: mwccarm canonicalises the
 * commutative add so the constant becomes the first operand and the call is
 * `_fadd(0.5f, t)`, which is what the image has.  See
 * docs/idioms/a-soft-float-add-puts-the-constant-first-unless-it-is-a-compound-assignment.md
 * (this file was matched earlier as `0.5f - t' / `t += 0.5f' against swapped
 * _fsub/_fadd addresses; 0x0209C95C is the add, 0x0209CB8C the subtract).
 */
void func_0204CC6C(struct Actor *o)
{
    f32 a, b;
    s32 i;

    CONV(a, o->pos.y);
    CONV(b, o->pos.x);
    func_020663D0((s32)b, (s32)a, 0);

    if (o->unk_60_18 != 0) {
        CONV(a, o->origin.y);
        CONV(b, o->origin.x);
        func_020663D0((s32)b, (s32)a, 0);

        func_020664CC(o->scale.x, o->scale.y, 0x1000);

        i = o->angle >> 4;
        func_02066620(g_020A1B38[i * 2], g_020A1B38[i * 2 + 1]);

        CONV(a, o->origin.y);
        CONV(b, o->origin.x);
        func_020663D0(-(s32)b, -(s32)a, 0);
    }

    switch (o->ctl.kind) {
    case 0:
        if (o->hidden == 1) {
            func_02065CE4((void *)o->ctl.unk_3c);
        } else {
            func_02065D4C(o->ctl.anim);
        }
        break;
    case 1:
        func_02065D4C(o->ctl.anim);
        break;
    case 2:
        func_02066080((struct Obj02066080 *)o->ctl.anim);
        break;
    }
}


/*
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204CC6C.c \
 *       --func func_0204CC6C --addr 0x0204CC6C --cc 1.1p1 --arm
 */


/*
 * Run the object through sub_0204B8D4, but only when the flag word at +0x60
 * has its seventh bit set.
 *
 * `lsl #6; lsr #31` with nothing that could be a type conversion is a
 * one-bit unsigned bitfield
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).  The
 * pair names the bit from the top: `lsl #6` says six bits sit above it, so
 * it is bit 25 counting from the least significant end, and this front end
 * allocates bitfields from the least significant end upward, which means
 * twenty-five bits of padding must be declared before it.  Declaring the
 * six-bit pad first instead gives `lsl #25` and is the whole difference
 * between the two spellings.  The guard is `== 1`, not a plain truth test, which
 * is why the comparison survives as an explicit `cmp r1, #1` instead of
 * folding into the shift's flags.
 *
 * sub_0204B8D4 takes one argument; the `ldr r1, [r0, #0x54]` that precedes
 * the call is a second, forwarded value this function reads but that callee
 * ignores (src/pending/sub_0204B8D4.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CEB4.c \
 *       --func sub_0204CEB4 --addr 0x0204CEB4 --cc 1.1p1 --arm
 */
void sub_0204CEB4(struct Actor *o)
{
    if (o->unk_60_25 == 1) {
        sub_0204B8D4(o, o->unk_54);
    }
}



/*
 * Apply the seven-field request to the object: the two signed halfwords at
 * +0 and +2 are the two axes of the same setter, selected by a trailing
 * 0/1; the byte at +6 replaces the low eight bits of the flag word at
 * +0x60; the byte at +7 and the halfword at +4 go to their own setters, and
 * sub_0204B95C commits the result.
 *
 * `ldrsh` with no immediate offset form is the only evidence that the first
 * two fields are `s16` rather than `u16`
 * (docs/idioms/ldrsh-register-offset-is-signedness.md); the third is
 * `ldrh`, so the request really does mix the two.
 *
 * The flag-word update is a plain `bic #0xff` / `orr`, with no shift on
 * either side, which places the field at bit 0 and fixes its width at
 * eight: the value comes from an `ldrb`, so nothing has to mask it first.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CED8.c \
 *       --func sub_0204CED8 --addr 0x0204CED8 --cc 1.1p1 --arm
 */
void sub_0204CED8(struct Actor *o, const struct ActorInit *r, u32 space)
{
    sub_0204B49C(o, r->x, space, 0);
    sub_0204B49C(o, r->y, space, 1);
    o->unk_60_00 = r->unk_06;
    sub_0204B84C(o, r->unk_07);
    sub_0204B878(o, r->unk_04);
    sub_0204B95C(o);
}



/*
 * Apply a four-field request to the object: the two words at +4 and +8 go
 * through the setters at 0x0204B784 and 0x0204B728, the two halfwords at +0
 * and +2 are copied straight into the object's +0x5c/+0x5e pair.
 *
 * Both halfwords are loaded before either is stored, which is the ordinary
 * effect of the two loads having no dependence on the stores: reading them
 * one at a time would have interleaved `ldrh`/`strh`.
 *
 * Was capped at MATCH: the PC24 site at +0x1c names 0x0204B728 and this is
 * that address's only branch site anywhere in the image, so `label` has
 * nothing outside the compared range to point at, and the two functions are
 * not contiguous, so no unit can make the site `local` either.  0x0204B728
 * is now EXACT in src/matched/sub_0204B728.c (the blocker there was one
 * `const` on the source pointer of its closing struct assignment, see
 * docs/idioms/const-source-pointer-schedules-the-block-load-first.md), and
 * the site resolves `matched` against it.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CF40.c \
 *       --func sub_0204CF40 --addr 0x0204CF40 --cc 1.1p1 --arm
 */
void sub_0204CF40(struct Actor *o, const struct ActorReq *r)
{
    sub_0204B784((char *)o, (const struct Mtx *)r->cell_rec);
    sub_0204B728(o, (const struct Xform *)r->anim_rec);
    o->unk_5c = r->cell;
    o->unk_5e = r->anim;
}



/*
 * Measure entry `id`, writing the two halfwords of the answer through
 * `out`.  The sentinel id 0xFFFF means "nothing", and zeroes both.
 *
 * 0xFFFF costs a pool word because it is not an ARM rotated immediate
 * (docs/idioms/out-of-range-immediate-subtract-costs-a-pool-word.md is the
 * same constraint on the other side of the comparison).  The whole early
 * return is predicated: one `moveq` feeding two `strheq` and a `popeq`,
 * with no branch anywhere.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CF74.c \
 *       --func sub_0204CF74 --addr 0x0204CF74 --cc 1.1p1 --arm
 */
void sub_0204CF74(struct Actor *o, u32 id, u16 *out)
{
    if (id == 0xFFFF) {
        out[0] = 0;
        out[1] = 0;
        return;
    }
    sub_0204B0C8(o->owner->unk_08, id, (struct Vec2 *)out);
}



/*
 * The seven-argument initialiser for the 0x20-byte request record: four
 * arguments arrive in registers, three more off the caller's stack, and the
 * last three words of the record are cleared.
 *
 * The four-register push is not about callee-saved state, it is the cost of
 * having three stack arguments to stage; [sp, #0x10] is the first of them,
 * sixteen bytes past the pushed frame.  `stmib r0, {r3, r5}` is the
 * compiler folding the +4 and +8 stores once both values happen to sit in
 * ascending registers, not a struct copy
 * (docs/idioms/aggregate-assignment-is-ldm-stm.md describes the other case).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CFA4.c \
 *       --func sub_0204CFA4 --addr 0x0204CFA4 --cc 1.1p1 --arm
 */
void sub_0204CFA4(struct ActorReq *r, u16 a, u16 b, struct Slot *c, struct Slot2 *d, void *e, struct AnimBank *f)
{
    r->cell = a;
    r->anim = b;
    r->cell_rec = c;
    r->anim_rec = d;
    r->unk_0c = e;
    r->unk_10 = f;
    r->unk_14 = 0;
    r->unk_18 = 0;
    r->unk_1c = 0;
}



/*
 * Allocate one object out of the owner's pool, back-link it, initialise its
 * embedded sub-object at +0x68 from the request, apply the two field
 * groups, register it with the owner and enable it.
 *
 * Five of the six callees want the object pointer and two want the owner,
 * so both are pinned for the whole body; that is what forces the
 * five-callee-saved push.  The fifth argument is only read once, straight
 * out of this function's own stack slot at [sp, #0x18] (five pushed
 * registers plus lr above it), and never spilled.
 *
 * Was parked at MATCH.  Three of the six sites name functions whose only
 * branch site image-wide is the one here, so each needed its own EXACT
 * entry to act as a `matched` witness; all three now have one and the C in
 * this file is unchanged.
 *
 *   0x0204C8E4, the allocator, is src/matched/sub_0204C8E4.c.  Its own
 *     blocker was the GF_ASSERT expression string, folded onto the
 *     file-name symbol
 *     (docs/idioms/an-assert-expression-string-rides-the-file-name-symbol.md).
 *   0x0204D0C4, the sub-object initialiser, is src/matched/sub_0204D0C4.c.
 *     Its handler table 0x020A13DC is row 6 of the array based at
 *     0x020A1394, not a symbol of its own.
 *   0x0204CF40 is src/matched/sub_0204CF40.c, which unstuck once
 *     0x0204B728 landed (one `const` on a struct assignment's source).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204CFDC.c \
 *       --func sub_0204CFDC --addr 0x0204CFDC --cc 1.1p1 --arm
 */
struct Actor *sub_0204CFDC(struct Bank *owner, const struct ActorInit *r, struct ActorReq *c, u32 space, u16 e)
{
    struct Actor *o = sub_0204C8E4(owner);

    o->owner = owner;
    sub_0204D0C4(&o->ctl, c, e);
    sub_0204CED8(o, r, space);
    sub_0204CF40(o, c);
    sub_0204C98C(owner, o);
    sub_0204B3DC(o, 1);
    return o;
}






/*
 * Build the object with sub_0204CFDC, then apply the six remaining fields
 * of the request to it: two axes share sub_0204B59C and two more share
 * sub_0204B5D4, selected by a trailing 0/1 argument, and the last two are
 * plain halfwords.
 *
 * The fifth argument is forwarded untouched: `ldrh r4, [sp, #0x18]` reads
 * this function's own stack argument (six pushed registers above it) and
 * `str r4, [sp]` writes it straight back out as sub_0204CFDC's, with r0-r3
 * never disturbed in between.
 *
 * The literals 0 and 1 are each materialised once, into r5 and r4, and
 * reused across four call sites rather than rematerialised per call
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md,
 * the "an argument shares it" case).  The `s16` field at +8 is loaded twice
 * with `ldrsh`, once per call, because the intervening call could have
 * written it.
 *
 * Was parked at MATCH.  0x0204B59C is reached from exactly two `bl` sites
 * image-wide, 0x0204D06C and 0x0204D080, and both of them are the two call
 * sites above, so no outside `label` witness exists and no cut can create
 * one: a split that removed this function would remove both sites at once.
 * The route taken instead was to decompile 0x0204B59C itself, which is the
 * first of three unlabelled leaf accessors now covered by
 * src/matched/unit_0204B59C.c; both sites here resolve `matched` against
 * that entry.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D048.c \
 *       --func sub_0204D048 --addr 0x0204D048 --cc 1.1p1 --arm
 */
struct Actor *sub_0204D048(struct Bank *owner, const struct ActorInit *r, struct ActorReq *c, u32 space, u16 e)
{
    struct Actor *o = sub_0204CFDC(owner, r, c, space, e);

    sub_0204B59C(o, r->unk_08, 0);
    sub_0204B59C(o, r->unk_08, 1);
    sub_0204B5D4(o, r->unk_0c, 0);
    sub_0204B5D4(o, r->unk_10, 1);
    sub_0204B5F4(o, r->unk_14);
    sub_0204B570(o, r->unk_16);
    return o;
}





extern void *(*const gUnk_020A1394[][3])();






/*
 * Constructor for the 0x7c-byte sub-object embedded at +0x68 of the
 * 0x0204Bxxx owner, and the counterpart of the destructor at 0x0204D104:
 * derive the kind tag from the request with sub_0204D134, stamp it into
 * word 0, then run row 6 of the handler table at 0x020A1394 with the object
 * and the two forwarded arguments.
 *
 * The kind stays in ip across the table load and is stored only just before
 * the `blx`, which is the ordinary effect of the store having no consumer:
 * the index is needed for the table load either way, so the store sinks to
 * the last position that still precedes the call.
 *
 * The table is row 6 of the one eight-by-three array based at 0x020A1394;
 * see src/matched/func_0204D324.c for the row map and why the base rather
 * than the row is the relocation's symbol.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D0C4.c \
 *       --func sub_0204D0C4 --addr 0x0204D0C4 --cc 1.1p1 --arm
 */
void sub_0204D0C4(struct Ctl *s, void *c, u32 e)
{
    u32 kind = sub_0204D134(c);

    s->kind = kind;
    gUnk_020A1394[6][kind](s, c, e);
}










void sub_0204D104(struct Ctl *p)
{
    gUnk_020A1394[5][p->kind](p);
    MI_CpuFill8(p, 0, 0x7c);
}






/*
 * Classify a request into the small index the sibling sub_0204D0C4 uses to
 * pick a handler out of its table: 1 if the pointer at +0x1c is set, else 2
 * if the one at +0x14 is, else 0.  A leaf with no prologue at all, so
 * disasm.py never labelled it.
 *
 * The first arm gets its own `bxne lr` while the last two share one exit as
 * a `movne`/`moveq` pair: that is what an early `return` followed by a
 * two-way tail looks like once the compiler has run out of conditional
 * slots to fold the first test into
 * (docs/idioms/initialise-the-result-before-the-input-or-every-arm-duplicates-the-return.md
 * read in reverse, the result here is not initialised first).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D134.c \
 *       --func sub_0204D134 --addr 0x0204D134 --cc 1.1p1 --arm
 */
s32 sub_0204D134(const struct ActorReq *r)
{
    if (r->unk_1c != 0) {
        return 1;
    }
    if (r->unk_14 != 0) {
        return 2;
    }
    return 0;
}






/*
 * Copy the source's two handles into the object's +4/+8 pair, then bind the
 * record at +0xc to them.
 *
 * The +4 field is read back from memory for sub_0206428C's third argument
 * rather than reused out of r2: the intervening call to sub_020627D8 could
 * alias it, so the cached load does not survive
 * (docs/idioms/const-pointer-lets-a-field-load-survive-a-store.md, the case
 * without the `const`).
 *
 * sub_020627D8 is called here with an explicit zero in r1, where
 * src/matched/sub_0204D340.c leaves r1 untouched: the two call sites
 * disagree about the arity, and the zero is written out only because this
 * one needs it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D158.c \
 *       --func sub_0204D158 --addr 0x0204D158 --cc 1.1p1 --arm
 */
void sub_0204D158(struct Ctl *o, const struct ActorReq *s)
{
    o->unk_04 = s->unk_0c;
    o->unk_08 = s->unk_10;
    sub_0206428C((char *)o->anim, (int)sub_020627D8(o->unk_08, 0), o->unk_04);
}






/*
 * Record builder in clact.c.  Wave 15 (register-tie lane): the last 10
 * bytes (the image sinks `mov sb, r0` above the two a->f0c/a->f10 loads)
 * close with `const struct A *a`.  The read-only source pointer lets the
 * parameter copy of p be scheduled before the loads, freeing r0 for the
 * stmib pair {r0, r1}.  The rest is the 2026-09-22 source from
 * docs/notes/pkt_0204D18C.func_0204D224.c.txt: the nested t1/t0 block
 * (descending loads) for the stmib, and `two - 3` for the -1 argument.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D18C.c \
 *       --func func_0204D18C --addr 0x0204D18C --cc 1.1p1 --arm
 */
void func_0204D18C(struct Ctl *p, const struct ActorReq *a)
{
    u32 zero = 0;
    u32 two;
    u32 h0, h1, h2;
    struct ReqTail *r;

    {
        struct AnimBank *t1 = a->unk_10;
        void *t0 = a->unk_0c;
        p->unk_04 = t0;
        p->unk_08 = t1;
    }
    p->unk_64 = func_02066AE0();
    r = (struct ReqTail *)a->unk_1c;
    h0 = (u32)sub_020627D8(p->unk_08, zero);
    h1 = func_020637B4((int *)a->cell_rec, 1);
    two = 2;
    h2 = func_020637B4((int *)a->cell_rec, two);
    func_020642C8((char *)p->anim, h0, p->unk_04, p->unk_64,
                  two - 3, h1, h2, r->unk_14, zero, r->unk_10);
}






/*
 * Record constructor in clact.c.  Wave 15 (register-tie lane): EXACT* (the
 * listing extent runs over the unlabelled fill leaf 0x0204D2C8, filed as
 * src/matched/func_0204D2C8.c).  Two facts closed it:
 *  - the older 2-byte "best source" in
 *    docs/notes/pkt_0204D18C.func_0204D224.c.txt stored a1->f14 into +0x04
 *    and a1->f0c into +0x70, which is NOT what the image does (image: +0x04
 *    gets f0c, +0x70 gets f14).  The honest residue with the image's
 *    pairing was 9 bytes.
 *  - `const struct A *a1` with the four stores written straight from a1 and
 *    func_020648B4 fed a fresh a1->f14: the const source lets mwcc keep all
 *    four loads above the stores in field order and CSE the f14 re-read.
 *    The `volatile` device on +0x04 is no longer needed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D224.c \
 *       --func func_0204D224 --addr 0x0204D224 --cc 1.1p1 --arm
 */
void func_0204D224(struct Ctl *p, const struct ActorReq *a1, u32 heap)
{
    p->unk_04 = a1->unk_0c;
    p->unk_08 = a1->unk_10;
    p->unk_70 = a1->unk_14;
    p->unk_74 = a1->unk_18;

    p->unk_78 = sub_02030734(heap, func_020648B4((u32)a1->unk_14, 1), 0, s_clact_c, 0x171d);
    func_02064754((char *)p->anim, p->unk_78, p->unk_08, p->unk_04, p->unk_70, 1);
    sub_0206469C((struct Obj0206469C *)p->anim, sub_020627D8(p->unk_74, 0));
}






/*
 * Unlabelled leaf after func_0204D224 in clact.c: clears the 0x7c-byte
 * animation sub-object (the same fill sub_0204D2DC ends with), as a tail
 * call.  Filed as the witness that turns func_0204D224's EXACT* into EXACT
 * once 0x0204D2C8 is seeded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D2C8.c \
 *       --func func_0204D2C8 --addr 0x0204D2C8 --cc 1.1p1 --arm
 */
void func_0204D2C8(void *anim)
{
    MI_CpuFill8(anim, 0, 0x7c);
}






/*
 * Destructor for one variant of the 0x7c-byte 0x0204Cxxx/0x0204Dxxx
 * object: release the sub-resource whose handle lives at +0x64, then wipe
 * the whole record.  0x02082BCC is the SDK's byte fill (dest, value,
 * length); the 0x7c length is the object's own size, which the sibling
 * sub_0204D300 repeats verbatim for the +0x78 variant.
 *
 * Was capped at MATCH: the PC24 site at +0x0c names 0x02066B38 and this is
 * that address's only branch site anywhere in the image, so `label` has
 * nothing to point at and no split can create one from a single function.
 * 0x02066B38 is now EXACT in src/matched/sub_02066B38.c and the site
 * resolves `matched` against it.  The C in this file is unchanged.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D2DC.c \
 *       --func sub_0204D2DC --addr 0x0204D2DC --cc 1.1p1 --arm
 */
void sub_0204D2DC(struct Ctl *o)
{
    sub_02066B38((u32)o->unk_64);
    MI_CpuFill8(o, 0, 0x7c);
}






/*
 * The sibling of sub_0204D2DC: same destructor shape for the variant whose
 * owned resource hangs off +0x78 and is freed through the heap entry point
 * at 0x020307B0 rather than 0x02066B38.  The trailing wipe is the same
 * 0x7c-byte object fill.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D300.c \
 *       --func sub_0204D300 --addr 0x0204D300 --cc 1.1p1 --arm
 */
void sub_0204D300(struct Ctl *o)
{
    sub_020307B0(o->unk_78);
    MI_CpuFill8(o, 0, 0x7c);
}












/*
 * Dispatch on the object's kind word, passing the object and one forwarded
 * argument.
 *
 * The second parameter is real, not a leftover: the original steps over r1
 * entirely (kind in r3, table base in r2) where the one-parameter spelling
 * uses r2 and r1.  A register that the body never touches and never
 * reallocates is a live argument being forwarded.
 *
 * This file was previously parked at MATCH on the theory that the pool word
 * 0x020A13B8 named a table object of its own, which left the ABS32 site
 * with no witness: 0x020A13B8 appears in exactly one pool image-wide, this
 * function's own, and self-reference is refused.  It is not a table of its
 * own.  The words from 0x020A1394 onward are one two-dimensional array of
 * at least eleven rows of three handlers, indexed [operation][kind], and
 * the functions of this family each pin a different row:
 *
 *   row 0  0x020A1394   pooled at 0x0204D490
 *   row 1  0x020A13A0   pooled at 0x0204D45C
 *   row 3  0x020A13B8   pooled here
 *   row 5  0x020A13D0   pooled at 0x0204D130  (sub_0204D104)
 *   row 6  0x020A13DC   pooled at 0x0204D100
 *   row 7  0x020A13E8   pooled at 0x0204D428  (sub_0204D410)
 *   row 10 0x020A140C   pooled at 0x0204D3C4  (unit_0204D3C4.c)
 *
 * Declared that way the relocation names the array's base, 0x020A1394, and
 * the +0x24 is the row index coming from the C rather than from the bytes
 * under test; the base is attested `literal` by the pool word at 0x0204D490,
 * well outside this range.  Same bytes, same pool word, an honest witness.
 * See docs/idioms/pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D324.c \
 *       --func func_0204D324 --addr 0x0204D324 --cc 1.1p1 --arm
 */
void func_0204D324(struct Ctl *obj, u32 arg)
{
    gUnk_020A1394[3][obj->kind](obj, arg);
}






/*
 * One of this family's per-slot "apply" hooks: take the handle at +8,
 * resolve it through sub_020627D8, and feed the result to sub_0206434C
 * together with the embedded record at +0xc.  sub_0204D360 is a
 * byte-for-byte duplicate of this function at a different address (the two
 * differ only in their PC24 displacements), which is what a pair of
 * distinct table slots sharing one body looks like when neither was folded.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D340.c \
 *       --func sub_0204D340 --addr 0x0204D340 --cc 1.1p1 --arm
 */
void sub_0204D340(struct Ctl *o, u32 idx)
{
    sub_0206434C(o->anim, sub_020627D8(o->unk_08, idx));
}






/*
 * The second copy of sub_0204D340: same body, same two callees, emitted
 * again thirty-two bytes later.  Two adjacent dispatch-table slots each got
 * their own definition and nothing folded them, so the only difference
 * between the two functions in the image is the PC24 displacement.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D360.c \
 *       --func sub_0204D360 --addr 0x0204D360 --cc 1.1p1 --arm
 */
void sub_0204D360(struct Ctl *o, u32 idx)
{
    sub_0206434C(o->anim, sub_020627D8(o->unk_08, idx));
}






/*
 * The third member of the sub_0204D340 / sub_0204D360 trio, reading the
 * handle from +0x74 instead of +8 and finishing in sub_0206469C instead of
 * sub_0206434C.  The shared middle step, sub_020627D8 on the handle, is
 * what says these three are the same operation over different slots.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D380.c \
 *       --func sub_0204D380 --addr 0x0204D380 --cc 1.1p1 --arm
 */
void sub_0204D380(struct Ctl *o, u32 idx)
{
    sub_0206469C((struct Obj0206469C *)o->anim, sub_020627D8(o->unk_74, idx));
}





/*
 * Set the +0x10 field of the record sub_0204D410 resolves for this object,
 * then re-run the object through the sub_0204D3C4 dispatcher with a zero
 * second argument.  Both callees are themselves index-dispatch thunks
 * (`ldr r3,[r0]; ldr r2,[table, r3 lsl 2]; blx r2`), so this function is
 * the C-visible half of a virtual pair.
 *
 * The object pointer is kept in r5 across the first call rather than
 * recomputed, which is what forces the four-register push: r4 holds the
 * incoming second argument over the same call.
 *
 * This is the missing witness for src/pending/sub_0204B8C4.c, whose only
 * unresolved site is the ABS32 pool word naming 0x0204D3A0.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0204D3A0.c \
 *       --func sub_0204D3A0 --addr 0x0204D3A0 --cc 1.1p1 --arm
 */
void sub_0204D3A0(struct Ctl *o, u32 value)
{
    sub_0204D410(o)->unk_10 = value;
    sub_0204D3C4(o, 0);
}










void *sub_0204D3C4(struct Ctl *o, u32 arg)
{
    return gUnk_020A1394[10][o->kind](o, arg);
}





void sub_0204D3E0(struct Ctl *o, s32 frames)
{
    sub_02064364((struct CellAnim *)(o->anim), frames);
}





void sub_0204D3F0(struct Ctl *o, s32 frames)
{
    sub_02064364((struct CellAnim *)(o->anim), frames);
}





void sub_0204D400(struct Ctl *o, s32 frames)
{
    sub_020649D4((char *)o->anim, frames);
}










/*
 * One index-dispatch thunk plus the three handlers it dispatches to, 52
 * bytes end to end with no padding.  The object's first word is a small
 * kind index, and row 7 of the handler table at 0x020A1394 holds the three
 * implementations, which are all the same pointer adjustment to +0xc.
 * They save nothing, so disasm.py gives them no labels and they used to be
 * this function's `EXACT*` tail; as a unit they are four real entries.
 *
 * The register pair the load uses names the arity: this one allocates r2
 * then r1, leaving r1 free, so the thunk forwards only r0
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 * `blx` plus `push {r3, lr}` rather than a tail `bx` is the ordinary
 * non-tail form: the result is returned unchanged, which is what lets
 * sub_0204D3A0 write through it directly.
 *
 * This file was parked at MATCH* while 0x020A13E8 was read as a table
 * object of its own, which left the ABS32 without a witness.  It is row 7
 * of the one eight-by-three array based at 0x020A1394; see
 * src/matched/func_0204D324.c for the row map and the reasoning.  The base
 * is attested `literal` by the pool word at 0x0204D490, outside this range.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D410.c \
 *       --addr 0x0204D410 --arm
 */
struct Anim *sub_0204D410(struct Ctl *o)
{
    return gUnk_020A1394[7][o->kind](o);
}






void *sub_0204D42C(struct Ctl *o)
{
    return o->anim;
}






void *sub_0204D434(struct Ctl *o)
{
    return o->anim;
}






void *sub_0204D43C(struct Ctl *o)
{
    return o->anim;
}






/*
 * The same shape as src/matched/unit_0204D410.c one row over: the thunk
 * dispatches on the object's kind through row 1 of the handler table at
 * 0x020A1394, and the three row-1 handlers are again the +0xc pointer
 * adjustment.  Three unlabelled leaves folded into the unit with the thunk.
 *
 * The base is attested `literal` by the pool word at 0x0204D490, outside
 * this range; see src/matched/func_0204D324.c for the row map.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D444.c \
 *       --addr 0x0204D444 --arm
 */
struct Anim *sub_0204D444(struct Ctl *o)
{
    return gUnk_020A1394[1][o->kind](o);
}






void *sub_0204D460(struct Ctl *o)
{
    return o->anim;
}






void *sub_0204D468(struct Ctl *o)
{
    return o->anim;
}






void *sub_0204D470(struct Ctl *o)
{
    return o->anim;
}















/*
 * Row 0 of the eight-by-three handler table at 0x020A1394, the same shape as
 * src/matched/unit_0204D410.c (row 7), src/matched/unit_0204D444.c (row 1)
 * and src/matched/func_0204D324.c (row 3, and the row map).  Every concrete
 * byte is reproduced; the single unresolved site is the ABS32 in the pool.
 *
 * Blocked on: evidence class `literal`, and it can never be satisfied.  For
 * rows 1, 3, 5, 6 and 7 the pool word is base+0x0c..base+0x54, so some other
 * row's thunk holds a different word and the base is witnessed from outside.
 * Row 0's pool word *is* the array base, 0x020A1394, and `--suggest-split`
 * reports exactly one witness image-wide: this function's own relocation site
 * at 0x0204D490.  Self-reference is refused, so no cut can free it.  It would
 * become EXACT only if some future matched entry defines the table data at
 * 0x020A1394, or if a caller elsewhere is found that pools the bare base.
 *
 * The arity comes from the register pair, not from the call: the original
 * takes the kind in r3 and the table base in r2, which is the two-parameter
 * allocation (compare src/matched/func_0204D324.c).  The one-parameter
 * spelling allocates r2 then r1 and is a four-instruction diff.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D478.c \
 *       --func sub_0204D478 --addr 0x0204D478 --cc 1.1p1 --arm
 */
void *sub_0204D478(struct Ctl *o, u32 arg)
{
    return gUnk_020A1394[0][o->kind](o, arg);
}












/*
 * Two identical tail calls to the same callee with the argument biased by
 * 0xc.  Unlabelled leaves; the range 0x0204D494..0x0204D4B4 is contiguous.
 */
void func_0204D494(u8 *a0, u32 i)
{
    func_02064384((struct CellAnim *)(a0 + 0xc), i);
}












void func_0204D4A4(u8 *a0, u32 i)
{
    func_02064384((struct CellAnim *)(a0 + 0xc), i);
}











/*
 * note:     promoted 2026-09-21: the blocker named below, 0x02064AB4, was
 *           filed EXACT as src/matched/func_02064AB4.c (pin ../2.0/sp2) by the
 *           pkt_02064934 lane, so the sole ABS32 site now resolves `matched`.
 *
 * The third row-0 handler of the table at 0x020A1394 (row map in
 * src/matched/func_0204D324.c).  Same shape as the two in
 * src/matched/unit_0204D494.c, tail calling the +0xc subobject through a pool
 * word, but to a different target.  It saves nothing, so disasm.py gives it
 * no label.
 *
 * Was blocked on: no evidence class at all.  `--suggest-split` reported zero
 * witnesses image-wide for 0x02064AB4: nothing branches to it (so no `label`),
 * no other pool holds the word (so no `literal`), and it is inside the G2D
 * block that has no matched entry yet.  The address is reachable only through
 * this table row, which is why it never appears as a branch target.  It will
 * resolve as `matched` once the G2D function at 0x02064AB4 is decompiled, or
 * as `label` if an overlay turns out to call it directly.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D4B4.c \
 *       --func sub_0204D4B4 --addr 0x0204D4B4 --cc 1.1p1 --arm
 */
void sub_0204D4B4(struct Ctl *o, u32 i)
{
    sub_02064AB4((char *)o->anim, i);
}










/*
 * A dispatch thunk and the first two of the three handlers its table row
 * names, 60 bytes end to end.  Each handler steps the pointer past the
 * object's 0xc-byte header and tail-calls into the G2D layer; a tail call
 * is always a pool word and a `bx`, never a displacement branch, because
 * every function is its own section
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md).  The handlers save
 * nothing, so disasm.py gives them no labels; they are folded in here
 * rather than left as this thunk's `EXACT*` tail.
 *
 * The thunk forwards two arguments, not one: it allocates r3 then r2 for
 * the table load, leaving r1 alone, where the one-argument form in
 * src/matched/unit_0204D410.c allocates r2 then r1
 * (docs/idioms/a-forwarding-call-passes-one-argument-and-the-rest-are-leftovers.md).
 *
 * The third handler, sub_0204D500 at 0x0204D500, is deliberately left out
 * of the range: its tail-call target 0x02064B68 is named only by its own
 * pool word, so including it caps the whole unit at MATCH.  It is parked
 * byte-correct in src/pending/sub_0204D500.c, and it graduates when
 * 0x02064B68 does (docs/notes/sub_02064B68.c.txt).
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_0204D4C4.c \
 *       --addr 0x0204D4C4 --arm
 */
void sub_0204D4C4(struct Ctl *o, u32 arg)
{
    gUnk_020A7F3C[o->kind](o, arg);
}










void sub_0204D4E0(struct Ctl *o, u32 arg)
{
    sub_020643C4((struct MultiCellAnim *)(o->anim), arg);
}










void sub_0204D4F0(struct Ctl *o, u32 arg)
{
    sub_020643C4((struct MultiCellAnim *)(o->anim), arg);
}









/*
 * The third handler of the row that src/matched/unit_0204D4C4.c dispatches
 * through: step the pointer past the object's 0xc-byte header and tail-call
 * into the G2D layer, forwarding the second argument untouched.
 *
 * Byte-correct, capped at MATCH.  The tail call is a pool word and a `bx`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md), so the site is an ABS32
 * naming 0x02064B68, and that address is named by no other pool word and by
 * no branch anywhere in the image: `label`, `literal` and `veneer` all have
 * nothing outside this range.  The one route left is an EXACT entry for
 * 0x02064B68 itself acting as a `matched` witness; that function is a
 * 168-byte two-armed cell/node walk which is four transposed instructions
 * away from matching, recorded in docs/notes/sub_02064B68.c.txt.
 *
 * Kept out of unit_0204D4C4.c for exactly this reason: folding it back in
 * would cap that whole range at MATCH for one unattestable word.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/sub_0204D500.c \
 *       --func sub_0204D500 --addr 0x0204D500 --cc 1.1p1 --arm
 */
void sub_0204D500(struct Ctl *o, u32 arg)
{
    sub_02064B68((o->anim), (void *)arg);
}









/*
 * Closes the clact.c fan-in-1 blocker documented in
 * docs/notes/clact_c_fan_in_1_blockers.c.txt: func_0204B9A0 (its only
 * caller image wide) forwards its argument unchanged.
 *
 * Dispatch through a function-pointer table indexed by the mode word at
 * +0x00 of the argument; the call itself is an indirect `blx` (no PC24
 * relocation to attest), but the table base at 0x020A7F48 is an ABS32
 * literal with no second reference anywhere in the ARM9 image, so this
 * stays MATCH regardless of the C.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204D510.c \
 *       --func func_0204D510 --addr 0x0204D510 --cc 1.1p1 --arm
 */
void func_0204D510(struct Ctl *c)
{
    g_DispatchTable_0204D510[c->kind](c);
}








void func_0204D52C(void *p){ func_020643A4((struct CellAnim *)((char *)p + 0xc)); }







/*
 * The same 0xc-biased tail call to the other callee of the pair.
 */
void func_0204D53C(u8 *a0)
{
    func_020643A4((struct CellAnim *)(a0 + 0xc));
}






/*
 * Tear the actor down and release the sub-object at +0x40: func_0204D52C on
 * the actor itself, then func_02064C10 on the tail.
 *
 * Both call sites resolve from `matched` witnesses, which is what this file
 * waited for while it sat parked in src/pending/ with both PC24s wildcarded.
 * The trailing star is the listing extent only: the next func_ label after
 * 0x0204D54C is 540 bytes away, so the harness compares the 32 bytes this
 * body compiles to and reports the disagreement rather than a concrete diff.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D54C.c \
 *       --func func_0204D54C --addr 0x0204D54C --cc 1.1p1 --arm
 */
void func_0204D54C(void *p)
{
    func_0204D52C(p);
    func_02064C10((struct Obj02064C10 *)((u8 *)p + 0x40));
}





void *func_0204D564(ClactObj *o, u32 idx)
{
    ClactBlk *b = o->f08->blk14;
    ClactTbl *t;
    if (b == 0 || b->tag != 0x55414154) {
        b = 0;
    }
    t = b != 0 ? &b->tbl : 0;
    if (t != 0) {
        if ((u16)idx < t->count) {
            return t->items + (u16)idx * 12;
        }
        return 0;
    }
    return 0;
}





void *func_0204D5CC(ClactObj *o, u32 idx)
{
    ClactBlk *b = o->f08->blk14;
    ClactTbl *t;
    if (b == 0 || b->tag != 0x55414154) {
        b = 0;
    }
    t = b != 0 ? &b->tbl : 0;
    if (t != 0) {
        if ((u16)idx < t->count) {
            return t->items + (u16)idx * 12;
        }
        return 0;
    }
    return 0;
}





void *func_0204D634(ClactObj *o, u32 idx)
{
    ClactBlk *b = o->f74->blk14;
    ClactTbl *t;
    if (b == 0 || b->tag != 0x55414154) {
        b = 0;
    }
    t = b != 0 ? &b->tbl : 0;
    if (t != 0) {
        if ((u16)idx < t->count) {
            return t->items + (u16)idx * 12;
        }
        return 0;
    }
    return 0;
}





ClactTbl *func_0204D69C(ClactObj *o)
{
    ClactBlk *b = o->f04->blk14;
    if (b == 0 || b->tag != 0x55434154) {
        b = 0;
    }
    return b != 0 ? &b->tbl : 0;
}





ClactTbl *func_0204D6D4(ClactObj *o)
{
    ClactBlk *b = o->f04->blk14;
    if (b == 0 || b->tag != 0x55434154) {
        b = 0;
    }
    return b != 0 ? &b->tbl : 0;
}





ClactTbl *func_0204D70C(ClactObj *o)
{
    ClactBlk *b = o->f70->blk10;
    if (b == 0 || b->tag != 0x55434154) {
        b = 0;
    }
    return b != 0 ? &b->tbl : 0;
}





u16 func_0204D744(ClactObj *o)
{
    return *(u16 *)o->f08;
}





u16 func_0204D750(ClactObj *o)
{
    return *(u16 *)o->f08;
}





u16 func_0204D75C(ClactObj *o)
{
    return *(u16 *)o->f74;
}













/*
 * Apply one animation command record to the handle behind the cell actor's
 * +0x68 sub-object.  The opcode is the u16 at +0 of the record; 0 and 2 both
 * call func_02063000 with a different mode, 1 calls func_02063018 with the
 * record's own u16 at +2 as its last argument.
 *
 * Three cases dense from zero, yet no halfword table: the compiler emits a
 * compare chain because the arms are all tail calls with no shared code, so
 * the table would cost more than the three compares
 * (docs/idioms/dense-switch-is-a-pc-relative-halfword-table.md is the case
 * where it does build one).  The compare chain runs 0, 1, 2 in case-label
 * order whatever the source does, but the arm *blocks* are laid out in source
 * order, so the cases have to be written 0, 2, 1 to put case 1's block last.
 * That is the only thing separating this from the image: with the arms in
 * numeric order the two `beq` displacements swap and fourteen bytes differ.
 *
 * `ldmib r4, {r2, r3}` is not a struct copy, it is the compiler merging the
 * two consecutive word loads at +4 and +8 that feed argument registers three
 * and four.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D768.c \
 *       --func func_0204D768 --addr 0x0204D768 --cc 1.1p1 --arm
 */
void func_0204D768(struct Ctl *c, const struct Cmd *cmd)
{
    void *h = func_0204D410(c);

    switch (cmd->op) {
    case 0:
        func_02063000((int)h, 1, cmd->arg1, cmd->arg2);
        break;
    case 2:
        func_02063000((int)h, 3, cmd->arg1, cmd->arg2);
        break;
    case 1:
        func_02063018(h, cmd->arg1, cmd->arg2, cmd->arg0);
        break;
    }
}













/*
 * Reset the animation handle behind the cell actor's +0x68 sub-object: the
 * all-zero form of the case-0 arm of func_0204D768 next door.
 *
 * The three zero arguments are one `mov r1, #0` and two register copies, not
 * three `mov`s of an immediate
 * (docs/idioms/a-small-constant-is-rematerialised-off-a-zero-register-unless-an-argument-shares-it.md).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D7C4.c \
 *       --func func_0204D7C4 --addr 0x0204D7C4 --cc 1.1p1 --arm
 */
void func_0204D7C4(struct Ctl *c)
{
    func_02063000((int)func_0204D410(c), 0, 0, 0);
}













/*
 * Blocked at MATCH: all 204 concrete bytes are correct; func_0204DA5C,
 * func_0204DCA8 and func_0204E01C all now resolve `matched` off their own
 * manifest entries (src/matched/func_0204DA5C.c, func_0204DCA8.c). Only
 * func_02034558 (+0x0038 and +0x005C) is left, and it cannot reach EXACT
 * from here: see docs/notes/func_02034558.c.txt. Its only two branch
 * references image wide are the two calls in this function, so no cut
 * frees it, and decompiling it does not help either, since it is itself
 * blocked by sub_02034520's unwitnessed g_FlagTable literal, one level
 * further down.
 *
 * Build the cell-actor system's five resource managers out of the caller's
 * config and capacity records, then keep a copy of the six capacities in the
 * output block at +0x14..+0x1e.
 *
 * The first two managers are the same func_02034558 with a different pair of
 * config words; its fifth argument goes through the four-byte stack slot the
 * prologue reserves, which is the whole reason for the `sub sp, sp, #4`.  The
 * shared constant 1 is hoisted into r8 rather than re-materialised at each
 * call, because both calls want it in r1 and nothing in between clobbers it.
 *
 * The two capacities that reach func_02034558 are scaled by 32 with a plain
 * `lsl` on the zero-extended halfword; the six stores at the end are six
 * separate `strh`, not an aggregate copy, so they are written as six field
 * assignments (docs/idioms/aggregate-assignment-is-ldm-stm.md is the shape
 * that would have collapsed them).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204D7E0.c \
 *       --func func_0204D7E0 --addr 0x0204D7E0 --cc 1.1p1 --arm
 */
void func_0204D7E0(struct Res *res, u32 heapId, const struct ResCfg *cfg,
                   const struct Caps *caps)
{
    res->tiles    = func_02034558(heapId, 1, cfg->unk_10, caps->tiles << 5,
                                  cfg->unk_28);
    res->palettes = func_02034558(heapId, 1, cfg->unk_18, caps->palettes << 5,
                                  cfg->unk_2c);
    res->cell     = func_0204DA5C(heapId, caps->cell);
    res->anim     = func_0204DCA8(heapId, caps->anim);
    res->pattern  = func_0204E01C(heapId, caps->pattern);

    res->n_cell     = caps->cell;
    res->n_anim     = caps->anim;
    res->n_pattern  = caps->pattern;
    res->n_unk_06   = caps->unk_06;
    res->n_tiles    = caps->tiles;
    res->n_palettes = caps->palettes;
}













/*
 * Was blocked at MATCH: all 264 concrete bytes were correct and the two PC24
 * sites at +0x00E0 and +0x00E8, both calls to func_020345DC, had no witness
 * of any class (those two calls were its only branch references image
 * wide).  Unblocked by src/matched/func_020345DC.c, now a `matched` witness.
 *
 * The inverse of src/pending/func_0204D7E0.c: release every live entry of the
 * three parallel tables, then the tables themselves and the two heaps, and
 * NULL all five pointers.  This block is the tail of the singleton, at
 * +0x104, which is why the three per-entry finalisers take a bare index and
 * find the table through the global themselves (src/matched/sub_0204A8D4.c,
 * sub_0204ADA4.c and sub_0204AFD8.c).
 *
 * The liveness tests are the same three fields those finalisers write: the
 * one-bit field at bit 31 of +0x3c of the 0x40-byte record, the whole word at
 * +0x10 of the 0x14-byte record, and the one-bit field at bit 31 of +0x14 of
 * the 0x18-byte record.  Bit 31 reads as a bare `lsrs #0x1f` with no mask,
 * which is the bitfield tell
 * (docs/idioms/shift-pair-with-no-matching-type-is-a-bitfield.md).
 *
 * Every loop re-reads both its bound and its table base, because the
 * finaliser it calls is opaque and may store to the singleton.  The two
 * non-power-of-two strides become `mla` against a register-held 0x14 and
 * 0x18; only the 0x40 stride folds into `add r0, r0, r4, lsl #6`.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0204D8AC.c \
 *       --func func_0204D8AC --addr 0x0204D8AC --cc 1.1p1 --arm
 */
void func_0204D8AC(struct Res *res)
{
    u32 i;

    for (i = 0; i < res->n_cell; i++) {
        if (res->cell[i].unk_3c_31 == 0) {
            func_0204A8D4(i);
        }
    }

    for (i = 0; i < res->n_pattern; i++) {
        if (res->pattern[i].unk_10 == 0) {
            func_0204AFD8(i);
        }
    }

    for (i = 0; i < res->n_anim; i++) {
        if (res->anim[i].unk_14_31 == 0) {
            func_0204ADA4(i);
        }
    }

    func_0204DC64(res->cell);
    func_0204E010(res->anim);
    func_0204E0C4(res->pattern);
    func_020345DC(res->palettes);
    func_020345DC(res->tiles);

    res->tiles    = 0;
    res->palettes = 0;
    res->cell     = 0;
    res->anim     = 0;
    res->pattern  = 0;
}













/*
 * Two-value compatibility test: value 2 is the wildcard, otherwise the two
 * have to be equal.  A leaf, no relocation.
 *
 * The disjunction has to be one expression so that both halves share the
 * `moveq r0, #1` / `bxeq lr` exit
 * (docs/idioms/disjunction-must-be-one-expression-to-share-its-exit.md); the
 * second test is the predicated `cmpne r1, #2`, which is what a `||` looks
 * like once it is short enough not to branch.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D9B4.c \
 *       --func func_0204D9B4 --addr 0x0204D9B4 --cc 1.1p1 --arm
 */
u32 func_0204D9B4(u32 a, u32 b)
{
    if (a == 2 || b == 2) {
        return 1;
    }
    return a == b;
}













/*
 * Load an archive member, optionally decompressing it.  Both arms read the
 * member with func_02049250 into a scratch block taken from the far end of
 * the caller's heap, (heapId & 0x7fff) | 0x8000, the same "allocate high"
 * form src/matched/unit_02045C44.c uses.  When the third argument is set the
 * block is treated as a compressed image: its first word carries the
 * uncompressed size in the top 24 bits, a normal-end block of that size is
 * allocated, func_020834C0 expands into it and the scratch is released.
 *
 * The heap id is computed once above the branch, which is why the `lsl #16`
 * sits before the `beq` and only the matching `lsr #16` is duplicated into
 * each arm: the compiler hoists the common subexpression and cross-jumps what
 * is left.  Spelling the cast per arm instead moves the whole pair down twice.
 *
 * The decompressing arm is the fall-through, so the guard is written `!= 0`
 * (docs/idioms/the-fall-through-arm-is-the-source-order.md).
 *
 * func_020834C0 takes source first and destination second here, and only two
 * arguments: r2 still holds the allocator's clobbered register at the call and
 * the original never reloads it.  Other files in the tree declare a
 * three-argument (dest, src, size) form of the same address; the declarations
 * live in different translation units and never meet, and this one is what the
 * bytes at this call site say.
 *
 * The fourth argument doubles as the heap id for both allocations, so it is
 * held in a callee-saved register across the whole function rather than
 * recomputed.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204D9D4.c \
 *       --func func_0204D9D4 --addr 0x0204D9D4 --cc 1.1p1 --arm
 */
void *func_0204D9D4(void *owner, u32 which, u32 compressed, u32 heapId)
{
    void *out;
    struct CompHeader *raw;

    if (compressed != 0) {
        raw = (struct CompHeader *)func_02049250(owner, which,
                  (u16)((heapId & 0x7fff) | 0x8000));
        out = sub_02030734(heapId, raw->header >> 8, 0, s_clact_c, 0x1ba5);
        func_020834C0(raw, out);
        sub_020307B0(raw);
    } else {
        out = func_02049250(owner, which,
                  (u16)((heapId & 0x7fff) | 0x8000));
    }
    return out;
}













/*
 * Closes one of the two clact.c fan-in-1 blockers of func_0204D7E0
 * documented in docs/notes/clact_c_fan_in_1_blockers.c.txt (the other is
 * func_0204DCA8, the packet's next function).
 *
 * Allocate `count` 0x40-byte records and initialise each: set bit 31 of
 * the word at +0x3c (a one-bit bitfield, unconditional `bic`/`orr` of the
 * same immediate is the bitfield-store tell), then hand the two
 * two-word sentinel pairs at +0x2c and +0x34 to sub_02034630 (already
 * matched, src/matched/unit_02034630.c).
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204DA5C.c \
 *       --func func_0204DA5C --addr 0x0204DA5C --cc 1.1p1 --arm
 */
void *func_0204DA5C(u32 heapId, u32 count)
{
    u32 i;
    struct Rec_0204D768 *arr;

    arr = sub_02030734(heapId, count << 6, 0, s_clact_c, 0x1bbe);

    for (i = 0; i < count; i++) {
        struct Rec_0204D768 *r = &arr[i];
        r->unk_3c_31 = 1;
        sub_02034630(&r->a);
        sub_02034630(&r->b);
    }

    return arr;
}












/*
 * Upload one 0x40-byte cell's two graphics halves to VRAM. The optional
 * fourth argument supplies an override key: when it is null the key comes
 * from the sink's +0x10 field and the "overridden" flag stays clear;
 * otherwise it is the first word of the override's +0x0C block, with the
 * flag set. func_02063790 resets the cell's three-word handle triple, then
 * each half (the +0x2C descriptor against bank +0x00 and kind 1, the +0x34
 * descriptor against bank +0x04 and kind 2) is uploaded only when
 * func_0204D9B4 admits the mode pair and func_02034660 finds the resource:
 * func_020346D8 turns the descriptor into a byte offset, func_0204DC70
 * selects the VRAM window, and one of the three upload entries is chosen by
 * the override flag and, failing that, by the sink's own +0x08 selector.
 * Finally the sink pointer is published at +0x28 (null when not overridden)
 * and the key is packed into the low 31 bits of the word at +0x3C.
 */
void func_0204DACC(struct Res *r, u32 idx, struct Sink *s, struct Ovr *ovr,
                   u32 mode)
{
    struct Slot *cell;
    u32 ovrd;
    u32 key;
    u32 kind;
    u32 off;

    cell = &r->cell[idx];

    if (ovr == 0) {
        key = s->f10;
        ovrd = 0;
    } else {
        ovrd = (ovr->f0C != 0);
        if (ovrd) key = *ovr->f0C;
        else key = 0;
        ovrd = 1;
    }

    func_02063790((u32 *)cell);

    if (func_0204D9B4(mode, 0) != 0) {
        if (func_02034660((u8 *)r->tiles, key, (void **)&cell->unk_2c) != 0) {
            off = func_020346D8((struct Item020346D8 *)r->tiles, (u32 *)&cell->unk_2c);
            kind = 1;
            func_0204DC70((struct TargetStruct *)s, (int)kind);
            if (ovrd != 0) {
                func_02063C80((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else if (s->f08 != 0) {
                func_02063828((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else {
                func_02063A54((struct Res *)s, off, (int)kind, (struct Out *)cell);
            }
        }
    }

    if (func_0204D9B4(mode, 1) != 0) {
        if (func_02034660((u8 *)r->palettes, key, (void **)&cell->unk_34) != 0) {
            off = func_020346D8((struct Item020346D8 *)r->palettes, (u32 *)&cell->unk_34);
            kind = 2;
            func_0204DC70((struct TargetStruct *)s, (int)kind);
            if (ovrd != 0) {
                func_02063C80((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else if (s->f08 != 0) {
                func_02063828((struct Res *)s, off, (int)kind, (struct Out *)cell);
            } else {
                func_02063A54((struct Res *)s, off, (int)kind, (struct Out *)cell);
            }
        }
    }

    if (ovrd == 0) s = 0;
    cell->unk_28 = (u32)s;
    cell->unk_3c_1 = key;
}












void func_0204DC64(void *ptr)
{
    sub_020307B0(ptr);
}












void func_0204DC70(struct TargetStruct *obj, int which)
{
    u32 val = (which == 1) ? (*(vu32 *)0x04000000 & 0x00300010) : (*(vu32 *)0x04001000 & 0x00300010);
    if (obj->dispcnt != val) {
        obj->dispcnt = val;
    }
}










/*
 * Closes the other of the two clact.c fan-in-1 blockers of func_0204D7E0
 * documented in docs/notes/clact_c_fan_in_1_blockers.c.txt (the other is
 * func_0204DA5C, this packet's previous function).
 *
 * Allocate `count` 0x18-byte records and set bit 31 of the word at +0x14
 * of each (a one-bit bitfield; the unconditional `bic`/`orr` pair of the
 * same immediate is the bitfield-store tell, same shape as
 * func_0204DA5C's +0x3c field).
 *
 * The record size 0x18 is a real `mul` against a register, not a shift
 * pair, because 0x18 is not a power of two; the per-record address inside
 * the loop is then one `mla`.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204DCA8.c \
 *       --func func_0204DCA8 --addr 0x0204DCA8 --cc 1.1p1 --arm
 */
void *func_0204DCA8(u32 heapId, u32 count)
{
    u32 i;
    struct Rec_0204DCA8 *arr;

    arr = sub_02030734(heapId, count * sizeof(struct Rec_0204DCA8), 0, s_clact_c, 0x1c58);

    for (i = 0; i < count; i++) {
        arr[i].unk_14_31 = 1;
    }

    return arr;
}









/*
 * Reconfigure one 0x18-byte entry of the holder's table: trim the surface
 * (the +0x08 byte count / +0x0c data word pair, a palette-shaped record) by
 * `head` 32-byte blocks from the front and to `tail` blocks, clamp it to the
 * layer limit, re-upload for one or both engines, then store the surviving
 * byte count into the entry's bits 0..30.  Sole caller: sub_0204AC18.
 *
 * The C body is docs/notes/sub_0204DD08.c.txt's (476 against 480 there),
 * closed in wave 10 by two levers:
 *  - THE MATERIALISED `lsl r0, r3, #5`.  The head block's offset is a named
 *    64-BIT local, `unsigned long long ofs = head * 32;`, used by the add and
 *    the sub, while the compare keeps the plain `head * 32` (which is why the
 *    image re-folds `cmp r1, r3, lsl #5` beside the live r0).  A 32-bit local
 *    of any type (u32, int, long, pointer, enum) is copy-propagated and folded
 *    into both consumers (476 bytes); a u16/s16 local materialises the value
 *    but narrows it (`lsl #21` + `lsr #16` shifter operands, 5 out).  Only
 *    the u64 local keeps the plain shift as a register temporary: its low
 *    word is what the u32 add and sub consume.  tools/permuter.py found the
 *    materialising temp (`temp(tmp1=head * 32)`, as u16); the width was a
 *    hand sweep.
 *  - THE TAIL MASK ORDER.  The entry's bit-31 half is read into its own
 *    local before the OR (`u32 hi = ent->unk_14 & 0x80000000;`), which is what
 *    loads +0x14 before surf->unk_08 (permuter `temp(tmp2=...)`).
 */
void func_0204DD08(struct Holder *h, int idx, void *src, void *sel,
                  u32 size, u16 head, u16 tail)
{
    struct Surf *surf;
    void *tmp;
    u32 off;
    u8 *ents;
    int max;
    int limit;
    int flag;
    u32 saved;

    off  = idx * sizeof(struct Ent);
    ents = (u8 *)h->ents;
    if (size >= 0x200) {
        size  = (u16)(size - 0x200);
        flag  = 1;
        max   = 0x100;
        limit = 0x2000;
    } else {
        flag  = 0;
        max   = 0x10;
        limit = 0x200;
    }

    func_02062AD4(src, &tmp);
    if (!func_02062A98(src, (void **)(&surf))) {
        return;
    }
    func_020637D4((u32 *)(ents + off));

    if (head != 0) {
        unsigned long long ofs = head * 32;
        if (surf->unk_08 > head * 32) {
            surf->unk_0c += ofs;
            surf->unk_08 -= ofs;
        }
    }
    if (tail != 0) {
        if (head + tail <= max) {
            if (surf->unk_08 > tail * 32) {
                surf->unk_08 = tail * 32;
            }
        }
    }
    if (size != 0) {
        if (surf->unk_08 + size > limit) {
            surf->unk_08 = limit - size;
        }
    }

    if (func_0204D9B4((u32)sel, 0)) {
        saved = func_02080C34();
        if (flag) func_0208068C();
        func_02063E54(surf, size, 1, (struct Ent *)(ents + off));
        if (flag) func_020801F8(saved);
    }
    if (func_0204D9B4((u32)sel, 1)) {
        saved = func_02080C74();
        if (flag) func_0208068C();
        func_02063E54(surf, size, 2, (struct Ent *)(ents + off));
        if (flag) func_0208083C(saved);
    }

    ((struct Ent *)((u8 *)h->ents + off))->unk_14 &= ~0x80000000;
    {
        u32 hi = ((struct Ent *)((u8 *)h->ents + off))->unk_14 & 0x80000000;
        ((struct Ent *)((u8 *)h->ents + off))->unk_14 = hi | (surf->unk_08 & ~0x80000000);
    }
}








/*
 * The one-surface sibling of func_0204DD08 (same entry table, same 0x200
 * large-layer split, same bracketed double upload through func_0204D9B4's
 * engine select), uploading through func_02063F4C instead of func_02063E54.
 * Returns nothing: the trailing read-modify-write leaves r0 as garbage.
 *
 * Levers, all measured (wave 10): the two out-locals are declared `b` then
 * `a` (func_02062A98's out first), which puts `a` at sp+4 as the image has
 * it; and the 0x200 test is written small-arm-first
 * (`if (size < 0x200) flag = 0; else {...}`), which is what orders the
 * predicated `movlo sl,#0` before `movhs sl,#1`.  Either alone leaves 4-6
 * bytes out.  `off = idx * sizeof(struct Ent)` as a byte-offset local and
 * the entry re-derived from h->ents at the end are func_0204DD08's pins.
 */
void func_0204DEE8(struct Holder *h, int idx, void *src, void *sel, u32 size)
{
    void *b;
    void *a;
    u32 off;
    struct Ent *ent;
    int flag;
    u32 saved;

    off = idx * sizeof(struct Ent);
    ent = (struct Ent *)((u8 *)h->ents + off);
    if (size < 0x200) {
        flag = 0;
    } else {
        size = (u16)(size - 0x200);
        flag = 1;
    }

    func_02062AD4(src, &a);
    if (!func_02062A98(src, &b)) {
        return;
    }
    func_020637D4((u32 *)ent);

    if (func_0204D9B4((u32)sel, 0)) {
        saved = func_02080C34();
        if (flag) func_0208068C();
        func_02063F4C(b, a, size, 1, (struct Out02063F4C *)ent);
        if (flag) func_020801F8(saved);
    }
    if (func_0204D9B4((u32)sel, 1)) {
        saved = func_02080C74();
        if (flag) func_0208068C();
        func_02063F4C(b, a, size, 2, (struct Out02063F4C *)ent);
        if (flag) func_0208083C(saved);
    }

    ((struct Ent *)((u8 *)h->ents + off))->unk_14 &= ~0x80000000;
}








void func_0204E010(void *ptr)
{
    sub_020307B0(ptr);
}








/*
 * Allocate the 0x14-byte entry pool and mark every entry free.  The
 * allocation size is `count * sizeof(struct Entry)`, and the `mvn`-free
 * `mov r2, r4` is the alignment argument sharing the zero the loop counter
 * was just materialised into, so `i` must be spelled before the call, not
 * only in the `for` header.
 *
 * The file string at 0x020A7F74 is "clact.c" and the stacked fifth argument
 * is __LINE__ = 7494; it is declared as an extern array pinned by address,
 * never as a literal __FILE__.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E01C.c \
 *       --func func_0204E01C --addr 0x0204E01C --cc 1.1p1 --arm
 */
struct Entry3 *func_0204E01C(u32 heap, u32 count)
{
    struct Entry3 *entries;
    u32 i;

    i = 0;
    entries = (struct Entry3 *)sub_02030734(heap,
                                            count * sizeof(struct Entry3), i,
                                            func_0204E01C_File, 7494);

    for (; i < count; i++) {
        entries[i].unk_10 = 1;
    }

    return entries;
}








/*
 * Publish the two handles of one 0x14-byte pool entry.  The entry is
 * addressed as `pool->entries[idx]` (the `mla` by 0x14 is the subscript,
 * not a byte offset), each handle is registered through its own registrar,
 * and only when both succeed is the entry's +0x10 slot cleared and 1
 * returned.  Either failure leaves the entry alone and returns 0.
 *
 * The two guards must be written nested (`if (ok1) { if (ok2) { ...; return
 * 1; } } return 0;`), not as two early-`return 0` guards and not as one
 * `||`.  Only the nested form leaves the success path as the fall-through
 * of the second `cmp`, which is what lets the store, the constant and the
 * return if-convert into `movne`/`strne`/`movne`/`popne` above a single
 * shared `mov r0, #0` tail.  Two early returns give an if-converted first
 * guard and no shared tail (76 bytes); `||` emits the failure block first
 * and duplicates the return (84 bytes).  Both arguments must be read
 * into locals before the first call: the `mov r5, r3` ahead of the `bl` is
 * the fourth argument being parked in a callee-saved register, which only
 * happens when it is live across the call as a plain value.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E074.c \
 *       --func func_0204E074 --addr 0x0204E074 --cc 1.1p1 --arm
 */
s32 func_0204E074(struct Res *pool, s32 idx, void *a, void *b)
{
    struct Entry3 *entry = &pool->pattern[idx];

    if (func_02062820((int)a, &entry->unk_08) != 0) {
        if (func_02062670(b, &entry->unk_0c) != 0) {
            entry->unk_10 = 0;
            return 1;
        }
    }
    return 0;
}








void func_0204E0C4(void *ptr)
{
    sub_020307B0(ptr);
}








/*
 * Resolve a handle through func_02062A00 into a stack temporary and, only
 * on success, hand it to func_0204DACC together with the two stacked
 * arguments, then clear bit 31 of +0x3c in the 0x40-byte slot `idx` of the
 * table at `owner->unk_08`.
 *
 * The temporary must be a plain local whose address is taken: the `add r1,
 * sp, #4` before the first call and the `ldr r2, [sp, #4]` after it are the
 * out-parameter, and the `ldr r3, [sp, #0x18]` is the caller's fifth
 * argument being reloaded from the incoming stack area, which fixes the
 * arity at five.  Argument four reaches func_0204DACC's own stack slot and
 * argument five reaches its r3, so the two are swapped relative to this
 * function's own signature; that is the original's order, not a slip.
 *
 * The final read-modify-write must go through a named `struct Slot *`.
 * Written inline as `owner->cell[idx].unk_3c &= ~0x80000000`, the compiler
 * folds the constant 0x3c into the base and leaves the scaled index in both
 * the load and the store (`[r1, r5, lsl #6]`), three instructions wrong;
 * binding the element address to a local first forces `add r1, r0, r5, lsl
 * #6` once with an immediate-offset load and store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E0D0.c \
 *       --func func_0204E0D0 --addr 0x0204E0D0 --cc 1.1p1 --arm
 */
void func_0204E0D0(struct Res *owner, s32 idx, u32 handle, u32 a3, u32 a4)
{
    u32 value;
    struct Slot *slot;

    if (func_02062A00((struct NitroFileHeader *)handle, (void **)(&value)) != 0) {
        func_0204DACC((struct Res *)owner, idx, (struct Sink *)value, (struct Ovr *)a4, a3);
        slot = &owner->cell[idx];
        slot->unk_3c_31 = 0;
    }
}
