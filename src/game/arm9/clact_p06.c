/*
 * file:     clact_p06.c
 * unit:     yes
 * function: sub_0204D048, sub_0204D0C4, sub_0204D104, func_0204D134, func_0204D158, func_0204D18C, func_0204D224, func_0204D2C8, func_0204D2DC, func_0204D300, func_0204D324, func_0204D340, func_0204D360, func_0204D380, sub_0204D3A0, sub_0204D3C4, sub_0204D410, sub_0204D444, sub_0204D478, sub_0204D4B4, sub_0204D4C4, sub_0204D500, func_0204D494, func_0204D4A4, func_0204D510, func_0204D52C, func_0204D53C, func_0204D54C, func_0204D564, func_0204D5CC, func_0204D634, func_0204D69C, func_0204D6D4, func_0204D70C, func_0204D744, func_0204D750, func_0204D75C, func_0204D768, func_0204D7C4, func_0204D7E0, func_0204D8AC, func_0204D9B4, func_0204D9D4, func_0204DA5C, func_0204DACC, func_0204DC64, func_0204DC70, func_0204DCA8, func_0204DD08, func_0204DEE8, func_0204E010, func_0204E01C, func_0204E074, func_0204E0C4, func_0204E0D0
 * address:  0x0204D048
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
 *   sub_0204CFDC  0x0204CFDC  arm
 *   sub_0204B59C  0x0204B59C  arm
 *   sub_0204B5D4  0x0204B5D4  arm
 *   sub_0204B5F4  0x0204B5F4  arm
 *   sub_0204B570  0x0204B570  arm
 *   gUnk_020A1394  0x020A1394  data
 *   MI_CpuFill8    0x02082BCC  arm
 *   sub_020627D8  0x020627D8  arm
 *   sub_0206428C  0x0206428C  arm
 *   func_02066AE0  0x02066AE0  arm
 *   func_020627D8  0x020627D8  arm
 *   func_020637B4  0x020637B4  arm
 *   func_020642C8  0x020642C8  arm
 *   s_clact_c      0x020A7F74  data
 *   func_020648B4  0x020648B4  arm
 *   func_02030734  0x02030734  arm
 *   func_02064754  0x02064754  arm
 *   func_0206469C  0x0206469C  arm
 *   sub_02082BCC   0x02082BCC  arm
 *   sub_02066B38  0x02066B38  arm
 *   sub_020307B0  0x020307B0  arm
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
 *   func_0204D410  0x0204D410  arm
 *   func_02063000  0x02063000  arm
 *   func_02063018  0x02063018  arm
 *   func_02034558  0x02034558  arm
 *   func_0204A8D4  0x0204A8D4  arm
 *   func_0204AFD8  0x0204AFD8  arm
 *   func_0204ADA4  0x0204ADA4  arm
 *   func_020345DC  0x020345DC  arm
 *   func_02049250  0x02049250  arm
 *   func_020834C0  0x020834C0  arm
 *   sub_02030734   0x02030734  arm
 *   sub_02034630  0x02034630  arm
 *   func_02063790    0x02063790  arm
 *   func_02034660    0x02034660  arm
 *   func_020346D8    0x020346D8  arm
 *   func_02063828    0x02063828  arm
 *   func_02063A54    0x02063A54  arm
 *   func_02063C80    0x02063C80  arm
 *   func_020307B0  0x020307B0  arm
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
#include "../../matched/include/Obj08865.h"

struct Actor;
struct Req_0204D048;
struct AnimBank;
struct AnimSequence;
struct Obj0206469C;
struct CellAnim;
struct Rec;
struct Node;
struct MultiCellAnim;
struct Obj02064C10;
struct Obj;
struct Rec_0204D768;
struct Bank;
struct Entry;
struct Struct020345DC;
struct ArcFile;
struct Cell;
struct Item020346D8;
struct Out;
struct TargetStruct;
struct NitroFileHeader;
struct List02063F4C;
struct Out02063F4C;
struct Self02063F4C;
struct Ovr;
struct Res;
struct Sink;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

struct Obj {
    u32 kind;
    u8  pad_04[8];
    u8  unk_0c;
};

struct Req_0204D048 {
    u8   pad_00[8];
    s16  unk_08;
    u8   pad_0a[2];
    u32  unk_0c;
    u32  unk_10;
    u16  unk_14;
    u16  unk_16;
};

struct Sub {
    u32 kind;
};

typedef signed int     s32;

struct Dispatchable {
    u32 kind;
};

struct Req_0204D134 {
    u8    pad_00[0x14];
    void *unk_14;
    u8    pad_18[4];
    void *unk_1c;
};

struct Rec_0204D134 {
    u8 unk_00[1];
};

struct Src {
    u8    pad_00[0xc];
    void *unk_0c;
    void *unk_10;
};

struct Obj_0204D158 {
    u8         pad_00[4];
    void      *unk_04;
    void      *unk_08;
    struct Rec_0204D134 unk_0c;
};

struct P_0204D18C {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad_0c[0x64 - 0x0c];
    u32 f64;
};

struct A_0204D18C {
    u32 f00;
    u32 f04;
    u8  pad_08[4];
    u32 f0c;
    u32 f10;
    u8  pad_14[8];
    u32 f1c;
};

struct R {
    u8  pad_00[0x10];
    u32 f10;
    u32 f14;
};

struct P_0204D224 {
    u32 f00;
    u32 f04;
    u32 f08;
    u8  pad_0c[0x70 - 0x0c];
    u32 f70;
    u32 f74;
    u32 f78;
};

struct A_0204D224 {
    u8  pad_00[0x0c];
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
};

struct Obj_0204D2DC {
    u8    pad_00[0x64];
    void *unk_64;
};

struct Obj_0204D300 {
    u8    pad_00[0x78];
    void *unk_78;
};

struct Obj0204D324 {
    u32 kind;
};

struct Obj_0204D340 {
    u8         pad_00[8];
    void      *unk_08;
    struct Rec_0204D134 unk_0c;
};

struct Obj_0204D360 {
    u8         pad_00[8];
    void      *unk_08;
    struct Rec_0204D134 unk_0c;
};

struct Obj_0204D380 {
    u8         pad_00[0xc];
    struct Rec_0204D134 unk_0c;
    u8         pad_0d[0x74 - 0xd];
    void      *unk_74;
};

struct Rec {
    u8   pad_00[0x10];
    u32  unk_10;
};

typedef void (*DispatchFn_0204D4C4)(struct Obj *o, u32 arg);

struct Ctl_0204D478 {
    u32 mode;  /* 0x00 */
};

typedef void (*Handler)(struct Ctl_0204D478 *c);

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

struct Ctl_0204D768 {
    u8 pad_00[4];
};

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

struct Cfg {
    u8  pad_00[0x10];
    u32 unk_10;    /* 0x10 */
    u8  pad_14[4];
    u32 unk_18;    /* 0x18 */
    u8  pad_1c[0x0c];
    u32 unk_28;    /* 0x28 */
    u32 unk_2c;    /* 0x2c */
};

struct Res_0204D7E0 {
    void *tiles;      /* 0x00 */
    void *palettes;   /* 0x04 */
    void *cell;       /* 0x08 */
    void *anim;       /* 0x0c */
    void *pattern;    /* 0x10 */
    u16   n_cell;     /* 0x14 */
    u16   n_anim;     /* 0x16 */
    u16   n_pattern;  /* 0x18 */
    u16   n_unk_06;   /* 0x1a */
    u16   n_tiles;    /* 0x1c */
    u16   n_palettes; /* 0x1e */
};

struct RecC {
    u8  pad_00[0x3c];
    u32 unk_3c_0  : 1;
    u32 unk_3c_1  : 30;
    u32 unk_3c_31 : 1;
};

struct RecA {
    u8  pad_00[0x14];
    u32 unk_14_0  : 31;
    u32 unk_14_31 : 1;
};

struct RecB {
    u8  pad_00[0x10];
    u32 unk_10;
};

struct Res_0204D8AC {
    void        *tiles;      /* 0x00 */
    void        *palettes;   /* 0x04 */
    struct RecC *cell;       /* 0x08 */
    struct RecA *anim;       /* 0x0c */
    struct RecB *pattern;    /* 0x10 */
    u16          n_cell;     /* 0x14 */
    u16          n_anim;     /* 0x16 */
    u16          n_pattern;  /* 0x18 */
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

struct Res {
    u32 f00;
    u32 f04;
    u32 f08;
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

struct Entry_0204E01C {
    u8  pad_00[0x10];
    u32 unk_10;
};

struct Entry_0204E074 {
    u8    pad_00[8];
    void *unk_08;
    void *unk_0c;
    u32   unk_10;
};

struct Pool {
    u8            pad_00[0x10];
    struct Entry_0204E074 *entries;
};

struct Slot {
    u8  pad_00[0x3c];
    u32 unk_3c;
};

struct Owner {
    u8           pad_00[8];
    struct Slot *slots;
};

extern struct Obj *sub_0204CFDC(void *owner, const struct Req_0204D048 *r, void *c, u32 space,
                                u16 e);
extern void sub_0204B59C(struct Obj *o, s16 value, u32 axis);
extern void sub_0204B5D4(struct Actor *actor, u32 value, u32 which);
extern void sub_0204B5F4(struct Actor *actor, u16 value);
extern void sub_0204B570(struct Actor *actor, u32 value);
extern void MI_CpuFill8(void *dest, u8 data, u32 size);
extern struct AnimSequence *sub_020627D8(struct AnimBank *bank, u32 idx);
extern void sub_0206428C(char *self, int a1, char *c);
extern int func_02066AE0(void);
extern struct AnimSequence *func_020627D8(struct AnimBank *bank, u32 idx);
extern int func_020637B4(int *p, int i);
extern void func_020642C8(char *self, int a1, char *c, int d, int e, int f, int g, int h, int i, int j);
extern int func_020648B4(u32 a, u32 b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02064754(char *o, char *buf, void *set, int a3, void *bank, int kind);
extern void func_0206469C(struct Obj0206469C *o, void *bank);
extern void sub_02082BCC(void *dst, int value, u32 len);
extern void sub_02066B38(u32 idx);
extern u32 sub_020307B0(void *p);
extern void  sub_0206434C(struct Rec_0204D134 *r, void *v);
extern void sub_0206469C(struct Obj0206469C *o, void *bank);
extern void sub_02064364(struct CellAnim *anim, s32 frames);
extern void sub_020649D4(char *self, int a1);
extern void func_02064384(struct CellAnim *anim, u32 i);
extern void sub_02064AB4(char *self, unsigned int i);
extern void sub_020643C4(struct MultiCellAnim *mca, u32 value);
extern void sub_02064B68(struct Obj *o, void *arg);
extern void func_020643A4(struct CellAnim *anim);
extern void func_02064C10(struct Obj02064C10 *x);
extern struct Rec_0204D768 *func_0204D410(struct Obj *o);
extern void func_02063000(int p0, int p1, int p2, int p3);
extern void func_02063018(struct CellAnim *anim, u32 a, u32 b, u16 tag);
extern struct Bank *func_02034558(u32 heapId, u32 kind, u32 flags, u32 base, u32 b);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_020345DC(struct Struct020345DC *obj);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void func_020834C0(const void *src, void *dest);
extern void  sub_02034630(struct Sentinel *p);
extern void func_02063790(u32 *p);
extern int func_02034660(u8 *p, u32 a, void **out);
extern u32 func_020346D8(struct Item020346D8 *a, u32 *b);
extern void func_02063828(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063A54(struct Res *r, u32 dst, int mode, struct Out *out);
extern void func_02063C80(struct Res *r, u32 dst, int mode, struct Out *out);
extern u32 func_020307B0(void *p);
extern s32 func_02062AD4(struct NitroFileHeader *file, void **out);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern void func_020637D4(u32 *p);
extern void func_02063E54(struct Surf *s, u32 size, int mode,
                         struct Ent *ent);
extern u16 func_02080C34(void);
extern u16 func_02080C74(void);
extern void func_0208068C(void);
extern void func_020801F8(int objExtPltt);
extern void func_0208083C(int sub_objExtPltt);
extern void func_02063F4C(struct Self02063F4C *self, struct List02063F4C *list, u32 base, int sel, struct Out02063F4C *out);
extern int func_02062820(int a, int *out);
extern s32 func_02062670(void *handle, void **slot);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void  func_020461F4(u32 a);
struct Obj *sub_0204D048(void *owner, const struct Req_0204D048 *r, void *c, u32 space, u16 e);
void sub_0204D0C4(struct Sub *s, void *c, u32 e);
void sub_0204D104(struct Dispatchable *p);
s32 sub_0204D134(const struct Req_0204D134 *r);
void sub_0204D158(struct Obj_0204D158 *o, const struct Src *s);
void func_0204D18C(struct P_0204D18C *p, const struct A_0204D18C *a);
void func_0204D224(struct P_0204D224 *p, const struct A_0204D224 *a1, u32 heap);
void func_0204D2C8(void *anim);
void sub_0204D2DC(struct Obj_0204D2DC *o);
void sub_0204D300(struct Obj_0204D300 *o);
void func_0204D324(struct Obj0204D324 *obj, u32 arg);
void sub_0204D340(struct Obj_0204D340 *o, u32 idx);
void sub_0204D360(struct Obj_0204D360 *o, u32 idx);
void sub_0204D380(struct Obj_0204D380 *o, u32 idx);
void sub_0204D3A0(struct Obj *o, u32 value);
void *sub_0204D3C4(struct Obj *o, u32 arg);
void sub_0204D3E0(struct Obj *o, s32 frames);
void sub_0204D3F0(struct Obj *o, s32 frames);
void sub_0204D400(struct Obj *o, s32 frames);
struct Rec *sub_0204D410(struct Obj *o);
void *sub_0204D42C(struct Obj *o);
void *sub_0204D434(struct Obj *o);
void *sub_0204D43C(struct Obj *o);
struct Node *sub_0204D444(struct Obj *o);
void *sub_0204D460(struct Obj *o);
void *sub_0204D468(struct Obj *o);
void *sub_0204D470(struct Obj *o);
void *sub_0204D478(struct Obj *o, u32 arg);
void func_0204D494(u8 *a0, u32 i);
void func_0204D4A4(u8 *a0, u32 i);
void sub_0204D4B4(struct Obj *o, u32 i);
void sub_0204D4C4(struct Obj *o, u32 arg);
void sub_0204D4E0(struct Obj *o, u32 arg);
void sub_0204D4F0(struct Obj *o, u32 arg);
void sub_0204D500(struct Obj *o, u32 arg);
void func_0204D510(struct Ctl_0204D478 *c);
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
void func_0204D768(struct Ctl_0204D768 *c, const struct Cmd *cmd);
void func_0204D7C4(struct Ctl_0204D768 *c);
void func_0204D7E0(struct Res_0204D7E0 *res, u32 heapId, const struct Cfg *cfg, const struct Caps *caps);
void func_0204D8AC(struct Res_0204D8AC *res);
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
struct Entry_0204E01C *func_0204E01C(u32 heap, u32 count);
s32 func_0204E074(struct Pool *pool, s32 idx, void *a, void *b);
void func_0204E0C4(void *ptr);
void func_0204E0D0(struct Owner *owner, s32 idx, u32 handle, u32 a3, u32 a4);
extern char s_clact_c[];
extern DispatchFn_0204D4C4 const gUnk_020A7F3C[];
extern Handler g_DispatchTable_0204D510[];
extern const char func_0204E01C_File[];





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
struct Obj *sub_0204D048(void *owner, const struct Req_0204D048 *r, void *c, u32 space, u16 e)
{
    struct Obj *o = sub_0204CFDC(owner, r, c, space, e);

    sub_0204B59C(o, r->unk_08, 0);
    sub_0204B59C(o, r->unk_08, 1);
    sub_0204B5D4((struct Actor *)o, r->unk_0c, 0);
    sub_0204B5D4((struct Actor *)o, r->unk_10, 1);
    sub_0204B5F4((struct Actor *)o, r->unk_14);
    sub_0204B570((struct Actor *)o, r->unk_16);
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
void sub_0204D0C4(struct Sub *s, void *c, u32 e)
{
    u32 kind = sub_0204D134(c);

    s->kind = kind;
    gUnk_020A1394[6][kind](s, c, e);
}




extern void *(*const gUnk_020A1394[][3])();




void sub_0204D104(struct Dispatchable *p)
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
s32 sub_0204D134(const struct Req_0204D134 *r)
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
void sub_0204D158(struct Obj_0204D158 *o, const struct Src *s)
{
    o->unk_04 = s->unk_0c;
    o->unk_08 = s->unk_10;
    sub_0206428C((char *)(&o->unk_0c), (int)sub_020627D8(o->unk_08, 0), o->unk_04);
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
void func_0204D18C(struct P_0204D18C *p, const struct A_0204D18C *a)
{
    u32 zero = 0;
    u32 two;
    u32 h0, h1, h2;
    struct R *r;

    {
        u32 t1 = a->f10;
        u32 t0 = a->f0c;
        p->f04 = t0;
        p->f08 = t1;
    }
    p->f64 = func_02066AE0();
    r = (struct R *)a->f1c;
    h0 = (u32)func_020627D8((struct AnimBank *)p->f08, zero);
    h1 = func_020637B4((int *)a->f04, 1);
    two = 2;
    h2 = func_020637B4((int *)a->f04, two);
    func_020642C8((char *)((u8 *)p + 0xc), h0, (char *)p->f04, p->f64,
                  two - 3, h1, h2, r->f14, zero, r->f10);
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
void func_0204D224(struct P_0204D224 *p, const struct A_0204D224 *a1, u32 heap)
{
    p->f04 = a1->f0c;
    p->f08 = a1->f10;
    p->f70 = a1->f14;
    p->f74 = a1->f18;

    p->f78 = (u32)func_02030734(heap, func_020648B4(a1->f14, 1), 0, s_clact_c, 0x171d);
    func_02064754((char *)((u8 *)p + 0xc), (char *)p->f78, (void *)p->f08, p->f04, (void *)p->f70, 1);
    func_0206469C((struct Obj0206469C *)((u8 *)p + 0xc), func_020627D8((struct AnimBank *)p->f74, 0));
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
    sub_02082BCC(anim, 0, 0x7c);
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
void sub_0204D2DC(struct Obj_0204D2DC *o)
{
    sub_02066B38((u32)o->unk_64);
    sub_02082BCC(o, 0, 0x7c);
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
void sub_0204D300(struct Obj_0204D300 *o)
{
    sub_020307B0(o->unk_78);
    sub_02082BCC(o, 0, 0x7c);
}





extern void *(*const gUnk_020A1394[][3])();





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
void func_0204D324(struct Obj0204D324 *obj, u32 arg)
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
void sub_0204D340(struct Obj_0204D340 *o, u32 idx)
{
    sub_0206434C(&o->unk_0c, sub_020627D8(o->unk_08, idx));
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
void sub_0204D360(struct Obj_0204D360 *o, u32 idx)
{
    sub_0206434C(&o->unk_0c, sub_020627D8(o->unk_08, idx));
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
void sub_0204D380(struct Obj_0204D380 *o, u32 idx)
{
    sub_0206469C((struct Obj0206469C *)(&o->unk_0c), sub_020627D8(o->unk_74, idx));
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
void sub_0204D3A0(struct Obj *o, u32 value)
{
    sub_0204D410(o)->unk_10 = value;
    sub_0204D3C4(o, 0);
}




extern void *(*const gUnk_020A1394[][3])();




void *sub_0204D3C4(struct Obj *o, u32 arg)
{
    return gUnk_020A1394[10][o->kind](o, arg);
}




void sub_0204D3E0(struct Obj *o, s32 frames)
{
    sub_02064364((struct CellAnim *)(&o->unk_0c), frames);
}




void sub_0204D3F0(struct Obj *o, s32 frames)
{
    sub_02064364((struct CellAnim *)(&o->unk_0c), frames);
}




void sub_0204D400(struct Obj *o, s32 frames)
{
    sub_020649D4((char *)(&o->unk_0c), frames);
}



extern void *(*const gUnk_020A1394[][3])();





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
struct Rec *sub_0204D410(struct Obj *o)
{
    return gUnk_020A1394[7][o->kind](o);
}





void *sub_0204D42C(struct Obj *o)
{
    return &o->unk_0c;
}





void *sub_0204D434(struct Obj *o)
{
    return &o->unk_0c;
}





void *sub_0204D43C(struct Obj *o)
{
    return &o->unk_0c;
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
struct Node *sub_0204D444(struct Obj *o)
{
    return gUnk_020A1394[1][o->kind](o);
}





void *sub_0204D460(struct Obj *o)
{
    return &o->unk_0c;
}





void *sub_0204D468(struct Obj *o)
{
    return &o->unk_0c;
}





void *sub_0204D470(struct Obj *o)
{
    return &o->unk_0c;
}


extern void *(*const gUnk_020A1394[][3])();











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
void *sub_0204D478(struct Obj *o, u32 arg)
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
void sub_0204D4B4(struct Obj *o, u32 i)
{
    sub_02064AB4((char *)(&o->unk_0c), i);
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
void sub_0204D4C4(struct Obj *o, u32 arg)
{
    gUnk_020A7F3C[o->kind](o, arg);
}









void sub_0204D4E0(struct Obj *o, u32 arg)
{
    sub_020643C4((struct MultiCellAnim *)(&o->unk_0c), arg);
}









void sub_0204D4F0(struct Obj *o, u32 arg)
{
    sub_020643C4((struct MultiCellAnim *)(&o->unk_0c), arg);
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
void sub_0204D500(struct Obj *o, u32 arg)
{
    sub_02064B68((struct Obj *)(&o->unk_0c), (void *)arg);
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
void func_0204D510(struct Ctl_0204D478 *c)
{
    g_DispatchTable_0204D510[c->mode](c);
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
void func_0204D768(struct Ctl_0204D768 *c, const struct Cmd *cmd)
{
    void *h = func_0204D410((struct Obj *)c);

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
void func_0204D7C4(struct Ctl_0204D768 *c)
{
    func_02063000((int)func_0204D410((struct Obj *)c), 0, 0, 0);
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
void func_0204D7E0(struct Res_0204D7E0 *res, u32 heapId, const struct Cfg *cfg,
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
void func_0204D8AC(struct Res_0204D8AC *res)
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
    u8 *cell;
    u32 ovrd;
    u32 key;
    u32 kind;
    u32 off;

    cell = (u8 *)r->f08 + idx * 0x40;

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
        if (func_02034660((u8 *)r->f00, key, (void **)(cell + 0x2c)) != 0) {
            off = func_020346D8((struct Item020346D8 *)r->f00, (u32 *)(cell + 0x2c));
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
        if (func_02034660((u8 *)r->f04, key, (void **)(cell + 0x34)) != 0) {
            off = func_020346D8((struct Item020346D8 *)r->f04, (u32 *)(cell + 0x34));
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
    ((struct Obj08865 *)cell)->f28 = (u32)s;
    ((struct Obj08865 *)cell)->f3C = (((struct Obj08865 *)cell)->f3C & 0x80000001)
                          | ((key << 2) >> 1);
}











void func_0204DC64(void *ptr)
{
    func_020307B0(ptr);
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
    func_020307B0(ptr);
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
struct Entry_0204E01C *func_0204E01C(u32 heap, u32 count)
{
    struct Entry_0204E01C *entries;
    u32 i;

    i = 0;
    entries = (struct Entry_0204E01C *)func_02030734(heap,
                                            count * sizeof(struct Entry_0204E01C), i,
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
s32 func_0204E074(struct Pool *pool, s32 idx, void *a, void *b)
{
    struct Entry_0204E074 *entry = &pool->entries[idx];

    if (func_02062820((int)a, (int *)(&entry->unk_08)) != 0) {
        if (func_02062670(b, &entry->unk_0c) != 0) {
            entry->unk_10 = 0;
            return 1;
        }
    }
    return 0;
}







void func_0204E0C4(void *ptr)
{
    func_020307B0(ptr);
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
 * Written inline as `owner->slots[idx].unk_3c &= ~0x80000000`, the compiler
 * folds the constant 0x3c into the base and leaves the scaled index in both
 * the load and the store (`[r1, r5, lsl #6]`), three instructions wrong;
 * binding the element address to a local first forces `add r1, r0, r5, lsl
 * #6` once with an immediate-offset load and store.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0204E0D0.c \
 *       --func func_0204E0D0 --addr 0x0204E0D0 --cc 1.1p1 --arm
 */
void func_0204E0D0(struct Owner *owner, s32 idx, u32 handle, u32 a3, u32 a4)
{
    u32 value;
    struct Slot *slot;

    if (func_02062A00((struct NitroFileHeader *)handle, (void **)(&value)) != 0) {
        func_0204DACC((struct Res *)owner, idx, (struct Sink *)value, (struct Ovr *)a4, a3);
        slot = &owner->slots[idx];
        slot->unk_3c &= ~0x80000000;
    }
}
