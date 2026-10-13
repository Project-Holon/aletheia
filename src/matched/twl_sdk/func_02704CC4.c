/*
 * function: ReplyCallback
 * address:  0x02704CC4
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
 *   func_02087988  0x02087988  arm twl
 *   func_0208799C  0x0208799C  arm twl
 *   SetSndexWork  0x02704D48  arm twl
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
extern u32 func_02087988(void);
extern void func_0208799C(u32);
void SetSndexWork(Cb a0, void *a1, void *a2, u32 a3);

void ReplyCallback(u32 a0) {
    u32 irq = func_02087988();
    u8 cmd = DAT_02734450.f58;
    Cb cb = DAT_02734450.f4c;
    void *arg = DAT_02734450.f50;
    if (cmd == 0xc7) {
        DAT_02734450.f18 = 0;
        DAT_02734450.busy = 0;
    }
    SetSndexWork(0, 0, 0, 0);
    if (cmd == 0xfb) {
        DAT_02734450.state = 4;
    } else {
        DAT_02734450.state = 2;
    }
    func_0208799C(irq);
    if (cb != 0) {
        cb(a0, arg);
    }
}
