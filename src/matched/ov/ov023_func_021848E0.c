/*
 * function: OEKAKI_SetupBgs
 * address:  0x021848E0
 * packet:   pkt_ov023_021848E0
 * region:   ov023
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203FC28  0x0203FC28  arm
 *   func_0203FCA0  0x0203FCA0  arm
 *   func_020414EC  0x020414EC  arm
 *   func_02040B94  0x02040B94  arm
 *   gOekakiDispConfig     0x02186B3C  data  ov023  a4
 *   gOekakiBgTemplate0     0x02186BCC  data  ov023  a4
 *   gOekakiBgTemplate1     0x02186B6C  data  ov023  a4
 *   gOekakiBgTemplate2     0x02186B8C  data  ov023  a4
 *   gOekakiBgTemplate4     0x02186BAC  data  ov023  a4
 *   gOekakiBgTemplate5     0x02186B4C  data  ov023  a4
 */

typedef struct { int w[4]; } B16;
typedef struct { int w[8]; } B32;

extern const B16 gOekakiDispConfig;
extern const B32 gOekakiBgTemplate0;
extern const B32 gOekakiBgTemplate1;
extern const B32 gOekakiBgTemplate2;
extern const B32 gOekakiBgTemplate4;
extern const B32 gOekakiBgTemplate5;
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
struct BgTemplate;
extern void func_0203FCA0(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
typedef unsigned int   u32;
extern void func_020414EC(u32 i);
typedef unsigned short u16;
typedef unsigned char  u8;
extern void func_02040B94(u8 layer, u32 size, u32 offset, u32 heapId);

void OEKAKI_SetupBgs(void)
{
    B16 t;
    B32 t0;
    B32 t1;
    B32 t2;
    B32 t4;
    B32 t5;

    t = gOekakiDispConfig;
    func_0203FC28((struct DispConfig *)(&t));

    t0 = gOekakiBgTemplate0;
    func_0203FCA0(0, (const struct BgTemplate *)(&t0), 0);
    func_020414EC(0);

    t1 = gOekakiBgTemplate1;
    func_0203FCA0(1, (const struct BgTemplate *)(&t1), 0);
    func_020414EC(1);

    t2 = gOekakiBgTemplate2;
    func_0203FCA0(2, (const struct BgTemplate *)(&t2), 0);

    t4 = gOekakiBgTemplate4;
    func_0203FCA0(4, (const struct BgTemplate *)(&t4), 0);
    func_020414EC(4);

    t5 = gOekakiBgTemplate5;
    func_0203FCA0(5, (const struct BgTemplate *)(&t5), 0);

    func_02040B94(0, 0x20, 0, 0x28);
    func_02040B94(4, 0x20, 0, 0x28);
    func_02040B94(1, 0x20, 0, 0x28);
    func_02040B94(5, 0x20, 0, 0x28);
}
