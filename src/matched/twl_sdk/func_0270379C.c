/*
 * function: NWM_SetReceivingFrameBuffer
 * address:  0x0270379C
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_GetSystemWork  0x027026DC  arm twl
 *   NWMi_CheckState  0x027028E4  arm twl
 *   MIi_DmaFill32  0x020821C0  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   NWMi_SetCallbackTable  0x02703A34  arm twl
 *   NWMi_SetReceiveCallbackTable  0x02703A54  arm twl
 *   NWMi_SendCommand  0x02703A74  arm twl
 *   NWMi_ReceivingFrameCallback  0x027038BC  arm twl
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

extern TwlWork *NWMi_GetSystemWork(void);
extern u32 NWMi_CheckState(u32, u32, u32);
extern void MIi_DmaFill32(u32, u32, u32, u32, u32);
extern void func_020862D4(void *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void NWMi_SetReceiveCallbackTable(u32, u32);
extern u32 NWMi_SendCommand();
void NWMi_ReceivingFrameCallback(TwlMsg *a0);

u32 NWM_SetReceivingFrameBuffer(u32 a0, u32 a1, u32 a2, u32 a3) {
    TwlWork *w;
    u32 r;

    w = NWMi_GetSystemWork();
    r = NWMi_CheckState(2, 3, 4);
    if (r != 0 && r != 2) {
        return r;
    }
    MIi_DmaFill32(w->h2280, a1, 0, a2, 1);
    func_020862D4((void *)a1, a2);
    NWMi_SetCallbackTable(0xA, (u32)NWMi_ReceivingFrameCallback);
    NWMi_SetReceiveCallbackTable(a3, a0);
    r = NWMi_SendCommand(0xA, 3, a1, a2, a3);
    if (r == 0) {
        r = 2;
    }
    return r;
}
