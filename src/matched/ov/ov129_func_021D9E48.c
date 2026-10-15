/*
 * function: WF2DMAP_SCENE_SetCursorVisible
 * address:  0x021D9E48
 * packet:   pkt_021D9E48
 * region:   ov129
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_SetActorDrawEnable  0x0204B3DC  arm
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct Obj;
extern void CLACT_SetActorDrawEnable(struct Obj *p, u32 v);

void WF2DMAP_SCENE_SetCursorVisible(char *p, int i, int a)
{
    CLACT_SetActorDrawEnable(*(void **)(p + i * 0x1c + 0x194), a);
}
