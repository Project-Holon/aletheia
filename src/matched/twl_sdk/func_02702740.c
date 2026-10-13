/*
 * function: NWMi_ReceiveFifo9
 * address:  0x02702740
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_027341a4   0x027341a4  data twl
 *   func_020862B8  0x020862B8  arm twl
 *   NWMi_DeleteSleepCallback  0x02702A78  arm twl
 *   PM_DeletePostExitCallback  0x02731590  arm twl
 *   DAT_027341a8   0x027341a8  data twl
 *   MI_CpuFill8  0x02082BCC  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   NWMi_ClearFifoRecvFlag  0x027026EC  arm twl
 */

typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Msg {
    u16 type;
    u16 sub;
    void (*cb)(struct Msg *);
    u32 w08;
    u32 w0c;
    u32 w10;
} Msg;

extern u32 DAT_027341a4[];
extern void func_020862B8(u32, u32);
extern void NWMi_DeleteSleepCallback(void);
extern void PM_DeletePostExitCallback(u32);
extern u32 DAT_027341a8[];
extern void MI_CpuFill8(u32, u32, u32);
extern void func_020862D4(u32, u32);
extern void NWMi_ClearFifoRecvFlag(void);

void NWMi_ReceiveFifo9(u32 a0, Msg *msg, u32 a2) {
    u32 base = DAT_027341a4[0];
    void (*handler)(Msg *);
    u32 type;
    if (base == 0) {
        return;
    }
    if (a2 != 0) {
        return;
    }
    if (msg == 0) {
        return;
    }
    if (msg->type >= 0x14) {
        return;
    }
    func_020862B8(*(u32 *)(base + 0x227C), 0x100);
    func_020862B8(*(u32 *)(base + 0x2278), 0xC0);
    if ((u32)msg != *(u32 *)(base + 0x227C)) {
        func_020862B8((u32)msg, 0x100);
    }
    type = msg->type;
    if ((type == 3 && msg->sub != 0) || (type == 4 && msg->sub == 0) || type == 0x13) {
        NWMi_DeleteSleepCallback();
    }
    if (msg->type == 0xB && msg->sub != 0xC && msg->cb != 0) {
        msg->cb(msg);
    }
    type = msg->type;
    if (type != 0xB) {
        if (type == 4 || type == 0x13 || (type == 3 && msg->sub != 0)) {
            PM_DeletePostExitCallback((u32)DAT_027341a8);
        }
        type = msg->type;
        handler = *(void (**)(Msg *))(base + type * 4 + 0x2284);
        if (type == 7) {
            func_020862B8(msg->w10, msg->w0c);
        }
        if (handler != 0) {
            handler(msg);
        }
    }
    MI_CpuFill8((u32)msg, 0, 0x100);
    func_020862D4((u32)msg, 0x100);
    if (base != 0) {
        NWMi_ClearFifoRecvFlag();
    }
}
