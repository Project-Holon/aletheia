/*
 * function: func_021BCD68
 * address: 0x021BCD68
 * packet: pkt_ov208_021BCD68
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: SDK g3x.h shading enum and boolean inline bodies preserve the hardware mask sequence; pool word at 021BCE04 is BFFF0000.
 * volatile: hardware 04000008 and 04000060 read/write at 021BCD78-021BCDBA; 04000580 write at 021BCDD8.
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021C8164 0x021C8164 data a2
 */
typedef unsigned short u16;
typedef enum {ShadeToon=0,ShadeHighlight=1} GXShading;
#define REG60 (*(volatile u16 *)0x04000060)
static inline void SetShading(GXShading shading) {REG60=(u16)((REG60 & ~0x3002)|(shading<<1));}
static inline void AntiAlias(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|0x10);else REG60&=(u16)~0x3010;}
static inline void AlphaTest(int enable,int ref) {if(enable){REG60=(u16)((REG60 & ~0x3000)|4);*(volatile u16 *)0x04000340=(u16)ref;}else REG60&=(u16)~0x3004;}
static inline void AlphaBlend(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|8);else REG60&=(u16)~0x3008;}
static inline void EdgeMarking(int enable) {if(enable)REG60=(u16)((REG60 & ~0x3000)|0x20);else REG60&=(u16)~0x3020;}
extern void func_020434DC(unsigned,unsigned);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16,int,int,int,int);
typedef unsigned int   u32;
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned,unsigned);
extern const u16 d_021C8164[][4];
void func_021BCD68(void)
{
    unsigned i;
    func_020434DC(1,1);
    *(volatile u16 *)0x04000008=(*(volatile u16 *)0x04000008 & ~3)|1;
    SetShading(ShadeHighlight);
    AntiAlias(0);
    AlphaTest(0,0);
    AlphaBlend(1);
    EdgeMarking(0);
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,0x7fff,0x3f,0);
    *(volatile unsigned *)0x04000580=0xbfff0000;
    for(i=0;i<4;i++)func_02046A94((unsigned char)i,d_021C8164[i]);
    func_02046BE0(0,0);
}
