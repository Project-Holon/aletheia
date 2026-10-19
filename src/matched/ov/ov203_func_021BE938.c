/*
 * function: DEMO3D_DATA_IsDouble3dDisplay
 * address:  0x021BE938
 * packet:   pkt_021BE938
 * region:   ov203
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   DEMO3D_ENGINE_GetCameraRecord 0x021BE7A8 thumb
 */

typedef unsigned int   u32;
extern u32 DEMO3D_ENGINE_GetCameraRecord(u32 id);

int DEMO3D_DATA_IsDouble3dDisplay(void *a)
{
    unsigned int v = *(unsigned short *)(DEMO3D_ENGINE_GetCameraRecord((u32)a) + 6);
    return (v << 30) >> 31;
}
