/*
 * function: NWM_SetWPAPSK
 * address:  0x02703960
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NWMi_CheckState  0x027028E4  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   NWMi_SetCallbackTable  0x02703A34  arm twl
 *   MI_CpuCopy8  0x02082D44  arm twl
 *   NWMi_SendCommandDirect  0x02703B24  arm twl
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct TwlReq {
    u16 kind;
    u8 data[0x20];
} TwlReq;

typedef struct TwlMsg {
    u16 len;
    u16 kind;
    u8 data[0x20];
} TwlMsg;

extern u32 NWMi_CheckState(u32, u32);
extern void func_020862D4(const void *, u32);
extern void NWMi_SetCallbackTable(u32, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern u32 NWMi_SendCommandDirect(void *, u32);

u32 NWM_SetWPAPSK(u32 a0, TwlReq *a1) {
    u32 r;
    TwlMsg msg;

    r = NWMi_CheckState(1, 3);
    if (r != 0 && r != 2) {
        return r;
    }
    if (a1 == 0) {
        return 5;
    }
    func_020862D4(a1, 0x22);
    switch (a1->kind) {
    case 4:
    case 5:
    case 6:
    case 7:
        break;
    default:
        return 5;
    }
    NWMi_SetCallbackTable(0x12, a0);
    msg.len = 0x12;
    msg.kind = a1->kind;
    MI_CpuCopy8(a1->data, msg.data, 0x20);
    r = NWMi_SendCommandDirect(&msg, 0x24);
    if (r == 0 || r == 2) {
        r = 2;
    }
    return r;
}
