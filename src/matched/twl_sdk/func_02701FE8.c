/*
 * function: CameraCallCallbackAndUnlock
 * address:  0x02701FE8
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
extern CamPxiCmd data_02732FC8;

void CameraCallCallbackAndUnlock(u32 result) {
    CamPxiCallback cb;
    if (data_02732FC8.busy != 0) {
        data_02732FC8.busy = 0;
    }
    cb = data_02732FC8.callback;
    if (cb == 0) {
        return;
    }
    data_02732FC8.callback = 0;
    cb(result, data_02732FC8.arg);
}
