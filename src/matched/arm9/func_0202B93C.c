/*
 * function: ISS_3DS_SYS_SetCamera
 * address:  0x0202B93C
 * packet:   pkt_0202B93C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ISS_3DS_SYS_SetCameraImpl  0x0202BA9C  thumb
 */

extern void ISS_3DS_SYS_SetCameraImpl(char *p, const int *a, const int *b);

void ISS_3DS_SYS_SetCamera(int a, void *b, void *c)
{
    ISS_3DS_SYS_SetCameraImpl((char *)a, b, c);
}
