/*
 * function: FIELD_CAMERA_ANIME_Create
 * address:  0x0218FE80
 * packet:   pkt_ov021_0218FE80
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FIELDMAP_GetHeapId  0x02188C84  thumb
 *   FIELD_CAMERA_ANIME_Alloc  0x0218FF30  thumb
 *   FIELD_CAMERA_ANIME_Init  0x0218FF50  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

extern u16 FIELDMAP_GetHeapId(u8 *p);
extern void *FIELD_CAMERA_ANIME_Alloc(u32 heap);
extern void FIELD_CAMERA_ANIME_Init(u32 *o, void *a);

void *FIELD_CAMERA_ANIME_Create(void *a)
{
    void *o = FIELD_CAMERA_ANIME_Alloc(FIELDMAP_GetHeapId(a));
    FIELD_CAMERA_ANIME_Init(o, a);
    return o;
}
