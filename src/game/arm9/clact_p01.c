/*
 * file:     clact_p01.c
 * unit:     yes
 * function: sub_0204A48C, sub_0204A5AC, func_0204A600, func_0204A648, func_0204A698, sub_0204A6C8, func_0204A7A0, func_0204A8D4, func_0204A9D0, func_0204AA94, func_0204AB84, func_0204ABBC, func_0204ABF0, func_0204AC18, func_0204ACEC, sub_0204ADA4, sub_0204ADEC, sub_0204AEC0, sub_0204AF28, func_0204AFD8, func_0204B034, func_0204B084, func_0204B09C, func_0204B0C8, func_0204B0F4, func_0204B100, func_0204B1CC, func_0204B22C, func_0204B248, func_0204B258, func_0204B270, func_0204B294, func_0204B324, func_0204B3B4, func_0204B3DC, func_0204B3F4, func_0204B404, func_0204B454, func_0204B49C, func_0204B4EC, func_0204B528, func_0204B53C, func_0204B550, func_0204B560, sub_0204B570, sub_0204B59C, func_0204B5AC, sub_0204B5C0, func_0204B5D4, func_0204B5E4, func_0204B5F4, func_0204B5FC, func_0204B604, func_0204B658, func_0204B688, func_0204B6E4, func_0204B6F4, func_0204B714, func_0204B728, func_0204B764, func_0204B784, func_0204B7C8, func_0204B7F0, func_0204B7F8, func_0204B800, func_0204B838, func_0204B84C, func_0204B864, func_0204B878, func_0204B898, func_0204B8A0, func_0204B8C4, func_0204B8D4, func_0204B8F4, func_0204B908, func_0204B918, func_0204B92C, func_0204B944, func_0204B954, func_0204B95C, func_0204B974, func_0204B98C, func_0204B9A0, func_0204B9C4, func_0204BA00, func_0204BA10, func_0204BA20, func_0204BA38, func_0204BA7C, func_0204BAEC, func_0204BB04, func_0204BB20, func_0204BB38, func_0204BB54, func_0204BB8C, func_0204BBC8, func_0204BC40, func_0204BC94, func_0204BCD8, func_0204BCF4, func_0204BD18, func_0204BD3C, func_0204BD64, func_0204BD7C, func_0204BD94, func_0204BE28
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
 *   func_0204D7E0  0x0204D7E0  arm
 *   func_0204C660  0x0204C660  arm
 *   func_0204C6E4  0x0204C6E4  arm
 *   func_0204D8AC  0x0204D8AC  arm
 *   sub_020307B0   0x020307B0  arm
 *   lbl_02146A74  0x02146A74 data
 *   func_02066998 0x02066998 arm
 *   func_0204C7A4 0x0204C7A4  arm
 *   unk_02146A74   0x02146A74  data
 *   func_0204D9D4  0x0204D9D4  arm
 *   func_0204E0D0  0x0204E0D0  arm
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
 *   func_0204DD08  0x0204DD08  arm
 *   func_0204DEE8  0x0204DEE8  arm
 *   func_0206380C  0x0206380C  arm
 *   func_02063800  0x02063800  arm
 *   func_0207E51C  0x0207E51C  arm
 *   func_0207E5D0  0x0207E5D0  arm
 *   func_0204E074  0x0204E074  arm
 *   func_0204CAE4  0x0204CAE4  arm
 *   sub_0204CFA4   0x0204CFA4  arm
 *   sub_0204CFDC   0x0204CFDC  arm
 *   func_0204D048  0x0204D048  arm
 *   func_0204CA30  0x0204CA30  arm
 *   func_0204D104  0x0204D104  arm
 *   func_0204CF74  0x0204CF74  arm
 *   func_0204B528  0x0204B528  arm
 *   sub_0204B5AC  0x0204B5AC  arm
 *   sub_0206380C  0x0206380C  arm
 *   func_0204C98C  0x0204C98C  arm
 *   func_0204D324  0x0204D324  arm
 *   sub_0204B95C   0x0204B95C  arm
 *   sub_0204D4C4   0x0204D4C4  arm
 *   sub_0204D3C4   0x0204D3C4  arm
 *   sub_0204D444   0x0204D444  arm
 *   sub_02062F1C   0x02062F1C  arm
 *   func_0204D410  0x0204D410  arm
 *   func_0204D444  0x0204D444  arm
 *   func_0204D510  0x0204D510  arm
 *   func_0204D768  0x0204D768  arm
 *   func_0204D7C4  0x0204D7C4  arm
 *   g_020A7F3C     0x020A7F3C  data
 *   func_0204C944  0x0204C944  arm
 *   func_02063078  0x02063078  arm
 *   func_0206343C  0x0206343C  arm
 *   func_02063640  0x02063640  arm
 *   func_02065AA8   0x02065AA8  arm
 *   func_02030734   0x02030734  arm
 *   func_0204BE84   0x0204BE84  arm
 *   func_02065B64   0x02065B64  arm
 */
#include "../../matched/include/Obj16080.h"
#include "../../matched/include/Obj16081.h"
#include "../../matched/include/Obj16082.h"
#include "../../matched/include/Obj16083.h"
#include "../../matched/include/Obj11428.h"

struct Bank;
struct Caps;
struct Obj_0204A48C;
struct Res;
struct Pool;
struct Table;
struct Ovr;
struct Sink;
struct Sentinel;
struct Owner;
struct ArcFile;
struct Holder;
struct Actor;
struct Req;
struct Dispatchable;
struct Mgr;
struct Node;
struct Pt;
struct Obj0204D324;
struct Obj0204D478;
struct Rec;
struct Cmd;
struct Ring;
struct NNSG2dOamManagerInstance;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef signed short   s16;

typedef signed int     s32;

struct Handle {
    u32 unk_00;
    u32 unk_04;
};

struct Slot {
    u8            pad_00[0x24];
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
    void *unk_00;
    void *unk_04;
    u32   unk_08;
    u32   unk_0c;
    u32   unk_10;
};

struct Ctl {
    u8 pad_00[4];
};

struct Pt {
    u16 x;
    u16 y;
};

struct Pair {
    u32 x;
    u32 y;
};

struct Actor {
    void     *unk_00;
    u8        pad_04[4];
    void     *unk_08;
    struct Pt pos;
    struct Pt unk_10;
    struct Pair p;
    u8        pad_1c[0x44];
    u32       unk_60_00 : 18;
    u32       unk_60_18 : 2;
    u32       unk_60_20 : 6;
    u32       unk_60_26 : 1;
    u32       unk_60_27 : 5;
    u8        pad_64[4];
    struct Ctl ctl;
    u8        pad_6c[0x78];
};

struct Bank {
    struct Actor *actors;
    u8            pad_04[4];
    void         *unk_08;
    u16           count;
    u8            source : 4;
    u8            mode   : 4;
    u8            unk_0f;
    struct Bank  *next;
    struct Bank  *prev;
};

struct Owner {
    void         *unk_00;
    void         *unk_04;
    struct Slot  *slots;
    struct Slot2 *slots2;
    struct Entry3 *entries3;
    volatile u16  count;
    volatile u16  count2;
    volatile u16  count3;
    u8            pad_1a[6];
};

struct Sub {
    u8  pad_00[0x1c];
    u32 bound;
};

struct Obj_0204A48C {
    struct Sub w[2];
};

struct Sys {
    u8           pad_000[0xec];
    u32          unk_0ec;
    u16          unk_f0[2];
    u32          unk_0f4;
    u32          unk_0f8;
    u32          unk_0fc;
    struct Bank *head;
    struct Owner owner;
};

struct Cfg {
    u8  pad_00[8];
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

struct Rec {
    u32 w[9];
};

struct Dest {
    u8    pad_00[8];
    u32   unk_08;
    void *unk_0c;
};

struct Pool {
    u8            pad_00[0x10];
    struct Entry3 *entries;
    u8            pad_14[4];
    volatile u16  count;
};

struct Obj_0204B034 {
    u8 pad_00[0xa0];
};

typedef struct {
    int x;
    int y;
    char pad[0x40];
} Entry;

typedef struct {
    char pad[0x98];
    Entry *entries;
} EntryTable;

typedef struct {
    s16 x;
    s16 y;
} Vec16;

struct Request {
    u8 b[0x20];
};

struct Vec2 {
    s16 x;
    s16 y;
};

struct PtS {
    s16 x;
    s16 y;
};

struct Actor_0204B5D4 {
    u8  pad_00[0x14];
    u32 unk_14;
    u32 unk_18;
};

struct Actor_0204B5F4 {
    u8  pad_00[0x58];
    u16 unk_58;
};

struct Actor_0204B604 {
    u8  pad_00[0x60];
    u32 f_00 : 8;
    u32 f_08 : 4;
    u32 f_0c : 6;
    u32 f_12 : 2;
    u32 f_14 : 2;
    u32 f_16 : 2;
    u32 f_18 : 8;
};

struct Actor_0204B658 {
    u8  pad_00[0x60];
    u32 f_00 : 8;
    u32 f_08 : 4;
    u32 f_0c : 6;
    u32 f_12 : 2;
    u32 f_14 : 2;
    u32 f_16 : 2;
    u32 f_18 : 8;
};

struct Actor_0204B688 {
    u8  pad_00[0x60];
    u32 f_00 : 8;
    u32 f_08 : 4;
    u32 f_0c : 6;
    u32 f_12 : 2;
    u32 f_14 : 2;
    u32 f_16 : 2;
    u32 f_18 : 8;
};

struct Obj_0204B6F4 {
    u32 pad_00[0x18];
    struct {
        u32 fieldA : 12;
        u32 fieldB : 4;
        u32 pad    : 15;
        u32 flag   : 1;
    } bits60;
};

struct Xform {
    u32 w[5];
};

struct Obj_0204B728 {
    u8           pad_00[0x40];
    struct Xform unk_40;
};

typedef struct Struct20 {
    int w[5];
} Struct20;

typedef struct Struct36 {
    int w[9];
} Struct36;

struct Node {
    u8   pad_000[8];
    void *unk_008;
    u8   pad_00c[0x60 - 0x0c];
    u32  unk_060 : 8;
};

typedef struct {
    char pad[0x60];
    unsigned int f60;
} S;

struct Obj_204B800 {
    u8  pad_00[0x5a];
    u16 unk_5a;
    u8  pad_5c[0x0c];
    u8  unk_68;
};

struct Sub68 {
    u8 unk_00[1];
};

struct Obj_0204B898 {
    u8         pad_00[0x5a];
    u16        unk_5a;
    u8         pad_5c[0xc];
    struct Sub68 unk_68;
};

struct Obj_0204B8C4 {
    u8         pad_00[0x68];
    struct Sub68 unk_68;
};

struct Obj_0204B8D4 {
    u8         pad_00[0x68];
    struct Sub68 unk_68;
};

struct Node_204B8F4 {
    u8  pad_00[0xc];
    u32 unk_0c;
    u32 unk_10;
};

struct Obj_204B8F4 {
    u8         pad_00[0x68];
    struct Sub68 unk_68;
};

struct Obj_204B92C {
    u32 unk_00[24];
    u32 unk_60_0 : 25;
    u32 unk_60_25 : 1;
    u32 unk_60_26 : 6;
};

struct Actor_0204B954 {
    u8  pad_00[0x54];
    u32 unk_54;   /* 0x54 */
};

struct Anim {
    u8  pad_00[0x0c];
    u32 flag;   /* 0x0c */
};

struct Actor_0204B95C {
    u8         pad_00[0x68];
    struct Ctl ctl;   /* 0x68 */
};

struct Actor_0204B974 {
    u8         pad_00[0x68];
    struct Ctl ctl;   /* 0x68 */
};

struct Rec_204B92C {
    u8  pad_00[0x0c];
    u32 value;   /* 0x0c */
};

struct Actor_0204B98C {
    u8         pad_00[0x68];
    struct Ctl ctl;   /* 0x68 */
};

struct Anim_204B9C4 {
    u8  pad_00[8];
    u32 unk_08;   /* 0x08 */
    u8  pad_0c[0x0c];
    u32 unk_18;   /* 0x18 */
};

struct Actor_204B9C4 {
    u8         pad_00[0x60];
    u32        pad_60_lo : 27;
    u32        mode      : 4;    /* 0x60, bits 27..30 */
    u32        pad_60_hi : 1;
    u8         pad_64[4];
    struct Ctl ctl;              /* 0x68 */
};

struct Actor_0204BA20 {
    u8  pad_00[0x64];
    u32 hidden : 1;    /* 0x64, bit 0 */
    u32 pad_64 : 31;
};

struct Rec_204BA38 {
    s16 x;            /* 0x00 */
    s16 y;            /* 0x02 */
    u8  pad_04[0x0c];
};

struct Clact {
    void      (*vt[6])(void);   /* 0x00 */
    struct Rec_204BA38  rec[2];         /* 0x18 */
};

struct Obj_0204BD3C {
    u8 pad_00[0x80];
    u32 f80;
    u8 pad_84[0x14];
    u32 f98;
    u32 f9c;
};

extern void *sub_02030734(u32 heapId, u32 size, int clear, const char *site,
                          u16 tag);
extern void  func_02082BCC(void *dst, int fill, u32 size);
extern void func_0204D7E0(struct Res *res, u32 heapId, const struct Cfg *cfg, const struct Caps *caps);
extern void func_0204C660(struct Pool *p, u8 n, u32 heapId);
extern void func_0204C6E4(struct Pool *p);
extern void func_0204D8AC(struct Res *res);
extern u32 sub_020307B0(void *p);
extern void func_02066998(void);
extern void func_0204C7A4(struct Table *t);
extern void *func_0204D9D4(void *owner, u32 which, u32 compressed, u32 heapId);
extern void func_0204E0D0(struct Owner *owner, s32 idx, u32 handle, u32 a3, u32 a4);
extern u32 func_020307B0(void *p);
extern void sub_0204DACC(struct Res *r, u32 idx, struct Sink *s, struct Ovr *ovr, u32 mode);
extern int sub_02034640(struct Sentinel *p);
extern void sub_020346B8(struct Owner *owner, struct Sentinel *p);
extern int func_020637BC(const u32 *p, u32 i);
extern int func_020637B4(int *p, int i);
extern void func_020862F0(void *a, u32 b);
extern void func_0207E780(void *a, void *b, u32 c);
extern void func_0207E804(void *a, void *b, u32 c);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern void func_0204DD08(struct Holder *h, int idx, void *src, void *sel, u32 size, u16 head, u16 tail);
extern void func_0204DEE8(struct Holder *h, int idx, void *src, void *sel, u32 size);
extern int func_0206380C(char *p, int i);
extern int func_02063800(char *p, int i);
extern void func_0207E51C(void *dest, void *src, u32 size);
extern void func_0207E5D0(void *dest, void *src, u32 size);
extern s32 func_0204E074(struct Owner *pool, s32 idx, void *a, void *b);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_0204BE38(struct Obj_0204A48C *obj, int on);
extern void func_0204CAE4(struct Actor *o);
extern void sub_0204CFA4(struct Req *out, u16 i, u16 j, u32 c,
                         u32 a, u32 x, u32 y);
extern struct Actor *sub_0204CFDC(void *owner, const struct Req *position,
                               void *req, u32 space, u16 heap);
extern struct Actor *func_0204D048(void *owner, const struct Req *position,
                                void *request, u32 space, u16 heap);
extern void func_0204CA30(struct Mgr *m, struct Node *l);
extern void func_0204D104(struct Dispatchable *p);
extern void func_0204CF74(struct Actor *o, u32 id, u16 *out);
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
extern int sub_0206380C(char *p, int i);
extern void func_0204C98C(void *p, struct Node *node);
extern void func_0204D324(struct Obj0204D324 *obj, u32 arg);
extern void sub_0204B95C(struct Actor *a);
extern void sub_0204D3A0(struct Obj_0204B8C4 *o, u32 value);
extern void sub_0204D4C4(struct Obj_0204B8D4 *o, u32 arg);
extern void *sub_0204D3C4(struct Obj_0204B8D4 *o, u32 arg);
extern struct Node_204B8F4 *sub_0204D444(struct Obj_204B8F4 *o);
extern void *func_0204D478(struct Obj0204D478 *o, u32 arg);
extern u16 sub_02062F1C(const struct Node_204B8F4 *n);
extern struct Anim *func_0204D410(struct Ctl *c);
extern struct Rec_204B92C *func_0204D444(struct Ctl *c);
extern void         func_0204D510(struct Ctl *c);
extern void         func_0204D768(struct Ctl *c, const struct Cmd *cmd);
extern void         func_0204D7C4(struct Ctl *c);
extern void func_0204C944(struct Ring *b);
extern void func_02063078(void);
extern unsigned int func_02063138(void *p, int a, int b, int which);
extern void func_0206343C(struct NNSG2dOamManagerInstance *pMan, u32 bound);
extern void func_02063640(struct NNSG2dOamManagerInstance *pMan);
extern void func_02065AA8(u8 *o);
extern void  func_0204BE84(void *dst, void *src);
extern void func_02065B64(int p0, void *p1);
void sub_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
void sub_0204A5AC(void);
void func_0204A600(void);
void func_0204A648(void);
void func_0204A698(void);
s32 sub_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
s32 func_0204A7A0(u32 size, u32 a2, u16 heapId);
void sub_0204A8D4(u32 i);
void func_0204A9D0(int a, struct Sub0204A9D0 *b);
void func_0204AA94(int a, void *b, u32 c, int d, int e);
void func_0204AB84(u32 idx, struct Rec *dst);
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
struct Obj_0204B034 *func_0204B034(u8 *a0, u32 a1, u32 heap);
asm void func_0204B084(void);
void func_0204B09C(EntryTable *o, int idx, Vec16 *v);
void sub_0204B0C8(EntryTable *owner, u32 index, Vec16 *out);
void func_0204B0F4(struct Actor *a0, int a1);
struct Bank *sub_0204B100(int count, u8 flag, u32 heapId);
u32 sub_0204B1CC(struct Bank *bank);
void sub_0204B22C(struct Bank *bank, u32 mode);
u32 sub_0204B248(struct Bank *bank);
void sub_0204B258(struct Bank *bank, void *p);
void sub_0204B270(struct Bank *bank);
struct Actor *sub_0204B294(void *owner, u32 i, u32 j, u32 k, const void *position, u16 f, u16 g);
struct Actor *func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g);
void sub_0204B3B4(struct Actor *p);
void sub_0204B3DC(struct Actor *p, u32 v);
u32 sub_0204B3F4(struct Actor *p);
void sub_0204B404(struct Actor *p, const struct Vec2 *delta, u32 which);
void sub_0204B454(struct Actor *actor, struct PtS *out, u16 space);
void sub_0204B49C(struct Actor *actor, s16 value, u32 space, u32 axis);
s16 sub_0204B4EC(struct Actor *actor, u32 space, u32 axis);
void sub_0204B528(struct Actor *actor, const struct Pt *src);
void sub_0204B53C(const struct Actor *actor, struct Pt *out);
void sub_0204B550(struct Actor *actor, signed short value, u32 axis);
s16 sub_0204B560(const struct Actor *actor, u32 axis);
void sub_0204B570(struct Actor *actor, u32 value);
void sub_0204B588(struct Actor *actor, const struct Pt *src);
void sub_0204B59C(struct Actor *o, signed short v, u32 sel);
void func_0204B5AC(struct Actor *dst, struct Pair *src);
void sub_0204B5C0(const struct Actor *o, struct Pair *p);
void sub_0204B5D4(struct Actor_0204B5D4 *actor, u32 value, u32 which);
u32 sub_0204B5E4(const struct Actor_0204B5D4 *actor, u32 which);
void sub_0204B5F4(struct Actor_0204B5F4 *actor, u16 value);
u16 sub_0204B5FC(const struct Actor_0204B5F4 *actor);
void func_0204B604(struct Actor_0204B604 *actor, u32 which, u32 set);
u32 sub_0204B658(const struct Actor_0204B658 *actor, u32 which);
void sub_0204B688(struct Actor_0204B688 *actor, u32 value);
u32 sub_0204B6E4(const struct Actor_0204B688 *actor);
void sub_0204B6F4(struct Obj_0204B6F4 *o, u32 v, u32 flag);
u32 sub_0204B714(struct Obj_0204B6F4 *o);
void sub_0204B728(struct Obj_0204B728 *o, const struct Xform *m);
void func_0204B764(const char *src, Struct20 *dst);
void func_0204B784(char *dst, const Struct36 *src);
void func_0204B7C8(const char *src, Struct36 *dst);
u16 func_0204B7F0(u8 *p);
u16 func_0204B7F8(u8 *p);
void func_0204B800(struct Node *node, u32 val);
int func_0204B838(int a0);
void func_0204B84C(S *p, unsigned int v);
u32 func_0204B864(u8 *a0);
void sub_0204B878(struct Obj_204B800 *p, u16 value);
u16 sub_0204B898(struct Obj_0204B898 *p);
void sub_0204B8A0(struct Obj_0204B898 *p, u16 v);
void sub_0204B8C4(struct Obj_0204B8C4 *p, u32 value);
void sub_0204B8D4(struct Obj_0204B8D4 *p, u32 arg);
u32 sub_0204B8F4(struct Obj_204B8F4 *p);
void func_0204B908(int a0, int a1);
u16 sub_0204B918(struct Obj_204B8F4 *p);
void sub_0204B92C(struct Obj_204B92C *p, u32 v);
u32 sub_0204B944(struct Obj_204B92C *p);
void func_0204B954(struct Actor_0204B954 *a, u32 v);
void func_0204B95C(struct Actor_0204B95C *a);
void func_0204B974(struct Actor_0204B974 *a);
u32 func_0204B98C(struct Actor_0204B98C *a);
void func_0204B9A0(struct Actor *a);
void func_0204B9C4(struct Actor_204B9C4 *a, u32 v);
void func_0204BA00(struct Actor_204B9C4 *a, const struct Cmd *cmd);
void func_0204BA10(struct Actor_204B9C4 *a);
void func_0204BA20(struct Actor_0204BA20 *a, u32 v);
void func_0204BA38(void *a, const s16 *src, u32 mode);
void func_0204BA7C(u32 set, u16 bias, u32 v);
void func_0204BAEC(u32 v);
u32 func_0204BB04(void);
void func_0204BB20(u32 v);
u32 func_0204BB38(void);
void func_0204BB54(void);
void func_0204BB8C(void);
void func_0204BBC8(struct Bank *bank);
void func_0204BC40(struct Bank *bank);
void func_0204BC94(struct Obj_0204A48C *o, u32 base, u32 count, u32 base2, u8 count2);
void func_0204BCD8(struct Obj_0204A48C *o);
void func_0204BCF4(struct Obj_0204A48C *o);
void func_0204BD18(struct Obj_0204A48C *o);
void func_0204BD3C(char *p, int a, int b, int which);
void func_0204BD64(struct Sub *s);
void func_0204BD7C(struct Sub *s);
void func_0204BD94(struct Obj_0204BD3C *obj, u8 *src, int count, u32 heap);
void func_0204BE28(int *p);
extern struct Sys *g_02146A74;
extern const char s_clact_c[];
extern const struct Templ g_020A1430;
extern struct Clact g_020A7F3C;


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
void sub_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId)
{
    u16 dims[6];
    int i;

    g_02146A74 = sub_02030734(heapId, sizeof(struct Sys), 0, s_clact_c, 0x28f);
    func_02082BCC(g_02146A74, 0, sizeof(struct Sys));

    dims[0] = cfg->unk_10;
    dims[1] = cfg->unk_12;
    dims[2] = cfg->unk_14;
    dims[3] = cfg->unk_16;
    dims[4] = cfg->unk_18;
    dims[5] = cfg->unk_1a;

    func_0204D7E0((struct Res *)((u8 *)g_02146A74 + 0x104), heapId, (const struct Cfg *)arg, (const struct Caps *)dims);
    func_0204BC94((struct Obj_0204A48C *)g_02146A74, cfg->unk_08, cfg->unk_09, cfg->unk_0a,
                  cfg->unk_0b);
    func_0204BA38((u8 *)g_02146A74 + 0x40, (const s16 *)cfg, heapId);
    func_0204C660((struct Pool *)((u8 *)g_02146A74 + 0xe0), cfg->unk_0c, heapId);

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
    func_0204BCD8((struct Obj_0204A48C *)g_02146A74);
    func_0204BE28((int *)((u8 *)g_02146A74 + 0x40));
    func_0204C6E4((struct Pool *)((u8 *)g_02146A74 + 0xe0));
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
    if (p->unk_0ec != 0) {
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

    func_0204BCF4((struct Obj_0204A48C *)g_02146A74);

    if (g_02146A74->unk_0ec != 0)
        func_0204C7A4((struct Table *)((char *)(u8 *)g_02146A74 + 0xe0));

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
    struct Owner *owner;
    struct Slot  *slot;
    u32 i;
    u32 handle;

    sys   = g_02146A74;
    owner = &sys->owner;

    for (i = 0; i < owner->count; i++) {
        if (owner->slots[i].unk_3c_31 != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i != (u32)-1) {
        slot   = &sys->owner.slots[i];
        handle = (u32)func_0204D9D4(a, b, c, (u16)((flags & 0x7fff) | 0x8000));

        func_0204E0D0(&g_02146A74->owner, i, handle, a3, 0);
        func_020307B0((void *)handle);

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
    struct Owner *owner;
    struct Slot  *slot;
    u32 i;
    struct Templ t;

    sys   = g_02146A74;
    owner = &sys->owner;

    for (i = 0; i < owner->count; i++) {
        if (owner->slots[i].unk_3c_31 != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i != (u32)-1) {
        slot = &sys->owner.slots[i];
        t = g_020A1430;
        t.w2 = *(volatile u32 *)0x04000000 & 0x00300010;
        t.w4 = size;
        t.w5 = sub_02030734((u16)((heapId & 0x7fff) | 0x8000), size, 1, s_clact_c, 0x3c8);

        sub_0204DACC((struct Res *)(&g_02146A74->owner), i, (struct Sink *)(&t), 0, a2);

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

    if (sub_02034640((struct Sentinel *)(&g_02146A74->owner.slots[i].unk_2c)) == 0) {
        sub_020346B8(g_02146A74->owner.unk_00, (struct Sentinel *)(&g_02146A74->owner.slots[i].unk_2c));
    }

    if (sub_02034640((struct Sentinel *)(&g_02146A74->owner.slots[i].unk_34)) == 0) {
        sub_020346B8(g_02146A74->owner.unk_04, (struct Sentinel *)(&g_02146A74->owner.slots[i].unk_34));
    }

    payload = g_02146A74->owner.slots[i].unk_24;
    if (payload != 0) {
        if (g_02146A74->owner.slots[i].unk_3c_0 == 0) {
            sub_020307B0(payload);
        } else {
            g_02146A74->owner.slots[i].unk_3c_0 = 0;
        }
        g_02146A74->owner.slots[i].unk_24 = 0;
    }

    g_02146A74->owner.slots[i].unk_3c_31 = 1;
    g_02146A74->owner.slots[i].unk_3c_1 = 0;
}


void func_0204A9D0(int a, struct Sub0204A9D0 *b)
{
    if (func_020637BC((const u32 *)((u32)g_02146A74->owner.slots + (a << 6)), 1) != 0) {
        void *p = (void *)func_020637B4((int *)((u32)g_02146A74->owner.slots + (a << 6)), 1);
        func_020862F0((void *)b->f14, b->f10);
        func_0207E780((void *)b->f14, p, b->f10);
    }
    if (func_020637BC((const u32 *)((u32)g_02146A74->owner.slots + (a << 6)), 2) == 0)
        return;
    {
        void *p = (void *)func_020637B4((int *)((u32)g_02146A74->owner.slots + (a << 6)), 2);
        func_020862F0((void *)b->f14, b->f10);
        func_0207E804((void *)b->f14, p, b->f10);
    }
}


void func_0204AA94(int a, void *b, u32 c, int d, int e)
{
    if (e == 0 || e == 2) {
        if (func_020637BC((const u32 *)((u32)g_02146A74->owner.slots + (a << 6)), 1) != 0) {
            void *p = (void *)func_020637B4((int *)((u32)g_02146A74->owner.slots + (a << 6)), 1);
            func_020862F0(b, c);
            func_0207E780(b, (char *)p + d, c);
        }
    }
    if (e == 1 || e == 2) {
        if (func_020637BC((const u32 *)((u32)g_02146A74->owner.slots + (a << 6)), 2) == 0)
            return;
        {
            void *p = (void *)func_020637B4((int *)((u32)g_02146A74->owner.slots + (a << 6)), 2);
            func_020862F0(b, c);
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
void func_0204AB84(u32 idx, struct Rec *dst)
{
    struct Rec *src = (struct Rec *)((u8 *)g_02146A74->owner.slots + idx * 64);

    *dst = *src;
}


/*
 * Snapshot one actor record into a local 36-byte buffer and hand it to
 * func_020637B4 with mode 1, or mode 2 when the second argument is set.
 */
int func_0204ABBC(u32 idx, u32 flag)
{
    struct Rec buf;
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
    struct Owner *owner;
    u32 i;
    u32 handle;

    owner = &g_02146A74->owner;

    for (i = 0; i < owner->count2; i++) {
        if (owner->slots2[i].unk_14_31 != 0) {
            goto found;
        }
    }
    i = (u32)-1;

found:
    if (i == (u32)-1) {
        return i;
    }

    handle = (u32)func_02049250(a, b, (u16)((g & 0x7fff) | 0x8000));

    func_0204DD08((struct Holder *)(&g_02146A74->owner), i, (void *)handle, (void *)c, d, e, f);
    func_020307B0((void *)handle);

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
    struct Owner *in = &g_02146A74->owner;
    u32 i;
    void *v;
    struct Slot2 *arr;

    for (i = 0; i < in->count2; i++) {
        arr = (struct Slot2 *)in->slots2;
        if (arr[i].unk_14_31 != 0)
            goto found;
    }
    i = -1;
found:
    if (i == (u32)-1)
        return (int)i;
    v = func_02049250(a0, a1, (u16)((a4 & 0x7fff) | 0x8000));
    func_0204DEE8((struct Holder *)(&g_02146A74->owner), i, v, (void *)a2, a3);
    func_020307B0(v);
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
    g_02146A74->owner.slots2[i].unk_14_31 = 1;
    g_02146A74->owner.slots2[i].unk_14_0 = 0;
}


/*
 * Flush both halves of one slot of the 0x18-byte-stride table at +0x110 of
 * the singleton behind 0x02146A74 into the destination the caller supplies.
 * Each half is guarded by func_0206380C, fetched with func_02063800 and
 * written through func_0207E51C (selector 1) or func_0207E5D0 (selector 2),
 * with func_020862F0 invalidating the destination first.
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

    if (func_0206380C((char *)(&g_02146A74->owner.slots2[idx]), 1) != 0) {
        void *src = (void *)func_02063800((char *)(&g_02146A74->owner.slots2[idx]), 1);

        func_020862F0(dest->unk_0c, size);
        func_0207E51C(dest->unk_0c, src, size);
    }

    if (func_0206380C((char *)(&g_02146A74->owner.slots2[idx]), 2) != 0) {
        void *src = (void *)func_02063800((char *)(&g_02146A74->owner.slots2[idx]), 2);

        func_020862F0(dest->unk_0c, size);
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
    *dest = g_02146A74->owner.slots2[idx].record;
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
    struct Owner *pool = &g_02146A74->owner;
    struct Entry3 *entry;
    s32 idx;

    struct Entry3 *entries;

    idx = 0;
    if ((u32)idx < pool->count3) {
        entries = pool->entries3;
        do {
            if (entries[idx].unk_10 != 0) {
                goto found;
            }
            idx++;
        } while ((u32)idx < pool->count3);
    }
    idx = -1;
found:
    entry = &g_02146A74->owner.entries3[idx];

    entry->unk_00 = func_02049250(owner, first, mode);
    entry->unk_04 = func_02049250(owner, second, mode);

    func_0204E074(&g_02146A74->owner, idx, entry->unk_00, entry->unk_04);

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
    struct Entry3 *s = &g_02146A74->owner.entries3[i];

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
struct Obj_0204B034 *func_0204B034(u8 *a0, u32 a1, u32 heap)
{
    struct Obj_0204B034 *p = (struct Obj_0204B034 *)func_02030734(heap, 0xa0, 0, s_clact_c, 0x633);

    func_0204BD94((struct Obj_0204BD3C *)p, a0, a1, heap);
    return p;
}


asm void func_0204B084(void)
{
    stmfd sp!, {r4, lr}
    mov	r4, r0
    bl func_0204BE28
    mov	r0, r4
    bl func_020307B0
    ldmfd sp!, {r4, pc}
}


/*
 * Unlabelled arm9 leaf (the label at 0x0204B09C also spans the next leaf at
 * 0x0204B0C8); witness for ov021 func_021A87A8. Writes a 16-bit x/y pair,
 * scaled to fx32, into entry idx (0x48 bytes each) of the table at +0x98.
 */
void func_0204B09C(EntryTable *o, int idx, Vec16 *v)
{
    int x = v->x;
    int y = v->y;
    Entry *e = &o->entries[idx];
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
void sub_0204B0C8(EntryTable *owner, u32 index, Vec16 *out)
{
    Entry *item = &owner->entries[index];

    out->x = item->x >> 12;
    out->y = item->y >> 12;
}


void func_0204B0F4(struct Actor *a0, int a1)
{
    func_0204BE38((struct Obj_0204A48C *)a0, a1);
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
    func_02082BCC(bank, 0, sizeof(struct Bank));

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
        if (bank->actors[i].unk_00 != 0) {
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
    bank->unk_08 = (u8 *)g_02146A74 + 0x40;
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
struct Actor *sub_0204B294(void *owner, u32 i, u32 j, u32 k,
                        const void *position, u16 f, u16 g)
{
    struct Request req;

    sub_0204CFA4((struct Req *)&req, i, j, (u32)&g_02146A74->owner.slots[i], (u32)&g_02146A74->owner.slots2[j],
                 g_02146A74->owner.entries3[k].unk_08, g_02146A74->owner.entries3[k].unk_0c);
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
struct Actor *func_0204B324(u32 owner, u32 i, u32 j, u32 k, u32 e, u16 f, u16 g)
{
    struct Request req;

    sub_0204CFA4((struct Req *)(&req), i, j, (u32)(&g_02146A74->owner.slots[i]), (u32)(&g_02146A74->owner.slots2[j]),
                 g_02146A74->owner.entries3[k].unk_08, g_02146A74->owner.entries3[k].unk_0c);
    return func_0204D048((void *)owner, (const struct Req *)e, &req, f, g);
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
    func_0204CA30(p->unk_08, (struct Node *)p);
    func_0204D104((struct Dispatchable *)(&p->ctl));
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
    p->unk_60_26 = v;
}


u32 sub_0204B3F4(struct Actor *p)
{
    return p->unk_60_26;
}


void sub_0204B404(struct Actor *p, const struct Vec2 *delta, u32 which)
{
    struct Vec2 pos;
    struct Vec2 dest;

    func_0204CF74(p, which, (u16 *)(&pos));
    dest.x = delta->x + pos.x;
    dest.y = delta->y + pos.y;
    func_0204B528((struct Actor *)p, (const struct Pt *)(&dest));
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
void sub_0204B454(struct Actor *actor, struct PtS *out, u16 space)
{
    struct PtS origin;

    func_0204CF74((struct Actor *)actor, space, (u16 *)&origin);
    sub_0204B53C(actor, (struct Pt *)out);

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
    struct PtS origin;

    func_0204CF74((struct Actor *)actor, space, (unsigned short *)&origin);

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
    struct PtS origin;
    s16        v;
    s16        o;

    func_0204CF74((struct Actor *)actor, space, (unsigned short *)&origin);
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
void sub_0204B528(struct Actor *actor, const struct Pt *src)
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
void sub_0204B53C(const struct Actor *actor, struct Pt *out)
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


void sub_0204B588(struct Actor *actor, const struct Pt *src)
{
    actor->unk_10.x = src->x;
    actor->unk_10.y = src->y;
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
        o->unk_10.x = v;
    } else {
        o->unk_10.y = v;
    }
}


/*
 * Unlabelled ARM leaf: copy two words from src into the pair at +0x14/+0x18
 * of dst.  `ldr r2,[r1]; ldr r1,[r1,#4]; str r2,[r0,#0x14]; str r1,[r0,#0x18]`.
 */
void func_0204B5AC(struct Actor *dst, struct Pair *src)
{
    struct Pair v = *src;

    dst->p = v;
}


void sub_0204B5C0(const struct Actor *o, struct Pair *p)
{
    p->x = o->p.x;
    p->y = o->p.y;
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
void sub_0204B5D4(struct Actor_0204B5D4 *actor, u32 value, u32 which)
{
    if (which == 0) {
        actor->unk_14 = value;
    } else {
        actor->unk_18 = value;
    }
}


u32 sub_0204B5E4(const struct Actor_0204B5D4 *actor, u32 which)
{
    if (which == 0) {
        return actor->unk_14;
    } else {
        return actor->unk_18;
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
void sub_0204B5F4(struct Actor_0204B5F4 *actor, u16 value)
{
    actor->unk_58 = value;
}


u16 sub_0204B5FC(const struct Actor_0204B5F4 *actor)
{
    return actor->unk_58;
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
void func_0204B604(struct Actor_0204B604 *actor, u32 which, u32 set)
{
    u32 mask = (which == 0) ? 1 : 2;

    if (set == 0) {
        actor->f_14 &= ~mask;
        return;
    }

    actor->f_14 |= mask;
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
u32 sub_0204B658(const struct Actor_0204B658 *actor, u32 which)
{
    u32 result = 0;

    if (which == 0) {
        if ((actor->f_14 & 1) != 0) {
            result = 1;
        }
    } else {
        if ((actor->f_14 & 2) != 0) {
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
void sub_0204B688(struct Actor_0204B688 *actor, u32 value)
{
    actor->f_16 = value;

    if (value == 0) {
        if ((actor->f_08 & 8) == 0) {
            return;
        }
        actor->f_08 = actor->f_08 ^ 8;
    } else {
        actor->f_08 = actor->f_08 | 8;
    }
}


u32 sub_0204B6E4(const struct Actor_0204B688 *actor)
{
    return actor->f_16;
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
void sub_0204B6F4(struct Obj_0204B6F4 *o, u32 v, u32 flag)
{
    o->bits60.fieldB = v;
    o->bits60.flag = flag;
}


u32 sub_0204B714(struct Obj_0204B6F4 *o)
{
    return (unsigned char)o->bits60.fieldB;
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
void sub_0204B728(struct Obj_0204B728 *o, const struct Xform *m)
{
    sub_0206380C((char *)m, 1);
    sub_0206380C((char *)m, 2);
    o->unk_40 = *m;
}


static inline void copy_inline1(const Struct36 *src, Struct36 *dst) {
    *dst = *src;
}


static inline void copy_inline2(Struct36 *dst, const Struct36 *src) {
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
 * struct local (`Struct36 s; ... s = *src; *(Struct36 *)(dst + 0x1c) = s;`),
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
void func_0204B764(const char *src, Struct20 *dst)
{
    const Struct20 *s = (const Struct20 *)(src + 0x40);
    *dst = *s;
}


void func_0204B784(char *dst, const Struct36 *src)
{
    Struct36 s;
    func_020637BC((void *)src, 1);
    func_020637BC((void *)src, 2);
    s = *src;
    *(Struct36 *)(dst + 0x1c) = s;
}


void func_0204B7C8(const char *src, Struct36 *dst)
{
    const Struct36 *s = (const Struct36 *)(src + 0x1c);
    *dst = *s;
}


/*
 * u16 field read at +0x5c.  Unlabelled in the current listings: the prologue
 * saves nothing, so disasm.py never auto-labelled it (see
 * docs/idioms/unlabelled-leaf-functions-hide-in-word-runs.md).  It sits
 * between the literal pool of func_0204B7C8 and func_0204B800.
 */
u16 func_0204B7F0(u8 *p)
{
    return ((struct Obj16080 *)p)->f5C;
}


/*
 * Same as func_0204B7F0 one field up, at +0x5e.  Unlabelled leaf for the
 * same reason.
 */
u16 func_0204B7F8(u8 *p)
{
    return ((struct Obj16081 *)p)->f5E;
}


/*
 * Field at +0x60 is an 8-bit bitfield in a whole word: the original is a
 * word load, and/bic/orr, word store, never a ldrb/strb.
 */
void func_0204B800(struct Node *node, u32 val)
{
    node->unk_060 = val;
    func_0204CA30(node->unk_008, node);
    func_0204C98C(node->unk_008, node);
}


int func_0204B838(int a0){ return (((unsigned int)((((struct Obj16082 *)((char *)(a0)))->f60 << 0x18)) >> 0x18) & 0xff); }


void func_0204B84C(S *p, unsigned int v)
{
    p->f60 = (p->f60 & ~0x30000) | ((v & 3) << 16);
}


u32 func_0204B864(u8 *a0)
{
    return (u8)((((struct Obj16083 *)a0)->f60 << 14) >> 30);
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
void sub_0204B878(struct Obj_204B800 *p, u16 value)
{
    p->unk_5a = value;
    func_0204D324((struct Obj0204D324 *)(&p->unk_68), value);
    func_0204B95C((struct Actor_0204B95C *)p);
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
u16 sub_0204B898(struct Obj_0204B898 *p)
{
    return p->unk_5a;
}


void sub_0204B8A0(struct Obj_0204B898 *p, u16 v)
{
    if (v == p->unk_5a) {
        return;
    }
    sub_0204B878((struct Obj_204B800 *)p, v);
    sub_0204B95C((struct Actor *)p);
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
void sub_0204B8C4(struct Obj_0204B8C4 *p, u32 value)
{
    sub_0204D3A0((struct Obj_0204B8C4 *)(&p->unk_68), value);
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
void sub_0204B8D4(struct Obj_0204B8D4 *p, u32 arg)
{
    sub_0204D4C4((struct Obj_0204B8D4 *)(&p->unk_68), arg);
    sub_0204D3C4((struct Obj_0204B8D4 *)(&p->unk_68), 0x1000);
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
u32 sub_0204B8F4(struct Obj_204B8F4 *p)
{
    return sub_0204D444((struct Obj_204B8F4 *)(&p->unk_68))->unk_10;
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
u16 sub_0204B918(struct Obj_204B8F4 *p)
{
    return sub_02062F1C(sub_0204D444((struct Obj_204B8F4 *)(&p->unk_68)));
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
void sub_0204B92C(struct Obj_204B92C *p, u32 v)
{
    p->unk_60_25 = v;
}


u32 sub_0204B944(struct Obj_204B92C *p)
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
void func_0204B954(struct Actor_0204B954 *a, u32 v)
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
void func_0204B95C(struct Actor_0204B95C *a)
{
    func_0204D410(&a->ctl)->flag = 1;
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
void func_0204B974(struct Actor_0204B974 *a)
{
    func_0204D410(&a->ctl)->flag = 0;
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
u32 func_0204B98C(struct Actor_0204B98C *a)
{
    return func_0204D444(&a->ctl)->value;
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
    func_0204D410(&a->ctl)->flag = 1;
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
void func_0204B9C4(struct Actor_204B9C4 *a, u32 v)
{
    struct Anim_204B9C4 *an;

    a->mode = v;

    an = (struct Anim_204B9C4 *)func_0204D410(&a->ctl);
    if (v == 0) {
        an->unk_08 = 0;
        an->unk_18 = 0;
    } else {
        an->unk_18 = v;
    }
}


void func_0204BA00(struct Actor_204B9C4 *a, const struct Cmd *cmd)
{
    func_0204D768(&a->ctl, cmd);
}


void func_0204BA10(struct Actor_204B9C4 *a)
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
void func_0204BA20(struct Actor_0204BA20 *a, u32 v)
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
void func_0204BA38(void *a, const s16 *src, u32 mode)
{
    g_020A7F3C.rec[0].x = src[0];
    g_020A7F3C.rec[0].y = src[1];
    g_020A7F3C.rec[1].x = src[2];
    g_020A7F3C.rec[1].y = src[3];

    func_0204BD94((struct Obj_0204BD3C *)a, (u8 *)g_020A7F3C.rec, 2, mode);
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

    g_02146A74->unk_0f4 = v;
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

    func_0204BD18((struct Obj_0204A48C *)g_02146A74);
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
        func_0204C944((struct Ring *)cur);
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
void func_0204BC94(struct Obj_0204A48C *o, u32 base, u32 count, u32 base2, u8 count2)
{
    func_02063078();
    func_0204BD3C((char *)(&o->w[0]), base, count, 0);
    func_0204BD3C((char *)(&o->w[1]), base2, count2, 1);
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
void func_0204BCD8(struct Obj_0204A48C *o)
{
    func_0204BD18((struct Obj_0204A48C *)o);
    func_0204BCF4((struct Obj_0204A48C *)o);
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
void func_0204BCF4(struct Obj_0204A48C *o)
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
void func_0204BD18(struct Obj_0204A48C *o)
{
    int i;

    for (i = 0; i < 2; i++) {
        func_0204BD7C(&o->w[i]);
    }
}


void func_0204BD3C(char *p, int a, int b, int which)
{
    if (b == 0) {
        ((struct Obj11428 *)p)->f1C = 0;
        return;
    }
    func_02063138(p, a, b, which);
    ((struct Obj11428 *)p)->f1C = 1;
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
void func_0204BD64(struct Sub *s)
{
    if (s->bound == 0) {
        return;
    }

    func_0206343C((struct NNSG2dOamManagerInstance *)s, s->bound);
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
void func_0204BD7C(struct Sub *s)
{
    if (s->bound == 0) {
        return;
    }

    func_02063640((struct NNSG2dOamManagerInstance *)s);
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
void func_0204BD94(struct Obj_0204BD3C *obj, u8 *src, int count, u32 heap)
{
    u32 i;

    func_02065AA8((u8 *)obj);
    obj->f80 = 1;
    obj->f98 = (u32)func_02030734(heap, count * 0x48, 0, s_clact_c, 0xfc7);
    obj->f9c = count;
    for (i = 0; i < count; i++) {
        func_0204BE84((void *)(obj->f98 + i * 0x48), src + i * 0x10);
        func_02065B64((int)obj, (void *)(obj->f98 + i * 0x48));
    }
}


void func_0204BE28(int *p){ func_020307B0((void *)p[0x26]); }
