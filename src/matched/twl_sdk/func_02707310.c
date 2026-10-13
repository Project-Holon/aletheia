/*
 * function: PxiCallback
 * address:  0x02707310
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02735A9C  0x02735A9C  data twl a2
 *   data_02735AAC  0x02735AAC  data twl a2
 *   AESi_PxiSendResult  0x02707ACC  arm twl a2
 *   AESi_Unlock  0x02707BDC  arm twl a2
 */

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    u32 pad0;
    u32 arg;
    void (*callback)(u32, u32);
    u32 ready;
} Slot;

extern Slot data_02735A9C;
extern u32 data_02735AAC[];
extern void OS_SendMessage(u32 *q, u32 msg, u32 flags);
extern void AESi_PxiSendResult(u32 a, u32 b);
extern void AESi_Unlock(void);

void PxiCallback(u32 tag, u32 data, u32 err) {
    u32 type;
    if (err != 0) {
        return;
    }
    type = (data & 0x1e00000) >> 21;
    data = (u16)data;
    switch (type) {
    case 6:
        if (data_02735A9C.callback != 0) {
            data_02735A9C.callback(data, data_02735A9C.arg);
        }
        AESi_Unlock();
        break;
    case 7:
        OS_SendMessage(data_02735AAC, data, 0);
        break;
    default:
        AESi_PxiSendResult(7, 6);
        break;
    }
}
