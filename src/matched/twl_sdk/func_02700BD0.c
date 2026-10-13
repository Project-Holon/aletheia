/*
 * function: CAMERA_StopCore
 * address:  0x02700BD0
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   CAMERA_StopCaptureCore  0x0270212C  arm twl a2
 *   func_02087A04  0x02087A04  arm twl a2
 *   CAMERA_IsBusyCore  0x027020F0  arm twl a2
 *   CAMERA_ClearBufferCore  0x027021E4  arm twl a2
 *   CAMERA_I2CActivateCore  0x02700DB8  arm twl a2
 */

typedef unsigned int u32;
typedef signed int s32;

extern void CAMERA_StopCaptureCore(void);
extern void func_02087A04(u32);
extern s32 CAMERA_IsBusyCore(void);
extern void CAMERA_ClearBufferCore(void);
extern u32 CAMERA_I2CActivateCore(u32 a0);

void CAMERA_StopCore(void) {
    s32 r5 = 0x001991B0;
    u32 r4 = 4;
    CAMERA_StopCaptureCore();
    goto entry;
    do {
        func_02087A04(r4);
entry:
        if (r5-- <= 0) break;
    } while (CAMERA_IsBusyCore() != 0);

    CAMERA_ClearBufferCore();
    CAMERA_I2CActivateCore(0);
}
