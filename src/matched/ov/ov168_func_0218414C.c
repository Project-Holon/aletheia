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
 *   func_0203F8F4 0x0203F8F4 arm
 *   func_02045088 0x02045088 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040B94 0x02040B94 arm
 *   func_02040588 0x02040588 arm
 *   d_02184878 0x02184878 data a4
 *   d_02184964 0x02184964 data a1
 */
#include "../include/Obj23821.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0203F8F4(u16);
extern void func_02045088(u16);
struct DispConfig;
extern void func_0203FC28(struct DispConfig *cfg);
typedef unsigned int   u32;
struct GfFont;
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
struct BgTemplate;
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
extern void func_020414EC(unsigned);
extern void func_02040B94(u8 layer, u32 size, u32 offset, u16 heapId);
extern void func_02040588(unsigned, unsigned);
extern int d_02184878[];
extern u8 d_02184964[];
void func_0218414C(char *p, int heap)
{
    unsigned i;
    unsigned bg;
    func_0203F8F4(heap);
    func_02045088(heap);
    func_0203FC28((struct DispConfig *)d_02184878);
    ((struct Obj23821 *)p)->f10 = func_0201D7EC(23, 0, 0, 0, (u16)heap);
    for (i = 0; i < 5; i++) {
        bg = d_02184964[i * 0x24 + 0x20];
        func_0203FCA0(bg, (const struct BgTemplate *)(d_02184964 + i * 0x24), d_02184964[i * 0x24 + 0x21]);
        func_020414EC(bg);
        func_02040B94(bg, 32, 0, (u16)heap);
        func_02040588(bg, 1);
    }
}
