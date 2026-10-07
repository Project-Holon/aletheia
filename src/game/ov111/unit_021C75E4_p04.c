/*
 * file:     unit_021C75E4_p04.c
 * unit:     yes
 * function: func_021C8078, func_021C80B4, func_021C80E8
 * address:  0x021C8078
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
 *   func_02012BF8  0x02012BF8  thumb
 *   func_02012BE0  0x02012BE0  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_020061E4  0x020061E4  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 */
struct Obj;
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
    Parent *f108;
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
} Work_021C8078;

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
} Work_021C80B4;

typedef struct {
    u8 pad0[4];
    void *f4;
    void *f8;
    void *fC;
    u8 f10;
    u8 pad11[3];
    void *f14;
    u8 pad18[0x7C - 0x18];
    void *f7C[12];
    u8 padAC[0xF8 - 0xAC];
    void *fF8;
    u16 fFC;
    u8 padFE[2];
    void *f100;
    void *f104;
    u8 pad108[4];
    int state;
} Work_021C80E8;

extern int func_02012BF8(int a0, int a1);
extern void func_02012BE0(void *p, u32 a, u32 b);
extern void func_0204B878(struct Obj *p, u16 value);
extern void func_020061E4(u32 a);
extern void func_0204B3DC(struct Obj *p, u32 v);
void func_021C8078(Work_021C8078 *p);
void func_021C80B4(Work_021C80B4 *p);
void func_021C80E8(Work_021C80E8 *p, int row, int v);


void func_021C8078(Work_021C8078 *p)
{
    int v = func_02012BF8((int)p->f108->f4, 0x17) ^ 1;

    func_0204B878(p->f58, v + 6);
    func_02012BE0(p->f108->f4, 0x17, v);
    func_020061E4(0x646);
}


/*
 * Addresses are Black-image addresses.
 */
void func_021C80B4(Work_021C80B4 *p)
{
    p->f114 = 0;
    p->f116 = p->f118 / 10;
    if (p->f118 % 10) {
        p->f116++;
    }
}


void func_021C80E8(Work_021C80E8 *p, int row, int v)
{
    int i;

    for (i = 0; i < 3; i++) {
        func_0204B3DC(p->f7C[row * 3 + i], v);
    }
}
