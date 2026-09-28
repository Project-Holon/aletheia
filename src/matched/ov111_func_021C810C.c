/*
 * function: func_021C810C
 * address:  0x021C810C
 * packet:   pkt_ov111_021C810C
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012F08  0x02012F08  thumb
 *   func_0200C234  0x0200C234  thumb
 *   func_0204B3DC  0x0204B3DC  arm
 *   func_021C80E8  0x021C80E8  thumb
 *   func_02012BF8  0x02012BF8  thumb
 *   func_0204B878  0x0204B878  arm
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

extern void *func_02012F08(void *p);
extern int func_0200C234(void *obj, int i);
extern void func_0204B3DC(void *o, int v);
extern void func_021C80E8(Work *p, int row, int v);
extern int func_02012BF8(void *p, int id);
extern void func_0204B878(void *o, u16 v);

void func_021C810C(Work *p, int a, int b)
{
    void *obj;
    int i;

    obj = func_02012F08(p->f108->f4);
    for (i = 0; i < 8; i++) {
        if (func_0200C234(obj, i)) {
            func_0204B3DC(p->f5C[i], 1);
            func_021C80E8(p, i, 1);
            p->f17C[i] = 1;
        } else {
            func_0204B3DC(p->f5C[i], 0);
            func_021C80E8(p, i, 0);
            p->f17C[i] = 0;
        }
    }
    func_0204B878(p->f58, func_02012BF8(p->f108->f4, 0x17) + 6);
}
