/*
 * function: C_GEAR_StartTileFlash
 * address:  0x021F0B00
 * packet:   pkt_ov029_021F0B00
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     `t = 0` must come first: set after the stores, the third parameter stays in r2
 *           instead of moving to r1 at entry (27 bytes out).
 *
 * symbols:
 *   C_GEAR_GetTilePalette  0x021F0C70  thumb  ov029
 *   C_GEAR_DrawTile  0x021F1290  thumb  ov029
 *   C_GEAR_SetTileFlashStep  0x021F0C00  thumb  ov029
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

extern int C_GEAR_GetTilePalette(void *p, int i, int j, int k);
extern void C_GEAR_DrawTile(void *q, int a, int b, int c);
extern void C_GEAR_SetTileFlashStep(Ent *p, int t);

void C_GEAR_StartTileFlash(Ent *p, void *q, int a, int mode, int c, u16 d)
{
    int t;

    t = 0;
    p->f4 = a;
    p->cnt = 0;
    p->on = 1;
    p->f2 = d;
    if (mode == 0) {
        p->f5 = 0;
    } else if (mode == 1) {
        p->f5 = 4;
    } else if (mode == 2) {
        p->f5 = C_GEAR_GetTilePalette(q, a, p->f6, p->f7);
        p->cnt = d * 5;
        t = 4;
    }
    C_GEAR_DrawTile(q, p->f6, p->f7, c);
    C_GEAR_SetTileFlashStep(p, t);
}
