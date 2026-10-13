/*
 * function: CAMERA_I2CPhotoModeAsyncCore
 * address:  0x027013A4
 * packet:   twl_sys
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732FC8  0x02732FC8  data twl a2
 *   data_02733FC8  0x02733FC8  data twl a2
 *   CAMERA_CheckRetryCount  0x027007C8  arm twl a2
 *   func_02087988  0x02087988  arm twl a2
 *   func_0208799C  0x0208799C  arm twl a2
 *   CameraSendPxiCommand  0x027019B4  arm twl a2
 *   CameraSendPxiData  0x02701A60  arm twl a2
 */

typedef unsigned int u32;
typedef signed int s32;
typedef unsigned char u8;

typedef void (*CamPxiCallback)(u32 result, u32 arg);

typedef struct CamPxiCmd {
    u32 busy;
    CamPxiCallback callback;
    u32 f08;
    u32 arg;
    s32 command;
    s32 type;
    u8 index;
    u8 total;
    u8 pad[2];
    u8 *buf;
    u32 len;
    u32 pend0;
    u32 pend1;
    u32 pend2;
} CamPxiCmd;

typedef struct CamPxiState {
    u8 pad0[0x1a0];
    u32 flagsA;
    u32 flagsB;
    s32 value;
} CamPxiState;

extern u32 CAMERA_CheckRetryCount(void);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern int CameraSendPxiCommand(u32, u32, u32);
extern void CameraSendPxiData(const u8 *);
extern CamPxiCmd data_02732FC8;
extern CamPxiState data_02733FC8;

u32 CAMERA_I2CPhotoModeAsyncCore(u32 a0, s32 a1, CamPxiCallback a2, u32 a3) {
    u8 buf[2];
    u32 st = CAMERA_CheckRetryCount();
    u32 irq;
    if (st == 7) {
        return st;
    }
    if (a0 != 1 && a0 != 2 && a0 != 3) {
        return 3;
    }
    switch (a1) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
        break;
    default:
        return 3;
    }
    irq = func_02087988();
    if (data_02732FC8.busy != 0) {
        func_0208799C(irq);
        return (st == 6) ? 6 : 2;
    }
    data_02732FC8.busy = 1;
    func_0208799C(irq);
    data_02732FC8.callback = a2;
    data_02732FC8.arg = a3;
    buf[0] = a0;
    buf[1] = a1;
    data_02733FC8.flagsA = a0;
    data_02733FC8.value = a1;
    if (CameraSendPxiCommand(0x34, 2, buf[0]) == 0) {
        return 4;
    }
    CameraSendPxiData(&buf[1]);
    return 0;
}
