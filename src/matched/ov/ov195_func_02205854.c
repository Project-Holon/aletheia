/*
 * function: func_02205854
 * address:  0x02205854
 * packet:   pkt_02205854
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_02208CCC 0x02208CCC data a4
 *   BG_SYS_SetMainPlaneVisible 0x020434DC arm
 *   G3X_SetFog 0x0207DC44 arm
 *   G3X_SetClearColor 0x0207DD24 arm
 *   G3D_SYSTEM_SetLight 0x02046A94 arm
 *   G3D_SYSTEM_SetSwapBuffersMode 0x02046BE0 arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

#define REG_BG0CNT     (*(volatile u16 *)0x04000008)
#define REG_DISP3DCNT  (*(volatile u16 *)0x04000060)
#define REG_VIEWPORT   (*(volatile u32 *)0x04000580)

extern u8 d_02208CCC[];
extern void BG_SYS_SetMainPlaneVisible(u32 mask, u32 enable);
extern void G3X_SetFog(int, int, int, int);
extern void G3X_SetClearColor(u16 rgb, int alpha, int depth, int polygonID, int fog);
extern void G3D_SYSTEM_SetLight(u32 idx, const u16 *src);
extern void G3D_SYSTEM_SetSwapBuffersMode(u32 a, u32 b);

void func_02205854(void)
{
    u32 i;

    BG_SYS_SetMainPlaneVisible(1, 1);
    REG_BG0CNT = REG_BG0CNT & ~3;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3002) | 2;
    REG_DISP3DCNT &= ~0x3010;
    REG_DISP3DCNT &= ~0x3004;
    REG_DISP3DCNT = (REG_DISP3DCNT & ~0x3000) | 8;
    REG_DISP3DCNT &= ~0x3020;
    G3X_SetFog(0, 0, 0, 0);
    i = 0;
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, i);
    REG_VIEWPORT = 0xbfff0000;
    for (; i < 4; i++)
        G3D_SYSTEM_SetLight((u8)i, (const u16 *)(d_02208CCC + i * 8));
    G3D_SYSTEM_SetSwapBuffersMode(1, 0);
}
