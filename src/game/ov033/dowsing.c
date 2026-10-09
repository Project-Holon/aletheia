/*
 * file:     dowsing.c
 * unit:     yes
 * function: func_021EFEC0, func_021EFEE4, func_021EFEEC, func_021EFF40, func_021EFF48, func_021F000C, func_021F0124, func_021F0174, func_021F05A4, func_021F0674, func_021F06AC, func_021F0738, func_021F0760, func_021F07DC, func_021F07F4, func_021F08EC, func_021F0924, func_021F0A90, func_021F0AC4, func_021F0B74, func_021F0C0C
 * address:  0x021EFEC0
 * region:   ov033
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02030734 0x02030734 arm
 *   d_021F0E60 0x021F0E60 data ov033 a1
 *   func_020307B0 0x020307B0 arm
 *   func_020142E8 0x020142E8 thumb
 *   func_021CFAC0 0x021CFAC0 thumb ov021
 *   func_0216476C 0x0216476C thumb ov010
 *   func_021CFB68 0x021CFB68 thumb ov021
 *   func_0204A298 0x0204A298 arm
 *   func_020056A0 0x020056A0 thumb
 *   func_02188C80 0x02188C80 thumb ov021
 *   func_020120F4 0x020120F4 thumb
 *   func_0201296C 0x0201296C thumb
 *   func_02012EBC 0x02012EBC thumb
 *   func_0200BE48 0x0200BE48 thumb
 *   func_0207D63C 0x0207D63C arm
 *   func_0203D34C 0x0203D34C arm
 *   func_02030EAC 0x02030EAC arm
 *   func_02024ABC 0x02024ABC thumb
 *   func_02159C48 0x02159C48 thumb ov010
 *   func_02159BD4 0x02159BD4 thumb ov010
 *   func_020120F8 0x020120F8 thumb
 *   func_02012AA0 0x02012AA0 thumb
 *   func_02012974 0x02012974 thumb
 *   func_02013E7C 0x02013E7C thumb
 *   func_02013D74 0x02013D74 thumb
 *   func_02006148 0x02006148 thumb
 *   func_0200616C 0x0200616C thumb
 *   func_02006268 0x02006268 thumb
 *   func_02006224 0x02006224 thumb
 *   func_020061E4 0x020061E4 thumb
 *   d_021F0DC8 0x021F0DC8 data ov033 a4
 *   func_021F0C44 0x021F0C44 thumb ov033
 *   func_0204B3DC 0x0204B3DC arm
 *   func_0204B404 0x0204B404 arm
 *   func_0204B878 0x0204B878 arm
 *   func_0204B92C 0x0204B92C arm
 *   func_0204B8C4 0x0204B8C4 arm
 *   func_02021D50 0x02021D50 thumb
 *   func_02040588 0x02040588 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414AC 0x020414AC arm
 *   func_02040618 0x02040618 arm
 *   func_0204B100 0x0204B100 arm
 *   func_0204B270 0x0204B270 arm
 *   func_02043598 0x02043598 arm
 *   d_021F0DF0 0x021F0DF0 data ov033 a4
 *   func_0204B1CC 0x0204B1CC arm
 *   func_020403F4 0x020403F4 arm
 *   func_020490F4 0x020490F4 arm
 *   func_02049BDC 0x02049BDC arm
 *   func_02049740 0x02049740 arm
 *   func_02049990 0x02049990 arm
 *   func_02049238 0x02049238 arm
 *   func_020413B0 0x020413B0 arm
 *   func_02041B6C 0x02041B6C arm
 *   func_0203FB44 0x0203FB44 arm
 *   func_0204AC18 0x0204AC18 arm
 *   func_0204A6C8 0x0204A6C8 arm
 *   func_0204AF28 0x0204AF28 arm
 *   func_0204B294 0x0204B294 arm
 *   func_0204B688 0x0204B688 arm
 *   d_021F0DBC 0x021F0DBC data ov033 a1
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_02024A20 0x02024A20 thumb
 *   func_020275E4 0x020275E4 thumb
 *   func_02027624 0x02027624 thumb
 *   func_02027628 0x02027628 thumb
 *   func_0202762C 0x0202762C thumb
 *   func_02027614 0x02027614 thumb
 *   func_02027618 0x02027618 thumb
 *   func_0202761C 0x0202761C thumb
 *   func_02027620 0x02027620 thumb
 *   func_02049B68 0x02049B68 arm
 *   func_02049EF4 0x02049EF4 arm
 *   func_020410D0 0x020410D0 arm
 *   func_0204B954 0x0204B954 arm
 *   func_02024DCC 0x02024DCC thumb
 *   func_02035D20 0x02035D20 arm
 *   func_020355D8 0x020355D8 arm
 *   func_020362DC 0x020362DC arm
 *   func_0204B98C 0x0204B98C arm
 *   func_021A0F30 0x021A0F30 thumb ov021
 *   func_02030CB0 0x02030CB0 arm
 *   func_02030CBC 0x02030CBC arm
 *   func_02021518 0x02021518 thumb
 *   func_02021EE4 0x02021EE4 thumb
 *   func_0202155C 0x0202155C thumb
 *   func_020216D4 0x020216D4 thumb
 *   func_020215A0 0x020215A0 thumb
 *   func_02021540 0x02021540 thumb
 *   func_02030DA4 0x02030DA4 arm
 */
#include "../../matched/include/Obj07642.h"
#include "../../matched/include/Obj13070.h"
#include "../../matched/include/Obj13071.h"
#include "../../matched/include/Obj00618.h"
#include "../../matched/include/Obj09801.h"
#include "../../matched/include/Obj00323.h"
#include "../../matched/include/Obj06142.h"
#include "../../matched/include/Obj09802.h"
#include "../../matched/include/G_ov033_021F0DF0.h"
#include "../../matched/include/Obj20474.h"
#include "../../matched/include/Obj13072.h"
#include "../../matched/include/Obj20475.h"
#include "../../matched/include/Obj09803.h"
#include "../../matched/include/Obj20476.h"
#include "../../matched/include/Obj06143.h"
#include "../../matched/include/Obj01512.h"
#include "../../matched/include/Obj06144.h"

struct Big;
struct BigObj;
struct Ctx;
struct Node;
struct Rec44;
struct Vec12;
struct Obj_vFEC0;
struct Vec2;
struct S02021D50;
struct BgTemplate;
struct Bank;
struct Actor;
struct Obj_v08EC;
struct Obj02021EE4;
struct PalAnmSlot;
typedef unsigned int u32;

typedef unsigned short u16;

typedef struct { void *f00; u16 f04; void *f08; u16 f0c; } Work;

typedef signed int     s32;

typedef unsigned char  u8;

typedef struct {
    unsigned kind;
    unsigned a;
    unsigned b;
} Rec_021EFEC0;

typedef struct {
    unsigned short h0;
    unsigned short h2;
    unsigned short h4;
    unsigned short h6;
    unsigned f8;
    unsigned short hc;
} T_vFEC0;

typedef signed short   s16;

typedef struct {
    u32 a : 3;
    u32 b : 3;
    u32 c : 3;
    u32 x : 8;
    u32 y : 8;
    u32 pan : 7;
} Ent_021F0174;

typedef struct {
    u32 kind;
    u32 a;
    u32 b;
} Rec_021F000C;

typedef struct {
    u8 pad0[2];
    u8 b2;
    u8 pad3;
    u16 h4;
    u16 h6;
    u16 h8;
} Ev;

typedef struct {
    int x, y, z;
} Vec;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[0x60 - 0x0C];
    u8 *map;
    int f64;
    int f68;
    int f6C;
    Rec_021F000C cur;
    Rec_021F000C found;
    int f88;
    int f8C;
    int f90;
    int f94;
    int f98;
    int f9C;
    u16 hA0;
    u16 padA2;
    int fA4;
    u32 fA8;
    u32 fAC;
    int fB0;
    u32 fB4;
    u32 fB8;
    u32 fBC;
    int fC0;
    u32 fC4;
    int fC8;
    int fCC;
    void *fD0;
} W;

typedef struct {
    u32 a : 3;
    u32 b : 3;
    u32 c : 3;
    u32 x : 8;
    u32 y : 8;
    u32 pad : 7;
} Ent_021F05A4;

typedef struct {
    u16 x;
    u16 y;
} Pt;

typedef struct {
    unsigned f00;
    unsigned f04[8];
    unsigned f24;
    unsigned f28;
} E;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local_vFEC0;

typedef struct {
    u16 x;
    u16 y;
} Pos;

typedef struct {
    u8 a;
    u8 b;
    u8 c;
} Ids;

typedef struct {
    u32 chr;
    u32 cell;
    u32 obj;
} Rec;

typedef struct {
    u16 heap;
    u16 heap2;
    u8 pad4[0x8];
    u32 fC;
    u8 pad10[0x1C];
    u32 f2C;
    Rec rec[4];
} Obj_vFEC0;

typedef struct {
    u16 a;
    u16 b;
    u16 c;
    u8 d;
    u8 e;
} Local_v08EC;

struct Scr {
    u8 pad00[0xC];
    u16 data[0x300];
};

typedef struct {
    u16 heap;
    u16 heap2;
    u8 pad4[0x4];
    u32 f8;
    u32 fC;
    u8 pad10[0x4];
    u32 f14;
    u32 f18;
    u32 f1C;
    u32 f20;
    u32 f24;
    u32 f28;
} Obj_v08EC;

typedef struct {
    unsigned f00;
    unsigned f04;
    char pad[0x1C];
    unsigned f24;
    unsigned f28;
} T_v08EC;

extern void *func_02030734(u32, u32, int, const char *, u16);
extern u32 func_020307B0(void *p);
extern u32 func_020142E8(void *bitmap, s32 id);
extern int func_021CFAC0(u8 *base, int a, int b, int c, int d);
extern char *func_0216476C(unsigned short *);
extern unsigned func_021CFB68(unsigned, unsigned *);
extern int func_0204A298(int a0, int a1, int a2, int a3, u32 *out);
extern void *func_020056A0(void *fn, void *ctx, u32 a);
extern void *func_02188C80(void *p);
extern void *func_020120F4(const struct Ctx *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012EBC(struct Big *p);
extern u16 *func_0200BE48(void *sys);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void func_0203D34C(u32, u32);
extern void func_02030EAC(struct Node *n);
extern void func_02024ABC(void);
extern u8 *func_020120F8(const struct Ctx *p);
extern struct Vec12 *func_02012AA0(struct Rec44 *p);
extern u32 func_02012974(const struct BigObj *p);
extern int func_02159C48(int a0, int a1, int a2);
extern int func_02159BD4(int a0, int a1, int a2);
extern u32 func_02013E7C(u32 id);
extern int func_02013D74(u32 key);
extern int func_02006148(u32 a0);
extern void func_0200616C(void *arg, int i);
extern void func_02006268(int i, u32 a, u32 b, u32 c);
extern int func_02006224(u32 a0);
extern void func_020061E4(u32 se);
extern void func_021F0C44(char *p);
extern void func_0204B3DC(struct Obj_vFEC0 *p, u32 v);
extern void func_0204B404(struct Obj_vFEC0 *p, const struct Vec2 *delta, u32 which);
extern void func_0204B878(struct Actor *p, u16 value);
extern void func_0204B92C(struct Actor *p, u32 v);
extern void func_0204B8C4(struct Obj_vFEC0 *p, u32 value);
extern void func_02021D50(struct S02021D50 *);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
extern void func_020414AC(unsigned char);
extern void func_02040618(unsigned char, unsigned, unsigned);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_0204B270(struct Bank *bank);
extern void func_02043598(unsigned, unsigned);
extern unsigned int func_0204B1CC(struct Bank *bank);
extern void func_020403F4(u32 i);
extern void *func_020490F4(unsigned int id, unsigned int heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049740(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 flags);
extern u32 func_02049990(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_02049238(void *);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(unsigned);
extern void func_0203FB44(u32 layer, u32 offset, u32 size);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
extern struct Actor *func_0204B294(void *, unsigned int, unsigned int, unsigned int, const void *, unsigned short, unsigned short);
extern void func_0204B688(struct Actor *actor, u32 value);
extern void func_0204B3B4(struct Actor *p);
extern void func_0204AFD8(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204ADA4(u32 i);
extern void func_02024A20(u8 a0, u8 a1, void *a2, u16 heap);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32);
extern u32 func_02027620(u32);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void *func_02049EF4(void *o, u32 a, u32 b, void **out, u16 e);
extern void func_020410D0(u32 index, u32 a1, u32 a2, u32 a3, u8 a4, u32 a5, u8 a6, u8 a7, u8 a8, u8 a9);
extern void func_0204B954(struct Actor *a, u32 v);
extern int func_02024DCC(void);
extern u32 func_02035D20(u32 *outA, u32 *outB);
extern void func_020355D8(u8 v);
extern u32 func_020362DC(void);
extern u32 func_0204B98C(struct Actor *a);
extern int func_021A0F30(u32 a, u32 b);
extern unsigned func_02030CB0(unsigned);
extern struct Ctx *func_02030CBC(u32 capacity, struct Ctx *c);
extern void *func_02021518(u32 heap);
extern void func_02021EE4(struct Obj02021EE4 *o, int v);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020216D4(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_02030DA4(void *);
Work *func_021EFEC0(u32 heap, void *a, void *b);
void func_021EFEE4(void *p);
int func_021EFEEC(char *p, int *q);
void func_021EFF40(char *p);
int func_021EFF48(T_vFEC0 *p, unsigned *out, int mode);
void *func_021F000C(u32 heap, u32 heap2, u32 a, u32 b);
void func_021F0124(char *p);
void func_021F0174(W *p, int on);
void func_021F05A4(char *p, int flag);
void func_021F0674(int a, unsigned char *p);
void func_021F06AC(char *p);
void func_021F0738(char *p);
void func_021F0760(char *p);
void func_021F07DC(char *p);
void func_021F07F4(Obj_vFEC0 *p);
void func_021F08EC(char *p);
void func_021F0924(Obj_v08EC *p);
void func_021F0A90(char *p);
void func_021F0AC4(T_v08EC *p);
void func_021F0B74(char *p);
void func_021F0C0C(char *p);
extern const char d_021F0E60[];
extern const Ent_021F0174 d_021F0DC8[];
extern struct G_ov033_021F0DF0 d_021F0DF0[];
extern const Ids d_021F0DBC[];




Work *func_021EFEC0(u32 heap, void *a, void *b)
{
    Work *p;
    p = func_02030734(heap, 0x10, 1, d_021F0E60, 0x8d);
    p->f00 = a;
    p->f04 = 0;
    p->f08 = b;
    p->f0c = 0;
    return p;
}





void func_021EFEE4(void *p)
{
    func_020307B0(p);
}





int func_021EFEEC(char *p, int *q)
{
    int r;
    if (q[0] == 1) {
        unsigned short *s = *(unsigned short * *)&((struct Obj07642 *)q)->f4;
        return func_020142E8((void *)(((struct Obj13070 *)p)->f0), (unsigned short)(*s + 0x384)) == 0;
    }
    if (q[0] == 2) {
        short *s = *(short * *)&((struct Obj07642 *)q)->f8;
        r = 0;
        if (func_021CFAC0((u8 *)(((struct Obj13070 *)p)->f8), (unsigned short)s[3], s[0], s[1], s[2]) != 0xFF)
            r = 1;
        return r;
    }
    return 0;
}





void func_021EFF40(char *p)
{
    ((struct Obj13071 *)p)->f4 = 0;
    ((struct Obj13071 *)p)->fC = 0;
}





int func_021EFF48(T_vFEC0 *p, unsigned *out, int mode)
{
    unsigned short cnt;
    unsigned idx;
    Rec_021EFEC0 rec;
    char *tbl;
    unsigned v;
    int found;

    found = 0;
    tbl = func_0216476C(&cnt);
    idx = p->hc;
    if (mode == 0 || mode == 1) {
        while (p->h4 < cnt) {
            rec.kind = 1;
            rec.a = (unsigned)(tbl + p->h4 * 10);
            if (func_021EFEEC((char *)p, (int *)(&rec))) {
                out[0] = rec.kind;
                out[1] = rec.a;
                found = 1;
            }
            p->h4++;
            if (found)
                return 1;
        }
    }
    if (mode == 0 || mode == 2) {
        v = func_021CFB68(p->f8, &idx);
        p->hc = idx;
        while (v != 0) {
            rec.b = v;
            rec.kind = 2;
            if (func_021EFEEC((char *)p, (int *)(&rec))) {
                out[0] = rec.kind;
                out[2] = rec.b;
                found = 1;
            }
            if (found)
                return 1;
            v = func_021CFB68(p->f8, &idx);
            p->hc = idx;
        }
    }
    out[0] = 0;
    return 0;
}





void *func_021F000C(u32 heap, u32 heap2, u32 a, u32 b)
{
    char *p;
    u32 size;
    u32 s;
    u32 v;

    p = func_02030734(heap, 0xD4, 1, d_021F0E60, 0x272);
    ((struct Obj00618 *)p)->f0 = heap;
    ((struct Obj00618 *)p)->f2 = heap2;
    ((struct Obj00618 *)p)->f4 = a;
    ((struct Obj00618 *)p)->f8 = b;
    func_021F06AC(p);
    func_021F0760(p);
    func_021F07F4((Obj_vFEC0 *)p);
    func_021F0924((Obj_v08EC *)p);
    ((struct Obj00618 *)p)->f60 = (void *)func_0204A298(0xC3, 0xD, 0, ((struct Obj00618 *)p)->f0, &size);
    ((struct Obj00618 *)p)->fA8 = func_020056A0(func_021F0674, p, 1);
    ((struct Obj00618 *)p)->fAC = 0;
    ((struct Obj00618 *)p)->fB0 = 1;
    func_021F0B74(p);
    ((struct Obj00618 *)p)->f64 = 10;
    ((struct Obj00618 *)p)->f68 = 9;
    ((struct Obj00618 *)p)->f6C = 10;
    ((struct Obj00618 *)p)->f70 = 0;
    ((struct Obj00618 *)p)->f7C = 0;
    ((struct Obj00618 *)p)->f88 = 0;
    ((struct Obj00618 *)p)->f8C = 0;
    ((struct Obj00618 *)p)->f90 = 0;
    ((struct Obj00618 *)p)->f94 = 0;
    ((struct Obj00618 *)p)->f9C = 0;
    ((struct Obj00618 *)p)->fA4 = 0;
    func_021F05A4(p, 1);
    ((struct Obj00618 *)p)->fC8 = 1;
    ((struct Obj00618 *)p)->fCC = 1;
    s = (u32)func_020120F4(func_02188C80((void *)(((struct Obj00618 *)p)->f8)));
    v = func_0201296C((const struct BigObj *)s);
    ((struct Obj00618 *)p)->fD0 = (void *)func_021EFEC0(((struct Obj00618 *)p)->f0, (void *)v, (void *)((u32)func_0200BE48(func_02012EBC((struct Big *)s))));
    func_0207D63C(0x04001050, 0x10, 0x18, 1, 7);
    func_0203D34C(0, ((struct Obj00618 *)p)->f0);
    return p;
}





void func_021F0124(char *p)
{
    *(volatile unsigned short *)0x04001050 = 0;
    func_021EFEE4((void *)(((struct Obj09801 *)p)->fD0));
    func_021F0C0C(p);
    func_02030EAC((struct Node *)(((struct Obj09801 *)p)->fA8));
    func_020307B0(((struct Obj09801 *)p)->f60);
    func_021F0A90(p);
    func_021F08EC(p);
    func_021F07DC(p);
    func_021F0738(p);
    func_020307B0(p);
}





void func_021F0174(W *p, int on)
{
    Rec_021F000C r[2];
    int snd;
    int changed;
    int x0;
    u32 map;
    void *obj;
    int gx, gy, gz;
    int zone;
    int flag;
    u32 n;
    int xmin, xmax, zmin, zmax;
    int best;
    u16 bestIdx;
    Ev *e;
    s16 *s;
    int x1, z1;
    Vec *pos;
    int go;
    int start;
    u16 i;
    int x, z;
    int dx, dz;
    u16 idx;
    u32 d;
    int h;
    int pan;
    int c68;
    u32 k;

    p->fB0 = on;
    if (on)
        p->fC0 = 1;
    else
        p->fC0 = 2;
    func_02024ABC();
    if (on == 0)
        return;
    p->f64 = p->f68;
    p->cur.kind = p->found.kind;
    if (p->cur.kind == 1)
        p->cur.a = p->found.a;
    else if (p->cur.kind == 2)
        p->cur.b = p->found.b;
    obj = func_02188C80((void *)p->f08);
    pos = (Vec *)func_02012AA0((struct Rec44 *)func_020120F8(obj));
    gx = (pos->x >> 4) / 4096;
    gy = (pos->y >> 4) / 4096;
    gz = (pos->z >> 4) / 4096;
    map = func_02012974(func_020120F4(obj));
    zone = 0xFFFF;
    flag = 0;
    if (func_02159C48((int)map, pos->x, pos->z) == 1) {
        zone = func_02159BD4((int)map, pos->x, pos->z);
        flag = (int)func_02013E7C((u16)zone);
    }
    if (p->f94 == 0) {
        p->f94 = 1;
        go = 1;
    } else {
        go = 1;
    }
    if (go) {
        xmin = gx - 15;
        xmax = gx + 17;
        zmin = gz - 11;
        zmax = gz + 13;
        best = -1;
        r[0].kind = 0;
        if (p->fC8 != 0) {
            func_021EFF40(p->fD0);
            p->fC8 = 0;
        }
        if (p->fCC != 0) {
            n = 0xFFFF;
            p->fCC = 0;
        } else {
            n = 11;
        }
        for (i = 0; i < n; i++) {
            if (i == 0) {
                if (p->cur.kind != 0) {
                    if (func_021EFEEC(p->fD0, (int *)(&p->cur))) {
                        r[1].kind = p->cur.kind;
                        if (r[1].kind == 1)
                            r[1].a = p->cur.a;
                        else if (r[1].kind == 2)
                            r[1].b = p->cur.b;
                    } else {
                        p->fC8 = 1;
                        p->fCC = 1;
                        break;
                    }
                }
            } else {
                if ((p->fC8 = func_021EFF48((T_vFEC0 *)p->fD0, (unsigned *)(&r[1]), 0) ? 0 : 1) != 0)
                    break;
            }
            if (zone == 0xFFFF)
                continue;
            if (r[1].kind == 1) {
                e = (Ev *)r[1].a;
                if (zone != e->h4) {
                    if (e->b2 == 0)
                        continue;
                    if (flag == 0)
                        continue;
                    if (func_02013D74(e->h4) != 0)
                        continue;
                }
                x = e->h6;
                z = e->h8;
            } else if (r[1].kind == 2) {
                s = (s16 *)r[1].b;
                if ((int)func_02013E7C((u16)s[3]) == 0)
                    continue;
                if (flag == 0)
                    continue;
                x = s[0];
                z = s[2];
            }
            if (xmin <= x && x < xmax && zmin <= z && z < zmax) {
                dz = z - gz;
                dx = x - gx;
                idx = (u16)(dx + 15 + (dz + 11) * 32);
                if (p->map[idx] == 9)
                    continue;
                d = dx * dx + dz * dz;
                if (d < (u32)best) {
                    bestIdx = idx;
                    best = d;
                    r[0].kind = r[1].kind;
                    if (r[1].kind == 1)
                        r[0].a = r[1].a;
                    else if (r[1].kind == 2)
                        r[0].b = r[1].b;
                }
            }
        }
        k = r[0].kind;
        p->found.kind = k;
        if (k != 0) {
            p->f68 = p->map[bestIdx];
            if (k == 1)
                p->found.a = r[0].a;
            else if (k == 2)
                p->found.b = r[0].b;
        } else {
            p->f68 = 9;
        }
    }
    snd = 1;
    if (p->f68 == 8) {
        start = 0;
        if (p->f9C == 0) {
            start = 1;
            p->f9C = 1;
        } else if (p->hA0 == 6) {
            if (func_02006224(p->f98) == 0)
                p->hA0--;
        } else if (p->hA0 == 0) {
            start = 1;
        } else {
            p->hA0--;
        }
        if (start) {
            p->f98 = func_02006148(0x760);
            func_0200616C((void *)0x760, p->f98);
            func_02006268(p->f98, -1, 0x180, -1);
            p->hA0 = 6;
            p->fA4 = 1;
        }
        snd = 0;
    } else {
        p->f9C = 0;
    }
    if (snd && (c68 = p->f68) != 8 && p->found.kind != 0) {
        changed = 0;
        if (p->cur.kind == 1) {
            e = (Ev *)p->cur.a;
            x0 = e->h6;
            z = e->h8;
        } else if (p->cur.kind == 2) {
            s = (s16 *)p->cur.b;
            x0 = s[0];
            z = s[2];
        } else {
            changed = 1;
            goto done;
        }
        if (p->found.kind == 1) {
            e = (Ev *)p->found.a;
            x1 = e->h6;
            z1 = e->h8;
        } else if (p->found.kind == 2) {
            s = (s16 *)p->found.b;
            x1 = s[0];
            z1 = s[2];
        }
        if ((x0 != x1 || z != z1) && p->f64 != c68)
            changed = 1;
    done:
        if (changed) {
            h = func_02006148(0x760);
            pan = ((int)d_021F0DC8[p->f68].pan - 8) * 16;
            if (pan < -127)
                pan = -127;
            else if (pan > 127)
                pan = 127;
            func_0200616C((void *)0x760, h);
            func_02006268(h, -1, -1, pan);
            snd = 0;
        }
    }
    if (snd && p->f64 != p->f68)
        func_020061E4(0x762);
    p->f88 = gx;
    p->f8C = gy;
    p->f90 = gz;
    func_021F0AC4((T_v08EC *)p);
}





void func_021F05A4(char *p, int flag)
{
    Pt pt;

    func_021F0C44(p);
    if (flag == 0)
        return;
    if (((struct Obj00323 *)p)->f6C != ((struct Obj00323 *)p)->f68) {
        func_0204B3DC(((struct Obj00323 *)p)->f50,
                      (((struct Obj00323 *)p)->f68 == 8 || ((struct Obj00323 *)p)->f68 == 9) ? 0 : 1);
        func_0204B3DC(((struct Obj00323 *)p)->f5C, ((struct Obj00323 *)p)->f68 == 8);
        pt.x = d_021F0DC8[*(int *)(p + 0x68)].x;
        pt.y = d_021F0DC8[*(int *)(p + 0x68)].y;
        func_0204B404(((struct Obj00323 *)p)->f50, (const struct Vec2 *)(&pt), 1);
        func_0204B878(((struct Obj00323 *)p)->f38, d_021F0DC8[*(int *)(p + 0x68)].a);
        func_0204B878(((struct Obj00323 *)p)->f44, d_021F0DC8[*(int *)(p + 0x68)].b);
        func_0204B878(((struct Obj00323 *)p)->f50, d_021F0DC8[*(int *)(p + 0x68)].c);
        ((struct Obj00323 *)p)->f6C = ((struct Obj00323 *)p)->f68;
    }
    if (((struct Obj00323 *)p)->f68 == 8 && ((struct Obj00323 *)p)->fA4 != 0) {
        func_0204B878(((struct Obj00323 *)p)->f5C, 0);
        func_0204B92C(((struct Obj00323 *)p)->f5C, 1);
        func_0204B8C4(((struct Obj00323 *)p)->f5C, 0);
        ((struct Obj00323 *)p)->fA4 = 0;
    }
}




void func_021F0674(int a, unsigned char *p)
{
    func_02021D50(*(struct S02021D50 * *)&((struct Obj06142 *)p)->fBC);
    if (((struct Obj06142 *)p)->fB0 != 0) {
        if (p[0xac] >= 4)
            p[0xac] = 0;
        p[0xac]++;
    }
}




void func_021F06AC(char *p)
{
    int i;
    unsigned id;
    E *e;
    unsigned j;
    for (i = 4; i <= 7; i++)
        func_02040588((unsigned char)i, (unsigned char)0);
    for (j = 0; j < 2; j++) {
        e = &((E *)d_021F0DF0)[j];
        id = e->f00;
        func_0203FCA0((unsigned char)id, (const struct BgTemplate *)e->f04, (unsigned char)e->f24);
        func_020414AC(id);
        func_02040588((unsigned char)id, (unsigned char)e->f28);
        func_02040618(id, 0, 0);
        func_02040618(id, 3, 0);
    }
    ((struct Obj09802 *)p)->fC = func_0204B100(8, 0, ((struct Obj09802 *)p)->f0);
    func_0204B270(((struct Obj09802 *)p)->fC);
    func_02043598(0x10, 1);
}



void func_021F0738(char *p) { unsigned i; func_0204B1CC((struct Bank *)(((struct Obj20474 *)p)->fC)); for(i=0;i<2;i++) func_020403F4((unsigned char)d_021F0DF0[i].f00); }




void func_021F0760(char *p)
{
    unsigned h = ((struct Obj13072 *)p)->f2;
    void *a = func_020490F4(0xC3, h);
    unsigned b;
    func_02049BDC(a, 0, 4, 0, 0, 0x40, h);
    b = func_02049740(a, 2, 7, 0, 0, h);
    func_02049990(a, 7, 7, 0, (unsigned short)b, 0, 0, h);
    func_02049238(a);
    func_020413B0(7, 0, 0, 0x20, 0x18, 1);
    func_02041B6C(7);
    ((struct Obj13072 *)p)->f10 = b;
}



void func_021F07DC(char *p) { unsigned v = ((struct Obj20475 *)p)->f10; func_0203FB44(7, (unsigned short)v, (unsigned short)(v>>16)); }




/*
 * note:     the four `strh #0` at the loop top are `Local_vFEC0 s = {0};` declared
 *           in the loop body (field-by-field zeroing ends in two strb), and
 *           `pt` lives in its own block after the loop so it takes the
 *           lower slot (sp+0x10) below `s` (sp+0x14).
 */
/*
 * note:     the four `strh #0` at the loop top are `Local s = {0};` declared
 *           in the loop body (field-by-field zeroing ends in two strb), and
 *           `pt` lives in its own block after the loop so it takes the
 *           lower slot (sp+0x10) below `s` (sp+0x14).
 */
void func_021F07F4(Obj_vFEC0 *p)
{
    void *arc;
    u8 i;

    arc = func_020490F4(0xC3, p->heap2);
    p->f2C = func_0204AC18(arc, 1, 1, 0, 0, 1, p->heap);
    for (i = 0; i < 4; i++) {
        Local_vFEC0 s = {0};
        if (i == 1) {
            p->rec[i].chr = p->rec[0].chr;
            p->rec[i].cell = p->rec[0].cell;
        } else {
            p->rec[i].chr = func_0204A6C8(arc, d_021F0DBC[i].a, 0, 1, p->heap);
            p->rec[i].cell = func_0204AF28(arc, d_021F0DBC[i].b, d_021F0DBC[i].c, p->heap);
        }
        s.d = i;
        p->rec[i].obj = (u32)func_0204B294((void *)p->fC, p->rec[i].chr, p->f2C, p->rec[i].cell, &s, 1, p->heap);
        func_0204B92C((struct Actor *)p->rec[i].obj, 1);
        func_0204B688((struct Actor *)p->rec[i].obj, 1);
    }
    func_02049238(arc);
    {
        Pos pt;

        pt.x = 0x50;
        pt.y = 0x60;
        func_0204B404((struct Obj_vFEC0 *)p->rec[0].obj, (const struct Vec2 *)(&pt), 1);
        pt.x = 0xB0;
        pt.y = 0x60;
        func_0204B404((struct Obj_vFEC0 *)p->rec[1].obj, (const struct Vec2 *)(&pt), 1);
        pt.x = 0x80;
        pt.y = 0x60;
        func_0204B404((struct Obj_vFEC0 *)p->rec[3].obj, (const struct Vec2 *)(&pt), 1);
    }
}


void func_021F08EC(char *p) { unsigned char i; char *q; for(i=0;i<4;i++) { q=p+i*12; func_0204B3B4((struct Actor *)(((struct Obj09803 *)q)->f38)); if(i!=1) { func_0204AFD8(((struct Obj09803 *)q)->f34); func_0204A8D4(((struct Obj09803 *)q)->f30); } } func_0204ADA4(((struct Obj20476 *)p)->f2C); }



/*
 * note:     the four `strh #0` after func_02024A20 are `Local_v08EC s = {0};`
 *           opening an inner block there; declared at the top they land
 *           before the first call.
 */
/*
 * note:     the four `strh #0` after func_02024A20 are `Local s = {0};`
 *           opening an inner block there; declared at the top they land
 *           before the first call.
 */
void func_021F0924(Obj_v08EC *p)
{
    struct Scr *ptr;
    u32 heap2;

    heap2 = p->heap2;
    func_02024A20(4, 3, func_020120F4(func_02188C80((void *)p->f8)), p->heap);
    {
        Local_v08EC s = {0};
        void *h;
        void *arc;
        u16 *d;
        u16 i;
        u16 base;

        arc = func_020490F4(func_020275E4(), heap2);
        func_02049B68(arc, func_02027624(), 4, 0x40, 0x20, heap2);
        p->f14 = func_02049740(arc, func_02027628(), 4, 0, 0, heap2);
        h = func_02049EF4(arc, func_0202762C(), 0, (void **)&ptr, heap2);
        base = p->f14;
        d = ptr->data;
        for (i = 0; i < 0x300; i++) {
            d[i] &= 0xFFF;
            d[i] = (base + d[i]) | 0x2000;
        }
        func_020410D0(4, 0, 0x15, 0x20, 3, (u32)ptr->data, 0, 0x15, 0x20, 0x18);
        func_02041B6C(4);
        func_020307B0(h);
        p->f18 = func_0204AC18(arc, func_02027614(), 1, 0x20, 0, 3, p->heap);
        p->f1C = func_0204A6C8(arc, func_02027618(), 0, 1, p->heap);
        p->f20 = func_0204AF28(arc, func_0202761C(0), func_02027620(0), p->heap);
        s.a = 0xE8;
        s.b = 0xA8;
        p->f24 = (u32)func_0204B294((void *)p->fC, p->f1C, p->f18, p->f20, &s, 1, p->heap);
        func_0204B92C((struct Actor *)p->f24, 1);
        func_0204B954((struct Actor *)p->f24, 0x2000);
        func_0204B878((struct Actor *)p->f24, 0);
        func_02049238(arc);
        p->f28 = 0;
    }
}


void func_021F0A90(char *p) { unsigned v; func_0204B3B4((struct Actor *)(((struct Obj06143 *)p)->f24)); func_0204AFD8(((struct Obj06143 *)p)->f20); func_0204A8D4(((struct Obj06143 *)p)->f1C); func_0204ADA4(((struct Obj06143 *)p)->f18); v=((struct Obj06143 *)p)->f14; func_0203FB44(4,(unsigned short)v,(unsigned short)(v>>16)); func_02024DCC(); }



void func_021F0AC4(T_v08EC *p)
{
    unsigned x;
    unsigned y;
    int hit;

    switch (p->f28) {
    case 0:
        hit = 0;
        if (func_02035D20(&x, &y) != 0) {
            if (x >= 0xE8 && x < 0x100 && y >= 0xA8 && y < 0xC0) {
                func_020355D8(1);
                hit = 1;
            }
        }
        if (hit == 0) {
            if (func_020362DC() & 0x400) {
                func_020355D8(0);
                hit = 1;
            }
        }
        if (hit != 0) {
            p->f28 = 1;
            func_0204B878((struct Actor *)p->f24, 8);
            func_020061E4(0x556);
            return;
        }
        break;
    case 1:
        if (func_0204B98C((struct Actor *)p->f24) == 0) {
            p->f28 = 2;
            func_0204B878((struct Actor *)p->f24, 0);
            return;
        }
        break;
    case 2:
        func_021A0F30(p->f04, 0);
        p->f28 = 3;
        break;
    case 3:
        break;
    }
}



/*
 * note:     func_02030CBC takes (n, mem) (sub_0200545C): the 0xB8 result
 *           left in r1 before `blx func_02030CBC` is its second argument.
 */
void func_021F0B74(char *p)
{
    ((struct Obj01512 *)p)->fB8 = func_02030734(((struct Obj01512 *)p)->f0, func_02030CB0(2), 1, d_021F0E60, 0x6DF);
    ((struct Obj01512 *)p)->fB4 = func_02030CBC(2, ((struct Obj01512 *)p)->fB8);
    ((struct Obj01512 *)p)->fBC = (unsigned int)func_02021518(((struct Obj01512 *)p)->f0);
    func_02021EE4((struct Obj02021EE4 *)(((struct Obj01512 *)p)->fBC), 1);
    func_0202155C((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 1, 0x60, ((struct Obj01512 *)p)->f0);
    func_0202155C((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 3, 0x80, ((struct Obj01512 *)p)->f0);
    func_020216D4((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 1, 0, 0x60);
    func_020216D4((struct PalAnmSlot *)(((struct Obj01512 *)p)->fBC), 3, 0, 0x80);
    ((struct Obj01512 *)p)->fC0 = 0;
    ((struct Obj01512 *)p)->fC4 = 0;
}


void func_021F0C0C(char *p) { func_020215A0(((struct Obj06144 *)p)->fBC,1); func_020215A0(((struct Obj06144 *)p)->fBC,3); func_02021540(((struct Obj06144 *)p)->fBC); func_02030DA4(((struct Obj06144 *)p)->fB4); func_020307B0(((struct Obj06144 *)p)->fB8); }
