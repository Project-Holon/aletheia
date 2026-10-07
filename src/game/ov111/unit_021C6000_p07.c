/*
 * file:     unit_021C6000_p07.c
 * unit:     yes
 * function: func_021C7098, func_021C70EC
 * address:  0x021C7098
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
 *   func_021C795C  0x021C795C  thumb
 *   func_021C78F8  0x021C78F8  thumb
 *   func_021C7808  0x021C7808  thumb
 *   func_021C7730  0x021C7730  thumb
 *   func_021C7658  0x021C7658  thumb
 *   func_021C74D0  0x021C74D0  thumb
 *   func_021C72C8  0x021C72C8  thumb
 *   func_021C71CC  0x021C71CC  thumb
 *   func_021C81C0  0x021C81C0  thumb
 *   func_020315D4  0x020315D4  arm
 *   func_0203084C  0x0203084C  arm
 *   func_020306F0  0x020306F0  arm
 *   func_02040618  0x02040618  arm
 *   func_0204A648  0x0204A648  arm
 *   func_020419E4  0x020419E4  arm
 */
struct S020315D4;
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
} Parent_021C7098;

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
    Parent_021C7098 *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
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
} Work_021C7098;

typedef struct {
    u8 pad0[4];
    void *f4;
} Parent_021C70EC;

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
    u8 pad48[0x58 - 0x48];
    void *f58;
    void *f5C[8];
    void *f7C[24];
    u8 padDC[0xF4 - 0xDC];
    void *fF4;
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    Parent_021C70EC *f108;
    int state;
    int f110;
    u16 f114;
    u16 f116;
    int f118;
    int f11C;
    u8 pad120[0x140 - 0x120];
    int f140;
    int f144;
    u8 pad148[0x14C - 0x148];
    void *f14C[3];
    Res *f158[3];
    void *f164[3];
    u8 pad170[0x17C - 0x170];
    u8 f17C[8];
    void *f184;
    int f188[8];
    u8 f1A8[8];
    u8 f1B0[8];
} Work_021C70EC;

extern void func_021C795C(Work_021C7098 *p);
extern void func_021C78F8(Work_021C7098 *p);
extern void func_021C7808(Work_021C7098 *p);
extern void func_021C7730(Work_021C7098 *p);
extern void func_021C7658(Work_021C7098 *p);
extern void func_021C74D0(Work_021C7098 *p);
extern void func_021C72C8(Work_021C7098 *p);
extern void func_021C71CC(Work_021C7098 *p);
extern void func_021C81C0(Work_021C7098 *p);
extern void func_020315D4(struct S020315D4 *p);
extern void *func_0203084C(u32 heapId);
extern void func_020306F0(u32 heap);
extern void func_02040618(u32 layer, u32 a, u32 b);
extern void func_0204A648(void);
extern void func_020419E4(void);
int func_021C7098(void *proc, void *seq, int c, Work_021C7098 *p);
void func_021C70EC(void *unused, Work_021C70EC *p);


/*
 * Addresses are Black-image addresses.
 */
int func_021C7098(void *proc, void *seq, int c, Work_021C7098 *p)
{
    func_021C795C(p);
    func_021C78F8(p);
    func_021C7808(p);
    func_021C7730(p);
    func_021C7658(p);
    func_021C74D0(p);
    func_021C72C8(p);
    func_021C71CC(p);
    func_021C81C0(p);
    func_020315D4(proc);
    func_0203084C(0x27);
    func_020306F0(0x27);
    return 1;
}


void func_021C70EC(void *unused, Work_021C70EC *p)
{
    int v = -(p->f11C / 2);

    func_02040618(6, 0, v);
    func_02040618(6, 3, v);
    func_02040618(3, 0, v);
    func_02040618(3, 3, v);
    func_0204A648();
    func_020419E4();
}
