/*
 * function: IRC_COMPATIBLE_TOUCH_TEST_Setup3DDisplay
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
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   IRC_COMPATIBLE_TOUCH_TEST_Lights 0x021B92B4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
extern const u8 IRC_COMPATIBLE_TOUCH_TEST_Lights[];
#define D (*(volatile u16 *)0x04000060)
void IRC_COMPATIBLE_TOUCH_TEST_Setup3DDisplay(void) {
 unsigned i;
 BG_SYS_SetMainPlaneVisible(1,1);
 *(volatile u16 *)0x04000008 = (u16)(*(volatile u16 *)0x04000008 & ~3);
 D=(D & ~0x3002)|2;
 D &= (u16)~0x3010;
 D &= (u16)~0x3004;
 D=(D & ~0x3000)|8;
 D &= (u16)~0x3020;
 G3X_SetFog(0,0,0,0);
 G3X_SetClearColor(0,0,0x7fff,63,0);
 *(volatile unsigned *)0x04000580=0xbfff0000;
 for(i=0;i<4;i++)G3D_SYSTEM_SetLight((u8)i,(void *)(IRC_COMPATIBLE_TOUCH_TEST_Lights+i*8));
 G3D_SYSTEM_SetSwapBuffersMode(1,0);
}
