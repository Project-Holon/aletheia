/*
 * function: ENTRANCE_CAMERA_DeleteAnime
 * address:  0x021BDDAC
 * packet:   pkt_ov021_021BDDAC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELD_CAMERA_ANIME_Delete  0x0218FE98  thumb  ov021
 */

typedef struct {
    char pad[0x54];
    void *f54;
} Obj;

extern void FIELD_CAMERA_ANIME_Delete(void);

void ENTRANCE_CAMERA_DeleteAnime(Obj *p)
{
    if (p->f54 != 0) {
        FIELD_CAMERA_ANIME_Delete();
        p->f54 = 0;
    }
}
