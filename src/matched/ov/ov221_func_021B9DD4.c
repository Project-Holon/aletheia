/*
 * function: func_021B9DD4
 * address: 0x021B9DD4
 * packet: pkt_ov221_021B9DD4
 * region: ov221
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B9DE2 BG0CNT; 021B9DEE..021B9E20 DISP3DCNT; 021B9E3E viewport.
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BA200 0x021BA200 data a2
 */
#define REG3D (*(volatile unsigned short *)0x04000060)
typedef enum { SHADING1 = 1 } GXShading;
typedef int BOOL;
extern void func_020434DC(unsigned, unsigned);
extern void func_0207DC44(BOOL,int,int,int);
extern void func_0207DD24(unsigned short,int,int,int,BOOL);
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(unsigned,unsigned);
extern const unsigned short d_021BA200[][4];
static inline void Shading(GXShading mode) { REG3D=(unsigned short)((REG3D & ~0x3002)|(mode<<1)); }
static inline void AntiAlias(BOOL enable) { if(enable) REG3D=(unsigned short)((REG3D & ~0x3000)|0x10); else REG3D &= (unsigned short)~0x3010; }
static inline void AlphaTest(BOOL enable,int ref) { if(enable) { REG3D=(unsigned short)((REG3D & ~0x3000)|4); *(volatile unsigned short *)0x04000340=ref; } else REG3D &= (unsigned short)~0x3004; }
static inline void AlphaBlend(BOOL enable) { if(enable) REG3D=(unsigned short)((REG3D & ~0x3000)|8); else REG3D &= (unsigned short)~0x3008; }
static inline void EdgeMarking(BOOL enable) { if(enable) REG3D=(unsigned short)((REG3D & ~0x3000)|0x20); else REG3D &= (unsigned short)~0x3020; }
void func_021B9DD4(void)
{
    unsigned i;
    func_020434DC(1,1);
    *(volatile unsigned short *)0x04000008 = *(volatile unsigned short *)0x04000008 & ~3;
    Shading(SHADING1);
    AntiAlias(0);
    AlphaTest(0,0);
    AlphaBlend(1);
    EdgeMarking(0);
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,0x7FFF,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) func_02046A94((unsigned char)i,d_021BA200[i]);
    func_02046BE0(0,0);
}
