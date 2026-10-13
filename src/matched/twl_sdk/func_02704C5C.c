/*
 * function: CheckState
 * address:  0x02704C5C
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
 */

typedef unsigned int u32;
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

u32 CheckState(void) {
    u32 irq = OS_DisableInterrupts();
    switch (DAT_02734450.state) {
    case 0:
    case 1:
        OS_RestoreInterrupts(irq);
        return 1;
    case 3:
    case 4:
    case 5:
        OS_RestoreInterrupts(irq);
        return 3;
    default:
        DAT_02734450.state = 3;
        OS_RestoreInterrupts(irq);
        return 0;
    }
}
