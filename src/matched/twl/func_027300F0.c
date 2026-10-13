/*
 * function: MI_SendNDmaGXCommandAsyncFast
 * address:  0x027300F0
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
 *   data_02732EFC 0x02732EFC data twl
 *   MI_WaitNDma 0x0272FCB0 arm twl
 *   MIi_NDmaAsync_withConfig_Dev 0x0272F9C4 arm twl
 *   MIi_NDMAFastCallback 0x027301B4 arm twl
 */
typedef unsigned int u32;

struct St {
    volatile u32 f0;
    u32 f4;
    u32 f8;
    u32 fc;
    void (*f10)(u32);
    u32 f14;
    u32 f18;
    u32 f1c;
};
struct E { int a, b, c, d; };
extern struct St data_02732F3C;
extern struct E data_02732EFC[];
extern void MI_WaitNDma(u32);
extern void MIi_NDMAFastCallback(void);
extern void MIi_NDmaAsync_withConfig_Dev(u32, u32, u32, u32, u32, u32, void (*)(), u32, void *, u32, u32);

void MI_SendNDmaGXCommandAsyncFast(u32 ch, u32 src, u32 size, void (*cb)(u32), u32 arg)
{
    struct St *s;
    if (size == 0) {
        if (cb != 0) {
            cb(arg);
        }
        return;
    }
    while (data_02732F3C.f0 != 0) {
    }
    s = &data_02732F3C;
    s->f0 = 1;
    s->f4 = ch;
    s->f10 = cb;
    s->f14 = arg;
    MI_WaitNDma(ch);
    MIi_NDmaAsync_withConfig_Dev(9, ch, src, 0x04000400, 0, size, MIi_NDMAFastCallback, 0, (void *)((char *)data_02732EFC + (ch << 4)), -1, 0x80000000);
}
