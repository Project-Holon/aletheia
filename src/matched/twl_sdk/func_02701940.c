/*
 * function: CAMERA_SetLEDAsyncCore
 * address:  0x02701940
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
 *   OS_DisableInterrupts  0x02087988  arm twl a2
 *   OS_RestoreInterrupts  0x0208799C  arm twl a2
 *   CameraSendPxiCommand  0x027019B4  arm twl a2
 */

typedef unsigned int u32;
typedef signed int s32;
typedef unsigned short u16;
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
    u8 pad0[0x128];
    s32 f128, f12c, f130, f134, f138, f13c, f140, f144;
    s32 f148, f14c, f150, f154, f158, f15c, f160, f164;
    s32 f168, f16c, f170, f174, f178, f17c, f180, f184;
    s32 f188, f18c, f190, f194, f198, f19c;
    u32 flagsA;
    u32 flagsB;
    s32 value;
} CamPxiState;
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern CamPxiCmd data_02732FC8;
extern CamPxiState data_02733FC8;

int CAMERA_SetLEDAsyncCore(u32 command, CamPxiCallback callback, u32 arg) {
    u32 irq = OS_DisableInterrupts();
    if (data_02732FC8.busy != 0) {
        OS_RestoreInterrupts(irq);
        return 2;
    }
    data_02732FC8.busy = 1;
    OS_RestoreInterrupts(irq);
    data_02732FC8.callback = callback;
    data_02732FC8.arg = arg;
    data_02733FC8.value = command;
    if (CameraSendPxiCommand(0x40, 1, command & 0xff) != 0) {
        return 0;
    }
    return 4;
}
