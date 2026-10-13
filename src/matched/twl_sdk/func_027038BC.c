/*
 * function: NWMi_ReceivingFrameCallback
 * address:  0x027038BC
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
 *   func_020862D4  0x020862D4  arm twl
 *   NWMi_SendCommand  0x02703A74  arm twl
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
extern void func_020862D4(void *, u32);
extern u32 NWMi_SendCommand();

void NWMi_ReceivingFrameCallback(TwlMsg *a0) {
    TwlWork *w;
    u32 first;

    w = NWMi_GetSystemWork();
    if (a0->kind != 0) {
        if (a0->kind != 0xB) {
            return;
        }
        first = 0;
    } else {
        first = 1;
    }
    if (w->cb[a0->idx] != 0) {
        func_020862D4(a0, 0x10);
        w->cb[a0->idx](a0);
    }
    if (first == 0) {
        NWMi_SendCommand(0xA, 3, a0->arg, 0, a0->idx);
    }
}
