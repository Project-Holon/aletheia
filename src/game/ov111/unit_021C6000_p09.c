/*
 * file:     unit_021C6000_p09.c
 * unit:     yes
 * function: func_021C7228, func_021C72C8, func_021C72FC, func_021C74D0, func_021C7504
 * address:  0x021C7228
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   func_02040588  0x02040588  arm
 *   func_0207D63C  0x0207D63C  arm
 *   d_021C895C  0x021C895C  data
 *   d_021C89E0  0x021C89E0  data
 *   d_021C885C  0x021C885C  data
 *   func_020403F4  0x020403F4  arm
 *   func_0203F9B4  0x0203F9B4  arm
 *   func_020275E4  0x020275E4  thumb
 *   func_02027624  0x02027624  thumb
 *   func_02027628  0x02027628  thumb
 *   func_0202762C  0x0202762C  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
 *   func_02049658  0x02049658  arm
 *   func_020498F4  0x020498F4  arm
 *   func_02049B68  0x02049B68  arm
 *   func_02049BDC  0x02049BDC  arm
 *   func_02049B40  0x02049B40  arm
 *   func_020413B0  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_0201F57C  0x0201F57C  thumb
 *   func_0201F554  0x0201F554  thumb
 *   func_02049F78  0x02049F78  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_0204A48C  0x0204A48C  arm
 *   func_0204B100  0x0204B100  arm
 *   func_020434DC  0x020434DC  arm
 *   func_02043598  0x02043598  arm
 *   func_0204A6C8  0x0204A6C8  arm
 *   func_0204ABF0  0x0204ABF0  arm
 *   func_0204AC18  0x0204AC18  arm
 *   func_0204AF28  0x0204AF28  arm
 *   d_020A1448  0x020A1448  data
 *   d_021C88FC  0x021C88FC  data
 */
struct DispConfig;
struct Bank;
struct Cfg;
typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef long long s64;

typedef unsigned long long u64;

typedef struct {
    u8 pad0[0xC];
    void *fC;
} Res;

typedef struct {
    u8 pad0[4];
    void *f4;
    u8 pad8[4];
    int fC;
    int f10;
} Parent;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7228;

typedef struct { u32 w[4]; } BankCfg;

typedef struct { u32 w[8]; } BgTemplate;

typedef struct { BgTemplate t[6]; } BgTemplates;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[4][3];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work_021C72C8;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[2];
    u16 f122;
    u8 pad124[4];
    int f128;
    int f12C;
    int f130;
    u8 pad134[4];
    int f138;
    int f13C;
    int f140;
    int f144;
    int f148;
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C72FC;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x58 - 0x18];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF8 - 0xDC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    void *f108;
    int state;
    u8 pad110[4];
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    u8 pad144[0x14C - 0x144];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
} Work_021C74D0;

typedef struct {
    void *f0;
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x20 - 0x18];
    void *f20;
    void *f24;
    void *f28;
    void *f2C[7];
    void *f48;
    void *f4C;
    void *f50;
    void *f54;
    void *f58;
    void *f5C[8];
    void *f7C[24];
    void *fDC;
    void *fE0;
    void *fE4;
    void *fE8;
    void *fEC;
    void *fF0;
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x13C - 0x120];
    int f13C;
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    Res *f170[3];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C7504;

typedef signed int     s32;

extern void func_0203F8F4(u16 heapId);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u8 frame, const BgTemplate *t, int mode);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern void func_0207D63C(volatile void *reg, int plane1, int plane2, int ev1, int ev2);
extern void func_020403F4(u32 i);
extern void func_0203F9B4(void);
extern u32 func_020275E4(void);
extern u32 func_02027624(void);
extern u32 func_02027628(void);
extern u32 func_0202762C(void);
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049238(void *arc);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *arc, u32 id, u32 frame, u32 a, u32 b, u32 c, u16 heap);
extern void func_02049B68(void *arc, u32 id, u32 a, u32 b, u32 c, u16 heap);
extern void func_02049BDC(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern void func_0201F57C(u32 a, u32 b, u32 c, u32 d);
extern void func_0201F554(u32 a, u32 b, u32 c, u32 d);
extern void *func_02049F78(void *a0, u32 a1, u32 a2, u32 a3);
extern u32 func_020307B0(void *p);
extern u32 func_02027614(void);
extern u32 func_02027618(void);
extern u32 func_0202761C(u32 a);
extern u32 func_02027620(u32 a);
extern void func_0204A48C(const struct Cfg *cfg, u32 arg, u32 heapId);
extern struct Bank *func_0204B100(int count, u8 flag, u32 heapId);
extern void func_020434DC(u32 mask, u32 enable);
extern void func_02043598(u32 mask, u32 enable);
extern s32 func_0204A6C8(void *a, u32 b, u32 c, u32 a3, u16 flags);
extern s32 func_0204ABF0(void *a, u32 b, u32 c, u32 d, u16 g);
extern s32 func_0204AC18(void *a, u32 b, u32 c, u32 d, u16 e, u16 f, u16 g);
extern s32 func_0204AF28(void *owner, u32 first, u32 second, u32 mode);
void func_021C7228(void);
void func_021C72C8(void);
void func_021C72FC(Work_021C72FC *p);
void func_021C74D0(Work_021C74D0 *p);
void func_021C7504(Work_021C7504 *p);
extern const BankCfg d_021C895C;
extern const BgTemplates d_021C89E0;
extern const u32 d_021C885C[];
extern const unsigned char d_020A1448[];
extern const unsigned char d_021C88FC[];


/*
 * Addresses are Black-image addresses.
 */
void func_021C7228(void)
{
    BankCfg bank;
    BgTemplates tmpl;
    u32 i;

    func_0203F8F4(0x27);
    bank = d_021C895C;
    func_0203FC28((struct DispConfig *)(&bank));
    tmpl = d_021C89E0;
    for (i = 0; i < 6; i++) {
        u32 v = d_021C885C[i];
        func_0203FCA0(v, &tmpl.t[i], 0);
        func_020414EC((u8)v);
        func_02040B94(v, 0x20, 0, 0x27);
        func_02040588(v, 1);
    }
    func_02040588(7, 0);
    *(volatile u16 *)0x04000050 = 0;
    func_0207D63C((volatile void *)0x04001050, 2, 4, 7, 0x10);
}


void func_021C72C8(void)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        func_020403F4((u8)d_021C885C[i]);
    }
    func_0203F9B4();
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
}


/*
 * lever:    enum-typed zero in the eighth call preserves copied argument registers and the preceding late heap store.
 *
 * Addresses are Black-image addresses.
 */
void func_021C72FC(Work_021C72FC *p)
{
    typedef enum { Zero } ZeroArg;
    ZeroArg z = Zero;
    void *arc = p->f0;
    void *arc2;
    int i;

    func_02049658(arc, 0x19, 6, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x22, 6, 0, 0, 0, 0x27);
    func_02049B68(arc, 1, 4, 0, 0, 0x27);
    func_02049658(arc, 0x1A, 5, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x23, 5, 0, 0, 0, 0x27);
    func_02049658(arc, 0x19, 3, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x22, 3, 0, 0, 0, 0x27);
    func_02049B68(arc, z, z, z, z, 0x27);
    func_02049658(arc, 0x19, 1, 0, 0, 0, 0x27);
    func_020498F4(arc, 0x21, 1, 0, 0, 0, 0x27);
    arc2 = func_020490F4(func_020275E4(), 0x27);
    func_02049658(arc2, func_02027628(), 2, 0, 0, 0, 0x27);
    func_020498F4(arc2, func_0202762C(), 2, 0, 0, 0, 0x27);
    func_02049BDC(arc2, func_02027624(), 0, 0, 0x1C0, 0x20, 0x27);
    func_020413B0(2, 0, 0x15, 0x20, 3, 0xE);
    func_020409B4(2);
    func_02049238(arc2);
    func_02049B40(0x17, 5, 0, 0x1E0, 0x20, 0x27);
    func_02049B40(0x17, 5, 4, 0x1E0, 0x20, 0x27);
    func_0201F57C(4, 0xE, 0, 0x27);
    func_0201F554(4, 1, 0, 0x27);
    for (i = 0; i < 3; i++) {
        p->f14C[i] = func_02049F78(arc, 4 - i, (u32)(&p->f158[i]), 0x27);
    }
    for (i = 0; i < 3; i++) {
        p->f164[i] = func_02049F78(arc, 0x17 - i, (u32)(&p->f170[i]), 0x27);
    }
}


void func_021C74D0(Work_021C74D0 *p)
{
    int i;

    for (i = 0; i < 3; i++) {
        func_020307B0(p->f164[i]);
    }
    for (i = 0; i < 3; i++) {
        func_020307B0(p->f14C[i]);
    }
}


void func_021C7504(Work_021C7504 *p)
{
    void *arc = func_020490F4(func_020275E4(), 0x27);

    func_0204A48C((const struct Cfg *)d_020A1448, (u32)d_021C88FC, 0x27);
    p->f48 = func_0204B100(0x24, 1, 0x27);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    p->fE0 = (void *)func_0204A6C8(p->f0, 0x1B, 0, 0, 0x27);
    p->fDC = (void *)func_0204ABF0(p->f0, 2, 0, 0, 0x27);
    p->fE4 = (void *)func_0204AF28(p->f0, 0x2D, 0x2F, 0x27);
    p->fEC = (void *)func_0204A6C8(arc, func_02027618(), 0, 0, 0x27);
    p->fE8 = (void *)func_0204AC18(arc, func_02027614(), 0, 0x160, 0, 3, 0x27);
    p->fF0 = (void *)func_0204AF28(arc, func_0202761C(0), func_02027620(0), 0x27);
    func_02049238(arc);
}
