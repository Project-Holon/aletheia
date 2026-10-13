/*
 * function: ENTRANCE_CAMERA_Start
 * address:  0x021BDD20
 * packet:   pkt_ov021_021BDD20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ENTRANCE_CAMERA_IsPhaseActive  0x021BE1C4  thumb  ov021
 *   FIELD_CAMERA_ANIME_Start  0x0218FF00  thumb  ov021
 */

typedef struct {
    char pad[0x54];
    void *f54;
} Obj;

typedef unsigned int   u32;
extern int ENTRANCE_CAMERA_IsPhaseActive(u32 a);
extern int FIELD_CAMERA_ANIME_Start(u32 a);

void ENTRANCE_CAMERA_Start(Obj *p)
{
    if (ENTRANCE_CAMERA_IsPhaseActive((u32)p)) {
        FIELD_CAMERA_ANIME_Start((u32)p->f54);
    }
}
