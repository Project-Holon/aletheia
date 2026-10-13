/*
 * function: EVENT_ENTRANCE_OUT_ShowPlaceName
 * address:  0x021BDC80
 * packet:   pkt_ov021_021BDC80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetPlaceName  0x02188D20  thumb  ov021
 *   FIELD_PLACE_NAME_OnZoneChange  0x021BC550  thumb  ov021
 */

typedef short s16;

typedef struct {
    char pad[0xC];
    void *fC;
    char pad2[0x10];
    s16 s20;
} Inner;

typedef struct {
    Inner *f0;
} Obj;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern u32 FIELDMAP_GetPlaceName(u8 *p);
extern void FIELD_PLACE_NAME_OnZoneChange(void *p, int v);

void EVENT_ENTRANCE_OUT_ShowPlaceName(Obj *p)
{
    Inner *q = p->f0;

    FIELD_PLACE_NAME_OnZoneChange((void *)FIELDMAP_GetPlaceName(q->fC), q->s20);
}
