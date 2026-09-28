/*
 * function: func_021C7F2C
 * address:  0x021C7F2C
 * packet:   pkt_ov111_021C7F2C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *   func_021C7B20  0x021C7B20  thumb
 *   func_021C7908  0x021C7908  thumb
 *   func_021C7EF8  0x021C7EF8  thumb
 *   func_021C8078  0x021C8078  thumb
 *   func_0204B878  0x0204B878  arm
 *   func_020355D8  0x020355D8  arm
 *   d_021C88B4  0x021C88B4  data
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

extern void func_020061E4(int se);
extern void func_021C7B20(Work *p, int mode, int idx);
extern void func_021C7908(Work *p);
extern int func_021C7EF8(int v);
extern void func_021C8078(Work *p);
extern void func_0204B878(void *o, int anm);
extern void func_020355D8(int v);
extern const int d_021C88B4[8];

void func_021C7F2C(Work *p, int sel, int flag)
{
    int idx;

    if (sel == -1) {
        return;
    }
    switch (sel) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        if (p->f17C[sel] == 0) {
            return;
        }
        func_020061E4(0x65F);
        func_021C7B20(p, 0, sel);
        func_021C7908(p);
        p->f144 = 0;
        p->f148 = d_021C88B4[sel];
        p->f140 = 40000;
        return;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
        if (p->f140 != 0) {
            return;
        }
        idx = func_021C7EF8(p->f13C);
        func_020061E4(0x65E);
        func_021C7B20(p, 1, (sel - 8 + idx) % 8);
        func_021C7908(p);
        return;
    case 16:
        p->state = 2;
        p->f110 = sel;
        func_020061E4(0x54C);
        func_0204B878(p->f4C, 0xC);
        return;
    case 17:
        func_021C8078(p);
        return;
    case 18:
        func_020061E4(0x556);
        p->state = 2;
        p->f110 = sel;
        func_0204B878(p->f54, 8);
        return;
    case 19:
        func_020061E4(0x551);
        p->state = 2;
        p->f110 = sel;
        func_0204B878(p->f50, 9);
        if (flag) {
            func_020355D8(0);
        } else {
            func_020355D8(1);
        }
        return;
    }
}
