/*
 * function: ENTRANCE_CAMERA_Create
 * address:  0x021BDC94
 * packet:   pkt_ov021_021BDC94
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb  ov021
 *   ENTRANCE_CAMERA_AllocWork  0x021BDD58  thumb  ov021
 *   ENTRANCE_CAMERA_InitWork  0x021BDD7C  thumb  ov021
 *   ENTRANCE_CAMERA_CreateAnime  0x021BDD9C  thumb  ov021
 */

typedef unsigned short u16;
typedef unsigned char  u8;
extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *ENTRANCE_CAMERA_AllocWork(int a);
extern void ENTRANCE_CAMERA_InitWork(void *r, void *a);
extern void ENTRANCE_CAMERA_CreateAnime(void *r, void *x);

void *ENTRANCE_CAMERA_Create(void *a)
{
    void *x = (void *)FIELDMAP_GetHeapId(a);
    void *r = ENTRANCE_CAMERA_AllocWork((int)x);

    ENTRANCE_CAMERA_InitWork(r, a);
    ENTRANCE_CAMERA_CreateAnime(r, x);
    return r;
}
