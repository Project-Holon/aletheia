/*
 * function: FIELD_MENU_UpdateSelection
 * address:  0x021A90E0
 * packet:   pkt_ov021_021A90E0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 *   FIELD_MENU_PlaceCursor  0x021A9080  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u32 f00;
    u32 f04;
    u32 f08;
    u8 pad0C[8];
    u8 f14;
    u8 f15;
    u8 pad16[2];
    void *f18;
};

struct W {
    u8 pad00[0x1E];
    u8 f1E;
    u8 f1F;
    u8 pad20[4];
    u32 f24;
    u8 pad28[4];
    u32 f2C;
    u32 f30;
    struct Slot slots[7];
    struct Slot *cur;
    u8 padFC[0x28];
    void *f124;
};

struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
extern void FIELD_MENU_PlaceCursor(struct W *w, u32 a, u32 b);

void FIELD_MENU_UpdateSelection(struct W *w)
{
    struct Slot *old;

    if (w->f24 == 1) {
        old = w->cur;
        w->cur = &w->slots[w->f1E + w->f1F * 2];
        CLACT_SetActorAnimSeq(w->f124, 0);
        FIELD_MENU_PlaceCursor(w, w->cur->f14, w->cur->f15);
        if (w->cur->f18 != 0 && w->f2C == 1) {
            CLACT_SetActorAnimSeq(w->cur->f18, 1);
        }
        if (old != 0 && old->f18 != 0) {
            CLACT_SetActorAnimSeq(old->f18, 0);
        }
        w->f24 = 0;
    }
}
