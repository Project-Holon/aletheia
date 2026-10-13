/*
 * function: SendCommandEx
 * address:  0x02704BE0
 * packet:   twl
 * region:   twl
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DAT_02734450  0x02734450  data twl
 *   OS_DisableInterrupts  0x02087988  arm twl
 *   OS_RestoreInterrupts  0x0208799C  arm twl
 *   PXI_SendWordByFifo  0x02088610  arm twl
 */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef void (*Cb)(u32, void *);

typedef struct {
    u32 pad0;
    u32 busy;
    u32 pad8;
    volatile u32 state;
    u32 pad10;
    u32 pad14;
    u32 f18;
    void (*f1c)(void);
    u32 f20;
    u32 pad24;
    u32 pad28;
    Cb f2c;
    void *f30;
    u32 pad34;
    u32 pad38;
    void (*f3c)(void);
    u32 f40;
    u32 pad44;
    u32 pad48;
    Cb f4c;
    void *f50;
    void *f54;
    u8 f58;
} State;

extern State DAT_02734450;
extern u32 OS_DisableInterrupts(void);
extern void OS_RestoreInterrupts(u32);
extern int PXI_SendWordByFifo(u32, u32, u32);

u32 SendCommandEx(u32 a0, u32 a1) {
    u32 irq = OS_DisableInterrupts();
    int r = PXI_SendWordByFifo(0x18, ((a0 << 16) & 0xff0000) | (u16)a1, 0);
    if (r < 0) {
        DAT_02734450.state = 2;
        OS_RestoreInterrupts(irq);
        return 0;
    }
    if (a0 == 0xc7) {
        DAT_02734450.f18 = 1;
    }
    OS_RestoreInterrupts(irq);
    return 1;
}
