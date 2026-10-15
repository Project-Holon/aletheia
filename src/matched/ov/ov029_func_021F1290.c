/*
 * function: C_GEAR_DrawTile
 * address:  0x021F1290
 * packet:   pkt_ov029_021F1290
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note 2026-10-05 (wD7 lane15): closed. The table entry is a named block local (w = t.w[c]) in the
 *   store block. mwcc puts a named local first in `w + o` (adds r0,r0,r4); the plain t.w[c] load
 *   is a temp and goes second, which was the last 2-byte residue.
 *
 * symbols:
 *   C_GEAR_TileToScreen  0x021F0D14  thumb  ov029
 *   C_GEAR_GetTilePalette  0x021F0C70  thumb  ov029
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   d_021F3354     0x021F3354  data  a4
 *   d_021F31D4     0x021F31D4  data  a2
 *   d_021F323C     0x021F323C  data  a1
 */

typedef unsigned char  u8;
typedef unsigned short u16;

typedef struct { int w[6]; } Tab;

extern const Tab d_021F3354;
extern const u16 d_021F31D4[];
extern const u8 d_021F323C[];
extern void C_GEAR_TileToScreen(int a, int b, int *x, int *y);
extern int C_GEAR_GetTilePalette(void *p, int i, int j, int k);
typedef unsigned int   u32;
extern u32 BG_SYS_GetBuf(int channel);

void C_GEAR_DrawTile(void *q, int a, int b, int c)
{
    Tab t = d_021F3354;
    int y, x, xx, v, pal, i, yy, j;
    u16 *buf;

    buf = (u16 *)BG_SYS_GetBuf(4);
    C_GEAR_TileToScreen(a, b, &y, &x);
    v = d_021F31D4[c];
    pal = C_GEAR_GetTilePalette(q, v, a, b);
    xx = x;
    for (i = 0; i < 4; i++) {
        int o = i * 32;
        u16 *row = buf + xx * 32;
        yy = y;
        for (j = 0; j < 4; j++) {
            if (yy >= 0 && yy < 0x20) {
                int w = t.w[c];
                row[yy] = (w + o + j) | ((d_021F323C + v * 5)[pal] << 12);
            }
            yy++;
        }
        xx++;
    }
}
