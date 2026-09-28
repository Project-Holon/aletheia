/*
 * function: func_021C72FC
 * address:  0x021C72FC
 * packet:   pkt_ov111_021C72FC
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   DIFF
 * blocker:  one stack-argument store (heap 0x27 at sp+8) of the seventh call is scheduled first instead of last; 3 instructions, see docs/notes/pkt_ov111_021C72FC.c.txt
 *
 * symbols:
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
} Work;

extern int func_020275E4(void);
extern int func_02027624(void);
extern int func_02027628(void);
extern int func_0202762C(void);
extern void *func_020490F4(int id, int heap);
extern void func_02049238(void *arc);
extern void func_02049658(void *arc, int id, int frame, int a, int b, int c, int heap);
extern void func_020498F4(void *arc, int id, int frame, int a, int b, int c, int heap);
extern void func_02049B68(void *arc, int id, int a, int b, int c, int heap);
extern void func_02049BDC(void *arc, int id, int a, int b, int c, int d, int heap);
extern void func_02049B40(int a, int b, int c, int d, int e, int heap);
extern void func_020413B0(int a, int b, int c, int d, int e, int f);
extern void func_020409B4(int a);
extern void func_0201F57C(int a, int b, int c, int heap);
extern void func_0201F554(int a, int b, int c, int heap);
extern void *func_02049F78(void *arc, int id, Res **out, int heap);

void func_021C72FC(Work *p)
{
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
    func_02049B68(arc, 0, 0, 0, 0, 0x27);
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
        p->f14C[i] = func_02049F78(arc, 4 - i, &p->f158[i], 0x27);
    }
    for (i = 0; i < 3; i++) {
        p->f164[i] = func_02049F78(arc, 0x17 - i, &p->f170[i], 0x27);
    }
}
