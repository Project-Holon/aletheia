/*
 * function: func_021F6328
 * address: 0x021F6328
 * packet: pkt_ov215_021F6328
 * region: ov215
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware 021F6336,6342,634E,6358,6362,636E,6392.
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021F71A4 0x021F71A4 data a2
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern const u16 d_021F71A4[];
extern void func_020434DC(int,int);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_02046A94(u8,const u16 *);
extern void func_02046BE0(unsigned,unsigned);
static inline void SetPriority(int priority)
{
    *(volatile u16 *)0x04000008=(u16)((*(volatile u16 *)0x04000008 & ~3)|(priority<<0));
}
void func_021F6328(void)
{
    unsigned i;
    func_020434DC(1,1);
    SetPriority(0);
    *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060 & ~0x3002)|2);
    *(volatile u16 *)0x04000060 &= ~0x3010;
    *(volatile u16 *)0x04000060 &= ~0x3004;
    *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060 & ~0x3000)|8);
    *(volatile u16 *)0x04000060 &= ~0x3020;
    func_0207DC44(0,0,0,0);
    func_0207DD24(0,0,0x7FFF,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) func_02046A94(i,d_021F71A4+i*4);
    func_02046BE0(0,0);
}
