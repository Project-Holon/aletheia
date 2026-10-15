/*
 * function: SHINKA_DEMO_GRAPHIC_GetCamera
 * address:  0x02205A28
 * packet:   pkt_02205A28
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SHINKA_DEMO_GRAPHIC_GetCameraId 0x02205BD8 thumb ov195
 */

extern int SHINKA_DEMO_GRAPHIC_GetCameraId(int *p);

int SHINKA_DEMO_GRAPHIC_GetCamera(char *a)
{
    return SHINKA_DEMO_GRAPHIC_GetCameraId((int *)(a + 4));
}
