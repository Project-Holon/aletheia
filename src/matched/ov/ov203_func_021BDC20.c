/*
 * function: func_021BDC20
 * address: 0x021BDC20
 * packet: pkt_ov203_021BDC20
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BE948 0x021BE948 thumb ov203
 *   WIPE_SetMstBrightColor 0x02022268 thumb
 *   FADE_GetSpeed 0x0204E6E0 arm
 *   func_0202208C 0x0202208C thumb
 */
extern void func_021BE948(void *ctx, int mode, unsigned char *width, unsigned char *height);
extern void WIPE_SetMstBrightColor(unsigned);
extern unsigned FADE_GetSpeed(void);
extern void func_0202208C(void *, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
int func_021BDC20(void *ctx, unsigned mode, unsigned heap)
{
    unsigned char width, height;
    unsigned char factor;
    int color;
    func_021BE948(ctx, (unsigned char)(mode == 0), &width, &height);
    color = 0;
    if (width) color = 32767;
    WIPE_SetMstBrightColor(color);
    if (height) {
        factor = FADE_GetSpeed();
        func_0202208C(0, mode, mode, color, height * factor, 1, heap);
        return 0;
    }
    return 1;
}
