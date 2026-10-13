/*
 * function: FLDMMDL_InitPosRecord
 * address:  0x0216E618
 * packet:   pkt_ov010_0216E618
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf (sole blocker of ov018 INTRUDE_FIELD_InitMmdlCopyAnime): clears the word
 * at +0x18 and fills the {u16, u16, int} record at +0x1C.
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 x;
    u16 y;
    int z;
} Pos;

typedef struct {
    u8 pad00[0x18];
    int f18;
    Pos pos;
} Obj;

void FLDMMDL_InitPosRecord(Obj *o, u16 x, u16 y, int z)
{
    Pos *p;

    o->f18 = 0;
    p = &o->pos;
    p->x = x;
    p->y = y;
    p->z = z;
}
