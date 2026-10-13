/*
 * function: func_021D9580
 * address: 0x021D9580
 * packet: pkt_ov121_021D9580
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware rereads at 021D959A..021D95CA
 * symbols:
 *   func_020434DC 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 *   d_021DF5E4 0x021DF5E4 data a4
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern const int d_021DF5E4[];
typedef unsigned int   u32;
extern void func_020434DC(u32 mask, u32 enable);
extern void G3X_SetFog(int,int,int,int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);
#define REG (*(volatile u16 *)0x04000060)
void func_021D9580(void)
{
    unsigned i;
    func_020434DC(1,0);
    *(volatile u16 *)0x04000008=(u16)(*(volatile u16 *)0x04000008 &~3);
    REG=(u16)((REG&~0x3002)|2);
    REG&=(u16)~0x3010;
    REG&=(u16)~0x3004;
    REG=(u16)((REG&~0x3000)|8);
    REG&=(u16)~0x3020;
    G3X_SetFog(0,0,0,0);
    G3X_SetClearColor(0,0,32767,63,0);
    *(volatile unsigned *)0x04000580=0xBFFF0000;
    for(i=0;i<4;i++) G3D_SYSTEM_SetLight((u8)i,(const u16 *)(d_021DF5E4+i*2));
    G3D_SYSTEM_SetSwapBuffersMode(0,0);
}
