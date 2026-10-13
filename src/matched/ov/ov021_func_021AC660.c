/*
 * function: FLDEFF_KEMURI_Exit
 * address: 0x021AC660
 * packet: pkt_ov021_021AC660
 * region: ov021
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/ov021/field_effect_p17.c and filed here.
 *
 * symbols:
 *   FIELD_G3DOBJ_DeleteObject 0x021C6628 thumb ov021
 */

typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct HidObj_021AC660 {
    int f0;
    void *f4;
    u16 f8;
} HidObj_021AC660;

void FIELD_G3DOBJ_DeleteObject(u32 a, u32 b);
void FLDEFF_KEMURI_Exit(u32 a, HidObj_021AC660 *q);

void FLDEFF_KEMURI_Exit(u32 a, HidObj_021AC660 *q)
{
    FIELD_G3DOBJ_DeleteObject((u32)q->f4, q->f8);
}
