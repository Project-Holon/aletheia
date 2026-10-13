/*
 * unit:     yes
 * function: PMS_DRAW_IsPrintEnd, PMS_DRAW_Clear, PMS_DRAW_SetVisible
 * address:  0x0202DC98
 * packet:   pkt_0202DC98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PMS_DRAW_ClearElem  0x0202E38C  thumb
 *   PMS_DRAW_SetElemVisible  0x0202E3E4  thumb
 *
 * Three leaves before PMS_DRAW_IsActive over an object with a count at +0x28 and
 * an array of 0x28-byte elements at +0xc: the count getter, and two
 * forwarders that pass element i and one argument to PMS_DRAW_ClearElem and
 * PMS_DRAW_SetElemVisible.  Seeded from ov031 0x021F069A, ov110 0x021C0CC6, ov111
 * 0x021C61D2, ov216 0x021BD12A.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

struct Elem0202DC98 {
    u8 unk00[0x28];
};

struct Obj0202DC98 {
    u8 unk00[0xC];
    struct Elem0202DC98 *elems; /* +0x0C */
    u8 unk10[0x18];
    u32 count;                  /* +0x28 */
};

struct Obj0202E38C;
struct Obj0202E3E4;
extern void PMS_DRAW_ClearElem(struct Obj0202E38C *obj, u32 a1);
extern void PMS_DRAW_SetElemVisible(struct Obj0202E3E4 *obj, u32 a1);

u32 PMS_DRAW_IsPrintEnd(struct Obj0202DC98 *o)
{
    return o->count;
}

void PMS_DRAW_Clear(struct Obj0202DC98 *o, int i, u32 a1)
{
    PMS_DRAW_ClearElem((struct Obj0202E38C *)(&o->elems[i]), a1);
}

void PMS_DRAW_SetVisible(struct Obj0202DC98 *o, int i, u32 a1)
{
    PMS_DRAW_SetElemVisible((struct Obj0202E3E4 *)(&o->elems[i]), a1);
}
