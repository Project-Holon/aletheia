/*
 * function: AESi_Init
 * address:  0x027073AC
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02735A9C_msg  0x02735A9C  data twl a2
 *   data_02735A9C  0x02735A9C  data twl a2
 *   data_02735AAC  0x02735AAC  data twl a2
 *   PxiCallback  0x02707310  arm
 *   AESi_InitLock  0x02707AEC  arm
 *   PXI_Init  0x02088498  arm  arm9
 */

typedef unsigned int u32;

typedef struct OSEvent OSEvent;

typedef struct {
    u32 msg[1];
    OSEvent *arg;
    void (*callback)(u32, OSEvent *);
    u32 ready;
} Slot;

extern Slot data_02735A9C;
/* Message buffer at the same address as data_02735A9C.msg: AESi_Init has two
   pool entries for 0x02735A9C (one for the ready flag, one for this argument),
   so the original referenced two distinct symbols there. */
extern u32 data_02735A9C_msg[1];
extern u32 data_02735AAC[];
extern void func_02085D94(u32 *q, u32 *buf, u32 count);
extern void func_020885A0(u32 tag, void (*cb)(u32, u32, u32));
extern u32 func_020885EC(u32 tag, u32 arg);
extern void PXI_Init(void);
extern void AESi_InitLock(void);
extern void PxiCallback(u32 tag, u32 data, u32 err);

void AESi_Init(void) {
    if (data_02735A9C.ready != 0) {
        return;
    }
    func_02085D94(data_02735AAC, data_02735A9C_msg, 1);
    AESi_InitLock();
    PXI_Init();
    func_020885A0(0x13, PxiCallback);
    while (func_020885EC(0x13, 1) == 0) {
    }
    data_02735A9C.ready = 1;
}
