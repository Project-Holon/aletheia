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
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_InitRun  0x02040B94  arm
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
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
struct BgTemplate;
extern void BG_SYS_InitBgLayer(unsigned int bgId, const struct BgTemplate *tmpl, unsigned int type);
typedef unsigned int   u32;
extern void BG_SYS_ClearSlot(u32 i);
typedef unsigned short u16;
typedef unsigned char  u8;
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

void OEKAKI_SetupBgs(void)
{
    B16 t;
    B32 t0;
    B32 t1;
    B32 t2;
    B32 t4;
    B32 t5;

    t = gOekakiDispConfig;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&t));

    t0 = gOekakiBgTemplate0;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&t0), 0);
    BG_SYS_ClearSlot(0);

    t1 = gOekakiBgTemplate1;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&t1), 0);
    BG_SYS_ClearSlot(1);

    t2 = gOekakiBgTemplate2;
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&t2), 0);

    t4 = gOekakiBgTemplate4;
    BG_SYS_InitBgLayer(4, (const struct BgTemplate *)(&t4), 0);
    BG_SYS_ClearSlot(4);

    t5 = gOekakiBgTemplate5;
    BG_SYS_InitBgLayer(5, (const struct BgTemplate *)(&t5), 0);

    BG_SYS_InitRun(0, 0x20, 0, 0x28);
    BG_SYS_InitRun(4, 0x20, 0, 0x28);
    BG_SYS_InitRun(1, 0x20, 0, 0x28);
    BG_SYS_InitRun(5, 0x20, 0, 0x28);
}
