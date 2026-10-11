/*
 * function: func_0272F8A8
 * address:  0x0272F8A8
 * packet:   twl_sys
 * region:   twl
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_02087988 0x02087988 arm
 *   func_0208799C 0x0208799C arm
 *   func_0272FD40 0x0272FD40 arm twl
 *   func_0272F804 0x0272F804 arm twl
 */
typedef unsigned int u32;
struct Cfg {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};
extern u32 func_02087988(void);
extern void func_0208799C(u32);
extern void func_0272FD40(int);
extern u32 func_0272F804(u32);


struct NdmaCh {
    u32 src;
    u32 dst;
    u32 total;
    u32 block;
    u32 intv;
    u32 fill;
    u32 ctrl;
};
#define NDMA ((volatile struct NdmaCh *)0x04004104)

void func_0272F8A8(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, struct Cfg *cfg, int words, u32 flags)
{
    u32 irq;
    u32 ctrl;

    if (size == 0) {
        return;
    }
    irq = func_02087988();
    func_0272FD40(ch);
    if (mode != 0) {
        NDMA[ch].src = src;
    }
    NDMA[ch].dst = dst;
    NDMA[ch].intv = cfg->unk0 | cfg->unk4;
    if (mode == 0) {
        NDMA[ch].fill = fill;
    }
    if (words == -1) {
        NDMA[ch].block = size >> 2;
    } else {
        u32 w;
        w = size >> 2;
        NDMA[ch].total = w;
        if (cfg->unkC != -1) {
            w = cfg->unkC;
        }
        NDMA[ch].block = w;
    }
    ctrl = cfg->unk8 | (flags & 0x80000000);
    ctrl |= func_0272F804(mode);
    NDMA[ch].ctrl = ctrl | (words == -1 ? 0x10000000 : words);
    func_0272FD40(ch);
    func_0208799C(irq);
}
