/*
 * file:     box2_main_p01.c
 * unit:     yes
 * function: func_021DC9E0, func_021DCB48, func_021DCB8C, func_021DCDB8, func_021DCDD8, func_021DCDF0, func_021DCE14, func_021DCE80, func_021DCEC0, func_021DCF30, func_021DCF58, func_021DCFC0, func_021DD090, func_021DD14C, func_021DD16C, func_021DD1C4, func_021DD1E8, func_021DD210, func_021DD238, func_021DD25C, func_021DD2B4, func_021DD2D0, func_021DD314, func_021DD330, func_021DD39C
 * address:  0x021DC9E0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_020434DC 0x020434DC arm
 *   func_02043598 0x02043598 arm
 *   d_021EF7FC 0x021EF7FC data
 *   d_021EF82C 0x021EF82C data
 *   d_021EF8CC 0x021EF8CC data
 *   d_021EF86C 0x021EF86C data
 *   d_021EF88C 0x021EF88C data
 *   d_021EF80C 0x021EF80C data
 *   d_021EF8AC 0x021EF8AC data
 *   d_021EF84C 0x021EF84C data
 *   func_020403F4 0x020403F4 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020490F4  0x020490F4  arm
 *   func_02049658  0x02049658  arm
 *   func_02049740  0x02049740  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02049F34  0x02049F34  arm
 *   func_02040E78  0x02040E78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   func_02027628  0x02027628  thumb
 *   func_02027624  0x02027624  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_020413B0  0x020413B0  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_0201F5DC  0x0201F5DC  thumb
 *   func_02049B40  0x02049B40  arm
 *   func_020215A0  0x020215A0  thumb
 *   func_02021540  0x02021540  thumb
 *   func_0207D63C  0x0207D63C  arm
 *   func_02045B38 0x02045B38 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201EC64 0x0201EC64 thumb
 *   func_0201C450 0x0201C450 thumb
 *   func_020457B0 0x020457B0 arm
 *   func_02045808 0x02045808 arm
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201ED04 0x0201ED04 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_02045C04 0x02045C04 arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_02027F60 0x02027F60 thumb
 *   func_020260F0 0x020260F0 thumb
 *   func_020355D8 0x020355D8 arm
 *   func_02027778 0x02027778 thumb
 *   func_02027CFC 0x02027CFC thumb
 *   func_021EBFCC 0x021EBFCC thumb
 *   func_021EBFEC 0x021EBFEC thumb
 *   func_0202CF98 0x0202CF98 thumb
 *   func_0202CFC0 0x0202CFC0 thumb
 *   func_0202CF8C 0x0202CF8C thumb
 *   func_021EE038  0x021EE038  thumb  ov170
 *   func_021EF660  0x021EF660  thumb  ov170
 *   func_021EBFA8 0x021EBFA8 thumb
 *   func_021EC35C 0x021EC35C thumb
 *   func_021DEDCC 0x021DEDCC thumb
 *   func_021DEC98 0x021DEC98 thumb
 *   func_021DEB14  0x021DEB14  thumb  ov170
 *   func_021EDECC  0x021EDECC  thumb  ov170
 *   func_021EE008  0x021EE008  thumb  ov170
 *   func_021ED904  0x021ED904  thumb  ov170
 *   func_021ED9B4  0x021ED9B4  thumb  ov170
 *   func_021EDF5C  0x021EDF5C  thumb  ov170
 *   func_021EB85C  0x021EB85C  thumb  ov170
 *   func_021EF738  0x021EF738  thumb  ov170
 *   func_0201AA18 0x0201AA18 thumb
 *   func_0201AB28 0x0201AB28 thumb
 *   func_02017E1C 0x02017E1C thumb
 *   func_02017E88 0x02017E88 thumb
 *   func_02007A18 0x02007A18 thumb
 *   func_020185F0 0x020185F0 thumb
 *   func_021EDAB0 0x021EDAB0 thumb ov170
 *   func_0201747C 0x0201747C thumb
 *   func_020185F4 0x020185F4 thumb
 *   func_020075B0 0x020075B0 thumb
 *   func_0201AB48 0x0201AB48 thumb
 *   func_0201A98C 0x0201A98C thumb
 */
#include "../../matched/include/Obj12146.h"
#include "../../matched/include/Obj18439.h"
#include "../../matched/include/Obj18440.h"
#include "../../matched/include/Obj00000.h"
#include "../../matched/include/Obj23825.h"
#include "../../matched/include/Obj23826.h"
#include "../../matched/include/Obj23827.h"
#include "../../matched/include/Obj18441.h"
#include "../../matched/include/Obj18442.h"
#include "../../matched/include/Obj18443.h"
#include "../../matched/include/Obj18444.h"

#define HALF(p,n) (*(unsigned short *)(WORK(p)+(n)))
struct PalAnmSlot;
struct GfFont;
struct MsgBank;
struct U16Vec;
struct WordSet;
struct PrintSys;
struct Rec;
struct R;
struct TaskMenuState;
struct Sound;
struct TaskMenu;
struct TaskMenuTmpl;
struct WinMgr;
struct Struct_02025CD0;
struct Sub020079BCEntry;
struct Party;
struct Mon;
struct PartyMon;
struct Sub020075B0Entry;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

struct DispConfig {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0c;
};

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

typedef struct { u32 f0; u32 f4; u32 f8; u8 *fC; } PlttData;

struct Ov170Ctx { char pad[0x2c]; char *f2c; };

typedef struct {
    u32 heapId;
    u8 count;
    u8 pad05[3];
    const void *items;
    u32 unk0c;
    u8 x;
    u8 y;
    u8 w;
    u8 h;
} MenuTmpl;

typedef struct {
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} Fade;

typedef struct {
    unsigned char pad[0x1A6];
    unsigned char flag : 1;
    unsigned char id : 7;
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char state;
    unsigned char count;
    unsigned char x;
    unsigned char y;
    unsigned char w;
    unsigned char h;
} Work;

typedef struct {
    unsigned char pad[0x2C];
    Work *work;
} Sys;

typedef signed char s8;

typedef signed int     s32;

extern void func_0203F8F4(u16 heap);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern void func_020403F4(unsigned);
extern void func_0203F9B4(void);
extern void *func_020490F4(u32 id, u32 heap);
extern u32 func_02049658(void *, u32, u32, u32, u32, u32, u16);
extern u32 func_02049740(void *, u32, u32, u32, u32, u16);
extern void func_020498F4(void *, u32, u32, u32, u32, u32, u16);
extern void func_02049B68(void *, u32, u32, u32, u32, u16);
extern u32 func_020275E4(void);
extern void *func_02049F34(u32 a0, u32 a1, u32 a2, u32 a3);
extern void func_02040E78(u32 a, void *src, u32 size, u32 ofs);
extern u32 func_020307B0(void *p);
extern void func_02049238(void *);
extern u32 func_02027628(void);
extern u32 func_02027624(void);
extern u32 func_0202762C(void);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_02041B6C(u32);
extern u32 func_0204162C(int channel);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_02049B40(u32, u32, u32, u32, u32, u16);
extern void *func_02021518(u32 heap);
extern void func_0202155C(struct PalAnmSlot *slots, u32 idx, u32 size, u32 heap);
extern void func_020215A0(struct PalAnmSlot *slots, u32 idx);
extern u32 func_02021540(void *a0);
extern void func_0207D63C(int, int, int, int, int);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern struct WordSet *func_0201EC64(u32 heap);
extern void *func_0201C450(unsigned short,unsigned);
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045808(struct U16Vec *vec);
extern void func_0201C4C0(struct PrintSys *p);
extern unsigned int func_0201ED04(struct WordSet *p);
extern u32 func_0201D83C(void *ptr);
extern u32 func_02045C04(struct Rec *rec);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern u32 func_020260F0(struct Sound *obj);
extern void func_020355D8(u8 v);
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02027CFC(u8 *p, int sel);
extern void func_021EBFCC(char *p, int i, int v);
extern u32 func_021EBFEC(char *p, int i);
extern void func_0202CF98(struct WinMgr *mgr, u32 idx, s8 *x, s8 *y);
extern void func_0202CFC0(struct WinMgr *mgr, u32 idx, u16 *w, u16 *h);
extern u8 func_0202CF8C(struct WinMgr *mgr, u32 idx);
extern void func_021EE038(char *, int, int, int);
extern void func_021EF660(struct WinMgr *mgr);
extern void func_021EBFA8(char *p, int i, int v);
extern void func_021EC35C(char **p, int box);
extern int func_021DEDCC(char *p, int box);
extern void func_021DEC98(char *p, void *a, int dir);
extern unsigned char func_021DEB14(unsigned char *p, int a);
extern void func_021EDECC(unsigned char *p, int d);
extern void func_021EE008(char *, int, int);
extern void func_021ED904(unsigned char *p);
extern void func_021ED9B4(int);
extern void func_021EDF5C(unsigned char *p);
extern void func_021EB85C(unsigned char *p, int i);
extern void func_021EF738(struct WinMgr *mgr);
extern void func_020260F4(struct Struct_02025CD0 *obj, u32 state);
extern unsigned func_0201AA18(void *p);
extern void *func_0201AB28(void *party, unsigned i);
extern unsigned func_02017E1C(void *p, unsigned id, unsigned v);
extern unsigned func_02017E88(void *p, unsigned id, unsigned v);
extern struct Sub020079BCEntry *func_02007A18(void **save, u32 box, u32 slot);
extern void func_02017E64(void *p, u32 id, u32 v);
extern int func_020185F0(void *p);
extern void func_02007664(void *save, u32 box, u32 slot);
extern u32 func_0201A9C8(struct Party *p, s32 idx);
extern void func_021EDAB0(char *p, int i);
extern void *func_0201747C(struct Mon *p, u32 heap);
extern void *func_020185F4(void *);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern void func_0201AB48(struct Party *p, u32 idx, const struct PartyMon *src);
extern u32 func_0201A98C(struct Party *p, const struct PartyMon *src);
void func_021DC9E0(u8 *a0);
void func_021DCB48(void *p);
void func_021DCB8C(struct Ov170Ctx *ctx);
void func_021DCDB8(char *p);
void func_021DCDD8(int *p);
void func_021DCDF0(int a);
void func_021DCE14(char *p);
void func_021DCE80(char *p);
void func_021DCEC0(char *p);
void func_021DCF30(char *p);
void func_021DCF58(unsigned char *p, int sel);
int func_021DCFC0(char *p);
void func_021DD090(Sys *p, unsigned idx);
void func_021DD14C(char *p);
void func_021DD16C(unsigned char *p, int dir);
void func_021DD1C4(char *p, int a);
void func_021DD1E8(char *p);
int func_021DD210(unsigned char *p, unsigned a, unsigned b);
void func_021DD238(char *p);
unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v);
void func_021DD2B4(int a, int b, int c, int d, int e);
int func_021DD2D0(void ***p, int a, unsigned b);
void func_021DD314(char **p, int a, unsigned b);
void func_021DD330(unsigned char *p,unsigned short *q,unsigned short *t);
void func_021DD39C(unsigned char *p, unsigned short *q);
extern const struct DispConfig d_021EF7FC;
extern const struct BgTemplate d_021EF82C;
extern const struct BgTemplate d_021EF8CC;
extern const struct BgTemplate d_021EF86C;
extern const struct BgTemplate d_021EF88C;
extern const struct BgTemplate d_021EF80C;
extern const struct BgTemplate d_021EF8AC;
extern const struct BgTemplate d_021EF84C;


/*
 * Background setup of the box screen: display banks, seven layers from
 * the rodata templates (clearing 1, 4 and 6), then the plane masks.
 */
void func_021DC9E0(u8 *a0)
{
    struct DispConfig c;
    struct BgTemplate t0;
    struct BgTemplate t1;
    struct BgTemplate t2;
    struct BgTemplate t3;
    struct BgTemplate t4;
    struct BgTemplate t5;
    struct BgTemplate t6;

    func_0203F8F4(0x4C);
    c = d_021EF7FC;
    func_0203FC28(&c);
    t0 = d_021EF82C;
    func_0203FCA0(0, &t0, 0);
    t1 = d_021EF8CC;
    func_0203FCA0(1, &t1, 0);
    func_020414EC(1);
    func_02040B94(1, 0x20, 0, 0x4C);
    t2 = d_021EF86C;
    func_0203FCA0(2, &t2, 0);
    t3 = d_021EF88C;
    func_0203FCA0(3, &t3, 0);
    t4 = d_021EF80C;
    func_0203FCA0(4, &t4, 0);
    func_020414EC(4);
    func_02040B94(4, 0x20, 0, 0x4C);
    t5 = d_021EF8AC;
    func_0203FCA0(5, &t5, 0);
    t6 = d_021EF84C;
    func_0203FCA0(6, &t6, 0);
    func_020414EC(6);
    func_02040B94(6, 0x20, 0, 0x4C);
    func_020434DC(0xF, 1);
    func_02043598(7, 1);
}

void func_021DCB48(void *p)
{
    func_020434DC(15, 0);
    func_02043598(7, 0);
    func_020403F4(6);
    func_020403F4(5);
    func_020403F4(4);
    func_020403F4(3);
    func_020403F4(2);
    func_020403F4(1);
    func_020403F4(0);
    func_0203F9B4();
}


void func_021DCB8C(struct Ov170Ctx *ctx)
{
    void *arc;
    void *arc2;
    void *pal;
    PlttData *pd;
    u8 *src;
    u32 ofs;
    u32 r6;
    u16 *a;
    u16 *b;
    u32 i;

    arc = func_020490F4(0x74, 0x4c);
    func_02049658(arc, 0xc, 1, 0, 0, 1, 0x4c);
    func_02049740(arc, 3, 2, 0, 1, 0x4c);
    func_020498F4(arc, 2, 2, 0, 0, 1, 0x4c);
    func_02049658(arc, 1, 3, 0, 0, 1, 0x4c);
    func_020498F4(arc, 0, 3, 0, 0, 1, 0x4c);
    func_02049B68(arc, 4, 0, 0, 0x80, 0x4c);
    func_02049658(arc, 0x3e, 1, 1000, 0x300, 1, 0x4c);
    func_02049B68(arc, 0x3f, 0, 0x180, 0x40, 0x4c);
    pal = func_02049F34(func_020275E4(), 0x1f, (u32)(&pd), 0x804c);
    src = pd->fC;
    ofs = 0x194;
    func_02040E78(0, src + 0x34, 4, ofs);
    src += 0x14;
    ofs += 0x20;
    func_02040E78(0, src, 4, ofs);
    func_020307B0(pal);
    func_02049658(arc, 6, 5, 0, 0, 1, 0x4c);
    func_020498F4(arc, 5, 5, 0, 0, 1, 0x4c);
    func_02049658(arc, 6, 6, 0, 0, 1, 0x4c);
    func_02049B68(arc, 7, 4, 0, 0, 0x4c);
    func_02049238(arc);
    arc2 = func_020490F4(func_020275E4(), 0x4c);
    func_02049740(arc2, func_02027628(), 0, 0, 0, 0x4c);
    func_02049B68(arc2, func_02027624(), 0, 0xe0, 0x20, 0x4c);
    func_020498F4(arc2, func_0202762C(), 0, 0, 0, 0, 0x4c);
    func_020413B0(0, 0, 0x15, 0x20, 3, 7);
    func_02041B6C(0);
    r6 = func_02049740(arc2, func_02027628(), 2, 0, 0, 0x4c);
    func_02049238(arc2);
    a = (u16 *)func_0204162C(0);
    b = (u16 *)func_0204162C(2);
    for (i = 0; i < 0x60u; i++) {
        *(u16 *)((char *)b + 0x540 + i * 2) = r6 + *(u16 *)((char *)a + 0x540 + i * 2);
    }
    func_02041B6C(2);
    *(int *)(ctx->f2c + 0x178) = (int)func_0201F5DC(0, 10, 0, 0x4c);
    func_02049B40(0x17, 5, 0, 0x160, 0x20, 0x4c);
    func_02049B40(0x17, 5, 4, 0x1e0, 0x20, 0x4c);
}


/*
 * Allocate 76 bytes, keep the handle, then configure it.
 */
void func_021DCDB8(char *p)
{
    int v = (int)func_02021518(0x4c);

    ((struct Obj18439 *)(*(char * *)&((struct Obj12146 *)p)->f2C))->f6C = v;
    func_0202155C((struct PalAnmSlot *)(((struct Obj18440 *)(*(char * *)&((struct Obj12146 *)p)->f2C))->f6C), 0, 0x200, 0x4c);
}


void func_021DCDD8(int *p)
{
    func_020215A0((struct PalAnmSlot *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x6c)), 0);
    func_02021540((void *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x6c)));
}

void func_021DCDF0(int a)
{
    if (a == 1)
        func_0207D63C(0x04000050, 0, 0x2a, 6, 0xa);
    else
        *(volatile unsigned short *)0x04000050 = 0;
}

#define PTR(p,n) (*(void **)(*(char **)((p)+0x2c)+(n)))

void func_021DCE14(char *p)
{
    PTR(p,0x80) = func_02045B38(0,2,9,0x4c);
    PTR(p,0x78) = func_0201D7EC(0x17,0,1,0,0x4c);
    PTR(p,0x7c) = func_0201D7EC(0x17,3,0,0,0x4c);
    PTR(p,0x84) = func_0201EC64(0x4c);
    PTR(p,0x8c) = func_0201C450(0x800,0x4c);
    PTR(p,0x88) = func_020457B0(0x400,0x4c);
}

#define WORK(p) (*(char **)((p)+0x2c))

#undef PTR
#define PTR(p,n) (*(void **)(WORK(p)+(n)))

/*
 * trailing: two bytes alignment padding at 0x021DCEBE.
 */
void func_021DCE80(char *p)
{
    func_02045808(PTR(p,0x88));
    func_0201C4C0(PTR(p,0x8c));
    func_0201ED04(PTR(p,0x84));
    func_0201D83C(PTR(p,0x7c));
    func_0201D83C(PTR(p,0x78));
    func_02045C04(PTR(p,0x80));
}

#undef WORK
#define WORK(p) (*(char **)((p)+0x2c))

#undef PTR
#define PTR(p,n) (*(void **)(WORK(p)+(n)))

void func_021DCEC0(char *p)
{
    PTR(p,0x184)=func_02045EC0(PTR(p,0x80),0x6e);
    HALF(p,0x188)=0x39e3;
    PTR(p,0x18c)=0;
    PTR(p,0x190)=func_02045EC0(PTR(p,0x80),0x6f);
    HALF(p,0x194)=0x39e3;
    PTR(p,0x198)=0;
    PTR(p,0x19c)=func_02027F60(0,8,(u32)PTR(p,0x78),(u32)PTR(p,0x8c),0x4c);
}

/*
 * lane O46
 */
void func_021DCF30(char *p)
{
    func_02027FD8((struct TaskMenuState *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x19C)));
    func_02045808((struct U16Vec *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x190)));
    func_02045808((struct U16Vec *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 0x184)));
}

#undef WORK

#define WORK(p) (*(char **)((p) + 0x2C))


void func_021DCF58(unsigned char *p, int sel)
{
    MenuTmpl t;
    t.heapId = 0x4C;
    t.count = 2;
    t.items = WORK(p) + 0x184;
    t.unk0c = 1;
    t.x = 0x20;
    t.y = 0x12;
    t.w = 8;
    t.h = 3;
    if (func_020260F0(*(void **)(WORK(p) + 0x70)) == 1)
        func_020355D8(0);
    else
        func_020355D8(1);
    *(void **)(WORK(p) + 0x1A0) = func_02027778((struct TaskMenuTmpl *)(&t), *(void **)(WORK(p) + 0x19C));
    func_02027CFC(*(void **)(WORK(p) + 0x1A0), sel);
}


int func_021DCFC0(char *p)
{
    Fade *f = (Fade *)(*(char * *)&((struct Obj00000 *)p)->f2C + 0x1A6);
    switch (f->state) {
    case 0:
        if (f->flag == 0) {
            func_021EBFCC(*(char * *)&((struct Obj00000 *)p)->f2C, f->id, f->lo);
        } else {
            func_020413B0(f->id, f->x, f->y, f->w, f->h, f->lo);
            func_02041B6C(f->id);
        }
        f->state++;
        break;
    case 1:
        if (f->flag == 0) {
            if (func_021EBFEC(*(char * *)&((struct Obj00000 *)p)->f2C, f->id) == 0)
                return 0;
        } else {
            f->count++;
            if (f->count == 4) {
                func_020413B0(f->id, f->x, f->y, f->w, f->h, f->hi);
                func_02041B6C(f->id);
                f->count = 0;
                f->state++;
            }
        }
        break;
    case 2:
        f->count++;
        if (f->count == 2)
            return 0;
        break;
    }
    return 1;
}


void func_021DD090(Sys *p, unsigned idx)
{
    unsigned short w;
    unsigned short h;
    signed char pos[2];
    func_0202CF98(*(struct WinMgr * *)&((struct Obj23825 *)((char *)p->work))->f74, idx, &pos[1], &pos[0]);
    func_0202CFC0(*(struct WinMgr * *)&((struct Obj23826 *)((char *)p->work))->f74, idx, &w, &h);
    p->work->flag = 1;
    p->work->id = func_0202CF8C(*(struct WinMgr * *)&((struct Obj23827 *)((char *)p->work))->f74, idx);
    p->work->lo = 0xD;
    p->work->hi = 0xC;
    p->work->state = 0;
    p->work->count = 0;
    p->work->x = pos[1];
    p->work->y = pos[0];
    p->work->w = w;
    p->work->h = h;
}

void func_021DD14C(char *p)
{
    func_021EE038(p, ((struct Obj00000 *)p)->f1F, ((struct Obj00000 *)p)->f20,
                  ((struct Obj00000 *)p)->f21);
    func_021EF660(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
}


void func_021DD16C(unsigned char *p, int dir)
{
    if (dir == 0) {
        p[0x14] = p[0x14] == 0 ? p[0x15] - 1 : p[0x14] - 1;
        func_021EBFA8(*(char * *)&((struct Obj00000 *)p)->f2C, 0, 2);
    } else {
        p[0x14] = p[0x14] == p[0x15] - 1 ? 0 : p[0x14] + 1;
        func_021EBFA8(*(char * *)&((struct Obj00000 *)p)->f2C, 1, 4);
    }
    func_021EC35C((char **)p, p[0x14]);
    func_021DEC98((char *)p, (void *)func_021DEDCC((char *)p, p[0x14]), dir);
}

/*
 * Fold the signed delta into p[0x19] through the wrap helper,
 *   then refresh and re-key the queue.
 */
void func_021DD1C4(char *p, int a)
{
    ((struct Obj00000 *)p)->f19 = func_021DEB14((unsigned char *)p, (signed char)a);
    func_021EDECC((unsigned char *)p, a);
    func_021EE008(p, 0, 0);
}

/*
 * Five-step reset: fold the delta, rebuild the queue object,
 *   re-run the frame update, clear the flag and re-stage channel 9.
 */
void func_021DD1E8(char *p)
{
    func_021ED904((unsigned char *)p);
    func_021ED9B4(*(int *)&((struct Obj00000 *)p)->f2C);
    func_021EDF5C((unsigned char *)p);
    func_021EB85C((unsigned char *)p, 0);
    func_021EF738(*(struct WinMgr **)(*(int *)&((struct Obj00000 *)p)->f2C + 0x74));
}

/*
 * True when the absolute difference of the two unsigned arguments
 * straddles half of the +0x15 counter, in the direction of the order.
 */
int func_021DD210(unsigned char *p, unsigned a, unsigned b)
{
    int d = a - b;
    if (d < 0)
        d = -d;
    if (a > b)
        return d >= ((unsigned)p[0x15] >> 1);
    return d < ((unsigned)p[0x15] >> 1);
}


/*
 * Enable the pooled object when it reports zero.
 */
void func_021DD238(char *p)
{
    func_020355D8(0);
    if (func_020260F0(((struct Obj18441 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70) == 0)
        func_020260F4(((struct Obj18442 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f70, 1);
}


unsigned func_021DD25C(void ***p, unsigned short a, int box, unsigned id, unsigned v)
{
    if (a >= 0x1E) {
        if (a >= 0x1E)
            a -= 0x1E;
        if ((int)func_0201AA18((*p)[2]) > a)
            return func_02017E1C(func_0201AB28((*p)[2], a), id, v);
    } else if (a != 0xFF) {
        void *m = func_02007A18((*p)[1], box, a);
        if (m != 0)
            return func_02017E88(m, id, v);
    }
    return 0;
}

/*
 * Open the range, then feed the handle to the second call.
 */
void func_021DD2B4(int a, int b, int c, int d, int e)
{
    int r = func_021DD2D0((void ***)a, c, b);
    if (r)
        func_02017E64((void *)r, d, e);
}


int func_021DD2D0(void ***p, int a, unsigned b)
{
    if (a == 0xFF || b >= 0x1E) {
        if (b >= 0x1E)
            b -= 0x1E;
        if (func_0201AA18((*p)[2]) > b)
            return func_020185F0(func_0201AB28((*p)[2], b));
    } else if (b != 0xFF) {
        return (int)func_02007A18((*p)[1], a, b);
    }
    return 0;
}


/*
 * Two ranges: below 30 forward all, at or above rebase.
 * The tested field is unsigned: a signed `b` compiles the inverted
 * branch as blo where the image has bhs.
 */
void func_021DD314(char **p, int a, unsigned b)
{
    if (b < 0x1eU)
        func_02007664((void *)(((struct Obj18443 *)(*p))->f4), a, b);
    else
        func_0201A9C8((struct Party *)(((struct Obj18444 *)(*p))->f8), b - 0x1eU);
}

void func_021DD330(unsigned char *p,unsigned short *q,unsigned short *t)
{
    unsigned box;
    unsigned short slot;
    void *m;
    if (q[0] == 0x24) box=p[0x17]; else box=p[0x14];
    m=func_0201747C((struct Mon *)func_021DD2D0((void ***)p,box,q[2]),0x804c);
    slot=t[2]-30;
    func_020075B0((*(void ***)p)[1],box,q[2],func_020185F4(func_0201AB28((*(void ***)p)[2],slot)));
    func_0201AB48((*(void ***)p)[2],slot,m);
    func_020307B0(m);
    func_021EDAB0((char *)p,box);
}

void func_021DD39C(unsigned char *p, unsigned short *q)
{
    void *m;
    m = func_0201747C((struct Mon *)func_021DD2D0((void ***)p,p[0x17],q[2]),0x804c);
    func_0201A98C((*(void ***)p)[2],m);
    func_021DD314((char **)p,p[0x17],q[2]);
    func_020307B0(m);
    func_021EDAB0((char *)p,p[0x17]);
}
