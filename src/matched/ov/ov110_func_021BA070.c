/*
 * function: func_021BA070
 * address: 0x021BA070
 * packet: pkt_ov110_021BA070
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: GX_SetDispSelect's enum inline keeps the 0xFFFF7FFF pool mask;
 *   a direct halfword &= expression emits 0x00007FFF (two bytes differ).
 * abi: original A0E0..A0EC truncates i separately before both calls;
 *   narrow first extern parameters retain those explicit u8 argument values.
 * volatile: hardware halfword at 04000304 is read/modified at A078..A07E.
 * symbols:
 *   d_021C3714 0x021C3714 data a4
 *   d_021C3604 0x021C3604 data a4
 *   d_021C3694 0x021C3694 data a4
 *   d_021C36B4 0x021C36B4 data a4
 *   d_021C3674 0x021C3674 data a4
 *   d_021C3614 0x021C3614 data a4
 *   d_021C36F4 0x021C36F4 data a4
 *   d_021C36D4 0x021C36D4 data a4
 *   d_021C3654 0x021C3654 data a4
 *   d_021C3634 0x021C3634 data a4
 *   func_020433E0 0x020433E0 arm
 *   func_0203FC28 0x0203FC28 arm
 *   func_0203FCA0 0x0203FCA0 arm
 *   func_020414EC 0x020414EC arm
 *   func_02040588 0x02040588 arm
 *   func_0201D7EC 0x0201D7EC thumb
 *   func_0201C450 0x0201C450 thumb
 */
#include "../include/Obj13769.h"
#include "../include/Obj22333.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { GX_DISP_SELECT_SUB_MAIN=0, GX_DISP_SELECT_MAIN_SUB=1 } GXDispSelect;
static inline void GX_SetDispSelect(GXDispSelect sel) {
    *(volatile u16 *)0x04000304=(u16)((*(volatile u16 *)0x04000304 & ~0x8000) | (sel<<15));
}
extern const u8 d_021C3714[];
extern u8 d_021C3604[];
extern const u8 d_021C3694[],d_021C36B4[],d_021C3674[],d_021C3614[];
extern const u8 d_021C36F4[],d_021C36D4[],d_021C3654[],d_021C3634[];
struct BgTemplate;
struct DispConfig;
struct DispVram;
extern void func_020433E0(const struct DispVram *c);
extern void func_0203FC28(struct DispConfig *cfg);
extern void func_0203FCA0(u32 bgId, const struct BgTemplate *tmpl, u32 type);
struct GfFont;
extern void func_020414EC(u32 i);
extern void func_02040588(unsigned char which, unsigned char enable);
extern struct GfFont *func_0201D7EC(int a0, int a1, int a2, int a3, u32 heapId);
extern void *func_0201C450(u16,u32);
void func_021BA070(u8 *p) {
    u8 *q=*(u8 * *)&((struct Obj22333 *)p)->f0;
    int i;
    GX_SetDispSelect(GX_DISP_SELECT_SUB_MAIN);
    func_020433E0((const struct DispVram *)d_021C3714);
    func_0203FC28((struct DispConfig *)d_021C3604);
    func_0203FCA0(0,(const struct BgTemplate *)d_021C3694,0);
    func_0203FCA0(1,(const struct BgTemplate *)d_021C36B4,0);
    func_0203FCA0(2,(const struct BgTemplate *)d_021C3674,0);
    func_0203FCA0(3,(const struct BgTemplate *)d_021C3614,0);
    func_0203FCA0(4,(const struct BgTemplate *)d_021C36F4,0);
    func_0203FCA0(5,(const struct BgTemplate *)d_021C36D4,0);
    func_0203FCA0(6,(const struct BgTemplate *)d_021C3654,0);
    func_0203FCA0(7,(const struct BgTemplate *)d_021C3634,0);
    for(i=0;i<=7;++i) {
        func_020414EC((u8)i);
        func_02040588((u8)i,1);
    }
    ((struct Obj13769 *)q)->f80=func_0201D7EC(23,0,0,0,42);
    ((struct Obj13769 *)q)->f7C=func_0201C450(0x500,42);
}
