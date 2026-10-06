/*
 * function: func_0217D720
 * address:  0x0217D720
 * packet:   pkt_ov018_0217D720
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_0203FCA0            0x0203FCA0  arm
 *   MIi_CpuClear32           0x02082A7C  arm
 *   G2x_SetBlendBrightness_  0x0207D658  arm
 *   func_02049658            0x02049658  arm
 *   func_020498F4            0x020498F4  arm
 *   func_02049EF4            0x02049EF4  arm
 *   MIi_CpuCopy16            0x02082A60  arm
 *   func_020307B0            0x020307B0  arm
 *   func_02049B68            0x02049B68  arm
 *   func_02049B40            0x02049B40  arm
 *   func_02040588            0x02040588  arm
 *   func_0217EF70            0x0217EF70  thumb  ov018
 *   func_0217F1E8            0x0217F1E8  thumb  ov018
 *   func_0217F240            0x0217F240  thumb  ov018
 *   d_0218370C               0x0218370C  data  a4
 *   d_0218372C               0x0218372C  data  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct BgTemplate {
    u32 unk_00;
    u32 unk_04;
    u32 bufSize;
    u32 unk_0c;
    u8  unk_10;
    u8  unk_11;
    u8  unk_12;
    u8  unk_13;
    u32 unk_14;
    u8  unk_18;
    u8  unk_19;
    u8  unk_1a;
    u8  unk_1b;
    u32 unk_1c;
};

extern const struct BgTemplate d_0218370C;
extern const struct BgTemplate d_0218372C;

void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
void MIi_CpuClear32(u32 data, void *dest, u32 size);
void G2x_SetBlendBrightness_(volatile u16 *reg, int plane, int brightness);
u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
void *func_02049EF4(void *p, u32 a, u32 b, void **out, u16 d);
void MIi_CpuCopy16(const void *src, void *dest, u32 size);
void func_020307B0(void *p);
void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02049B40(u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_02040588(u32 which, u32 enable);
void func_0217EF70(int *p, int x);
int func_0217F1E8(u8 *w);
void func_0217F240(u8 *w, int x);

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_DB_BLDCNT_SUB  (*(volatile u16 *)0x04001050)

void func_0217D720(u8 *w, void *bg)
{
    int layer;
    u8 *pal;
    void *res;

    layer = 6;
    func_0203FCA0(6, &d_0218370C, 0);
    func_0203FCA0(7, &d_0218372C, 0);
    MIi_CpuClear32(0, (void *)0x06200000, 0x20000);
    REG_DB_DISPCNT_SUB &= 0xFFFF1FFF;
    REG_DB_BLDCNT_SUB = 0;
    G2x_SetBlendBrightness_(&REG_DB_BLDCNT_SUB, 0x3F, -8);
    func_02049658(bg, 4, 7, 0, 0, 1, 0x15);
    func_020498F4(bg, 5, 7, 0, 0x800, 1, 0x15);
    if (w[0xDA] <= 1) {
        w[0x11F] = 0;
    } else {
        layer = 7;
        w[0x11F] = 1;
    }
    func_020498F4(bg, layer, 6, 0, 0x800, 1, 0x15);
    func_0217EF70((int *)w, w[0xD8]);
    res = func_02049EF4(bg, 8, 1, (void **)&pal, 0x15);
    MIi_CpuCopy16(pal + 0xC, w + 0x138, 0x30);
    func_020307B0(res);
    if (func_0217F1E8(w) == 1) {
        func_0217F240(w, 0);
    }
    func_02049B68(bg, 9, 4, 0, 0x140, 0x15);
    func_02049B40(0x17, 5, 4, 0x1C0, 0x20, 0x15);
    func_02040588(4, 0);
    func_02040588(5, 0);
    func_02040588(6, 1);
    func_02040588(7, 1);
}
