/*
 * function: func_021B9E6C
 * address: 0x021B9E6C
 * packet: pkt_ov222_021B9E6C
 * region: ov222
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: SDK BG0 priority uses explicit (u16) assignment; compound &= pools 0xfffc.
 * volatile: 021B9E7A..021B9EB8 BG0CNT/DISP3DCNT re-reads; 021B9ED6 VIEWPORT
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   func_0207DC44 0x0207DC44 arm
 *   func_0207DD24 0x0207DD24 arm
 *   func_02046A94 0x02046A94 arm
 *   func_02046BE0 0x02046BE0 arm
 *   d_021BA2AC 0x021BA2AC data a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 d_021BA2AC[][4];
extern void func_020434DC(u32,u32);
extern void func_0207DC44(int,int,int,int);
extern void func_0207DD24(u16,int,int,int,int);
extern void func_02046A94(u32 idx, const u16 *src);
extern void func_02046BE0(u32,u32);
#define R (*(volatile u16*)0x04000060)
void func_021B9E6C(void)
{
 u32 i;
 func_020434DC(1,1);
 *(volatile u16*)0x04000008 = (u16)(*(volatile u16*)0x04000008 & ~3);
 R=(R & ~0x3002)|2;
 R &= ~0x3010;
 R &= ~0x3004;
 R=(R & ~0x3000)|8;
 R &= ~0x3020;
 func_0207DC44(0,0,0,0);
 func_0207DD24(0,0,0x7fff,63,0);
 *(volatile u32*)0x04000580=0xbfff0000;
 for(i=0;i<4;i++)func_02046A94((u8)i,d_021BA2AC[i]);
 func_02046BE0(0,0);
}
