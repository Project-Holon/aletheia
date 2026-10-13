/*
 * function: MIi_NDMACallback
 * address:  0x02730090
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
 *   func_02084998 0x02084998 arm
 *   func_02084774 0x02084774 arm
 */
typedef unsigned int u32;

struct St {
    u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    void (*f10)(u32);
    u32 f14;
    u32 f18;
    u32 f1c;
};
extern struct St data_02732F3C;
extern void func_02084998(u32);
extern void func_02084774(u32, u32);

void MIi_NDMACallback(void)
{
    struct St *s = &data_02732F3C;
    void (*cb)(u32);
    u32 arg;
    volatile u32 *reg = (volatile u32 *)0x04000600;
    func_02084998(0x200000);
    *reg = (s->f18 << 30) | (*reg & ~0xC0000000);
    func_02084774(0x200000, s->f1c);
    s->f0 = 0;
    cb = s->f10;
    arg = s->f14;
    if (cb != 0) {
        cb(arg);
    }
}
