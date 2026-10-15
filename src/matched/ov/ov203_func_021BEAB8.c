/*
 * function: DEMO3D_DATA_ApplyCapture
 * address: 0x021BEAB8
 * packet: pkt_ov203_021BEAB8
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: SDK GX_SetCapture inline preserves argument-load order and enum shifts.
 * volatile: hardware capture control 0x04000064, store at 021BEAEE.
 */
typedef enum { CaptureSize0 = 0, CaptureSize3 = 3 } GXCaptureSize;
typedef enum { CaptureMode0 = 0, CaptureMode2 = 2 } GXCaptureMode;
typedef enum { CaptureSrcA0 = 0, CaptureSrcA1 = 1 } GXCaptureSrcA;
typedef enum { CaptureSrcB0 = 0, CaptureSrcB6 = 6 } GXCaptureSrcB;
typedef enum { CaptureDest0 = 0, CaptureDest15 = 15 } GXCaptureDest;
static inline void GX_SetCapture(GXCaptureSize sz, GXCaptureMode mode, GXCaptureSrcA a, GXCaptureSrcB b, GXCaptureDest dest, int eva, int evb)
{
    *(volatile unsigned *)0x04000064 = 0x80000000 | (mode << 29) | (b << 25) | (a << 24) | (sz << 20) | (dest << 16) | (evb << 8) | eva;
}
void DEMO3D_DATA_ApplyCapture(void *task, const int *ctx)
{
    if (ctx[12]) {
        GX_SetCapture(ctx[4], ctx[5], ctx[6], ctx[7], ctx[8], ctx[9], ctx[10]);
    }
}
