/*
 * function: func_0218414C
 * address: 0x0218414C
 * packet: pkt_ov168_0218414C
 * region: ov168
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BG_SYS_Create 0x0203F8F4 arm
 *   BMP_WIN_Init 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   GF_FONT_Create 0x0201D7EC thumb
 *   BG_SYS_InitBgLayer 0x0203FCA0 arm
 *   BG_SYS_ClearSlot 0x020414EC arm
 *   BG_SYS_InitRun 0x02040B94 arm
 *   func_02040588 0x02040588 arm
 *   d_02184878 0x02184878 data a4
 *   d_02184964 0x02184964 data a1
 */
#include "../include/Obj23821.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void BG_SYS_Create(u16);
extern void BMP_WIN_Init(u16);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
typedef unsigned int   u32;
struct GfFont;
extern struct GfFont *GF_FONT_Create(int a0, int a1, int a2, int a3, u32 heapId);
struct BgTemplate;
extern void BG_SYS_InitBgLayer(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void BG_SYS_ClearSlot(unsigned);
extern void BG_SYS_InitRun(u8 layer, u32 size, u32 offset, u16 heapId);
extern void func_02040588(unsigned char which, unsigned char enable);
extern int d_02184878[];
extern u8 d_02184964[];
void func_0218414C(char *p, int heap)
{
    unsigned i;
    unsigned bg;
    BG_SYS_Create(heap);
    BMP_WIN_Init(heap);
    func_0203FC28((struct DispConfig *)d_02184878);
    ((struct Obj23821 *)p)->f10 = GF_FONT_Create(23, 0, 0, 0, (u16)heap);
    for (i = 0; i < 5; i++) {
        bg = d_02184964[i * 0x24 + 0x20];
        BG_SYS_InitBgLayer(bg, (const struct BgTemplate *)(d_02184964 + i * 0x24), d_02184964[i * 0x24 + 0x21]);
        BG_SYS_ClearSlot(bg);
        BG_SYS_InitRun(bg, 32, 0, (u16)heap);
        func_02040588(bg, 1);
    }
}
