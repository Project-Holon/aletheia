/*
 * file:     nwm_recvframe.c
 * unit:     yes
 * function: NWM_SetReceivingFrameBuffer, NWM_UnsetReceivingFrameBuffer, NWMi_ReceivingFrameCallback
 * address:  0x0270379C
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * sdk:      libnwm.TWL.HYB.a nwm_recvframe.o
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm
 *   NWMi_SetCallbackTable  0x02703A34  arm
 *   NWMi_SetReceiveCallbackTable  0x02703A54  arm
 *   NWMi_SendCommand  0x02703A74  arm
 *   NWMi_CheckState  0x027028E4  arm
 *   MIi_DmaFill32  0x020821C0  arm  arm9
 *   DC_StoreRange  0x020862D4  arm  arm9
 */
typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct TwlMsg {
    u16 w0;
    u16 kind;
    u16 idx;
    u16 w6;
    u32 w8;
    u32 arg;
} TwlMsg;

typedef struct TwlWork {
    u8 pad0[0x2280];
    u16 h2280;
    u8 pad1[0x22D4 - 0x2282];
    void (*cb[1])(TwlMsg *);
} TwlWork;

extern unsigned int NWMi_GetSystemWork(void);
extern u32 NWMi_CheckState(unsigned int n, ...);
extern void MIi_DmaFill32(unsigned int dmaNo, void *dest, unsigned int data, unsigned int size, int dmaEnable);
extern void DC_StoreRange(void *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void NWMi_SetReceiveCallbackTable(u32, u32);
extern u32 NWMi_SendCommand(u16 apiid, u16 argc, ...);
u32 NWM_SetReceivingFrameBuffer(u32 callback, u32 recvBuf, u32 recvBufSize, u32 protocol);
u32 NWM_UnsetReceivingFrameBuffer(u32 callback, u32 protocol);
void NWMi_ReceivingFrameCallback(TwlMsg *msg);

u32 NWM_SetReceivingFrameBuffer(u32 callback, u32 recvBuf, u32 recvBufSize, u32 protocol) {
    TwlWork *w;
    u32 r;

    w = (struct TwlWork *)NWMi_GetSystemWork();
    r = NWMi_CheckState(2, 3, 4);
    if (r != 0 && r != 2) {
        return r;
    }
    MIi_DmaFill32(w->h2280, (void *)recvBuf, 0, recvBufSize, 1);
    DC_StoreRange((void *)recvBuf, recvBufSize);
    NWMi_SetCallbackTable(0xA, (u32)NWMi_ReceivingFrameCallback);
    NWMi_SetReceiveCallbackTable(protocol, callback);
    r = NWMi_SendCommand(0xA, 3, recvBuf, recvBufSize, protocol);
    if (r == 0) {
        r = 2;
    }
    return r;
}

u32 NWM_UnsetReceivingFrameBuffer(u32 callback, u32 protocol) {
    u32 st;
    u32 res;

    NWMi_GetSystemWork();
    st = NWMi_CheckState(2, 3, 4);
    if (st != 0 && st != 2) {
        return st;
    }
    NWMi_SetCallbackTable(0xC, callback);
    NWMi_SetReceiveCallbackTable(protocol, 0);
    res = NWMi_SendCommand(0xC, 1, protocol);
    if (res == 0) {
        return 2;
    }
    return res;
}

void NWMi_ReceivingFrameCallback(TwlMsg *msg) {
    TwlWork *w;
    u32 first;

    w = (struct TwlWork *)NWMi_GetSystemWork();
    if (msg->kind != 0) {
        if (msg->kind != 0xB) {
            return;
        }
        first = 0;
    } else {
        first = 1;
    }
    if (w->cb[msg->idx] != 0) {
        DC_StoreRange(msg, 0x10);
        w->cb[msg->idx](msg);
    }
    if (first == 0) {
        NWMi_SendCommand(0xA, 3, msg->arg, 0, msg->idx);
    }
}
