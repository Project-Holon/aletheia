/*
 * function: FIELD_PLACE_NAME_StateFadeInWait
 * address:  0x021BCD70
 * packet:   pkt_ov021_021BCD70
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_PLACE_NAME_SetState  0x021BCB9C  thumb  ov021
 */

typedef unsigned short u16;

typedef struct {
    char pad[0x42];
    u16 h42;
} Obj;

extern void FIELD_PLACE_NAME_SetState(void *p, int keep);

void FIELD_PLACE_NAME_StateFadeInWait(Obj *p)
{
    if (p->h42 > 10) {
        FIELD_PLACE_NAME_SetState(p, 4);
    }
}
