/*
 * function: ZUKAN_DETAIL_FORM_HandleScrollKey
 * address:  0x021C6D10
 * packet:   pkt_ov208_021C6D10
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ZUKAN_DETAIL_FORM_CountEntriesBefore  0x021C6E30  thumb
 *   ZUKAN_DETAIL_FORM_GetScrollSlotRange  0x021C6D6C  thumb
 *   CLACT_AddActorSurfacePos  0x0204B404  arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Ov208Cursor {
    u8  slot;
    u8  pad;
    s16 x;
    s16 y;
};

extern u16  ZUKAN_DETAIL_FORM_CountEntriesBefore(void *a0, u8 *p, int a2, u16 skip, u16 stop);
extern void ZUKAN_DETAIL_FORM_GetScrollSlotRange(int n, int i, u8 *lo, u8 *mid, u8 *hi);
struct Obj;
struct Vec2;
extern void CLACT_AddActorSurfacePos(struct Obj *p, const struct Vec2 *delta, u32 which);

#define W(o) (*(u32 *)(p + (o)))
#define H(o) (*(u16 *)(p + (o)))

int ZUKAN_DETAIL_FORM_HandleScrollKey(void *a0, u8 *p, int a2)
{
    struct Ov208Cursor c;
    int moved;
    u16 i;

    moved = 0;
    if (W(0x698) != 0) {
        i = ZUKAN_DETAIL_FORM_CountEntriesBefore(a0, p, a2, H(0x54e), H(0x550));
        ZUKAN_DETAIL_FORM_GetScrollSlotRange((u16)(H(0x548) - 1), i, 0, &c.slot, 0);
        c.x = c.slot;
        c.y = 0x30;
        CLACT_AddActorSurfacePos((struct Obj *)W(0x5e8), (const struct Vec2 *)(&c.x), 0);
        moved = 1;
    }
    return moved;
}
