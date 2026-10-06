/*
 * function: func_021F683C
 * address:  0x021F683C
 * packet:   pkt_ov097_021F683C
 * region:   ov097
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203F8F4  0x0203F8F4  arm
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   d_021F75F8     0x021F75F8  data  ov097  a4
 *   d_021F7688     0x021F7688  data  ov097  a4
 *   d_021F7668     0x021F7668  data  ov097  a4
 *   d_021F76A8     0x021F76A8  data  ov097  a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef signed char s8;
typedef unsigned int u32;
typedef int s32;

typedef struct {
    u32 w[4];
} Disp;

typedef struct {
    u32 w[8];
} Bg;

extern const Disp d_021F75F8;
extern const Bg d_021F7688;
extern const Bg d_021F7668;
extern const Bg d_021F76A8;

extern void func_0203F8F4(u16 heapId);
struct BgTemplate;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(u32 i);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);

void func_021F683C(void)
{
    Disp a;
    Bg b0;
    Bg b1;
    Bg b2;
    func_0203F8F4(0x71);
    a = d_021F75F8;
    func_0203FC28((struct DispConfig *)(&a));
    b0 = d_021F7688;
    func_0203FCA0(0, (const struct BgTemplate *)(&b0), 0);
    func_020414EC(0);
    func_02040B94(0, 0x20, 0, 0x71);
    b1 = d_021F7668;
    func_0203FCA0(1, (const struct BgTemplate *)(&b1), 0);
    b2 = d_021F76A8;
    func_0203FCA0(2, (const struct BgTemplate *)(&b2), 0);
}
