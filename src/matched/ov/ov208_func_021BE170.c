/*
 * function: ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft
 * address:  0x021BE170
 * packet:   pkt_ov208_021BE170
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZKND_TBAR_GetButtonActor  0x021BD3C0  thumb
 *   CLACT_SetActorPaletteOffset  0x0204B6F4  arm
 */

typedef unsigned int u32;

struct Ov208Slot {
    int *key;
    u32 f4;
};

struct Ov208Scene {
    u32 pad0[7];
    u32 f1c;
    u32 pad20[4];
    u32 mgr;
    u32 pad34[14];
    struct Ov208Slot slots[10];
};

struct Obj;
extern int ZKND_TBAR_GetButtonActor(void *mgr, int key);
extern void CLACT_SetActorPaletteOffset(struct Obj *o, u32 v, u32 flag);

void ZUKAN_DETAIL_TOUCHBAR_ApplyPaletteLeft(struct Ov208Scene *p)
{
    u32 idx = 9;

    switch (p->f1c) {
    case 0:
        idx = 6;
        break;
    case 1:
        idx = 5;
        break;
    case 2:
        idx = 4;
        break;
    case 3:
        idx = 3;
        break;
    }
    if (idx != 9)
        CLACT_SetActorPaletteOffset((struct Obj *)ZKND_TBAR_GetButtonActor((void *)p->mgr, *p->slots[idx].key), 2, 0);
}
