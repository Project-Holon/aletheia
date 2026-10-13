/*
 * function: NWMi_InitCore
 * address:  0x02702468
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988  0x02087988  arm twl
 *   func_02090ECC  0x02090ECC  arm twl
 *   func_0208799C  0x0208799C  arm twl
 *   data_027341A0  0x027341A0  data twl a2
 *   data_027341A4  0x027341A4  data twl a2
 *   func_02088498  0x02088498  arm twl
 *   func_020885EC  0x020885EC  arm twl
 *   func_020862B8  0x020862B8  arm twl
 *   func_020821C0  0x020821C0  arm twl
 *   func_020862D4  0x020862D4  arm twl
 *   NWMi_ClearFifoRecvFlag  0x027026EC  arm twl
 *   func_02085D94  0x02085D94  arm twl
 *   func_02085DBC  0x02085DBC  arm twl
 *   func_020885A0  0x020885A0  arm twl
 *   NWMi_ReceiveFifo9  0x02702740  arm twl
 *   func_02082BCC  0x02082BCC  arm twl
 */

typedef unsigned int u32;
typedef unsigned char u8;
typedef unsigned short u16;
typedef struct CamRing {
    u8 pad0[0x24];
    u16 ready;
} CamRing;
typedef struct CamBuf {
    u16 lines[0x20][0x80];
    u8 ctlA[0x20];
    u8 ctlB[0x100];
    u8 state[0x154];
    u8 *p274;
    CamRing *ring;
    u8 *p27c;
    u16 f280;
} CamBuf;
extern u32 func_02087988(void);
extern u32 func_02090ECC(void);
extern void func_0208799C(u32);
extern void func_02088498(void);
extern u32 func_020885EC(u32, u32);
extern void func_020862B8(void *, u32);
extern void func_020821C0(u32, void *, u32, u32, u32);
extern void func_020862D4(void *, u32);
extern void NWMi_ClearFifoRecvFlag(void);
extern void func_02085D94(void *, void *, u32);
extern void func_02085DBC(void *, void *, u32);
extern void func_020885A0(u32, void (*)(void));
extern void NWMi_ReceiveFifo9(void);
extern void func_02082BCC(void *, u32, u32);
extern CamBuf *data_027341A4;
extern u8 data_027341A0[];

u32 NWMi_InitCore(CamBuf *buf, u32 size, u32 mode) {
    u32 irq = func_02087988();
    int i;
    if (func_02090ECC() == 0) {
        func_0208799C(irq);
        return 3;
    }
    if (data_027341A0[0] != 0) {
        func_0208799C(irq);
        return 3;
    }
    if (buf == 0) {
        func_0208799C(irq);
        return 5;
    }
    if (mode > 3) {
        func_0208799C(irq);
        return 5;
    }
    if (((u32)buf & 0x1f) != 0) {
        func_0208799C(irq);
        return 5;
    }
    func_02088498();
    if (func_020885EC(0x16, 1) == 0) {
        func_0208799C(irq);
        return 4;
    }
    func_020862B8(buf, size);
    func_020821C0(mode, buf, 0, size, 1);
    data_027341A4 = buf;
    func_020862D4(&data_027341A4, 4);
    data_027341A4->p274 = (u8 *)data_027341A4 + 0x22e0;
    data_027341A4->ring = (CamRing *)(data_027341A4->p274 + 0x20);
    data_027341A4->p27c = (u8 *)data_027341A4->ring + 0xc0;
    NWMi_ClearFifoRecvFlag();
    data_027341A4->f280 = mode;
    func_02085D94(data_027341A4->ctlA, data_027341A4->ctlB, 0x20);
    for (i = 0; i < 0x20; i++) {
        data_027341A4->lines[i][0] = 0x8000;
        func_020862D4(data_027341A4->lines[i], 2);
        func_02085DBC(data_027341A4->ctlA, data_027341A4->lines[i], 1);
    }
    func_020885A0(0x16, NWMi_ReceiveFifo9);
    func_02082BCC(data_027341A4->state, 0, 0x154);
    data_027341A0[0] = 1;
    data_027341A4->ring->ready = 1;
    func_020862D4(data_027341A4, 0x22e0);
    func_020862D4((void *)0x27341a0, 1);
    func_0208799C(irq);
    return 0;
}
