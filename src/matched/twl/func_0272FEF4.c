/*
 * function: MI_SendNDmaGXCommandAsync
 * address:  0x0272FEF4
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   data_02732F3C 0x02732F3C data twl
 *   MIi_FIFOCallback 0x0272FFC8 arm twl
 *   MI_WaitNDma 0x0272FCB0 arm twl
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_02084818 0x02084818 arm
 *   func_02084774 0x02084774 arm
 *   func_02084968 0x02084968 arm
 */
typedef unsigned int u32;
struct St { u32 f0; u32 f4; u32 f8; u32 fc; void (*f10)(u32); u32 f14; u32 f18; u32 f1c; };
extern struct St data_02732F3C;
extern void MI_WaitNDma(u32);
extern void MIi_FIFOCallback(void);
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern u32 func_02084818(u32);
extern void func_02084774(u32, void (*)(void));
extern void func_02084968(u32);

void MI_SendNDmaGXCommandAsync(u32 a0, u32 a1, u32 a2, void (*cb)(u32), u32 arg)
{
    u32 irq;
    struct St *s;
    if (a2 == 0) {
        if (cb != 0) {
            cb(arg);
        }
        return;
    }
    while (((volatile struct St *)&data_02732F3C)->f0 != 0) {
    }
    while ((((*(volatile u32 *)0x04000600) & 0x7000000) >> 24 & 2) == 0) {
    }
    s = &data_02732F3C;
    s->f0 = 1;
    s->f4 = a0;
    s->f8 = a1;
    s->fc = a2;
    s->f10 = cb;
    s->f14 = arg;
    MI_WaitNDma(a0);
    irq = func_02087988();
    s->f18 = (*(volatile u32 *)0x04000600 & 0xc0000000) >> 0x1e;
    s->f1c = func_02084818(0x200000);
    *(volatile u32 *)0x04000600 = (*(volatile u32 *)0x04000600 & ~0xc0000000) | 0x40000000;
    func_02084774(0x200000, MIi_FIFOCallback);
    func_02084968(0x200000);
    MIi_FIFOCallback();
    func_0208799C(irq);
}


