/*
 * function: func_021B7D58
 * address: 0x021B7D58
 * packet: pkt_ov103_021B7D58
 * region: ov103
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * note: Full u16 cast around the BG0 priority update preserves the full complement and bics.
 * volatile: DISP3DCNT re-read at 021B7D72, 021B7D7E, 021B7D88, 021B7D92, 021B7D9E.
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021B92B4 0x021B92B4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void func_020434DC(u32 mask, u32 enable);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(u32 a, u32 b);
extern const u8 d_021B92B4[];
#define D (*(volatile u16 *)0x04000060)
void func_021B7D58(void) {
 unsigned i;
 func_020434DC(1,1);
 *(volatile u16 *)0x04000008 = (u16)(*(volatile u16 *)0x04000008 & ~3);
 D=(D & ~0x3002)|2;
 D &= (u16)~0x3010;
 D &= (u16)~0x3004;
 D=(D & ~0x3000)|8;
 D &= (u16)~0x3020;
 func_0207DC44(0,0,0,0);
 func_0207DD24(0,0,0x7fff,63,0);
 *(volatile unsigned *)0x04000580=0xbfff0000;
 for(i=0;i<4;i++)func_02046A94((u8)i,(void *)(d_021B92B4+i*8));
 func_02046BE0(1,0);
}
