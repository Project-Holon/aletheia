/*
 * function: AESi_CalcMac
 * address:  0x027074B0
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   data_02735A9C  0x02735A9C  data twl a2
 *   AESi_PxiSendCmd  0x02707A94  arm twl a2
 *   AESi_TryLock  0x02707B0C  arm twl a2
 *   AESi_FlushRange  0x02707C2C  arm twl a2
 *   AESi_InvalidateRange  0x02707C48  arm twl a2
 */

typedef unsigned int u32;

typedef struct OSEvent OSEvent;

typedef struct {
    u32 pad0;
    u32 arg;
    void (*callback)(u32, OSEvent *);
    u32 ready;
} Slot;

typedef struct {
    u32 head[3];
    u32 pad;
    u32 a1;
    u32 a2;
    u32 zero;
    u32 kind;
    u32 a3;
} Request;

extern Slot data_02735A9C;
extern u32 AESi_TryLock(void);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern void AESi_FlushRange(u32 a, u32 b);
extern void AESi_InvalidateRange(u32 addr, u32 size);
extern void AESi_PxiSendCmd(u32 cmd, void *data, u32 size);

u32 AESi_CalcMac(u32 src, u32 a1, u32 a2, u32 a3, void (*callback)(u32, OSEvent *), OSEvent *arg) {
    Request req;
    if (AESi_TryLock() == 0) {
        return 4;
    }
    data_02735A9C.callback = callback;
    data_02735A9C.arg = (u32)arg;
    MI_CpuCopy8((void *)src, &req, 0xc);
    req.a1 = a1;
    req.a2 = a2;
    req.zero = 0;
    req.kind = 7;
    req.a3 = a3;
    AESi_FlushRange(a1, a2);
    AESi_InvalidateRange(a3, 0x10);
    AESi_PxiSendCmd(9, &req, 0x24);
    return 1;
}
