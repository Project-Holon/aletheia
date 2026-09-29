/*
 * function: func_02189810
 * address:  0x02189810
 * packet:   pkt_ov021_02189810
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0219047C    0x0219047C  thumb  ov021
 *   func_0218CC64    0x0218CC64  thumb  ov021
 *   func_021C7FB4    0x021C7FB4  thumb  ov021
 *   _ll_mul          0x0209C054  arm
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   func_0206A854    0x0206A854  arm
 *   func_0206DB80    0x0206DB80  arm
 *   func_021ABE0C    0x021ABE0C  thumb  ov021
 *   func_021C64E0    0x021C64E0  thumb  ov021
 *   func_02050790    0x02050790  arm
 *   func_0217F928    0x0217F928  thumb  ov019
 *   func_021BB954    0x021BB954  thumb  ov021
 *   func_021A1B38    0x021A1B38  thumb  ov021
 *   func_021BE4F8    0x021BE4F8  thumb  ov021
 *   func_021C1AEC    0x021C1AEC  thumb  ov021
 *   func_021C1C4C    0x021C1C4C  thumb  ov021
 *   g_02148B54       0x02148B54  data
 *   g_02148BCC       0x02148BCC  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;
typedef int fx32;
typedef long long fx64;

typedef struct { fx32 m[4][4]; } MtxFx44;

extern MtxFx44 g_02148B54;
typedef struct {
    u8 pad[0x7C];
    u32 flag;
} Glb;

extern Glb g_02148BCC;

extern void func_0219047C(u32 a);
extern void func_0218CC64(u32 a, u32 b, int c);
extern void func_021C7FB4(u32 a);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 size);
extern void func_0206A854(void);
extern void func_0206DB80(void);
extern void func_021ABE0C(u32 a);
extern void func_021C64E0(u32 a);
extern void func_02050790(u32 a, u32 b, u32 c);
extern void func_0217F928(u32 a);
extern void func_021BB954(u32 a);
extern void func_021A1B38(u32 a);
extern void func_021BE4F8(u32 a);
extern void func_021C1AEC(void);
extern void func_021C1C4C(u32 a);

#define FX_MUL(a, b) ((fx32)(((fx64)(a) * (b) + 0x800) >> 12))

void func_02189810(u8 *p)
{
    MtxFx44 saved;
    MtxFx44 m;

    if (*(u32 *)(p + 0x28) != 0)
        func_0219047C(*(u32 *)(p + 0x28));
    func_0218CC64(*(u32 *)(p + 0x48), *(u32 *)(p + 0xA4), 1);
    func_021C7FB4(*(u32 *)(p + 0xA0));
    saved = g_02148B54;

    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], *(fx32 *)(p + 0x104));
    MIi_CpuCopyFast(&m, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();
    func_0206DB80();
    func_021ABE0C(*(u32 *)(p + 0x94));
    func_021C64E0(*(u32 *)(p + 0x130));
    func_02050790(*(u32 *)(p + 0xB0), *(u32 *)(p + 0xA4), *(u32 *)(p + 0xA8));
    func_02050790(*(u32 *)(p + 0xB8), *(u32 *)(p + 0xA4), *(u32 *)(p + 0xA8));
    if (*(u32 *)(p + 0x98) != 0)
        func_0217F928(*(u32 *)(p + 0x98));

    m = saved;
    m.m[3][2] += FX_MUL(m.m[2][2], *(fx32 *)(p + 0x104) / 2);
    MIi_CpuCopyFast(&m, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();
    func_0206DB80();
    func_02050790(*(u32 *)(p + 0xB4), *(u32 *)(p + 0xA4), *(u32 *)(p + 0xA8));

    MIi_CpuCopyFast(&saved, &g_02148B54, 0x40);
    g_02148BCC.flag &= ~0x50;
    func_0206A854();

    func_021BB954(*(u32 *)(p + 0xBC));
    func_021A1B38(*(u32 *)(p + 0x20));
    func_021BE4F8(*(u32 *)(p + 0x34));
    func_021C1AEC();
    func_021C1C4C(*(u32 *)(p + 0x124));
}
