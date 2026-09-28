/*
 * function: func_021C7504
 * address:  0x021C7504
 * packet:   pkt_ov111_021C7504
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020275E4  0x020275E4  thumb
 *   func_02027614  0x02027614  thumb
 *   func_02027618  0x02027618  thumb
 *   func_0202761C  0x0202761C  thumb
 *   func_02027620  0x02027620  thumb
 *   func_020490F4  0x020490F4  arm
 *   func_02049238  0x02049238  arm
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

extern int func_020275E4(void);
extern int func_02027614(void);
extern int func_02027618(void);
extern int func_0202761C(int a);
extern int func_02027620(int a);
extern void *func_020490F4(int id, int heap);
extern void func_02049238(void *arc);
extern void func_0204A48C(const void *a, const void *b, int heap);
extern void *func_0204B100(int n, int a, int heap);
extern void func_020434DC(int a, int b);
extern void func_02043598(int a, int b);
extern void *func_0204A6C8(void *arc, int id, int a, int b, int heap);
extern void *func_0204ABF0(void *arc, int id, int a, int b, int heap);
extern void *func_0204AC18(void *arc, int id, int a, int b, int c, int d, int heap);
extern void *func_0204AF28(void *arc, int id, int id2, int heap);
extern const unsigned char d_020A1448[];
extern const unsigned char d_021C88FC[];

void func_021C7504(Work *p)
{
    void *arc = func_020490F4(func_020275E4(), 0x27);

    func_0204A48C(d_020A1448, d_021C88FC, 0x27);
    p->f48 = func_0204B100(0x24, 1, 0x27);
    func_020434DC(0x10, 1);
    func_02043598(0x10, 1);
    p->fE0 = func_0204A6C8(p->f0, 0x1B, 0, 0, 0x27);
    p->fDC = func_0204ABF0(p->f0, 2, 0, 0, 0x27);
    p->fE4 = func_0204AF28(p->f0, 0x2D, 0x2F, 0x27);
    p->fEC = func_0204A6C8(arc, func_02027618(), 0, 0, 0x27);
    p->fE8 = func_0204AC18(arc, func_02027614(), 0, 0x160, 0, 3, 0x27);
    p->fF0 = func_0204AF28(arc, func_0202761C(0), func_02027620(0), 0x27);
    func_02049238(arc);
}
