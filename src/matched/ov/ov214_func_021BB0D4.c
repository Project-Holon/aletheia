/*
 * function: func_021BB0D4
 * address: 0x021BB0D4
 * packet: pkt_ov214_021BB0D4
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * volatile: BG0CNT at 021BB0E2/021BB0EA; DISP3DCNT rereads at 021BB0EE/021BB0FA/021BB102/021BB10E/021BB11A; viewport store 021BB13E
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   rects 0x021BB568 data a4
 */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Rect {u16 h[4];};
extern const struct Rect rects[];
extern void func_020434DC(u32,u32);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(u32,u32);
typedef enum { GX_SHADING_TOON, GX_SHADING_HIGHLIGHT } GXShading;
#define REG3D (*(volatile u16 *)0x04000060)
static inline void G2_SetBG0Priority(int priority)
{
    *(volatile u16 *)0x04000008=(u16)((*(volatile u16 *)0x04000008 & ~3) | priority);
}
static inline void G3X_SetShading(GXShading shading)
{
    REG3D=(u16)((REG3D & ~(2|0x3000)) | (shading<<1));
}
static inline void G3X_AntiAlias(int enable)
{
    if(enable) REG3D=(u16)((REG3D & ~0x3000)|16);
    else REG3D &= (u16)~(16|0x3000);
}
static inline void G3X_AlphaTest(int enable,int ref)
{
    if(enable) { REG3D=(u16)((REG3D & ~0x3000)|4); *(volatile u16 *)0x04000340=(u16)ref; }
    else REG3D &= (u16)~(4|0x3000);
}
static inline void G3X_AlphaBlend(int enable)
{
    if(enable) REG3D=(u16)((REG3D & ~0x3000)|8);
    else REG3D &= (u16)~(8|0x3000);
}
static inline void G3X_EdgeMarking(int enable)
{
    if(enable) REG3D=(u16)((REG3D & ~0x3000)|32);
    else REG3D &= (u16)~(32|0x3000);
}
void func_021BB0D4(void)
{
    u32 i;
    func_020434DC(1,1);
    G2_SetBG0Priority(0);
    G3X_SetShading(GX_SHADING_HIGHLIGHT);
    G3X_AntiAlias(0);
    G3X_AlphaTest(0,0);
    G3X_AlphaBlend(1);
    G3X_EdgeMarking(0);
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,32767,63,0);
    *(volatile u32 *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) func_02046A94((u8)i,(const u16 *)(&rects[i]));
    func_02046BE0(0,0);
}
