/*
 * function: func_021C6FC4
 * address:  0x021C6FC4
 * packet:   pkt_ov111_021C6FC4
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082AC0  0x02082AC0  arm
 *   func_021C7130  0x021C7130  thumb
 *   func_021C7208  0x021C7208  thumb
 *   func_021C7228  0x021C7228  thumb
 *   func_021C72FC  0x021C72FC  thumb
 *   func_021C7504  0x021C7504  thumb
 *   func_021C75E4  0x021C75E4  thumb
 *   func_021C76A4  0x021C76A4  thumb
 *   func_021C7744  0x021C7744  thumb
 *   func_021C78C4  0x021C78C4  thumb
 *   func_021C7934  0x021C7934  thumb
 *   func_021C81A4  0x021C81A4  thumb
 *   func_0203D34C  0x0203D34C  arm
 *   func_0202208C  0x0202208C  thumb
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

extern void func_0203064C(u32 a, u32 heap, u32 size);
extern Work *func_0203159C(void *proc, int size, int heap);
extern void func_02082AC0(int v, void *p, int size);
extern void func_021C7130(Work *p, void *parent);
extern void func_021C7208(void);
extern void func_021C7228(Work *p);
extern void func_021C72FC(Work *p);
extern void func_021C7504(Work *p);
extern void func_021C75E4(Work *p);
extern void func_021C76A4(Work *p);
extern void func_021C7744(Work *p);
extern void func_021C78C4(Work *p);
extern void func_021C7934(Work *p);
extern void func_021C81A4(Work *p, u16 v);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0202208C(void *p1, u32 p2, u32 p3, u32 p4, u32 p5, u32 p6, u32 p7);

int func_021C6FC4(void *proc, int *seq, void *parent)
{
    Work *p;

    func_0203064C(1, 0x27, 0x20000);
    p = func_0203159C(proc, 0x1C8, 0x27);
    func_02082AC0(0, p, 0x1C8);
    func_021C7130(p, parent);
    func_021C7208();
    func_021C7228(p);
    func_021C72FC(p);
    func_021C7504(p);
    func_021C75E4(p);
    func_021C76A4(p);
    func_021C7744(p);
    func_021C78C4(p);
    func_021C7934(p);
    func_021C81A4(p, p->f114);
    func_0203D34C(1, 0x27);
    func_0202208C(0, 1, 1, 0, 6, 1, 0x27);
    return 1;
}
