/*
 * function: ZUKAN_DETAIL_AREA_DeleteTownMarkerActors
 * address:  0x021C06A0
 * packet:   pkt_021C06A0
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   CLACT_DeleteActor  0x0204B3B4  arm  arm9
 *   (none)

 * Frees the second word of every entry whose first word is 2.
 */


struct Obj;
extern void CLACT_DeleteActor(struct Obj *p);

typedef struct {
    char pad[0x1e0];
    int arr[0x7a];
} S;

void ZUKAN_DETAIL_AREA_DeleteTownMarkerActors(int unused, S *s)
{
    unsigned char i;

    for (i = 0; i < 0x3d; i++) {
        if (s->arr[i * 2] == 2)
            CLACT_DeleteActor((struct Obj *)s->arr[i * 2 + 1]);
    }
}
