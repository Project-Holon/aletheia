/*
 * function: C_GEAR_UpdateTabPalettes
 * address:  0x021F0728
 * packet:   pkt_ov029_021F0728
 * region:   ov029
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   C_GEAR_UpdateTabPalettes  0x021F0728  thumb  ov029
 *   C_GEAR_UpdateTabPaletteKind3  0x021F07AC  thumb  ov029
 *   C_GEAR_UpdateTabPaletteKind1  0x021F07EC  thumb  ov029
 *   C_GEAR_UpdateTabPaletteKind2  0x021F0824  thumb  ov029
 *   C_GEAR_UpdateTabPaletteKind0  0x021F0858  thumb  ov029
 *   C_GEAR_UpdateTabPaletteKind4  0x021F088C  thumb  ov029
 */

typedef unsigned char u8;

struct E {
    u8 b[10];
};

typedef unsigned short u16;
extern void C_GEAR_UpdateTabPaletteKind3(u8 *p, int i, u16 *e);
extern void C_GEAR_UpdateTabPaletteKind1(void *p, int i, unsigned short *q);
extern void C_GEAR_UpdateTabPaletteKind2(void *p, int i, unsigned short *q);
extern void C_GEAR_UpdateTabPaletteKind0(void *p, int i, unsigned short *q);
extern void C_GEAR_UpdateTabPaletteKind4(void *p, int i, unsigned short *q);

void C_GEAR_UpdateTabPalettes(u8 *p)
{
    struct E *q = (struct E *)(p + 0x418);
    int i;

    for (i = 0; i < 3; i++) {
        u8 c = p[i + 0x44a];

        switch (c) {
        case 3:
            C_GEAR_UpdateTabPaletteKind3(p, i, (u16 *)(&q[c]));
            break;
        case 1:
            C_GEAR_UpdateTabPaletteKind1(p, i, (short unsigned int *)(&q[c]));
            break;
        case 2:
            C_GEAR_UpdateTabPaletteKind2(p, i, (short unsigned int *)(&q[c]));
            break;
        case 0:
            C_GEAR_UpdateTabPaletteKind0(p, i, (short unsigned int *)(&q[c]));
            break;
        case 4:
            C_GEAR_UpdateTabPaletteKind4(p, i, (short unsigned int *)(&q[c]));
            break;
        }
    }
}
