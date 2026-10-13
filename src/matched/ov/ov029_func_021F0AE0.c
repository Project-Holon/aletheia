/*
 * function: C_GEAR_ResetTileFlash
 * address: 0x021F0AE0
 * packet: pkt_ov029_021F0AE0
 * region: ov029
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   C_GEAR_DrawTile 0x021F1290 thumb ov029
 *   C_GEAR_SetTileFlashStep 0x021F0C00 thumb ov029
 */
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct { u16 on:1, cnt:15; u16 f2; u8 f4, f5, f6, f7; } Ent;
extern void C_GEAR_DrawTile(void *, int, int, int);
extern void C_GEAR_SetTileFlashStep(Ent *, int);
void C_GEAR_ResetTileFlash(Ent *p, void *q, int c)
{
    p->f4 = 0;
    C_GEAR_DrawTile(q, p->f6, p->f7, c);
    C_GEAR_SetTileFlashStep(p, 0);
}
