/*
 * function: MIi_NDma_withConfig_Dev
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
 *   MIi_Wait 0x0272FD40 arm twl
 *   MIi_GetControlData 0x0272F804 arm twl
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
extern void MIi_Wait(int);
extern u32 MIi_GetControlData(u32);


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

void MIi_NDma_withConfig_Dev(int mode, int ch, u32 src, u32 dst, u32 fill, u32 size, struct Cfg *cfg, int words, u32 flags)
{
    u32 irq;
    u32 ctrl;

    if (size == 0) {
        return;
    }
    irq = func_02087988();
    MIi_Wait(ch);
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
    ctrl |= MIi_GetControlData(mode);
    NDMA[ch].ctrl = ctrl | (words == -1 ? 0x10000000 : words);
    MIi_Wait(ch);
    func_0208799C(irq);
}
