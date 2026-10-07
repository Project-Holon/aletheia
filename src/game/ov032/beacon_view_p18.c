/*
 * file:     beacon_view_p18.c
 * unit:     yes
 * function: func_021F2A8C, func_021F2BD4, func_021F2C1C, func_021F2CC4, func_021F2D20, func_021F2EDC, func_021F2F44, func_021F2FCC
 * address:  0x021F2A8C
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_02082A7C  0x02082A7C  arm
 *   func_020216B4  0x020216B4  thumb
 *   func_02021640  0x02021640  thumb
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_0207D63C  0x0207D63C  arm
 *   func_02040588  0x02040588  arm
 *   d_021F3608     0x021F3608  data  ov032  a4
 *   d_021F3628     0x021F3628  data  ov032  a4
 *   d_021F3648     0x021F3648  data  ov032  a4
 *   d_021F3668     0x021F3668  data  ov032  a4
 *   func_020403F4 0x020403F4 arm
 *   func_02028590 0x02028590 thumb
 *   func_02027F60 0x02027F60 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   func_02028148 0x02028148 thumb
 *   func_02045808 0x02045808 arm
 *   func_02027FD8 0x02027FD8 thumb
 *   func_02028604 0x02028604 thumb
 *   func_021F30D4  0x021F30D4  thumb  ov032
 *   func_020490F4  0x020490F4  arm
 *   func_02049250  0x02049250  arm
 *   func_02062A98  0x02062A98  arm
 *   func_02062A00  0x02062A00  arm
 *   DC_FlushAll    0x02086284  arm
 *   func_02049238  0x02049238  arm
 *   d_021F35BC     0x021F35BC  data  ov032  a2
 *   d_021F35C8     0x021F35C8  data  ov032  a2
 *   d_021F35D4     0x021F35D4  data  ov032  a2
 *   func_020307B0 0x020307B0 arm
 *   func_021F31A8 0x021F31A8 thumb ov032
 *   d_021F35E0 0x021F35E0 data ov032 a4
 *   func_0204B100 0x0204B100 arm
 *   func_0204B034 0x0204B034 arm
 *   func_0204B258 0x0204B258 arm
 *   func_02025538 0x02025538 thumb
 *   func_021F3264 0x021F3264 thumb ov032
 *   func_021F32F8 0x021F32F8 thumb ov032
 *   func_02043598 0x02043598 arm
 *   func_021F34C8 0x021F34C8 thumb ov032
 *   func_021F32D4 0x021F32D4 thumb ov032
 *   func_02025588 0x02025588 thumb
 *   func_0204B084 0x0204B084 arm
 *   func_0204B1CC 0x0204B1CC arm
 */
#include "../../matched/include/Obj00007.h"
#include "../../matched/include/Obj00812.h"
#include "../../matched/include/Obj20461.h"
#include "../../matched/include/Obj20462.h"

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)
struct BgTemplate;
struct PalAnmSlot;
struct MsgBank;
struct R;
struct TaskMenuState;
struct U16Vec;
struct ArcFile;
struct NitroFileHeader;
struct Bank;
struct Obj;
typedef unsigned char  u8;

typedef unsigned short u16;

typedef unsigned int   u32;

typedef struct {
    u32 count;
    u32 *items;
} ResList;

typedef struct {
    u16 count;
    u16 base;
} ResSpec;

typedef struct {
    ResSpec s[3];
} ResSpec3;

typedef struct {
    void *data;
    void *res;
} Ent;

typedef struct {
    u8 *hdr;
    u32 data;
    void *res;
} Res3;

typedef struct {
    u8 pad0[0x96];
    u16 heap;
    u16 heap2;
    u8 pad9a[0x12];
    u32 fac;
    u8 padb0[0x84];
    ResList l134[3];
    ResList l14c[3];
    ResList l164[3];
    u8 pad17c[0x15c];
    Ent e2[12];
    Ent e1[16];
    Res3 r3b8;
    Res3 r3c4;
} Work;

typedef signed int     s32;

typedef struct { int w[4]; } T16;

extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_02082A7C(u32 fill, void *dst, u32 size);
extern void func_020216B4(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_0207D63C(u32 reg, int plane1, int plane2, int ev1, int ev2);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_020403F4(unsigned);
extern unsigned func_02028590(int, int, int, unsigned);
extern struct R *func_02027F60(u16 a0, u16 a1, u32 a2, u32 a3, u16 heap);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_02028148(u8 *p);
extern void func_02045808(struct U16Vec *vec);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern int func_02028604(int a0);
extern void func_021F30D4(Work *p, ResList *out, const ResSpec *spec, void *arc);
extern void *func_020490F4(u32 id, u32 heap);
extern void *func_02049250(struct ArcFile *arc, u32 member, u32 heap);
extern s32 func_02062A98(struct NitroFileHeader *file, void **out);
extern s32 func_02062A00(struct NitroFileHeader *file, void **out);
extern void DC_FlushAll(void);
extern void func_02049238(void *h);
extern u32 func_020307B0(void *p);
extern void func_021F31A8(char *, char *);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern struct Obj *func_0204B034(u8 *a0, u32 a1, u32 heap);
extern void func_0204B258(struct Bank *bank, void *p);
extern void *func_02025538(unsigned int a0, void *a1);
extern void func_021F3264(char *);
extern void func_021F32F8(char *, unsigned char);
extern void func_02043598(unsigned, unsigned);
extern void func_021F34C8(char *, int);
extern void func_021F32D4(char *);
extern void func_02025588(void *p);
extern void func_0204B084(int);
extern u32 func_0204B1CC(struct Bank *bank);
void func_021F2A8C(u8 *p, void *h);
void func_021F2BD4(char *p);
void func_021F2C1C(char *p);
void func_021F2CC4(char *p);
void func_021F2D20(Work *p, void *h);
void func_021F2EDC(char *p);
void func_021F2F44(char *p, void *a);
void func_021F2FCC(char *p);
extern const u8 d_021F3608[];
extern const u8 d_021F3628[];
extern const u8 d_021F3648[];
extern const u8 d_021F3668[];
extern const ResSpec3 d_021F35BC;
extern const ResSpec3 d_021F35C8;
extern const ResSpec3 d_021F35D4;
extern T16 d_021F35E0;


/*
 * volatile: 0x021F2ACE ldr / 0x021F2AD6 str of 0x04001000 (REG_DB_DISPCNT_SUB read-modify-write); 0x021F2ADC strh to 0x04001050 (hardware registers)
 */
void func_021F2A8C(u8 *p, void *h)
{
    func_0203FCA0(4, (const struct BgTemplate *)d_021F3608, 0);
    func_0203FCA0(5, (const struct BgTemplate *)d_021F3628, 0);
    func_0203FCA0(6, (const struct BgTemplate *)d_021F3648, 0);
    func_0203FCA0(7, (const struct BgTemplate *)d_021F3668, 0);
    func_02082A7C(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    func_020216B4((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), (void *)h, 0x13, ((struct Obj00007 *)p)->f96, 1, 0x1a0, 0);
    func_02021640((struct PalAnmSlot *)(((struct Obj00007 *)p)->fAC), 0x17, 5, ((struct Obj00007 *)p)->f96, 1, 0x20, 0xd0);
    func_02049658((void *)h, 0x14, 7, 0, 0, 1, ((struct Obj00007 *)p)->f96);
    func_020498F4((void *)h, 0x15, 5, 0, 0x800, 1, ((struct Obj00007 *)p)->f96);
    func_020498F4((void *)h, 0x16, 6, 0, 0x800, 1, ((struct Obj00007 *)p)->f96);
    func_020498F4((void *)h, 0x17, 7, 0, 0x800, 1, ((struct Obj00007 *)p)->f96);
    func_0207D63C(0x04001050, 4, 0x1e, 0xd, 3);
    func_02040588(4, 1);
    func_02040588(5, 1);
    func_02040588(6, 1);
    func_02040588(7, 1);
}


void func_021F2BD4(char *p)
{
    unsigned short z = 0;

    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 0);
    func_02040588(7, 0);
    *(volatile unsigned short *)0x04001050 = z;
    func_020403F4(4);
    func_020403F4(5);
    func_020403F4(6);
    func_020403F4(7);
}


void func_021F2C1C(char *p)
{
    int i;
    int z;

    z = 0;
    ((struct Obj00007 *)p)->fBC = func_02028590(9, 0, 1, ((struct Obj00007 *)p)->f98);
    ((struct Obj00007 *)p)->fB8 = (unsigned int)func_02027F60(4, 0xe, ((struct Obj00007 *)p)->fB0, ((struct Obj00007 *)p)->fB4, ((struct Obj00007 *)p)->f98);
    i = 0;
    do {
        *(unsigned *)(p + i * 16 + 0xc4) = (unsigned int)func_02045EC0((struct MsgBank *)(*(unsigned *)&((struct Obj00007 *)p)->f114), i + 0xc);
        *(unsigned short *)(p + i * 16 + 0xc8) = 0x39e3;
        *(int *)(p + i * 16 + 0xcc) = z;
        *(int *)(p + i * 16 + 0xc0) = z;
        i++;
    } while (i < 3);
    z = 0;
    i = 0;
    do {
        *(unsigned *)(p + i * 16 + 0xf4) = (unsigned int)func_02045EC0((struct MsgBank *)(*(unsigned *)&((struct Obj00007 *)p)->f114), i + 0xf);
        *(unsigned short *)(p + i * 16 + 0xf8) = 0x39e3;
        *(int *)(p + i * 16 + 0xfc) = z;
        *(int *)(p + i * 16 + 0xf0) = z;
        i++;
    } while (i < 2);
}


void func_021F2CC4(char *p)
{
    int i;

    for (i = 0; i < 2; i++) {
        if (*(int *)(p + i * 16 + 0xf0) != 0) {
            func_02028148((u8 *)(*(int *)(p + i * 16 + 0xf0)));
        }
        func_02045808((struct U16Vec *)(*(int *)(p + i * 16 + 0xf4)));
    }
    for (i = 0; i < 3; i++) {
        if (*(int *)(p + i * 16 + 0xc0) != 0) {
            func_02028148((u8 *)(*(int *)(p + i * 16 + 0xc0)));
        }
        func_02045808((struct U16Vec *)(*(int *)(p + i * 16 + 0xc4)));
    }
    func_02027FD8((struct TaskMenuState *)(((struct Obj00812 *)p)->fB8));
    func_02028604(((struct Obj00812 *)p)->fBC);
}


/*
 * note:     the work block must be a struct with the two Ent arrays as members:
 *           raw (p + K)[i] offsets fold the base into one register and the
 *           frame comes out 0x10 bytes short.
 */
void func_021F2D20(Work *p, void *h)
{
    void *h2;
    ResSpec3 a;
    ResSpec3 b;
    ResSpec3 c;
    int i;

    h2 = func_020490F4(0x20, p->heap);
    a = d_021F35BC;
    func_021F30D4(p, p->l134, a.s, h);
    b = d_021F35D4;
    func_021F30D4(p, p->l164, b.s, h);
    c = d_021F35C8;
    func_021F30D4(p, p->l14c, c.s, h2);
    func_020216B4((struct PalAnmSlot *)p->fac, h, 0, p->heap, 3, 0x1c0, 0);
    func_02021640((struct PalAnmSlot *)p->fac, 0, 1, p->heap, 3, 0x20, 0xe0);
    p->r3c4.res = func_02049250(h, 4, p->heap2);
    func_02062A98(p->r3c4.res, (void **)(&p->r3c4.hdr));
    p->r3c4.data = ((struct Obj20461 *)(p->r3c4.hdr))->fC;
    p->r3b8.res = func_02049250(h2, 0, p->heap2);
    func_02062A98(p->r3b8.res, (void **)(&p->r3b8.hdr));
    p->r3b8.data = ((struct Obj20462 *)(p->r3b8.hdr))->fC;
    for (i = 0; i < 16; i++) {
        p->e1[i].res = func_02049250(h2, i + 0x31, p->heap2);
        func_02062A00(p->e1[i].res, &p->e1[i].data);
    }
    for (i = 0; i < 12; i++) {
        p->e2[i].res = func_02049250(h, i + 7, p->heap2);
        func_02062A00(p->e2[i].res, &p->e2[i].data);
    }
    DC_FlushAll();
    func_02049238(h2);
}


void func_021F2EDC(char *p)
{
    int i;

    for (i = 0; i < 12; i++) {
        func_020307B0((void *)(*(int *)(p + 0x2dc + i * 8)));
    }
    for (i = 0; i < 16; i++) {
        func_020307B0((void *)(*(int *)(p + 0x33c + i * 8)));
    }
    func_020307B0((void *)(((struct Obj00812 *)p)->f3CC));
    func_020307B0((void *)(((struct Obj00812 *)p)->f3C0));
    func_021F31A8(p, p + 0x14c);
    func_021F31A8(p, p + 0x164);
    func_021F31A8(p, p + 0x134);
}


/*
 * note:     func_0204B258 takes two arguments (twin ov029_func_021F1DE8): the
 *           0x12C result still in r1 at that call is its second argument.
 */
void func_021F2F44(char *p, void *a)
{
    T16 t;
    int i;

    ((struct Obj00007 *)p)->f128 = func_0204B100(0x40, 0, ((struct Obj00007 *)p)->f94);
    t = d_021F35E0;
    ((struct Obj00007 *)p)->f12C = func_0204B034((u8 *)(&t), 1, ((struct Obj00007 *)p)->f98);
    func_0204B258(((struct Obj00007 *)p)->f128, ((struct Obj00007 *)p)->f12C);
    ((struct Obj00007 *)p)->f124 = func_02025538(((struct Obj00007 *)p)->f98, ((struct Obj00007 *)p)->f128);
    func_021F3264(p);
    for (i = 0; i < 5; i++) {
        func_021F32F8(p, i);
    }
    func_02043598(0x10, 1);
}


void func_021F2FCC(char *p)
{
    int i;

    func_02043598(0x10, 0);
    for (i = 0; i < 5; i++) {
        func_021F34C8(p, (unsigned char)i);
    }
    func_021F32D4(p);
    func_02025588((void *)(((struct Obj00812 *)p)->f124));
    func_0204B084(((struct Obj00812 *)p)->f12C);
    func_0204B1CC((struct Bank *)(((struct Obj00812 *)p)->f128));
}
