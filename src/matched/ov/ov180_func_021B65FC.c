/*
 * function: HALL_OF_FAME_Setup3dState
 * address: 0x021B65FC
 * packet: pkt_ov180_021B65FC
 * region: ov180
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: 021B660A..021B6648 re-read hardware 0x04000008 and 0x04000060; hardware write 0x04000580.
 * symbols:
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   gHallOfFameLights 0x021B8040 data a4
 */
typedef unsigned short u16;
extern void BG_SYS_SetMainPlaneVisible(unsigned,unsigned); extern void G3X_SetFog(int,int,int,int); extern void G3X_SetClearColor(u16,int,int,int,int);
typedef unsigned int   u32;
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src); extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);
extern const unsigned char gHallOfFameLights[];
#define REG(a) (*(volatile u16 *)(a))
void HALL_OF_FAME_Setup3dState(void) {
 unsigned i;
 BG_SYS_SetMainPlaneVisible(1,1);
 REG(0x04000008)=REG(0x04000008)&~3;
 REG(0x04000060)=(u16)((REG(0x04000060)&~0x3002)|2);
 REG(0x04000060)&=(u16)~0x3010;
 REG(0x04000060)&=(u16)~0x3004;
 REG(0x04000060)=(u16)((REG(0x04000060)&~0x3000)|8);
 REG(0x04000060)&=(u16)~0x3020;
 G3X_SetFog(0,0,0,0); G3X_SetClearColor(0,0,32767,63,0);
 *(volatile unsigned *)0x04000580=0xBFFF0000;
 for(i=0;i<4;i++) G3D_SYSTEM_SetLight((unsigned char)i,(const u16 *)(gHallOfFameLights+i*8));
 G3D_SYSTEM_SetSwapBuffersMode(1,0);
}
