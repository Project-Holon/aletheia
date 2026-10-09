/*
 * file:     unit_02184D30.c
 * unit:     yes
 * function: func_02184D30, func_02184ECC, func_02185004, func_0218506C, func_02185080, func_021850A0, func_021852B4, func_021852F4, func_0218530C, func_02185354, func_02185378, func_021853D0, func_021853F0, func_02185420, func_02185454, func_02185584, func_021855C8, func_021855EC, func_02185628, func_02185670, func_021856AC, func_021856CC, func_021856F4, func_02185730, func_02185764, func_021857F4, func_02185814, func_02185854, func_02185880, func_021858B8, func_02185930, func_02185934, func_02185954, func_02185974, func_021859C4, func_02185A1C, func_02185AB0, func_02185BBC, func_02185C38, func_02185DA8, func_02185DE8, func_02185EA0, func_02185F10, func_02185F50, func_02185F74, func_021860D0, func_02186164, func_02186170, func_021861C4, func_021862B0, func_021862F4, func_02186304, func_02186324, func_02186444, func_0218644C, func_02186480, func_021864A8, func_021864C4, func_0218654C, func_02186558, func_02186564, func_021865B4, func_02186660, func_02186694, func_021866C4, func_02186708, func_021867C4, func_02186860, func_02186878, func_02186888, func_021868C8, func_02186938, func_02186958, func_02186988, func_021869C0
 * address:  0x02184D30
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0204B294  0x0204B294  arm
 *   func_0204B92C  0x0204B92C  arm
 *   func_0204B878  0x0204B878  arm
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_0204B84C  0x0204B84C  arm
 *   func_0204B800  0x0204B800  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_02185930  0x02185930  thumb  ov023
 *   d_02186BEC     0x02186BEC  data  ov023  a2
 *   func_02045088  0x02045088  arm
 *   func_020450F0  0x020450F0  arm
 *   func_02045770  0x02045770  arm
 *   func_02043B5C  0x02043B5C  arm
 *   func_0203101C  0x0203101C  arm
 *   func_0201C440  0x0201C440  thumb
 *   func_02045334  0x02045334  arm
 *   func_02045374  0x02045374  arm
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0203115C  0x0203115C  arm
 *   func_02031140  0x02031140  arm
 *   func_0201C6EC  0x0201C6EC  thumb
 *   func_0201C4C0  0x0201C4C0  thumb
 *   func_020452E8  0x020452E8  arm
 *   func_020450C8  0x020450C8  arm
 *   func_0204B528 0x0204B528 arm
 *   d_02186AFC     0x02186AFC  data  ov023  a4
 *   d_02186AB4     0x02186AB4  data  ov023  a4
 *   func_02035C08  0x02035C08  arm
 *   func_02035BA4  0x02035BA4  arm
 *   func_02035CB8  0x02035CB8  arm
 *   func_02035C38  0x02035C38  arm
 *   func_02039338  0x02039338  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0207D658  0x0207D658  arm
 *   func_020278F4  0x020278F4  thumb
 *   func_0201F7A8  0x0201F7A8  thumb
 *   func_02184560  0x02184560  thumb  ov023
 *   func_02082BCC  0x02082BCC  arm
 *   func_020399A8  0x020399A8  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0202208C 0x0202208C thumb
 *   func_02184114  0x02184114  thumb  ov022
 *   func_02184180 0x02184180 thumb ov022
 *   func_0201F02C 0x0201F02C thumb
 *   func_0203996C  0x0203996C  arm
 *   func_0203A424 0x0203A424 arm
 *   func_0203D1C0  0x0203D1C0  arm
 *   func_02039CB4  0x02039CB4  arm
 *   func_021841A0  0x021841A0  thumb  ov022
 *   func_021841A4  0x021841A4  thumb  ov022
 *   func_020436FC  0x020436FC  arm
 *   func_020439A0  0x020439A0  arm
 *   func_020437AC  0x020437AC  arm
 *   d_02186C34     0x02186C34  data  ov023  a4
 *   func_0203F684  0x0203F684  arm
 *   GX_LoadOBJPltt  0x0207E51C  arm
 *   func_02043AF4  0x02043AF4  arm
 *   func_02008500  0x02008500  thumb
 *   func_0201C724  0x0201C724  thumb
 *   func_0203D56C  0x0203D56C  arm
 *   func_02186A04  0x02186A04  thumb  ov023
 *   func_020457B0  0x020457B0  arm
 *   func_02045CAC  0x02045CAC  arm
 *   func_0201F250  0x0201F250  thumb
 *   func_02045808  0x02045808  arm
 *   func_0201F73C  0x0201F73C  thumb
 *   func_0201CE48  0x0201CE48  thumb
 *   func_02012FFC  0x02012FFC  thumb
 *   func_0201CCE4  0x0201CCE4  thumb
 *   func_0201CE30  0x0201CE30  thumb
 *   func_020362DC  0x020362DC  arm
 *   func_0201CE38  0x0201CE38  thumb
 *   d_02186E84 0x02186E84 data a4
 *   d_02186AAC 0x02186AAC data a4
 *   func_02040588  0x02040588  arm
 *   func_02027F60  0x02027F60  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_02027778  0x02027778  thumb
 *   d_02186ABC     0x02186ABC  data
 *   func_02027974 0x02027974 thumb
 *   func_020279E8 0x020279E8 thumb
 *   func_02027A04 0x02027A04 thumb
 *   func_02027858 0x02027858 thumb
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200ED48  0x0200ED48  thumb
 *   func_02008530  0x02008530  thumb
 *   func_0200ED54  0x0200ED54  thumb
 *   func_0201C4E4  0x0201C4E4  thumb
 *   func_0201C6C4  0x0201C6C4  thumb
 */
#include "../../matched/include/Obj03624.h"
#include "../../matched/include/Obj00525.h"
#include "../../matched/include/Obj01221.h"
#include "../../matched/include/Obj01221.h"
#include "../../matched/include/Obj00525.h"
#include "../../matched/include/Obj00336.h"
#include "../../matched/include/Obj20348.h"
#include "../../matched/include/Obj02742.h"
#include "../../matched/include/Obj02741.h"
#include "../../matched/include/Obj20349.h"
#include "../../matched/include/Obj09769.h"
#include "../../matched/include/Obj13025.h"
#include "../../matched/include/Obj20350.h"
#include "../../matched/include/Obj20351.h"
#include "../../matched/include/Obj05108.h"
#include "../../matched/include/Obj20354.h"
#include "../../matched/include/Obj20355.h"
#include "../../matched/include/Obj06119.h"
#include "../../matched/include/Obj02104.h"
#include "../../matched/include/Obj20359.h"
#include "../../matched/include/Obj20361.h"
#include "../../matched/include/Obj20363.h"
#include "../../matched/include/Obj20365.h"
#include "../../matched/include/Obj00460.h"
#include "../../matched/include/Obj20366.h"
#include "../../matched/include/Obj07610.h"
#include "../../matched/include/Obj13027.h"
#include "../../matched/include/Obj20368.h"
#include "../../matched/include/Obj03625.h"
#include "../../matched/include/Obj03626.h"
#include "../../matched/include/Obj06120.h"
#include "../../matched/include/Obj01674.h"
#include "../../matched/include/Obj20371.h"
#include "../../matched/include/Obj07611.h"
#include "../../matched/include/Obj09772.h"
#include "../../matched/include/Obj05109.h"
#include "../../matched/include/Obj13028.h"

#define E(p) ((struct e6 *)((char *)(p) + 0x4212))
struct Obj;
struct Node;
struct Descriptor;
struct Cfg;
struct CharBuf;
struct Tcbl;
struct PrintSys;
struct S02031140;
struct Actor;
struct Pt;
struct P;
struct Entry;
struct WordSet;
struct Link;
struct Bmp;
struct Obj020437AC;
struct MsgBank;
struct Rec3;
struct U16Vec;
struct R;
struct TaskMenu;
struct TaskMenuTmpl;
struct TaskMenuState;
struct Big;
struct L0200ED54;
struct Sub0200852CObj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef signed short   s16;

typedef unsigned int   u32;

typedef struct Pos {
    s16 x;
    s16 y;
    s16 z;
    u8 a;
    u8 b;
} Pos;

typedef struct Ent_02184D30 {
    u16 x;
    u16 y;
    u16 anim;
} Ent_02184D30;

typedef struct Work {
    u8  pad00[0x38];
    u32 f38, f3C, f40, f44, f48, f4C, f50, f54, f58, f5C;
    u32 a60[14];
    u32 a98[14];
    u32 aD0[12];
    u32 f100;
} Work;

typedef struct { u16 x, y; } Pt;

typedef struct { unsigned char b[4]; unsigned char lo:3, mid:3, hi:2; } Rec;

typedef struct { unsigned char b[4]; unsigned char lo:3, mid:3, hi:2; unsigned char pad; } Rec6;

typedef struct {
    u16 n;
    u16 a;
    u16 b;
    u16 pad;
} PathEnt;

typedef struct {
    PathEnt e[8];
    u16 tail;
} Path;

typedef struct {
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
} Bits;

struct bf4210 {
    unsigned char a : 3;
    unsigned char b : 3;
    unsigned char c : 2;
};

typedef signed int     s32;

struct e6 {
    unsigned char b[4];
    unsigned char c : 3;
    unsigned char n : 3;
    unsigned char d : 2;
    unsigned char pad;
};

struct o4 {
    unsigned char x;
    unsigned char y;
    unsigned short n;
};

struct P {
    char pad0[4];
    int *unk4;
    char pad1[0x60 - 8];
    int unk60[5];
};

typedef int s32_02185934;

typedef struct {
    u32 w;
    u8 f;
} Ent;

typedef struct {
    char pad0[0xc];
    u32 f0c;
    char pad10[0x8];
    u32 arr18[5];
    char pad2c[0x6c];
    u32 arr98[5];
    char padac[0x58];
    u32 win[7];
    char pad120[0xc];
    Ent ent[7];
    u32 f164;
    u32 f168;
    u32 f16c;
    u32 f170;
    char pad174[0x54];
    Ent e1c8[5];
} W_02185934;

typedef struct {
    u32 a;
    u8  b;
    u32 c;
    u32 d;
    u8  e[4];
} Arg;

typedef struct {
    u32 a;
    u32 b;
} Ent_021865B4;

typedef signed int     s32_02186708;




typedef struct { Rec6 r[5]; } Grp_02186958;

typedef struct {
    u8 b[4];
    u8 lo : 3;
    u8 mid : 3;
    u8 hi : 2;
    u8 b5;
} Rec_021869C0;

extern struct Obj *func_0204B294(void *owner, unsigned int i, unsigned int j, unsigned int k, const void *position, unsigned short space, unsigned short heap);
extern void func_0204B92C(struct Obj *p, u32 v);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_0204B3DC(struct Obj *p, unsigned int v);
extern void func_0204B84C(u32, int);
extern void func_0204B800(struct Node *node, u32 val);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_02045088(u16 heapId);
extern u32 func_020450F0(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern u32 func_0201C440(void *p);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_020409B4(u32 a);
extern void func_0203115C(struct Tcbl *p);
extern void func_02031140(struct S02031140 *p);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_020450C8(void);
extern void func_0204B528(struct Actor *actor, const struct Pt *src);
extern int  func_02035C08(const void *p);
extern int  func_02035BA4(const void *p);
extern u32 func_02035CB8(u32 *outA, u32 *outB);
extern int  func_02035C38(void);
extern u16 func_02039338(void);
extern void func_020061E4(u32 a);
extern void func_0207D658(u32 addr, int plane, int brightness);
extern void func_020278F4(u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);
extern void func_02184560(char *p, int a);
extern void func_02082BCC(void *p, int v, int n);
extern struct Entry *func_020399A8(void);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_0202208C(void *, unsigned int, unsigned int, unsigned int,
                        unsigned int, unsigned int, unsigned int);
extern int func_02184114(unsigned char *p);
extern char *func_02184180(unsigned char *p, int i);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern struct Entry *func_0203996C(s32 idx);
extern void func_0203A424(char *p, int a, int b, int c);
extern u32 func_0203D1C0(u32 index);
extern u32 func_02039CB4(struct Link *h, u32 a, u32 b);
extern int  func_021841A4(unsigned char *p);
extern unsigned char func_021841A0(unsigned char *p);
extern struct Bmp *func_020436FC(void *pixels, u32 width, u32 height, u32 depth, u16 heap);
extern void func_020439A0(struct Bmp *dst, struct Bmp *src, u32 x, u32 y, int sx, int sy, u32 w, u32 h, u32 key);
extern void func_020437AC(struct Obj020437AC *p);
extern short func_0203F684(unsigned short x);
extern void GX_LoadOBJPltt(void *src, unsigned long offset, unsigned long size);
extern void func_02043AF4(struct Bmp *b, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6);
extern void func_02008500(void *a, void *b);
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern int  func_0203D56C(void *h);
extern void func_02186A04(char *a, char *b);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_0201CE48(struct Rec3 *p);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(void *a0, u32 a1, u32 a2, void *a3, u32 a4, u32 a5, void *a6, u32 a7, u16 a8, u32 a9);
extern u32 func_0201CE30(void *p);
extern u32 func_020362DC(void);
extern void func_0201CE38(void *h);
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027974(struct Obj *);
extern u32 func_020279E8(struct TaskMenu *);
extern u8 func_02027A04(const u8 *);
extern void func_02027858(struct TaskMenu *);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void *func_02012EBC(struct Big *p);
extern void *func_0200ED48(void *p);
extern u32 func_02008530(const struct Sub0200852CObj *obj);
extern void func_0200ED54(struct L0200ED54 *l, u32 val);
extern u32 func_0201C4E4(struct PrintSys *ps);
extern u32 func_0201C6C4(struct PrintSys *p, void *v);
void func_02184D30(Work *p);
void func_02184ECC(W_02185934 *p);
void func_02185004(char *p);
void func_0218506C(void *actor, int x, int y);
void func_02185080(Rec *d, int a, int c);
void func_021850A0(char *p);
void func_021852B4(u32 *p, int n);
void func_021852F4(void *p, int flag);
int func_0218530C(char *p, int x);
void func_02185354(char *p);
int func_02185378(char *p, int x);
int func_021853D0(char *p, int a1);
int func_021853F0(char *p, int result);
int func_02185420(char *p, int a1);
int func_02185454(char *p, int x);
int func_02185584(char *p, int x);
int func_021855C8(unsigned char *p, int a1);
int func_021855EC(unsigned char *p, int a1);
int func_02185628(char *p, int x);
int func_02185670(unsigned char *p, int a1);
int func_021856AC(char *p, int a1);
int func_021856CC(char *p, int a1);
int func_021856F4(char *p, int a);
int func_02185730(char *p, int a1);
int func_02185764(char *p, int x);
void func_021857F4(char *p, int a, int i);
int func_02185814(char *p, int a1);
int func_02185854(char *p, int a);
int func_02185880(char *p, int a);
int func_021858B8(char *p, int a1);
int func_02185930(int a, int b);
int func_02185934(char *p, int a);
int func_02185954(char *p, int a);
int func_02185974(char *p, int a1);
int func_021859C4(char *p, int a1);
int func_02185A1C(char *p, int a1);
void func_02185AB0(char *p, int msg, int arg);
void func_02185BBC(int a0, int a1, int x, int y, int w, int h, int dx, int dy, int mx, int my);
void func_02185C38(int a0, int a1, int x1, int y1, int *px, int *py, int c, int d);
void func_02185DA8(struct e6 *e, struct o4 *o);
void func_02185DE8(char *p, struct e6 *e, struct o4 *o, int flag);
void func_02185EA0(struct P *p);
void func_02185F10(u16 *p);
int func_02185F50(char *p);
void func_02185F74(u32 *win, u16 color, W_02185934 *p);
void func_021860D0(char *p);
int func_02186164(char *p);
int func_02186170(char *p);
void func_021861C4(u8 *w, u32 msg, int mode);
int func_021862B0(char *p);
void func_021862F4(char *p);
void func_02186304(char *p, int a);
int func_02186324(u8 *p);
void func_02186444(char *p, u32 v);
void func_0218644C(char *p, int mode);
void func_02186480(char *p);
int func_021864A8(char *p);
void func_021864C4(Rec *d, PathEnt *s, int a, int c);
int func_0218654C(char *p);
int func_02186558(char *p);
void func_02186564(void);
int func_021865B4(char *p);
int func_02186660(char *p);
void func_02186694(char *p);
void func_021866C4(u32 *p);
void func_02186708(char *p);
void func_021867C4(char *p);
void func_02186860(char *p, int x, int y);
int func_02186878(char *p);
void func_02186888(char *p);
void func_021868C8(char *p);
void func_02186938(Rec6 *p);
void func_02186958(char *p);
void func_02186988(Rec6 *s, char *p, int i);
void func_021869C0(Rec_021869C0 *d, char *p);
extern const Ent_02184D30 d_02186BEC[];
extern char d_02186AFC[];
extern char d_02186AB4[];
extern char d_02186C34[];
extern int d_02186E84[][2];
extern char d_02186AAC[];
extern Ent_021865B4 d_02186ABC[];





void func_02184D30(Work *p)
{
    Pos pos;
    int i;
    int j;

    pos.x = 0;
    pos.y = 0;
    pos.z = 0;
    pos.a = 1;
    pos.b = 1;
    for (i = 0; i < 5; i++) {
        pos.x = i * 0x28 + 0x18;
        pos.y = 0x40;
        p->a60[i] = (u32)func_0204B294((void *)p->f38, p->f40, p->f3C, p->f44, &pos, 0, 0x28);
        func_0204B92C((struct Obj *)p->a60[i], 1);
        func_0204B878((struct Obj *)p->a60[i], i);
        func_0204B3DC((struct Obj *)p->a60[i], 0);
    }
    for (j = 0; j < 12; j++) {
        pos.x = d_02186BEC[j].x;
        pos.y = d_02186BEC[j].y;
        p->aD0[j] = (u32)func_0204B294((void *)p->f38, p->f40, p->f3C, p->f44, &pos, 0, 0x28);
        func_0204B92C((struct Obj *)p->aD0[j], 1);
        func_0204B878((struct Obj *)p->aD0[j], d_02186BEC[j].anim);
        if (j >= 8) {
            func_0204B84C(p->aD0[j], 2);
        }
    }
    func_0204B878((struct Obj *)p->aD0[0], 6);
    for (i = 0; i < 5; i++) {
        pos.x = 0x18;
        pos.y = i * 0x20 + 0x20 + 0x100000u;
        p->a98[i] = (u32)func_0204B294((void *)p->f38, p->f58, p->f54, p->f5C, &pos, 1, 0x28);
        func_0204B92C((struct Obj *)p->a98[i], 1);
        func_0204B878((struct Obj *)p->a98[i], i);
        func_0204B800((struct Node *)p->a98[i], 1);
        func_0204B3DC((struct Obj *)p->a98[i], 0);
    }
    pos.x = 0xD4;
    pos.y = 0xA0;
    p->f100 = (u32)func_0204B294((void *)p->f38, p->f4C, p->f48, p->f50, &pos, 0, 0x28);
    func_0204B92C((struct Obj *)p->f100, 1);
    func_0204B878((struct Obj *)p->f100, 1);
    func_0204B3DC((struct Obj *)p->f100, 1);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
}





void func_02184ECC(W_02185934 *p)
{
    int i;
    u32 w;

    func_02045088(0x28);
    p->win[6] = func_020450F0(0, 2, (u8)1, 0x1b, (u32)4, (u32)0xd, (u32)1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[6])), 0xf);
    p->ent[6].w = p->win[6];
    p->ent[6].f = 0;
    p->win[5] = func_020450F0(1, 1, (u8)2, 0x1e, (u32)0xf, (u32)0, (u32)1);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[5])), 2);
    p->f170 = (u32)func_0203101C(0x28, 0x28, 0x20, 0x20);
    p->f164 = func_0201C440((void *)0x28);
    p->f168 = func_0201C440((void *)0x28);
    for (i = 0; i < 5; i++) {
        p->win[i] = func_020450F0(4, 5, (u8)(i * 4 + 3), 0xa, (u32)2, (u32)0xd, (u32)1);
        func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)p->win[i])), 0);
        p->ent[i].w = p->win[i];
        p->ent[i].f = 0;
        w = p->win[i];
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
    func_02185F74(p->win, 0x44f, p);
}





void func_02185004(char *p)
{
    int i;

    func_0203115C((struct Tcbl *)(((struct Obj03624 *)p)->f170));
    func_02031140((struct S02031140 *)(((struct Obj03624 *)p)->f170));
    func_0201C6EC((struct PrintSys *)(((struct Obj03624 *)p)->f168));
    func_0201C4C0((struct PrintSys *)(((struct Obj03624 *)p)->f168));
    func_0201C6EC((struct PrintSys *)(((struct Obj03624 *)p)->f164));
    func_0201C4C0((struct PrintSys *)(((struct Obj03624 *)p)->f164));
    for (i = 0; i < 5; i++)
        func_020452E8((struct Descriptor *)(*(u32 *)(p + 0x104 + i * 4)));
    func_020452E8((struct Descriptor *)(((struct Obj03624 *)p)->f118));
    func_020452E8((struct Descriptor *)(((struct Obj03624 *)p)->f11C));
    func_020450C8();
}




void func_0218506C(void *actor, int x, int y)
{
    Pt p;
    p.x = x;
    p.y = y - 8;
    func_0204B528(actor, (const struct Pt *)(&p));
}



void func_02185080(Rec *d, int a, int c)
{
    unsigned char buffer[0x44];
    ((PathEnt *)buffer)[0].n = 0;
    ((PathEnt *)buffer)[0].a = 0;
    ((PathEnt *)buffer)[0].b = 0;
    func_021864C4(d, (PathEnt *)buffer, a, c);
}








static inline u8 activate(char *p, int value)
{
    func_021861C4((u8 *)p, value, value);
    func_02186444(p, 5);
    func_021852F4((void *)(((struct Obj00525 *)p)->f100), 1);
    func_020061E4(0x551);
    return value;
}








/*
 * Lever: the activation tail is an inline returning its flag value;
 * assigning the returned u8 to k recolours the merged flag store to r1.
 * The pointer-out helper and inline assignment stayed DIFF by two bytes.
 */
void func_021850A0(char *p)
{
    Path path;
    int tx;
    int ty;
    Rec rec;
    int x;
    int y;
    u8 k;
    int r;
    int i;

    k = 0;
    r = func_02035C08(d_02186AFC);
    if (r != -1) {
        switch (r) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            if (((struct Obj01221 *)p)->f420A != r) {
                ((struct Obj01221 *)p)->f420A = r;
                func_021852B4((u32 *)(p + 0xd0), r);
                func_020061E4(0x548);
            }
            break;
        case 8:
            if (((struct Obj01221 *)p)->f198 != 4)
                break;
            if (func_02039338() == 0) {
                if (((struct Obj01221 *)p)->f1B0 != func_02186558(p)) {
                    func_020061E4(0x54b);
                } else {
                    ((struct Obj01221 *)p)->f9E6C = 2;
                    k = activate(p, 1);
                }
            } else {
                if (((struct Obj01221 *)p)->f4217 == 2) {
                    func_020061E4(0x54b);
                } else {
                    k = activate(p, 1);
                }
            }
            break;
        case 9:
        case 10:
        case 11:
            for (i = 0; i < 3; i++) {
                if (r - 9 == i)
                    func_0204B878((struct Obj *)(*(u32 *)(p + 0xf4 + i * 4)), i * 2 + 0x1e);
                else
                    func_0204B878((struct Obj *)(*(u32 *)(p + 0xf4 + i * 4)), i * 2 + 0x1d);
            }
            if (((struct Obj01221 *)p)->f420B != r - 9) {
                ((struct Obj01221 *)p)->f420B = r - 9;
                func_020061E4(0x548);
            }
            break;
        }
    }
    r = func_02035BA4(d_02186AB4);
    func_0204B3DC((struct Obj *)*(u32 *)(p + 0x60 + func_02039338() * 4), 0);
    if (r != -1) {
        func_02035CB8((u32 *)(&tx), (u32 *)(&ty));
        func_0218506C((void *)(*(int *)(p + 0x60 + func_02039338() * 4)), tx, ty);
        func_0204B3DC((struct Obj *)*(u32 *)(p + 0x60 + func_02039338() * 4), 1);
    }
    x = 0;
    y = 0;
    if (func_02035C38() == 1) {
        func_02035CB8((u32 *)(&x), (u32 *)(&y));
        path.e[0].n = 2;
        path.e[0].a = ((Path *)(p + 0x4244))->e[1].a;
        path.e[0].b = ((Path *)(p + 0x4244))->e[1].b;
        path.e[1].a = x;
        path.e[1].b = y;
        func_021864C4(&rec, path.e, ((struct Obj01221 *)p)->f420A, ((struct Obj01221 *)p)->f420B);
        if (k == 1)
            rec.mid = 0;
    } else {
        path.e[1].a = 0;
        path.e[1].b = 0;
        func_02185080(&rec, ((struct Obj01221 *)p)->f420A, ((struct Obj01221 *)p)->f420B);
    }
    func_02186988((Rec6 *)&rec, p + 0x928c, 0);
    if (func_02039338() == 0)
        func_021868C8(p + 0x928c);
    else
        func_02186888(p + 0x928c);
    *(Path *)(p + 0x4244) = path;
}









void func_021852B4(u32 *p, int n)
{
    int i;

    for (i = 0; i < 8; i++) {
        if (i == n)
            func_0204B878((struct Obj *)p[i], (u16)(d_02186BEC[i].anim + 1));
        else
            func_0204B878((struct Obj *)p[i], d_02186BEC[i].anim);
    }
}








void func_021852F4(void *p, int flag)
{
    if (flag == 1)
        func_0204B878(p, 9);
    else
        func_0204B878(p, 1);
}









int func_0218530C(char *p, int x)
{
    func_021850A0(p);
    if (func_02039338() == 0) {
        if (func_02185F50(p) == 1) {
        } else {
            func_021860D0(p);
        }
    } else {
        func_021860D0(p);
    }
    func_02185EA0((struct P *)p);
    func_02185DE8((char *)(((struct Obj01221 *)p)->f118), (struct e6 *)(p + 0x4212), (struct o4 *)(p + 0x4230), 1);
    return x;
}







void func_02185354(char *p)
{
    func_02185EA0((struct P *)p);
    func_02185DE8(*(char * *)&((struct Obj00525 *)p)->f118, (struct e6 *)(p + 0x4212), (struct o4 *)(p + 0x4230), 0);
}








int func_02185378(char *p, int x)
{
    if (((struct Obj00336 *)p)->f1B4 == func_02039338())
        func_021861C4((u8 *)p, 0xd, 0);
    else
        func_021861C4((u8 *)p, 0, 0);
    func_02186444(p, 2);
    func_02186480(p);
    func_020061E4(0x54c);
    func_0207D658(0x04000050, 14, -6);
    func_02185354(p);
    return x;
}








int func_021853D0(char *p, int a1)
{
    int i;

    for (i = 0; i < 5; i++)
        func_0204B3DC(*(void **)(p + 0x60 + i * 4), 0);
    return a1;
}







/*
 * volatile: hardware halfword store at 0x021853F8 to 0x04000050.
 */
int func_021853F0(char *p, int result)
{
    *(volatile u16 *)0x04000050 = 0;
    func_02186304(p, 1);
    func_02186444(p, 4);
    func_02185354(p);
    ((struct Obj20348 *)p)->f9E7C = 0;
    return result;
}








int func_02185420(char *p, int a1)
{
    if (func_021862B0(p)) {
        if (((struct Obj02742 *)p)->f178 == 0)
            ((struct Obj02742 *)p)->f178 = (void *)func_021865B4(p);
        func_02186444(p, 6);
    }
    func_02185354(p);
    return a1;
}








int func_02185454(char *p, int x)
{
    u32 w;

    ((Bits *)(p + 0x4210))->mid = 0;
    if (((struct Obj02741 *)p)->f4217 == 2 && func_02039338() != 0) {
        func_02185354(p);
        func_020278F4(((struct Obj02741 *)p)->f178);
        if (func_021864A8(p))
            func_020061E4(0x54b);
        return x;
    }
    if (func_02039338() == 0 && ((struct Obj02741 *)p)->f9280 != 0) {
        func_02185354(p);
        func_020278F4(((struct Obj02741 *)p)->f178);
        return x;
    }
    switch (func_02186660(p)) {
    case 0:
        if (func_02039338() == 0) {
            func_02186444(p, 0xf);
            func_021861C4((u8 *)p, 4, 1);
        } else {
            func_02186444(p, 8);
            func_0201F7A8((void *)(((struct Obj02741 *)p)->f11C), 2);
        }
        w = ((struct Obj02741 *)p)->f118;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        break;
    case 1:
        func_02186444(p, 4);
        func_021852F4((void *)(((struct Obj02741 *)p)->f100), 0);
        func_0201F7A8((void *)(((struct Obj02741 *)p)->f11C), 2);
        w = ((struct Obj02741 *)p)->f118;
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
        if (func_02039338() == 0) {
            func_02184560(p, 1);
            ((struct Obj02741 *)p)->f9E6C = 1;
        }
        break;
    }
    func_02185354(p);
    return x;
}








int func_02185584(char *p, int x)
{
    u8 b[4];

    func_02082BCC(b, 0, 4);
    b[2] = 0;
    b[0] = func_02039338();
    if (func_0203D3A8(func_020399A8(), 0x2905, 4, (u32)((void *)b)))
        func_02186444(p, 7);
    func_02185354(p);
    return x;
}








int func_021855C8(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    ((struct Obj20349 *)p)->f9286 = 0;
    func_02185354((char *)p);
    return a1;
}








int func_021855EC(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    ((struct Obj09769 *)p)->f9286 += 1;
    if (((struct Obj09769 *)p)->f9286 > 0x1e) {
        func_02186444((char *)p, 0xa);
        ((struct Obj09769 *)p)->f9286 = 0;
    }
    func_02185354((char *)p);
    return a1;
}







int func_02185628(char *p, int x)
{
    u8 b[4];

    func_02082BCC(b, 0, 4);
    b[2] = 1;
    b[0] = func_02039338();
    if (func_0203D3A8(func_020399A8(), 0x2905, 4, (u32)((void *)b)))
        func_02186444(p, 12);
    func_02185354(p);
    return x;
}







int func_02185670(unsigned char *p, int a1)
{
    ((struct bf4210 *)(p + 0x4210))->b = 0;
    ((struct Obj13025 *)p)->f9288 = 0;
    func_02186444((char *)p, 4);
    func_021852F4(((struct Obj13025 *)p)->f100, 0);
    func_02185354((char *)p);
    return a1;
}







int func_021856AC(char *p, int a1)
{
    func_021861C4((u8 *)p, 6, 1);
    func_02186444(p, 0xd);
    func_02185354(p);
    return a1;
}







int func_021856CC(char *p, int a1)
{
    if (func_021862B0(p)) {
        ((struct Obj20350 *)p)->f1A4 = 0;
        func_02186444(p, 0xe);
    }
    func_02185354(p);
    return a1;
}






int func_021856F4(char *p, int a)
{
    if (++((struct Obj20351 *)p)->f1A4 > 60) {
        func_0202208C(0, 8, 8, 0, 0x10, 1, 0x28);
        a = 3;
    }
    func_02185354(p);
    return a;
}







int func_02185730(char *p, int a1)
{
    if (func_021862B0(p)) {
        if (((struct Obj02742 *)p)->f178 == 0)
            ((struct Obj02742 *)p)->f178 = (void *)func_021865B4(p);
        func_02186444(p, 0x10);
    }
    func_02185354(p);
    return a1;
}







int func_02185764(char *p, int x)
{
    int m;

    m = func_02186660(p);
    if (((struct Obj05108 *)p)->f1AC != func_02186164(p) || ((struct Obj05108 *)p)->f9280 != 0) {
        func_02185354(p);
        return x;
    }
    switch (m) {
    case 0:
        func_02186444(p, 0x11);
        func_02184114((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj05108 *)p)->f4));
        break;
    case 1:
        func_02186444(p, 4);
        func_021852F4((void *)(((struct Obj05108 *)p)->f100), 0);
        func_0201F7A8((void *)(((struct Obj05108 *)p)->f11C), 2);
        if (func_02039338() == 0) {
            func_02184560(p, 1);
            ((struct Obj05108 *)p)->f9E6C = 1;
        }
        break;
    }
    func_02185354(p);
    return x;
}






/*
 * Original narrows the lookup index to u8; its extern expresses the observed call-site width.
 */
void func_021857F4(char *p, int a, int i)
{
    char *v;
    v = func_02184180(**(u8 ** *)&((struct Obj00525 *)p)->f4, (u8)i);
    if (v != 0)
        func_0201F02C(((struct Obj00525 *)p)->f10, a, v);
}







int func_02185814(char *p, int a1)
{
    int z;
    z = 0;
    if (func_0203D3A8(func_0203996C(0xff), 0x2906, 0, 0)) {
        func_02186444(p, 0x12);
        func_021857F4(p, z, z);
        a1 = 2;
    }
    func_02185354(p);
    return a1;
}





int func_02185854(char *p, int a)
{
    func_021857F4(p, 0, 0);
    func_021861C4((u8 *)p, 3, 1);
    func_02186444(p, 0x13);
    func_02185354(p);
    return a;
}





/*
 * extent: two zero padding bytes follow the return at 0x021858B4.
 * Original narrows r3 to u16 before func_0203A424, retained in the call prototype.
 */
int func_02185880(char *p, int a)
{
    if (func_021862B0(p)) {
        func_02186444(p, 0x14);
        func_0203A424((char *)func_020399A8(), 0xc8, 0x29, (u16)((struct Obj20354 *)p)->f1B0);
    }
    func_02185354(p);
    return a;
}




int func_021858B8(char *p, int a1)
{
    int h;
    int i;
    int mask;

    h = (int)func_020399A8();
    mask = 0;
    for (i = 0; i < 5; i++) {
        if (func_0203D1C0((unsigned char)i) == 1)
            mask |= 1 << i;
    }
    if (func_02039CB4((struct Link *)h, 0xc8, 0x29) != 0 || func_0218654C(p) == 1
        || mask != ((struct Obj20355 *)p)->f1B0) {
        func_0202208C(0, 8, 8, 0, 0x10, 1, 0x28);
        a1 = 3;
    }
    func_02185354(p);
    return a1;
}








int func_02185930(int a, int b)
{
    return b;
}

int func_02185934(char *p, int a)
{
    func_021861C4((u8 *)p, 5, 1);
    func_02186444(p, 0x17);
    func_02185354(p);
    return a;
}








int func_02185954(char *p, int a)
{
    if (func_021862B0(p))
        func_02186444(p, 0xe);
    func_02185354(p);
    return a;
}









int func_02185974(char *p, int a1)
{
    func_021861C4((u8 *)p, 2, 1);
    func_02186480(p);
    func_02186444(p, 0x19);
    func_020061E4(0x54c);
    if (func_02039338() == 0)
        func_02186304(p, 0);
    ((struct Obj00336 *)p)->f927C = func_0218654C(p);
    func_02185354(p);
    return a1;
}









int func_021859C4(char *p, int a1)
{
    if (!((((struct Obj06119 *)p)->f927C == 0 || ((struct Obj06119 *)p)->f927C == func_0218654C(p))
          && (func_02186558(p) & ((struct Obj06119 *)p)->f9280)))
        ((struct Obj06119 *)p)->f927C = 0;
    if (func_021862B0(p)) {
        func_02186444(p, 0x1a);
        ((struct Obj06119 *)p)->f1A4 = 0;
    }
    func_02185354(p);
    return a1;
}









int func_02185A1C(char *p, int a1)
{
    if (!((((struct Obj02104 *)p)->f927C == 0 || ((struct Obj02104 *)p)->f927C == func_0218654C(p))
          && (func_02186558(p) & ((struct Obj02104 *)p)->f9280)))
        ((struct Obj02104 *)p)->f927C = 0;
    ((struct Obj02104 *)p)->f1A4 += 1;
    if (((struct Obj02104 *)p)->f1A4 > 0x3c && ((struct Obj02104 *)p)->f927C == 0) {
        func_021862F4(p);
        func_02186444(p, 4);
        if (func_02039338() == 0) {
            ((struct Obj02104 *)p)->f9E6C = 1;
            func_02186304(p, 1);
        }
        ((struct Obj02104 *)p)->f1AC = func_021841A4(**(unsigned char ** *)&((struct Obj02104 *)p)->f4);
        ((struct Obj02104 *)p)->f1B0 = func_021841A0((unsigned char *)(**(u32 * *)&((struct Obj02104 *)p)->f4));
    }
    func_02185354(p);
    return a1;
}









void func_02185AB0(char *p, int msg, int arg)
{
    u32 w;

    switch (msg) {
    case 1:
        if (((struct Obj00336 *)p)->f9288 == 1)
            return;
        if (((struct Obj00336 *)p)->f198 == 6 || ((struct Obj00336 *)p)->f198 == 0x10)
            func_02186480(p);
        func_021852F4((void *)(((struct Obj00336 *)p)->f100), 0);
        func_021857F4(p, 0, arg);
        ((struct Obj00336 *)p)->f1B4 = arg;
        ((struct Obj00336 *)p)->f9280 = 0;
        break;
    case 3:
        func_021862F4(p);
        break;
    case 0xb:
    case 0x12:
        break;
    case 0x18:
        if (((struct Obj00336 *)p)->f9288 == 1)
            return;
        func_021857F4(p, 0, arg);
        if (arg == func_02039338())
            return;
        if (func_02039338() == 0)
            ((struct Obj00336 *)p)->f9280 = ((struct Obj00336 *)p)->f9280 & (arg ^ 0xFFFF);
        if (((struct Obj00336 *)p)->f198 == 6 || ((struct Obj00336 *)p)->f198 == 0x10) {
            func_02186480(p);
            w = ((struct Obj00336 *)p)->f118;
            func_02045334((struct Descriptor *)w);
            func_02045374((struct Cfg *)w);
            func_020409B4(func_02045730((struct Descriptor *)w));
        }
        func_021852F4((void *)(((struct Obj00336 *)p)->f100), 0);
        break;
    case 9:
        func_02186860(p, 0x2907, func_02039338());
        break;
    default:
        return;
    }
    func_02186444(p, msg);
}









/*
 * Clearing dx/dy before the w/h subtraction is what moves a1 into r0 at
 * entry (t in r1, the bound in r2); clearing it last keeps a1 in r1.
 */
void func_02185BBC(int a0, int a1, int x, int y, int w, int h, int dx, int dy,
                   int mx, int my)
{
    int s;
    int t;

    if (dx < 0) {
        t = -dx;
        if (t > mx)
            t = mx;
        x += t;
        dx = 0;
        w -= t;
    }
    if (dy < 0) {
        t = -dy;
        if (t > my)
            t = my;
        y += t;
        dy = 0;
        h -= t;
    }
    s = (int)func_020436FC((void *)a1, 8, 8, 0x20, 0x28);
    func_020439A0((struct Bmp *)s, (struct Bmp *)((int)func_02045770((struct Descriptor *)a0)), x, y, dx, dy, w, h, 0);
    func_020437AC((struct Obj020437AC *)s);
}








void func_02185C38(int a0, int a1, int x1, int y1, int *px, int *py, int c, int d)
{
    int sx;
    int sy;
    int ex;
    int dx;
    int ey;
    int dy;
    int err;
    int step;

    sx = *px;
    sy = *py;
    ex = x1;
    ey = y1;
    if (c == 0 && d == 0) {
        *px = x1;
        *py = y1;
        return;
    }
    dx = x1 - sx;
    if (dx < 0)
        dx = -dx;
    dy = y1 - sy;
    if (dy < 0)
        dy = -dy;
    if (dx > dy) {
        if (sx > x1) {
            step = (sy > y1) ? 1 : -1;
            ex = sx;
            sx = x1;
            sy = y1;
        } else {
            step = (sy < y1) ? 1 : -1;
        }
        func_02185BBC(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        err = dx >> 1;
        for (sx++; sx <= ex; sx++) {
            err -= dy;
            if (err < 0) {
                err += dx;
                sy += step;
            }
            func_02185BBC(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        }
    } else {
        if (sy > y1) {
            step = (sx > x1) ? 1 : -1;
            ey = sy;
            sy = y1;
            sx = x1;
        } else {
            step = (sx < x1) ? 1 : -1;
        }
        func_02185BBC(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        err = dy >> 1;
        for (sy++; sy <= ey; sy++) {
            err -= dx;
            if (err < 0) {
                err += dy;
                sx += step;
            }
            func_02185BBC(a0, a1, 0, 0, 6, 6, sx, sy, 6, 6);
        }
    }
    *px = x1;
    *py = y1;
}








void func_02185DA8(struct e6 *e, struct o4 *o)
{
    int i;

    for (i = 0; i < 5; i++) {
        o[i].n = e[i].n;
        if (e[i].n != 0) {
            o[i].x = *((unsigned char *)&e[i] + e[i].n - 1);
            o[i].y = *((unsigned char *)&e[i] + e[i].n + 1);
        }
    }
}








void func_02185DE8(char *p, struct e6 *e, struct o4 *o, int flag)
{
    int hit;
    int i;
    int x;
    int y;

    hit = 0;
    for (i = 0; i < 5; i++) {
        if (e[i].n == 2) {
            x = e[i].b[0] - 9;
            y = e[i].b[2] - 0x11;
            func_02185C38((int)p, (int)(d_02186C34 + e[i].d * 0xc0 + e[i].c * 0x18),
                          e[i].b[1] - 9, e[i].b[3] - 0x11, &x, &y, 1, o[i].n);
            hit = 1;
        }
    }
    if (hit && flag) {
        func_02045334((struct Descriptor *)p);
        func_02045374((struct Cfg *)p);
        func_020409B4(func_02045730((struct Descriptor *)p));
    }
    func_02185DA8(e, o);
    for (i = 0; i < 5; i++)
        e[i].n = 0;
}








/*
 * The 6-byte records at +0x4212 are reached through a byte cast of a struct
 * pointer at every use (E below): the base is hoisted into r6 and the
 * element address is recomputed (muls) at each use. A local `e`, or a
 * `char *` parameter with the same cast, CSEs the element pointer instead.
 */
void func_02185EA0(struct P *p)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (i == func_02039338())
            continue;
        if (E(p)[i].n != 0 && func_02184180((unsigned char *)(*p->unk4), (unsigned char)i) != 0) {
            func_0204B3DC((struct Obj *)p->unk60[i], 1);
            func_0218506C((void *)p->unk60[i], E(p)[i].b[E(p)[i].n - 1], E(p)[i].b[E(p)[i].n + 1]);
        } else {
            func_0204B3DC((struct Obj *)p->unk60[i], 0);
        }
    }
}








void func_02185F10(u16 *p)
{
    u16 col;

    *p += 20;
    if (*p > 360)
        *p = 0;
    col = (u16)((((func_0203F684(*p) * 10) / 0x1000) + 15) << 5 | 0x1d);
    GX_LoadOBJPltt(&col, 0x18, 2);
}







/*
 * lever: index declared before count places i in r4 and n in r5.
 */
int func_02185F50(char *p)
{
    int i;
    int n;
    n = 0;
    for (i = 0; i < 5; i++) {
        if (func_02184180(**(u8 ** *)&((struct Obj20359 *)p)->f4, (u8)i) != 0)
            n++;
    }
    return n;
}








void func_02185F74(u32 *win, u16 color, W_02185934 *p)
{
    int sel;
    int i;
    u32 w;
    u32 t;

    sel = func_02039338();
    if (!func_02186170((char *)p))
        return;
    for (i = 0; i < 5; i++) {
        if (p->e1c8[i].w == 0)
            func_0204B3DC((struct Obj *)p->arr98[i], 0);
        else
            func_0204B3DC((struct Obj *)p->arr98[i], 1);
    }
    func_0201C6EC((struct PrintSys *)p->f164);
    for (i = 0; i < 5; i++)
        func_02043AF4((struct Bmp *)((u32)func_02045770((struct Descriptor *)win[i])), 0, 0, 0x50, 0x10, 0);
    for (i = 0; i < 5; i++) {
        if (p->e1c8[i].w != 0) {
            func_02008500((void *)p->e1c8[i].w, (void *)p->arr18[i]);
            if (sel == i) {
                t = p->f164;
                func_0201C724((void *)t, (u32)func_02045770((struct Descriptor *)p->ent[i].w), 0, 0, p->arr18[i], p->f0c, 0xc80);
                p->ent[i].f = 1;
            } else {
                t = p->f164;
                func_0201C724((void *)t, (u32)func_02045770((struct Descriptor *)p->ent[i].w), 0, 0, p->arr18[i], p->f0c, color);
                p->ent[i].f = 1;
            }
        }
        w = win[i];
        func_02045334((struct Descriptor *)w);
        func_02045374((struct Cfg *)w);
        func_020409B4(func_02045730((struct Descriptor *)w));
    }
}








void func_021860D0(char *p)
{
    void *h;

    if (func_02039338() == 0) {
        h = func_020399A8();
        if (func_0203D56C(h) == 0)
            return;
        func_02186A04(p + 0x9e4c, p + 0x928c);
        ((struct Obj01221 *)p)->f9E51 = ((struct Obj01221 *)p)->f9E6C;
        if (func_0203D3A8(h, 0x2902, 0x1e, (u32)(p + 0x9e4c)) == 1)
            func_02186958(p + 0x928c);
    } else {
        h = func_020399A8();
        func_021869C0((Rec_021869C0 *)(p + 0x420c), p + 0x928c);
        if (func_0203D56C(h) == 0)
            return;
        if (func_0203D3A8(func_020399A8(), 0x2901, 6, (u32)(p + 0x420c)) == 1)
            func_02186958(p + 0x928c);
    }
}








/*
 * Unblocked by matching the leaf at 0x021841A4 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
int func_02186164(char *p)
{
    return func_021841A4((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj20361 *)p)->f4));
}








int func_02186170(char *p)
{
    int i;
    int r;

    r = 0;
    for (i = 0; i < 5; i++) {
        *(int *)(p + i * 8 + 0x1cc) = *(int *)(p + i * 8 + 0x1c8);
        *(int *)(p + i * 8 + 0x1c8) = (int)func_02184180((unsigned char *)(**(int * *)&((struct Obj20363 *)p)->f4), (unsigned char)i);
    }
    for (i = 0; i < 5; i++) {
        if (*(int *)(p + i * 8 + 0x1cc) != *(int *)(p + i * 8 + 0x1c8))
            r = 1;
    }
    return r;
}








void func_021861C4(u8 *w, u32 msg, int mode)
{
    void *str;
    void *t;
    void *p;

    str = func_020457B0(0x50, 0x28);
    func_02045CAC(((struct Obj00525 *)w)->f14, msg, str);
    func_0201F250(((struct Obj00525 *)w)->f10, ((struct Obj00525 *)w)->f30, str);
    func_02045808(str);
    func_02043B5C(func_02045770(((struct Obj00525 *)w)->f11C), 15);
    func_0201F73C(((struct Obj00525 *)w)->f11C, 0, 1, 10);
    if (((struct Obj00525 *)w)->f16C != 0) {
        func_0201CE48(((struct Obj00525 *)w)->f16C);
        ((struct Obj00525 *)w)->f16C = 0;
    }
    if (mode == 0) {
        t = ((struct Obj00525 *)w)->f168;
        func_0201C724(t, (u32)func_02045770(((struct Obj00525 *)w)->f15C), 0, 0, (u32)(((struct Obj00525 *)w)->f30), ((struct Obj00525 *)w)->fC, 0x44F);
        ((struct Obj00525 *)w)->f160 = 1;
    } else {
        ((struct Obj00525 *)w)->f16C = func_0201CCE4(((struct Obj00525 *)w)->f11C, 0, 0, ((struct Obj00525 *)w)->f30,
                                              ((struct Obj00525 *)w)->fC, func_02012FFC(),
                                              ((struct Obj00525 *)w)->f170, 1, 0x28, 0xF0F);
    }
    p = ((struct Obj00525 *)w)->f11C;
    func_02045334(p);
    func_02045374(p);
    func_020409B4(func_02045730(p));
}








int func_021862B0(char *p)
{
    int r = func_0201CE30(((struct Obj00525 *)p)->f16C);

    if (r == 1) {
        if (func_020362DC() & 1) {
            func_0201CE38(((struct Obj00525 *)p)->f16C);
        }
        return 0;
    }
    if (r == 2) {
        func_0201CE48(((struct Obj00525 *)p)->f16C);
        ((struct Obj00525 *)p)->f16C = 0;
        return 1;
    }
    return ((struct Obj00525 *)p)->f16C == 0;
}







void func_021862F4(char *p)
{
    func_0201F7A8(((struct Obj20365 *)p)->f11C, 0);
}







/*
 * extent: two zero padding bytes follow the return at 0x02186320.
 * Caller explicitly sets r1 for func_02184560, retained despite its legacy one-argument definition.
 */
void func_02186304(char *p, int a)
{
    if (func_02039338() == 0) {
        func_0218654C(p);
        func_02184560(p, a);
    }
}








int func_02186324(u8 *p)
{
    int st;
    int r;

    st = func_02186164((char *)p);
    switch (st) {
    case 0:
        break;
    case 1:
        if (((struct Obj00460 *)p)->f198 > 0x10) {
            break;
        }
        if (func_02186558((char *)p) != 1) {
            ((struct Obj00460 *)p)->f9E78 = 1;
        }
        ((struct Obj00460 *)p)->f19C = 0x16;
        if (((struct Obj00460 *)p)->f9E70 != 0) {
            func_02186480((char *)p);
            func_0204B878(((struct Obj00460 *)p)->fF0, 0x15);
        }
        return 2;
    case 2:
    case 3:
    case 4:
        if (st < ((struct Obj00460 *)p)->f1A8) {
            if (((struct Obj00460 *)p)->f9E6C == 2) {
                func_02186304((char *)p, 0);
            } else if (((struct Obj00460 *)p)->f9E7C == 0) {
                func_02186304((char *)p, 1);
            } else {
                func_02186304((char *)p, 0);
            }
        }
        break;
    case 5:
        break;
    }
    if (st < ((struct Obj00460 *)p)->f1A8) {
        ((struct Obj00460 *)p)->f1AC = func_0218654C((char *)p);
        r = func_02186558((char *)p);
        ((struct Obj00460 *)p)->f1B0 = r;
        if (((struct Obj00460 *)p)->f9E7C != 0 && (r & ((struct Obj00460 *)p)->f9E80) == 0) {
            func_02186304((char *)p, 1);
            ((struct Obj00460 *)p)->f9E6C = 1;
            ((struct Obj00460 *)p)->f9E7C = 0;
            ((struct Obj00460 *)p)->f9E80 = 0;
        }
    }
    ((struct Obj00460 *)p)->f1A8 = func_02186164((char *)p);
    if (((struct Obj00460 *)p)->f1AC < func_0218654C((char *)p)) {
        ((struct Obj00460 *)p)->f9E6C = 2;
        ((struct Obj00460 *)p)->f9E7C = 1;
        ((struct Obj00460 *)p)->f9E80 = func_02186558((char *)p) ^ ((struct Obj00460 *)p)->f1B0;
    }
    return 1;
}








void func_02186444(char *p, u32 v)
{
    ((struct Obj20366 *)p)->f19C = v;
}







void func_0218644C(char *p, int mode)
{
    int n;
    n = ((struct Obj07610 *)p)->f19C;
    if (((struct Obj07610 *)p)->f198 != n) {
        if (mode != 2) {
            ((struct Obj07610 *)p)->f198 = n;
            return;
        }
        if (d_02186E84[n][0] != 0)
            ((struct Obj07610 *)p)->f198 = n;
    }
}







void func_02186480(char *p)
{
    if (((struct Obj00336 *)p)->f9E70 != 0) {
        if (((struct Obj00336 *)p)->f178 != 0)
            func_02186694(p);
        ((struct Obj00336 *)p)->f9E70 = 0;
    }
}






int func_021864A8(char *p)
{
    if (func_02035C08(d_02186AAC) != -1)
        return 1;
    return 0;
}







void func_021864C4(Rec *d, PathEnt *s, int a, int c)
{
    int i;
    PathEnt *e;

    if (s[0].n != 0) {
        d->b[0] = s[0].a;
        d->b[2] = s[0].b;
        e = &s[s[0].n - 1];
        d->b[1] = e->a;
        d->b[3] = e->b;
        for (i = 0; i < 2; i++) {
            if (d->b[i] + d->b[i + 2] == 0) {
                s[0].n = 0;
            }
        }
    }
    if (s[0].n >= 2) {
        d->mid = 2;
    } else {
        d->mid = s[0].n;
    }
    d->lo = a;
    d->hi = c;
}







int func_0218654C(char *p)
{
    return func_021841A4((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj13027 *)p)->f4));
}







/*
 * Unblocked by matching the leaf at 0x021841A0 in ov022: the address is
 * below ov023's own base (0x021841E0) and ov022 is its only coherent code
 * home; the region hint is corrected from ov023 to ov022.
 */
int func_02186558(char *p)
{
    return func_021841A0((unsigned char *)(*(u32 *)*(u32 * *)&((struct Obj20368 *)p)->f4));
}







void func_02186564(void)
{
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    func_02040588(0, 1);
    func_02040588(1, 1);
    func_02040588(2, 1);
    func_02040588(4, 1);
    func_02040588(5, 1);
    *(volatile u16 *)0x04000304 = *(volatile u16 *)0x04000304 & 0xFFFF7FFF;
}







int func_021865B4(char *p)
{
    int i;
    int r;
    char *e;
    Ent_021865B4 *t;
    Arg s;

    ((struct Obj02742 *)p)->f174 = (u32)func_02027F60(0, 2, ((struct Obj02742 *)p)->fC, ((struct Obj02742 *)p)->f168, 0x28);
    for (i = 0; i < 2; i++) {
        t = &d_02186ABC[i];
        *(u32 *)(p + i * 12 + 0x17C) = (u32)func_02045EC0((struct MsgBank *)(((struct Obj02742 *)p)->f14), d_02186ABC[i].a);
        *(u16 *)(p + i * 12 + 0x180) = 0x39E3;
        *(u32 *)(p + i * 12 + 0x184) = t->b;
    }
    s.a = 0x28;
    s.b = 2;
    s.c = (u32)(p + 0x17C);
    s.d = 0;
    s.e[0] = 0x15;
    s.e[1] = 7;
    s.e[2] = 10;
    s.e[3] = 3;
    r = (int)func_02027778((struct TaskMenuTmpl *)(&s), (void *)(((struct Obj02742 *)p)->f174));
    ((struct Obj02742 *)p)->f9E70 = 1;
    return r;
}






/*
 * extent: trailing two-byte zero alignment padding at 0x02186692.
 * lever: naming the accessor result before clearing r preserves call/store scheduling.
 */
int func_02186660(char *p)
{
    int r = 2;
    func_02027974(*(struct Obj * *)&((struct Obj03625 *)p)->f178);
    if (func_020279E8(*(struct TaskMenu * *)&((struct Obj03625 *)p)->f178) != 0) {
        u8 v = func_02027A04(*(const u8 * *)&((struct Obj03625 *)p)->f178);
        r = 0;
        if (v != 0) r = 1;
        func_02186694(p);
    }
    return r;
}






/*
 * extent: trailing two-byte zero alignment padding at 0x021866C2.
 */
void func_02186694(char *p)
{
    func_02027858(*(struct TaskMenu * *)&((struct Obj03625 *)p)->f178);
    func_02045808(((struct Obj03625 *)p)->f188);
    func_02045808(((struct Obj03625 *)p)->f17C);
    func_02027FD8(*(struct TaskMenuState * *)&((struct Obj03625 *)p)->f174);
    *(int *)&((struct Obj03625 *)p)->f178 = 0;
}







void func_021866C4(u32 *p)
{
    int i;
    u32 h;
    u32 r;

    h = (u32)func_0200ED48(func_02012EBC((struct Big *)(*(u32 *)(p[1] + 4))));
    for (i = 0; i < 5; i++) {
        r = (u32)func_02184180((unsigned char *)(*(u32 *)p[1]), (u8)i);
        if (r != 0) {
            if (i != func_02039338()) {
                func_0200ED54((struct L0200ED54 *)h, func_02008530((const struct Sub0200852CObj *)r));
            }
        }
    }
}






void func_02186708(char *p)
{
    int i;
    u32 h;

    func_0201C4E4((struct PrintSys *)(((struct Obj03626 *)p)->f164));
    func_0201C4E4((struct PrintSys *)(((struct Obj03626 *)p)->f168));
    for (i = 0; i < 5; i++) {
        h = ((struct Obj03626 *)p)->f164;
        if (*(u8 *)(p + i * 8 + 0x130) != 0) {
            if (func_0201C6C4((struct PrintSys *)h, (void *)((u32)func_02045770((struct Descriptor *)*(u32 *)(p + i * 8 + 0x12C)))) == 0) {
                func_02045334((struct Descriptor *)*(u32 *)(p + i * 8 + 0x12C));
                *(u8 *)(p + i * 8 + 0x130) = 0;
            }
        }
    }
    h = ((struct Obj03626 *)p)->f168;
    if (((struct Obj03626 *)p)->f160 != 0) {
        if (func_0201C6C4((struct PrintSys *)h, (void *)((u32)func_02045770((struct Descriptor *)((struct Obj03626 *)p)->f15C))) == 0) {
            func_02045334((struct Descriptor *)((struct Obj03626 *)p)->f15C);
            ((struct Obj03626 *)p)->f160 = 0;
        }
    }
}






void func_021867C4(char *p)
{
    switch (((struct Obj06120 *)p)->f9270) {
    case 0x2903:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2903, 1, (u32)(p + 0x9274)) != 0) {
            ((struct Obj06120 *)p)->f9270 = 0;
        }
        break;
    case 0x2904:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2904, 0, 0) != 0) {
            ((struct Obj06120 *)p)->f9270 = 0;
        }
        break;
    case 0x2905:
        if (func_0203D3A8(func_0203996C(0xFF), 0x2905, 4, (u32)(p + 0x9278)) != 0) {
            ((struct Obj06120 *)p)->f9270 = 0;
        }
        break;
    case 0x2906:
        break;
    case 0x2907:
        if (func_0203D3A8(func_020399A8(), 0x2907, 0, 0) != 0) {
            ((struct Obj06120 *)p)->f9270 = 0;
        }
        break;
    }
}





void func_02186860(char *p, int x, int y)
{
    if (((struct Obj01674 *)p)->f9270 == 0) {
        ((struct Obj01674 *)p)->f9270 = x;
        ((struct Obj01674 *)p)->f9274 = y;
    }
}





int func_02186878(char *p)
{
    int i = ((struct Obj20371 *)p)->fBBC - 1;
    if (i < 0) i = 99;
    return i;
}






void func_02186888(char *p)
{
    if (((Rec6 *)(p + ((struct Obj07611 *)p)->fBBC * 30))->mid != 0
        || ((Rec6 *)(p + func_02186878(p) * 30))->mid != 0) {
        ((struct Obj07611 *)p)->fBBC += 1;
        if (((struct Obj07611 *)p)->fBBC >= 100) {
            ((struct Obj07611 *)p)->fBBC = 0;
        }
    }
}





/*
 * The second loop indexes ((Grp_02186958 *)p)[idx].r[j] in full and lets the
 * compiler hoist p + idx*30 itself: a named group pointer puts the 30*idx
 * temporary in r1 instead of r2.
 * Rec6 has a spare sixth byte so `r[i]` is `muls #6`.
 */
/*
 * The second loop indexes ((Grp *)p)[idx].r[j] in full and lets the
 * compiler hoist p + idx*30 itself: a named group pointer puts the 30*idx
 * temporary in r1 instead of r2.
 * Byte 6 of Rec (b5) exists only to make sizeof(Rec) == 6 so `r[i]` is `muls #6`.
 */
void func_021868C8(char *p)
{
    int i;
    int n;
    int m;
    Rec6 *r;

    n = 0;
    m = 0;
    i = 0;
    r = ((Grp_02186958 *)p)[*(int *)(p + 0xBBC)].r;

    for (; i < 5; i++) {
        if (r[i].mid == 0) {
            n++;
        }
    }
    if (n == 5) {
        int idx = func_02186878(p);
        int j;
        for (j = 0; j < 5; j++) {
            if (((Grp_02186958 *)p)[idx].r[j].mid == 0) {
                m++;
            }
        }
    }
    if (m != 5) {
        ((struct Obj09772 *)p)->fBBC += 1;
        if (((struct Obj09772 *)p)->fBBC >= 100) {
            ((struct Obj09772 *)p)->fBBC = 0;
        }
    }
}




/*
 * extent: trailing two-byte zero alignment padding at 0x02186956.
 */
void func_02186938(Rec6 *p)
{
    int i;
    for (i = 0; i < 5; i++) p[i].mid = 0;
}



void func_02186958(char *p)
{
    if (((struct Obj05109 *)p)->fBB8 != ((struct Obj05109 *)p)->fBBC) {
        func_02186938((Rec6 *)(p + ((struct Obj05109 *)p)->fBB8 * 30));
        ((struct Obj05109 *)p)->fBB8 += 1;
        if (((struct Obj05109 *)p)->fBB8 >= 100) ((struct Obj05109 *)p)->fBB8 = 0;
    }
}



void func_02186988(Rec6 *s, char *p, int i)
{
    ((Grp_02186958 *)p)[*(int *)(p + 0xBBC)].r[i] = *s;
}




void func_021869C0(Rec_021869C0 *d, char *p)
{
    int i = ((struct Obj13028 *)p)->fBB8;

    if (i != ((struct Obj13028 *)p)->fBBC) {
        *d = *(Rec_021869C0 *)(p + i * 30);
    } else {
        d->mid = 0;
    }
}
