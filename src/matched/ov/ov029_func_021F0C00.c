/*
 * function: C_GEAR_SetTileFlashStep
 * address:  0x021F0C00
 * packet:   pkt_ov029_021F0C00
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_TileToScreen  0x021F0D14  thumb  ov029
 *   BG_SYS_FillTileMap  0x020413B0  arm
 *   func_020409B4  0x020409B4  arm
 *   d_021F323C     0x021F323C  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct {
    u16 on  : 1;
    u16 cnt : 15;
    u16 f2;
    u8  f4;
    u8  f5;
    u8  f6;
    u8  f7;
} Ent;

extern const u8 d_021F323C[];
extern void C_GEAR_TileToScreen(int a, int b, int *x, int *y);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(unsigned int index);

void C_GEAR_SetTileFlashStep(Ent *p, int idx)
{
    int x, y, w;
    int pal;

    pal = (d_021F323C + p->f4 * 5)[idx];
    C_GEAR_TileToScreen(p->f6, p->f7, &x, &y);
    w = 4;
    if (x < 0) {
        w = x + 4;
        x = 0;
    } else if (x + 4 > 0x20) {
        w = 0x20 - x;
    }
    BG_SYS_FillTileMap(4, x, y, w, 4, pal);
    func_020409B4(4);
}
