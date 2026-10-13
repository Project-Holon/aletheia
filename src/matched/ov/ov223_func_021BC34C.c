/*
 * function: func_021BC34C
 * address: 0x021BC34C
 * packet: pkt_ov223_021BC34C
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: display control reads/stores 021BC356-021BC398 and 021BC3C0.
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BC960 0x021BC960 data a4
 */
typedef enum { TOON, HIGHLIGHT } Shading;
extern char d_021BC960[];
typedef unsigned int   u32;
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(unsigned short,int,int,int,int);
typedef unsigned short u16;
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void func_02046BE0(u32 a, u32 b);
static inline void shading(Shading s)
{
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3002)|(s<<1));
}
static inline void priority(int p)
{
    *(volatile unsigned short *)0x04000008=(unsigned short)((*(volatile unsigned short *)0x04000008 & ~3)|p);
}
void func_021BC34C(void)
{
    unsigned i;
    func_020434DC(1,1);
    priority(0);
    shading(HIGHLIGHT);
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3000)|16);
    *(volatile unsigned short *)0x04000060 &=(unsigned short)~0x3004;
    *(volatile unsigned short *)0x04000060=(unsigned short)((*(volatile unsigned short *)0x04000060 & ~0x3000)|8);
    *(volatile unsigned short *)0x04000060 &=(unsigned short)~0x3020;
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,32767,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((unsigned char)i,(const u16 *)(d_021BC960+i*8));
    func_02046BE0(0,0);
}
