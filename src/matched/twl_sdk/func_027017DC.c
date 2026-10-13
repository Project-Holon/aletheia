/*
 * function: CAMERA_I2CAutoExposureCore
 * address:  0x027017DC
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02701FD8  0x02701FD8  arm twl a2
 *   data_02732FC8  0x02732FC8  data twl a2
 *   CAMERA_I2CAutoExposureAsyncCore  0x02701718  arm twl a2
 *   CameraWaitBusy  0x02702028  arm twl a2
 */

typedef unsigned int u32;

extern u32 data_02701FD8;
extern u32 data_02732FC8[];
extern u32 CAMERA_I2CAutoExposureAsyncCore(u32, u32, u32*, u32);
extern void CameraWaitBusy(void);

u32 CAMERA_I2CAutoExposureCore(u32 a0, u32 a1) {
    u32 ret = CAMERA_I2CAutoExposureAsyncCore(a0, a1, &data_02701FD8, 0);
    data_02732FC8[2] = ret;
    if (ret == 0) {
        CameraWaitBusy();
    }
    return data_02732FC8[2];
}
