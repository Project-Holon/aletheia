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
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021BA2AC 0x021BA2AC data a4
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern const u16 d_021BA2AC[][4];
extern void BG_SYS_SetMainPlaneVisible(u32,u32);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32,u32);
#define R (*(volatile u16*)0x04000060)
void func_021B9E6C(void)
{
 u32 i;
 BG_SYS_SetMainPlaneVisible(1,1);
 *(volatile u16*)0x04000008 = (u16)(*(volatile u16*)0x04000008 & ~3);
 R=(R & ~0x3002)|2;
 R &= ~0x3010;
 R &= ~0x3004;
 R=(R & ~0x3000)|8;
 R &= ~0x3020;
 G3X_SetFog(0,0,0,0);
 G3X_SetClearColor(0,0,0x7fff,63,0);
 *(volatile u32*)0x04000580=0xbfff0000;
 for(i=0;i<4;i++)G3D_SYSTEM_SetLight((u8)i,d_021BA2AC[i]);
 G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
