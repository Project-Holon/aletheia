/*
 * function: func_021C7E48
 * address:  0x021C7E48
 * packet:   pkt_ov111_021C7E48
 * region:   ov111
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   TOUCHPANEL_HitTrg  0x02035C08  arm
 *   TOUCHPANEL_HitCont  0x02035BA4  arm
 *   TOUCHPANEL_GetPointCont  0x02035CB8  arm
 *   KEY_GetTrg  0x020362DC  arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   func_021C7F2C  0x021C7F2C  thumb
 *   func_021C7CD0  0x021C7CD0  thumb
 *   func_021C842C  0x021C842C  thumb
 *   d_021C898C  0x021C898C  data
 *   d_021C8808  0x021C8808  data
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

extern int TOUCHPANEL_HitTrg(const void *rects);
extern int TOUCHPANEL_HitCont(const void *rects);
extern u32 TOUCHPANEL_GetPointCont(u32 *outA, u32 *outB);
extern u32 KEY_GetTrg(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern void func_021C7F2C(Work *p, int sel, int flag);
extern void func_021C7CD0(Work *p, int a, int b, int x);
extern void func_021C842C(Work *p, int idx);
extern const unsigned char d_021C898C[];
extern const unsigned char d_021C8808[];

int func_021C7E48(Work *p)
{
    int x = 0;
    int y = 0;
    int flag = 0;
    int ret;
    int b;
    int a;
    int c;

    ret = TOUCHPANEL_HitTrg(d_021C898C);
    a = TOUCHPANEL_HitCont(d_021C898C);
    b = TOUCHPANEL_HitTrg(d_021C8808);
    c = TOUCHPANEL_HitCont(d_021C8808);
    TOUCHPANEL_GetPointCont((u32 *)(&x), (u32 *)(&y));
    if (KEY_GetTrg() & 2) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        flag = 1;
        ret = 0x13;
    } else if (KEY_GetTrg() & 0x400) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        ret = 0x12;
    } else if (KEY_GetTrg() & 0x800) {
        ret = 0x11;
    } else if (KEY_GetTrg() & 1) {
        ret = 0x10;
    }
    func_021C7F2C(p, ret, flag);
    func_021C7CD0(p, b, c + 1, x);
    func_021C842C(p, a);
    return ret;
}
