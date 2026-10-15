/*
 * function: DEMO3D_StartWipe
 * address: 0x021BDC20
 * packet: pkt_ov203_021BDC20
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_DATA_GetTextureSize 0x021BE948 thumb ov203
 *   WIPE_SetMstBrightColor 0x02022268 thumb
 *   FADE_GetSpeed 0x0204E6E0 arm
 *   WIPE_SYS_Start 0x0202208C thumb
 */
extern void DEMO3D_DATA_GetTextureSize(void *ctx, int mode, unsigned char *width, unsigned char *height);
extern void WIPE_SetMstBrightColor(unsigned);
extern unsigned FADE_GetSpeed(void);
extern void WIPE_SYS_Start(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
int DEMO3D_StartWipe(void *ctx, unsigned mode, unsigned heap)
{
    unsigned char width, height;
    unsigned char factor;
    int color;
    DEMO3D_DATA_GetTextureSize(ctx, (unsigned char)(mode == 0), &width, &height);
    color = 0;
    if (width) color = 32767;
    WIPE_SetMstBrightColor(color);
    if (height) {
        factor = FADE_GetSpeed();
        WIPE_SYS_Start(0, mode, mode, color, height * factor, 1, heap);
        return 0;
    }
    return 1;
}
