/*
 * function: INTRUDE_SUBDISP_SetTownCursor
 * address:  0x0217F118
 * packet:   pkt_ov018_0217F118
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 pad0[0x5C];
    void *tbl[9];
    u8 pad80[0x114 - 0x80];
    u8 f114;
    u8 pad115[3];
    u16 f118;
    u8 f11A;
    u8 f11B;
} Ov018Sel;

typedef unsigned int   u32;
struct Obj;
void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

void INTRUDE_SUBDISP_SetTownCursor(Ov018Sel *p, int n)
{
    u8 c;

    c = p->f11B;
    if (c != n && p->f114 != 1) {
        if (c < 8) {
            CLACT_SetActorPaletteOffset(p->tbl[c], 6, 1);
        } else if (c == 8) {
            CLACT_SetActorPaletteOffset(p->tbl[8], 6, 1);
        }
        if (n < 8) {
            CLACT_SetActorPaletteOffset(p->tbl[n], 8, 1);
        } else if (n == 8) {
            CLACT_SetActorPaletteOffset(p->tbl[8], 8, 1);
        }
        p->f11B = n;
        p->f118 = 0;
        p->f11A = 0;
    }
}
