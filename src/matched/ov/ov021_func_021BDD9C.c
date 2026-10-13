/*
 * function: ENTRANCE_CAMERA_CreateAnime
 * address:  0x021BDD9C
 * packet:   pkt_ov021_021BDD9C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_Create  0x0218FE80  thumb  ov021
 */

typedef struct {
    void *f0;
    char pad[0x50];
    void *f54;
} Obj;

extern void *FIELD_CAMERA_ANIME_Create(void *a);

void ENTRANCE_CAMERA_CreateAnime(Obj *p)
{
    p->f54 = FIELD_CAMERA_ANIME_Create(p->f0);
}
