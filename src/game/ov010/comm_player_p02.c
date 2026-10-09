/*
 * file:     comm_player_p02.c
 * unit:     yes
 * function: func_02167BFC, func_02167CB4, func_02167CF4, func_02167D00, func_02167D44, func_02167DB8, func_02167DEC, func_02167E28, func_02167E54, func_02167E88, func_02167EAC, func_02167ED0, func_02167EF4, func_02167FB4, func_021680C8, func_02168174, func_021681C8, func_021684E8, func_0216869C, func_02168800, func_0216880C, func_02168824, func_0216883C, func_02168878
 * address:  0x02167BFC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02167B44  0x02167B44  thumb
 *   func_02167B9C  0x02167B9C  thumb
 *   func_02167BB4  0x02167BB4  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008494  0x02008494  thumb
 *   func_02167BCC  0x02167BCC  thumb
 *   func_02167BD8  0x02167BD8  thumb
 *   func_02167BE4  0x02167BE4  thumb
 *   func_02167BF0  0x02167BF0  thumb
 *   func_0200FB24  0x0200FB24  thumb
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_02039338  0x02039338  arm
 *   func_02082D44 0x02082D44 arm
 *   func_0201210C 0x0201210C thumb
 *   func_020122C0 0x020122C0 thumb
 *   func_020124E8 0x020124E8 thumb
 *   func_0201A364 0x0201A364 thumb
 *   func_020120F4 0x020120F4 thumb
 *   func_0200CA1C 0x0200CA1C thumb
 *   func_02082BCC 0x02082BCC arm
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0200CA38 0x0200CA38 thumb
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_020144DC  0x020144DC  thumb
 *   func_02014910  0x02014910  thumb
 *   func_020145CC  0x020145CC  thumb
 *   func_021BE92C  0x021BE92C  thumb  ov021
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   func_02188C54  0x02188C54  thumb ov021
 *   func_020457B0  0x020457B0  arm
 *   func_02045B38  0x02045B38  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_02045C04  0x02045C04  arm
 *   func_0202435C  0x0202435C  thumb
 *   func_02012964  0x02012964  thumb
 *   func_0216DE94  0x0216DE94  thumb
 *   func_0216D88C  0x0216D88C  thumb
 *   func_0219129C  0x0219129C  thumb ov021
 *   func_02191388  0x02191388  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_021912D8  0x021912D8  thumb
 *   func_021912F8  0x021912F8  thumb
 *   func_02045808  0x02045808  arm
 *   func_021AA304  0x021AA304  thumb  ov021
 *   func_02013090  0x02013090  thumb
 *   func_02013610  0x02013610  thumb
 *   func_02013644  0x02013644  thumb
 *   func_02013734  0x02013734  thumb
 *   func_02013810  0x02013810  thumb
 *   func_02013980  0x02013980  thumb
 *   func_0201A954  0x0201A954  thumb
 *   func_020173EC  0x020173EC  thumb
 *   func_02030734  0x02030734  arm
 *   func_02017528  0x02017528  thumb
 *   func_02019CE0  0x02019CE0  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_02019CA0  0x02019CA0  thumb
 *   func_020307B0  0x020307B0  arm
 *   func_02045924  0x02045924  arm
 *   func_0202428C  0x0202428C  thumb
 *   func_02168AC8  0x02168AC8  thumb  ov010
 *   func_0201394C  0x0201394C  thumb
 *   d_02172A2C     0x02172A2C  data
 *   MI_CpuFill8    0x02082BCC  arm
 *   func_020186C8  0x020186C8  thumb
 *   _s32_div_f     0x0209C0A4  arm
 *   func_02019C90  0x02019C90  thumb
 *   sub_02045B38   0x02045B38  arm
 *   func_02045F5C  0x02045F5C  arm
 *   d_02172084     0x02172084  data
 *   func_02017588  0x02017588  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_020185B0  0x020185B0  thumb
 *   func_02045A98  0x02045A98  arm
 *   func_02018430  0x02018430  thumb
 *   func_02048F4C  0x02048F4C  arm
 *   func_0204A1BC  0x0204A1BC  arm
 *   func_020056EC  0x020056EC  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 *   func_021688BC  0x021688BC  thumb
 *   func_02168924  0x02168924  thumb
 */
#include "../../matched/include/Obj00116.h"
#include "../../matched/include/Obj09320.h"
#include "../../matched/include/Obj07315.h"
#include "../../matched/include/Obj12375.h"
#include "../../matched/include/Obj12376.h"
#include "../../matched/include/Obj12377.h"
#include "../../matched/include/Obj07204.h"
#include "../../matched/include/Obj09162.h"

struct Entry;
struct Blk37;
struct Ctx;
struct Desc;
struct Obj;
struct SeqWork;
struct Evt;
struct Party;
struct PartyMon;
struct BigObj;
struct Ent;
struct MsgBank;
struct Rec;
struct U16Vec;
struct Actor;
struct VecFx32;
struct Strbuf;
struct BattleMon;
struct Obj02013734;
struct RecDC;
struct Sav;
struct ZoneData;
struct MsgData;
struct Mon;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef unsigned long long u64;

typedef struct Blk12 {
    u64 lo;
    u32 hi;
} Blk12;

typedef struct Ent {
    Blk12 pos;
    u32 f0c;
    u16 f10;
    u16 f12;
    u8 used : 1;
    u8 pend : 1;
    u8 dir : 4;
    u8 f15[3];
    u32 f18;
} Ent;

typedef struct Work {
    void *sys;
    void *obj;
    Ent e[4];
} Work;

typedef struct Obj_02167BFC {
    u8 pad00[0x12];
    u16 h12;
    u8 pad14[0x668 - 0x14];
    u8 b668[0x20];
} Obj_02167BFC;

typedef struct Obj_02167CB4 {
    u8 pad00[0x12];
    u16 h12;
    u8 pad14[0x668 - 0x14];
    u8 b668[0x1C];
} Obj_02167CB4;

typedef struct Obj {
    u8 pad00[0x724];
    u8 b724;
    u8 b725;
    u8 pad726[2];
    u16 h728;
} Obj;

typedef struct {
    u8 pad0[0xb];
    u8 f0b;
    u16 lo : 5;
    u16 hi : 3;
    u16 rest : 8;
    u8 pad1[0xa];
    u16 f18;
    u16 f1a;
    u16 f1c;
    u8 pad2[4];
    u16 f22;
    u16 f24;
    u8 pad3[0x724 - 0x26];
    u8 f724;
    u8 pad4[3];
    u16 f728;
} D;

typedef struct {
    u8 pad[0xc];
    u16 low : 3;
    u16 flag : 1;
    u16 high : 12;
} Flags;

typedef struct 
{
  u8 pad0[8];
  int f8;
  u8 fc;
  u8 fd;
  u8 fe;
  u8 ff;
  u8 f10;
  u8 pad11[7];
  int f18;
} T;

typedef struct 
{
  u8 pad0[0x14];
  u8 *f14;
  u8 pad18[0x1c];
  int f34;
  int f38;
} Q;

typedef struct 
{
  int f0;
  int f4;
  int f8;
  u8 padc[0x30 - 0xc];
  int f30;
  u8 pad34[0xc8 - 0x34];
  u8 buf[0x184 - 0xc8];
  int f184;
  int f188;
  int f18c;
  int f190;
  int f194;
} P;

typedef struct SeqWork {
    u32 heap;           /* 0x000 */
    void *arg;          /* 0x004 */
    u8 f08[0x28];       /* 0x008 */
    u8 f30[0x3C];       /* 0x030 */
    u32 f6c;            /* 0x06C */
    u32 f70;            /* 0x070 */
    u8 pad74[5];
    u8 order[6];        /* 0x079 */
    u8 pad7F[0x105];
    u32 *out184;        /* 0x184 */
    u32 *out188;        /* 0x188 */
    u8 *order18c;       /* 0x18C */
    void *party190;     /* 0x190 */
    void *party194;     /* 0x194 */
} SeqWork;

typedef struct {
    u8 pad0[0x18];
    u16 f18;
    u16 f1a;
    u8 pad1c[0x120 - 0x1c];
} E;

typedef struct {
    int f0;
    int f4;
    int f8;
    int fc;
    int f10;
    int f14;
} R;

typedef signed int s32;

struct Info { u32 f00; u32 f04; u8 f08; u8 f09; u16 f0A; u8 f0C; u8 f0D; u8 pad0E[2]; };

typedef struct { u8 raw[0x3C]; } BattleMon;

typedef struct { u16 v[8]; } W8;

typedef enum { SIDE_0, SIDE_1, SIDE_2, SIDE_3 } Side;

typedef struct Rec {
    u32 f00;
    u16 f04;
    u8 pad06[2];
    u8 f08[0x18];
    W8 w20;
    BattleMon mons[4];
} Rec;

typedef struct Spr {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[8];
    struct Strbuf *f14;
    W8 w18;
} Spr;

typedef struct Bs {
    u8 pad00[0x22];
    u8 f22;
    u8 pad23;
    struct Party *f24[4];
    u8 *f34[4];
    u8 pad44[4];
    Spr *f48[4];
} Bs;

typedef struct FacRec {
    u16 species;        /* 0x00 */
    u16 moves[4];       /* 0x02 */
    u8 evMask;          /* 0x0A */
    u8 nature;          /* 0x0B */
    u16 item;           /* 0x0C */
    u16 form;           /* 0x0E */
} FacRec;

typedef struct BattleMon_021684E8 {
    u16 species : 11;   /* 0x00 */
    u16 form : 5;
    u16 item;           /* 0x02 */
    u16 moves[4];       /* 0x04 */
    u32 otId;           /* 0x0C */
    u32 pid;            /* 0x10 */
    u32 hpIv : 5;       /* 0x14 */
    u32 atkIv : 5;
    u32 defIv : 5;
    u32 speIv : 5;
    u32 spaIv : 5;
    u32 spdIv : 5;
    u32 ivRest : 2;
    u8 ev[6];           /* 0x18 */
    u8 ppUps;           /* 0x1E */
    u8 lang;            /* 0x1F */
    u8 ability;         /* 0x20 */
    u8 friendship;      /* 0x21 */
    u16 nick[11];       /* 0x22 */
    u8 nature;          /* 0x38 */
} BattleMon_021684E8;

typedef struct BattleMon_0216869C {
    u16 species : 11;   /* 0x00 */
    u16 form : 5;
    u16 item;           /* 0x02 */
    u16 moves[4];       /* 0x04 */
    u32 otId;           /* 0x0C */
    u32 pid;            /* 0x10 */
    u32 ivs;            /* 0x14 */
    u8 ev[6];           /* 0x18 */
    u8 ppUps;           /* 0x1E */
    u8 lang;            /* 0x1F */
    u8 f20;             /* 0x20 */
    u8 f21;             /* 0x21 */
    u16 nick[11];       /* 0x22 */
    u8 f38;             /* 0x38 */
} BattleMon_0216869C;

extern void func_02167B44(Obj_02167BFC *o, void *t);
extern void func_02167B9C(Obj_02167BFC *o);
extern void func_02167BB4(Obj_02167BFC *o, u32 v);
extern u8 *func_02012944(void *p);
extern void func_02008494(void *a, void *b);
extern void func_02167BCC(Obj_02167BFC *o);
extern void func_02167BD8(Obj_02167BFC *o, u32 v);
extern void func_02167BE4(Obj_02167BFC *o, u32 v);
extern void func_02167BF0(Obj_02167BFC *o, u32 v);
extern u32 func_0200FB24(void);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u16 func_02039338(void);
extern void func_02082D44(void *, void *, unsigned int);
extern void *func_0201210C(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern void func_0201A364(int a, unsigned int b);
extern void *func_020120F4(const struct Ctx *p);
extern int func_0200CA1C(void);
extern void func_02082BCC(void *, int, int);
extern u32 func_0201AA18(void *p);
extern u32 func_0200CA38(struct Blk37 *p);
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern int func_020144DC(int a0, int a1);
extern void *func_02014910(char *a0, int a1, int a2, int a3);
extern void *func_020145CC(void *a0);
extern int func_021BE92C(void *a, int b, int sel, int d, int e, u8 f, u8 g);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_0201AA14(void *p);
extern void *func_0201AB28(void *p, u32 idx);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
extern u32 func_02188C54(u8 *p);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_0202435C(void *slots, unsigned int heap);
extern u32 func_02012964(const struct BigObj *p);
extern void *func_0216DE94(void *map, u32 id);
extern void func_0216D88C(const struct Actor *, struct VecFx32 *);
extern struct Ent *func_0219129C(u8 *base, int idx, u32 c, u32 d, u32 f, u32 g);
extern int func_02191388();
extern u32 func_020362DC(void);
extern int func_021912D8();
extern int func_021912F8();
extern int func_02045808();
extern void func_021AA304(struct Info *out, void *a1, void *a2);
extern void *func_02013090(u32 heap);
extern void func_02013610(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013644(u8 *p, u32 a, u32 b, u32 c, u16 d);
extern void func_02013734(struct Obj02013734 *o, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02013810(u8 *o, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u32 a6, u16 a7);
extern void func_02013980(struct ZoneData *o, u32 heap);
extern void func_0201A954(struct Party *p, s32 capacity);
extern u32 func_020173EC(void);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void func_02017528(struct Sav *p);
extern void func_02019CE0(const struct RecDC *src, struct RecDC *dest);
extern u32 func_02017E1C(void *p, u32 id, u32 v);
extern void func_02019CA0(void *p, u32 v);
extern u32 func_020307B0(void *p);
extern void func_02045924(struct Strbuf *o, const u16 *src);
extern void func_0202428C(void *p);
extern int func_02168AC8(int a0);
extern void func_0201394C(struct ZoneData *o);
extern void MI_CpuFill8(void *dst, u8 val, u32 size);
extern u32 func_020186C8(u32 a0, int a1, int a2, int a3, int a4, int a5);
extern u32 func_02019C90(u16 a, u16 b, u32 k);
extern struct MsgBank *sub_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern void func_02045F5C(struct MsgData *msg, u32 msgIndex, u16 *str, u32 maxLen);
extern void func_02017588(struct Mon *p, u16 species, u16 level, unsigned long long id, u32 pow, unsigned long long rnd);
extern void func_02017E40(void *p, u32 id, u32 v);
extern void func_020185B0(void *p, u32 v);
extern u16 func_02045A98(void);
extern u32 func_02018430(void *p);
extern void func_02048F4C(void *dst, u32 archive_id, u32 member);
extern int func_0204A1BC(int a0, int a1, int a2, int a3);
extern u32 func_020056EC(u32 range);
extern int func_0209C2B0();
extern int func_021688BC(u8 *, int, u16);
extern int func_02168924(int, int, u8 *, u8, int, int, int, u16);
void func_02167BFC(Obj_02167BFC *o, u32 cmd, u32 arg);
int func_02167CB4(Obj_02167CB4 *o);
void func_02167CF4(u8 *w, u8 v);
int func_02167D00(Obj *o, u16 *out);
void func_02167D44(int a, int b, const u16 *c, D *d);
void func_02167DB8(u16 a, int b, void *c, u8 *p);
void func_02167DEC(u16 a, int b, u16 *c, u8 *p);
void func_02167E28(u16 a, int b, void *c, u8 *p);
void func_02167E54(u16 a, int b, u16 *c, u8 *p);
void func_02167E88(u16 a, int b, u16 *c, u8 *p);
void func_02167EAC(u16 a, int b, u16 *c, u8 *p);
void func_02167ED0(u16 a, int b, u16 *c, u8 *p);
int func_02167EF4(int a, int b, int c, int d, int e, int f, int g, int h, int i);
int func_02167FB4(void *evt, u32 *seq, SeqWork *w);
int func_021680C8(int a, E *b, int c, int d);
int func_02168174(int a0, int a1, int a2);
Bs *func_021681C8(void *sys, void *partyA, u32 mode0, Rec *recA, Rec *recB, int n);
u32 func_021684E8(BattleMon_021684E8 *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap);
void func_0216869C(const BattleMon_0216869C *src, void *mon);
void func_02168800(void *dst, u32 member);
void *func_0216880C(u32 group, u32 heap);
int func_02168824(void);
u8 func_0216883C(u32 n);
int func_02168878(u8 *a, int b, int c, int d, int e, int f, u16 g);
extern const char d_02172A2C[];
extern const u16 d_02172084[];





/*
 * evidence: 0x02008494 is an unlabelled ARM9 thunk ("ldr r3, =func_02082D44; movs r2, #0x20; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov018 0x0217FDEC, ov021 0x021CD548, ov088 0x021BC32A and more), so the call
 * attests as `label`.
 */
void func_02167BFC(Obj_02167BFC *o, u32 cmd, u32 arg)
{
    void *t;

    t = ((struct Obj00116 *)o)->f6C;
    switch (cmd) {
    case 0:
        o->h12 = 0x2C00;
        func_02167B44(o, t);
        return;
    case 1:
        o->h12 = 0x2C01;
        func_02167B9C(o);
        return;
    case 2:
        o->h12 = 0x2C02;
        func_02167BB4(o, arg);
        return;
    case 3:
        o->h12 = 0x2C03;
        func_02008494(func_02012944(t), o->b668);
        return;
    case 4:
        o->h12 = 0x2C04;
        func_02167BCC(o);
        return;
    case 5:
        o->h12 = 0x2C05;
        func_02167BD8(o, arg);
        return;
    case 6:
        o->h12 = 0x2C06;
        func_02167BE4(o, arg);
        return;
    case 7:
        o->h12 = 0x2C07;
        func_02167BF0(o, arg);
        return;
    default:
        o->h12 = 0x2C08;
        return;
    }
}





int func_02167CB4(Obj_02167CB4 *o)
{
    u16 h;

    if (func_0200FB24() != 0)
        return 1;
    h = o->h12;
    if (h >= 0x2C08)
        return 1;
    if (func_0203D3A8(func_020399A8(), h, 0x46, (u32)o->b668) == 1)
        return 1;
    return 0;
}






/*
 * Byte setter at +0x725. bl from ov021 func_021CA5C4 at 0x021CB596.
 */
void func_02167CF4(u8 *w, u8 v)
{
    w[0x725] = v;
}






int func_02167D00(Obj *o, u16 *out)
{
    int want;

    if (func_0200FB24() != 0)
        return 1;
    want = 1;
    if (o->b725 != 1)
        want = 2;
    if (o->b724 == want) {
        o->b724 = 0;
        if (out != 0)
            *out = o->h728;
        return 1;
    }
    return 0;
}






/*
 * lever: Const source halfwords restores c[0]/c[1] load scheduling.
 */
void func_02167D44(int a, int b, const u16 *c, D *d)
{
    u16 n = 0;
    u16 w;
    u16 v;
    d->f724++;
    if (a != func_02039338()) {
        w = c[0];
        v = c[1];
        d->f0b = w;
        d->f1a = v;
        d->f1c = c[2];
        d->f18 = c[3];
        d->hi = d->f0b + 5;
        if (d->f22 == v || d->f22 == d->f1c)
            n += 1;
        if (d->f24 == v || d->f24 == d->f1c)
            n += 2;
        d->f728 = n;
    }
}





void func_02167DB8(u16 a, int b, void *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338() && func_02039338() != 0)
        func_02082D44(c, p + 0x32, 0x1c);
}





void func_02167DEC(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338()) {
        ((struct Obj09320 *)p)->f728 = 0;
        if (((Flags *)p)->flag != 0 || *c != 0)
            ((struct Obj09320 *)p)->f728 = 1;
    }
}





void func_02167E28(u16 a, int b, void *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338())
        func_02082D44(c, p + 0x72c, 0x20);
}





void func_02167E54(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338()) {
        if (p[9] != *c)
            ((struct Obj07315 *)p)->f728 = 0;
        else
            ((struct Obj07315 *)p)->f728 = 1;
    }
}





void func_02167E88(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338())
        ((struct Obj12375 *)p)->f728 = *c;
}





void func_02167EAC(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338())
        ((struct Obj12376 *)p)->f728 = *c;
}





void func_02167ED0(u16 a, int b, u16 *c, u8 *p)
{
    p[0x724]++;
    if (a != func_02039338())
        ((struct Obj12377 *)p)->f728 = *c;
}





/*
 * lever: named temporaries keep Q+0x30 live across0201A364; bounded permuter47 compiles found byte-correct192.
 * Interface evidence: ov019_func_0217BA10.c records r0->r2, r1->r0, r1=0x69, jump via02048F4C. Original caller supplies d in r0 and p->buf in r1.
 * TU: MATCH192,9/10 relocations; suggest-split leaves sole function OUT.
 * checks: 1 020124E8 takes live hd from122C0, own matched accessor reads+0xc; 2 family/neighbours reread, no full twin; 3 unsigned b/c each retain31 before search; 4 pointer-copy idiom read; 5 neighbours/idioms reread, frame is scalar spills, no stack aggregate.
 * permuter: once budget300 types, emitted baseline agreed31/192; stopped at47 with MATCH; fixed one confirmsMATCH192.
 */
int func_02167EF4(int a, int b, int c, int d, int e, int f, int g, int h, int i)
{
  P *p;
  Q *q;
  T *t;
  int r7;
  int s;
  int hd;
  int x;
  Q *tmp1;
  u8 *tmp2;
  P *tmp3;
  u8 tmp;
  x = (int)func_0201210C((const struct Ctx *)a);
  hd = (int)func_020122C0((void *)a, 0, func_02167FB4, 0x198);
  tmp3 = func_020124E8((struct Obj *)hd);
  p = tmp3;
  q = (Q *) p;
  p->f0 = a;
  p->f4 = x;
  p->f18c = f;
  p->f188 = g;
  p->f184 = h;
  p->f190 = e;
  tmp2 = ((u8 *) q) + 0x30;
  p->f194 = i;
  tmp1 = (Q *) tmp2;
  func_0201A364(d, (unsigned int)p->buf);
  q = tmp1;
  p->f30 = e;
  q->f14 = p->buf;
  q->f38 = b;
  q->f34 = c;
  t = (T *) (((u8 *) p) + 8);
  r7 = (int)func_020120F4((const struct Ctx *)a);
  s = func_0200CA1C();
  func_02082BCC(t, 0, 0x28);
  p->f8 = e;
  t->fc = 1;
  tmp = func_0201AA18((void *)e);
  t->fe = tmp;
  t->fd = 0;
  t->f10 = 0;
  t->f8 = r7;
  t->f18 = func_0200CA38((struct Blk37 *)s);
  return hd;
}






/*
 * Sub-process sequence: runs five child processes one after another
 * (two from ov021, three from arm9), copying the result of the fifth
 * back and re-adding the chosen party members.
 *
 * First draft plus one lever (2026-09-28 tree_ov010_4): w->heap read into
 * a local before the switch. The member index is taken before the range
 * fix-up, so a reset slot still passes its old index (the image does not
 * reload it).
 */
int func_02167FB4(void *evt, u32 *seq, SeqWork *w)
{
    int n;
    int i;
    int idx;
    u32 heap;

    heap = w->heap;
    switch (*seq) {
    case 0:
        func_02012374(evt, (struct Evt **)func_021BE8D4((void *)heap, (int)w->arg, 0, 0));
        (*seq)++;
        break;
    case 1:
        func_02012374(evt, (struct Evt **)func_020144DC(heap, (int)w->arg));
        (*seq)++;
        break;
    case 2:
        func_02012374(evt, func_02014910((char *)heap, (int)w->arg, (int)w->f30, (int)w->f08));
        (*seq)++;
        break;
    case 3:
        func_02012374(evt, func_020145CC((void *)heap));
        (*seq)++;
        break;
    case 4:
        func_02012374(evt, (struct Evt **)func_021BE92C((void *)heap, (int)w->arg, 0, 0, 1, 0, 0));
        MI_CpuCopy8(w->order, w->order18c, 6);
        *w->out188 = w->f6c;
        *w->out184 = w->f70;
        if (*w->out188 != 7 && *w->out188 != 8 && w->party194 != 0) {
            n = func_0201AA14(w->party194);
            for (i = 0; i < n; i++) {
                idx = w->order18c[i] - 1;
                if (idx >= 6)
                    w->order18c[i] = 1;
                func_0201A98C(w->party194, func_0201AB28(w->party190, idx));
            }
        }
        (*seq)++;
        break;
    case 5:
        return 1;
    }
    return 0;
}




/*
 * evidence: 0x0202435C is an unlabelled ARM9 thunk ("ldr r3, =func_02024368; movs r2, #2; bx r3") that the
 * prologue sweep misses; its start is seeded in layout/function_starts.txt
 * from the raw bl sites elsewhere in the image (ov069 0x021BA21A, ov093 0x021D1894, ov010 0x0216C778), so the call
 * attests as `label`.
 */
int func_021680C8(int a, E *b, int c, int d)
{
    int hd;
    int h;
    int g;
    R *p;
    h = (int)func_020120F4((const struct Ctx *)a);
    g = func_02188C54(func_0201210C((void *)a));
    hd = (int)func_020122C0((void *)a, 0, func_02168174, 0x1c);
    p = func_020124E8((struct Obj *)hd);
    p->f0 = a;
    if (b->f18 == 0xFFFF) {
        int t;
        p->f14 = (int)func_020457B0(0x5c, 4);
        t = (int)func_02045B38(0, 2, 0xb8, 4);
        func_02045CAC((struct MsgBank *)t, b->f1a, (void *)p->f14);
        func_02045C04((struct Rec *)t);
    } else {
        p->f14 = (int)func_0202435C(&b[c].f18, 4);
    }
    func_0216D88C((const struct Actor *)func_0216DE94((void *)func_02012964((const struct BigObj *)h), d), (struct VecFx32 *)&p->f4);
    p->f10 = (int)func_0219129C((u8 *)g, 1, (u32)(&p->f4), p->f14, 0, 0);
    return hd;
}




int func_02168174(int a0, int a1, int a2)
{
    int t4;
    int t5;

t5 = a1 + 0;
a0 = ((struct Obj09162 *)((char *)t5))->f0;
t4 = a2 + 0;
    if (a0 == 0) goto loc_0216818A;
loc_02168180:
    if (a0 == 1) goto loc_0216819C;
loc_02168184:
    if (a0 == 2) goto loc_021681AE;
loc_02168188:
    goto loc_021681C2;
loc_0216818A:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = func_02191388(a0);
loc_02168190:
    if (a0 != 1) goto loc_021681C2;
loc_02168194:
a0 = ((struct Obj09162 *)((char *)t5))->f0;
a0 = a0 + 1;
((struct Obj09162 *)((char *)t5))->f0 = a0;
    goto loc_021681C2;
loc_0216819C:
    a0 = func_020362DC();
loc_021681A0:
a1 = 3;
    if ((a0 & a1) == 0) goto loc_021681C2;
loc_021681A6:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = func_021912D8(a0);
loc_021681AC:
    goto loc_02168194;
loc_021681AE:
a0 = ((struct Obj07204 *)t4)->f10;
    a0 = func_021912F8(a0);
loc_021681B4:
    if (a0 != 1) goto loc_021681C2;
loc_021681B8:
a0 = ((struct Obj07204 *)t4)->f14;
    a0 = func_02045808(a0);
loc_021681BE:
a0 = 1;
    return a0;
loc_021681C2:
a0 = 0;
    return a0;}




/*
 * Builds the battle-intro sprite set: a func_02013090 object, one party
 * list per side filled from 0x3C-byte records through func_0216869C.
 * Levers: side ids are an enum (an int index folds to a constant offset);
 * the mode truncation is a u16 local copied from a u32 parameter; the
 * mode==4 and func_02168AC8 arms each carry their own copy of the eight
 * halfword stores (the cross-jump leaves the `b` into the second copy);
 * one party local per side block sets the spill slots; the sprite pointer
 * of the third block is read before the record pointer moves.
 */
Bs *func_021681C8(void *sys, void *partyA, u32 mode0, Rec *recA, Rec *recB, int n)
{
    u16 mode;
    struct Info info;
    Bs *bs;
    void *ctx;
    void *mon;
    struct Party *party;
    struct Party *partyB;
    struct Party *partyC;
    struct Party *partyD;
    Spr *o;
    int i;
    Side k;
    int flag;
    void *e;
    u8 *vec;
    Rec *recC;

    ctx = func_020120F4((const struct Ctx *)sys);
    mode = mode0;
    func_021AA304(&info, ctx, func_0201210C((const struct Ctx *)sys));
    bs = func_02013090(4);
    switch (mode) {
    case 0:
    case 4:
    case 5:
        func_02013610((u8 *)bs, (u32)ctx, (u32)(&info), 0, 4);
        break;
    case 1:
    case 6:
        func_02013644((u8 *)bs, (u32)ctx, (u32)(&info), 0, 4);
        break;
    case 2:
    case 7:
        func_02013734((struct Obj02013734 *)bs, (u32)ctx, (u32)(&info), 0, 0, 0, 4);
        break;
    case 3:
    case 8:
        e = func_020399A8();
        flag = 0;
        if (func_02039338() != 0)
            flag = 2;
        func_02013810((u8 *)bs, (u32)ctx, (u32)e, 1, flag, 0, 0, 4);
        break;
    }
    func_02013980((struct ZoneData *)bs, 4);

    k = SIDE_0;
    i = 0;
    vec = func_02012944(ctx);
    bs->f34[k] = vec;
    party = bs->f24[k];
    func_0201A954(party, 6);
    mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x253);
    func_02017528(mon);
    for (; i < n; i++) {
        e = func_0201AB28(partyA, i);
        func_02019CE0(e, mon);
        if (func_02017E1C(e, 0x9E, 0) != 0x32)
            func_02019CA0(mon, 0x32);
        func_0201A98C(party, mon);
    }
    func_020307B0(mon);

    k = SIDE_1;
    o = bs->f48[k];
    o->f00 = recA->f00;
    o->f04 = recA->f04;
    o->f08 = 0x87;
    func_02045924(o->f14, (const u16 *)recA->f08);
    func_0202428C(&o->w18.v[0]);
    func_0202428C(&o->w18.v[4]);
    if (mode == 4) {
        o->w18.v[0] = recA->w20.v[0];
        o->w18.v[1] = recA->w20.v[1];
        o->w18.v[2] = recA->w20.v[2];
        o->w18.v[3] = recA->w20.v[3];
        o->w18.v[4] = recA->w20.v[4];
        o->w18.v[5] = recA->w20.v[5];
        o->w18.v[6] = recA->w20.v[6];
        o->w18.v[7] = recA->w20.v[7];
    } else if (func_02168AC8((int)recA) != 0) {
        o->w18.v[0] = recA->w20.v[0];
        o->w18.v[1] = recA->w20.v[1];
        o->w18.v[2] = recA->w20.v[2];
        o->w18.v[3] = recA->w20.v[3];
        o->w18.v[4] = recA->w20.v[4];
        o->w18.v[5] = recA->w20.v[5];
        o->w18.v[6] = recA->w20.v[6];
        o->w18.v[7] = recA->w20.v[7];
    }
    partyB = bs->f24[k];
    func_0201A954(partyB, 6);
    mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x29E);
    for (i = 0; i < n; i++) {
        func_0216869C((const BattleMon_0216869C *)((const struct BattleMon *)(&recA->mons[i])), mon);
        func_0201A98C(partyB, mon);
    }
    func_020307B0(mon);

    if (bs->f22 != 0) {
        k = SIDE_3;
        o = bs->f48[k];
        recC = recA + 1;
        o->f00 = recC->f00;
        o->f04 = recC->f04;
        o->f08 = 0x87;
        func_02045924(o->f14, (const u16 *)recC->f08);
        partyC = bs->f24[k];
        func_0201A954(partyC, 6);
        mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x2C4);
        for (i = 0; i < n; i++) {
            func_0216869C((const BattleMon_0216869C *)((const struct BattleMon *)(&recC->mons[i])), mon);
            func_0201A98C(partyC, mon);
        }
        func_020307B0(mon);
    }
    if (bs->f22 == 3) {
        k = SIDE_2;
        o = bs->f48[k];
        o->f00 = recB->f00;
        o->f04 = recB->f04;
        o->f08 = 0x87;
        func_02045924(o->f14, (const u16 *)recB->f08);
        func_0202428C(&o->w18.v[0]);
        func_0202428C(&o->w18.v[4]);
        partyD = bs->f24[k];
        func_0201A954(partyD, 6);
        mon = func_02030734(0x8004, func_020173EC(), 0, d_02172A2C, 0x2F3);
        for (i = 0; i < n; i++) {
            func_0216869C((const BattleMon_0216869C *)((const struct BattleMon *)(&recB->mons[i])), mon);
            func_0201A98C(partyD, mon);
        }
        func_020307B0(mon);
    }
    func_0201394C((struct ZoneData *)bs);
    return bs;
}





/*
 * Build a battle-facility Pokemon from its a/2/1/4 record (the reader is
 * func_02168800). Levers: the pid store in both arms of an if/else, the
 * ability as a nested if storing in all three arms, and (2026-09-28
 * tree_ov010_4) the EV share as an int local computed straight from the
 * division with the count n reused as the second loop's counter.
 */
u32 func_021684E8(BattleMon_021684E8 *out, u32 member, u32 otId, u32 pid, u8 iv, u8 itemIdx, int useItem, u16 heap)
{
    FacRec rec;
    int i;
    int n;
    u8 friendship;
    int ev;
    u32 ability;
    void *bank;

    MI_CpuFill8(out, 0, sizeof(BattleMon_021684E8));
    func_02168800(&rec, member);
    out->species = rec.species;
    out->form = rec.form;
    if (useItem)
        out->item = d_02172084[itemIdx];
    else
        out->item = rec.item;
    friendship = 0xFF;
    for (i = 0; i < 4; i++) {
        out->moves[i] = rec.moves[i];
        if (rec.moves[i] == 0xDA)
            friendship = 0;
    }
    out->otId = otId;
    if (pid == 0) {
        pid = func_020186C8(otId, rec.species, rec.form, 2, 2, 0);
        out->pid = pid;
    } else {
        out->pid = pid;
    }
    out->nature = rec.nature;
    out->hpIv = iv;
    out->atkIv = iv;
    out->defIv = iv;
    out->speIv = iv;
    out->spaIv = iv;
    out->spdIv = iv;
    n = 0;
    for (i = 0; i < 6; i++) {
        if (rec.evMask & (1 << i))
            n++;
    }
    ev = 510 / n;
    if (ev > 255)
        ev = 255;
    for (n = 0; n < 6; n++) {
        if (rec.evMask & (1 << n))
            out->ev[n] = ev;
    }
    out->ppUps = 0;
    out->lang = 0;
    ability = func_02019C90(out->species, 0, 0x1B);
    if (ability != 0) {
        if (out->pid & 1)
            out->ability = ability;
        else
            out->ability = func_02019C90(out->species, 0, 0x1A);
    } else {
        out->ability = func_02019C90(out->species, 0, 0x1A);
    }
    out->friendship = friendship;
    bank = sub_02045B38(0, 2, 0x46, heap);
    func_02045F5C(bank, out->species, out->nick, 11);
    func_02045C04(bank);
    return pid;
}





/*
 * Builds a level-50 party mon from a 0x3C-byte record. Two levers: the
 * PP-up count read back through func_02017E1C goes through a u8 local, and
 * the nickname copy reads through a `const u16 *` local (indexing
 * src->nick directly keeps the strbuf in a register and swaps r5/r6).
 */
void func_0216869C(const BattleMon_0216869C *src, void *mon)
{
    u16 name[11];
    void *buf;
    u16 eos;
    int i;
    u8 pp;
    const u16 *n;

    func_02017528(mon);
    func_02017588(mon, src->species, 50, (u64)-1, src->ivs & 0x3FFFFFFF, src->pid);
    func_02017E40(mon, 0x6F, (u8)src->form);
    func_02017E40(mon, 6, src->item);
    for (i = 0; i < 4; i++) {
        func_02017E40(mon, 0x36 + i, src->moves[i]);
        func_02017E40(mon, 0x3E + i, (u8)((src->ppUps >> (i * 2)) & 3));
        pp = func_02017E1C(mon, 0x42 + i, 0);
        func_02017E40(mon, 0x3A + i, pp);
    }
    func_02017E40(mon, 7, src->otId);
    func_02017E40(mon, 0xD, src->ev[0]);
    func_02017E40(mon, 0xE, src->ev[1]);
    func_02017E40(mon, 0xF, src->ev[2]);
    func_02017E40(mon, 0x10, src->ev[3]);
    func_02017E40(mon, 0x11, src->ev[4]);
    func_02017E40(mon, 0x12, src->ev[5]);
    func_02017E40(mon, 0xA, src->f20);
    func_02017E40(mon, 9, src->f21);
    func_020185B0(mon, src->f38);
    buf = func_020457B0(11, 4);
    eos = func_02045A98();
    n = src->nick;
    for (i = 0; i < 11; i++)
        name[i] = n[i];
    name[i - 1] = eos;
    func_02045924(buf, name);
    func_02017E40(mon, 0x73, (u32)buf);
    func_02045808(buf);
    func_02017E40(mon, 0xC, src->lang);
    func_02017E40(mon, 0x9E, func_02018430(mon));
}





/*
 * The reader for a/2/1/4: copy one 16-byte record into the caller's buffer.
 * 214 is the archive id and it never appears as an immediate at any call to
 * the arc_tool.c entry points, because this accessor reaches func_02048F4C
 * by pool word and `bx` rather than by `bl`
 * (docs/idioms/tail-call-is-a-pool-word-and-bx.md): a plain scan of `bl`
 * sites misses it entirely.
 *
 * The record is a battle-facility Pokemon: func_021684E8, three functions
 * up in the same file (fld_btl_inst_tool.c, by the __FILE__ anchors either
 * side of this address), reads the buffer field by field into a party
 * slot: +0 species (masked to 11 bits), +2/+4/+6/+8 the four move ids,
 * +10 a six-bit "which stats are EV-invested" mask (the caller divides 510
 * EVs between the set bits), +11 the nature (0..24 over the whole archive),
 * +12 the held item and +14 the form (five bits, always zero here).  The
 * member ids come from a/2/1/5, whose own reader is func_0216880C
 * immediately below this one.
 *
 * Addresses are Black-image addresses.  --region ov010 is required: this
 * address is only ov010 in the overlay that defines it.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02168800.c \
 *       --func func_02168800 --addr 0x02168800 --region ov010 \
 *       --cc 1.1p1 --thumb
 */
void func_02168800(void *dst, u32 member)
{
    func_02048F4C(dst, 214, member);
}





/*
 * The reader for a/2/1/5: allocate a buffer and load one group record.
 * func_0204A1BC(archive_id, member, flag, heap) is arc_util.c's
 * "allocate and read a member" helper, so the returned pointer is the
 * sub-file itself.
 *
 * Two things the bytes pin down.  The member is `group + 1`, truncated to
 * 16 bits before the call, so group 0 is sub-file 1 and sub-file 0 is the
 * usual unused sentinel.  And the record is the group list documented in
 * docs/ASSETS.md, [u16 group_id][u16 count][u16 member_id x count]: its
 * consumer func_02168924 takes `count` from +2, picks a random index below
 * it, reads `member_id` from +4 + 2*index, and hands that id to
 * func_02168800, the a/2/1/4 record reader immediately above this
 * function.  That is the direct evidence that a/2/1/5's member ids index
 * a/2/1/4, which the previous pass could only infer from the id range.
 *
 * Addresses are Black-image addresses.  --region ov010 is required.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0216880C.c \
 *       --func func_0216880C --addr 0x0216880C --region ov010 \
 *       --cc 1.1p1 --thumb
 */
void *func_0216880C(u32 group, u32 heap)
{
    return (void *)func_0204A1BC(215, (u16)(group + 1), 0, heap);
}





int func_02168824(void)
{
    int a0;
    int a1;
    int t4;

t4 = 0;
t4 = ~t4;
a0 = t4 + 0;
    a0 = func_020056EC(a0);
loc_02168830:
a1 = (unsigned)t4 >> 0x10;
    a0 = func_0209C2B0(a0, a1);
loc_02168836:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    return a0;}





/*
 * IV value for a battle-facility trainer index: a step table over the
 * index (3 below 50, up to 31 from 200). Returns u8: func_02168924
 * stores the result to its u8 local without an extension.
 */
u8 func_0216883C(u32 n)
{
    if (n < 50)
        return 3;
    if (n < 70)
        return 6;
    if (n < 90)
        return 9;
    if (n < 110)
        return 12;
    if (n < 160)
        return 15;
    if (n < 180)
        return 18;
    if (n < 200)
        return 21;
    return 31;
}



int func_02168878(u8 *a, int b, int c, int d, int e, int f, u16 g)
{
    int t = func_021688BC(a, b, g);
    int r = func_02168924(t, b, a + 0x30, (u8)c, d, e, f, g);
    func_020307B0((void *)t);
    return r;
}
