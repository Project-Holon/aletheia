/*
 * function: CameraStandbyCallback
 * address:  0x02702070
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CAMERA_I2CActivateCore  0x02700DB8  arm twl
 */

typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef void (*CamPxiCallback)(u32 result, u32 arg);
extern u32 CAMERA_I2CActivateCore(u32 a0);

static void CameraStandbyCallback(void) {
    CAMERA_I2CActivateCore(0);
}
