/*
 * function: func_021C7228
 * address:  0x021C7228
 * packet:   pkt_ov111_021C7228
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
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
 *
 * Addresses are Black-image addresses.
 */

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
} Work;

typedef struct { u32 w[4]; } BankCfg;
typedef struct { u32 w[8]; } BgTemplate;
typedef struct { BgTemplate t[6]; } BgTemplates;

extern void func_0203F8F4(u16 heapId);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u8 frame, const BgTemplate *t, int mode);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 frame, int size, int ofs, int heap);
extern void func_02040588(u8 frame, int on);
extern void func_0207D63C(volatile void *reg, int plane1, int plane2, int ev1, int ev2);
extern const BankCfg d_021C895C;
extern const BgTemplates d_021C89E0;
extern const u32 d_021C885C[];

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
