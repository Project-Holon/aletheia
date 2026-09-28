/*
 * function: ov208_func_021BC758
 * address:  0x021BC758
 * packet:   pkt_ov208_021BC758
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020216D4  0x020216D4  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208PalFade {
    u32 f0;
    u32 f4;
    void *slots;
    u16 mask;
};

extern void func_020216D4(void *slots, u32 bank, u32 off, u32 size);

void ov208_func_021BC758(struct Ov208PalFade *p)
{
    if (p->mask & 1)
        func_020216D4(p->slots, 0, 0, 0x1a0);
    if (p->mask & 4)
        func_020216D4(p->slots, 2, 0, 0x100);
    if (p->mask & 2)
        func_020216D4(p->slots, 1, 0, 0x1a0);
    if (p->mask & 8)
        func_020216D4(p->slots, 3, 0, 0x1c0);
}
