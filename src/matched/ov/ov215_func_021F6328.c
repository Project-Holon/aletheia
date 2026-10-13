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
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021F71A4 0x021F71A4 data a2
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern const u16 d_021F71A4[];
typedef unsigned int   u32;
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16,int,int,int,int);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(unsigned,unsigned);
static inline void SetPriority(int priority)
{
    *(volatile u16 *)0x04000008=(u16)((*(volatile u16 *)0x04000008 & ~3)|(priority<<0));
}
void func_021F6328(void)
{
    unsigned i;
    BG_SYS_SetMainPlaneVisible(1,1);
    SetPriority(0);
    *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060 & ~0x3002)|2);
    *(volatile u16 *)0x04000060 &= ~0x3010;
    *(volatile u16 *)0x04000060 &= ~0x3004;
    *(volatile u16 *)0x04000060=(u16)((*(volatile u16 *)0x04000060 & ~0x3000)|8);
    *(volatile u16 *)0x04000060 &= ~0x3020;
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,0x7FFF,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,d_021F71A4+i*4);
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
