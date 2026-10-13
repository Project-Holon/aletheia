/*
 * function: MIi_NDMAFastCallback
 * address:  0x027301B4
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

void MIi_NDMAFastCallback(void)
{
    struct St *s = &data_02732F3C;
    void (*cb)(u32);
    u32 arg;
    s->f0 = 0;
    cb = s->f10;
    arg = s->f14;
    if (cb != 0) {
        cb(arg);
    }
}
