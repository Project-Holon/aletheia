/*
 * function: VS_MULTI_LIST_InitBgs
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
 *   BG_SYS_Create  0x0203F8F4  arm
 *   BG_SYS_SetGraphicsMode  0x0203FC28  arm
 *   BG_SYS_InitBgLayer  0x0203FCA0  arm
 *   BG_SYS_ClearSlot  0x020414EC  arm
 *   BG_SYS_InitRun  0x02040B94  arm
 *   gVsMultiListDispConfig     0x021F75F8  data  ov097  a4
 *   gVsMultiListBg0Template     0x021F7688  data  ov097  a4
 *   gVsMultiListBg1Template     0x021F7668  data  ov097  a4
 *   gVsMultiListBg2Template     0x021F76A8  data  ov097  a4
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

extern const Disp gVsMultiListDispConfig;
extern const Bg gVsMultiListBg0Template;
extern const Bg gVsMultiListBg1Template;
extern const Bg gVsMultiListBg2Template;

extern void BG_SYS_Create(u16 heapId);
struct BgTemplate;
struct DispConfig;
extern void BG_SYS_SetGraphicsMode(struct DispConfig *cfg);
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(u32 i);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u32 heapId);

void VS_MULTI_LIST_InitBgs(void)
{
    Disp a;
    Bg b0;
    Bg b1;
    Bg b2;
    BG_SYS_Create(0x71);
    a = gVsMultiListDispConfig;
    BG_SYS_SetGraphicsMode((struct DispConfig *)(&a));
    b0 = gVsMultiListBg0Template;
    BG_SYS_InitBgLayer(0, (const struct BgTemplate *)(&b0), 0);
    BG_SYS_ClearSlot(0);
    BG_SYS_InitRun(0, 0x20, 0, 0x71);
    b1 = gVsMultiListBg1Template;
    BG_SYS_InitBgLayer(1, (const struct BgTemplate *)(&b1), 0);
    b2 = gVsMultiListBg2Template;
    BG_SYS_InitBgLayer(2, (const struct BgTemplate *)(&b2), 0);
}
